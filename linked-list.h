#ifdef DDLINKED_LIST_H
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

#endif