#include<iostream>
using namespace std; 

//to calculate Discrete Logarithm problem
int compute(int a, int m, int n)
{
	int r;
	int y = 1;

	while (m > 0)
	{
		r = m % 2;
		if (r == 1)
			y = (y*a) % n;
		a = a*a % n;

		m = m / 2;
	}

	return y;
}

int Alice(int n,int g,int x)
{
 long int A;
 A = compute(g, x, n);
 return A;
}

int Bob(int n,int g,int y)
{
 long int B;
 B = compute(g, y, n);
 return B;
}

void check(int k1, int k2)
{
	if(k1 == k2)
	{
		cout<<"\n\nValue of both keys are the same. \n";
		cout<<"Symmetric key is established using Diffie-Hellman key exchange Protocol.";
		cout<<"\nAlice and Bob can agree for further communication.";
	}
	else
	{
		cout<<"\nValue of both keys are not the same. \n";
		cout<<"Symmetric key is not able to be established using Diffie-Hellman key exchange Protocol.";
	}
}

int main()
{
 long int g,x,y,A,B,k1,k2,n;
 
 cout<<"Enter value of n & g (Large Prime Numbers) : ";
 cin>>n>>g;

 cout<<"Alice, Enter a large random integer : ";
 cin>>x;
 
 cout<<"Bob, Enter a large random integer : ";
 cin>>y;

 A=Alice(n,g,x);
 cout<<"\nAlice side value generation : "<<A;

 B=Bob(n,g,y);
 cout<<"\nBob side value generation : "<<B;

 k1=Alice(n,B,x);
 cout<<"\nSecret key of Alice : "<<k1;

 k2=Bob(n,A,y);
 cout<<"\nSecret key of Bob : "<<k2;
 
 check(k1, k2);
 return 0;
}

