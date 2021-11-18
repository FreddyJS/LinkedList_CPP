/**
 * @file LinkedListItem.hpp
 * @author FreddyJS
 * @brief LinkedListItem class header file
 * @version 0.1
 * @date 2021-11-18
 */

#ifndef _LinkedListItem_H
#define _LinkedListItem_H

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

#endif