/**************************************
Template created by Kazumi Slott
CS311

Your name: Jorge Ezequiel Garcia Lopez
Your programmer number: 08
Any difficulties?:
**************************************/

#include <iostream>
using namespace std;

void swap(int& data1, int& data2)
{
  int temp = data1;
  data1 = data2;
  data2 = temp;
}

void print(const int ar[], int n)
{
  for(int i = 0; i < n; i++)
    cout << ar[i] << " ";
}

void insertionSort(int ar[], int n)
{
  //https://www.youtube.com/watch?v=ROalU379l3U
  //Implement the insertion sort by watching the above youTube video. Your algorithm has to match their dance.
  //call swap
  /*
   * Checks every element
   * Check Right element
   *    swap if right is < left
   * check left element
   *    swap until swapped value is < left value
   */
    for (int i = 1; i < n; i++) // checks right elements
    {
        /*
        int right = ar[i];
        int left = ar[i-1];
        */
        int rightIndex = i;
        int leftIndex = i-1;

        /*
        int right = ar[rightIndex];
        int left = ar[leftIndex];
         */

        while (ar[rightIndex] < ar[leftIndex]) // checks left elements
        {
            swap(ar[rightIndex], ar[leftIndex]);
            rightIndex--;
            leftIndex--;
        }
    }
}

void selectionSort(int array[], int N)
{
  //Implement selection sort by moving the smallest element to the beginning.
  //call swap

  //You can find more information in my homework document

  /**
   * find smallest
   * check if right is smaller than left
   *    set smallest
   * if smallest then swap
   * move to next element in unsorted elements
   */
   int smallest = -1;
   int smallestIndex = smallest;
    for (int i = 0; i < N; i++)
    {
        int j;
        for (j = i+1; j < N; j++)
        {
            int right = array[j];
            int left = array[i];
            if (right < left)
            {
                smallest = right;
                smallestIndex = j;
                swap(array[i], array[smallestIndex]);
                continue;
            }
        }
    }
}

//Implemented by Kazumi Slott
//ar is an integer array of any size
//s is the size of the array
//For more info, read my CS211 lec notes "Lec notes 2-2: bubble sort"
//You could also watch my CS211 lecture recording "Lecture 2/5(Fri) - bubble sort and enum" 
void bubbleSort(int ar[], int s)
{
  bool done = false; //set to false if there was swapping meaning not done yet.                                   
  int last = s - 2; //last is the index of the left element in the last pair to be checked. In the first step, last should point to the second to last.                                                                            
  while(!done) //swapping required in the previous iteration or the first iteration starts                        
    {
      done = true; //no swapping has happened yet when a new step starts.                                         

      for(int i = 0; i <= last; i++) //check each adjacent pair of items in the unsorted part                     
        {
	  if(ar[i] < ar[i + 1]) //the pair is out of order                                                          
	    {
	      swap(ar[i], ar[i+1]);
	      done = false; //swapping required. needs to proceed to the next iteration.                            
	    }
        }
      last--; //the area to be checked shrinks down after each iteration                                         
    }//end of while                                                                                               
}

/**
 * This function divides an array into segments that will be used to
 * swap elements in order to organize them using a pivot value
 * @param ar the array to be organized/ segmented
 * @param start the index where the segmenting will start
 * @param end the index where the segmenting will end
 * @return returns the index at which the pivot went in.
 */
int partition(int ar[], int start, int end)
{

    //I have 3 variables: pivot, i and swap_index. You may have any local variables.
    int pivot = ar[end];
    //cout << "pivot: " << pivot << endl;
    int i = start; // green
    int swap_index = start; // red

    //For implementation of this function, refer to my lecture notes "quick sort".
    //If you used a different implementation, I would assume you cheated and give you zero points.

    //green traverses the partition from start to the index right before pivot
    for (;  i <= end - 1;  i++)
    {
        // red points to the element that will be swapped with a value less than the pivot value.
        // Red points to the first value that is greater than pivot value.


        /* Check the current element at green.
         * If it is less than the pivot value, swap it with the value at red.
         * Then move red to the next slot.
         */

        if (ar[i] <= pivot)
        {
            // Swap elements at red and green then move red to the next slot.
            swap(ar[swap_index], ar[i]);
            //printAr(ar, 9);
            // Notice red now points to the first value that is greater than the pivot value (elements to the left of red are less than pivot value).
            // The next element that is less than pivot value will be swapped with the value at red.
            swap_index++;
        }



        //printAr(ar, 9);
    }

    swap(ar[swap_index], ar[end]);


    //This function returns the index where the pivot value went in.
    return swap_index;

}

/**
 * This function uses Tony Hoare's sorting algorithm quicksort to
 * sort an array from least to greatest.
 * It works by using a pivot value.
 * Every element to the left is less than the pivot value
 * and every element to the right is greater than the pivot value.
 * @param ar the array which will be sorted
 * @param start the index where the array is to be sorted
 * @param end the index of the last element in the array
 */
void quickSort(int ar[], int start, int end)
{
    if( (end - start) >= 2 || (start < end)) //If the partition has only one element or none, return.
        //In other words, if the partition has at least 2 elements, go inside the if.
        //use start and end to figure out.
    {
        //call partition.
        int parti = partition(ar, start, end);
        //quickSort on the left partition
        int leftPartition = parti - 1;
        int rightPartition = parti + 1;
        quickSort(ar, start, leftPartition);
        //quickSort on the right partition
        quickSort(ar, rightPartition, end);
    }
}

/**
 * This function sorts halves of an array in order to
 * sort the entire array. This function uses the algorithm
 * created by Jon von Neumann.
 * @param ar the array to be sorted
 * @param first the initial element in the array
 * @param last the final element in the array
 */
void merge(int ar[], int first, int last)
{
    //For implementation of this function, refer to my lecture notes "merge sort"
    //If you are using a different technique, I assume you cheated and will give you zero points.
    /*
    int sizeFirst = first;
    int sizeLast = last;
     */

    int left = first;
    int middle = (first + last) / 2;
    int right = middle + 1;

    /*
  int arrFirstElement = ar[first];
  int arrLastElement = ar[last];
     */

    //int mergedArraySize = last + 1;
    int mergedArraySize = (last - first) + 1;
    //make temp array dynamically with the exact number of slots you need
    int* mergedArray = new int[mergedArraySize];

    /*
     * [1, 4, 6, 8, 10, 3, 5, 2, 22]
     *
     * GOAL: SORT halved array before merging
     *  5  6  7   8
     * [3, 5, 2, 22]
     * temp[][][][]
     *
     *  left = 5  // ar[left]
     *  right = 7 // ar[right]
     *
     *  if (ar[left] > ar[right])
     *  {
     *    temp[i] = ar[right];
     *  }
     *  else
     *  {
     *    temp[i] = ar[left];
     *   }
     *
     */

    int mergedArrayOpenPosition = 0;
    while (left <= middle && right <= last) // left and right must be within bounds
    {
        /*
        if (ar[left] < ar[right])
        {
            mergedArray[mergedArrayOpenPosition] = ar[left];
            left++;
        }
        else
        {
            mergedArray[mergedArrayOpenPosition] = ar[right];
            right++;
        }
         */
        if (ar[left] > ar[right])
        {
            mergedArray[mergedArrayOpenPosition] = ar[right];
            right++;
        }
        else
        {
            mergedArray[mergedArrayOpenPosition] = ar[left];
            left++;
        }
        mergedArrayOpenPosition++;
    }


    //printAr(mergedArray, mergedArraySize);

    // once bounds are broken "Copy the remainder of elements from the right array" or left.

    while (left <= middle)
    {
        mergedArray[mergedArrayOpenPosition] = ar[left];
        left++;
        mergedArrayOpenPosition++;
    }

    while (right <= last)
    {
        mergedArray[mergedArrayOpenPosition] = ar[right];
        right++;
        mergedArrayOpenPosition++;
    }


    //load the content of temp to array
    for (int i  = 0; i < mergedArraySize; i++)
    {
        //ar[i] = mergedArray[i];
        ar[first + i] = mergedArray[i];
    }

    //Don't forget to destroy temp array, which is created dynamically
    delete[] mergedArray;
}

/**
 * This function uses Jon von Neumann's algorithm mergesort to
 * sort an array.
 * @param ar the array to be sorted
 * @param first the initial element in the array
 * @param last  the final element in the array
 */
void mergeSort(int ar[], int first, int last)
{
    //For implementation of this function, refer to my lecture notes "merge sort"
    //if there are at least 2 elements
    if (first < last)
    {
        int middle = (first + last)/2;
        //int mid = ar[middle];
        mergeSort(ar, first, middle);
        mergeSort(ar, middle + 1, last);
        merge(ar, first, last);
    }
    //if there is only one element, return to the caller immediately.
}


