//-------------------------------------------------------------
// Lola Blue
//
// Project: Sorting Algorithms
// 			INSERTION SORT
// 				time complexity: O(n)- O(n^2)
//				space complexity: O(1)
//				stable
//				non-recursive
//				-> only to be used on (very) small data sets or on 
//					 data that is nearly sorted. 
//
// insertion.cpp
//-------------------------------------------------------------
#include "insertion.h"
#include <cstdio>
#include <chrono>


// setup for insertionSort() statistics
static int compares = 0; // how many times are two elements compared?
static int moves = 0;  // how many times are elements are moved around?
static double duration; // how long does insertionSort() take to execute?


//
// insertionSort()
// sorts an array of size n 
//
void insertionSort(int *arr, int n) {

	auto start = std::chrono::high_resolution_clock::now(); // start clock
	
	// INSERTION SORT
	// with each iteration, arr[i] is added the sorted portion of the array appropriately. 
	for (int i = 1; i < n; i++) {
	
		int element_to_be_placed = arr[i]; // arr[i] is the element to be placed (ETBP) in this pass // one element has been moved
		int index_to_the_left = i - 1; // comparison will begin with the largest element of the sorted portion
				
		// find the index of the largest element in the sorted portion that is smaller than the ETBP
		while (index_to_the_left >= 0 && element_to_be_placed < arr[index_to_the_left]) { // if the ETBP is smaller
			arr[index_to_the_left + 1] = arr[index_to_the_left]; // the element to the left gets shifted to the right to make room for the ETBP
			index_to_the_left -= 1;  // progress has been made, but we need to confirm that the next element to the left isn't smaller than the ETBP
			moves += 1; // one element has been moved
			compares += 1; // one comparison has been made between two elements
		}
		compares += 1; // coincides with the falsy boolean evaluated by the while loop
		arr[index_to_the_left + 1] = element_to_be_placed; // move the ETBP to the right of the determined index!
		moves += 1; // one element has been moved
	}
	
	// stop clock and calculate time elapsed
	auto stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	
	// success!
	return;
}

//
// printInsertionSortStats(): prints compares and swaps done in the last call to selectionSort()
//
void printInsertionSortStats(int n) {
	printf("---- Insertion Sort ----\n");
  printf("%d elements\n", n);
  printf("%d moves\n", moves);
  printf("%d compares\n\n", compares);  
  printf("%f seconds to sort\n\n", duration * 1e-6);
	return;
}