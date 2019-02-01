#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	int* Sequence;
	int arraySize, key, i, j, k;

	//size of sequence
	cin >> arraySize;
	Sequence = new int[arraySize];

	//Read sequence
	for (i = 0; i < arraySize; i++) {
		cin >> Sequence[i];
	}

	//Insertion Sort
	for (i = 1; i < arraySize; i ++) {
		key = Sequence[i];
		j = i - 1;

		while (j >= 0 && Sequence[j] > key) {
			Sequence[j + 1] = Sequence[j];
			j = j - 1;
		}

		Sequence[j + 1] = key;

	//Printing output after each iteration
		for (k = 0; k <= i; k++) {
			cout << Sequence[k] << ";";
		}
		cout << endl;
	}

	//Free allocated space
	delete[] Sequence;

}