#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool str[100001];
string s;
long long int v1[100001][2];
long long int v2[100001][2];
long long int v3[100001][2];
long long int v4[100001][2];
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	cin >> s;
	long long int ans = 0, h, e, f, len = s.length(), ci = 0, hi = 0, ei = 0, fi = 0;
	for(long long int i = 0; i < len; i++)
	{
		str[i] = true;
		if(s[i] == 'C')
		{
			v1[ci][0] = i;
			ci++;
		}
		else if(s[i] == 'H')
		{
			v2[hi][0] = i;
			hi++;
		}
		else if(s[i] == 'E')
		{
			v3[ei][0] = i;
			ei++;
		}
		else if(s[i] == 'F')
		{
			v4[fi][0] = i;
			fi++;
		}
	}
	v1[0][1] = ci;
	v2[0][1] = hi;
	v3[0][1] = ei;
	v4[0][1] = fi;
	ci = 0; hi = 0; ei = 0; fi = 0;
	for(int i = 0; i < v1[0][1]; i++)
	{
		if(str[v1[i][0]] == true)
		{
			while(v2[hi][0] < v1[i][0] || str[v2[hi][0]] == false) {hi++; if(hi >= v2[0][1]){break;}}
			if(hi >= v2[0][1]){break;}
			while(v3[ei][0] < v2[hi][0] || str[v3[ei][0]] == false) {ei++; if(ei >= v3[0][1]) {break;}}
			if(ei >= v3[0][1]) {break;}
			while(v4[fi][0] < v3[ei][0] || str[v4[fi][0]] == false) {fi++; if(fi >= v4[0][1]) {break;}}
			if(fi >= v4[0][1]) {break;}
			str[v1[i][0]] = str[v2[hi][0]] = str[v3[ei][0]] = str[v4[fi][0]] = false;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
