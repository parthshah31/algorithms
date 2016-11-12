#include "insertionsort.hpp"

/*
INSERTION SORT
*/

template <class T>
T* InsertionSort(T* array[]){
    for(int i = 1; i < sizeof(array); i++){
        while(i > 0 && array[i] < array[i-1]){
            swap(array[i], array[i-1]);
        }
    }
    return array;
}

template <class T>
void swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}