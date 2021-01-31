//-------------------------------------------------------------
// Lola Blue
//
// Project: Sorting Algorithms
//		
// 			
//
// main.cpp
//-------------------------------------------------------------
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include <iostream>
#include <cstdlib>
using namespace std;


//
// printArray(): prints the first n elements of argument array
//
void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return;
}

int main() {

  // WELCOME AND SETUP 
  int n;  
  cout << "WELCOME TO MY SORTING ALGORITHMS PROJECT! (>^_^)>\n"; 
  cout << "Please enter an array size: n =  ";
  cin >> n; // get array size
  cout << endl;
  int *array = new int[n]; // new keyword allocates memory on the heap.
  
  
  // BUBBLE SORT
  srand(822202); // set seed for rand()
  for (int i = 0; i < n ; i++) { // let's throw some pseudorandom ints in there, 0 - 100
    array[i] = rand() % 201; // limit them to 200, why not.
  }
  bubbleSort(array, n);
  //printArray(array, n);
  printBubbleSortStats(n);
  
  
  // SELECTION SORT
  srand(822202); // set seed for rand()
  for (int i = 0; i < n ; i++) { // let's throw some pseudorandom ints in there, 0 - 100
    array[i] = rand() % 101;
  }
  selectionSort(array, n);
  //printArray(array, n);	
  printSelectionSortStats(n);
  
  // INSERTION SORT
  srand(822202); // set seed for rand()
  for (int i = 0; i < n ; i++) { // let's throw some pseudorandom ints in there, 0 - 100
    array[i] = rand() % 101;
  }
  insertionSort(array, n);
  //printArray(array, n);
  printInsertionSortStats(n);
  
  // MERGE SORT
  srand(822202); // set seed for rand()
  for (int i = 0; i < n ; i++) { // let's throw some pseudorandom ints in there, 0 - 100
    array[i] = rand() % 101;
  }
  mergeSort(array, n);
  // printArray(array, n);
  printMergeSortStats(n);
  
  // QUICK SORT
  srand(822202); // set seed for rand()
  for (int i = 0; i < n ; i++) { // let's throw some pseudorandom ints in there, 0 - 100
    array[i] = rand() % 101;
  }
  quickSort(array, n);
  //printArray(array, n);
  printQuickSortStats(n);
  
  // HOUSEKEEPING
  delete[] array; // reserved memory of the heap must be freed.
  return 0;
  
}