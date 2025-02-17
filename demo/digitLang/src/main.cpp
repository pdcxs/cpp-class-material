#include <bitset>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 声明部分
class Expr;
using ExprPtr = unique_ptr<Expr>;
ExprPtr getVar(const string &content);
using Circuit = unordered_map<string, ExprPtr>;
using Value = bitset<16>;

// 表达式基类
class Expr
{
public:
    virtual ExprPtr eval(Circuit &circuit) = 0;
    virtual void print(ostream &out) const = 0;
    virtual ~Expr() = default;
};

ostream &operator<<(ostream &out, const Expr &expr)
{
    expr.print(out);
    return out;
}

// 数字
class Num : public Expr
{
private:
    Value v;

public:
    explicit Num(const Value &value) : v(value.to_ulong()) {}
    ExprPtr eval(Circuit &c) override
    {
        return make_unique<Num>(v);
    }

    void print(ostream &out) const override
    {
        out << v.to_ulong();
    }

    const Value &value() const
    {
        return v;
    }
};

// 变量
class Var : public Expr
{
private:
    string name;

public:
    explicit Var(const string &name) : name(name) {}
    ExprPtr eval(Circuit &circ) override
    {
        auto expr = circ.find(name);
        if (expr == circ.end())
        {
            cerr << "Cannot find " << name << endl;
            return nullptr;
        }
        auto result = expr->second->eval(circ);
        const Num *num = dynamic_cast<Num *>(result.get());
        circ[name] = make_unique<Num>(num->value());
        return result;
    }
    void print(ostream &out) const override
    {
        out << name;
    }
};

// 单目运算，此例中只有 Not
class Unary : public Expr
{
private:
    string var;
    using Op = function<Value(Value)>;
    const Op op;
    string opName;

public:
    Unary(string var, const Op &op, const string &opName = "NOT")
        : var(var), op(op), opName(opName) {}

    ExprPtr eval(Circuit &circ) override
    {
        auto vexpr = getVar(var);
        ExprPtr evaluated = vexpr->eval(circ);
        const Num *num = dynamic_cast<Num *>(evaluated.get());

        return make_unique<Num>(op(num->value()));
    }

    void print(ostream &out) const override
    {
        out << opName << " " << var;
    }
};

// 双目运算，有AND OR LSHIFT RSHIFT
class Binary : public Expr
{
public:
    using Op = function<Value(Value, Value)>;

private:
    string var1, var2;
    const Op op;
    string opName;

public:
    Binary(string var1, string var2, const Op &op, const string &opName)
        : var1(var1), var2(var2), op(op), opName(opName) {}

    ExprPtr eval(Circuit &circ) override
    {
        auto vexpr1 = getVar(var1);
        auto vexpr2 = getVar(var2);

        auto e1 = vexpr1->eval(circ);
        auto e2 = vexpr2->eval(circ);

        const Num *n1 = dynamic_cast<Num *>(e1.get());
        const Num *n2 = dynamic_cast<Num *>(e2.get());

        return make_unique<Num>(op(n1->value(), n2->value()));
    }

    void print(ostream &out) const override
    {
        out << var1 << " " << opName << " " << var2;
    }
};

vector<string> words(const string &content)
{
    istringstream iss(content);
    vector<string> result;
    string wd;
    while (getline(iss, wd, ' '))
    {
        if (wd != "")
            result.push_back(wd);
    }
    return result;
}

ExprPtr getVar(const string &content)
{
    char fstChar = content[0];
    if (fstChar >= '0' && fstChar <= '9')
        return make_unique<Num>(stoi(content));
    return make_unique<Var>(content);
}

Binary::Op parseBin(const string &content)
{
    if (content == "AND")
    {
        return [](Value x, Value y)
        {
            return x & y;
        };
    }
    if (content == "OR")
    {
        return [](Value x, Value y)
        {
            return x | y;
        };
    }
    if (content == "LSHIFT")
    {
        return [](Value x, Value y)
        {
            return x << y.to_ulong();
        };
    }
    if (content == "RSHIFT")
    {
        return [](Value x, Value y)
        {
            return x >> y.to_ulong();
        };
    }

    // should not reach here.
    cerr << "Unknown operator " << content;
    return [](Value x, Value y)
    {
        return 0;
    };
}

Circuit parse(const string &fileName)
{
    ifstream stm(fileName);
    if (!stm.is_open())
    {
        cerr << "Cannot open file " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    Circuit result;
    string ln;
    while (!stm.eof())
    {
        getline(stm, ln);
        auto wds = words(ln);
        string right = wds[wds.size() - 1];
        int leftWdCnt = 0;
        for (; leftWdCnt < wds.size(); leftWdCnt++)
        {
            if (wds[leftWdCnt] == "->")
                break;
        }

        switch (leftWdCnt)
        {
        case 1:
            result[right] = getVar(wds[0]);
            break;
        case 2:
            result[right] = make_unique<Unary>(
                wds[1],
                [](Value v)
                { return ~v; });
            break;
        case 3:
            result[right] = make_unique<Binary>(
                wds[0], wds[2],
                parseBin(wds[1]), wds[1]);
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    Circuit c = parse("input.txt");

    // problem 1
    Var a("a");
    a.eval(c);
    Num r = *dynamic_cast<Num *>(c.at("a").get());
    cout << r << endl;

    // problem 2
    c = parse("input.txt");
    c["b"] = make_unique<Num>(r);
    a.eval(c);
    r = *dynamic_cast<Num *>(c.at("a").get());
    cout << r << endl;

    return 0;
}
