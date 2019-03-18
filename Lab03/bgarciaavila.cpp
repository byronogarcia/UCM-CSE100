#include <iostream>

using namespace std;

/*
Took out maximum function that mightve messed with compilation. It
compiled in Linux and worked with the two functions FindMaxCrossSubarray
as well as FindMaxSubarray. The finding max like functino is at the
bottom of FindMaxSubarray
*/

int FindMaxCrossSubarray(int A[], int low, int mid, int high) {
	int leftSum = INT_MIN; //negative infinity = -2147483647
	int sum = 0;
	int maxLeft;

	for (int i = mid; i >= low; i--) {
		sum += A[i];

		if (sum > leftSum) {
			leftSum = sum;
			//maxLeft = i;
		}
	}

	int rightSum = INT_MIN; //negative infinity = -2147483647
	sum = 0;
	int maxRight;

	for (int j = mid + 1; j <= high; j++) {
		sum += A[j];

		if (sum > rightSum) {
			rightSum = sum;
			//maxRight = j;
		}

	}

	return leftSum + rightSum; 
	/*
	Instead of returning (max-left, max-right, left-sum + right-sum)
	I just return leftSum + rightSum, since that is what I have been
	using for this algorithm. Another example of thios is below with
	int leftSum, rightSum, crossSum. 
	*/
}

int FindMaxSubarray(int A[], int low, int high) {

	if (high == low) {
		return A[low]; //base case: only opne element
	}
	else {
	int mid = (low + high)/2;

	//not sure how to implement (left-low, left-high, left-sum) or the right/cross alternatives
	int leftSum = FindMaxSubarray(A, low, mid); //Used int Sums instead
	int rightSum = FindMaxSubarray(A, mid + 1, high);
	int crossSum = FindMaxCrossSubarray(A, low, mid, high);

	//Finding the max of the three rightsum, leftsum, and crosssum
	if (leftSum >= rightSum && leftSum >= crossSum) {
		return leftSum;
	}
	else if (rightSum >= leftSum && rightSum >= crossSum) {
		return rightSum;
	}
	else {
		return crossSum;
	}

	}
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