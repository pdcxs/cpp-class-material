#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    // this example
    // vector is better
    int n = 10;
    vector<unique_ptr<int[]>> pascalTrig(n);

    for (int i = 0; i < n; i++)
    {
        pascalTrig[i] = make_unique<int[]>(i + 1);
        pascalTrig[i][0] = 1;

        if (i == 0)
            continue;
        for (int j = 1; j <= i; j++)
        {
            if (j == i)
            {
                pascalTrig[i][j] = 1;
            }
            else
            {
                pascalTrig[i][j] =
                    pascalTrig[i - 1][j - 1] +
                    pascalTrig[i - 1][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << pascalTrig[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    return 0;
}
