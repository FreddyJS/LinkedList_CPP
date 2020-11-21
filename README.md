# DoublyLinkedList for C++

C++ library that provides all the necessary methods to handle a dynamic type list.

The LinkedList needs to be created with dynamic allocation in order to work properly!

## How to use
### LinkedList Class
```c++
private:
    Item<T>* getItemPtr(size_t index);
    Item<T>* first;
    Item<T>* last;

    Item<T>* current;
    size_t index = 0;

public:
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
// The list MUST be created with dynamic allocation
LinkedList<int>* myList = new LinkedList<int>();
```
### 2. Adding elements
```c++
bool addLast(T item); // Receives the data to store, returns true if success
```
```c++
LinkedList<int>* myList = new LinkedList<int>();
myList->addLast(10);
```
### 3. Getting elements
```c++
T getFirst();
T getLast();
T get(size_t index);
```
```c++
LinkedList<int>* myList = new LinkedList<int>();
myList->addLast(10);
myList->get(0); // Get the first item that is the 10 stored
```
### 4. Removing elements
```c++
bool remove(size_t index); // Receives an index to be removed, returns true if success
```
```c++
LinkedList<int>* myList = new LinkedList<int>();
myList->addLast(10);
myList->remove(0); // Removes the first item that is the 10 stored
    
// We can also clear the list
myList->clear();
```
### 5. How to go through the list
```c++
LinkedList<int>* myList = new LinkedList<int>();
myList->addLast(10);
    
for (int i = 0; i < myList->size; i++) {
    cout << "Integer value: " << myList->get(i) << endl;
}

// You can use also a for range based, with C++11 or greater
for (int value : *myList) {
    cout << "Integer value: " << value << endl;
}
   
```
## More operations
- ###  Cyclic Shift
```c++
myList->shiftr(); // Shifts to the right
myList->shiftl(); // Shifts to the left
    
// To shift a number of times
myList->shiftr(2); // Shifts to the right 2 times
myList->shiftl(2); // Shifts to the left 2 times
```
