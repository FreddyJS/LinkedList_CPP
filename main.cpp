#include <LinkedList.hpp>
#include <iostream>

using namespace std;

void intList(LinkedList<int>* list) {
    list->addLast(10);
    list->addLast(11);
    list->addLast(12);
    list->addLast(13);
    list->addLast(14);
    list->addLast(15);
}


void printIntList(LinkedList<int>* list) {
    cout << "-- LinkedList<int> Size: " << list->size << ". List values:\n   [";

    for (size_t i = 0; i < list->size; i++) {
        if (i == list->size-1) {
            cout << list->get(i) << "]" << endl;;
        } else {
            cout << list->get(i) << ", ";
        }
    }
}


int main(int argc, char* argv[]) {
    LinkedList<int>* list = new LinkedList<int>();
    // Checking methods when the list is empty
    list->get(0);
    cout << "   [shiftr:" << list->shiftr(1) << ", shiftl:" << list->shiftl(1) << ", clear:" << list->clear() << ", remove:" << list->remove(0) << "]\n" << endl;

    intList(list);
    printIntList(list);

    list->shiftr(1);
    printIntList(list);
    list->shiftl(2);
    printIntList(list);

    list->get(20);
    list->remove(20);

    list->remove(0);
    list->remove(list->size-1);
    list->remove(1);
    list->getFirst();
    list->getLast();
    list->get(1);
    list->shiftr();
    list->get(0);
    list->shiftl();
    
    printIntList(list);
    cout << "    ";
    for (int val: *list) {
        cout << val << "  ";
    }
    cout << endl;

    list->clear();
    cout << "   LinkedList<int> Size After Clear: " << list->size << endl;
    
    return 0;
}