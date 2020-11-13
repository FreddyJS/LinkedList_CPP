# DoublyLinkedList for C++

C++ library that provides all the necessary methods to handle a dynamic type list. 

## How to use
### LinkedList Class
```c++ 
    size_t size;

    bool addLast(T item);
    T getFirst();
    T getLast();
    T get(int index);

    bool remove(size_t index);
    bool clear();

    bool shiftr();
    bool shiftr(size_t shifts);
    bool shiftl();
    bool shiftl(size_t shifts);
```
### 1. Creating a list
```c++
    LinkedList<int> myList;
    LinkedList<int> myList = LinkedList<int>();
    // For this example we create an integer list, but you can store anything!

    LinkedList<int>* myList = new LinkedList<int>();
    // This last way to create the list returns a pointer.
    // It is because using new we are calling a malloc and then the constructor
```
### 2. Adding elements
```c++
    bool addLast(T item); // Receives the data to store, returns true if success
```
```c++
    LinkedList<int> myList;
    myList.addLast(10);
```
### 3. Getting elements
```c++
    T getFirst();
    T getLast();
    T get(size_t index);
```
```c++
    LinkedList<int> myList;
    myList.addLast(10);
    myList.get(0); // Get the first item that is the 10 stored
```
### 4. Removing elements
```c++
    bool remove(size_t index); // Receives an index to be removed, returns true if success
```
```c++
    LinkedList<int> myList;
    myList.addLast(10);
    myList.remove(0); // Removes the first item that is the 10 stored
    // We can also clear the list
    myList.clear();
```
### 5. How to go through the list
```c++
    LinkedList<int> myList;
    myList.addLast(10);
    
    for (int i = 0; i < myList.size; i++) {
     cout << "Integer value: " << myList.get(i) << endl;
    }
    // Or just
    for (int value : myList) {
     cout << "Integer value: " << value << endl;
    }
   
```
## More operations
- ###  Cyclic Shift
```c++
    // To shift the items of the list (cyclic shift only)
    myList.shiftr(); // Shifts to the right
    myList.shiftl(); // Shifts to the left
    // To shift a number of times
    myList.shiftr(2); // Shifts to the right 2 times
    myList.shiftl(2); // Shifts to the left 2 times
```
