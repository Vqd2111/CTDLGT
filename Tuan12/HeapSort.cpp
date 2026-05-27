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

int main() {
    cout << "--- KHOI TAO DU AN HEAP SORT ---\n";
    return 0;
}