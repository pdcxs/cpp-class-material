#include <iostream>

using namespace std;

int josephus(int n, int k) {
    return n == 1 ? 0 :
      (k + josephus(n - 1, k)) % n;
}

int josephus2(int n, int k) {
    // inverse josephus
    int r = 0;
    for (int i = 2; i <= n; i++) {
        r = (r + k) % i;
    }
    return r + 1;
}

int main() {
    cout << "Please input ring size and step size.\n";
    cout << "If ring size is less than 1, program will exit." << endl;
    while (true) {
        int n, k;
        cout << ">>> ";
        cin >> n;
        if (n < 1) break;
        cin >> k;
        // cout << "Last one is: " << 1 + josephus(n, k) << endl;
        cout << "Last one is: " << josephus2(n, k) << endl;
    }
    return 0;
}
