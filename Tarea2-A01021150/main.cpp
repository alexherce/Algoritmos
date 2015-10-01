#include <iostream>
#include <ctime>
#include <cstdlib>
#include "sortingAlgorithms.h"
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;
using namespace std::chrono;

void generateNumbers(int n)
{
    int rndGen;

    ofstream myfile;

    if( remove( "numberArray.txt" ) != 0 )
    perror( "Error deleting file!" );
        else
    puts( "Previous file successfully deleted!" );

    myfile.open ("numberArray.txt");
    srand (time(NULL));
    for (int i = 0; i < n + 1; i++)
    {
        rndGen = 0;
        // De acuerdo con lo investigado, rand solo puede tener numeros hasta el 32,767.
        // Este for genera numeros del 0 al millon usando varias llamadas a rand (31 en total).
        for(int i = 0; i<20 ; i++)
        {
            rndGen += rand();
        }
        myfile << rndGen << endl;
    }
    myfile.close();
}

void copyArray(int a[], int n)
{
    string line;
    int value;
    int i = 0;
    ifstream myfile ("numberArray.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            value = atoi(line.c_str());
            a[i] = value;
            i++;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void saveTimes(int a[])
{

     ofstream myfile;

    if( remove( "resultsFile.txt" ) != 0 )
    perror( "Error deleting file!" );
        else
    puts( "Previous file successfully deleted!" );

    myfile.open ("resultsFile.txt");

    myfile << "-------------- RESULTS --------------" << endl;
    myfile << "1.- Bubble Sort ------------------- " << a[0] << " micros | " << a[0]/1000 << "ms | " << a[0]/1000000 << "s" << endl;
    myfile << "2.- Cocktail Sort ------------------ " << a[1] << " micros | " << a[1]/1000 << "ms | " << a[1]/1000000 << "s" << endl;
    myfile << "3.- Insertion Sort ----------------- " << a[2] << " micros | " << a[2]/1000 << "ms | " << a[2]/1000000 << "s" << endl;
    myfile << "4.- Bucket Sort ------------------- " << a[3] << " micros | " << a[3]/1000 << "ms | " << a[3]/1000000 << "s" << endl;
    myfile << "5.- Counting Sort ----------------- " << a[4] << " micros | " << a[4]/1000 << "ms | " << a[4]/1000000 << "s" << endl;
    myfile << "6.- Merge Sort -------------------- " << a[5] << " micros | " << a[5]/1000 << "ms | " << a[5]/1000000 << "s" << endl;
    myfile << "7.- Binary Tree Sort --------------- " << a[6] << " micros | " << a[6]/1000 << "ms | " << a[6]/1000000 << "s" << endl;
    myfile << "8.- Radix Sort --------------------- " << a[7] << " micros | " << a[7]/1000 << "ms | " << a[7]/1000000 << "s" << endl;
    myfile << "9.- Shell Sort --------------------- " << a[8] << " micros | " << a[8]/1000 << "ms | " << a[8]/1000000 << "s" << endl;
    myfile << "10.- Selection Sort ---------------- " << a[9] << " micros | " << a[9]/1000 << "ms | " << a[9]/1000000 << "s" << endl;
    myfile << "11.- Heap Sort -------------------- " << a[10] << " micros | " << a[10]/1000 << "ms | " << a[10]/1000000 << "s" << endl;
    myfile << "12.- Quick Sort ------------------- " << a[11] << " micros | " << a[11]/1000 << "ms | " << a[11]/1000000 << "s" << endl;
    myfile << endl << endl;

    myfile.close();
}

void displayTimes(int a[])
{
    cout << endl << endl;
    cout << "-------------- RESULTS --------------" << endl;
    cout << "1.- Bubble Sort ------------------- " << a[0] << " micros | " << a[0]/1000 << "ms | " << a[0]/1000000 << "s" << endl;
    cout << "2.- Cocktail Sort ------------------ " << a[1] << " micros | " << a[1]/1000 << "ms | " << a[1]/1000000 << "s" << endl;
    cout << "3.- Insertion Sort ----------------- " << a[2] << " micros | " << a[2]/1000 << "ms | " << a[2]/1000000 << "s" << endl;
    cout << "4.- Bucket Sort ------------------- " << a[3] << " micros | " << a[3]/1000 << "ms | " << a[3]/1000000 << "s" << endl;
    cout << "5.- Counting Sort ----------------- " << a[4] << " micros | " << a[4]/1000 << "ms | " << a[4]/1000000 << "s" << endl;
    cout << "6.- Merge Sort -------------------- " << a[5] << " micros | " << a[5]/1000 << "ms | " << a[5]/1000000 << "s" << endl;
    cout << "7.- Binary Tree Sort --------------- " << a[6] << " micros | " << a[6]/1000 << "ms | " << a[6]/1000000 << "s" << endl;
    cout << "8.- Radix Sort --------------------- " << a[7] << " micros | " << a[7]/1000 << "ms | " << a[7]/1000000 << "s" << endl;
    cout << "9.- Shell Sort --------------------- " << a[8] << " micros | " << a[8]/1000 << "ms | " << a[8]/1000000 << "s" << endl;
    cout << "10.- Selection Sort ---------------- " << a[9] << " micros | " << a[9]/1000 << "ms | " << a[9]/1000000 << "s" << endl;
    cout << "11.- Heap Sort -------------------- " << a[10] << " micros | " << a[10]/1000 << "ms | " << a[10]/1000000 << "s" << endl;
    cout << "12.- Quick Sort ------------------- " << a[11] << " micros | " << a[11]/1000 << "ms | " << a[11]/1000000 << "s" << endl;
    cout << endl << endl;
}


int main()
{
    cout << "This program will use 12 sorting methods to sort the same N number array." << endl;
    cout << "For each method, time will be taken from the start of the sorting to the end of the sorting." << endl;
    cout << "Times for each method will be desplayed at the end of all sorting methods." << endl;
    cout << endl;


    int ammount;
    int timesArray[12];

    cout << "Enter the ammount of numbers to sort:" << endl;
    cin >> ammount;

    int* temporalArray = new int[ammount];

    cout << "Generating " << ammount << " numbers... ";

    generateNumbers(ammount);

    cout << "Done!" << endl << endl;

     high_resolution_clock::time_point t1;
     high_resolution_clock::time_point t2;

    // Total time
    high_resolution_clock::time_point tot1 = high_resolution_clock::now();

    // BEGIN Bubble Sort
    cout << "1/12: Sorting with Bubble Sort... " << endl;

    copyArray(temporalArray, ammount);

    t1 = high_resolution_clock::now();
    bubbleSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[0] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

    // END Bubble Sort

    // BEGIN Cocktail Sort
    copyArray(temporalArray, ammount);

    cout << "2/12: Sorting with Cocktail Sort... " << endl;

    t1 = high_resolution_clock::now();
    cocktailSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[1] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

    // END Cocktail Sort

    // BEGIN Insertion Sort
    copyArray(temporalArray, ammount);

    cout << "3/12: Sorting with Insertion Sort... " << endl;

    t1 = high_resolution_clock::now();
    insertionSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[2] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

    // END Insertion Sort

    // BEGIN Bucket Sort

    copyArray(temporalArray, ammount);

    cout << "4/12: Sorting with Bucket Sort... " << endl;

    t1 = high_resolution_clock::now();
    bucketSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[3] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

    // END Bucket Sort

    // BEGIN Counting Sort
    copyArray(temporalArray, ammount);

    cout << "5/12: Sorting with Counting Sort... " << endl;

    t1 = high_resolution_clock::now();
    countingSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[4] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

    // END Counting Sort

    // BEGIN Merge Sort
    copyArray(temporalArray, ammount);

    cout << "6/12: Sorting with Merge Sort... " << endl;

    t1 = high_resolution_clock::now();
    mergeSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[5] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

    // END Merge Sort

    // BEGIN Binary Tree Sort

    // END Binary Tree Sort

    // BEGIN Radix Sort
    copyArray(temporalArray, ammount);

    cout << "8/12: Sorting with Radix Sort... " << endl;

    t1 = high_resolution_clock::now();
    radixSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[7] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

    // END Radix Sort

    // BEGIN Shell Sort

    copyArray(temporalArray, ammount);

    cout << "9/12: Sorting with Shell Sort... " << endl;

    t1 = high_resolution_clock::now();
    shellSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[8] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

    // END Shell Sort

    // BEGIN Selection Sort
    copyArray(temporalArray, ammount);

    cout << "10/12: Sorting with Selection Sort... " << endl;

    t1 = high_resolution_clock::now();
    selectionSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[9] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

    // END Selection Sort

    // BEGIN Heap Sort

    copyArray(temporalArray, ammount);

    cout << "11/12: Sorting with Heap Sort... " << endl;

    t1 = high_resolution_clock::now();
    heapSort(temporalArray, ammount);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[10] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;


    // END Heap Sort

    // BEGIN Quick Sort
    copyArray(temporalArray, ammount);

    cout << "12/12: Sorting with Quick Sort... " << endl;

    t1 = high_resolution_clock::now();
    quickSort(temporalArray, 0, ammount-1);
    t2 = high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    timesArray[11] = duration;

    cout << "Done in " << duration << " microseconds!" << endl;

//     END Quick Sort

    displayTimes(timesArray);
    saveTimes(timesArray);

    // Total Time
    high_resolution_clock::time_point tot2 = high_resolution_clock::now();

    auto totalDuration = std::chrono::duration_cast<std::chrono::seconds>( tot2 - tot1 ).count();

    cout << "Time executing: " << totalDuration << " seconds."<< endl;

    return 0;
}
