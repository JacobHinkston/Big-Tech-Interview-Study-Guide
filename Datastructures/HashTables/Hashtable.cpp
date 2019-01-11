
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct HashTableItem {
    string data;
    HashTableItem* next;
    HashTableItem(string data, HashTableItem* next){
        this->data = data;
        this->next = next;
    }
};

const int MAX_HASHTABLE_SIZE = 100;

class Hashtable {
    public:
        Hashtable(){
            numCollisions = 0;
        }
        ~Hashtable(){}
        void addItem(string str){
            int hash = getHash(str);
            HashTableItem* newHashTableItem = new HashTableItem(str, NULL);
            if(hashTable[hash]){
                numCollisions++;
                HashTableItem* c = NULL;
                for(c = hashTable[hash]; c->next; c=c->next);
                c->next = newHashTableItem;
            } else {
                hashTable[hash] = newHashTableItem;
            }
            cout << "Added " + str << endl;
        }
        void removeItem(string str){
            if(isInTable(str)){
                int hash = getHash(str);
                HashTableItem* c = hashTable[hash];
                if(c->data == str){
                    hashTable[hash] = c->next;
                    delete c;
                } else {
                    bool found = false;
                    for(;c && !found; c=c->next){
                        if(c->next && c->next->data != str){
                            HashTableItem* temp = c->next;
                            c->next = c->next->next;
                            delete temp;
                            found = true;
                            cout << "Deleted hashtable item, " + str + ".";
                        }
                    }
                }
            } else {
                cout << "Could not find " + str + " in the hashtable" << endl;
            }   
        }
        bool isInTable(string str){
            return (searchTable(str) ? true : false);
        }
        void printHashTable(){
            cout << "-----Hashtable-----" << endl;
            for(int i = 0; i < hashTableSize; i++){
                cout << "[" << i <<  "]: ";
                for(HashTableItem* c = hashTable[i]; c; c=c->next){
                    if(c) {
                        cout << c->data;
                        if(c->next) cout << "->";
                    } else {
                        cout << "NULL";
                    }
                }
                cout << endl;
            }
            cout << "------------------" << endl;
        }
        int getNumCollisions(){ return numCollisions; }
    private:
        int numCollisions;
		int hashTableSize = MAX_HASHTABLE_SIZE;
        HashTableItem* hashTable[MAX_HASHTABLE_SIZE]; 
        HashTableItem* searchTable(string str){
            int hash = getHash(str);
            HashTableItem* c = NULL;
            for(c = hashTable[hash]; c ; c=c->next){
                if(c->data == str) return c;
            }
            return c;
            
        }
        int getHash(string str){
            int hash = 5381;
            for(int i=0; i<str.length(); i++){
                hash = hash * 33 + str[i];
            }
            hash = hash % hashTableSize;
            if(hash < 0) hash += hashTableSize;
            return hash;
        }
};
int main(int argc, char* argv[]){
    Hashtable hashTable;
    hashTable.printHashTable();
    return 0;
}
