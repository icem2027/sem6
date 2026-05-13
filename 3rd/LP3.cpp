/*
    HEADER FILE

    iostream means Input Output Stream

    Used for:
    cout -> print output
    cin  -> take input
*/
#include <iostream>



/*
    using namespace std

    So we can directly use:
    cout
    cin

    instead of:
    std::cout
    std::cin
*/
using namespace std;



/*
    Selection Sort Function

    arr[] -> array to sort

    n -> size of array
*/
void selectionSort(int arr[], int n)
{

    /*
        OUTER LOOP

        Controls number of passes

        n-1 because last element
        automatically becomes sorted
    */
    for (int i = 0; i < n - 1; i++)
    {

        /*
            Assume current index
            contains minimum element

            min stores INDEX
            not value
        */
        int min = i;



        /*
            INNER LOOP

            Used to find smallest element
            in remaining unsorted array

            Starts from i+1 because
            left side is already sorted
        */
        for (int j = i + 1; j < n; j++)
        {

            /*
                Compare current element
                with minimum element
            */
            if (arr[j] < arr[min])
            {

                /*
                    If smaller element found

                    Update minimum index
                */
                min = j;
            }
        }



        /*
            SWAPPING SECTION

            Swap current element
            with smallest element
        */



        /*
            Store arr[i]
            temporarily
        */
        int temp = arr[i];



        /*
            Put smallest element
            at correct position
        */
        arr[i] = arr[min];



        /*
            Put old value
            into minimum position
        */
        arr[min] = temp;
    }
}



/*
    MAIN FUNCTION

    Program execution starts here
*/
int main()
{

    /*
        Create integer array

        Unsorted array
    */
    int arr[] = {64, 25, 12, 22, 11};



    /*
        Find size of array

        sizeof(arr)
        gives total bytes

        sizeof(arr[0])
        gives size of one element

        Formula:

        total bytes / one element bytes
    */
    int n = sizeof(arr) / sizeof(arr[0]);



    /*
        Call selection sort function
    */
    selectionSort(arr, n);



    /*
        Print heading
    */
    cout << "Sorted Array: ";



    /*
        LOOP to print sorted array
    */
    for (int i = 0; i < n; i++)
    {

        /*
            Print each element
        */
        cout << arr[i] << " ";
    }



    /*
        return 0 means
        program executed successfully
    */
    return 0;
}