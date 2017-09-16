#ifndef DDLINKED_LIST_H
#define DDLINKED_LIST_H

#include <functional>

template<class T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;

    LinkedListNode() : next(nullptr) {}
    LinkedListNode(T data, LinkedListNode<T>* next = nullptr) : data(data), next(next) {}
    ~LinkedListNode();
};

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
    int length();

    // find index of a node with specified value, -1 will returned if the node doesn't exist
    // NOTE: the returned index may become invalid after any node insert/delete operation
    int find(LinkedListNode<T> target);
    int find(T target);

    // retrieve the pointer which point to the node indexed by index
    // NOTE: the index of node which the returned pointer point to may change after any node insert/add/delete operation
    LinkedListNode<T>* retrieve(int index);

    // insert a node to position index, and move all node behind one step back
    // i.e. if index set to zero, the new node will be first node
    // this function cannot append a node, if you want to do that, use add()
    void insert(T data, int index);
    void insert(LinkedListNode<T>* node, int index);

    // add a node back to the linked list
    void add(T data);

    // traverse through all node of the linked list, and for each node call provided function
    // first int value in callback function is index of the node, and second value is the value of the node 
    void traverse(std::function<void(int, T)> callback);
    void traverse(std::function<void(int, LinkedListNode<T>* node)> callback);
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
int LinkedList<T>::length() {
    return count;
}


template<typename T>
int LinkedList<T>::find(LinkedListNode<T> target) {
    return find(target.data);
}

template<typename T>
int LinkedList<T>::find(T target) {
    int index = 0;
    bool flag = false;
    LinkedListNode<T>* p = dummyHead->next;
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
LinkedListNode<T>* LinkedList<T>::retrieve(int index) {
    if (index >= count || index < 0) {
        return nullptr;
    }
    LinkedListNode<T>* p = dummyHead->next;
    int i = 0;
    while(p) {
        if ( index == i) {
            return p;
        }
        p = p->next;
        i++;
    }
    return nullptr;
}

template<typename T>
void LinkedList<T>::insert(T data, int index) {
    if (index >= count || index < 0) return;
    LinkedListNode<T>* nodePrev;
    if (index == 0) {
        nodePrev = dummyHead;
    } else {
        nodePrev = retrieve(index - 1);
    }
    LinkedListNode<T>* newNode = new LinkedListNode<T>(data);
    newNode->next = nodePrev->next;
    nodePrev->next = newNode;
    count++;
}


template<typename T>
void LinkedList<T>::insert(LinkedListNode<T>* node, int index) {
    insert(node->data, index);
}

template<typename T>
void LinkedList<T>::add(T data) {
    LinkedListNode<T>* last;
    if (isEmpty()) {
        last = dummyHead;
    } else {
        last = retrieve(count - 1);
    }
    LinkedListNode<T>* newNode = new LinkedListNode<T>(data);
    last->next = newNode;
    count++;
}

template<typename T>
void LinkedList<T>::traverse(std::function<void(int, T)> callback) {
    LinkedListNode<T>* p = dummyHead->next;
    int index = 0;
    while(p) {
        callback(index, p->data);
        index++;
        p = p->next;
    }
}

template<typename T>
void LinkedList<T>::traverse(std::function<void(int, LinkedListNode<T>* node)> callback) {
    LinkedListNode<T>* p = dummyHead->next;
    int index = 0;
    while(p) {
        callback(index, p);
        index++;
        p = p->next;
    }
}

#endif