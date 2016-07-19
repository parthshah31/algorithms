#include "structures.hpp"
#include <assert.h>

template <class T>
Link<T>::Link(T inpData, T* linkPrev, T* linkNext){
    data = inpData;
    prev = linkPrev;
    next = linkNext;
}

template <class T>
Stack<T>::Stack(){
    size = 0;
    last = 0;
}

template <class T>
void Stack<T>::Push(T inpData){
    if(last == 0){
        *last = Link<T>(inpData, 0, 0);
    }
    else{
        *(*last).next,*last = Link<T>(inpData, last, 0);
    }
    size++;
}

template <class T>
T Stack<T>::Pop(){
    assert(size > 0);
    T data = (*last).data;
    *last = (*last).prev;
    (*last).next = 0;
    size--;
    return data;
}

template <class T>
Queue<T>::Queue(){
    size = 0;
    first = 0;
    last = 0;
}

template <class T>
void Queue<T>::Push(T inpData){
    if(last == 0){
        *last,*first = Link<T>(inpData, 0, 0);
    }
    else{
        *(*last).next,*last = Link<T>(inpData, last, 0);
    }
    size++;
}

template <class T>
T Queue<T>::Pop(){
    assert(size > 0);
    T data = (*first).data;
    *first = (*first).next;
    (*first).prev = 0;
    size--;
    return data;
}

template <class T>
LinkedList<T>::LinkedList(){
    size = 0;
    first = 0;
    last = 0;
}

template <class T>
void LinkedList<T>::Append(T inpData, int index){
    assert(index >= 0 && index <= size);
    Link<T>* prevLink;
    Link<T>* nextLink;
    if(index == 0){
        prevLink = first;
    }
    else{
        prevLink = (*Get(index - 1)).next;
    }
    if(index == size){
        nextLink = last;
    }
    else{
        nextLink = (*Get(index)).prev;
    }
    *nextLink,*prevLink = Link<T>(inpData,Get(index-1),Get(index));
    size++;
}

template <class T>
int LinkedList<T>::Search(T data){
    int i = 0;
    Link<T>* link = first;
    while(i < size){
        if(data == (*link).data){
            return i;
        }
        i++;
    }
    return -1; //not in list
}

template <class T>
Link<T>* LinkedList<T>::Get(int index){
    int i;
    Link<T>* link;
    if(index <= size/2){
        i = 0;
        link = first;
        while(i < index){
            i++;
            link = (*link).next;
        }
    }
    else{
        int i = size - 1;
        link = last;
        while(i > index){
            i--;
            link = (*link).prev;
        }
    }
    return link;
}