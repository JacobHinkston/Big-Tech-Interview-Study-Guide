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

void merge(int* someArray, int low, int high, int mid){
	// We have low to mid and mid+1 to high already sorted.
    int temp[high-low+1]; // Temp array to store the values of the new sorted values.
    int i = low; // i goes through the left most elements.
	int j = mid + 1; // j goes throught the right most elements.
    int k = 0; // K points to the index in temp that needs to be added.
    
 
    // Merge the two parts into temp[].
    while (i <= mid && j <= high){ // While J and i are not at their sections of the main array.
        if (someArray[i] < someArray[j]){ // If the array value at i is less the array value at j, put i into temp.
            temp[k] = someArray[i]; 
            k++, i++; // Increment the pointer to i and k.
        }else{ // else j is smaller, so put j in the value of k instead.
            temp[k] = someArray[j];
            k++, j++; // increment the pointer to K and J.
        }
    }

    while (i <= mid){ // Only way the following loops are reached is if one of the statments above fails. Meaning, we have iterated over one of the major Left/Right subsections.
        temp[k] = someArray[i]; // Point the value of K at somearray to be equal to the the value at somearray at i.
        k++, i++;
    }
    
    while (j <= high){
        temp[k] = someArray[j];
        k++, j++;
    }
 
    // Assign sorted data stored in temp[] to a[].
    for (i=low; i<=high; i++) someArray[i] = temp[i-low];

}

void split(int* someArray, int low, int high){
	if (low < high){ // If the low is equal to the high, then we know we got the element by itself.
        int mid = (low + high) / 2; // Midpoint of indexes to split, and then call split again.
        split(someArray, low, mid); //We want to split the array again, on the right side and sort.
        split(someArray, mid+1, high); //Split the Array on the left side, and sort.
        merge(someArray, low, high, mid); // Merge the two halves.
    }

}


void mergeSort(int* someArray, int length){
	split(someArray, 0, length-1);
}




int main(int argc, char* argv[]){
	int someArray[8] = {6,5,3,1,8,7,2,4};
    int lengthOfArray = sizeof(someArray) / sizeof(someArray[0]);

    cout << "Before MergeSort: ";
    printArray(someArray, lengthOfArray);

    mergeSort(someArray, lengthOfArray);

    cout << "After MergeSort: ";

    printArray(someArray, lengthOfArray);
    return 0;
}