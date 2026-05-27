#include <iostream>
#include <vector>

using namespace std;

// Ham in mang sau moi thao tac
void printArray(const vector<int>& arr) {
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

// Ham vun dong tai mot node
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Vun dong lai de quy
        heapify(arr, n, largest);
    }
}

// Ham sap xep vun dong
void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    cout << "Tao dong ban dau" << endl;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        cout << "Sau khi vun dong tai node" << i << ": ";
        printArray(arr);
    }
    
    cout << "Sap xep vun dong " << endl;
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        cout << "Hoan vi nut goc voi mang dang xet[" << i << "]: ";
        printArray(arr);
        
        heapify(arr, i, 0);
        cout << "Vun dong lai nut goc: ";
        printArray(arr);
    }
}

int main() {
    // Cay vi du trong Slide
    vector<int> arrSlide = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    // Cay vi du tren bang
    vector<int> arrBoard = {203, 106, 78, 84, 59, 15, 32, 16, 10, 17, 38, 11};
    
    cout << "Cay trong slide" << endl;
    cout << "Mang ban dau: ";
    printArray(arrSlide);
    heapSort(arrSlide);
    
    cout << "\nCay tren bang" << endl;
    cout << "Mang ban dau: ";
    printArray(arrBoard);
    heapSort(arrBoard);
    
    return 0;
}