#pragma once
/*int* merge(int a[], int b[]){

        int sA = sizeA(a), sB = sizeA(b);
        int sizeC = sA + sB;
        int* c = new int(sizeC);
        //[sizeC];
        int counter = 0, ma = 0, mb = 0, i;

        while(ma < sA && mb < sB){
                if(a[ma] < b[mb]){
                        c[counter] = a[ma];
                        ma++;
                }
                else{
                        c[counter] = b[mb];
                        mb++;
                }
                counter++;
                cout << "HERE\n";
        }
        for(i = ma; i < sA; i++, counter++) c[counter] = a[ma];
        for(i = mb; i < sB; i++, counter++) c[counter] = b[mb];
        return c;
}*/

void merge(int c[], int ini, int fin, int mid) {

    int sA = mid - ini + 1; // size of array
    int sB = fin - mid;
    int* a = new int[sA];
    int* b = new int[sB];
    int i, ma = 0, mb = 0, counter = ini;
    // cout << "HERE\n";
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

// Continously split the array in half
/*int* mergeSort(int array[], int n){
        if (n == 1) return array;

        int* left = new int(ceil(n/2));
        int* right = new int(n/2);
        int i, fh = ceil(n/2);
        for(i = 0; i < fh; i++)
                left[i] = array[i];

        for(i = 0; i < n/2; i++)
                right[i] = array[i+(n/2)];

        cout << "HERE\n";

        left = mergeSort(left, fh);
        right = mergeSort(right, n/2);
        merge(left, right);


}*/

void mergeSort(int array[], int ini, int fin) {
    // cout << "HERE\n";
    if (ini >= fin)
        return;
    int mid = ini + (fin - ini) / 2;
    mergeSort(array, ini, mid);
    mergeSort(array, mid + 1, fin);
    merge(array, ini, fin, mid);
}