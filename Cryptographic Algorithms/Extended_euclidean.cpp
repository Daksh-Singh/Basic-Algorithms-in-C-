#include <iostream> 
#include <string>
using namespace std; 

//to check if multiplicative inverse is possible or not
int gcd(int x , int y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);	
} 
	
//Multiplicative inverse of the key
int mul_inv(int a, int b)
{
	int r,r1,r2,t,t1,t2,q=0;
	r1=b, r2=a, t1=0, t2=1;
	while(r2>0)
	{
		q=r1/r2;
		r=r1-(q*r2);
		r1=r2;
		r2=r;
		t=t1-(q*t2);
		t1=t2;
		t2=t;	
	}
	if(r1==1)
	{
		if(t1<0)
			return r1+t1;
		else
			return t1;
	}
		
}

int main() 
{ 
	int num, num_inv, modulo;
	cout << "Enter the number: ";
	cin>>num;
	cout<<"Enter the modulo";
	cin>>modulo;
	if(gcd(num,modulo)==1){
		num_inv=mul_inv(num,modulo);
		cout << "\nNumber is " << num;
		cout << "\nMultiplicative inverse of "<<num<<" mod "<<modulo<<" is: " << num_inv; 
		return 0;
	}
	else
		cout<<"Sorry the Multiplicative inverse of the key cannot be calculated";
	return 0;
} 
