#include<iostream>
#include<math.h>
 
using namespace std;
 
//Multiplicative inverse of the key
int mul_inv(long int a, long int b)
{
	long int r, r1, r2, t, t1, t2, q = 0;
	r1 = b, r2 = a, t1 = 0, t2 = 1;
	while(r2 > 0)
	{
		q = r1/r2;
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;
		t = t1 - (q*t2);
		t1 = t2;
		t2 = t;	
	}
	if(r1 == 1)
	{
		if( t1 < 0)
			return b + t1;
		else
			return t1;
	}		
}

//to find gcd
int gcd(long int a, long int b)
{
    long int temp;
    while(1)
    {
        temp = a % b;
        if(temp==0)
        	return b;
        a = b;
        b = temp;
    }
}
 
int main()
{
    long  double p, q, n, phi, e, d1, d, flag;
    cout<<"Enter the value of p and q (prime-numbers) : ";
    cin>>p>>q;
    if(gcd(p, q) == 1)
    {
    	n = p * q;
    	phi = (p-1)*(q-1);
 
    	//public key
    	cout<<"Enter the value of e (Public key) co-prime with phi: ";
    	cin>>e;
 
    	//for checking co-prime which satisfies e>1
    	//to get the public key
    	while(e < phi){
    	flag = gcd(e, phi);
    	if(flag == 1)
        	break;
    	else
        	e++;
    	}
 
    	//Finding Private key
    	d1 = mul_inv(e, phi);
    	d = fmod(d1, phi);
    	long double msg;
    	cout<<"Enter the message greater than 1 and smaller than "<<n<<" : ";
    	cin>>msg;
    	long double c = pow(msg, e);
    	c = fmod(c, n);
    	long double m = pow(c, d);
    	m = fmod(m, n);
 
    	cout<<"\n p                 | "<<p;
    	cout<<"\n q                 | "<<q;
    	cout<<"\n n = pq            | "<<n;
    	cout<<"\n Value of phi(n)   | "<<phi;
    	cout<<"\n Public Key (e)    | "<<e;
    	cout<<"\n Private Key (d)   | "<<d;
    	cout<<"\n Original message  | "<<msg;
    	cout<<"\n Encrypted data    | "<<c;
    	cout<<"\n Decrypted message | "<<m;
	}
	else
	{
		cout<<"Please enter the correct values for p and q";
	}
    
    return 0;
}
