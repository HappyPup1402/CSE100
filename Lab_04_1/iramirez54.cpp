#include <iostream>
using namespace std;


void Max_Heapify(int arr[],int n, int i){
    //largest is also the parent
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i +2;

    //checks if the left child is larger than the parent. if it is then it takes that childs index;
    if(left_child < n && arr[left_child] > arr[largest]){
        largest = left_child;
    }

    //checks if the right child is larger than the parent. if it is then it takes that childs index;
    if(right_child < n && arr[right_child] > arr[largest]){
        largest = right_child;
    }

    //if the index of the parent changes the parent swaps value with the child that was greater
    if(largest != i){
        swap(arr[i], arr[largest]);
        
        //this part of the code is used to fix the tree with the parents being the largest after the swap
        Max_Heapify(arr, n, largest);
    }
}

//this function makes sure the largest value with children are at the front of the array or tree
void Build_Max_Heap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        Max_Heapify(arr, n, i);
    }
}

void HeapSort(int arr[], int n){
    //we first build a max heap
    Build_Max_Heap(arr, n);

    for(int i = n-1; i >= 1; i--){
        //the largest root gets swapped with the smallest
        swap(arr[0], arr[i]);

        /*since swapping the largest with the smallest changes the pattern of the largest being in the front
          we have to call max_heapify put the array back in that same pattern or fix the tree. max heapifies
          the reduced array
        */
        Max_Heapify(arr, i, 0);
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

    HeapSort(arr, n);
  
    printArray(arr, n);

}