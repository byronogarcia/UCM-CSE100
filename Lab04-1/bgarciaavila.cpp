#include <iostream>
#include <vector>
#include <string>

using namespace std;

void heapify(int A[], int length, int index) {
    //Properties of a Heap:
    int LEFT = (2 * index) + 1; 
    int RIGHT = (2 * index) + 2;

    //Assume parent is largest
    int largest = index;  
    
    if (LEFT < length && A[LEFT] > A[largest]) {
        largest = LEFT;
    }
    if (RIGHT < length && A[RIGHT] > A[largest]) {
        largest = RIGHT;
    }

    if (largest != index) {
        swap(A[index], A[largest]);
        heapify(A, length, largest);
    }
}

void heapSort(int A[], int shift) {
    for (int i = (shift / 2) - 1; i >= 0; i--) {
        heapify(A, shift, i);
    }
    for (int i = (shift - 1); i >= 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main() {
	int size;
    cin >> size;

    int A[size];

    //Filling in array A
    for (int i = 0; i < size; i++) {
        cin >> A[i];
    }

    heapSort(A, size);

    //Printing sorted list
    for (int i = 0; i < size; i++) {
        cout << A[i] << ";";
    }

}
