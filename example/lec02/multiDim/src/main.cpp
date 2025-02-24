#include <iostream>

using namespace std;

int main() {
    int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << "sizeof(a): " << sizeof(a) / sizeof(int) << endl;

    // int **p = a; wrong
    int (*p)[4] = a;
    cout << "sizeof(*p): " << sizeof(*p) / sizeof(int) << endl;

    cout << "*(p + 1)[0]: " << *(p + 1)[0] << endl;
    cout << "**(p + 1): " << **(p + 1) << endl;
    cout << "p[2][1]: " << p[2][1] << endl;
    cout << "*(*(p + 2) + 1): " << *(*(p + 2) + 1) << endl;
    return 0;
}
