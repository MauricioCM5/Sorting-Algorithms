#pragma once
// gap es la distancia
/*calcular el gap por cada pase,  y luego seleccionar los elementos hacia la
derecha de gap a ______ gap______ b -> derecha de gap, reducir el gap en 2
        */

void shellSort(int array[], int n) {
    int gap = n / 2;
    int i, j;
    while (gap > 0) {
        for (i = 0; i < n - gap; i++) {
            for (j = i + gap; j - gap >= 0 && array[j] < array[j - gap]; j -= gap)
                swap(array[j], array[j - gap]);
        }
        gap /= 2;
    }
    // termina cuando gap es 1
    /*
    if a[i] > a[i+gap]
            swap(a[i], a[i+gap])
            while(.... hasta que se pueda seguir usando el intercambio)
    */
}