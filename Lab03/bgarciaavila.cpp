#include <iostream>

using namespace std;

int maximum(int a, int b, int c) {
	if (a >= b && a >= c) {
		return a;
	}
	else if (b >= a && b >= c) {
		return b;
	}
	else {
		return c;
	}
}

int FindMaxCrossSubarray(int A[], int low, int mid, int high) {
	int leftSum = INT_MIN; //negative infinity = -2147483647
	int sum = 0;
	int maxLeft;

	for (int i = mid; i >= low; i--) {
		sum += A[i];

		if (sum > leftSum) {
			leftSum = sum;
			maxLeft = i;
	}
}

	int rightSum = INT_MIN; //negative infinity = -2147483647
	sum = 0;
	int maxRight;

	for (int j = mid + 1; j <= high; j++) {
		sum += A[j];

		if (sum > rightSum) {
			rightSum = sum;
			maxRight = j;
		}

	}

	return leftSum + rightSum;
}

int FindMaxSubarray(int A[], int low, int high) {
	if (high == low) {
		return A[low];
	}

	int mid = (low + high)/2;

	return maximum(FindMaxSubarray(A, low, mid), FindMaxSubarray(A, mid + 1, high), FindMaxCrossSubarray(A, low, mid, high));
}


int main() {
	int size, maxSum;

	cin >> size;

	int A[size];

	for (int i = 0; i < size; i++) {
		cin >> A[i]; 
	}

	maxSum = FindMaxSubarray(A, 0, size - 1);
	cout << maxSum;
}