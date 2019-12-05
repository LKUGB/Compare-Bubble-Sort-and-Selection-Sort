//
// Created by MSI on 2019/12/5.
//
#include <iostream>
#include <algorithm> //used for the swap function in the quickSort Function
#include <vector>

using namespace std;

class SortFunctions{
    //declare the bubbleSort, selectionSort, quickSort, and mergeSort functions
public:
    //bubbleSort
    template<typename T>
    void BubbleSort(vector<T> a, int n);

    //selectionSort
    template<typename T>
    void SelectionSort(vector<T> numbers, int numbersSize);

    //quickSort
    template <typename T>
    int Partition(vector<T> numbers, int i, int k);
    template<typename T>
    void QuickSort(vector<T> numbers, int i, int k);

    //mergeSort
    template<typename T>
    void Merge(vector<T> numbers, int i, int j, int k);
    template<typename T>
    void MergeSort(vector<T> numbers, int i, int k);



};









#ifndef MAIN_BUBBLESORT_H
#define MAIN_BUBBLESORT_H

#endif //MAIN_BUBBLESORT_H
