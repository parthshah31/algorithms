#ifndef STRUCTURES_H
#define STRUCTURES_H

template <class T>
class Link{
    T data;
    T* prev;
    T* next;
public:
    Link(T inpData, T* linkPrev, T* linkNext);
};

template <class T>
class Stack{
    int size;
    Link<T>* last;
public:
    Stack();
    void Push(T inpData);
    T Pop();
};

template <class T>
class Queue{
    int size;
    Link<T>* first;
    Link<T>* last;
public:
    Queue();
    void Push(T inpData);
    T Pop();
};

template <class T>
class LinkedList{
    int size;
    Link<T>* first;
    Link<T>* last;
public:
    LinkedList();
    void Append(T inpData, int index);
    int Search(T data);
    Link<T>* Get(int index);
};

#endif