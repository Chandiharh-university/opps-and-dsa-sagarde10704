#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {2, 8, 1, 4, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum element in the array: " << findMax(arr, size) << endl;
    return 0;
}
