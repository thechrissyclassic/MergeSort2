
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

void merge(int array[], int const left,
    int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays. These will store the elements during the sort. 
    //Merge sort will continue to divide this
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] 
    // and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    // Initial index of first sub-array
    // Initial index of second sub-array
    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;

    // Initial index of merged array
    int indexOfMergedArray = left;

    // Merge the temp arrays back into 
    // array[left..right]
    while (indexOfSubArrayOne < subArrayOne &&
        indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <=
            rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] =
                leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] =
                rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] =
            leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] =
            rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[],
    int const begin,
    int const end)
{
    // Returns recursively
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    int arr[100000]; //created the array. For this assignment, I will be changing the amount a couple of times. This amount will also change on lines
    //108 & 110
    auto arr_size = sizeof(arr) / sizeof(arr[0]); // this will calculate the size of the array 
    clock_t start, end; //setting up the clock and giving it its start and end functions. Will use it once the array starts to print and will end once it stops.

    for (int i = 0; i < 100000; i++)
    {
        arr[i] = rand() % 100000;
    }

    printArray(arr, arr_size); // is not calling the printArray :(
    start = clock(); //start clock as soon as the program starts to run

    mergeSort(arr, 0, arr_size - 1); //merge sort not being called. In our example in class, we created the bubble sort and called it "B". It was listed as "bubbleSort b;.
    end = clock(); //stops running
    printArray(arr, arr_size);

    cout << "merge sort time (MS) = " << (end - start) << endl;
    //line 121 will display the time it took to run.

    return 0;

}