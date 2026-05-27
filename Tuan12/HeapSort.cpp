#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    cout << "[ "; for (int i = 0; i < arr.size(); i++) cout << arr[i] << " "; cout << "]" << endl;
}
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; int left = 2 * i + 1; int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) { swap(arr[i], arr[largest]); heapify(arr, n, largest); }
}
void heapSort(vector<int>& arr) {
    int n = arr.size();
    cout << "Tao dong ban dau" << endl;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); cout << "Sau khi vun dong tai node" << i << ": "; printArray(arr);
    }
    cout << "Sap xep vun dong " << endl;
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); cout << "Hoan vi nut goc voi mang dang xet[" << i << "]: "; printArray(arr);
        heapify(arr, i, 0); cout << "Vun dong lai nut goc: "; printArray(arr);
    }
}

int main() {
    vector<int> arrSlide = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    cout << "Cay trong slide" << endl;
    cout << "Mang ban dau: "; printArray(arrSlide);
    heapSort(arrSlide);
    return 0;
}