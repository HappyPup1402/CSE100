#include <iostream>
using namespace std;
#include <random>

//this function randomly picks a index from the array
int randomNum(int low_index, int high_index){
    //a random number generator that produces non-deterministic random numbers.
    random_device num;

    //a portable Mersenne Twister(popular algorithm) random number generator.
    mt19937 rng(num());

    //assigns the range for the generator mt19937
    uniform_int_distribution<mt19937::result_type> dist(low_index,high_index); // distribution in range [low_index, high_index]
    return dist(rng);
}

int partition(int arr[], int p, int r){
    int pivot = arr[r];

    //this variable is the index of where the r will be placed in the array after puting all values smaller on the left and all larger values on the right of r
    int i = (p - 1);

    for(int j = p; j <= r-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return(i + 1);
}

//gives the partition function a random number to swap the right element in the array
int randomized_partition(int arr[], int p, int r){
    int randIndex = randomNum(p,r);
    swap(arr[randIndex], arr[r]);
    return partition(arr, p ,r);
}

//p is starting index
//r is the ending index
void randomized_quicksort(int arr[], int p, int r){
    if(p < r){
        //q is the index of the new random right most element 
        int q = randomized_partition(arr, p, r);

        //this randomized quicksort with sort the left side of the randomized partition
        randomized_quicksort(arr, p, q-1);

        //this randomized quicksort with sort the right side of the randomized partition
        randomized_quicksort(arr, q+1, r);
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i){
        cout << arr[i] << ";";
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    int input = 0;

    for(int i = 0; i < n; i++){
        cin >> input;
        arr[i] = input;
    }

    randomized_quicksort(arr, 0, n-1);
    
    printArray(arr, n);

}