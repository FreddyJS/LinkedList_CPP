# DoublyLinkedList for C++
C ++ library that provides all the necessary methods to handle a list of any type of data. It is implemented by two classes, the "manager" class (LinkedList) and the node class (LinkedListItem).

**The LinkedList needs to be created with dynamic allocation in order to work properly**. It is because if the first or last node of the list changes we need to change the first or last pointer of the LinkedList or something will break. 

In order to prevent to use static allocation the destructor of the LinkedList Class is private. To deallocate the memory of the list you can use the public method destruct or the method destructLinkedList. The items of the list will be removed automatically.

## LinkedList Class
```c++
private:
    LinkedListItem<T>* first;
    LinkedListItem<T>* last;
    LinkedListItem<T>* current;
    size_t index = 0;
    
public:
    size_t size;
    
    bool addLast(T data);
    T getFirst();
    T getLast();
    T get(size_t index);
    void set(size_t index, T data); // Replaces the data of the item
    
    bool remove(size_t index); // Deallocates the memory of the removed item
    bool clear(); // Deallocates the memory of every item of the list
    
    bool shiftr();
    bool shiftr(size_t shifts);
    bool shiftl();
    bool shiftl(size_t shifts);
            
    void destruct();
    friend void destructLinkedList(LinkedList<type>* list);
```

## LinkedListItem Class
```c++
public:
    LinkedListItem<T>* next;
    LinkedListItem<T>* previous;
    T data;

```

## How to use

### 1. Creating a list
```c++
// The list MUST be created with dynamic allocation
LinkedList<int>* intList = new LinkedList<int>();
LinkedList<bool>* boolList = new LinkedList<bool>();

// You can also use your own structures!
LinkedList<myStruct>* structList = new LinkedList<myStruct>();
```
### 2. Adding elements
```c++
bool addLast(T data); // Receives the data to store, returns true if success

LinkedList<int>* intList = new LinkedList<int>();
intList->addLast(10);

// Now we can also change the saved data
intList->set(0, 20);
```
### 3. Getting elements
```c++
T getFirst();
T getLast();
T get(size_t index);

LinkedList<int>* intList = new LinkedList<int>();
intList->addLast(10);
intList->get(0); // Get the first item that is the 10 stored
```
### 4. Removing elements
```c++
bool remove(size_t index); // Receives an index to be removed, returns true if success

LinkedList<int>* intList = new LinkedList<int>();
intList->addLast(10);
intList->remove(0); // Removes the first item that is the 10 stored
    
// We can also clear the list
intList->clear();
```
### 5. How to go through the list
```c++
LinkedList<int>* intList = new LinkedList<int>();
intList->addLast(10);
    
for (int i = 0; i < intList->size; i++) {
    cout << "Integer value: " << intList->get(i) << endl;
}

// You can use also a for range based, with C++11 or greater
for (int value : *intList) {
    cout << "Integer value: " << value << endl;
}
   
```
### 6. Deleting the list
```c++
LinkedList<int>* intList = new LinkedList<int>();
intList->addLast(10);

// To prevent from non-dynamical allocation the destructor of the LinkedList Class is private
// The list can be deallocated by two ways
intList->destruct();
destructLinkedList(intList);
```
## More operations
- ###  Cyclic Shift
```c++
LinkedList<int>* intList = new LinkedList<int>();
intList->addLast(23);
intList->addLast(7); // The min number of items to shift the list is 2 

intList->shiftr(); // Shifts to the right
intList->shiftl(); // Shifts to the left
    
// To shift a number of times
intList->shiftr(2); // Shifts to the right 2 times
intList->shiftl(2); // Shifts to the left 2 times
```
