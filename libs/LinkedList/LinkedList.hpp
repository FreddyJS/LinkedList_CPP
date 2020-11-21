#ifndef _LinkedList_H
#define _LinkedList_H

// ¡To use the LinkedList you must use dynamic allocation!
// Include the Item class, those will be the nodes that stores the data
#include "LinkedListItem.hpp"
// Include the Iterator class for the LinkedList, it allows to use the for_range with the list
#include "LinkedListIterator.hpp"

#include <stddef.h>
#include <iostream>

// LinkedList template class
template <class T>
class LinkedList{
    typedef T* iterator;

    private:
        Item<T>* getItemPtr(size_t index);
        Item<T>* first;
        Item<T>* last;

        Item<T>* current;
        size_t index = 0;
        ~LinkedList() { 
            clear();
            delete this;
        }

    public:
        LinkedList() {
            first = NULL;
            last = NULL;
            current = NULL;
            size = 0;
        }

        size_t size;

        bool addLast(T item);
        T getFirst();
        T getLast();
        T get(size_t index);

        bool remove(size_t index);
        bool clear();

        bool shiftr();
        bool shiftr(size_t shifts);

        bool shiftl();
        bool shiftl(size_t shifts);

        Iterator<T> begin() { return Iterator<T>(first);}
        Iterator<T> end() { return NULL;}

};

// Include all the definitions of the functions for the LinkedList class
#include "LinkedList.cpp"

#endif
