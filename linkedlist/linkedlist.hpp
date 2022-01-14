/**
 * @file linkedlist.hpp
 * @author FreddyJS
 * @brief LinkedList class header file
 * @version 0.1
 * @date 2021-11-18
 */

#ifndef _LinkedList_H
#define _LinkedList_H

#include <stddef.h>
#include <iostream>
#include <exception>

/*****************  LinkedListItem  *****************/
/**
 * @brief A class that represents a node in a linked list.
 * 
 * @tparam T  The type of the data stored in the node.
 */
template <class T>
class LinkedListItem {

    public:
        T data; /**< The data stored in the node. */
        LinkedListItem<T>* next; /**< The next node in the linked list. */
        LinkedListItem<T>* previous; /**< The previous node in the linked list. */

        LinkedListItem() {
            this->next = 0;
            this->previous = 0;
        }

        LinkedListItem(T data) {
            this->next = 0;
            this->previous = 0;
            this->data = data;
        }

        ~LinkedListItem() { }

        T getData();
        T* getDataPtr();
        void setData(T data);

};

/**
 * @brief Returns the data stored in the node.
 * 
 * @tparam T The type of the data stored in the node.
 * @return T The data stored in the node.
 */
template <class T>
T LinkedListItem<T>::getData() {
    return this->data;
}

/**
 * @brief Returns a pointer to the data stored in the node.
 * 
 * @tparam T The type of the data stored in the node.
 * @return T* A pointer to the data stored in the node.
 */
template <class T>
T* LinkedListItem<T>::getDataPtr() {
    return &(this->data);
}

/**
 * @brief Sets the data stored in the node.
 * 
 * @tparam T The type of the data stored in the node.
 * @param data The data to be stored in the node.
 */
template <class T>
void LinkedListItem<T>::setData(T data) {
    this->data = data;
}

/**
 * @brief Custom exception class. Used to throw exceptions.
 *  
 */
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

/**
 * @brief Iterator class for LinkedList.
 * 
 * @tparam T Type of the elements in the list.
 */
template <class T>
class LinkedListIterator
{
    public:
        LinkedListItem<T>* p; /**< Pointer to the current item */
        LinkedListIterator(LinkedListItem<T>* p) : p(p) {}
        ~LinkedListIterator() { }

        bool operator!=(LinkedListIterator<T> rhs) {return p != rhs.p;}
        T operator*() {return p->getData();}
        void operator++() {p = p->next;}
};

/*****************  LinkedList  *****************/
/**
 * @brief Doubly linked list implementation.
 * 
 * @tparam T Type of the elements in the list.
 */
template <class T>
class LinkedList
{
    typedef T* iterator;

    private:
        void copyLinkedList(LinkedList<T>* list);
        
        LinkedListItem<T>* getItemPtr(size_t index) const;
        LinkedListItem<T>* first = NULL;
        LinkedListItem<T>* last = NULL;

        size_t _size = 0;

    public:
        // Default constructor, creates an empty list
        LinkedList() = default;

        // Copy constructor (deep copy), creates a new list with the same data as the given list
        LinkedList(LinkedList<T>* list) {
            this->copyLinkedList(list);
        }

        // Copy constructor (deep copy), creates a new list with the same data as the given list
        LinkedList(LinkedList<T>& list) {
            this->copyLinkedList(&list);
        }

        // Copy constructor (deep copy), creates a new list with the same data as the given list
        LinkedList(const LinkedList<T>& list) {
            for (int i = 0; i < list.size(); i++) {
                this->addLast(list.get(i));
            }
        }

        // Destructor, deletes all the items in the list
        ~LinkedList() { 
            this->clear();
        }

        size_t size() const { return this->_size; }
        T get(size_t index) const;
        T getFirst() const;
        T getLast() const;

        void addLast(T data);
        void set(size_t index, T data);
        bool remove(size_t index);
        void clear();

        bool shiftr();
        bool shiftl();
        bool shiftr(size_t shifts);
        bool shiftl(size_t shifts);

        void chopLeft(size_t index);
        void chopRight(size_t index);

        LinkedListIterator<T> begin() { return LinkedListIterator<T>(first); }
        LinkedListIterator<T> end() { return NULL; }

        void operator delete(void* list);
        LinkedList<T>& operator =(const LinkedList<T>& list);
};

/**
 * @brief Returns the pointer to the LinkedListItem
 * 
 * @tparam T Type of the elements in the list.
 * @param index number of the position of the desired item
 * @return LinkedListItem<T>* pointer to the desired item
 */
template <class T>
LinkedListItem<T>* LinkedList<T>::getItemPtr(size_t index) const {
    LinkedListItem<T>* item = this->first;
    while (index != 0) {
        item = item->next;
        index--;
    }

    return item;
}

/**
 * @brief Removes the elements from the beginning of the list until the given index (exclusive).
 * 
 * @tparam T 
 * @param index Index of the new first element.
 */
template <class T>
void LinkedList<T>::chopLeft(size_t index) {
    if (index >= this->_size) {
        std::string msg = "LinkedListException: Index out of bounds. Operation: chopLeft(" + std::to_string(index) + ")";
        throw LinkedListException(msg);
    }

    LinkedListItem<T>* newFirstItem = this->getItemPtr(index);
    do {
        this->remove(0);
    } while (this->first != newFirstItem);
}

/**
 * @brief Removes the elements from the end of the list until the given index (exclusive).
 * 
 * @tparam T 
 * @param index Index of the new last element.
 */
template <class T>
void LinkedList<T>::chopRight(size_t index) {
    if (index >= this->_size) {
        std::string msg = "LinkedListException: Index out of bounds. Operation: chopRight(" + std::to_string(index) + ")";
        throw LinkedListException(msg);
    }

    LinkedListItem<T>* newLastItem = this->getItemPtr(index);
    do {
        this->remove(this->_size - 1);
    } while (this->last != newLastItem); // Stop if the last item is the one at the given index
}

/**
 * @brief Adds an item to the back of the list
 * 
 * @tparam T Type of the elements in the list.
 * @param data data to be added to the list
 */
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

/**
 * @brief Returns the first item in the list
 * 
 * @tparam T Type of the elements in the list.
 * @return T data of the first item
 */
template <class T>
T LinkedList<T>::getFirst() const {
    if (this->_size == 0) {
        std::string msg = "LinkedListException: List is empty. Operation: getFirst()";
        throw LinkedListException(msg);
    }

    return this->first->getData();
}

/**
 * @brief Returns the last item in the list
 * 
 * @tparam T Type of the elements in the list.
 * @return T data of the last item
 */
template <class T>
T LinkedList<T>::getLast() const {
    if (this->_size == 0) {
        std::string msg = "LinkedListException: List is empty. Operation: getLast()";
        throw LinkedListException(msg);
    }
    
    return this->last->getData();
}


/**
 * @brief Returns the item in the list at the given index
 * 
 * @tparam T Type of the elements in the list.
 * @param index number of the position of the desired item
 * @return T data of the desired item
 */
template <class T>
T LinkedList<T>::get(size_t index) const {
    if (index >= this->_size) {
        std::string msg = "LinkedListException: Index out of bounds. Operation: get(" + std::to_string(index) + ")";
        throw LinkedListException(msg);
    }

    return this->getItemPtr(index)->getData();
}

/**
 * @brief Sets the item in the list at the given index
 * 
 * @tparam T Type of the elements in the list.
 * @param index number of the position of the desired item
 * @param data data to replace the old data
 */
template <class T>
void LinkedList<T>::set(size_t index, T data){
    if (index >= this->_size) {
        std::string msg = "LinkedListException: Index out of bounds. Operation: set(" + std::to_string(index) + ")";
        throw LinkedListException(msg);
    }

    LinkedListItem<T>* p = this->getItemPtr(index);
    p->setData(data);
}

/**
 * @brief Removes the item in the list at the given index
 * 
 * @tparam T Type of the elements in the list.
 * @param index number of the position of the desired item
 * @return true if the item was removed, false if the item was not found
 */
template <class T>
bool LinkedList<T>::remove(size_t index) {
    if (index >= this->_size) {
        std::string msg = "LinkedListException: Index out of bounds. Operation: remove(" + std::to_string(index) + ")";
        throw LinkedListException(msg);
    }

    LinkedListItem<T>* item = this->getItemPtr(index);

    if (item == this->first && item == this->last) {
        this->first = NULL;
        this->last = NULL;
    } else if (item == this->last) {
        this->last = item->previous;
        (item->previous)->next = NULL;
    } else if (item == this->first) {
        this->first = item->next;
        (item->next)->previous = NULL;
    } else {
        (item->next)->previous = item->previous;
        (item->previous)->next = item->next;
    }
    
    this->_size--;
    delete item;

    return true;
}

/**
 * @brief Clears the list removing all items from it
 * 
 * @tparam T Type of the elements in the list.
 */
template <class T>
void LinkedList<T>::clear() {
    LinkedListItem<T>* p;
    LinkedListItem<T>* paux;

    if (this->_size > 0) {
        p = this->last;

        while ( (paux = p->previous) ) {
            delete p;
            p = paux;

            this->last = p;
        }

        p = this->first;
        delete p;
        
        this->last = NULL;
        this->first = NULL;
        this->_size = 0;
    }
}

/**
 * @brief Shifts the items of the list to the right one position
 * 
 * @tparam T Type of the elements in the list.
 * @return true if success
 */
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
       
        return true;
    } else {
        return false;
    }
    return false;
}

/**
 * @brief Shifts the items of the list to the right N times
 * 
 * @tparam T Type of the elements in the list.
 * @param shifts number of shifts to do
 * @return true if success
 */
template <class T>
bool LinkedList<T>::shiftr(size_t shifts) {
    for (size_t i = 0; i < shifts; i++) {
        bool success = this->shiftr();
        if (!success) return false;
    }

    return true;
}

/**
 * @brief Shifts the items of the list to the left one position
 * 
 * @tparam T Type of the elements in the list.
 * @return true if success
 */
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

        return true;
    } else {
        return false;
    }
    return false;
}

/**
 * @brief Shifts the items of the list to the left N times
 * 
 * @tparam T Type of the elements in the list.
 * @param shifts number of shifts to do
 * @return true if success
 */
template <class T>
bool LinkedList<T>::shiftl(size_t shifts) {
    for (size_t i = 0; i < shifts; i++) {
        bool success = this->shiftl();
        if (!success) return false;
    }

    return true;
}

/**
 * @brief Copy all the items of the list to the self list
 * 
 * @tparam T Type of the elements in the list.
 * @param list LinkedList pointer to the list to copy
 */
template <class T>
void LinkedList<T>::copyLinkedList(LinkedList<T>* list) {
    for (size_t i = 0; i < list->size(); i++) {
        this->addLast(list->get(i));
    }    
}

/**
 * @brief Overload of the operator delete. Clears the list and frees the memory
 * 
 * @tparam T Type of the elements in the list.
 * @param ptr pointer to the list to delete
 */
template <class T>
void LinkedList<T>::operator delete(void* ptr) {
    LinkedList<T>* list = (LinkedList<T>*) ptr;
    list->clear();
    free(ptr);
}

/**
 * @brief Overload of the operator =. Makes a deep copy of the list
 * 
 * @tparam T Type of the elements in the list.
 * @param list LinkedList pointer to the list to copy
 * @return LinkedList<T>& reference to the list
 */
template <class T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& list) {
    if (this != &list) {
        this->clear();
        this->copyLinkedList((LinkedList<T>*) &list);
    }

    return *this;
}

#endif
