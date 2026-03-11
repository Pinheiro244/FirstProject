#include <iostream>
#include "factorial.h"
#include "pl2.h"


int main() {

    int n=10;
    int r = factorial(n);
    std::cout<<"---->"<<r<<std::endl;

    return 0;



    // -------- EVEN --------

    int n = 10;
    bool r1 = isEven(n);
    std::cout << "isEven ----> " << r1 << std::endl;


    // -------- EQUAL --------

    int a = 5;
    int b = 5;

    bool r2 = isEqual(a,b);
    std::cout << "isEqual ----> " << r2 << std::endl;


    // -------- COUNT BITS --------

    int num = 13;

    int r3 = countBits(num);
    std::cout << "countBits ----> " << r3 << std::endl;


    // -------- SWAP --------

    int x = 7;
    int y = 3;

    swap(&x,&y);

    std::cout << "swap ----> " << x << " " << y << std::endl;


    // -------- SORT3 --------

    int p = 9;
    int q = 2;
    int r = 5;

    sort3(&p,&q,&r);

    std::cout << "sort3 ----> "
              << p << " "
              << q << " "
              << r << std::endl;


    // -------- ARRAY SUM --------

    int arr[] = {1,2,3,4};
    int size = 4;

    int r4 = sumArray(arr,size);
    std::cout << "sumArray ----> " << r4 << std::endl;


    // -------- LARGEST VALUE --------

    int arr2[] = {2,8,3,5};

    int r5 = largestValue(arr2,4);
    std::cout << "largestValue ----> " << r5 << std::endl;


    // -------- FIRST REPEATED --------

    int arr3[] = {1,3,5,3,7};

    int r6 = firstRepeated(arr3,5);
    std::cout << "firstRepeated ----> " << r6 << std::endl;


    // -------- MOST FREQUENT --------

    int arr4[] = {2,3,2,4,2,5};

    int r7 = mostFrequent(arr4,6);
    std::cout << "mostFrequent ----> " << r7 << std::endl;


    // -------- EVEN ODD --------

    int arr5[] = {1,2,3,4,5,6};

    evenOdd(arr5,6);

    std::cout << "evenOdd ----> ";

    for(int i=0;i<6;i++){
        std::cout << arr5[i] << " ";
    }

    std::cout << std::endl;


    // -------- SORT ARRAY --------

    int arr6[] = {5,2,7,1};

    sortArray(arr6,4);

    std::cout << "sortArray ----> ";

    for(int i=0;i<4;i++){
        std::cout << arr6[i] << " ";
    }

    std::cout << std::endl;


    return 0;
}