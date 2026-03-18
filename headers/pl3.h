#ifndef HEADERS_PL3_H_
#define HEADERS_PL3_H_

// Inteiro dinâmico
int* allocateInt();
void freeInt(int* p);

// Array dinâmico
int* allocateArray(int n);
void fillRandom(int* arr, int n);
void printArray(int* arr, int n);
void freeArray(int* arr);


#define ARRAY_SIZE 10

int* getRandom();
void incrementOne(int* r);



//  Reverse
void printReverse(int* arr, int n);

// Somar arrays
void sumArrays(int* arr, int* arr1, int* arr2, int n);

//  Get elemento
int getElement(int* arr, int index);

//  Matriz dinâmica
int** createMatrix(int rows, int cols);
void fillMatrix(int** m, int rows, int cols);
void printMatrix(int** m, int rows, int cols);
void freeMatrix(int** m, int rows);

#endif










