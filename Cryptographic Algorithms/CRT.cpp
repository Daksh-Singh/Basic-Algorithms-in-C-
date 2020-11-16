#include <iostream> 
#include <string>
using namespace std; 

//to check if multiplicative inverse is possible or not
int gcd(int x , int y)
{
	if(y == 0)
		return x;
	else
		return gcd(y, x % y);	
} 
	
//Multiplicative inverse using Extended Euclidean algorithm
int mul_inv(int a, int b)
{
	int r, r1, r2, t, t1, t2, q = 0;
	r1 = b, r2 = a, t1 = 0, t2 = 1;
	while(r2 > 0)
	{
		q = r1/r2;
		r = r1- (q * r2);
		r1 = r2;
		r2 = r;
		t = t1 - (q * t2);
		t1 = t2;
		t2 = t;	
	}
	if(r1 == 1)
	{
		if(t1 < 0)
			return b + t1;
		else
			return t1;
	}		
}

//CRT result calculation
int CRT(int a[], int m[], int n) 
{ 
    // Compute product of all numbers 
    int M = 1; 
    for (int i = 0; i < n; i++) 
        M *= m[i]; 
  
    int x = 0; 
    //Caclulating Mul inv and multiplying them
    for (int i = 0; i < n; i++) 
    { 
        int p = M / m[i]; 
        x += a[i] * p * mul_inv(p, m[i]); 
    } 
  
    return x % M; 
} 

int main() 
{ 
	int n;
	cout<<"Enter the number of equations to calculate : ";
	cin>>n;
	int a[n], m[n];
	cout<<"Enter the equations in the form of a mod m (All values of m relatively prime)\n";
	for(int i = 0;i < n; i++)
	{
		cout<<"Enter the value of a"<<i+1<<" : ";
		cin>>a[i];
		cout<<"Enter the value of m"<<i+1<<" : ";
		cin>>m[i];
	}
	cout<<"\n";
	for(int i = 0;i < n; i++)
	{
		cout<<"Equation "<<i+1<<" is : X = "<<a[i]<<" mod "<<m[i]<<"\n";
	}
	cout<<"\nThe Value of X(Solution of equations) is : "<<CRT(a, m, n);
	return 0;
} 
