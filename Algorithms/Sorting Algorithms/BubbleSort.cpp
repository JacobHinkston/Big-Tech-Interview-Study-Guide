#include <iostream>
using namespace std;


void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void printArray(int someArray[], int length){
    cout << "[";
	for(int i = 0; i < length; i++){
		if(i != length - 1) cout << someArray[i] << ",";
		else cout << someArray[i];
	}
    cout << "]" << endl;
}

void BubbleSort(int someArray[], int length){
    /*
     * Bubble sort time complexity:
     * Best Ω(n), because if the array is already sorted then nothing happens.
     * Worst θ(n^2), because if the array is reversed from sorted, then it touches exactly n^2 elements.
     * Average O(n^2), because the upper bound is θ(n^2) and the lower bound is Ω(n), it has to fall in between.
     */
    for(int i = 0; i < length; i++){
        for(int j = i+1; j < length; j++){
            if(someArray[i] > someArray[j]){
                swap(&someArray[i], &someArray[j]);
            }
        }
    }
}

int main(int argc, char* argv[]){
    int someArray[8] = {6,5,3,1,8,7,2,4};
    int lengthOfArray = sizeof(someArray) / sizeof(someArray[0]);

    cout << "Before BubbleSort: ";
    printArray(someArray, lengthOfArray);
    BubbleSort(someArray, lengthOfArray);
    cout << "After BubbleSort: ";
    printArray(someArray, lengthOfArray);

    return 0;
}