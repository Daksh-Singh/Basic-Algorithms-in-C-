#include<iostream>
#include<string.h>
 
using namespace std;
 
//Encrpytion Function
string encrypt(string text, int key){
    int len = text.length(), i, j, row = 0, col = 0, r =0;
    //to calculate number of rows
    if(len%key == 0)
    	r = len/key;
    else 
		r = len/key + 1;
    char columnar[r][key];
    char reverse[key][r];
 
    for(i = 0; i < r; ++i)
        for(j = 0; j < key; j++)
            columnar[i][j] = '-';
        
    for(i = 0; i < len; i++){
        columnar[row][col++] = text[i];
 
        if(col == key)
        {
        	row++;
        	col = 0;
		} 
 
    }
	//reversing the matrix to send it column wise
	for (i = 0; i < key; i++) 
        for (j = 0; j < r; j++) 
            reverse[i][j] = columnar[j][i];
        
 	string cipher;
    for(i = 0; i < key; i++)
        for(j = 0; j < r; j++)
            //if(reverse[i][j] != '-')
            cipher.push_back(reverse[i][j]);
    return cipher;
}

//Decryption Function
string decrypt(string text, int key){
    int len = text.length(), i, j, row = 0, col = 0, r =0;
    //to calculate number of columns
    if(len%key == 0)
    	r = len/key;
    else 
		r = len/key + 1;
    char columnar[key][r];
    char reverse[r][key];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < r; j++)
            columnar[i][j] = '-';
        
    for(i = 0; i < len; i++){
        columnar[row][col++] = text[i];
 
        if(col == r)
        {
        	row++;
        	col = 0;
		} 
 
    }
    //reversing the matrix to send it column wise
	for (i = 0; i < r; i++) 
        for (j = 0; j < key; j++) 
            reverse[i][j] = columnar[j][i];
        
 	string plain;
    for(i = 0; i < r; i++)
        for(j = 0; j < key; j++)
            if(reverse[i][j] != '-')
                plain.push_back(reverse[i][j]);
    return plain;
}

int main() 
{ 
	string Plain_text;
	int key;
	cout<<"Enter the plain Text: ";
	getline(cin,Plain_text);
	cout << "Enter the Key value (Column value): ";
	cin>>key;
	string En = encrypt(Plain_text, key); 
	string De = decrypt(En, key);
	cout<<"\nPlain Text: "<< Plain_text;
	cout<<"\nEncrypted Text(Cipher text): " << En;
	cout<<"\nDecrypted Text(Decrypted Plain text): " << De;  
    return 0; 
} 
