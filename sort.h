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

int partition(int a[], int start, int end)
{
  //copy and paste partition() from your quickSort.cpp
}

void quickSort(int ar[], int start, int end)
{
  //copy and paste quickSort() from your quickSort.cpp   
}

void merge(int ar[], int first, int last)
{
  //copy and paste merge() from your mergeSort.cpp   
}

void mergeSort(int ar[], int first, int last)

{
  //copy and paste mergeSort()from your mergeSort.cpp   
}


