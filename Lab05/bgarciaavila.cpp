#include <iostream>
#include <vector>

using namespace std;

void CountingSort(vector<int> A[], int n, int pos){
    vector<int>* output;
    int i, count[4] = {0};
  
    output = new vector<int>[n];

    for (i = 0; i < n; i++) {
        count[A[i][pos] % 4]++;
    }

    for (i = 1; i < 4; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[ A[i][pos]%4 ] - 1] = A[i];
        count[A[i][pos] % 4 ]--;
    }

    // Copy over
    for (i = 0; i < n; i++)
        A[i] = output[i];
}

void RadixSort(vector<int> A[], int n) {
    int vectorSize = 10;

    for (int pos = vectorSize -1; pos >= 0 ; pos--) {
        CountingSort(A, n, pos);
    }
}

int main(){
	int size;
    cin >> size;
  
    vector<int>* A = new vector<int>[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 10; j++) {
            int value;
            cin >> value;

            A[i].push_back(value);
        }
    }

    RadixSort(A, size);

    for (int i = 0; i < size; i++) {
        vector<int>::iterator v = A[i].begin();

        while (v != A[i].end()) {
            cout << *v << ";";
            v++;
        }

        cout << endl;
    }
}