#include "sorting.hpp"
#include <cstdlib>
#include <assert.h>

//template methods for comparison based sorting
//counting sort for integer sorting

template <class T>
bool LessThan(const T& a, const T& b){
    return (a < b);
}

/*
 QUICKSORT
 In nemory quicksort algorithm. Setting randomized to true makes it in memory randomized quicksort algorithm
 
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
 Merge Sort method
 */
//template <class T>
//void