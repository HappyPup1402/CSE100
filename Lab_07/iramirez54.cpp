#include<iostream>
#include <climits> 
using namespace std;

void Extended_Botttom_Up_Cut_Rod(int* arr, int size){
    int i, j, q;
    int r[size+1];
    int s[size+1];
    r[0] = 0;

    for(j = 1; j < size; j++){
        q = INT_MIN;
        for(i = 1; i <= j; i++){
            if(q < arr[i] + r[j - i]){
                q = arr[i] +r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }


    size = size - 1;
    cout << r[size] << endl;
    while(size > 0){
        cout << s[size] << " ";
        size = size-s[size];
    }
    cout << "-1" << endl;
    
}



int main(){
    int size; 
    int input;
    cin >> size;
    int arr[size+1];
    arr[0] = 0;

    for(int i = 1; i <= size; i ++){
        cin >> input;
        arr[i] = input;
    }


    Extended_Botttom_Up_Cut_Rod(arr,size+1);
    

    return 0;
}
//mario barrera
