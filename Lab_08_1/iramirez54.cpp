#include<bits/stdc++.h>
using namespace std;
int num=0;

void print_optimal_parens(int i, int j, int n,int *bracket ){
    
    if (i == j){
        cout <<"A"<<num;
        num++;
        return ;
    }

    cout << "(";

    print_optimal_parens(i, *((bracket+i*n)+j), n, bracket);

    print_optimal_parens(*((bracket+i*n)+j) + 1, j, n, bracket); 
    cout << ")";
}



void matrix_chain_order(int p[], int n){

   int m[n][n];

   int bracket[n][n];

    for (int i=1; i<n; i++){
       m[i][i] = 0;
    }
   
    for (int L=2; L<n; L++){
        for (int i=1; i<n-L+1; i++){
           int j = i+L-1;
           m[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++){
               int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << m[1][n-1] << "\n";

    print_optimal_parens(1, n-1, n, (int *)bracket);

}

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }

    int size = n+1;

   matrix_chain_order(arr, size);
   cout<<"\n";
   return 0;
}