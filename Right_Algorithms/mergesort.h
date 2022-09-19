

void merge(int c[], int ini, int fin, int mid) {

    int sA = mid - ini + 1; // size of array
    int sB = fin - mid;
    int* a = new int[sA];
    int* b = new int[sB];
    int i, ma = 0, mb = 0, counter = ini;
    
    for (i = 0; i < sA; i++)
        a[i] = c[ini + i];
    for (i = 0; i < sB; i++)
        b[i] = c[mid + i + 1];

    while (ma < sA && mb < sB) {
        if (a[ma] <= b[mb]) {
            c[counter] = a[ma];
            ma++;
        }
        else {
            c[counter] = b[mb];
            mb++;
        }
        counter++;
    }
    for (; ma < sA; ma++, counter++)
        c[counter] = a[ma];
    for (; mb < sB; mb++, counter++)
        c[counter] = b[mb];

    delete[] a;
    delete[] b;
}


void mergeSort(int array[], int ini, int fin) {
    if (ini >= fin)
        return;
    int mid = ini + (fin - ini) / 2;
    mergeSort(array, ini, mid);
    mergeSort(array, mid + 1, fin);
    merge(array, ini, fin, mid);
}
