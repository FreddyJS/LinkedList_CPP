// Returns the pointer to the interanl class Item
// NULL if the item on the position requested not exists
template <class T>
Item<T>* LinkedList<T>::getItemPtr(size_t index) {
    Item<T>* p;
    Item<T>* paux;

    p = this->first;

    if ( p == NULL ) {
        return NULL;
    } else {
        size_t n = 0;
        
        if ( n == index ) { return p; }
        while ( (paux = p->next) ) {
            n++;
            p = paux;
            if (n == index) {
                return p;
            }

        }
    }

    return NULL;
}


// Adds item to the back of the list
// Returns true if success
template <class T>
bool LinkedList<T>::addLast(T item) {

    Item<T>* last = this->last;
    if ( this->first == NULL ) {
        this->first = new Item<T>(item);
        this->size++;

        this->last = this->first;
        return true;
    } else {
        Item<T>* t = new Item<T>(item);
        (this->last)->next = t;
        t->previous = last;

        this->last = t;
        this->size++;

        return true;
    }

    return false;
}


// Returns the first item of the list
template <class T>
T LinkedList<T>::getFirst() {
    return first->getData();
}

// Returns the last item of the list
template <class T>
T LinkedList<T>::getLast() {
    Item<T>* last = this->getLastP();
    T data = last->getData();
    
    return data;
}


// Returns the requested item with the position [index]
// Range from 0 to the size-1
template <class T>
T LinkedList<T>::get(size_t index) {
    Item<T>* p = this->getItemPtr(index);

    if ( p == NULL ) {
        std::cout << "-- [LinkedList.get(i)] ItemNotFound : Item[" << index << "]. Returned default data" << std::endl;
        return T();
    } else {
        return p->getData();
    }    

}


// Remove the item on the position [index] if exists
// Returns true if success
template <class T>
bool LinkedList<T>::remove(size_t index) {
    Item<T>* p = this->getItemPtr(index);

    if ( p == this->last && this->last != NULL) {
        (p->previous)->next = NULL;
        this->last = p->previous;
        
        p->~Item<T>();
        this->size--;
        
        return true;
    } else if ( p == this->first && this->first != NULL) {
        (p->next)->previous = NULL;
        this->first = p->next;

        p->~Item<T>();
        this->size--;
        
        return true;
    } else {
        if ( p == NULL ) {
            return false;
        } else {
            (p->next)->previous = p->previous;
            (p->previous)->next = p->next;

            p->~Item<T>();
            this->size--;

            return true;
        }
    }

    return false;

}


// Clears the list by calling the destructor of any Item stored
// Returns true if success
template <class T>
bool LinkedList<T>::clear() {
    Item<T>* p = this->last;
    Item<T>* paux;

    if ( p != NULL) {
        while ( (paux = p->previous) ) {
            p->~Item<T>();
            this->size--;
            p = paux;

            this->last = p;
        }

        this->first->~Item<T>();
        this->size--;
        
        this->last = NULL;
        this->first = NULL;
        
    }

        if ( this->size == 0 ) {
            return true;
        }

        return false;

}



// Shifts the items of the list to the right one position
// Cyclic Shift Right
// Returns true if success
template <class T>
bool LinkedList<T>::shiftr() {
    if (this->size >= 2) {
        Item<T>* pfirst = this->first;
        Item<T>* plast = this->last;

        this->first = plast;
        this->last = plast->previous;

        (plast->previous)->next = NULL;
        plast->previous = NULL;
        plast->next = pfirst;
        return true;
    } else {
        return false;
    }
    return false;
}


template <class T>
bool LinkedList<T>::shiftr(size_t shifts) {
    for (int i = 0; i < shifts; i++) {
        bool success = this->shiftr();
        if (!success) return false;
    }

    return true;
}


// Shifts the items of the list to the left one position
// Cyclic Shift Right
// Returns true if success
template <class T>
bool LinkedList<T>::shiftl() {
    if (this->size >= 2) {
        Item<T>* pfirst = this->first;
        Item<T>* plast = this->last;

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

template <class T>
bool LinkedList<T>::shiftl(size_t shifts) {
    for (int i = 0; i < shifts; i++) {
        bool success = this->shiftl();
        if (!success) return false;
    }

    return true;
}
