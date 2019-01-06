#include <iostream>
using namespace std;

struct StackItem{
    int data;
    StackItem* next;
};

class StackLinkedList{
    public:
        StackLinkedList(){
            stackTop = NULL;
        }
        ~StackLinkedList(){
            cout << "Reallocating memory..." << endl;
            while(!isEmpty()){
                pop();
            }
        }
        void push(int data){
            StackItem* newStackItem = new StackItem;
            newStackItem->data = data;
            if(isEmpty()) newStackItem->next = NULL;
            else newStackItem->next = stackTop;
            stackTop = newStackItem;
            cout << "Pushed: " << data << endl;
        }
        void pop(){
            if(!isEmpty()){
                StackItem* tempStackItem = stackTop;
                stackTop = stackTop->next;
                cout << "Poped: " << tempStackItem->data << endl;
                delete tempStackItem;
            } else {
                cout << "Nothing to pop, stack is empty." << endl;
            }
        }
        bool isEmpty(){
            return !stackTop;
        }
        void printStack(){
            if(!isEmpty()){
                cout << "Current stack: ";
                for(StackItem* c = stackTop; c; c=c->next){
                    cout << c->data;
                    if(c->next) cout << "<-";
                }
                cout << endl;
            } else {
                cout << "The stack is empty, nothing to print." << endl;
            }
        }
    private:
       StackItem* stackTop;

};

int main(int argc, char* argv[]){
    StackLinkedList stackLinkedList;
    stackLinkedList.push(1);
    stackLinkedList.push(2);
    stackLinkedList.push(3);
    stackLinkedList.push(4);
    stackLinkedList.push(5);
    stackLinkedList.printStack();

    return 0;
}