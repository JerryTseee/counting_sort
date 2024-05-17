#include<iostream>
using namespace std;

int main(){

    int A[] = {5,4,3,5,6,1,3,2,5,6,4,2};//array that we want to sort
    int length = sizeof(A)/sizeof(A[0]);
    int k = 6;//length of the working array

    int* B = new int[k+1];//additional space
    for (int i = 0; i <= k; i++){
        B[i] = 0;//initialize the working array
    }

    int* C = new int[length];//output array

    for (int i = 0; i<length; i++){
        B[ A[i] ] = B[ A[i] ] + 1;//count the appearance times of each number
    }

    for (int i = 1; i<= k; i++){
        B[i] = B[i] + B[i-1];//store the number of elements less or equal to each value
    }

    for (int i = length-1; i>=0; i--){
        C[ B[A[i]]-1 ] = A[i];
        B[A[i]] -= 1;//decrement the value
    }

    for (int i = 0; i< length; i++){
        cout << C[i] <<" ";
    }
    cout<<endl;

    delete[] B;
    delete[] C;

    return 0;
}
