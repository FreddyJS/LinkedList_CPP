#include <LinkedList/LinkedList.h>
#include <iostream>

struct estructura {
    char data = 'a';
};

using namespace std;
//template class LinkedList<double>;


LinkedList<int> intList() {
    LinkedList<int> list;
    list.get(0);
    list.clear();

    list.addLast(10);
    list.addLast(11);
    list.addLast(12);
    list.addLast(13);
    list.addLast(14);
    list.addLast(15);

    return list;
}

LinkedList<estructura> estructuraList() {
    LinkedList<estructura> list;
    estructura i;

    list.addLast(i);

    i.data = 'b';
    list.addLast(i);

    i.data = 'c';
    list.addLast(i);

    i.data = 'd';
    list.addLast(i);

    i.data = 'e';
    list.addLast(i);

    i.data = 'f';
    list.addLast(i);

    return list;
}


int main(int argc, char* argv[]) {
    LinkedList<int> list = intList();
    cout << "-- LinkedList<int> Size: " << list.size << ". List values:\n   [";

    for (size_t i = 0; i < list.size; i++) {
        if (i == list.size-1) {
            cout << list.get(i) << "]" << endl;;
        } else {
            cout << list.get(i) << ", ";
        }
    }
    list.shiftr(1);
    cout << "   [";
    for (size_t i = 0; i < list.size; i++) {
        if (i == list.size-1) {
            cout << list.get(i) << "]" << endl;;
        } else {
            cout << list.get(i) << ", ";
        }
    }

    list.get(20);
    list.remove(20);
    list.remove(0);
    list.remove(list.size-1);
    list.remove(1);
    cout << "   [";
    for (size_t i = 0; i < list.size; i++) {
        if (i == list.size-1) {
            cout << list.get(i) << "]" << endl;;
        } else {
            cout << list.get(i) << ", ";
        }
    }

    list.clear();
    cout << "   LinkedList<int> Size After Clear: " << list.size << endl;
    list.shiftl();
    list.shiftr();
    
    LinkedList<estructura> list2 = estructuraList();


    cout << "\n-- LinkedList<estructura> Size: " << list2.size << ". List values:\n   [";
    for (size_t x = 0; x < list2.size; x++) {
        if (x == list2.size-1) {
            cout << list2.get(x).data << "]" << endl;;
        } else {
            cout << list2.get(x).data << ", ";
        }
    }
    cout << "   First: " << list2.getFirst().data << " - Last: " << list2.getLast().data << endl;

    cout << "   [";
    list2.shiftl(1);
    for (size_t x = 0; x < list2.size; x++) {
        if (x == list2.size-1) {
            cout << list2.get(x).data << "]" << endl;;
        } else {
            cout << list2.get(x).data << ", ";
        }
    }
    cout << "   First: " << list2.getFirst().data << " - Last: " << list2.getLast().data << endl;

    return 0;
}
