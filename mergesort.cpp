#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>
using namespace std;
using namespace std::chrono;
void merge(int *,int, int , int );
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
    }
}
// Merge sort 
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}
// read input array and call mergesort
int main()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    int num[5]; int elapsed_time[5];
    for (int i = 0; i<5; i++){
        

       /* clock_t startClock,finishClock;
        double timeCount;
        startClock = clock();*/

        sleep_for(nanoseconds(100));
        sleep_until(system_clock::now() + seconds(1));

        // initialize random seed
    srand (time(NULL));

    //Generate size of array for current iteration
    int size = rand() % 20 + 1;
    num[i] = size;

    int myarray[size];
    cout <<"Number of elements generated by the random number generator is:" << size <<endl;
    
    cout <<"Generated array is: ";
    for (int i = 0; i < size; i++) {
        myarray[i] = rand() % 100 + 1;
        cout << myarray[i] << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();
    merge_sort(myarray, 0, size-1);
    auto stop = high_resolution_clock::now();

    cout<<"Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout<<myarray[i]<<" ";
    }
    cout <<endl;

    auto duration = duration_cast<microseconds>(stop - start); 

    elapsed_time[i] = duration.count();
  
    cout << "Time taken by Sorting algorithm: "
         << duration.count() << " microseconds" << endl; 
    
    /*finishClock = clock();
    timeCount = finishClock - startClock ;
    elapsed_time[i] = timeCount/100.0;*/

    cout << endl;
    cout <<endl;
    }

    // open file ''example.dat'' for writing
    filebuf buffer;
    ostream output(&buffer);
    istream input(&buffer);
    buffer.open ("example.dat", ios::in | ios::out | ios::trunc);

    for (int i=0; i<5; i++) {
        // write one line of number and time
        output << num[i] << " " << elapsed_time[i] << endl;
    }

}