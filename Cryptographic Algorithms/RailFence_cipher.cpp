#include <bits/stdc++.h> 
using namespace std; 
  
//Encryption Function
string encrypt(string text, int key) 
{  
	int len = text.length();
    char rail[key][len]; 
  
    for (int i=0; i < key; i++) 
        for (int j = 0; j < len; j++) 
            rail[i][j] = '\n'; 
  
    bool dir = false; 
    int row = 0, col = 0; 
  
    for (int i=0; i < text.length(); i++) 
    { 
        if (row == 0 || row == key-1) 
            dir = !dir; 
  
        rail[row][col++] = text[i]; 
  
        dir?row++ : row--; 
    } 
  
    string cipher; 
    for (int i=0; i < key; i++) 
        for (int j=0; j < len; j++) 
            if (rail[i][j]!='\n') 
                cipher.push_back(rail[i][j]); 
  
    return cipher; 
} 

//Decryption Function
string decrypt(string text, int key) 
{ 
	
    int len = text.length();
    char fence[key][len];  
  
    for (int i=0; i < key; i++) 
        for (int j=0; j < len; j++) 
            fence[i][j] = '\n'; 
  
    bool dir; 
    int row = 0, col = 0; 
  
    for (int i=0; i < len; i++) 
    { 
        if (row == 0) 
            dir = true; 
        if (row == key-1) 
            dir = false; 
  
        fence[row][col++] = '*'; 
        dir?row++ : row--; 
    } 
  
    int index = 0; 
    for (int i=0; i<key; i++) 
        for (int j=0; j<len; j++) 
            if (fence[i][j] == '*' && len) 
                fence[i][j] = text[index++]; 
  
    string plain; 
  
    row = 0, col = 0; 
    for (int i=0; i< len; i++) 
    { 
        if (row == 0) 
            dir = true; 
        if (row == key-1) 
            dir = false; 
   
        if (fence[row][col] != '*') 
            plain.push_back(fence[row][col++]); 
  
        dir?row++: row--; 
    } 
    return plain; 
} 
  
int main() 
{ 
	string Plain_text;
	int key = 2;
	cout << "Enter the plain Text: ";
	getline(cin,Plain_text);
	string En = encrypt(Plain_text, key); 
	string De = decrypt(En, key);
 	cout<<"\nPlain Text: "<< Plain_text;
	cout << "\nEncrypted Text(Cipher text): " << En;
	cout << "\nDecrypted Text(Decrypted Plain text): " << De;  
    return 0; 
} 
