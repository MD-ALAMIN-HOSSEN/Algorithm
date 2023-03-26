#include <algorithm>
#include <chrono>
#include<vector>

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <fstream> 
using namespace std;
using namespace std::chrono;

  
//Function to print an array
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++)
    {
      cout << arr[i] << " "; 
      // cout << endl;
    }
} 
  
  
//Swap function
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in 
        // unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx]) 
              min_idx = j;
        }
        // Swap the found minimum element 
        // with the first element 
        if (min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
} 

// insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
  

// quick sort

  
 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 

 ////////////////////mergeSort

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
  //cout<<"\n merge";
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  
   if (l>=r)
   {
     //printArray(arr, r);
     return ;/////////////////
   }
  
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m =l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
  //printArray(arr, r);
}



// Driver program to test above functions 
int main() 
{ 
  const int n=200000;
  int arr[n];
  int array_length=0;
  string file="for10000.text";
  cout <<"give the file name :"<<endl;
  cin>>file;
 
  fstream myFile;
  
  myFile.open(file,ios::in);
  
  if (myFile.is_open())
  {
    // cout <<"file is open"<<endl;
    string line;
    while (getline(myFile,line))
    {
       //cout <<line<<endl;
      arr[array_length]=atoi(line.c_str());
      array_length+=1;
      // int y = atoi(s.c_str());  // Need to use s, not S
    }
    
  }
  //////////milliseconds
  
  ////////////////////selectionSort
   int arrselectionSort[n];
   
    std::copy_n(arr, n, arrselectionSort);
    srand(time(0));
    // Get starting timepoint
    auto start = steady_clock::now();
    selectionSort(arrselectionSort, array_length);
     auto stop = steady_clock::now();
     auto duration = duration_cast<microseconds>(stop - start)/(1000);
     cout << "Time taken by function (selectionSort):  "
         << duration.count() << " microseconds" << endl;
   // cout << "Sorted array: selectionSort \n"; 
    //printArray(arrselectionSort, array_length);
  ////////////////////selectionSort
  
   cout<<endl;
 
  //////////////////////insertionSort
    
    std::copy_n(arr, n, arrselectionSort);

     start = steady_clock::now();
     insertionSort(arrselectionSort, array_length);
      stop = steady_clock::now();
      duration = duration_cast<microseconds>(stop - start)/(1000);
     cout << "Time taken by function (insertionSort):  "
         << duration.count() << " microseconds" << endl;
    //printf("Sorted array: insertionSort \n");
    //printArray(arrselectionSort, array_length);
    
  ////////////////////insertionSort

    cout<<endl;

  ////////////////////bubbleSort
    std::copy_n(arr, n, arrselectionSort);
    start = steady_clock::now();
     bubbleSort(arrselectionSort, array_length);
     stop = steady_clock::now();
      duration = duration_cast<microseconds>(stop - start)/(1000);
     cout << "Time taken by function (bubbleSort):  "
         << duration.count() << " microseconds" << endl;
    // printf("Sorted array: bubbleSort \n");
     //printArray(arrselectionSort, array_length);
  
  ////////////////////bubbleSort

    cout<<endl;

  ////////////////////quickSort
  std::copy_n(arr, n, arrselectionSort);
  start = steady_clock::now();
     quickSort(arrselectionSort,0, array_length-1);
     stop = steady_clock::now();
      duration = duration_cast<microseconds>(stop - start)/(1000);
     cout << "Time taken by function (quickSort):  "
         << duration.count() << " microseconds" << endl;
     //printf("Sorted array: quickSort \n");
    // printArray(arrselectionSort, array_length);
     // quickSort(arr3, 0, n3 - 1);
   
  ////////////////////quickSort

    cout<<endl;
    
 
  ////////////////////mergeSort
  std::copy_n(arr, n, arrselectionSort);
  start = steady_clock::now();
  mergeSort(arrselectionSort,0, array_length-1);
  stop = steady_clock::now();
      duration = duration_cast<microseconds>(stop - start)/(1000);
     cout << "Time taken by function (mergeSort):  "
         << duration.count() << " microseconds" << endl;
   //cout << "Sorted array: mergeSort\n";
  // printArray(arrselectionSort, array_length);



  // int arr4[] = {6, 5, 12, 10, 9, 1};
  // int size4 = sizeof(arr4) / sizeof(arr4[0]);
  // mergeSort(arr4, 0, size4 - 1);
 
  ////////////////////mergeSort

 cout << "\n";
  cout << "\n";
   cout << "end\n";
   cout << "\n";
  cout << "\n";
  int q;
  //cin>>q;
    return 0; 
} 


