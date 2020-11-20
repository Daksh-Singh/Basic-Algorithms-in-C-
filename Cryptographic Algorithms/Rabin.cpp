#include <iostream> 
#include <string>
#include<math.h>
using namespace std; 

//to check if multiplicative inverse is possible or not
int gcd(int x , int y)
{
	if(y == 0)
		return x;
	else
		return gcd(y, x % y);	
} 
	
//Multiplicative inverse of the key
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
int CRT(int a1, int a2, int m1, int m2) 
{ 
    // Compute product of all numbers 
    int M = m1 * m2;
    int x = 0; 
    
    int p1, p2;
    p1 = M / m1;
    p2 = M / m2;
    
    x = (a1 * p1 * mul_inv(p1, m1)) + (a2 * p2 * mul_inv(p2, m2));
  
    return x % M; 
} 

void Decryption(long int a[], long int m[], int n)
{
	long int d[4];
	d[0] = CRT(a[0], a[2], m[0], m[2]);
	d[1] = CRT(a[0], a[3], m[0], m[3]);
	d[2] = CRT(a[1], a[2], m[1], m[2]);
	d[3] = CRT(a[1], a[3], m[1], m[3]);
	cout<<"All the possible Plain texts are : ";
	for(int i = 0;i < 4;i++)
	{
		cout<<"\nPlain text "<<i+1<<" : "<<d[i];
	}
}

int main() 
{ 
	long int n, p, q, P, C, x, y;
	long double a1, a2;
	long int a[4], m[4];
	cout<<"Enter the value of p and q in the form of 4k+3 : ";
	cin>>p>>q;
	n = p*q;
	cout<<"Public key is : "<<n;
	cout<<"\nPrivate key pair is : ("<<p<<", "<<q<<")";
	P = p;
	while(gcd(P, n) != 1)
	{
		cout<<"\nEnter the Plain text from Z*n : ";
		cin>>P;
	}
	C = (P * P) % n;
	x = (p + 1) / 4;
	y = (q + 1) / 4;
	
	m[0] = m[1] = p;
	m[2] = m[3] = q;
	
	a1 = pow(C, x);
	a1 = fmod(a1, p);
	a[0] = a1;
	a[1] = -a1;
	
	a2 = pow(C, y);
	a2 = fmod(a2, q);
	a[2] = a2;
	a[3] = -a2;
	
	for(int i = 0;i < 4; i++)
	{
		cout<<"Equation "<<i+1<<" is : "<<a[i]<<" mod "<<m[i]<<"\n";
	}
	a[1] = p + a[1];
	a[3] = q + a[3];
	
	Decryption(a, m, 4);
	return 0;
} 
