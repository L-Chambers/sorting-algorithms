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
// selection.cpp
//-------------------------------------------------------------
#include "selection.h"
#include <cstdio>
#include <chrono>
#define SWAP(arr, x, y) { int t = arr[x]; arr[x] = arr[y]; arr[y] = t; }

// setup for selectionSort() statistics
static int compares = 0; // how many times are two elements compared?
static int moves = 0;  // how many times are elements are moved around?
static double duration; // how long does selectionSort() take to execute?

//
// findMinimum() 
// returns index of minimum element in arr in range [firstIndex, lastIndex]
//
int findMinimum(int *arr, int first, int last) {

	int min = first; // assume first element is the min
	// make a pass over the array [first, last] and update min appropriately
  for (int i = first; i < last; i++) { 
    if (arr[i] < arr[min]) { 
    	min = i;
    }
    compares += 1; // one comparison has been made between two elements
  }
  return min;
  
}

//
// selectionSort() 
// sorts array of size n
//
void selectionSort(int *arr, int n) {

  auto start = std::chrono::high_resolution_clock::now(); // start clock
  
  // SELECTION SORT
  // make a pass over the unsorted portion of the array (shrinks with each iteration)
  // i represents the first index of the unsorted portion
	for (int i = 0; i <= n - 2; i++) {
		int minIndex = findMinimum(arr, i, n); // find minimum in subarray [i, n -1]
		if (minIndex != i) { // no sense in swapping an element with itself!
			SWAP(arr, i, minIndex);  // swap actual minimum with element at i
			moves += 3;  // swapping requires 3 movements (see macro)
		}
	}
	
	// stop clock and calculate time elapsed
	auto stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	
	// success!
  return;
}

//
// printSelectionSortStats()
// prints size, moves, compares, and time taken in last call to selectionSort()
//
void printSelectionSortStats(int n) {
  printf("---- Selection Sort ----\n");
  printf("%d elements\n", n);
  printf("%d moves\n", moves);
  printf("%d compares\n\n", compares);  
  printf("%f seconds to sort\n\n", duration * 1e-6);
	return;
}