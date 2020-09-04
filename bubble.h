//-------------------------------------------------------------
// Author: Lola Blue
//
// Project: Sorting Algorithms
// 			BUBBLE SORT:
// 				time complexity: O(n) - O(n^2)
//				space complexity: O(1)
//				stable
//				non-recursive
//				-> only to be used on (very) small data sets or on 
//					 data that is nearly sorted. 
//
// bubble.h
//-------------------------------------------------------------
#ifndef __BUBBLE_H__
#define __BUBBLE_H__

//
// bubbleSort()
// sorts an array of size n 
//
void bubbleSort(int *A, int n);

//
// printBubbleSortStats()
// prints size, moves, compares, and time taken in last call to bubbleSort()
//
void printBubbleSortStats(int n);

#endif

  