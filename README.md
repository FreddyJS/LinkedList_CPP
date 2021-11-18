# DoublyLinkedList for C++
C ++ library that provides all the necessary methods to handle a list of any type of data. It is implemented by two classes, the "manager" class (LinkedList) and the node class (LinkedListItem).

When passed a list by value it will be `deep copied` so the original list will not be modified. In order to save the changes to the list you will have to return the modified list.  
The copy method just clears the whole list and then add each element to it. Allocating space for each one.  

For more documentation you can take a look to [LinkedList Docs](https://freddyjs.github.io/LinkedList_CPP/)  

## LinkedList Class
```c++
private:
    LinkedListItem<T>* first;
    LinkedListItem<T>* last;
    LinkedListItem<T>* current;
    size_t index = 0;
    
public:
    size_t size;
    
    void addLast(T data);
    
    T getFirst();
    T getLast();
    T get(size_t index);
    void set(size_t index, T data); // Replaces the data of the item
    
    bool remove(size_t index); // Deallocates the memory of the removed item
    void clear(); // Deallocates the memory of every item of the list
    
    bool shiftr();
    bool shiftr(size_t shifts);
    bool shiftl();
    bool shiftl(size_t shifts);
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
// Creating a list with dynamic allocation
LinkedList<int>* intList = new LinkedList<int>();
LinkedList<bool>* boolList = new LinkedList<bool>();

// Creating a list with static allocation
LinkedList<int> intList;
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
    
for (int i = 0; i < intList->size(); i++) {
    cout << "Integer value: " << intList->get(i) << endl;
}

// You can use also a for range based, with C++11 or greater
for (int value : *intList) {
    cout << "Integer value: " << value << endl;
}

// If using static allocation
LinkedList<int> intList;
for (int value : intList) {
    cout << "Integer value: " << value << endl;
}
   
```
### 6. Deleting the list
```c++
// Just when using dynamic allocation
LinkedList<int>* intList = new LinkedList<int>();
intList->addLast(10);

delete(intList);
```
## More operations
###  Cyclic Shift
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
