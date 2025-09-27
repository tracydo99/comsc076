#include <iostream>
using namespace std;

bool isMember(int arr[], int value, int start, int end) {
    if (start > end) {
        return false;
    }

    if (arr[start] == value) {
        return true;
    }

    return isMember(arr, value, start + 1, end);
}

int main() {
    int arr[5];

    cout << "Enter 5 values into the array:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> arr[i];
    }

    int searchValue;
    cout << "Search for the value: ";
    cin >> searchValue;

    if (isMember(arr, searchValue, 0, 4)) {
        cout << "True. " << searchValue << " is found in the array." << endl;
    } else {
        cout << "False. " << searchValue << " is not found in the array." << endl;
    }

    return 0;
}
