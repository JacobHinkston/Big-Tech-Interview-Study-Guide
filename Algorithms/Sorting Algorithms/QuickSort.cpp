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

int partition(int* someArray, int start, int end){
	int pivot = someArray[end]; //The pivot point is always the value of the int at the end of the array. 
	int pIndex = start; // Pindex points to where the next value to swap is.
	for(int i = start; i < end; i++){ // We are going to traverse the array from the start index to the end index.
		if(someArray[i] <= pivot){ // if the value of the array at i is less then the pivot Array[end], then switch them.
			swap(&someArray[i], &someArray[pIndex]); 
			pIndex++; //Increase the swaping index.
		}
	}
	swap(&someArray[pIndex], &someArray[end]); //Once the loop is done, swap the pivot index with the index at the end.
	return pIndex; //Return the final index that you swapped to keep track of the midpoint.

}
void quickSort(int* someArray, int start, int end){
	if(start < end){ // This is out exit condition, if this fails, then we know we have reaches a 1 element segment.
		int partitionIndex = partition(someArray, start, end); // Calling partition index to swap, and receive an index to call the following calls of QuickSort below:
		quickSort(someArray, start, partitionIndex-1);
		quickSort(someArray, partitionIndex+1, end);
	}
}

int main(int argc, char* argv[]){
	int someArray[8] = {6,5,3,1,8,7,2,4};
    int lengthOfArray = sizeof(someArray) / sizeof(someArray[0]);

    cout << "Before QuickSort: ";
    printArray(someArray, lengthOfArray);

    quickSort(someArray, 0, lengthOfArray-1);

    cout << "After Quicksort: ";

    printArray(someArray, lengthOfArray);
    return 0;
}