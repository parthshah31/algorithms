#include "sorting.hpp"
#include <cstdlib>
#include <assert.h>

template <class T>
bool LessThan(const T& a, const T& b){
    return (a < b);
}

/*
 QUICKSORT
 In nemory quicksort algorithm. Setting randomized to true makes it in memory randomized quicksort algorithm
 NOTE: Current implementation is not a stable sort
 Uses Partition Method Defined Below
 */
template <class T>
void QuickSort(T* array[], int start, int end, bool randomized){
    if(end == -1){
        end = sizeof(array);
    }
    int size = end - start;
    if(size < 2){
        return;
    }
    int pivotIndex = Partition<T>(array, start, end, randomized);
    QuickSort(array,start,pivotIndex);
    QuickSort(array,pivotIndex+1,end);
}

/*
 PARTITION
 In memory partition method. Setting randomized to true ensures that partition quits with at least 1/4 of total members in each partition (lower and upper)
 */
template <class T>
int Partition(T* array[], int start, int end, bool randomized){
    assert(start <= end);
    int size = end - start + 1;
    int index = (std::rand() % size) + start;
    T pivotVal = *array[index];
    T lower[size];
    int numLower = 0;
    T upper[size];
    int numUpper = 0;
    for(int i = start; i < end; i++){
        if(i == index){
            continue;
        }
        if(LessThan(array[i],pivotVal)){
            lower[numLower++] = *array[i];
        }
        else{
            upper[numUpper++] = *array[i];
        }
    }
    if(randomized && size > 16){
        if(numLower < size/4 || numUpper < size/4){
            return Partition(array, start, end, randomized);
        }
    }
    for(int j = start; j < start + numLower; j++){
        *array[j] = lower[j - start];
    }
    int pivotIndex = start + numLower;
    *array[pivotIndex] = pivotVal;
    for(int j = pivotIndex + 1; j < end; j++){
        *array[j] = upper[j - pivotIndex - 1];
    }
    return pivotIndex;
}

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

/*
 COUNTING SORT/RADIX SORT
 Counting Sort/Radix Sort Method. Stable Sort
 */