/**
 * @file		QuickSort.cpp
 * @author		Ratna Lama
 * @date		08/03/2018
 * @brief 		A program to implement QuickSort.
 * 
 * @algorithm: 
 * Paradigm:: Divide and Conquer
 * Quick Sort orders values by partitioning the list around one
 * element, then sorting each partition.
 * Steps: 
 * 1) Choose one element in the list to be the pivot (usually the last element in the array)
 * 2) Organize the elements so that all elements less than the pivot are to the left and all greater
 * are to the right.
 * 3) Apply the Quick Sort algorith (recursivley) to both partitions
 * 
 */
 
#include <iostream>		// std::cout
#include <algorithm>	// std::swap
using namespace std;

// Function Prototypes
template<typename ItemType>
void QuickSort(ItemType Array[], int first_index, int last_index);

template<typename ItemType>
int Partition(ItemType Array[], int first_index, int last_index);



// Begin Main 
int main() {
	
	// Sort integer using QuickSort()
	int num[] = {20,80,40,25,60,10,15};
	QuickSort(num, 0, 6);
	
	cout << "[";
	for (int i=0; i<7; i++) {
		cout << num[i] << " ";
	}
	cout << "]" << endl;
	cout << "\n-------------------------------------------------------\n" << endl;
	
	// Sort string using QuickSort()
	string flower[] = {"lilly", "rose", "marigold", "daffodil", "tulip", "bougenvila", "dahlia", "jasmine"};
	QuickSort (flower, 0,7);
	cout << "[";
	for (int i=0; i<8; i++) {
		cout << flower[i] << " ";
	}
	cout << "]" << endl;
	cout << "\n-------------------------------------------------------\n" << endl;
	
	// Sort char using QuickSort()
	char vowels[] = {'i', 'o', 'e', 'u', 'a'};
	QuickSort(vowels, 0, 4);
	cout << "[";
	for (int i=0; i<5; i++) {
		cout << vowels[i] << " ";
	}
	cout << "]" << endl;
	cout << "\n-------------------------------------------------------\n" << endl;
	
	
	return 0;
} // end main


/**
* Function QuickSort
* 
**/ 
template<typename ItemType>
void QuickSort(ItemType Array[], int first_index, int last_index) {
	if (first_index < last_index) {		// Base Case
		
		// returns the index position of the corretly placed value in the array
		int partition_index = Partition(Array, first_index, last_index);
	
		QuickSort(Array, first_index, partition_index-1);	// Recursive call for left-half of the partitioned array
		QuickSort(Array, partition_index+1, last_index);	// Recursive call for right-half of the partitioned array
	}
} // end QuickSort()


/**
* Function Partition
* 
**/ 
template<typename ItemType>
int Partition(ItemType Array[], int first_index, int last_index) {
	ItemType pivot = Array[last_index];		// consider last Array element as the pivot 
	int i = first_index - 1;				// i th index starts at -1
	
	for (int j = first_index; j<last_index; j++) {
		
		if (Array[j] <= pivot ) {			// checks if the Array element is less than the pivot
			i++;							
			swap(Array[i], Array[j]);		// swap to form partition
			}
	}
	swap(Array[i+1], Array[last_index]);	// swap the pivot (the last element of the array) to the right position
	return i+1;								// return the index position of the pivot
} // end Partition()
