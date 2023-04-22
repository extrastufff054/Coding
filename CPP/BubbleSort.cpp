#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            // If no swap occurred, the array is already sorted
            break;
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 7, 3, 9, 1};

    cout << "Before sorting: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    bubbleSort(arr);

    cout << "After sorting: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
