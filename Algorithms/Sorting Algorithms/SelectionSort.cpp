#include <iostream>
using namespace std;

void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void printArray(int someArray[], int someArraySize){
    cout << "[";
	for(int i = 0; i<someArraySize; i++){
		if(i != someArraySize-1) cout << someArray[i] << ",";
		else cout << someArray[i];
	}
    cout << "]" << endl;
}

void SelectionSort(int someArray[], int length){
	/*
     * Selection sort time complexity:
     * Best Ω(n^2), because 
     * Worst θ(n^2), because if the array is reversed from sorted, then it touches exactly n^2 elements.
     * Average O(n^2), because the upper bound is θ(n^2) and the lower bound is Ω(n), it has to fall in between.
     */
	for(int i = 0; i < length-1; i++){
		int currentMin = someArray[i];
		int swapIndex = i;
		for(int j = i+1; j < length; j++){
			if(someArray[j] < currentMin){
				currentMin = someArray[j];
				swapIndex = j;
			}
		}
		swap(&someArray[i], &someArray[swapIndex]);
	}
}

int main(int argc, char* argv[]){
	int someArray[8] = {6,5,3,1,8,7,2,4};
    int length = sizeof(someArray) / sizeof(someArray[0]);

    cout << "Before Selection Sort: ";
    printArray(someArray, length);

    SelectionSort(someArray, length);

    cout << "After Selection Sort: ";
    printArray(someArray, length);
    return 0;
}