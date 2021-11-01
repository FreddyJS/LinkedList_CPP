#ifndef _LinkedList_H
#define _LinkedList_H

#include <stddef.h>
#include <iostream>
#include <exception>

// Include the Item class, those will be the nodes that stores the data
#include <LinkedListItem.hpp>

class LinkedListException: public std::exception
{
    private:
        std::string message_;
    public:
        explicit LinkedListException(const std::string& message) : message_(message) {}
        const char* what() const noexcept override {
            return message_.c_str();
        }   
};

// Iterator class for the LinkedList
template <class T>
class LinkedListIterator
{
    public:
        LinkedListItem<T>* p;
        LinkedListIterator(LinkedListItem<T>* p) : p(p) {}
        ~LinkedListIterator() { }

        bool operator!=(LinkedListIterator<T> rhs) {return p != rhs.p;}
        T operator*() {return p->getData();}
        void operator++() {p = p->next;}
};

// LinkedList class, doubly linked list implementation
// If you use static allocation please be sure to return the list if its modified
// \@type: the type of the data to store
//
// LinkedList<type> list;
// LinkedList<type>* list = new LinkedList<int>();
template <class T>
class LinkedList
{
    typedef T* iterator;

    private:
        void copyLinkedList(LinkedList<T>* list);
        
        LinkedListItem<T>* getItemPtr(size_t index);
        LinkedListItem<T>* first = NULL;
        LinkedListItem<T>* last = NULL;

        LinkedListItem<T>* current = NULL;
        size_t index = 0;
        size_t _size = 0;

    public:
        // Empty constructor
        LinkedList() {  }

        // Copy constructor from another list of the same type of data
        LinkedList(LinkedList<T>* list) {
            this->copyLinkedList(list);

            this->current = NULL;
            this->index = 0;
        }
        
        ~LinkedList() { 
            clear();
        }

        size_t size() { return this->_size; }
        void addLast(T data);
        T getFirst();
        T getLast();
        T get(size_t index);

        void set(size_t index, T data);

        bool remove(size_t index);
        void clear();

        bool shiftr();
        bool shiftr(size_t shifts);

        bool shiftl();
        bool shiftl(size_t shifts);

        LinkedListIterator<T> begin() { return LinkedListIterator<T>(first); }
        LinkedListIterator<T> end() { return NULL; }

        void* operator new(size_t size);
        void operator delete(void* list);
};

// ------ Linked List Methods Implementations ------ //

// Returns the pointer to the LinkedListItem
// Returns a null pointer if the item on the position requested not exists
// \@index: number of the position of the desired item
//
// Implements a current pointer to improve the time of the searchs
template <class T>
LinkedListItem<T>* LinkedList<T>::getItemPtr(size_t index) {
    if (this->first == NULL) return NULL;

    LinkedListItem<T>* p = this->current;
    LinkedListItem<T>* paux = NULL;
    size_t n = this->index;

    if (p == NULL) {
        p = this->first;
        n = 0;
    }

    if (n == index) {
        this->current = p;
        this->index = n;
        return p;
    }

    if (n < index) {
        while ( (paux = p->next) ) {
            n++;
            p = paux;
            if (n == index) {
                this->current = p;
                this->index = n;
                return p;
            }
        }

    } else {
        while ( (paux = p->previous) ) {
            n--;
            p = paux;
            if (n == index) {
                this->current = p;
                this->index = n;
                return p;
            }
        }
    }

    return NULL;
}


// Adds an item to the back of the list
// \@data: the data to store
template <class T>
void LinkedList<T>::addLast(T data) {
    LinkedListItem<T>* item = new LinkedListItem<T>(data);

    if ( this->_size == 0 ) {
        this->first = item;
    } else {
        (this->last)->next = item;
        item->previous = this->last;
    }
    
    this->last = item;
    this->_size++;
}

// Returns the first item of the list
//
// Throws exception if the list is empty
template <class T>
T LinkedList<T>::getFirst() {
    if (this->first != NULL) {
        T data = this->first->getData();
        return data;
    } else {
        std::string msg = "LinkedListException: Item not found! Operation: getLast()";
        throw LinkedListException(msg);
    }
}

// Returns the last item of the list
//
// Throws exception if the list is empty
template <class T>
T LinkedList<T>::getLast() {
    if (this->last != NULL) {
        T data = this->last->getData();
        return data;
    } else {
        std::string msg = "LinkedListException: Item not found! Operation: getLast()";
        throw LinkedListException(msg);
    }
}


// Returns the requested item on the position [index]
// Range [0, list.size-1] if the list is not empty
// \@index: number of the position of the desired item
//
// Throws exception if the item not exists
template <class T>
T LinkedList<T>::get(size_t index){
    LinkedListItem<T>* p = this->getItemPtr(index);

    if ( p == NULL ) {
        std::string msg = "LinkedListException: Item not found! Operation: get(" + std::to_string(index) + ")";
        throw LinkedListException(msg);
    } else {
        return p->getData();
    }    

}

// Replaces the data of the item on the position [index]
// Range [0, list.size-1] if the list is not empty
//
// \@index: number of the position of the item to change
// \@data: the data to store
//
// Throws exception if the item not exists
template <class T>
void LinkedList<T>::set(size_t index, T data){
    LinkedListItem<T>* p = this->getItemPtr(index);

    if ( p == NULL ) {
        std::string msg = "LinkedListException: Item not found! Operation: set(" + std::to_string(index) +")";
        throw LinkedListException(msg);
    } else {
        p->setData(data);
    }    

}


// Remove the item on the position [index] if exists
// \@index: number of the position of the item to remove
//
// Returns true if success
template <class T>
bool LinkedList<T>::remove(size_t index) {
    LinkedListItem<T>* p = this->getItemPtr(index);

    if (p != NULL) {
        this->current = p->previous;

        if (this->index != 0) {
            this->index--;
        }
    }

    if ( p == this->last && this->last != NULL) {
        if (p != this->first) {
            (p->previous)->next = NULL;
            this->last = p->previous;
        }
        
        delete p;
        this->_size--;
        
        return true;
    } else if ( p == this->first && this->first != NULL) {
        if (p != this->last) {
            (p->next)->previous = NULL;
            this->first = p->next;
        }

        delete p;
        this->_size--;
        
        return true;
    } else {
        if ( p == NULL ) {
            return false;
        } else {
            (p->next)->previous = p->previous;
            (p->previous)->next = p->next;

            delete p;
            this->_size--;

            return true;
        }
    }

    return false;

}


// Clears the list by calling the destructor of any Item stored
//
// Automatic called when the list is destroyed
template <class T>
void LinkedList<T>::clear() {
    LinkedListItem<T>* p;
    LinkedListItem<T>* paux;

    if (this->_size > 0) {
        p = this->last;

        while ( (paux = p->previous) ) {
            delete p;
            this->_size--;
            p = paux;

            this->last = p;
        }

        p = this->first;
        delete p;
        this->_size--;
        
        this->last = NULL;
        this->first = NULL;
        
        this->current = NULL;
        this->index = 0;
    }
}

// Shifts the items of the list to the right one position
// Cyclic Shift Right
// Returns true if success
template <class T>
bool LinkedList<T>::shiftr() {
    if (this->_size >= 2) {
        LinkedListItem<T>* pfirst = this->first;
        LinkedListItem<T>* plast = this->last;

        this->first = plast;
        this->last = plast->previous;

        (plast->previous)->next = NULL;
        plast->previous = NULL;
        plast->next = pfirst;
        pfirst->previous = plast;

        if (this->current != NULL) {
            if (this->index == this->_size-1) {
                this->index = 0;
            } else {
                this->index++;
            }
        }
        
        return true;
    } else {
        return false;
    }
    return false;
}



// Shifts the items of the list to the right N times
// Cyclic Shift Right
// \@shifts: the number of shifts to do
//
// Returns true if success
template <class T>
bool LinkedList<T>::shiftr(size_t shifts) {
    for (size_t i = 0; i < shifts; i++) {
        bool success = this->shiftr();
        if (!success) return false;
    }

    return true;
}

// Shifts the items of the list to the left one position
// Cyclic Shift Left
// Returns true if success
template <class T>
bool LinkedList<T>::shiftl() {
    if (this->_size >= 2) {
        LinkedListItem<T>* pfirst = this->first;
        LinkedListItem<T>* plast = this->last;

        this->first = pfirst->next;
        this->last = pfirst;

        (pfirst->next)->previous = NULL;
        plast->next = pfirst;
        pfirst->previous = plast;
        pfirst->next = NULL;


        if (this->current != NULL) {
            if (this->index == 0) {
                this->index = this->_size-1;
            } else {
                this->index--;
            }
        }

        return true;
    } else {
        return false;
    }
    return false;
}



// Shifts the items of the list to the left one position
// Cyclic Shift Left
// \@shifts: the number of shifts to do
//
// Returns true if success
template <class T>
bool LinkedList<T>::shiftl(size_t shifts) {
    for (size_t i = 0; i < shifts; i++) {
        bool success = this->shiftl();
        if (!success) return false;
    }

    return true;
}

// Copy all the items from one list to the new list
// Used on the copy constructor
// \@list: LinkedList pointer to the list to copy
//
// Allocates new memory for every item on the new list
template <class T>
void LinkedList<T>::copyLinkedList(LinkedList<T>* list) {
    for (size_t i = 0; i < list->size; i++) {
        this->addLast(list->get(i));
    }    
}

// Overloading operator new
template <class T>
void* LinkedList<T>::operator new(size_t size) {
    return malloc(size);
}

// Overloading operator delete
template <class T>
void LinkedList<T>::operator delete(void* ptr) {
    LinkedList<T>* list = (LinkedList<T>*) ptr;
    list->clear();
    free(ptr);
}


#endif
