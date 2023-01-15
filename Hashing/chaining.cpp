#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class HashMap{
    Node **arr;
    int capacity;
    int size;

    int hash(int key){
        return key % capacity;
    }
public:
    HashMap(){
        this->capacity = 0;
        this->size = 0;
    }
    
    //Constructor for making a HashMap
    HashMap(int capacity){
        this->capacity = capacity;
        arr = new Node*[capacity];
        for(int i=0; i<capacity; i++){
            arr[i] = NULL;
        }
    }


    int getSize(){
        return this->size;
    }

    int getCapacity(){
        return this->capacity;
    }

    // bool search(int key){

    // }

    void insert(int key){
        cout<<"Entered in Insert"<<endl;
        int h = hash(key);

        if(arr[h] == NULL){
            arr[h]->data = key;
            arr[h]->next = NULL;
        }else{
            Node *temp = arr[h];
            Node *hashNode = new Node();
            hashNode->data = key;
            hashNode->next = NULL;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = hashNode;
        }
        size++;
    }

    void print(){
        for(int i=0; i<capacity; i++){
            Node *temp = arr[i];
            cout<<"Starting"<<endl;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    // bool erase(){

    // }

};

int main() {
    HashMap *h = new HashMap(10);
    
    h->insert(10);
    h->insert(20);
    h->getSize();
    h->insert(11);
    h->insert(12);
    h->print();
    return 0;
}