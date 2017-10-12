#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

void merge(int A[], int p, int q, int r);
void mergeSort(int A[], int p, int r);

int main(int argc, char *argv[]) {

    if (argc != 2) {
	cout << "Error: expected filename as arg.\n";
	return 0;
    }

    ifstream inFile(argv[1]);

    if (!inFile.is_open()) {
	cout << "Error: file could not open.\n";
	return 0;
    }

    vector<int> numbers;
    int number;

    while (inFile >> number) {
	numbers.push_back(number);
    }

    inFile.close();

    ofstream outFile(argv[1]);

    int array[numbers.size()];

    for (int i = 0; i < numbers.size(); i++) {
	array[i] = numbers[i];
    }

    int start = clock();

    mergeSort(array, 0, (numbers.size() - 1));

    int stop = clock();

    for (int j = 0; j < numbers.size(); j++) {
	outFile << array[j] << endl;
    }

    outFile.close();

    cout << "The file \"" << argv[1] 
	    << "\" has been sorted in "
	    << (stop - start) / (double) CLOCKS_PER_SEC * 1000000
	    << " microseconds\n";

    return 0;
}

void merge(int A[], int p, int q, int r) {
    int num1 = q - p + 1;
    int num2 = r - q;
    int L[num1];
    int R[num2];
    
    for (int i = 0; i < num1; i++){
	L[i] = A[p + i];
    }
    
    for (int j = 0; j < num2; j++) {
	R[j] = A[q + j + 1];
    }
    
    int i = 0;
    int j = 0;
    int k = p;

    while (i < num1 && j < num2) {
	
	if (L[i] <= R[j]) {
	    A[k] = L[i];
	    i++;
	}
	
	else {
	    A[k] = R[j];
	    j++;
	}

	k++;
    }

    while (i < num1) {
	A[k] = L[i];
	i++;
	k++;
    }

    while (j < num2) {
	A[k] = R[j];
	j++;
	k++;
    }
}

void mergeSort(int A[], int p, int r) {
    if (p < r){
	int q = floor((p + r) / 2);
	mergeSort(A, p, q);
	mergeSort(A, (q + 1), r);
	merge(A, p, q, r);
    }
}
