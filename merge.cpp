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
// merge.cpp
//-------------------------------------------------------------
#include "merge.h"
#include <cstdio>
#include <chrono>

// setup for mergeSort() statistics
static int compares = 0; // how many times are two elements compared?
static int moves = 0;  // how many times are elements are moved around?
static double duration; // how long does mergeSort() take to execute?


//
// merge():
// merges two subarrays [left, middle] and [middle + 1, right]
// subarrays are assumed to be sorted already, assumes left < right
//
void merge(int *arr, int left, int middle, int right) {

  // compute the total number of elements left to right
  int n = right - left + 1;
  
  // create temporary array and variable to track next open index in merged array
  int mergedArray[n];
  int i = 0; 

  // create variables to track next available element in the subarrays
	int l = left; 
	int r = middle + 1;

	// while there are elements in both subarrays, compare and place the smaller one in the merged array
	while (l <= middle  && r <= right) {
	  
		if (arr[l] <= arr[r]) { // the <= maintains stability
		  mergedArray[i] = arr[l]; // either the left element belongs 
		  l++; // the next available element is now  to the right 
		} else {
			mergedArray[i] = arr[r]; // or the right element belongs
			r++; // the next available element is now to the right
		}
		i++; // the next available position in the merged array is now to the right
		compares += 1; // a comparison has been made between two elements
		moves +=1; // one element has been moved
		
	}
	
	// for leftover elements in the left array
	while(l <= middle) { // copy over any remaining elements
	  mergedArray[i] = arr[l];
	  i++; // the next available position in the merged array is now to the right
	  l++; // the next available element is now to the right
	  moves += 1; // one element has been moved
	}
	
	// for leftover elements in the right array
	while (r <= right) { // copy over any remaining elements
	  mergedArray[i] = arr[r];
	  i++; // the next available position in the merged array is now to the right
	  r++; // the next available element is now to the right
	  moves += 1; // one element has been moved
	}
	
	// copy the merged array back into arr
	for (int i = 0; i < n; i++) {
	  arr[left + i] = mergedArray[i]; // left may not be 0, so calibrate by adding left to i
	  moves++; // one element has been moved
	}
	
	// success! 
	return;
}

//
// mergeSort():
// recursively divides-and-conquers an array for indices [left, right] 
//
void mergeSort(int *arr, int left, int right) {
  
  // MERGE SORT
  if  (left < right) {
	  int middle = left + (right - left) / 2; // Divide: find the approximate middle index of array
	  mergeSort(arr, left, middle); // Conquer: recursive call for left subarray
	  mergeSort(arr, middle + 1, right); // Conquer: recursive call for right subarray
	  merge(arr, left, middle, right); // Combine: combine the sorted left and right subarrays
	}
	
	// Base Case: if left == right, the array is of size 1 and is already sorted!
	return;
}

//
// mergeSort():
// sorts an array of size n
//
void mergeSort(int *arr, int n) {

	auto start = std::chrono::high_resolution_clock::now(); // start clock

	mergeSort(arr, 0, n - 1); // merge sort the argument array! :) 
	
	// stop clock and calculate time elapsed
	auto stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
}


//
// printMergeSortStats()
// prints size, moves, compares, and time taken in last call to mergeSort()
//
void printMergeSortStats(int n) {
	printf("---- Merge Sort ----\n");
  printf("%d elements\n", n);
  printf("%d moves\n", moves);
  printf("%d compares\n\n", compares);  
  printf("%f seconds to sort\n\n", duration * 1e-6);
	return;
}
