#include "pl2.h"

bool isEven(unsigned int n){
    return (n & 1) == 0;
}

bool isEqual(int a, int b){
    return (a ^ b) == 0;
}

int countBits(int n){
    int count = 0;

    while(n != 0){
        count += (n & 1);
        n = n >> 1;
    }

    return count;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort3(int *a, int *b, int *c){

    if(*a > *b) swap(a,b);
    if(*a > *c) swap(a,c);
    if(*b > *c) swap(b,c);

}

int sumArray(int arr[], int size){

    int sum = 0;

    for(int i=0;i<size;i++){
        sum += arr[i];
    }

    return sum;
}

int largestValue(int arr[], int size){

    int max = arr[0];

    for(int i=1;i<size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

int firstRepeated(int arr[], int size){

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i] == arr[j]){
                return arr[i];
            }
        }
    }

    return -1;
}

int mostFrequent(int arr[], int size){

    int maxCount = 0;
    int most = arr[0];

    for(int i=0;i<size;i++){

        int count = 0;

        for(int j=0;j<size;j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }

        if(count > maxCount){
            maxCount = count;
            most = arr[i];
        }
    }

    return most;
}


void evenOdd(int arr[], int size){

    int temp[size];
    int index = 0;

    for(int i=0;i<size;i++){
        if(arr[i] % 2 == 0){
            temp[index++] = arr[i];
        }
    }

    for(int i=0;i<size;i++){
        if(arr[i] % 2 != 0){
            temp[index++] = arr[i];
        }
    }

    for(int i=0;i<size;i++){
        arr[i] = temp[i];
    }
}

void sortArray(int arr[], int size){

    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){

            if(arr[i] > arr[j]){

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }
}

int sumMatrix(int m[][10], int rows, int cols){

    int sum = 0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            sum += m[i][j];
        }
    }

    return sum;
}

void addMatrix(int A[][10], int B[][10], int C[][10], int rows, int cols){

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrix(int A[][10], int B[][10], int C[][10], int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            C[i][j] = 0;

            for(int k=0;k<n;k++){
                C[i][j] += A[i][k] * B[k][j];
            }

        }
    }
}

