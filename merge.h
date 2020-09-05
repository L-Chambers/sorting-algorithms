//-------------------------------------------------------------
// Lola Blue
//
// Project: Sorting Algorithms
// 			MERGE SORT
// 				time complexity: O(nlogn)
//				space complexity: O(n)
//				stable
//				recursive
//				-> use when memory usage is not an issue - O(nlogn) is a good
// 				   runtime. 
//
// merge.h
//-------------------------------------------------------------
#ifndef _MERGE_H__
#define _MERGE_H__

//
// merge():
// merges two subarrays [left, middle] and [middle + 1, right]
// subarrays are assumed to be sorted already
//
void merge(int *arr, int left, int middle, int right);

//
// mergeSort():
// recursively divides-and-conquers an array for indices [left, right] 
//
void mergeSort(int *arr, int left, int right);

//
// mergeSort():
// sorts an array of size n
//
void mergeSort(int *arr, int n);

//
// printMergeSortStats()
// prints size, moves, compares, and time taken in last call to mergeSort()
//
void printMergeSortStats(int n);

#endif