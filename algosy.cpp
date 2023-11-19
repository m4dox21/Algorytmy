#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <algorithm>

#include <fstream>
#include <chrono>

using namespace std;


struct Legitymacje
{
    int l; //   id
    int w; //   punkty

    bool operator<(const Legitymacje &a) const
    {
        return w < a.w;
    }

};

// timsort
const int RUN = 4194304; 
void insertionSort(Legitymacje array[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        Legitymacje temp = array[i];
        int j = i - 1;
        while(j>= left && array[j].w > temp.w)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void merge(Legitymacje array[], int l, int m, int r)
{
    int len1 = m - l + 1;
    int len2 = r - m + 1;
    Legitymacje left[len1]; 
    Legitymacje right[len2];

    for(int i = 0; i < len1; i++)
    {
        left[i] = array[l+i];
    }
    for(int i = 0; i < len2; i++)
    {
        right[i] = array[m + 1 + i];
    }

    int i=0;
    int j=0;
    int k=0;


    while(i < len1 && j < len2)
    {
        if(left[i].l <= right[j].l)
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
    k++;
}

    while(i < len1)
    {
        array[k] = left[i];
        k++;
        i++;
    }

    while (j < len2)
    {
        array[k] = right[j];
        k++;
        j++;
    }
}

void timSort(Legitymacje array[], int n)
{
    for(int i = 0; i < n; i += RUN)
    {
        insertionSort(array, i, min((i + RUN - 1), (n - 1)));
    }

    for (int size = RUN; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            if ( mid < right)
            {
                merge(array, left, mid, right);
            }
        }
    }
}

// Introsort
void swapValue(Legitymacje &a, Legitymacje &b) 
{ 
    Legitymacje temp = a; 
    a = b; 
    b = temp; 
    return;
}

void InsertionSort(Legitymacje array[], int begin, int end)
{
    for (int i = begin + 1; i <= end; i++)
    {
        Legitymacje key = array[i];
        int j = i - 1;

        while( j >= begin && array[j].w > key.w)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    return;
}

int Partition(Legitymacje array[], int low, int high)
{
    int pivot = array[high].w;
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {
        if(array[j].w <= pivot)
        {
            i++;
            swapValue(array[i], array[j]);
        }
    }
    swapValue(array[i + 1], array[high]);
    return(i + 1);
}

int medianOfThree(Legitymacje &a, Legitymacje &b, Legitymacje &c)
{
    if (a.w < b.w && b.w < c.w)
    {
        return 1;
    }
    if (a.w < c.w && c.w <= b.w)
    {
        return 2;
    }
    if (b.w <= a.w && a.w < c.w)
    {
        return 0;
    }
    if (b.w < c.w && c.w <= a.w)
    {
        return 2;
    }
    if (c.w <= a.w && a.w < b.w)
    {
        return 0;
    }
    if (c.w <= b.w && b.w <= a.w)
    {
        return 1;
    }
}

void IntrosortUtil(Legitymacje array[], int begin, int end, int depthLimit)
{
    int size = end - begin;

    if (size < 16)
    {
        InsertionSort(array, begin, end);
        return;
    }

    if (depthLimit == 0)
    {
        make_heap(array + begin, array + end + 1);
        sort_heap(array + begin, array + end + 1);
        return;
    }

    int pivotIndex = medianOfThree(array[begin], array[begin + size / 2], array[end]);
    swapValue(array[pivotIndex + begin], array[end]);

    int partitionPoint = Partition(array, begin, end);
    IntrosortUtil(array, begin, partitionPoint - 1, depthLimit - 1);
    IntrosortUtil(array, partitionPoint + 1, end, depthLimit - 1);

    return;
}

void Introsort(Legitymacje array[], int begin, int end)
{
    int depthLimit = 2 * log(end - begin);
    IntrosortUtil(array, begin, end, depthLimit);
    return;
}

// counting sort
void countSort(Legitymacje inputArray[], int size, Legitymacje outputArray[])
{
    int M = 0;

    for (int i = 0; i < size; i++)
        M = std::max(M, inputArray[i].w);

    int countArray[M + 1] = {0};

    for (int i = 0; i < size; i++)
        countArray[inputArray[i].w]++;

    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        outputArray[countArray[inputArray[i].w] - 1] = inputArray[i];
        countArray[inputArray[i].w]--;
    }
    // for (int i = 0; i < size; i++)
    // {
    //     cout << outputArray[i].w << " ";
    // }
}

void wypisz(Legitymacje array[], int n, int c)
{
    for(int j=0;j<n;j++)
    {
        if(c == 0)
        {
            cout<<array[j].l<<" ";
        }
        else if(c == 1)
        {
            cout<<array[j].w<<" ";
        }
    }
}


int main()
{   
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n, p, k, c;
    // n - rozmiar tablicy
    // p - dolna granica w
    // k - górna granica w
    // c - opcja
    cin>>n>>p>>k>>c;
    Legitymacje Legitymacja[n]; 
    Legitymacje outLegitymacja[n];
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    if (n >= 1 && n <= 3000000 )
    {
        if(p >= 0 && p <= k && k <= 1000000)
        {
            {
                for(int i=0;i<n;i++)
                {
                    Legitymacja[i].l =  rand() % 2000 + 1000;
                    Legitymacja[i].w =  rand() % (k - p + 1) + p;
                }

                if(n > 1000 && n <=5000)
                {
                    Introsort(Legitymacja, 0, n); 
                }
                else if(n>5000)
                {
                    countSort(Legitymacja, n, outLegitymacja);
                }
                else if (n <= 1000 )
                {
                    timSort(Legitymacja, n);
                }
            }
        }
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    ofstream myfile;
    myfile.open ("timSort.txt", std::ios::app);
    myfile << "\n"<< std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()<< std::endl;
    myfile.close();
    std::cout << "\nTime difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    return 0;
}
