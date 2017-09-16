#include <iostream>
#include "linked-list.h"
using namespace std;

void printOut(int index, int data) {
    cout << index << ": " << data << endl;
}

void printOut2(int index, LinkedListNode<int>* node) {
    cout << index << ": " << node << endl;
}

int main(int argc, char** argv) {
    LinkedList<int> linkedList;
    linkedList.add(3);
    linkedList.add(4);
    linkedList.add(5);
    linkedList.add(6);
    linkedList.traverse(printOut2);

    linkedList.insert(0, 0);
    cout << "after insert(0, 0): " << endl;
    linkedList.traverse(printOut2);

    linkedList.insert(1, 1);
    cout << "after insert(1, 1): " << endl;
    linkedList.traverse(printOut2);

    linkedList.insert(2, 2);
    cout << "after insert(2, 2): " << endl;
    linkedList.traverse(printOut2);
    linkedList.traverse(printOut);
}