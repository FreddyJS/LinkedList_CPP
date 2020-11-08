#ifndef _LinkedListIterator_H
#define _LinkedListIterator_H


// Iterator class for the LinkedList
template <class T>
class Iterator{
    public:
        Item<T>* p;
        Iterator(Item<T>* p) : p(p) {}
        bool operator!=(Iterator<T> rhs) {return p != rhs.p;}
        T operator*() {return p->getData();}
        void operator++() {p = p->next;}
};

#endif