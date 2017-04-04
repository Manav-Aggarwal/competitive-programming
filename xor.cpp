/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
 
int main() {
 
    string message;
    ifstream cipher("crypto_4.txt");
	stringstream buffer;
	buffer << cipher.rdbuf();
	message = buffer.str();
    string key;
	key = "xorcipher\n";
	int k = 9, i = 0;
    while(i < message.length())
    {
    	message[i] ^= key[k];
    	k++;
    	k %= key.length();
    	i++;
	}
	cout << message;   
	cout << endl << k;
	return 0;
}
