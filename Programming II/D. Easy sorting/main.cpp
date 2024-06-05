//
//  main.cpp
//  D. Easy sorting
//
//  Created by Majd Kawak on 10/10/22.
//

#include <iostream>
using namespace std;
double swaps_Num = 0;
void merge(int arr[], int start, int mid, int end)
{
    int arr_Size = end - start;
    int *temp = new int [arr_Size];
    for ( int i = 0; i<arr_Size; i++){
        temp[i] = arr[i];
    }
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
    double swaps=0;
    for ( int i = 0; i <arr_Size; i++){
        if(temp[i] != arr[i]){
            swaps++;
        }
    }
    swaps_Num+=swaps/2;
    delete[] temp;
    delete[] leftArr;
    delete[] rightArr;
}
void mergeSort(int arr[], int start, int end){
    if (start >= end){
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
int main(int argc, const char * argv[]) {
    int arrSize;
    cin >> arrSize;
    int arr[arrSize];
    int arrSorted[arrSize];
    for (int i = 0; i < arrSize; i++){
        cin >>arr[i];
        arrSorted[i] = arr[i];
    }
    mergeSort(arrSorted, 0, arrSize-1);
    double mods = swaps_Num;
        if((mods/2)>=1){
            cout << mods/2;
        }
        else{
            cout << 0;
        }
    return 0;
}
