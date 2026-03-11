#ifndef HEADERS_PL2_H_
#define HEADERS_PL2_H_



bool isEven(unsigned int n);
bool isEqual(int a, int b);
int countBits(int n);


void swap(int *a, int *b);
void sort3(int *a, int *b, int *c);


int sumArray(int arr[], int size);
int largestValue(int arr[], int size);
int firstRepeated(int arr[], int size);
int mostFrequent(int arr[], int size);
void evenOdd(int arr[], int size);
void sortArray(int arr[], int size);


int sumMatrix(int m[][10], int rows, int cols);
void addMatrix(int A[][10], int B[][10], int C[][10], int rows, int cols);
void multiplyMatrix(int A[][10], int B[][10], int C[][10], int n);







#endif /* HEADERS_PL2_H_ */