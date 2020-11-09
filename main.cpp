#include <LinkedList/LinkedList.h>
#include <iostream>

using namespace std;

LinkedList<int> intList() {
    LinkedList<int> list;

    list.addLast(10);
    list.addLast(11);
    list.addLast(12);
    list.addLast(13);
    list.addLast(14);
    list.addLast(15);

    return list;
}

void printIntList(LinkedList<int> list) {
    cout << "-- LinkedList<int> Size: " << list.size << ". List values:\n   [";

    for (size_t i = 0; i < list.size; i++) {
        if (i == list.size-1) {
            cout << list.get(i) << "]" << endl;;
        } else {
            cout << list.get(i) << ", ";
        }
    }
}


int main(int argc, char* argv[]) {
    LinkedList<int> list;
    // Checking methods when the list is empty
    list.get(0);
    cout << "[shiftr:" << list.shiftr(1) << ", shiftl:" << list.shiftl(1) << ", clear:" << list.clear() << ", remove:" << list.remove(0) << "]" << endl;

    list = intList();
    printIntList(list);
    
    list.shiftr(1);
    printIntList(list);

    list.get(20);
    list.remove(20);
    list.remove(0);
    list.remove(list.size-1);
    list.remove(1);
    
    printIntList(list);

    list.clear();
    cout << "   LinkedList<int> Size After Clear: " << list.size << endl;
    list.shiftl();
    list.shiftr();
    
    return 0;
}
