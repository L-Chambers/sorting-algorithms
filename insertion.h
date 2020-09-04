//-------------------------------------------------------------
// Lola Blue
//
// Project: Sorting Algorithms
// 			INSERTION SORT
//
// insertion.h
//-------------------------------------------------------------
#ifndef __INSERTION_H__
#define __INSERTION_H__

//
// insertionSort(): inserts element from unsorted subarray into sorted subarray one by one
//
void insertionSort(int *arr, int n);

//
// printInsertionSortStats()
// prints size, moves, compares, and time taken in last call to insertionSort()
//
void printInsertionSortStats(int n);

#endif