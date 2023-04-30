#include <climits>
#include <iostream>
using namespace std;

class MinHeap {
    int *arr;
    int size;
    int capacity;

  public:
    MinHeap(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    int getParent(int indexOfNode) { return (indexOfNode - 1) / 2; }

    int getLeftChild(int indexOfNode) { return ((2 * indexOfNode) + 1); }

    int getRightChild(int indexOfNode) { return ((2 * indexOfNode) + 2); }

    void insert(int node) {
        if (size == capacity) {
            cout << "\nThe capacity is full\n";
            return;
        }
        arr[size] = node;
        size++;
        for (int i = size - 1; i != 0 && arr[getParent(i)] > arr[i];) {
            swap(arr[getParent(i)], arr[i]);
            i = getParent(i);
        }

        return;
    }

    void heapify(int indexOfNode) {
        int leftChild = getLeftChild(indexOfNode);
        int rightChild = getRightChild(indexOfNode);
        int smallest = indexOfNode;

        if (leftChild < size && arr[leftChild] < arr[indexOfNode]) {
            smallest = leftChild;
        }

        if (rightChild < size && arr[rightChild] < arr[smallest]) {
            smallest = rightChild;
        }

        if (smallest != indexOfNode) {
            swap(arr[smallest], arr[indexOfNode]);
            heapify(smallest);
        }
    }

    int extractMin() {
        if (size == 0) {
            return INT_MAX;
        }

        if (size == 1) {
            size--;
            return arr[0];
        }

        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0);

        return arr[size];
    }

    void decreaseKey(int indexOfNode, int value) {
        arr[indexOfNode] = value;

        while (indexOfNode != 0 &&
               arr[getParent(indexOfNode)] > arr[indexOfNode]) {
            swap(arr[getParent(indexOfNode)], arr[indexOfNode]);
            indexOfNode = getParent(indexOfNode);
        }
    }

    void deleteAKey(int indexOfNode) {
        arr[indexOfNode] = arr[size - 1];
        size--;

        heapify(indexOfNode);
    }

    /* void deleteAKey(int indexOfNode){
        decreaseKey(indexOfNode, INT_MIN);
        cout<<extractMin()<<endl;
    } */

    void buildHeap(int arr[], int n) {
        int startIndex = (n - 2) / 2;

        for (int i = startIndex; i >= 0; i--) {
            heapify(i);
        }
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    MinHeap *heap = new MinHeap(10);

    // heap->insert(10);
    // heap->insert(20);
    // heap->insert(15);
    // heap->insert(40);
    // heap->insert(50);
    // heap->insert(100);
    // heap->insert(25);
    // heap->insert(45);

    // heap->printHeap();

    // // cout<<heap->extractMin()<<endl;
    // heap->decreaseKey(4, 12);
    // heap->printHeap();

    // Implimenting Heapify
    heap->insert(20);
    heap->insert(25);
    heap->insert(30);
    heap->insert(35);
    heap->insert(40);
    heap->insert(80);
    heap->insert(32);
    heap->insert(100);
    heap->insert(70);
    heap->insert(60);

    heap->printHeap();

    // heap->heapify(0);

    heap->deleteAKey(3);

    heap->printHeap();

    return 0;
}