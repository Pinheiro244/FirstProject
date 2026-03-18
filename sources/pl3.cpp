#include "pl3.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int* allocateInt() {
    return new int;
}

void freeInt(int* p) {
    delete p;
}


int* allocateArray(int n) {
    return new int[n];
}

void fillRandom(int* arr, int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void freeArray(int* arr) {
    delete[] arr;
}


int* getRandom() {
    int* r = new int[ARRAY_SIZE];

    srand((unsigned)time(NULL));

    for (int* p = r; p < r + ARRAY_SIZE; p++) {
        *p = rand();
    }

    return r;
}

void incrementOne(int* r) {
    for (int* p = r; p < r + ARRAY_SIZE; p++) {
        *p = *p + 1;
    }
}




void printReverse(int* arr, int n) {
    for(int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void sumArrays(int* arr, int* arr1, int* arr2, int n) {
    for(int i = 0; i < n; i++) {
        arr2[i] = arr[i] + arr1[n - 1 - i];
    }
}


int getElement(int* arr, int index) {
    return arr[index];
}


int** createMatrix(int rows, int cols) {
    int** m = new int*[rows];
    for(int i = 0; i < rows; i++) {
        m[i] = new int[cols];
    }
    return m;
}

void fillMatrix(int** m, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            m[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int** m, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void freeMatrix(int** m, int rows) {
    for(int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
}