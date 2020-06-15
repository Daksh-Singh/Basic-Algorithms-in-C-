#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
/*to use cout and cin, although it is not prefarable to use this method, 
 instead of std::cout and std::cin, but will work for small codes*/

struct Item                                                                   // Structure for an item which stores weight and corresponding 
{ 
    int value, weight;                                                        // value of Item  and wieghts 
}; 
  
bool cmp(struct Item a, struct Item b)                                        // Comparison function to sort Item according to val/weight ratio 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 
  
double fractionalKnapsack(int W, struct Item arr[], int n)                    // Main greedy function to solve problem 
{  
    sort(arr, arr + n, cmp);                                                  //    sorting Item on basis of ratio
  
    for (int i = 0; i < n; i++) 
    {                                                                         //   to see new order of Items with their ratio 
        cout << arr[i].value << "  " << arr[i].weight << " : " 
             << ((double)arr[i].value / arr[i].weight) << endl; 
    } 
  
    int curWeight = 0;                                                        // Current weight in knapsack 
    double finalvalue = 0.0;                                                  // Result (value in Knapsack) 
  
    for (int i = 0; i < n; i++)                                               // Looping through all Items 
    { 
         if (curWeight + arr[i].weight <= W)                                  // If adding Item won't overflow, add it completely
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        else                                                                  // If we can't add current Item, add fractional part of it 
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
   return finalvalue;                                                         // Returning final value 
} 

int main()
{
	int n,W;
	cout<<"Enter the weight of Knapsack: ";
	cin>>W;
	cout<<"Enter the number of elements: ";
	cin>>n;
	Item arr[n];
	cout<<"Enter the values and their respective weights: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].value;
		cin>>arr[i].weight;
	}

	cout << "Maximum value in Knapsack = "<< fractionalKnapsack(W, arr, n); 
    return 0; 
}

/*
Time complexity: O(nW) where n is the number of items and W is the capacity of the knapsack
Space complexity: O(1)
Data structure: Structure and Array
Class: Dynamic Programming
*/
