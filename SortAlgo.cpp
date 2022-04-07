#include "SortAlgo.h"
#include <stdio.h>
#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void SortAlgo::load(string fileName) {
    array.clear();
    //makes sure that array is clear before loading

    ifstream file;
    file.open(fileName);
    //opens file and stores it in ifstream object

    if(!file){
        cout << "Could not load " << fileName << endl;
        return;
    }  //prints error statement if file can't be loaded in

    else if (file){
        int value;
        while(file >> value){
            //pushes values to vector
            array.push_back(value);
        }  //loop through input file and extract values
    }

    file.close();
    //close file
}

void SortAlgo::execute() {
    std::chrono::high_resolution_clock::time_point time1, time2;
    //creates two variables which store time

    if(selection == 0){
        time1 = std::chrono::high_resolution_clock::now();
        algo = "Bubble Sort";
        bubbleSort(array, int(array.size()));
        time2 = std::chrono::high_resolution_clock::now();
    } //executes bubble sort

    else if (selection == 1){
        time1 = std::chrono::high_resolution_clock::now();
        algo = "Merge Sort";
        mergeSort(array, 0, array.size() - 1);
        time2 = std::chrono::high_resolution_clock::now();
    }  //executes merge sort

    else if (selection == 2){
        time1 = std::chrono::high_resolution_clock::now();
        algo = "Insertion Sort";
        insertionSort(array,array.size());
        time2 = std::chrono::high_resolution_clock::now();
    }  //executes insertion sort

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(time2 - time1);
    time = time_span.count();
}

void SortAlgo::display() {
    cout << endl;
    //ensures printed info starts on a new line

    cout << "----- Sorted Set: -----" << endl;
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << endl;
    }  //loops through array and prints elements
    cout << "-----------------------" << endl;
    cout << endl;
}

void SortAlgo::stats() {
    cout << endl;
    //ensures printed info starts on a new line

    cout << "------ Searching Statistics: ------" << endl;
    cout << "Algorithm used: " << algo << endl;
    cout << "Records analyzed: " << array.size() << endl;
    cout << "Runtime: " << time << endl;
    cout << "-----------------------------------" << endl;
    //prints stats
}

void SortAlgo::select(int x) {
    selection = x;
    //selects which algo to use
}

void SortAlgo::save() {
    ofstream file;
    file.open("output.txt");
    //opens output file

    for (int i = 0; i < array.size(); i++) {
        file << array[i];
    }  //prints vector to output file

    file.close();
    //closes file
}

void SortAlgo::configure() {
    //implementation will be added later
    //allows for future expandability
}

void SortAlgo::bubbleSort(vector<int>& arr, int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++) {
        swapped = false;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}  //GeeksForGeeks source code used as an example

void SortAlgo::swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}  //GeeksForGeeks source code used as an example

void SortAlgo::mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}  //GeeksForGeeks source code used as an example

void SortAlgo::merge(vector<int> arr, int l, int m, int r)  {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}  //GeeksForGeeks source code used as an example

void SortAlgo::insertionSort(vector<int>& arr, int n) {
    int i, j;
    int key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}   //GeeksForGeeks source code used as an example