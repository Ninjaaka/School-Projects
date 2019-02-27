/*
Stanley Su
CSCI 235

This project is about sorting algorithms and basically testing the time it takes for it to complete
a sort. We compare different sorting algorithms to see what is faster and what is slower.

*/




#include <iostream>
#include <fstream>
#include <cstdlib> // Provides size_t
#include <random>
#include <time.h>
#include<chrono>

using namespace std;
/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/

/**
@post Sorts an array in ascending order using the selection sort algorithm.
@param a the array to sort
@param size the number of elements in a
*/
void selectionSort(int a[], size_t size);

/**
@post Sorts an array in ascending order using insertion sort.
@param a the array to sort
@param size of the array
*/
void insertionSort(int a[], size_t size);

/**
@post Sorts the elements in a range of a array.
@param a the array with the elements to sort
@param from the first position in the range to sort
@param to the last position in the range to sort (included)
*/
void mergeSort(int a[], int from, int to);


void mergeSort(int data[], size_t n);

/*********************************************************************/
/****************** ARRAY POPULATING FUNCTIONS ***********************/
/*********************************************************************/


/**
@post Populates values with randomly generated numbers in range size
@param values the array to populate
@param size of the array to be populated
*/
void generateRandomArray(int values[], size_t size);

/**
@post Populates values with integers in ascending order
@param values the array to populate
@param size of the array to be populated
*/
void generateAscendingArray(int values[], size_t size);

/**
@post Populates values with integers in descending order
@param values the array to populate
@param size of the array to be populated
*/
void generateDescendingArray(int values[], size_t size);

/**
@post Populates values with integers in ascending order except for the last 10 that are randomly generated
@param values the array to populate
@param size of the array to be populated
*/
void generateLastTenRandomArray(int values[], size_t size);

/**
@post Populates values with integers in randomly generated in range size/10
@param values the array to populate
@param size of the array to be populated
*/void generateFewRandomArray(int values[], size_t size);



/*****************************************************************/
/****************** RUNTIME TEST FUNCTIONS ***********************/
/*****************************************************************/


///**
//@post Sorts values in ascending order and averages its runtime over 10 runs
//@param sortingFunction the function used to sort the array
//@param values the array to sort
//@param size of the array to sort
//@return the average runtime in microseconds
//*/
double sortTest(void(*sortingFunction)(int a[], size_t size), int values[], size_t size)
{
	double sum = 0;
	for (int i = 0 ;i < 10; i++)
	{


		using clock = std::chrono::system_clock;
		using ms = std::chrono::milliseconds;

		const auto before = clock::now();
		sortingFunction(values, size);

		const auto duration = std::chrono::duration_cast<ms>(clock::now() - before);

		sum += (duration.count() / 1000.0);

		return duration.count();

	}

	return (sum / 10);

}
//
///**
//@post Sorts values in ascending order using mergeSort and averages its runtime over 10 runs
//@param values the array to sort
//@param size of the array to sort
//@return the average runtime in microseconds
//*/
double mergeSortTest(int values[], size_t size)
{
	double sum = 0;
	for (int i = 0; i < 10; i++)
	{


		using clock = std::chrono::system_clock;
		using ms = std::chrono::milliseconds;

		const auto before = clock::now();
		mergeSort(values, size);

		const auto duration = std::chrono::duration_cast<ms>(clock::now() - before);

		sum += (duration.count() / 1000.0);

		return duration.count();

	}

	return (sum / 10);

	
	return 1;
}


void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void selectionSort(int a[], size_t size)
{


		size_t i, j, index_of_largest;
		int largest;

		if (size == 0) return;

		for (i = size - 1; i > 0; --i) {
			largest = a[0];
			index_of_largest = 0;
			for (j = 1; j <= i; ++j) {
				if (a[j] > largest) {
					largest = a[j];
					index_of_largest = j;
				}
			}
			//still have to write this function!
			swap(a[i], a[index_of_largest]);
		}


}

void generateRandomArray(int values[], size_t size)
{


	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		values[i] = rand() % size;
	}
}


void insertionSort(int a[], size_t size)
{

	int temp;
	int j;

	for (int i = 0; i < size; i++) {
		j = i;

		while ((j > 0) && a[j] < a[j - 1]) {
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
	}

}

void mergeSort(int data[], size_t n1, size_t n2)
{
	int * temp;
	size_t copied = 0;
	size_t copied1 = 0;
	size_t copied2 = 0;
	size_t i;

	//allocates memory for the temp dynamic array
	temp = new int[n1 + n2];

	//merge elements
	while ((copied1 < n1) && (copied2 < n2)) {
		if (data[copied1] < (data + n1)[copied2]) {
			temp[copied++] = data[copied1++];
		}
		else {
			temp[copied++] = (data + n1)[copied2++];
		}
	}

	while (copied1 < n1) {
		temp[copied++] = data[copied1++];
	}

	while (copied2 < n2) {
		temp[copied++] = (data + n1)[copied2++];
	}

	for (i = 0; i < n1 + n2; ++i) {
		data[i] = temp[i];
	}

	delete[] temp;


}
void mergeSort(int data[], size_t n){
		size_t n1; //Size of the first subarray
		size_t n2; //Size of the second subarray

		if (n>1){
			n1 = n / 2;
			n2 = n - n1;

			mergeSort(data, n1);
			mergeSort((data + n1), n2);

			mergeSort(data, n1, n2);
		}
	}


void generateFewRandomArray(int values[], size_t size)
{


	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		values[i] = rand() % 10;
	}

}


void generateLastTenRandomArray(int values[], size_t size)
{


	for (int i = 0; i < size - 10; i++)
	{

		values[i] = i;

	}

	for (int i = size - 10; i < size; i++)
	{

		values[i] = rand() % size;

	}

}

void generateDescendingArray(int values[], size_t size)
{

	int sz = size;
	for (int i = 0; i < size; i++)
	{
		values[i] = sz;
		sz--;
	}


}

void generateAscendingArray(int values[], size_t size)
{

	int sz = size;
	for (int i = 0; i < size; i++)
	{
		values[i] = i;
		
	}


}

void mergeSort(int a[], int from, int to)
{
	mergeSort(a,to);
}