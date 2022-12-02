#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<int> arr[], int n, int pos){
    vector<int> * newArr;
    int count[9] = {0};
    
    newArr = new vector<int>[n];

    for (int i = 0; i < n; i++){
        count[arr[i][pos]%9]++;
    }

    for (int i = 1; i < 9; i++){
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--){
        newArr[count[arr[i][pos]%9] - 1] = arr[i];
        count[arr[i][pos]%9]--;
    }

    for (int i = 0; i < n; i++){
        arr[i] = newArr[i];
    }
}

void radixsort(vector<int> arr[], int n){
    for (int i = 9; i >= 0 ; i--){
        countSort(arr, n, i);
    }
}

int main(){
    int n;
    int num;
    cin >> n;
  
    vector<int> *arr;
    arr = new vector<int>[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cin>>num;
            arr[i].push_back(num);
        }
    }

    radixsort(arr, n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cout << arr[i][j] << ";";
        }
        cout << "\n";
    }

    return 0;
}