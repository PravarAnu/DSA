# Data Structure & Algorithm

## Array
*Array is a static linear data structure which stores similar type of data item stored at contiguous memory location.*

### Advantages:
- It allows random access to elements.
- It is fast to access.
- It is easy to implement.

### Disadvantages:
- It's size is fixed.
- Insertion and deletion is difficult to implement because it stores data in contiguous memory location and to do this we have to shift all the elements.

### Real Life Examples:
- The contact list in our phone represents the feature of array because when we add a new contact all the contacts shifts and the same thing happens when we delete a contact. 


## Linked List
*Linked List is a dynamic linear data structure which stores similar type of data items stored at random memory location and each data is stored in a shell which is known as node which has a value bucket and a pointer bucket, value bucket stores value and the pointer bucket stores the address of the next node. That's why they are called linked list*
    
### Advantages:
- It has dynamic size.
- We can easily insert and delete elements in it.

### Disadvantages:
- Random access of element is not allowed.
- Extra memory required for pointer.

### Real Life Examples-
- Image viewer uses linked list to link images with two buttons previous and next, with which we can move forward or backward.


## Stack
*Stack is a linear data structure which follows a perticular order in which operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out). It can be implemented by both Array or Linked List. Mainly there are three operations performed in the stack.*
- Push(For adding item into the stack.)
- Pop(For removing the item from the stack.)
- Peek or Top(Shows what is the top most item.)

### Advantages:
- It is easy to implement.
- It can be implemented by array or linked list.
- In the implementation through array there is no need of pointer which saves space. 
- In the implementation through linked list the stack can grow or shrink at the runtime.

### Disadvantages:
- It is not dynamic.
- In implementation through array, we can't increase or decrease the size of stack at the runtime.
- In implementation through linked list, there is a need of extra memory due to pointers.

### Real Life Examples:
- In canteen the plates are stacked over one another. The plate which is at top is firstly removed and the last plate which was placed very firstly can remain in the stack for the longest time.


## Queue
*Queue is a linear data structure which follows a particular order in which operations are performed. The order is FIFO(First In First Out).Mainly there are four operations performed on the queue.*
- Enqueue(For adding item into the queue.)
- Dequeue(For removing item from the queue.)
- Front(Show the front item of the queue.)
- Rear(Show the last item of the queue.)

### Advantages:
- It is easy to implement.
- Implemented using linked list.

### Disadvantages:
- It is static, not dynamic.