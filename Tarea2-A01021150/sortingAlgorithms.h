#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;


void swapFunction( int& a, int& b );
void bubbleSort(int a[] , int n);
void insertionSort(int a[], int n);
void selectionSort(int a[], int n);


void swapFunction( int& a, int& b )
{
    int t = a;
   	a = b; b = t;
}

void bubbleSort(int a[] , int n)
{
    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (a[j-1] > a[j])
            {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
}


// FROM http://rosettacode.org/wiki/Sorting_algorithms/Cocktail_sort#C.2B.2B
void cocktailSort(int a[] , int n)
{
    bool notSorted = true;
    while( notSorted )
    {
        notSorted = false;
        for( int i = 0; i < n - 1; i++ )
        {
            if( a[i] > a[i + 1] )
            {
                swapFunction( a[i], a[i + 1] );
                notSorted = true;
            }
        }

        if( !notSorted ) break;
        notSorted = false;

        for( int i = n - 1; i > 0; i-- )
        {
            if( a[i - 1] > a[i] )
            {
                swapFunction( a[i], a[i - 1] );
                notSorted = true;
            }
        }
    }
}

void insertionSort(int a[], int n)
{
    int index;

    for (int i=1; i < n; i++)
    {
        index = a[i];

        int j = i-1;

        while (j >= 0 && a[j] > index)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j+1] = index;
    }
}

// FROM http://forums.anandtech.com/showthread.php?t=508716
void bucketSort(int a[], int n)
{
    int k, j = 0;

    map<int, int> buckets;

    for(k=0; k<n; k++)
    {
        buckets[a[k]]++;
    }

    map<int, int>::iterator it = buckets.begin( );
    while(it != buckets.end( ))
    {
        for(k=0; k<it->second; k++)
            a[j++] = it->first;
        it++;
    }
}

// FROM http://rosettacode.org/wiki/Sorting_algorithms/Counting_sort#C.2B.2B
void countingSort(int a[], int n)
{
    int mi, mx, z = 0;
    mi = n; mx = 0;
    int rnd;
    for( int i = 0; i < n; i++ )
    {
        if( a[i] > mx ) mx = a[i];
        if( a[i] < mi ) mi = a[i];
    }

    int nlen = ( mx - mi ) + 1;
    int* temp = new int[nlen];
    memset(temp, 0, nlen * sizeof( int ) );

    for( int i = 0; i < n; i++ )
    {
        rnd = a[i] -mi;
        temp[rnd]++;
    }

    for( int i = mi; i <= mx; i++ )
    {
        while( temp[i - mi] )
        {
            a[z++] = i;
            temp[i - mi]--;
        }
    }

    delete [] temp;
}

void merge(int a[], int l, int m, int n, int N)
{
    int i, j, k, tmp;
    int * aux = new int[N];

    for(i = m+1; i>l; i--)
    {
        tmp = a[i-1];
        aux[i-1] = tmp;
    }

    for (j=m; j<n; j++)
    {
        tmp = a[j+1];
        aux[n+m-j] = tmp;
    }

    for(k=l;k<=n;k++)
    {
        if (aux[i] < aux[j])
        {
            tmp = aux[i++];
            a[k] = tmp;
        }
        else
        {
            tmp = aux[j--];
            a[k] = tmp;
        }
    }
}

void mergeSort(int a[], int l, int n, int N)
{
    int m = (n+l)/2;
    if (n > l)
    {
        mergeSort (a, l, m, N);
        mergeSort (a, m+1, n, N);
        merge (a, l, m, n, N);
    }
}

void mergeSort(int a[], int n)
{
  mergeSort(a, 0, n-1, n);
}

//FROM http://www.geeksforgeeks.org/radix-sort/
void radixSort(int a[], int n)
{
    // Find the maximum number to know number of digits
    int mx = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > mx)
        {
            mx = a[i];
        }
    }

    int m = mx;

    for (int exp = 1; m/exp > 0; exp *= 10)
    {
        vector<int> output(n);
        int i;
        int count[10] = {0};


        for (i = 0; i < n; i++)
            count[ (a[i]/exp)%10 ]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--)
        {
            output[count[ (a[i]/exp)%10 ] - 1] = a[i];
            count[ (a[i]/exp)%10 ]--;
        }

        for (i = 0; i < n; i++)
            a[i] = output[i];
    }
}

void shellSort(int a[], int n)

{

    int gap, i, j, temp;



    for (gap = n/2; gap > 0; gap /= 2)

        for (i = gap; i < n; i++)

            for (j=i-gap; j>=0 && a[j]>a[j+gap]; j-=gap) {

                temp = a[j];

                a[j] = a[j+gap];

                a[j+gap] = temp;

            }

}

int partition (int a[], int lo, int hi)
{
    int pivot = a[hi];    // pivot
    int index = (lo - 1);  // Index of smaller element

    for (int j = lo; j <= hi - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (a[j] <= pivot)
        {
            index++;    // increment index of smaller element
            swap(a[index], a[j]);  // Swap current element with index
        }
    }
    swap(a[index + 1], a[hi]);
    return (index + 1);
}

void quickSort(int a[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = partition(a, lo, hi); /* Partitioning index */
        quickSort(a, lo, p - 1);
        quickSort(a, p + 1, hi);
    }
}

// Heap Sort FROM http://www.bogotobogo.com/Algorithms/heapsort.php
void siftDown(int numbers[], int root, int bottom)
{
    int done, maxChild, temp;

    done = 0;
    while ((root*2 <= bottom) && (!done))
    {
        if (root*2 == bottom)
            maxChild = root * 2;
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;

        if (numbers[root] < numbers[maxChild])
        {
            temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    for (i = (n / 2)-1; i >= 0; i--)
        siftDown(a, i, n);

    for (i = n - 1; i >= 1; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        siftDown(a, 0, i-1);
    }
}
void selectionSort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int temp;
        int minimum = i;
        for(int j = i + 1; j < n; j++)
        {
            if (a[minimum] > a[j])
                minimum = j;
        }
        temp = a[minimum];
        a[minimum] = a[i];
        a[i] = temp;
    }
}

