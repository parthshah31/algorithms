#ifndef SORTING_H
#define SORTING_H

template <class T>
bool LessThan(const T& a, const T&b);

template <class T>
void QuickSort(T* array[], int start = 0, int end = -1, bool randomized = false);

template <class T>
int Partition(T* array[], int start, int end, bool randomized);

#endif