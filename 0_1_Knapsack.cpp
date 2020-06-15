#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
/*to use cout and cin, although it is not prefarable to use this method, 
 instead of std::cout and std::cin, but will work for small codes*/
 
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

int KnapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
   
    for (i = 0; i <= n; i++) {                                         // Build table K[][] in bottom up manner
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max( 
                    val[i - 1] + K[i - 1][w - wt[i - 1]], 
                    K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W];                                                     //Returns the maximum value that 
} 

int main()
{
	int n,W;
	cout<<"Enter the weight of Knapsack: ";
	cin>>W;
	cout<<"Enter the number of elements: ";
	cin>>n;
	int val[n],wt[n];
	cout<<"Enter the values and their respective weights: ";
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
		cin>>wt[i];
	}

	cout << "Maximum value in Knapsack = "<< KnapSack(W, wt, val, n); 
    return 0; 
}

/*
Time complexity: O(nW) where n is the number of items and W is the capacity of the knapsack
Space complexity: O(1)
Data structure: Array
Class: Dynamic Programming
*/

