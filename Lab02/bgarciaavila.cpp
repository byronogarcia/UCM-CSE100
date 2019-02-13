#include <iostream>

using namespace std;

void Merge(int arr[], int p, int q, int r) {
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;

	//Temp arrays, split into left half and right half
	int L[n1], R[n2];

	//Copying data into left array
	for (i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}
	//Copying data into right array
	for (j = 0; j < n2; j++) {
		R[j] = arr[q + 1 + j];
	}

	//Initial indexes for first subarr, second subarr, and mergerd array
	i = j = 0;
	k = p;

	//Getting remaining elements in L and R into arr[]
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i]; 
        i++; 
        k++; 
    }

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
	}
}

void MergeSort(int arr[], int p, int r) {
	if (p < r) {
		//Getting q, which splits array
		int q = (p+r)/2;

		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);

		Merge(arr, p, q, r);
	}
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ";";
	}
}

int main() {
	int n;
	cin >> n;

	int arr [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	MergeSort(arr, 0, n - 1);
	print(arr, n);
}
