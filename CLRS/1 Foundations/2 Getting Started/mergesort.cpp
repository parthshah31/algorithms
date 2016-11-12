#include "mergesort.hpp"

/*
 MERGE SORT
 Merge Sort method. Not in memory. Stable sort.
 */
template <class T>
T* MergeSort(T* array[]){
    int size = sizeof(*array);
    if(size < 2){
        return array;
    }
    T array1[size/2];
    T array2[size - size/2];
    T sorted1[size/2];
    T sorted2[size - size/2];
    for(int i = 0; i < size/2; i++){
        array1[i] = *array[i];
    }
    for(int i = size/2; i < size; i++){
        array1[i - size/2] = *array[i];
    }
    sorted1 = MergeSort(array1);
    sorted2 = MergeSort(array2);
    return *Merge(sorted1, sorted2);
}

template <class T>
T* Merge(T* array1[], T* array2[]){
    int size = sizeof(*array1) + sizeof(*array2);
    T array[size];
    int index;
    int index1 = 0;
    int index2 = 0;
    while(index1 < sizeof(*array1) && index2 < sizeof(*array2)){
        if(LessThan(*array1[index1],*array2[index2])){
            array[index++] = *array1[index1++];
        }
        else{
            array[index++] = *array2[index2++];
        }
    }
    if(index1 == sizeof(*array1)){
        for(int i = index2; i < sizeof(*array2); i++){
            array[index++] = *array2[index2++];
        }
    }
    else{
        for(int i = index1; i < sizeof(*array1); i++){
            array[index++] = *array2[index1++];
        }
    }
    return *array;
}
