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
// quick.h
//-------------------------------------------------------------

//
// partition(): 
// takes last element (index right) as the pivot element. 
// [x | x < pivot] + pivot + [x | x > pivot]
// returns resulting index of the partition element
//
int partition(int *arr, int left, int right);

//
// quickSort(): 
// recursively divides-and-conquers an array for indices [left, right]
// calls partition()
//
void quickSort(int *arr, int left, int right);


//
// quickSort()
// sorts array of size n
//
void quickSort(int *arr, int n);

//
// printQuickSortStats()
// prints size, moves, compares, and time taken in last call to quickSort()
//
void printQuickSortStats(int n);