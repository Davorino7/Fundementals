#include <iostream>
#include <vector>
using namespace std;

// prints the current state of the array
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// prints array with a label — used for step-by-step output
void printStep(vector<int>& arr, string label) {
    cout << label << ": ";
    printArray(arr);
}

// TODO 1: bubble sort — add printStep() inside the outer loop
// after each pass, print the current state
// label: "Pass " + to_string(i + 1)
void bubbleSort(vector<int>& arr) {
    // your existing bubble sort here
    // add: printStep(arr, "Pass " + to_string(i + 1));
    // after the inner loop closes
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

// TODO 2: selection sort — add printStep() inside the outer loop
// after each swap, print the current state
// label: "Step " + to_string(i + 1)
void selectionSort(vector<int>& arr) {
    // your existing selection sort here
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

// TODO 3: merge sort — add printStep() inside merge()
// after copying temp back to arr, print the current state
// label: "Merged"
void merge(vector<int>& arr, int left, int mid, int right) {
    // your existing merge here
}
void mergeSort(vector<int>& arr, int left, int right) {
    // your existing mergeSort here — no changes needed
}

// TODO 4: quicksort — add printStep() inside partition()
// after placing pivot, print the current state
// label: "Pivot placed"
int partition(vector<int>& arr, int low, int high) {
    // your existing partition here
}
void quickSort(vector<int>& arr, int low, int high) {
    // your existing quickSort here — no changes needed
}

// TODO 5: getUserArray() — ask user for array size and elements
// return a vector<int> filled with user input
vector<int> getUserArray() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    vector<int> arr;
    // TODO: loop size times, ask for each element, push_back
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