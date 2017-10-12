#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;

void bubbleSort(int A[], int n);

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

    bubbleSort(array, numbers.size());

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

void bubbleSort(int A[], int n) {
    for (int i = 0; i < ( n - 1 ); i++) {
	for (int j = (n - 1); j > i; j--) {
	    if (A[j] < A[j - 1]) {
		int temp = A[j];
		A[j] = A[j - 1];
		A[j - 1] = temp;
	    }
	}
    }
}
