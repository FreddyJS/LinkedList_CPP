#include <LinkedList/LinkedList.h>
#include <iostream>

struct estructura {
    char data = 'a';
};

using namespace std;
template class LinkedList<double>;


LinkedList<int> intList() {
    LinkedList<int> list;
    int i = 10;

    list.addLast(i);
    list.addLast(++i);
    list.addLast(i+12);
    list.addLast(i+4);

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


    return list;
}


int main(int argc, char* argv[]) {
    cout << "- Creating LinkedList<int>" << endl;
    LinkedList<int> list = intList();

    cout << "\nintListSize: " << list.size << ". List values:" << endl;
    for (int i : list) {
        cout << i << ", ";
    }

    list.clear();
    cout << "\nintListSize after empty: " << list.size << ". List values:" << endl;
    for (int i : list) {
        cout << i << endl;
    }
    cout << "\n- Creating LinkedList<estructura>" << endl;
    LinkedList<estructura> list2 = estructuraList();

    cout << "\nestructuraListSize: " << list2.size << ". List values:" << endl;
    for (estructura e : list2) {
        cout << e.data << ", ";
    }
    cout << endl;

    return 0;
}
