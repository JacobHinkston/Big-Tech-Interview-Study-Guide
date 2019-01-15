#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* parent;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int data, TreeNode* parent){
        this->data = data;
        this->parent = parent;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

class Tree{ 
    public:
        Tree(){
            root = NULL;
            numTreeNodes = 0;
        }
        ~Tree(){ }
        TreeNode* getRoot(){ return root; }
        void addTreeNode(int data){
            TreeNode* newTreeNode = new TreeNode(data, NULL);
            if(root) {
                bool isPlaced = false;
                TreeNode* c = root;
                while(!isPlaced){
                    if(data <= c->data){
                        if(c->leftChild) c = c->leftChild;
                        else {
                            c->leftChild = newTreeNode;
                            newTreeNode->parent = c;
                            isPlaced = true;
                        }
                    } else if(data > c->data){
                        if(c->rightChild) c = c->rightChild;
                        else {
                            c->rightChild = newTreeNode;
                            newTreeNode->parent = c;
                            isPlaced = true;
                        }
                    }
                }
            } else {
                root = newTreeNode;
            }
            cout << "Node with data, " << data << " has been added to the tree." << endl;
        }
        TreeNode* findTreeNode(int data){
            if(root) {
                bool isRunning = true;
                TreeNode* c = root;
                while(isRunning){
                    if(!c){
                        isRunning = false;
                    } else if(data < c->data){
                        c = c->leftChild;
                    } else if(data > c->data){
                        c = c->rightChild;
                    } else {
                        return c;
                    }
                }
            } else {
                cout << "Tree is empty, nothing to find." << endl;
            }
            return NULL;
        }
        void deleteTreeNode(int data){
            /*
             * To delete a node in a BST, we have to maintain the BST property: 
             * All descendants to the left must be <= parent, and all descendants to the right must be > the parent.
             * To do this properly, without losing data, we have 3 main cases to look at:
             * 
             * Case 1: The node to delete has 0 children.
             * Case 2: The node to delete has 1 child.
             * Case 3: The node to delete has 2 children.
             * 
             * Not using recursion so that it is easier to follow the cases down.
             */
            TreeNode* nodeToDelete = findTreeNode(data);
            if(nodeToDelete){
                 if(nodeToDelete->leftChild && nodeToDelete->rightChild){
                     TreeNode* minNode = findMin_right(nodeToDelete->rightChild);
                     TreeNode* maxNode = NULL;
                     if(minNode){
                         nodeToDelete->data = minNode->data;
                         if(minNode->parent == nodeToDelete){
                            if(minNode->rightChild){
                                nodeToDelete->rightChild = minNode->rightChild;
                                minNode->rightChild->parent = nodeToDelete;
                            } else {
                                nodeToDelete->rightChild = NULL;
                            }
                         } else {
                             minNode->parent->leftChild = NULL;
                         } 
                         delete minNode;
                     } else { 
                        maxNode = findMax_left(nodeToDelete->leftChild);
                     }
                 } else if(nodeToDelete->leftChild){
                     if(nodeToDelete == root){
                         TreeNode* temp = root;
                         root = root->leftChild;
                     }else if(nodeToDelete->parent->leftChild == nodeToDelete){
                         nodeToDelete->parent->leftChild = nodeToDelete->leftChild;
                     } else {
                         nodeToDelete->parent->rightChild = nodeToDelete->leftChild;
                     }
                     delete nodeToDelete;
                 } else if(nodeToDelete->rightChild){
                     if(nodeToDelete == root){
                         TreeNode* temp = root;
                         root = root->rightChild;
                  
                     } else if(nodeToDelete->parent->leftChild == nodeToDelete){
                         nodeToDelete->parent->leftChild = nodeToDelete->rightChild;
                     } else {
                         nodeToDelete->parent->rightChild = nodeToDelete->rightChild;
                     }
                     delete nodeToDelete;
                } else {
                    if(nodeToDelete == root){
                        root = NULL;
                        delete root;
                    } else if(nodeToDelete->parent->leftChild == nodeToDelete){
                        nodeToDelete->parent->leftChild = NULL;
                    } else {
                        nodeToDelete->parent->rightChild = NULL;
                    }
                    delete nodeToDelete;
                }
                cout << "Deleted node with data, " << data << "." << endl;
            } else {
                cout << "Node with data, " << data << " was not found. Nothing to delete." << endl;
            }
        }

        /*
         * Binary Tree Traversal
         * Traversing a BST (Or any tree for that matter) is very important in big interviews, and will require you to understand the following:
         * Breadth first:
         *  - Level-order Traversal
         * Depth First:
         *  - In-order Traversal (Most common) <left><root><right>
         *  - Pre-order Traversal <root><left><right>
         *  - Post-Order Traversal <left><right><root>
         */
        
        void inOrderTraversal(TreeNode* head){
            if(!head) return;
            inOrderTraversal(head->leftChild);
            cout << head->data << endl;
            inOrderTraversal(head->rightChild);
        }
        void preOrderTraversal(TreeNode* head){
            if(!head) return;
            cout << head->data << endl;
            inOrderTraversal(head->leftChild);
            inOrderTraversal(head->rightChild);
        }
        void postOrderTraversal(TreeNode* head){
            if(!head) return;
            inOrderTraversal(head->leftChild);
            inOrderTraversal(head->rightChild);
            cout << head->data << endl;
        }

        /*
         * Binary Tree Interview Questions:
         */

        /*
        * Interview Question 4.2: Minimal Tree
        * Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
        */

       /*
        * Interview Question 4.3: List of depths.
        * Given a binary tree, design an algorithm which creates a linkedlist of all the nodes at each depth.
        * (e.g., if you have a tree with depth d, you'll have D linked lists).
        */

       /*
        * Interview Question 4.4: Check Balanced.
        * Implement a method to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that
        * the heights of the two subtrees of any node never differ by more than one.
        */

       /*
        * Interview Question 4.5: Validate BST.
        * Implement a method to check if a binary tree is a binary search tree, or not.
        */

       /*
        * Interview Question 4.6: Successor.
        * Write an algorithm to find the "next" node (i.e, in-order Successor) of a given node in a binary search tree.
        * You may assume that each node has a link to its parent.
        */
       
       /*
        * Interview Question 4.8: First common ancestor:
        * Design an algorithm and write code to find the first common ancestor of two nodes in a binary search tree. 
        * Avoid strong additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.
        */

       /*
        * Interview Question 4.9: BST sequences
        * A Binary search tree was created by traversing through an array from left to right and inserting each element.
        * Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.
        * 
        * EXAMPLE
        * Input:
        * 
        *    2
        *   /\
        *  1 3 
        * 
        * Output:
        * {2,1,3},{2,3,1}
        */

       /*
        * Interview Question 4.10: Check Subtree.
        * T1 and T2 are two very large binary trees, with T1 much bigger than T2.
        * Create an algorithm to determine if T2 is a subtree of T1.
        * A tree, T2, is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2.
        * That is, if you cut off the tree at node n, the two trees are identical.
        */

       /*
        * Interview Question 4.11: Random Node:
        * You are implementing a binary tree class from scratch, which, in addition to insert, find, and delete, has a method getRandomNode() which returns a random node from the tree.
        * All nodes should be equally likely to be chosen. Design and implement an algorithm for getRandomNode, and explain how you would implement the rest of the methods.
        */

       /*
        * Interview Question 4.12: Paths with Sum.
        * You are given a binary tree in which each node contains an integer value (which might be positive or negative). 
        * Design an algorithm to count the number of paths that sum to a given value. The path does not need to start or end at the root or a leaf, but it must go downwards
        * (Traveling only from parent nodes to child nodes).
        */




       

       
        
    private:
        TreeNode* findMin_right(TreeNode* head){
            TreeNode* minNode = head;
            for(TreeNode* c = head; c; c=c->leftChild){
                if(c->data < minNode->data) minNode = c;
            }
            return minNode;
        }

        TreeNode* findMax_left(TreeNode* head){
            TreeNode* maxNode = head;
            for(TreeNode* c = head; c; c=c->rightChild){
                if(c->data > maxNode->data) maxNode = c;
            }
            return maxNode;
        }
        TreeNode* root;
        int numTreeNodes;
};

int main(int argc, char* argv[]){
    Tree tree;
    int testData[7] = {5,3,12,10,9,1,2};
    for(int i = 0; i<7; i++) tree.addTreeNode(testData[i]);
    tree.inOrderTraversal(tree.getRoot());
    cout << endl;


    
}
