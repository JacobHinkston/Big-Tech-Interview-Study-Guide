/*
* Interview question 3.1
* Describe how you could use a SINGLE array to implement three stacks.
* Answer:
* In order to use 3 stacks in one array, we would have to partitition the array 3 ways.
* If the user wants to have each stack be X length, we have to multiply X * 3 to allocate the memory needed for each array.
* Now that we have done this, we need to have class methods to designate which stack we want to push/pop/peek on. Such as:
* push(0, {STACKNODE}); or pop(0); 0-2 being the stack's corresponding partition. 0 is stack 1, 1 is stack 2 and so on. Simple.
*/

/*
* Interview question 3.2
* How would you design a stack which, in addition to push and pop, has a method min, in which should returns the minimum element?
* Push pop and min should all operate in O(1) time.
* Answer:
* There are a few ways of going about doing this, given the questions ambiguity we can assume that no matter what we do in accordance
* with our stack, the method MIN will run in O(1) time. The first way I can think to solve this problem, is to calculate min on runtime
* within our push method. The only way for our stack items to get into the stack is to be pushed(). That being said, we can have an instance
* variable, minElement that will be updated wether it is smaller then the current min ON PUSH call. See the code snippet within the push method above.
* 
* Note: This will work on both Array and Linkedlist implementations of a stack.
*/

/*
 * Interview Question 3.3: Stack of plates.
 * Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple; 
 * Therefore, in real list, we would likely start a new stack when the previous stack exceeds some threshold. 
 * Implement a datastructure SetOfStacks that mimics this. 
 * SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity. 
 * SetOfStack.push() and SetOfStacks.pop() should behave identically to a single stack 
 * (That is, pop() should return the same values it would if there were just a single stack).
 */

/*
 * Interview Question 3.4: Queue Via Stack.
 * Implement a Queue using two stacks.
 */

/*
 * Interview Question 3.5: Sort Stack:
 * Write a program to sort a stack such that the smallest items are on the top. 
 * You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). 
 * The stack supports the following operations: push, pop, peek, and isEmpty.
 */

/*
 * Interview Question 3.6: Animal Shelter.
 * An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out" basis. 
 * People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, 
 * or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). 
 * They cannot select which specific animal they would like. 
 * Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. 
 * You may use the built-in Linked L is t data structure.
 */

#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 5;  

struct StackItem{
    int data;
};

class StackArray{
    public:
        StackArray(){
            stackTop = -1;
            minElement = NULL;
            for(int i = 0; i < MAX_STACK_SIZE; i++) {
                stack[i] = NULL;
            }
        }
        void push(int data){
            if(!isFull()){
                stackTop++;
                StackItem* newStackItem = new StackItem;
                newStackItem->data = data;
                stack[stackTop] = newStackItem;

                // INTERVIEW QUESTION 3.2
                if(minElement) {
                    if(data < minElement->data) minElement = newStackItem; 
                } else {
                    minElement = newStackItem;
                }
                
                cout << "Pushed: " << data << endl;
            } else {
                cout << "The stack is full, cannot push " << data << "." << endl;
            }

        }
        void pop(){
            if(!isEmpty()){
                StackItem* tempStackItem = stack[stackTop];
                cout << "Popped" << tempStackItem->data << endl;
                stack[stackTop] = NULL;
                delete tempStackItem;
                stackTop--;
            } else {
                cout << "Nothing to pop, stack is empty." << endl;
            }
        }
        
        bool isEmpty(){
            return(stackTop == -1);
        }
        bool isFull(){
            return(stackTop == MAX_STACK_SIZE - 1);
        }
        void printStack(){
            if(!isEmpty()){
                cout << "Current stack: ";
                for(int i = stackTop; i >=0; i--) {
                    cout << stack[i]->data;
                    if(i != 0) cout << "<-";
                }
                cout << endl;
            } else {
                cout << "The stack is empty, nothing to print." << endl;
            }  
        }
        StackItem* min(){
            return minElement;
        }
        int stackTop;
        StackItem* stack[MAX_STACK_SIZE];

        /*
         * INTERVIEW QUESTION 3.2
         * Initializzed as a pointer for scalability. If we have more data associated with the minElement that we are trying to access,
         * simply storing the min as an int will not do. The min function returns the minElement->data (int), but you can modify it to return the pointer
         * or any additional data associated with it.
        */
        StackItem* minElement; 
        

};


int main(int argc, char* argv[]){
    StackArray stackArray;
    stackArray.push(3);
    stackArray.push(2);
    stackArray.push(3);
    stackArray.push(4);
    stackArray.push(5);
    stackArray.printStack();

    StackItem* minElement = stackArray.min();
    cout << "The minimum element sits at " << minElement << ", and holds the value of " << minElement->data << "." << endl;

    SetOfStacks setOfStacks;
    setOfStacks.push(0);
    return 0;
}