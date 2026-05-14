#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void binarySearch(int arr[], int key, int start, int end);

int main() {
    int choice, size = 0;
    int* arr = nullptr;

    do {
        cout << "\nFinal Project" << endl;
        cout << "[1] - Create Array" << endl;
        cout << "[2] - Sequential Search" << endl;
        cout << "[3] - Binary Search" << endl;  
        cout << "[4] - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                if (arr != nullptr) delete[] arr; // Clean previous memory
                cout << "Enter the size of the array: ";
                cin >> size;
                arr = new int[size];
                cout << "Enter the elements of the array: ";   
                for (int i = 0; i < size; i++) {
                    cin >> arr[i];
                }
                break;
            }
            case 2: {
                if (arr == nullptr) {
                    cout << "Please create the array first (Option 1)." << endl;
                    break;
                }
                int key;
                cout << "Enter the element to search: ";
                cin >> key;

                auto start = high_resolution_clock::now();
                bool found = false;
                for (int i = 0; i < size; i++) {
                    if (arr[i] == key) {
                        found = true;
                        break;
                    }
                }
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(end - start);

                cout << (found ? "Element found." : "Element not found.") << endl;
                cout << "Time taken for sequential search: " << duration.count() << " ns" << endl;
                break;
            }
            case 3: {
                if (arr == nullptr) {
                    cout << "Please create the array first (Option 1)." << endl;
                    break;
                }
                int key;
                cout << "Enter the element to search: ";
                cin >> key;

                // Sorting
                auto startSort = high_resolution_clock::now();
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            swap(arr[j], arr[j + 1]);
                        }
                    }
                }
                auto endSort = high_resolution_clock::now();
                auto sortDuration = duration_cast<nanoseconds>(endSort - startSort);
                cout << "Time taken for sorting the array: " << sortDuration.count() << " ns" << endl;

                // Binary Search
                auto startSearch = high_resolution_clock::now();
                binarySearch(arr, key, 0, size - 1);
                auto endSearch = high_resolution_clock::now();
                auto searchDuration = duration_cast<nanoseconds>(endSearch - startSearch);
                cout << "Time taken for binary search: " << searchDuration.count() << " ns" << endl;

                break;
            }
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    delete[] arr; // Free memory at the end
    return 0;
}

// Recursive Binary Search
void binarySearch(int arr[], int key, int start, int end) {
    if (start > end) {
        cout << "Element not found." << endl;
        return;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == key) {
        cout << "Element found at index: " << mid << endl;
        return;
    } else if (arr[mid] > key) {
        return binarySearch(arr, key, start, mid - 1);
    } else {
        return binarySearch(arr, key, mid + 1, end);
    }
}
