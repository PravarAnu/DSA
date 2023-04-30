/* Linear Probing */

#include <iostream>
using namespace std;

class MyHash{
private:
    
    int hash(int key){
        return (key % capacity);
    }

public:

    int *arr;
    int capacity, size;

    MyHash(int c){
        capacity = c;
        size = 0;
        for(int i=0; i<capacity; i++){
            arr[i] = -1;
        }
    }


    void getSize(){
        cout<<"Size of the HashTable is: "<< this->size << endl;
    }

    void getCapacity(){
        cout<<"Capacity of the HashTable is: "<< this->capacity << endl;
    }

    bool search(int key){
        int h = hash(key);
        int i = h;
        while(arr[i] != -1){
            if(arr[i] == key){
                return true;
            }

            i = (i+1)%capacity;
            if(i==h){
                return false;
            }
        }
        return false;
    }

    bool insert(int key){
        int h = hash(key);
        int i = h;
        
        while(arr[i] != -1 && arr[i] != -2 && arr[i]!=key){
            i = (i+1)%capacity;
        }

        if(arr[i] == key){
            return false;
        }
        else{
            arr[i] = key;
            size++;
            return true;
        }
    }

    bool erase(int key){
        int h = hash(key);
        int i = h;

        while(arr[i]!=-1){
            
            if(arr[i] == key){
                arr[i] = -2;
                return true;
            }
            
            i = (i+1)%capacity;

            if(i==h){
                return false;
            }
        }

        return false;
    }
};

int main(){
    MyHash *hash1 = new MyHash(7);

    hash1->getSize();
    hash1->getCapacity();

    cout<<hash1->insert(49)<<endl;
    cout<<hash1->insert(50)<<endl;
    cout<<hash1->erase(49)<<endl;
    cout<<hash1->insert(51)<<endl;
    cout<<hash1->insert(63)<<endl;
    cout<<hash1->insert(65)<<endl;
    hash1->getSize();
    cout<<hash1->search(62)<<endl;
    cout<<hash1->insert(70)<<endl;

    hash1->getSize();
    hash1->getCapacity();

    return 0;
}