#include<iostream>
#include<string.h>
 
using namespace std;
int count = 0; 

//Encrpytion Function
string encrypt(string text, int key_arr[], int key){
    int i = 0, j = 0, len = text.size();
    string cipher;
    for(i = 0; i < len;)
    {
    	if(isspace(text[i]))
    	{
    		//keeping space as it is
    		cipher.push_back(text[i]);
    		i++;
		}	
    	else
    	{
    		//To change the word position according to input key array
    		for(j = 0; j < key; j++)
    		{
    			cipher.push_back(text[i + key_arr[j]]);
			}
			i += key;
		}
	}
	return cipher;
    
}

//Decryption Function
string decrypt(string text, int key_arr[], int key){
    int i = 0, j = 0, len = text.size();
    char cipher[len];
    for(i = 0; i < len;)
    {
    	if(isspace(text[i]))
    	{
    		//keeping space as it is
    		cipher[i] = text[i];
    		i++;
		}	
    	else
    	{
			//To change the word position according to input key array
    		for(j = 0; j < key; j++)
    		{
    			cipher[i + key_arr[j]] = text[i + j];
			}
			i += key;
		}
	}
	string plain(cipher);
	return plain;
    
}

//Setup function
string setup(string text, int key)
{
	string result, plain;
	int i = 0, k = 0, len = text.size();
	for(i = 0; i < len; i++)
	{
		if(isspace(text[i]))
			continue;
		else
			result += toupper(text[i]);
	}
	plain += result[0];
	//dividing the text in groups of key characters
	for(i = 1; i < result.length(); i++)
	{
		if(i%key == 0)
		{
			plain += " ";
			plain += result[i];
		}	
		else 
			plain += result[i];
	}
	if(i%key != 0)
	{
		//adding bogus character 'X'
		k = key - (i%key);
		count = k;
		for(i = 0; i < k; i++)
			plain += "X";
	}
	return plain;
}
int main() 
{ 
	string Plain_text, text;
	int key;
	cout<<"Enter the plain Text: ";
	getline(cin,Plain_text);
	cout<<"Enter the Key value: ";
	cin>>key;
	int key_arr[key];
	cout<<"Enter the value of the key permutation(1 to key): \n";
	for(int i = 0; i<key; i++)
	{
		cin>>key_arr[i];
		key_arr[i] -= 1;
	}
	text = setup(Plain_text, key);
	string En = encrypt(text, key_arr, key); 
	string De = decrypt(En, key_arr, key);
	cout<<"\nPlain Text: "<< Plain_text;
	cout<<"\nSetup Text: "<<text;
	cout<<"\nEncrypted Text(Cipher text): " << En;
	cout<<"\nDeciphered Text: " << De;
	int i = count;
	//removing the bogus character
	while(i > 0)
	{
		De.pop_back();
		i--;	
	}
	cout<<"\nDecrypted Text(Decrypted Plain text): " << De;   
    return 0; 
} 
