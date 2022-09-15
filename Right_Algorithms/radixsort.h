#pragma once
int Max_num(int array[], int n) {
	int m = array[0];
	for (int i = 1; i < n; i++) if (array[i] > m) m = array[i];
	return m;
}

//arreglo de listas enlazadas wtf
//Procesa los digitos

void miniSort(int array[], const int n, int digit) {
	const int maximum = 10;
	int i;
	int* res = new int[n];
	int  counters[maximum];
	for (i = 0; i < maximum; i++) counters[i] = 0;
	//Those with that digit, like an array of lists. 
	for (i = 0; i < n; i++) counters[(array[i] / digit) % 10]++;
	//So that it outputs correctly
	for (i = 1; i < maximum; i++) counters[i] += counters[i - 1];

	//Output
	for (i = n - 1; i >= 0; i--) {
		res[counters[(array[i] / digit) % 10] - 1] = array[i];
		counters[(array[i] / digit) % 10]--;
	}
	for (i = 0; i < n; i++) array[i] = res[i];

	delete[] res;
}


void radixSort(int array[], int n) {
	//int n = 0; //numero de digitos 
	int max = Max_num(array, n);

	for (int digit = 1; max / digit > 0; digit *= 10) //one digit larger each time
		miniSort(array, n, digit);

}