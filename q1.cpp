#include <iostream>
#include <vector>
using namespace std;

void findCombinations(vector<int>& arr, int sum, vector<int>& current, int start) {
    if (sum == 0) {
        for (int num : current)
            cout << num << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= sum; i++) {
        current.push_back(i);
        findCombinations(arr, sum - i, current, i);
        current.pop_back();
    }
}

void generateNumbersWithSum(int sum) {
    vector<int> arr;
    vector<int> current;
    findCombinations(arr, sum, current, 1);
}

int main() {
    int sum = 5;
    cout << "All combinations of numbers that add up to " << sum << ":\n";
    generateNumbersWithSum(sum);
    return 0;
}
