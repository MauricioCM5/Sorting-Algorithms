#include <iostream>
#include <math.h>
#include<vector>
#include<algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include <stdio.h>

using namespace std;
#define sizeA(a) (sizeof(a) / sizeof(int))
#include "bucketsort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "radixsort.h"
#include "shellsort.h"
#include <chrono>
using namespace std::chrono;

template <class T>
void print_arr(T array[], int n) {
	for (int i = 0; i < n; i++)
		cout << array[i] << "\t";
	cout << "\n";
}

template<class T>
void print_arr2(T array[], int n) {
	cout << "[";
	for (int i = 0; i < n; i++)
		cout << array[i] << ", ";
	cout << "],\n";
}

void generate_big_array(int array[], int n) {
	for (int i = 0; i < n; i++)
		array[i] = (rand() % 25000 + 1) * (rand() % 25000 + 1);
}

void copy_array(int array[], int array2[], int n) {
	for (int i = 0; i < n; i++)
		array[i] = array2[i];
}


void running(int array[], int origin[], int n, double* times) {
	//quickSort
	copy_array(array, origin, n);
	auto start = high_resolution_clock::now();
	quickSort(array, 0, n-1);
	auto stop = high_resolution_clock::now();
	times[0] = duration_cast<microseconds>(stop - start).count();

	//mergeSort
	copy_array(array, origin, n);
	start = high_resolution_clock::now();
	mergeSort(array, 0, n - 1);
	stop = high_resolution_clock::now();
	times[1] = duration_cast<microseconds>(stop - start).count();

	//shellSort
	copy_array(array, origin, n);
	start = high_resolution_clock::now();
	shellSort(array, n);
	stop = high_resolution_clock::now();
	times[2] = duration_cast<microseconds>(stop - start).count();
	
	//radixSort
	copy_array(array, origin, n);
	start = high_resolution_clock::now();
	radixSort(array, n);
	stop = high_resolution_clock::now();
	times[3] = duration_cast<microseconds>(stop - start).count();

	//bucketSort
	copy_array(array, origin, n);
	start = high_resolution_clock::now();
	bucketSort(array, n);
	stop = high_resolution_clock::now();
	times[4] = duration_cast<microseconds>(stop - start).count();

	//heapSort
	copy_array(array, origin, n);
	start = high_resolution_clock::now();
	heapSort(array, n);
	stop = high_resolution_clock::now();
	times[5] = duration_cast<microseconds>(stop - start).count();
	
}


int main() {
	const int size = 12000, multi = 8000;
	int origin[size];
	int num = multi;

	const int times_size = size / multi;
	double times[times_size][6];
	generate_big_array(origin, size);
	int test[size];

	cout << "\tCOMPUTATIONAL TIME\n";
	cout << "-For 6 different sorting algorithms\n\n";
	cout << "----------------------------------------\n";
	int i;
	for (i = 0, num = multi; i < times_size; i++, num+= multi) {
		running(test, origin, num, times[num / multi - 1]);
		cout << "With : " << num << " elements\n\n";
		cout << "n\tquick\tmerge\tshell\tradix\tbucket\theap\n";
		cout << num << "\t";
		print_arr(times[i], 6);
		cout << "----------------------------------------\n";
	}

	//for (i = 0; i < times_size; i++)
	//	print_arr2(times[i], 6); cout << "\n";

}
