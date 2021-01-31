//-------------------------------------------------------------
// Lola Blue
//
// Project: Sorting Algorithms
// 			QUICK SORT
//				time complexity: O(nlogn) - O(n^2)
//				space complexity: O(1)
//				unstable
//			  recursive
//				-> Use when fast sorting desired and if stability
//					 does not matter.
// quick.cpp
//-------------------------------------------------------------
#include "quick.h"
#include <cstdio>
#include <chrono>
#define SWAP(arr, x, y) { int t = arr[x]; arr[x] = arr[y]; arr[y] = t; }

static int compares = 0; // for statistics - how many comparisons are made?
static int moves = 0; // for statistics - how many times is something moved around?
static double duration; // for timing quickSort()

//
// partition(): 
// takes last element (index right) as the pivot element in the subarray [left, right]. 
// [x | x < pivot] + pivot + [x | x > pivot]
// returns resulting index of the partition element
//
int partition(int *arr, int left, int right) {
  
  // the pivot is the element that items will be divided by. the pivotIndex is the lower bound of the (> pivot) subarray
  int pivot = arr[right]; // let's choose the rightmost element as the pivot element.
  int pivotIndex = left; // let's assume the proper pivot index is at index left.
  
  // iterate over the entire subarray 
  for (int i = left; i < right; i++) {
    
    // if arr[i] is smaller than the pivot, it belongs before the current pivotIndex. 
    if (arr[i] <= pivot) {
      SWAP(arr, pivotIndex, i); // swapping ensures that arr[i] will be to the left of the new partition index. 
      pivotIndex++; // the greater-than pivot section now begins one index to the right
      moves += 3; // swapping requires 3 movements (see macro)
    }
    compares++; // a comparison has been made between two elements
  }
  
  SWAP(arr, pivotIndex, right); // put the pivot in its proper place! (it belongs at the piv	otIndex we thought so hard to find)
  moves += 3; // swapping requires 3 movements (see macro)
  return pivotIndex; // return the secured index. nice... 
}

//
// quickSort(): 
// recursively divides-and-conquers an array for indices [left, right]
// calls partition()
//
void quickSort(int *arr, int left, int right) {

	// QUICKSORT
	if (left < right) {
		int pivotIndex = partition(arr, left, right); // divide, conquer 1 element (element at returned index is placed)
		quickSort(arr, left, pivotIndex - 1); // Conquer: recursive call for left subarray
		quickSort(arr, pivotIndex + 1, right); // Conquer: recursive call for right subarray
		// no combining necessary! 
	}
	
	// Base Case: if left == right, the array is of size 1 and is already sorted!
	return;
}

//
// quickSort()
// sorts array of size n
//
void quickSort(int *arr, int n) {

	auto start = std::chrono::high_resolution_clock::now(); // start clock
	
	quickSort(arr, 0, n - 1);
	
	// stop clock and calculate time elapsed
	auto stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	
	// success!
	return;
	
}

//
// printQuickSortStats(): prints compares and swaps done in the last call to selectionSort()
//
void printQuickSortStats(int n) {
  printf("---- Quick Sort ----\n");
  printf("%d elements\n", n);
  printf("%d moves\n", moves);
  printf("%d compares\n\n", compares);  
  printf("%f seconds to sort\n\n", duration * 1e-6);
	return;
}