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
 
//Will use Merge Sort to sort the elements of the array in n*log(n) 

void Merge(int arr[],int low,int high,int mid)
{
	int i,j,k=0;
	int n1=mid-low+1;
	int n2=high-mid;
	int larr[n1],rarr[n2];                  //Dividing the array into two half array
	for(i=0;i<n1;i++)                       //so that to combine them back in sorted order
	{                                      
		larr[i]=arr[low+i];
	}
	for(j=0;j<n2;j++)
	{
		rarr[j]=arr[mid+1+j];
	}
	i=0,j=0,k=low;
	while(i<n1 && j<n2)
	{
		if(larr[i]<=rarr[j])                //to check which array has smaller element than other array
		{
			arr[k]=larr[i];
			i++;
		}
		else
		{
			arr[k]=rarr[j];
			j++;
		}        
		k++;                                 //increasing k here since at one time only one elemnt will be inserted in merged sorted array  
	}
	while(i<n1)                              //if element of left array is still remaining
	{                                        //thus, they are guranteed to be largest and sorted
		arr[k]=larr[i];                      //thus, we can directly add them to the sorted merged array
		k++;
		i++;
	}
	while(j<n2)                              //if element of Right array is still remaining
	{                                        //thus, they are guranteed to be largest and sorted
		arr[k]=rarr[j];                      //thus, we can directly add them to the sorted merged array
		k++;
		j++;
	}	
}

void Merge_Sort(int arr[],int low,int high)
{
	if(low<high)                             //to divide the array as small as having only two elements
	{
		int mid=(low+high-1)/2;              //calculating the mid
		Merge_Sort(arr,low,mid);             //Sorting the left half of array
		Merge_Sort(arr,mid+1,high);          //Sorting the right half of array
		Merge(arr,low,high,mid);             //Merging the both halves of sorted array into one
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
	
	Merge_Sort(arr,0,(n-1));                             //first to sort the array
	
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
