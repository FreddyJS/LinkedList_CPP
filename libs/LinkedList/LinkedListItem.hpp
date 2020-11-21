#ifndef _LinkedListItem_H
#define _LinkedListItem_H

template <class T>
class Item {
    T data;

    public:

        Item<T>* next;
        Item<T>* previous;

        Item(T data) {
            next = 0;
            previous = 0;
            this->data = data;
        }


        T getData();
        T* getDataPtr();

};

// Returns the data stored by the user
template <class T>
T Item<T>::getData() {
    T data = this->data;

    return data;
}

// Returns de pointer to the data stored by the user
template <class T>
T* Item<T>::getDataPtr() {
    T* data = &(this->data);

    return data;
}

#endif