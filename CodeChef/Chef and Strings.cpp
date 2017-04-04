#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
unsigned long long int ch[1000001][2], ce[1000001][2], cf[1000001][2], hc[1000001][2], he[1000001][2], hf[1000001][2], ec[1000001][2], eh[1000001][2], ef[1000001][2], fc[1000001][2], fh[1000001][2], fe[1000001][2]; 
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	string P;
	cin >> P;
	unsigned long long int len = P.length(), xch = 0, xce = 0, xcf = 0, xhc = 0, xhe = 0, xhf = 0, xec = 0, xeh = 0, xef = 0, xfc = 0, xfh = 0, xfe = 0;
	unsigned long long int countch = 0, countce = 0, countcf = 0, counthc = 0, counthe = 0, counthf = 0, countec = 0, counteh = 0, countef = 0, countfc = 0, countfh = 0, countfe = 0;
	ch[0][0] = 0; ce[0][0] = 0; cf[0][0] = 0; hc[0][0] = 0; he[0][0] = 0; hf[0][0] = 0; ec[0][0] = 0; eh[0][0] = 0; ef[0][0] = 0; fc[0][0] = 0; fh[0][0] = 0; fe[0][0] = 0;
	ch[0][1] = 0; ce[0][1] = 0; cf[0][1] = 0; hc[0][1] = 0; he[0][1] = 0; hf[0][1] = 0; ec[0][1] = 0; eh[0][1] = 0; ef[0][1] = 0; fc[0][1] = 0; fh[0][1] = 0; fe[0][1] = 0;
	for(unsigned long long int i = 0; i < len; i++)
	{
		if(P[i] == 'c')
		{
			xch++; xce++; xcf++;
			counthc += xhc; countec += xec; countfc += xfc;
		}
		else if(P[i] == 'h')
		{
			xhc++; xhe++; xhf++;
			countch += xch; counteh += xeh; countfh += xfh;
		}
		else if(P[i] == 'e')
		{
			xec++; xeh++; xef++;
			countce += xce; counthe += xhe; countfe += xfe;
		}
		else if(P[i] == 'f')
		{
			xfc++; xfh++; xfe++;
			countcf += xcf; counthf += xhf; countef += xef;
		}
		ch[i+1][0] = countch; ch[i+1][1] = xch;
		ce[i+1][0] = countce; ce[i+1][1] = xce;
		cf[i+1][0] = countcf; cf[i+1][1] = xcf;
		
		hc[i+1][0] = counthc; hc[i+1][1] = xhc;
		he[i+1][0] = counthe; he[i+1][1] = xhe;
		hf[i+1][0] = counthf; hf[i+1][1] = xhf;
		
		ec[i+1][0] = countec; ec[i+1][1] = xec;
		eh[i+1][0] = counteh; eh[i+1][1] = xeh;
		ef[i+1][0] = countef; ef[i+1][1] = xef;
		
		fc[i+1][0] = countfc; fc[i+1][1] = xfc;
		fh[i+1][0] = countfh; fh[i+1][1] = xfh;
		fe[i+1][0] = countfe; fe[i+1][1] = xfe;
	}
	unsigned long long int Q;
	cin >> Q;
	while(Q--)
	{
		char a, b;
		unsigned long long int L, R, count = 0, noOf = 0;
		cin >> a >> b >> L >> R;
		if(a == 'c' && b == 'h')
		{
			noOf = hc[R][1] - hc[L-1][1];
			count = (ch[R][0] - ch[L-1][0]) - (noOf*ch[L-1][1]);
		}
		else if(a == 'c' && b == 'e')
		{
			noOf = ec[R][1] - ec[L-1][1];
			count = (ce[R][0] - ce[L-1][0]) - (noOf*ce[L-1][1]);
		}
		else if(a == 'c' && b == 'f')
		{
			noOf = fc[R][1] - fc[L-1][1];
			count = (cf[R][0] - cf[L-1][0]) - (noOf*cf[L-1][1]);
		}
		else if(a == 'h' && b == 'c')
		{
			noOf = ch[R][1] - ch[L-1][1];
			count = (hc[R][0] - hc[L-1][0]) - (noOf*hc[L-1][1]);
		}
		else if(a == 'h' && b == 'e')
		{
			noOf = eh[R][1] - eh[L-1][1];
			count = (he[R][0] - he[L-1][0]) - (noOf*he[L-1][1]);
		}
		else if(a == 'h' && b == 'f')
		{
			noOf = fh[R][1] - fh[L-1][1];
			count = (hf[R][0] - hf[L-1][0]) - (noOf*hf[L-1][1]);
		}
		else if(a == 'e' && b == 'c')
		{
			noOf = ce[R][1] - ce[L-1][1];
			count = (ec[R][0] - ec[L-1][0]) - (noOf*ec[L-1][1]);
		}
		else if(a == 'e' && b == 'h')
		{
			noOf = he[R][1] - he[L-1][1];
			count = (eh[R][0] - eh[L-1][0]) - (noOf*eh[L-1][1]);
		}
		else if(a == 'e' && b == 'f')
		{
			noOf = fe[R][1] - fe[L-1][1];
			count = (ef[R][0] - ef[L-1][0]) - (noOf*ef[L-1][1]);
		}
		else if(a == 'f' && b == 'c')
		{
			noOf = cf[R][1] - cf[L-1][1];
			count = (fc[R][0] - fc[L-1][0]) - (noOf*fc[L-1][1]);
		}
		else if(a == 'f' && b == 'h')
		{
			noOf = hf[R][1] - hf[L-1][1];
			count = (fh[R][0] - fh[L-1][0]) - (noOf*fh[L-1][1]);
		}
		else if (a == 'f' && b == 'e')
		{
			noOf = ef[R][1] - ef[L-1][1];
			count = (fe[R][0] - fe[L-1][0]) - (noOf*fe[L-1][1]);
		}
		cout << count << endl;
	}
	return 0;
}
