#include<iostream>
using namespace std;

/*to use cout and cin, although it is not prefarable to use this method, 
 instead of std::cout and std::cin, but will work for small codes*/

void twoElementsSumK(int arr1[],int arr2[], int size1, int size2, int K)
    {

        for(int i=0;i<size1;){                                                             
		for(int j=size2-1;i<=j;){                                                    //i=0 & j=size2-1 (initialized) ; run till i<j
			if(arr1[i]+arr2[j]==K){                                              //if sum ==K
				cout<<"The elements are :"<<" "<<arr1[i]<<" "<<arr2[j]; 
				return;
			}
			else if (arr1[i]+arr2[j]<K)                                                // if sum <K increment i since array is sorted & we need higher value elements
				i=i+1;
			else
				j=j-1;                                                                //  if sum >K decrement j since array is sorted & we need lower value elements
		}
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
	int n1,n2,k;
	cout<<"Enter the size of the first array: ";
	cin>>n1;
	int arr1[n1];
	cout<<"Enter the elements of first array: ";
	for(int i=0;i<n1;i++)
	{
		cin>>arr1[i];
	}
	
	cout<<"Enter the size of the second array: ";
	cin>>n2;
	int arr2[n2];
	cout<<"Enter the elements of second array: ";
	for(int i=0;i<n2;i++)
	{
		cin>>arr2[i];
	}
	
	cout<<"Enter the sum of two element to search: ";
	cin>>k;
	
	Merge_Sort(arr1,0,(n1-1));                             // to sort first array
	Merge_Sort(arr2,0,(n2-1));                             // to sort first array
	
	twoElementsSumK(arr1,arr2,n1,n2,k);
	return 0;
}

/*
Worst complexity: O(nlog n)
Average complexity: O(nlog n)
Best complexity: O(nlogn)
Space complexity: O(n*n)
Data structure: Array
Class: Search algorithm and Sorting algorithm
*/
