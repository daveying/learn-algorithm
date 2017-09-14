#ifndef DDLINKED_LIST_H
#define DDLINKED_LIST_H

template<class T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;

    LinkedListNode();
    ~LinkedListNode();
};

template<class T>
class LinkedList {
private:
    LinkedListNode<T>* dummyHead;
public:
    LinkedList();
    ~LinkedList();
};


template<typename T>
LinkedListNode<T>::LinkedListNode() {
    next = nullptr;
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
    LinkedListNode<T>* p = dummyHead->next;
    while (p) {
        LinkedListNode<T>* temp = p->next;
        delete p;
        p = temp;
    }
}

#endif