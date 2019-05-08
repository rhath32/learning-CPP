#include <iostream>

void leftShiftElements(int arr[], int N, int M);

int main()
{
    int arr[] {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14};
    int size = sizeof(arr)/sizeof(arr[0]);
    leftShiftElements(arr, size, 1256);

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i]; std::cout << ((i == size - 1) ? "" : ",");
    }
    std::cout << "]";
    return 0;
}

/**
* FUNCTION SIGNATURE: void leftShiftElements(int arr[], int N, int M)
 * PURPOSE: Shift all elements of an array(integer) to left M times
 * PARAMETER:
 *     int arr[], array created in main()
 *     int N, size of array
 *     int M, number of times to shift elements
 * RETURN VALUE:
 *     none, this function modifies the contents of the array passed to it
*/
void leftShiftElements(int arr[], int N, int M)
{
    // performs shift M times
    for (int j = 0; j < M; j++)
    {
        // shifts all elements to the left 1 time
        int temp = arr[0];
        for (int i = 0; i < N; i++) 
            arr[i] = arr[i + 1]; 
        arr[N - 1] = temp; 
    }
}

/* --SAMPLE OUTPUT--
INPUT: arr[] {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14}, 1256 times
OUTPUT: [11,12,13,14,1,2,3,4,5,6,7,8,9,10]
*/
