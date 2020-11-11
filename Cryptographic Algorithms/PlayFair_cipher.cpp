#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
const char key[5][5]={{'A','B','C','D','E'},
                      {'F','G','H','I','K'},
                      {'L','M','N','O','P'},
                      {'Q','R','S','T','U'},
                      {'V','W','X','Y','Z'}};

void pos(char p, int& row, int& col)
{
    if (p < 'J')
    {
        row = (p - 65) / 5;
        col = (p - 65) % 5;
    }
    else if (p > 'J')
    {
        row = (p - 66) / 5;
        col = (p - 66) % 5;
    }
    return;
}
 
//Functions for the pos of various character of all three cases 
void same_row_e(int row, vector<char>& msg, int col1, int col2)
{
    msg.push_back(key[row][(col1 + 1) % 5]);
    msg.push_back(key[row][(col2 + 1) % 5]);
    return;
}
 
void same_column_e(int col, vector<char>& msg, int row1, int row2)
{
    msg.push_back(key[(row1 + 1) % 5][col]);
    msg.push_back(key[(row2 + 1) % 5][col]);
    return;
}
 
void diff_col_row(int row1, int col1, vector<char>& msg, int row2, int col2)
{
    msg.push_back(key[row1][col2]);
    msg.push_back(key[row2][col1]);
    return;
}

void same_row_d(int row, vector<char>& msg, int col1, int col2)
{
    msg.push_back(key[row][(col1 + 4) % 5]);
    msg.push_back(key[row][(col2 + 4) % 5]);
    return;
}
 
void same_column_d(int col, vector<char>& msg, int row1, int row2)
{
    msg.push_back(key[(row1 + 4) % 5][col]);
    msg.push_back(key[(row2 + 4) % 5][col]);
    return;
}
 
//Encryption Function
vector<char> encrypt(vector<char> text)
{
	int len = text.size();
    vector<char> cipher;
    int i = 0, j = 0;
    int row1, col1, row2, col2;
    while (i < len)
    {
        pos(text[i], row1, col1);
        i++;
        pos(text[i], row2, col2);
        if (row1 == row2)
        {
            same_row_e(row1, cipher, col1, col2);
        }
        else if (col1 == col2)
        {
            same_column_e(col1, cipher, row1, row2);
        }
        else
        {
            diff_col_row(row1, col1, cipher, row2, col2);
        }
        i++;
    }
    cout << "\nEncrypted Text(Cipher text): ";
    for (j = 0;j < cipher.size();j++)
    {
        cout<<cipher[j];
    }
    return cipher;
}

//Decryption Function
void decrypt(vector<char> text, int bogus)
{
	int x = bogus + 1;
	int len = text.size();
    vector<char> plain;
    int i = 0, j = 0;
    int row1, col1, row2, col2;
    while (i < len)
    {
        pos(text[i], row1, col1);
        i++;
        pos(text[i], row2, col2);
        if (row1 == row2)
        {
            same_row_d(row1, plain, col1, col2);
        }
        else if (col1 == col2)
        {
            same_column_d(col1, plain, row1, row2);
        }
        else
        {
            diff_col_row(row1, col1, plain, row2, col2);
        }
        i++;
    }
    cout<<"\nDeciphered Text: ";
    for (j = 0;j < plain.size();j++)
    {
        cout<<plain.at(j);
    }
    cout << "\nDecrypted Text(Decrypted Plain text): " ;
    for(int i = 0; i< plain.size(); i++)
    {
    	if((plain[i] == 'X') && (plain[i+1] != 'X'))
    		{
    			if(x > 0)
    			{
					plain.erase(plain.begin() + i);
					x--;
				}	
				i++;
			}	
	}
	if((plain[plain.size()-1] == 'X') && (plain[plain.size()-2] != 'X'))
   		plain.erase(plain.begin()+(plain.size()-1));
   	
    for (j = 0;j < plain.size();j++)
    {
    	if(plain.at(j)==' ')
    		j++;
    	else
        	cout<<plain.at(j);
    }
} 

//Converting all 'J' to 'I' in plain text
void input(vector<char>& Plain_text)
{
    char c;
    while (1)
    {
        c = getchar();
        if (c >= 97 && c <= 122)
        c-=32;
        if (c == '\n')
            break;
        //Skipping the whitespaces 
        else if (c==' ')
            continue;
        else if (c == 'J')
        	Plain_text.push_back('I');
        else
        	Plain_text.push_back(c);
    }
    return;
}
 
//Setting up the bogus character in the plain text
int setup(vector<char>& Plain_text, vector<char>& text)
{
    int i = 0, j = 0, count = 0;
    while (i < Plain_text.size())
    {
        text.push_back(Plain_text[i]);
        i++;
        if (i == Plain_text.size())
        {
            text.push_back('X');
            break;
        }
        if (Plain_text[i] == text[j])
        {
        	count+=1;
        	//Adding bogus character as 'X" if two characters are same
            text.push_back('X');
            j++;
        }
        else if(Plain_text[i] != text[j])
        {
            j++;
            text.push_back(Plain_text[i]);
            i+= 1;
        }
        j++;
    }
    cout<<"\nSetup Plain Text: ";
    for(int i=0; i<text.size();i++)
    	cout<<text[i];
    return count;
}
 
int main()
{
    vector<char> Plain_text;
    vector<char> text;
    vector<char> en;
    int i, j, count = 0;
    cout << "Enter the plain Text: ";
    input(Plain_text);
    cout<<"\nPlain Text: ";
    for(int i=0; i<Plain_text.size();i++)
    	cout<<Plain_text[i];
    cout<<"\nkey Matrix is: \n";
    for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<key[i][j]<<"|";
		}	
		cout<<"\n";			
	}
    count = setup(Plain_text, text);
    en = encrypt(text);
    decrypt(en, count);
 
    return 0;
}
