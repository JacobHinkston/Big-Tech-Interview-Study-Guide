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
                cout << "Pushed: " << data << endl;
            } else {
                cout << "The stack is full, cannot push " << data << "." << endl;
            }
        }
        void pop(){
            if(!isEmpty()){
                StackItem* tempStackItem = stack[stackTop];
                cout << "Poped: " << tempStackItem->data << endl;
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
    private:
        int stackTop;
        StackItem* stack[MAX_STACK_SIZE];

};
int main(int argc, char* argv[]){
    StackArray stackArray;
    stackArray.push(1);
    stackArray.push(2);
    stackArray.push(3);
    stackArray.push(4);
    stackArray.push(5);
    stackArray.printStack();
    stackArray.pop();
    stackArray.pop();
    stackArray.pop();
    stackArray.pop();
    stackArray.pop();
    stackArray.printStack();
    return 0;
}

/*
–  isEmpty
– isFull (esp for array-based implementa3ons) –  push
–  pop
– peek (or top)
*/