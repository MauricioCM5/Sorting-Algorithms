#pragma once
void heapify(int arr[], int N, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest]) largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        // sub-tree affected so heapify it recursively
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    // Building max heap
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0); // heapify with root in mind
    }
}
