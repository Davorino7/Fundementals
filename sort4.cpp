#include <iostream>                               // Binary Search
#include <vector> 
using namespace std;

// TODO 1: linearSearch — check every element
// loop through arr, if arr[i] == target return i
// if loop finishes without finding it, return -1
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// TODO 2: binarySearch — halve the range each step
// left = 0, right = arr.size() - 1
// while left <= right:
//   mid = (left + right) / 2
//   if arr[mid] == target → return mid
//   if arr[mid] < target  → left = mid + 1 (search right half)
//   if arr[mid] > target  → right = mid - 1 (search left half)
// if not found, return -1
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) { 
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {11, 12, 22, 25, 34, 64, 90};  // must be sorted!

    int target;
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\nEnter target to search: ";
    cin >> target;

    int linResult = linearSearch(arr, target);
    cout << "\nLinear search: ";
    if (linResult != -1)
        cout << "Found at index " << linResult << "\n";
    else
        cout << "Not found\n";

    int binResult = binarySearch(arr, target);
    cout << "Binary search: ";
    if (binResult != -1)
        cout << "Found at index " << binResult << "\n";
    else
        cout << "Not found\n";

    return 0;
}