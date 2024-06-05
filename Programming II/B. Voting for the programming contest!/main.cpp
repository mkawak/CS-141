//
//  main.cpp
//  B. Voting for the programming contest!
//
//  Created by Majd Kawak on 10/9/22.
//

#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
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
    int departmentNum;
    int departmentNumNeeded;
    int peopleNeeded=0;
    cin >> departmentNum;
    departmentNumNeeded=(departmentNum/2)+1;
    int arr[departmentNum];
    for (int i = 0; i<departmentNum; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, departmentNum-1);
    for (int i = 0; i<departmentNumNeeded; i++){
        peopleNeeded+=(arr[i]/2)+1;
    }
    cout << peopleNeeded << endl;
    return 0;
}
