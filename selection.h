//-------------------------------------------------------------
// Lola Blue
//
// Project: Sorting Algorithms
// 			SELECTION SORT
//				time complexity: O(n^2)
//				space complexity: O(1)
//				unstable
//				non-recursive
//				-> only to be used on (very) small data sets
//
// selection.h
//-------------------------------------------------------------
#ifndef __SELECTION_H__
#define __SELECTION_H__

//
// findMinimum() 
// returns index of minimum element in arr in range [firstIndex, lastIndex]
//
int findMinimum(int arr[], int firstIndex, int lastIndex);

//
// selectionSort() 
// sorts array of size n
//
void selectionSort(int *arr, int n);

//
// printSelectionSortStats()
// prints size, moves, compares, and time taken in last call to selectionSort()
//
void printSelectionSortStats(int n);

#endif