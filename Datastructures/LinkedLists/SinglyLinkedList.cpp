#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    public:
        SinglyLinkedList(){ head = NULL; }
        ~SinglyLinkedList(){ }
        void addNode(int data){
            Node* newNode = new Node; // Allocating memory for a new Node item.
            newNode-> data = data, newNode->next = NULL; // Setting values for the new Node item.
            if(head) { // IF there is a head pointer, meaning if the LL had been initialized with another item.
                Node* c = head; // Pointing a current node pointer to the head.
                while(c->next) c=c->next; // Traversing the LL to find the end. * WHILE c->next because if you increment c to the next while there is c vs c->next it will give a SEG FAULT.
                c->next = newNode; // Once the loop ends, pointing the end node to newNode;
            } else { // If there isnt a head pointer, point the head to the new node.
                head = newNode; 
            }
            cout << "Node with data " << data << ", has been added." << endl;
        }
        void printList(){
            if(head) { // IF there is a head pointer, meaning if the LL had been initialized with another item.
                for(Node* c = head; c; c=c->next){ //Node* c points to the head pointer, while there is a current node, go to the next;
                    cout << c->data; 
                    if(c->next) cout << "->";
                }
                cout << endl;
            } else { // If there isnt a head pointer, point the head to the new node.
                cout << "There are no nodes in this list." << endl;
            }
        }
        void deleteNode(int data){
            if(head){
                Node* c = head;
                Node* temp = head;
                while(c && c->data != data){
                    temp = c;
                    c=c->next;
                };
                if(c->data == data){
                    if(c==head){
                        if(head->next) head=head->next;
                        else head = NULL;
                    }
                    else if(c->next) temp->next = c->next;
                    else temp->next = NULL;
                    delete c;
                    cout << "The node with data " << data << ", was deleted." << endl;
                } else {
                    cout << "The node with data " << data << ", was not found." << endl;
                }
            } else {
                cout << "There are no nodes in this list." << endl;
            }
        }
        void deleteNodeAtIndex(int index){
            if(head) { 
                Node* c = head;
                Node* temp = head;
                int i = 0;
                while(c && i<index){
                    temp = c;
                    c=c->next;
                    i++;
                }
                if(i == index){
                    if(c == head){
                        if(c->next) head = head->next;
                        else head = NULL;
                    } else if (c->next == NULL) {
                        temp->next = NULL;
                    } else {
                        temp->next = c->next;
                    }
                    delete c;
                    cout << "Node at index "<< index << ", has been deleted." << endl;
                } else {
                    cout << "Node at index "<< index << ", does not exist." << endl;
                }
            } else {
                cout << "There are no nodes in this list." << endl;
            }
        }
        

    /*
     * CRACKING THE CODING INTERVIEW QUESTIONS.
     * PAGE 94 - 95.
     */

    /*
     * Interview Question 2.1: Remove Dups.
     * Write code to remove duplicates from an unsorted linkedlist.
     */

    /*
     * Interview Question 2.2: Return Kth to Last.
     * Implement an Algorithm to find the Kth to last element of a singly linked list.
     */

        void findKToLast(int k){
            Node* c = head;
            for(int i = 1; c; i++, c = c->next){
                if(i==k) cout << "K(" << k << ") to last: ";
                if(i >= k){
                    cout << c->data;
                    if(c->next) cout << "->";
                }
            }
            cout << endl;

        }

    /*
     * Interview Question 2.3: Delete Middle Node.
     * Implement an algorithm to delete a node in the middle. 
     * (i.e., any node but the first and the last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
     */
        int getLength(){
            int counter = 0;
            for(Node* c = head; c; c=c->next){
                counter++;
            }
            return counter;
        }
        
        Node* getMiddleNode(){
            int length = getLength();
            int midPoint = length/2;
            int i = 1;
            Node* c = NULL;
            for(c = head; c && i <= midPoint; c=c->next) i++;
            return c;
        }

        bool deleteMiddle(Node* ptr){
            if(ptr){
                Node* ptrTemp = ptr->next;
                cout << "Deleted node in middle with data, " << ptr->data << "." << endl;
                ptr->data = ptrTemp->data;
                ptr->next = ptr->next->next;
                delete ptrTemp;
                
            } else {
                return false;
            }
            return true;
        }
        
    /*
     * Interview Question 2.4: Partition.
     * Write code to partition a linkedlist around a value of x, such that all nodes less than x come before all nodes greater than or equal to x.
     * If x is contained within the list, the values of only x need to be after the elements less than x (see below). 
     * The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.
     * EXAMPLE:
     *  Input: 3->5->8->5->10->2->1 (partition = 5)
     *  Output: 3->1->2->10->5->->5->8
     */
        void partition(int p){
            Node* head_before = NULL;
            Node* tail_before = NULL;
            Node* head_after = NULL;
            Node* tail_after = NULL;
            Node* c = head;
            while(c){
                Node* temp = c;
                c=c->next;
                temp->next = NULL;
                if(temp->data < p){
                    if(head_before){
                        tail_before->next = temp;
                        tail_before = temp;
                    } else {
                        head_before = temp;
                        tail_before = temp;  
                    }
                } else {
                    if(head_after){
                        tail_after->next = temp;
                        tail_after = temp;
                    } else {
                        head_after = temp;
                        tail_after = temp;  
                    }
                }
            }
            tail_before->next = head_after;
            head = head_before;
        }
        
    /*
     * Interview Question 2.6: Palindrone.
     * Implement a function to check if a linkedlist is a plaindrone.
     */

        bool isPalindrone(){
            
        }
    /*
     * Interview Question 2.7: Intersection.
     * Given two (singly) linked list, determine if the two lists intersect. Return the intersecting node.
     * Note that the intersection is defined based on a reference, not value. That is, if the kth node of the first linkedlist is 
     * the exact same node (by reference) as the jth node of the second linkedlist, then they are intersecting.
     */

    /*
     * Interview Question: Given a circular linkedlist, implement an algorithm that returns the node at the begining of the loop.
     * 
     * DEFINITION
     * Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
     * 
     * EXAMPLE
     * Input: A->B->C->D->E->C [The same C as earlier]
     * Output: C
     */
        Node* getHeadPtr(){ return head; }
    private:
        
        Node* head;
};

/*
* Interview Question 2.5
* You have two numbers represdented by a linkedlist, where each node contains a single digit.
* The digits are stored in a reverse order, such that the 1's digit is at the head of the list.
* Write a function that adds the two numbers and returns the sum as a linkedlist.
* EXAMPLE:
*  Input: (7->1->6) + (5->9->2). that is, 617 + 295.
*  Output: 2->1->9. That is 912.
*/

int sumLists(SinglyLinkedList sslOne, SinglyLinkedList sslTwo){
    string strOne = "", strTwo = "";
    for(Node* c = sslOne.getHeadPtr(); c; c = c->next){
        string strEnd = strOne.substr(0);
        strOne = to_string(c->data) + strEnd;
    }
    for(Node* c = sslTwo.getHeadPtr(); c; c = c->next){
        string strEnd = strTwo.substr(0);
        strTwo = to_string(c->data) + strEnd;
    }
    return stoi(strOne) + stoi(strTwo);
    
}
int main(int argvc, char* argv[]) {
    SinglyLinkedList singlyLinkedList;
    singlyLinkedList.addNode(3);
    singlyLinkedList.addNode(5);
    singlyLinkedList.addNode(8);
    singlyLinkedList.addNode(5);
    singlyLinkedList.addNode(10);
    singlyLinkedList.addNode(2);
    singlyLinkedList.addNode(1);
    singlyLinkedList.printList();
    singlyLinkedList.partition(5);
    singlyLinkedList.printList();
    
    //sumLists
    SinglyLinkedList sslOne;
    sslOne.addNode(7);
    sslOne.addNode(1);
    sslOne.addNode(6);
    
    SinglyLinkedList sslTwo;
    sslTwo.addNode(5);
    sslTwo.addNode(9);
    sslTwo.addNode(2);
    
    cout << sumLists(sslOne, sslTwo);
    
    

    return 0;
}