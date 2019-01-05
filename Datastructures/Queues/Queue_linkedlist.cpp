#include <iostream>
using namespace std;

const int MAX_QUEUE_SIZE = 5;

struct QueueItem {
    int data;
    QueueItem* next;
};

class QueueLinkedList {
    public:
        QueueLinkedList(){
            queueFront = NULL;
            queueEnd = NULL;
            numElements = 0;
        }
        void enqueue(int data){
            QueueItem* newQueueItem = new QueueItem;
            newQueueItem->data = data;
            newQueueItem->next = NULL;
            if(!queueFront){
                queueFront = newQueueItem;
            } else {
                queueEnd->next = newQueueItem;
            }
            queueEnd = newQueueItem;
            cout << "Queued: " << data << endl;
        }
        void dequeue(){
            if(isEmpty()){
                cout << "The queue is empty, nothing to dequeue." << endl;
            } else {
                QueueItem* tempItem = queueFront;
                cout << "Dequeued: " << queueFront->data << endl;
                queueFront = tempItem->next;
                delete tempItem;
                if(!queueFront) queueEnd = queueFront;
            }
        } 
        bool isEmpty() {
            return(!queueFront);
        }
        int peek(){
            return queueFront->data;
        }
        void printQueue(){
            if(queueFront){
                cout << "Current Queue: ";
                for(QueueItem* c = queueFront; c; c=c->next){
                    cout << c->data;
                    if(c->next) cout << "<-";
                }
                cout << endl;
            } else {
                cout << "Queue is empty, nothing to print." << endl;
            }
            
        }
    private:
        QueueItem* queueFront;
        QueueItem* queueEnd;
        int numElements;

};

int main(int argc, char* argv[]) {
    QueueLinkedList queueLinkedList;
    queueLinkedList.enqueue(1);
    queueLinkedList.enqueue(2);
    queueLinkedList.enqueue(3);
    queueLinkedList.printQueue();
    queueLinkedList.dequeue();
    queueLinkedList.dequeue();
    queueLinkedList.dequeue();
    queueLinkedList.dequeue();

    // queueLinkedList.printQueue();
    return 0;
}