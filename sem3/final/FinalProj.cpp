//sequential search
//bbinary search

#include <iostream>
#include <chrono>
using namespace std;

int binarySearch(int arr[],int key,int start,int end,int comparison);

int main(){
int size;
cout << "Enter the size of the array: ";
cin >> size;
int *arr = new int[size];
cout << "Enter the elements of the array(separated by space): ";   
for(int i = 0; i < size; i++) {
    cin >> arr[i];
}
int key;
cout << "Enter the element to search: ";
cin >> key;
cout << endl;
//sequensearch
int sequen_comparison = 0;
auto sequen_start = chrono::steady_clock::now();
bool found = false;
for(int i = 0; i < size; i++) {
    sequen_comparison++;
    if(arr[i] == key) {
        found = true;
        break;
    }
}
auto sequen_end = chrono::steady_clock::now();
chrono::nanoseconds sequen_duration = sequen_end - sequen_start;

cout << "Sequential Search" << endl;
cout << "\tSearch Time: " << sequen_duration.count() << " ns" << endl;
cout << "\tNumber of comparisons: " << sequen_comparison << endl;
if(found) {
    cout << "\tResults: Found" << endl;
} else {
    cout << "\tResults: Not found" << endl;
}

//sorting 
auto bubble_start = chrono::steady_clock::now();
for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
        }
}
auto bubble_end = chrono::steady_clock::now();
chrono::nanoseconds bubble_duration = bubble_end - bubble_start;
cout << "Binary Search" << endl;
cout << "\tSorted Data: ";
for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}
cout << endl;
cout << "\tSorting Time: " << bubble_duration.count() << " ns" << endl;

//binary search
auto binary_start = chrono::steady_clock::now();
int binary_comparison = binarySearch(arr, key, 0, size - 1, binary_comparison);
auto binary_end = chrono::steady_clock::now();
chrono::nanoseconds binary_duration = binary_end - binary_start;
cout << "\tSearch Time: " << binary_duration.count() << " ns" << endl;
cout << "\tComparison: " << binary_comparison << endl;
cout << "Exiting program..." << endl;
delete[] arr; 
cout << "Made by: ACEDERA, KRUSCHEV HADRIEL B. " << endl;
cout << "Student No: 202211802" << endl;
cout << "Section: TN01" << endl;
return 0;
}


//divide half check lower upper, pass mid 1 to end if higher, mid + 1 to start if lower
int binarySearch(int arr[], int key, int start, int end, int comparison) {
    comparison++;
    int mid = (start + end) / 2;
    if (start > end) {
        cout << "\tResults: Not Found" << endl;
        return comparison;
    }
    if (arr[mid]==key){
        cout << "\tResults: Found" << endl;
        return comparison;
    } else if (arr[mid] > key) {
        return binarySearch(arr, key, start, mid - 1,comparison);
    } else {
        return binarySearch(arr, key, mid + 1, end,comparison);
    }
}
