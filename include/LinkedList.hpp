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
// Include the Exception class for the LinkedList, it allows to use custom exception messages
#include <LinkedList/LinkedListException.hpp>

// LinkedList class, doubly linked list implementation
// ¡Must use with dynamic allocation!
//
// i.e. LinkedList<int>* list = new LinkedList<int>();
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
        // Empty constructor
        LinkedList() {  }

        // Copy constructor from another list of the same type of data
        LinkedList(LinkedList<T>* list) {
            this->copyLinkedList(list);

            this->current = NULL;
            this->index = 0;
        }
        
        size_t size = 0;

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
        void destruct();
        
        template <class type>
        friend void destructLinkedList(LinkedList<type>* list);
};

// Include all the definitions of the functions for the LinkedList class
#include <LinkedList/LinkedList.cpp>

#endif
