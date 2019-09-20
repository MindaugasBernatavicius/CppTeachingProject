//
// Created by bernam on 9/17/2019.
//

#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size);

int main(int argc, char **argv) {
    int arr [5] = {10, 1, 2, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);

    for(unsigned int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void bubbleSort(int arr[], int size){
    for(unsigned int i = 0; i < size; i++){
        bool sorted = true;
        for(unsigned int j = 0; j < size-i-1; j++) {
            if (arr[j] < arr[j + 1]) {
                sorted = false;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if(sorted)
            break;
    }
}