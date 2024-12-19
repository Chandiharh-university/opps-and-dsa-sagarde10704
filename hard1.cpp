#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(int arr[], int size) {
    vector<int> lis(size, 1);

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maxLis = 0;
    for (int i = 0; i < size; i++) {
        if (maxLis < lis[i]) {
            maxLis = lis[i];
        }
    }
    return maxLis;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of longest increasing subsequence: " << longestIncreasingSubsequence(arr, size) << endl;
    return 0;
}
