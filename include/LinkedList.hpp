#ifndef _LinkedList_H
#define _LinkedList_H

#include <stddef.h>
#include <iostream>
#include <exception>

// ¡To use the LinkedList you must use dynamic allocation!
// Include the Item class, those will be the nodes that stores the data
#include <LinkedList/LinkedListItem.hpp>
// Include the Iterator class for the LinkedList, it allows to use for_range loops with the list
#include <LinkedList/LinkedListIterator.hpp>

#include <LinkedList/LinkedListException.hpp>


// LinkedList class, doubly linked list implementation
// ¡Must use with dynamic allocation!
// 
// LinkedList<int> list = new LinkedList<int>();
template <class T>
class LinkedList{
    typedef T* iterator;

    private:
        void copyLinkedList(LinkedList<T>* list);
        
        LinkedListItem<T>* getItemPtr(size_t index);
        LinkedListItem<T>* first = NULL;
        LinkedListItem<T>* last = NULL;

        LinkedListItem<T>* current = NULL;
        size_t index = 0;

        ~LinkedList() { 
            clear();
        }
    public:

        LinkedList() { }

        LinkedList(LinkedList<T>* list) {
            this->copyLinkedList(list);

            this->current = list->current;
            this->index = list->index;
        }
        
        size_t size = 0;

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

        LinkedListIterator<T> begin() {
            return LinkedListIterator<T>(first);
        }
        LinkedListIterator<T> end() { return NULL;}

};

// Include all the definitions of the functions for the LinkedList class
#include <LinkedList/LinkedList.cpp>

#endif
