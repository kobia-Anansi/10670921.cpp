#include <iostream>

using namespace std;


void insertionSort(int arr[], int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = arr[i];//take value
      j = i;
      while(j > 0 && arr[j-1]>key) {
         arr[j] = arr[j-1];
         j--;
      }
      arr[j] = key;   //insert in right place
   }
}

int main(void){
    int size;
    cout << "Enter the size of the array here: ";
    cin >> size;
    int arr[size];
    
    cout << "Enter the values of the array: " <<endl;
    for(int i = 0; i<size; i++){
        cin >> arr[i];
    }

    insertionSort(arr, size);

    int maxim = arr[size-1];
    int minim = arr[0];

    cout << "Maximum number is " << maxim <<endl;
    cout << "Minimum number is " << minim <<endl;

    return 0;
    }