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
// bubble.cpp
//-------------------------------------------------------------
#include "bubble.h"
#include <cstdio>
#include <iostream>
#include <chrono>
#define SWAP(arr, x, y) { int t = arr[x]; arr[x] = arr[y]; arr[y] = t; }


// setup for bubbleSort() statistics
static int compares = 0; // how many times are two elements compared?
static int moves = 0;  // how many times are elements are moved around?
static double duration; // how long does bubbleSort() take to execute?


//
// bubbleSort()
// sorts an array of size n 
//
void bubbleSort(int *arr, int length) {

  auto start = std::chrono::high_resolution_clock::now(); // start clock 
  
	// BUBBLE SORT 
	bool array_is_unsorted = true; // no swaps after a pass over the array indicates it is sorted
	while(array_is_unsorted) {
	
	  // make a pass over the array
		for (int i = 1; i < length; i++) {
			if (arr[i - 1] > arr[i]) { // compare all adjacent elements in the array
				SWAP(arr, i -1, i); // out-of-order elements are swapped
				moves += 3;  // swapping requires 3 movements (see macro)
				array_is_unsorted = true; // a swap indicates the array was not sorted before the pass
			}
	    compares += 1; // one comparison has been made between two elements 
		}
		
		// Each pass is guaranteed to bubble up the largest element out of place to its appropriate position
		// A sorted portion of the array grows  with each pass from the top index down.
		// We compare elements in the index range (0, n - 1), then (0, n - 2), (0, n - 3)... (0, 1) to reduce run time. 
		length--; 
		
	}
	
	// stop clock and calculate time elapsed
	auto stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	
	// success!
  return;
}


//
// printBubbleSortStats()
// prints size, moves, compares, and time taken in last call to bubbleSort()
//
void printBubbleSortStats(int length) {
	printf("---- Bubble Sort ----\n");
  printf("%d elements\n", length);
  printf("%d moves\n", moves);
  printf("%d compares\n", compares); 
  printf("%f seconds to sort\n\n", duration * 1e-6);
	return;
}
