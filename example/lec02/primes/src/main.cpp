#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " [max number]" << endl;
        return EXIT_FAILURE;
    }
    int maxNum = atoi(argv[1]);
    if (maxNum < 2) {
        return 0;
    }

    vector<bool> primes(maxNum + 1, true);
    for (int i = 2; i < primes.size() - 1; i++)
    {
        for (int j = i + 1; j < primes.size(); j++) {
            if (!primes[j])
                continue;
            if (j % i == 0)
                primes[j] = false;
        }
    }

    for (int i = 2; i < maxNum; i++)
        if (primes[i])
            cout << i << " ";
    cout << endl;

    return 0;
}
