#include <iostream>
#include <vector>
using namespace std;

void combineUtil(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }

    for (int i = start; i <= n; i++) {
        current.push_back(i);
        combineUtil(n, k, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    combineUtil(n, k, 1, current, result);
    return result;
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> result = combine(n, k);
    for (const auto& comb : result) {
        for (int num : comb)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
