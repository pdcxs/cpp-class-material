#include <bitset>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 声明部分
class Expr;
Expr *getVar(const string &content);
using Circuit = unordered_map<string, Expr *>;
using Value = bitset<16>;

// 表达式基类
class Expr
{
public:
    virtual Expr *eval(Circuit &circuit) = 0;
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
    Num(Value value) : v(value.to_ulong()) {}
    Expr *eval(Circuit &c) override
    {
        return this;
    }

    void print(ostream &out) const override
    {
        out << v.to_ulong();
    }

    Value value()
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
    Var(string name) : name(name) {}
    Expr *eval(Circuit &circ) override
    {
        auto expr = circ.find(name);
        if (expr == circ.end())
        {
            cerr << "Cannot find " << name << endl;
            return nullptr;
        }
        auto result = expr->second->eval(circ);
        if (result != expr->second)
            delete expr->second;
        circ[name] = result;
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
    Unary(string var, const Op &&op, string opName = "NOT")
        : var(var), op(op), opName(opName) {}

    Expr *eval(Circuit &circ) override
    {
        auto *vexpr = getVar(var);
        Expr *evaluated = vexpr->eval(circ);

        Value rv;
        if (auto *num = dynamic_cast<Num *>(evaluated))
        {
            rv = num->value();
        }
        else
        {
            delete vexpr;
            return nullptr;
        }
        delete vexpr;
        return new Num(op(rv));
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
    Binary(string var1, string var2, const Op &&op, string opName)
        : var1(var1), var2(var2), op(op), opName(opName) {}

    Expr *eval(Circuit &circ) override
    {
        auto *vexpr1 = getVar(var1);
        auto *vexpr2 = getVar(var2);

        Expr *e1 = vexpr1->eval(circ);
        Expr *e2 = vexpr2->eval(circ);

        Value rv1, rv2;
        if (auto *n1 = dynamic_cast<Num *>(e1))
        {
            rv1 = n1->value();
        }
        else
        {
            delete vexpr1;
            delete vexpr2;
            return nullptr;
        }

        if (auto *n2 = dynamic_cast<Num *>(e2))
        {
            rv2 = n2->value();
        }
        else
        {
            delete vexpr1;
            delete vexpr2;
            return nullptr;
        }

        delete vexpr1;
        delete vexpr2;
        return new Num(op(rv1, rv2));
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

Expr *getVar(const string &content)
{
    char fstChar = content[0];
    if (fstChar >= '0' && fstChar <= '9')
        return new Num(stoi(content));
    return new Var(content);
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
            result[right] = new Unary(
                wds[1],
                [](Value v)
                { return ~v; });
            break;
        case 3:
            result[right] = new Binary(
                wds[0], wds[2],
                parseBin(wds[1]), wds[1]);
        }
    }
    return result;
}

void deletePointers(Circuit &c)
{
    unordered_set<Expr *> deleted;
    for (auto &p : c)
        if (deleted.find(p.second) == deleted.end())
        {
            deleted.insert(p.second);
            delete p.second;
        }
    c.clear();
}

int main(int argc, char **argv)
{
    Circuit c = parse("input.txt");

    // problem 1
    Var a("a");
    a.eval(c);
    Num r = *dynamic_cast<Num *>(c.at("a"));
    cout << r << endl;

    deletePointers(c);

    // problem 2
    c = parse("input.txt");
    delete c["b"];
    c["b"] = new Num(r);
    a.eval(c);
    r = *dynamic_cast<Num *>(c.at("a"));
    cout << r << endl;

    deletePointers(c);

    return 0;
}
