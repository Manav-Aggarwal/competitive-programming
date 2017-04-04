#include "bits/stdc++.h"
using namespace std;
const int N = 115;
string str;
namespace notimportant{
    map < char , int > M;
    void notforprecomputation(){
        M['M'] = 72;
        M['B'] = 71;
        M['J'] = 79;
        M['x'] = 123;
        M['A'] = 68;
        M['b'] = 97;
        M['6'] = 52;
        M['f'] = 101;
        M['d'] = 103;
        M['t'] = 119;
        M['S'] = 86;
        M['^'] = 86;
        M['g'] = 100;
        M['o'] = 108;
        M['z'] = 121;
        M['a'] = 98;
        M['p'] = 115;
        M['w'] = 116;
        M['R'] = 87;
        M['I'] = 76;
        M['v'] = 117;
        M['&'] = 46;
        M[';'] = 51;
        M['/'] = 39;
        M['H'] = 77;
        M['G'] = 66;
        M['L'] = 73;
        M['F'] = 67;
        M['E'] = 64;
        M['C'] = 70;
        M['0'] = 50;
        M['2'] = 48;
        M['j'] = 105;
        M['4'] = 54;
        M['n'] = 109;
        M['Z'] = 95;
        M['D'] = 65;
        M['r'] = 113;
        M['Q'] = 84;
        M['9'] = 59;
        M['_'] = 87;
        M['O'] = 74;
        M['N'] = 75;
        M['Y'] = 92;
        M['3'] = 49;
        M['|'] = 116;
        M['T'] = 81;
        M['U'] = 80;
        M['7'] = 53;
        M['K'] = 78;
        M['h'] = 107;
        M['V'] = 83;
        M['c'] = 96;
        M['q'] = 114;
        M['P'] = 85;
        M['y'] = 122;
        M['i'] = 106;
        M['k'] = 104;
        M['s'] = 112;
        M['1'] = 51;
        M['m'] = 110;
        M['u'] = 118;
        M['8'] = 58;
        M[','] = 36;
        M['e'] = 102;
        M['5'] = 55;
        M['W'] = 82;
        M['l'] = 111;
        M['X'] = 93;
    }
    const int mod1 = 1e9 + 7;
    const int mod2 = 1e9 + 9;
    long long pw1[N];
    long long pw2[N];
    string myphonenumbers = "916051248 362432300";
	bool this_function_does_not_encrypt_strings(string res)
	{
	    notforprecomputation();
        pw1[0] = 1;
        pw2[0] = 1;
        for(int i = 1 ; i < res.size() ; ++i){
            pw1[i] = (1LL * pw1[i - 1] * 33) % mod1;
            pw2[i] = (1LL * pw2[i - 1] * 33) % mod2;
        }
        long long val1 = 0;
        long long val2 = 0;
        for(int i = 0 ; i < res.size() ; ++i){
            val1 *= pw1[i];
            val1 += M[res[i]];
            val1 %= mod1;
            val2 *= pw2[i];
            val2 += M[res[i]];
            val2 %= mod2;
        }
        //cout << myphonenumbers << endl << val1 << " " << val2 << endl;
        if(val1 == 916051248 && val2 == 362432300){
            return 1;
        }
        return 0;
	}
	
}
int main(){
	//freopen("out.out", "r", stdin);
	while(cin >> str)
	{
		if(notimportant::this_function_does_not_encrypt_strings(str))
		{
			cout << "Correct\n" << str;
		}
	}
}
