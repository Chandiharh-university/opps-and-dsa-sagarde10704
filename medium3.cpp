#include <iostream>
using namespace std;

int findMajorityElement(int arr[], int size) {
    int count = 0, candidate = -1;
    for (int i = 0; i < size; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }
    if (count > size / 2) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    int arr[] = {2, 2, 1, 1, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int majorityElement = findMajorityElement(arr, size);
    if (majorityElement != -1) {
        cout << "Majority element is: " << majorityElement << endl;
    } else {
        cout << "No majority element found" << endl;
    }
    return 0;
}
