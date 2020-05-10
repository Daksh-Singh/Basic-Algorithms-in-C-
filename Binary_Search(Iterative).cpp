#include<iostream>
/*using std::cout and std:: cin for output and input, instead of using namespace std*/

int main()
{
	int n,key,pos=0,mid=0;
	std::cout<<"Enter the number of elements in array: ";
	std::cin>>n;
	int arr[n];
	std::cout<<"Enter the elements of array in increasing order: ";
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];
	}
	std::cout<<"Enter the element to search: ";
	std::cin>>key;
    int low=0,high=n-1;                  //so that start will not be modified, have to use it in end to print the postion of searched element
    while(low<=high)
    {
    	mid=(low+high-1)/2;
    	if(arr[mid]==key)                //to check if the key is present at middle of the array
    	{
    		pos=mid;
    		break;
		}
		else if(arr[mid]>key)            //whether the key is smaller the middle element of array or not
		{
			high=mid-1;                  //if smaller than middle element of array,then changing high to mid-1
		}
		else low=mid+1;                  //if larger than middle element of array, then changing low to mid+1
		pos=-1;                          //if element not found, then returning -1
	}
	
	if(pos==-1)                          //to check whether the element is found or not, and if found at what position respective to array
	{
		std::cout<<"Element is not found in array";
	}
	else
		std::cout<<"Element is found at postion: "<<(pos+1)<<" and at index: "<<pos;
	
	return 0;
}


/*
Worst complexity: O(log n)
Average complexity: O(log n)
Best complexity: O(1)
Space complexity: O(1)
Data structure: Array
Class: Search algorithm
*/
