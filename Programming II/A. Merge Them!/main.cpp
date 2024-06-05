//
//  main.cpp
//  A. Merge Them
//
//  Created by Majd Kawak on 10/9/22.
//

#include <iostream>
using namespace std;
int candies=0;
void count_Candies(int arr[], int start, int mid, int end)
{
    int leftArrSize = mid - start + 1;
    int rightArrSize = end - mid;
 
    int *leftArr = new int[leftArrSize];
    int *rightArr = new int[rightArrSize];
 
    for (int i = 0; i < leftArrSize; i++){
        leftArr[i] = arr[start + i];
    }
    for (int j = 0; j < rightArrSize; j++){
        rightArr[j] = arr[mid + 1 + j];
    }
 
    int indexLeftArr = 0;
    int indexRightArr = 0;
    int indexMergeArr = start;
 
    while (indexLeftArr < leftArrSize && indexRightArr < rightArrSize) {
        if (leftArr[indexLeftArr] <= rightArr[indexRightArr]) {
            arr[indexMergeArr] = leftArr[indexLeftArr];
            indexLeftArr++;
        }
        else {
            arr[indexMergeArr]= rightArr[indexRightArr];
            indexRightArr++;
        }
        indexMergeArr++;
    }

    while (indexLeftArr < leftArrSize) {
        arr[indexMergeArr] = leftArr[indexLeftArr];
        indexLeftArr++;
        indexMergeArr++;
    }

    while (indexRightArr < rightArrSize) {
        arr[indexMergeArr] = rightArr[indexRightArr];
        indexRightArr++;
        indexMergeArr++;
    }
    candies+=arr[end]-arr[start];
    delete[] leftArr;
    delete[] rightArr;
}
void calculate_Candies(int arr[], int start, int end){
    if (start >= end){
        return;
    }
    int mid = start + (end - start) / 2;
    calculate_Candies(arr, start, mid);
    calculate_Candies(arr, mid + 1, end);
    count_Candies(arr, start, mid, end);
}

int main(int argc, const char * argv[]) {
    int arr_Size;
    cin >> arr_Size;
    int arr[arr_Size];
    for (int i = 0; i<arr_Size; i++){
        cin >> arr[i];
    }
    calculate_Candies(arr, 0, arr_Size-1);
    cout << candies << endl;
    return 0;
}
