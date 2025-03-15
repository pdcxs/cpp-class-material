#include <iostream>
#include "string_utility.h"
#include "josephus_ring.h"

using namespace std;

bool parseLine();
optional<pair<int, int>> getTwoNums(const string& s);

int main()
{
    cout << "Please input ring size and step size.\n"
         << "Input a blank line will exit this program"
         << endl;

    while (parseLine());

    return 0;
}

// return false to exit program.
bool parseLine()
{
    string input;
    cout << ">>> ";
    getline(cin, input);

    if (isBlack(input))
        return false;
    
    auto nums = getTwoNums(input);
    if (!nums.has_value()) {
        return true;
    }

    auto [ringSize, stepSize] = nums.value();

    if (stepSize < 1)
    {
        cout << "Step size should be an positive number"
             << endl;
        return true;
    }

    optional<josephus::Ring> ring = josephus::create(ringSize);
    if (!ring.has_value())
    {
        cout << "Cannot create a Josephus ring with "
             << ringSize << " elements." << endl;
        return true;
    }

    auto result = josephus::run(ring.value(), stepSize);
    josephus::printResult(result);
    return true;
}

optional<pair<int, int>> getTwoNums(const string& s) {
    vector<string> nums = words(s);
    if (nums.size() != 2)
    {
        cout << "Need 2 numbers, but you provide "
             << nums.size() << " number";
        cout << (nums.size() <= 1 ? "." : "s.")
             << endl;
        return nullopt;
    }

    optional<int> num1 = toInt(nums[0]);
    if (!num1.has_value())
    {
        cout << "Cannot convert " << nums[0]
             << " to an integer." << endl;
        return nullopt;
    }

    optional<int> num2 = toInt(nums[1]);
    if (!num2.has_value())
    {
        cout << "Cannot convert " << nums[1]
             << " to an integer." << endl;
        return nullopt;
    }
    return {{num1.value(), num2.value()}};
}