#include <iostream>
#include <climits>
using namespace std;

int maxOfTwo(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    }
    return num2;
}

int maxOfThree(int num1, int num2, int num3) {
    return maxOfTwo(maxOfTwo(num1, num2), num3);
}

int sumMaxHelper(const int *arr, int low, int mid, int high) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;

    for (int j = mid + 1; j <= high; j++) {
        sum = sum + arr[j];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    return (leftSum + rightSum);
}

int sumMax(int *arr, int low, int high) {
    if (high == low)
        return (low, high, arr[low]);
    else {
        int mid = (low + high) / 2;
        return maxOfThree(sumMax(arr, low, mid), sumMax(arr, mid + 1, high), sumMaxHelper(arr, low, mid, high));
    }
}

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << sumMax(arr, 0, size - 1);
    delete[] arr;
    return 0;

}

//colaborators mario barrera