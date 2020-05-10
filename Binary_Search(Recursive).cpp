#include<iostream>
using namespace std;
/*to use cout and cin, although it is not prefarable to use this method, 
 instead of std::cout and std::cin, but will work for small codes*/

int Binary_Search(int arr[],int low,int high,int key)
//User defined function to search the key using binary search recursive method 
{
	if(low<=high)
	{
		int mid=(low+high-1)/2;
		if(arr[mid]==key)                                 //to check if the key is present at middle of the array
		{
			return mid;
		}
		else if(arr[mid]>key)                             //whether the key is smaller the middle element of array or not
		{
			return Binary_Search(arr,low,mid-1,key);      //if smaller than middle element of array,then changing high to mid-1
		} 
		else
		{
			return Binary_Search(arr,mid+1,high,key);     //if larger than middle element of array, then changing low to mid+1
		}
	}
    return -1;                                            //if element not found, then returning -1
	
}
int main()
{
	int n,key,pos=0;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array in increasing order: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"Enter the element to search: ";
	cin>>key;
	
	pos=Binary_Search(arr,0,(n-1),key);
	if(pos==-1)                                           //to check whether the element is found or not, and if found at what position respective to array
	{
		cout<<"Element is not found in array";
	}
	else
	cout<<"Element is found at postion: "<<(pos+1)<<" and at index: "<<pos;
	return 0;
}

/*
Worst complexity: O(log n)
Average complexity: O(log n)
Best complexity: O(1)
Space complexity: O(n)
Data structure: Array
Class: Search algorithm
*/
