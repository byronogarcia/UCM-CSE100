#include <iostream>
#include <vector>

using namespace std;

void quickSort(int* arr, int p, int r)
{
    if ((r - p) > 1) {
        int random_value = arr[(rand() % (r - p) + p)];
        int left = p;
        int right = r;
        right--;

        while (left < right) {
            while (left < right && arr[right] > random_value) right--;
            while (left < r + 1 && arr[left] < random_value) left++;

            if (left < right) {
                arr[left] = arr[left] + arr[right];
                arr[right] = arr[left] - arr[right];
                arr[left] = arr[left] - arr[right];
                left++;
            }
        }
        quickSort(arr, p, left);
        quickSort(arr, right, r);
    }
}


int main() {
	int size;
    cin >> size;

    int A[size];

    for (int i = 0; i < size; i++) {
        cin >> A[i];
    }

    quickSort(A, 0, size);
    for (int i = 0; i < size; i++) {
        cout << A[i] << ";";
    }
}