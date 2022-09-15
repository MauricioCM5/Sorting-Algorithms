#pragma once
//Returns the index of where pivot is now that it was ordered
int partition(int array[], int ini, int fin) {
	int smallest = ini - 1; //In case it doesn't compare change at all
	int pivot = array[fin]; //Using last element as pivot
	for (int i = ini; i < fin; i++) {
		if (array[i] < pivot) {
			smallest++;
			swap(array[smallest], array[i]);
		}
	}
	swap(array[smallest + 1], array[fin]); //swaping the last smallest than pivot and pivot
	return smallest + 1; //because it was bigger than the most recent smaller

}

void quickSort(int array[], int ini, int fin) {
	if (ini < fin) {
		int pivot = partition(array, ini, fin); //index
		quickSort(array, ini, pivot - 1);
		quickSort(array, pivot + 1, fin);
	}
}