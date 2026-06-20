#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            }
        }
    }
}
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size() - 1; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    vector<int> a = {64, 34, 25, 12, 22, 11, 90};
    vector<int> b = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original:       ";
    printArray(a);

    bubbleSort(a);
    cout << "Bubble sorted:  ";
    printArray(a);

    selectionSort(b);
    cout << "Selection sorted: ";
    printArray(b);

    return 0;
}