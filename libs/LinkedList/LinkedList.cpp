// Returns the pointer to the interanl class Item
// NULL if the item on the position requested not exists
template <class T>
Item<T>* LinkedList<T>::getItemPtr(size_t index) {
    if (this->first == NULL) return NULL;

    // The list has at least one item
    Item<T>* p = this->current;
    size_t n = this->index;

    Item<T>* paux = NULL;

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


// Adds item to the back of the list
// Returns true if success
template <class T>
bool LinkedList<T>::addLast(T item) {

    if ( this->first == NULL && this->last == NULL ) {
        Item<T>* t = new Item<T>(item); 
        this->first = t;
        this->last = t;

        this->size++;

        return true;
    } else {
        Item<T>* t = new Item<T>(item);
        (this->last)->next = t;
        t->previous = this->last;

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
    Item<T>* last = this->last;
    T data = last->getData();
    
    return data;
}


// Returns the requested item with the position [index]
// Range from 0 to the size-1
template <class T>
T LinkedList<T>::get(size_t index) {
    Item<T>* p = this->getItemPtr(index);

    if ( p == NULL ) {
        std::cout << "\nError: [LinkedList.get(i)] ItemNotFound : Item[" << index << "]. Returned default data\n" << std::endl;
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

    if (p != NULL) {
        this->current = p->previous;

        if (this->index != 0) {
            this->index--;
        }
    }


    if ( p == this->last && this->last != NULL) {
        (p->previous)->next = NULL;
        this->last = p->previous;
        
        delete p;
        this->size--;
        
        return true;
    } else if ( p == this->first && this->first != NULL) {
        (p->next)->previous = NULL;
        this->first = p->next;

        delete p;
        this->size--;
        
        return true;
    } else {
        if ( p == NULL ) {
            return false;
        } else {
            (p->next)->previous = p->previous;
            (p->previous)->next = p->next;

            delete p;
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
            delete p;
            this->size--;
            p = paux;

            this->last = p;
        }


        p = this->first;
        delete p;
        this->size--;
        
        this->last = NULL;
        this->first = NULL;
        
        if ( this->size == 0 ) {
            this->current = NULL;
            this->index = 0;
            return true;
        }
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
        pfirst->previous = plast;

        if (this->current != NULL) {
            if (this->index == this->size-1) {
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


template <class T>
bool LinkedList<T>::shiftr(size_t shifts) {
    for (size_t i = 0; i < shifts; i++) {
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


        if (this->current != NULL) {
            if (this->index == 0) {
                this->index = this->size-1;
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

template <class T>
bool LinkedList<T>::shiftl(size_t shifts) {
    for (size_t i = 0; i < shifts; i++) {
        bool success = this->shiftl();
        if (!success) return false;
    }

    return true;
}
