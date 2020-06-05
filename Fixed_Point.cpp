#include<iostream>
using namespace std;
/*to use cout and cin, although it is not prefarable to use this method, 
 instead of std::cout and std::cin, but will work for small codes*/
 
 int Fixed_Point_Search(int arr[],int low,int high)
//User defined function to search the Fixed point using binary search recursive method with a little modification
{
	if(low<=high)
	{
		int mid=(low+high-1)/2;
		if(arr[mid]==mid)                                 //to check if the mid element of array is eqaul to middle of index
		{
			return mid;
		}
		else if(arr[mid]>mid)                             //whether the mid element of array is smaller the its index or not
		{
			return Fixed_Point_Search(arr,low,mid-1);          //if smaller than middle element of array,then changing high to mid-1, since then the fixed point will be at first half of array
		} 
		else
		{
			return Fixed_Point_Search(arr,mid+1,high);         //if larger than middle element of array, then changing low to mid+1, since then fixed point will be at last half of array
		}
	}
    return -1;                                            //if fixed point is not found, then returning -1
	
}

 int main()
{
	int n,flag=0;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array in increasing sorted order: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	flag=Fixed_Point_Search(arr,0,(n-1));
	if(flag==-1)                                           //to check whether the fixed point is found or not, and if found at what position respective to array
	{
		cout<<"No Fixed point is found";
	}
	else
	cout<<"Fixed point is found at postion: "<<(flag+1)<<" and at index: "<<flag;
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
