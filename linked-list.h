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

template<typename T>
LinkedListNode<T>::LinkedListNode() {
    next = nullptr;
}

template<typename T>
LinkedListNode<T>::~LinkedListNode() {
    delete next;
}


template<class T>
class LinkedList {
private:
    LinkedListNode<T>* dummyHead;
    int count;
public:
    LinkedList();
    ~LinkedList();

    bool isEmpty();
    bool isLast(LinkedListNode<T>* node);
    int find(LinkedListNode<T> target);
    int find(T target);
    LinkedListNode<T>* find(int index);
    LinkedListNode<T>* findPrevious()
    void insert(int index, LinkedListNode<T>* node);
};

template<typename T>
LinkedList<T>::LinkedList() {
    dummyHead = new LinkedListNode<T>();
    count = 0;
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

template<typename T>
bool LinkedList<T>::isEmpty() {
    return dummyHead->next == nullptr;
}

template<typename T>
bool LinkedList<T>::isLast(LinkedListNode<T>* node) {
    return node->next == nullptr;
}


template<typename T>
int LinkedList<T>::find(LinkedListNode<T> target) {
    return find(target.data);
}

template<typename T>
int LinkedList<T>::find(T target) {
    int index = 0;
    bool flag = false;
    LinkedListNode* p = dummyHead->next;
    while(p) {
        if (target == p->data) {
            flag = true;
            break;
        }
        index++;
    }
    return flag ? index : -1;
}

template<typename T>
LinkedListNode<T>* find(int index) {
    if (index >= count || index < 0) {
        return nullptr;
    }
    LinkedListNode<T>* p = dummyHead->next;
    int i = 0;
    while(!p) {
        if ( index == i) {
            return p;
        }
        p = p->next;
        i++;
    }
    return nullptr;
}

#endif