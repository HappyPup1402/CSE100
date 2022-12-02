#include <iostream>
using namespace std;

void merge(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;

    int size1 = mid - left + 1;
    int size2 = right - mid;

    int *leftArr = new int[size1];
    int *rightArr = new int[size2];

    for (int i = 0; i < size1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++) {
        rightArr[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int x = left;

    while (i < size1 && j < size2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[x++] = leftArr[i++];
        } else {
            arr[x++] = rightArr[j++];
        }
    }

    while (i < size1) {
        arr[x++] = leftArr[i++];
    }

    while (j < size2) {
        arr[x++] = rightArr[j++];
    }
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ";";
    }
    delete[] arr;
}

//colaborators mario barrera