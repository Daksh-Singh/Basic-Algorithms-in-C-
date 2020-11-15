#include <bits/stdc++.h> 
using namespace std; 

vector<string> roundkey; 

int shift_table[16] = { 1, 1, 2, 2, 
                        2, 2, 2, 2, 
                        1, 2, 2, 2, 
                        2, 2, 2, 1 }; 
  
int pbox_table[48] = {14, 17, 11, 24, 1, 5, 3, 28, 
					 15, 6, 21, 10, 23, 19, 12, 4, 
					 26, 8, 16, 7, 27, 20, 13, 2, 
					 41, 52, 31, 37, 47, 55, 30, 40, 
					 51, 45, 33, 48, 44, 49, 39, 56, 
					 34, 53, 46, 42, 50, 36, 29, 32 }; 
						 
string hex2bin(string key) 
{ 
    unordered_map<char, string> hexbin; 
    hexbin['0'] = "0000"; 
    hexbin['1'] = "0001"; 
    hexbin['2'] = "0010"; 
    hexbin['3'] = "0011"; 
    hexbin['4'] = "0100"; 
    hexbin['5'] = "0101"; 
    hexbin['6'] = "0110"; 
    hexbin['7'] = "0111"; 
    hexbin['8'] = "1000"; 
    hexbin['9'] = "1001"; 
    hexbin['A'] = "1010"; 
    hexbin['B'] = "1011"; 
    hexbin['C'] = "1100"; 
    hexbin['D'] = "1101"; 
    hexbin['E'] = "1110"; 
    hexbin['F'] = "1111"; 
    string binary = ""; 
    for (int i = 0; i < key.size(); i++) 
	{ 
        binary += hexbin[key[i]]; 
    } 
    return binary; 
} 
string bin2hex(string key) 
{  
    unordered_map<string, string> binhex; 
    binhex["0000"] = "0"; 
    binhex["0001"] = "1"; 
    binhex["0010"] = "2"; 
    binhex["0011"] = "3"; 
    binhex["0100"] = "4"; 
    binhex["0101"] = "5"; 
    binhex["0110"] = "6"; 
    binhex["0111"] = "7"; 
    binhex["1000"] = "8"; 
    binhex["1001"] = "9"; 
    binhex["1010"] = "A"; 
    binhex["1011"] = "B"; 
    binhex["1100"] = "C"; 
    binhex["1101"] = "D"; 
    binhex["1110"] = "E"; 
    binhex["1111"] = "F"; 
    string hex = ""; 
    for (int i = 0; i < key.length(); i += 4) 
	{ 
        string bit = ""; 
        bit += key[i]; 
        bit += key[i + 1]; 
        bit += key[i + 2]; 
        bit += key[i + 3]; 
        hex += binhex[bit]; 
    } 
    return hex; 
} 
  
string mixing(string key, int* table, int n) 
{ 
    string result = ""; 
    for (int i = 0; i < n; i++) 
	{ 
        result += key[table[i] - 1]; 
    } 
    return result; 
} 
  
string shift(string key, int shift_value) 
{ 
    string result = ""; 
    for(int i = 0; i < shift_value; i++) 
	{ 
        for (int j = 1; j < 28; j++) 
		{ 
            result += key[j]; 
        } 
        result += key[0]; 
        key = result; 
        result = ""; 
    } 
    return key; 
} 

void key_generator(string key, string first, string last)
{
    for (int i = 0; i < 16; i++) 
	{ 

        first = shift(first, shift_table[i]); 
        last = shift(last, shift_table[i]); 
  
        string round = first + last; 
  
        string rkey = mixing(round, pbox_table, 48); 

        roundkey.push_back(bin2hex(rkey)); 
    } 
}

int main() 
{ 
    string key, keyp; 
    cout<<"Enter the key(in hexadecimal): "; 
    cin>>key;

	//Conversion of key from hexadecimal to binary
    key = hex2bin(key); 
  
    int parity_table[56] = {57, 49, 41, 33, 25, 17, 9, 1,
							58, 50, 42, 34, 26, 18, 10, 2,
							59, 51, 43, 35, 27, 19, 11, 3, 
							60, 52, 44, 36, 63, 55, 47, 39, 
							31, 23, 15, 7, 62, 54, 46, 38, 
							30, 22, 14, 6, 61, 53, 45, 37, 
							29, 21, 13, 5, 28, 20, 12, 4 }; 
  
	//Parity droping and initial permutation
    keyp = mixing(key, parity_table, 56); 
    
    // Splitting the 56 bits to two 28 bits
    string first = keyp.substr(0, 28); 
    string last = keyp.substr(28, 28); 

    //16 rounds key
    key_generator(keyp, first, last);
  
	cout<<"All 16 Round keys are: \n";
	for(int i = 0; i < 16; i++)
	{
		if(i<9)
			cout<<"Round "<<(i + 1)<<" : "<<roundkey[i]<<"\n"; 
		else 
			cout<<"Round "<<(i + 1)<<": "<<roundkey[i]<<"\n";
	}
	return 0;
} 
