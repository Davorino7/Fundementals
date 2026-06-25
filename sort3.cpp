#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void printStep(vector<int>& arr, string label) {
    cout << label << ": ";
    printArray(arr);
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
        printStep(arr, "Pass " + to_string(i + 1));
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
        printStep(arr, "Step " + to_string(i + 1));
    }
}
void merge(vector<int>& arr, int left, int mid, int right) {
     vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
        printStep(arr, "Merged ");
    }
}
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid  = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
} 
void quickSort(vector<int>& arr, int low, int high) {
     if (low >= high) return;

    int pivotIndex = partition(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}
vector<int> getUserArray() {
    int size, value;
    cout << "Enter number of elements: ";
    cin >> size;
    vector<int> arr;
    for (int i = 0; i < size; i++) {
        cout << "Enter element: " << i + 1 << ": ";
        cin >> value;
        arr.push_back(value);
    }
    return arr;
}

int main() {
    int choice;
    do {
        cout << "\n====== Sorting Visualizer ======\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Exit\n";
        cout << "Choose algorithm: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            vector<int> arr = getUserArray();
            cout << "\nOriginal: ";
            printArray(arr);
            cout << "\n--- Step by step ---\n";

            switch (choice) {
                case 1: bubbleSort(arr); break;
                case 2: selectionSort(arr); break;
                case 3: mergeSort(arr, 0, arr.size() - 1); break;
                case 4: quickSort(arr, 0, arr.size() - 1); break;
            }

            cout << "\nFinal result: ";
            printArray(arr);
        } else if (choice != 5) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    cout << "Program closing..!\n";

    return 0;
}
