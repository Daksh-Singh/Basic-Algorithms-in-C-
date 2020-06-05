#include<iostream>
using namespace std;

/*to use cout and cin, although it is not prefarable to use this method, 
 instead of std::cout and std::cin, but will work for small codes*/

void twoElementsSumK(int arr[], int size, int K)
    {

    int lowIndex = 0;                                                                //maintain the low and high index
    int highIndex = size-1;
 
    while(lowIndex < highIndex)
    {
        int temp = arr[lowIndex] + arr[highIndex];                                   //get the sum
 
        if(temp == K)                                                                //return if we find a match
        {
            cout<<"The elements are :"<<arr[lowIndex]<<" "<<arr[highIndex];
            return;
        }
 
        if(temp < K)                                                                  //to change the low and high index according to the sum lower or higher than temp
            lowIndex++;
        else
            highIndex--;
    }
}
 
//Will use Quick Sort to sort the elements of both the array in n*log(n) 
//function to swap two elements of array using a temporary variable
void swap(int* a, int* b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
  

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];                                // taking last element as pivot  
    int i = (low - 1);                                    // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {                                                       
        if (arr[j] < pivot)                               // If current element is smaller than the pivot
        {  
            i++;                                          // increment index of smaller element  
            swap(&arr[i], &arr[j]);                       //swap the element according to that all smaller than pivot element will be to lefy of pivot and all greater element will be to right of pivot
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  					  //swapping the pivot to correct position
    return (i + 1);                                       //returns the partitioning index
}  
  

void Quick_Sort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
    
        int pi = partition(arr, low, high);               //to get the partition index

        Quick_Sort(arr, low, pi - 1);                      //left array from partioned point to sort
        Quick_Sort(arr, pi + 1, high);                     //right array from partioned point to sort
    }  
}  

int main()
{
	int n,k,pos=0,flag=0;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"Enter the sum of two element to search: ";
	cin>>k;
	
	Quick_Sort(arr,0,(n-1));                             //first to sort the array
	
	twoElementsSumK(arr,n,k);
	return 0;
}

/*
Worst complexity: O(nlog n)
Average complexity: O(nlog n)
Best complexity: O(nlogn)
Space complexity: O(n)
Data structure: Array
Class: Search algorithm and Sorting algorithm
*/
