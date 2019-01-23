#include <iostream>
using namespace std;

int binarySearch_recursive(int val, int* someArray, int start, int end){
    if(start > end) return -1;
    else {
        int mid = (start + end) / 2;
        if(val < someArray[mid]){
            binarySearch_recursive(val, someArray, start, mid-1);
        } else if(val > someArray[mid]){
            binarySearch_recursive(val, someArray, mid+1, end);
        } else {
            return mid;
        }
    }
    //May throw weird memory address if you are looking for a duplicate. Not sure why.
}

int binarySearch_iterative(int val, int* someArray, int length){
    int start = 0;
    int end = length - 1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(val < someArray[mid]){
            end = mid - 1;
        } else if(val > someArray[mid]){
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(int argc, char* argv[]){
    int someArray[] = {1,2,3,4,5,6,7,8,8,9,10,12,13,24,35,46,57,68,79,80};
    int length = sizeof(someArray)/sizeof(someArray[0]);

    int searchFor = 13;

    cout << "Binary Seach recursive looking for " << searchFor << ":" << endl;
    int i = binarySearch_recursive(searchFor, someArray, 0, length-1);
    if(i != -1) cout << "Value " << searchFor << " was found at index " << i << "." << endl;
    else cout << "Value " << searchFor << " doesn't exist." << endl;
    
    
    cout << "Binary Seach iterative looking for " << searchFor << ":" << endl;
    i = binarySearch_iterative(searchFor, someArray, length);
    if(i != -1) cout << "Value " << searchFor << " was found at index " << i << "." << endl;
    else cout << "Value " << searchFor << " doesn't exist." << endl;

    return 0;
}