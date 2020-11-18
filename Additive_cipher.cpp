#include <iostream> 
#include <string>
using namespace std; 

//Encryption Function
string encrypt(string text, int k) 
{ 
	string cipher = ""; 

	for (int i=0;i<text.length();i++) 
	{ 

		if (isupper(text[i])) 
			cipher += char(int(text[i]-65+k)%26 +65);
		//Keeping White spaces as same 
		else if(isspace(text[i]))
			cipher += text[i];

		else if(islower(text[i]))
		cipher += char(int(text[i]-97+k)%26 +97); 
	} 
	return cipher; 
} 

//Decryption Function
string decrypt(string text, int k) 
{ 
	string plain = ""; 
	k = 26-(k%26);
	//Additive inverse of the key

	for (int i=0;i<text.length();i++) 
	{ 
		if (isupper(text[i])) 
			plain += char(int(text[i]-65+k)%26 +65); 
		//Keeping White spaces as same 
		else if(isspace(text[i]))
			plain += text[i];
			
		else if(islower(text[i]))
			plain += char(int(text[i]-97+k)%26 +97); 
	} 
	return plain; 
} 

int main() 
{ 
	string Plain_text; 
	int key; 
	cout << "Enter the plain Text: ";
	getline(cin,Plain_text); 
	cout << "Enter the Key value: ";
	cin>>key;
	string En = encrypt(Plain_text, key); 
	string De = decrypt(En, key);
	cout<<"\nPlain Text: "<< Plain_text;
	cout << "\nEncrypted Text(Cipher text): " << En;
	cout << "\nDecrypted Text(Decrypted Plain text): " << De; 
	return 0; 
} 

