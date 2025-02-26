#include <iostream>
#include <iomanip>
#include <cmath>

using Fn = double(*)(double);

double newton(Fn func, double guess = 1.0)
{
    double y = func(guess);
    if (std::abs(y) < 1e-10) {
        return guess;
    }

    double delta = 1e-10;
    double dy = (func(guess + delta) - func(guess - delta)) / (2 * delta);
    return newton(func, guess - y / dy);
}

double equation1(double x) {
    return x * x - 2;
}

double equation2(double x) {
    return tan(x) - 1;
}

int main(int argc, char** argv) {
    std::cout << std::setprecision(10);
    std::cout << newton(equation1) << std::endl;
    std::cout << 4 * newton(equation2) << std::endl;
    std::cout << newton([](double x) {return x * x - 2;}) << std::endl;
    return 0;
}
