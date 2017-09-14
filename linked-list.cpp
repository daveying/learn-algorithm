#include "linked-list.h"

template<typename T>
LinkedListNode<T>::LinkedListNode() {
    next = NULL;
}

template<typename T>
LinkedListNode<T>::~LinkedListNode() {
    delete next;
}

template<typename T>
LinkedList<T>::LinkedList() {
    dummyHead = new LinkedListNode<T>();
}

template<typename T>
LinkedList<T>::~LinkedList() {
    LinkedListNode<T>* p = dummyHead.next;
    while (p) {
        LinkedListNode<T>* temp = p->next;
        delete p;
        p = temp;
    }
}