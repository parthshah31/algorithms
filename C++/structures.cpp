#include "structures.hpp"
#include <assert.h>

Link::Link(T inpData, T* linkPrev, T* linkNext){
    data = inpData;
    prev = linkPrev;
    next = linkNext;
}

Stack::Stack(){
    size = 0;
    last = nullptr;
}

void Stack::Push(T inpData){
    if(last == nullptr){
        *last = Link(inpData, nullptr, nullptr);
    }
    else{
        *(*last).next,*last = Link(inpData, last, nullptr);
    }
    size++;
}

T Stack::Pop(){
    assert(size > 0);
    T data = *last.data;
    *last = *last.prev;
    *last.next = nullptr;
    size--;
    return data;
}

Queue::Queue(){
    size = 0;
    first = nullptr;
    last = nullptr;
}

void Queue::Push(T inpData){
    if(last == nullptr){
        *last,*first = Link(inpData, nullptr, nullptr);
    }
    else{
        *(*last).next,*last = Link(inpData, last, nullptr);
    }
    size++;
}

T Queue::Pop(){
    assert(size > 0);
    T data = *first.data;
    *first = *first.next;
    *first.prev = nullptr;
    size--;
    return data;
}

LinkedList::LinkedList(){
    size = 0;
    first = nullptr;
    last = nullptr;
}

void LinkedList::Append(T inpData, index = size){
    assert(index >= 0 && index <= size);
    if(index == 0){
        Link* prev = &first;
    }
    else{
        Link* prev = &(*Get(index - 1)).next;
    }
    if(index == size){
        Link* next = &last;
    }
    else{
        Link* next = &(*Get(index)).prev;
    }
    next,prev = Link(inpData,Get(index-1),Get(index));
    size++;
}

int LinkedList::Search(T data){
    int i = 0;
    Link* link = first;
    while(i < size){
        if(data == *link.data){
            return i;
        }
        i++;
    }
    return -1; //not in list
}

Link* LinkedList::Get(index){
    int i;
    Link* link;
    if(index <= size/2){
        i = 0;
        link = first;
        while(i < index){
            i++;
            link = *link.next;
        }
    }
    else{
        int i = size - 1;
        link = last;
        while(i > index){
            i--;
            link = *link.prev;
        }
    }
    return link;
}