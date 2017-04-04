/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n = 0, num = 0, i, j, k, l, m, num1, num2, num3, num4, num5, num6;
	vector<ll> triangles, squares, pentagons, hexagons, heptagons, octagons, tmp;
	while(num <= 1000)
	{
		n++;
		num = (n*(n+1))/2;
	}
	while(num < 10000)
	{
		triangles.push_back(num);
		n++;
		num = (n*(n+1))/2;
	}
	
	n = 0, num = 0;
	while(num <= 1000)
	{
		n++;
		num = n*n;
	}
	while(num < 10000)
	{
		squares.push_back(num);
		n++;
		num = n*n;
	}
	
	n = 0, num = 0;
	while(num <= 1000)
	{
		n++;
		num = (n*(3*n - 1))/2;
	}
	while(num < 10000)
	{
		pentagons.push_back(num);
		n++;
		num = (n*(3*n - 1))/2;
	}
	
	n = 0, num = 0;
	while(num <= 1000)
	{
		n++;
		num = n*(2*n-1);
	}
	while(num < 10000)
	{
		hexagons.push_back(num);
		n++;
		num = n*(2*n-1);
	}
	
	n = 0, num = 0;
	while(num <= 1000)
	{
		n++;
		num = (n*(5*n-3))/2;
	}
	while(num < 10000)
	{
		heptagons.push_back(num);
		n++;
		num = (n*(5*n-3))/2;
	}
	
	n = 0, num = 0;
	while(num <= 1000)
	{
		n++;
		num = (n*(3*n-2));
	}
	while(num < 10000)
	{
		octagons.push_back(num);
		n++;
		num = (n*(3*n-2));
	}
	
	vector<vector<ll> > list3, list4, list5, list6, list7, list8, listToSearch, list8o, chain;
	for(i = 0; i < triangles.size(); i++)
	{
		for(j = 0; j < squares.size(); j++)
		{
			if(triangles[i] % 100 == squares[j]/100)
			{
				tmp.push_back(3);
				tmp.push_back(4);
				tmp.push_back(triangles[i]);
				tmp.push_back(squares[j]);	
				list3.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < pentagons.size(); j++)
		{
			if(triangles[i] % 100 == pentagons[j]/100)
			{	
				tmp.push_back(3);
				tmp.push_back(5);
				tmp.push_back(triangles[i]);
				tmp.push_back(pentagons[j]);	
				
				list3.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < hexagons.size(); j++)
		{
			if(triangles[i] % 100 == hexagons[j]/100)
			{
				tmp.push_back(3);
				tmp.push_back(6);
				tmp.push_back(triangles[i]);
				tmp.push_back(hexagons[j]);	
				
				list3.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < heptagons.size(); j++)
		{
			if(triangles[i] % 100 == heptagons[j]/100)
			{
				tmp.push_back(3);
				tmp.push_back(7);
				tmp.push_back(triangles[i]);
				tmp.push_back(heptagons[j]);	
				list3.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < octagons.size(); j++)
		{
			if(triangles[i] % 100 == octagons[j]/100)
			{
				
				tmp.push_back(3);
				tmp.push_back(8);
				tmp.push_back(triangles[i]);
				tmp.push_back(octagons[j]);	
				list3.push_back(tmp);
				tmp.clear();			
			}
		}
	}
	
	for(i = 0; i < squares.size(); i++)
	{
		for(j = 0; j < triangles.size(); j++)
		{
			if(squares[i] % 100 == triangles[j]/100)
			{
				tmp.push_back(4);
				tmp.push_back(3);
				tmp.push_back(squares[i]);
				tmp.push_back(triangles[j]);	
				list4.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < pentagons.size(); j++)
		{
			if(squares[i] % 100 == pentagons[j]/100)
			{	
				tmp.push_back(4);
				tmp.push_back(5);
				tmp.push_back(squares[i]);
				tmp.push_back(pentagons[j]);	
				
				list4.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < hexagons.size(); j++)
		{
			if(squares[i] % 100 == hexagons[j]/100)
			{
				tmp.push_back(4);
				tmp.push_back(6);
				tmp.push_back(squares[i]);
				tmp.push_back(hexagons[j]);	
				
				list4.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < heptagons.size(); j++)
		{
			if(squares[i] % 100 == heptagons[j]/100)
			{
				tmp.push_back(4);
				tmp.push_back(7);
				tmp.push_back(squares[i]);
				tmp.push_back(heptagons[j]);	
				list4.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < octagons.size(); j++)
		{
			if(squares[i] % 100 == octagons[j]/100)
			{
				
				tmp.push_back(4);
				tmp.push_back(8);
				tmp.push_back(squares[i]);
				tmp.push_back(octagons[j]);	
				list4.push_back(tmp);
				tmp.clear();			
			}
		}
	}
	
	for(i = 0; i < pentagons.size(); i++)
	{
		for(j = 0; j < squares.size(); j++)
		{
			if(pentagons[i] % 100 == squares[j]/100)
			{
				tmp.push_back(5);
				tmp.push_back(4);
				tmp.push_back(pentagons[i]);
				tmp.push_back(squares[j]);	
				list5.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < triangles.size(); j++)
		{
			if(pentagons[i] % 100 == triangles[j]/100)
			{	
				tmp.push_back(5);
				tmp.push_back(3);
				tmp.push_back(pentagons[i]);
				tmp.push_back(triangles[j]);	
				
				list5.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < hexagons.size(); j++)
		{
			if(pentagons[i] % 100 == hexagons[j]/100)
			{
				tmp.push_back(5);
				tmp.push_back(6);
				tmp.push_back(pentagons[i]);
				tmp.push_back(hexagons[j]);	
				
				list5.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < heptagons.size(); j++)
		{
			if(pentagons[i] % 100 == heptagons[j]/100)
			{
				tmp.push_back(5);
				tmp.push_back(7);
				tmp.push_back(pentagons[i]);
				tmp.push_back(heptagons[j]);	
				list5.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < octagons.size(); j++)
		{
			if(pentagons[i] % 100 == octagons[j]/100)
			{
				
				tmp.push_back(5);
				tmp.push_back(8);
				tmp.push_back(pentagons[i]);
				tmp.push_back(octagons[j]);	
				list5.push_back(tmp);
				tmp.clear();			
			}
		}
	}
	
	for(i = 0; i < hexagons.size(); i++)
	{
		for(j = 0; j < squares.size(); j++)
		{
			if(hexagons[i] % 100 == squares[j]/100)
			{
				tmp.push_back(6);
				tmp.push_back(4);
				tmp.push_back(hexagons[i]);
				tmp.push_back(squares[j]);	
				list6.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < pentagons.size(); j++)
		{
			if(hexagons[i] % 100 == pentagons[j]/100)
			{	
				tmp.push_back(6);
				tmp.push_back(5);
				tmp.push_back(hexagons[i]);
				tmp.push_back(pentagons[j]);	
				
				list6.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < triangles.size(); j++)
		{
			if(hexagons[i] % 100 == triangles[j]/100)
			{
				tmp.push_back(6);
				tmp.push_back(3);
				tmp.push_back(hexagons[i]);
				tmp.push_back(triangles[j]);	
				
				list6.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < heptagons.size(); j++)
		{
			if(hexagons[i] % 100 == heptagons[j]/100)
			{
				tmp.push_back(6);
				tmp.push_back(7);
				tmp.push_back(hexagons[i]);
				tmp.push_back(heptagons[j]);	
				list6.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < octagons.size(); j++)
		{
			if(hexagons[i] % 100 == octagons[j]/100)
			{
				
				tmp.push_back(6);
				tmp.push_back(8);
				tmp.push_back(hexagons[i]);
				tmp.push_back(octagons[j]);	
				list6.push_back(tmp);
				tmp.clear();			
			}
		}
	}
	
	for(i = 0; i < octagons.size(); i++)
	{
		for(j = 0; j < squares.size(); j++)
		{
			if(octagons[i] % 100 == squares[j]/100)
			{
				tmp.push_back(8);
				tmp.push_back(4);
				tmp.push_back(octagons[i]);
				tmp.push_back(squares[j]);	
				list8.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < pentagons.size(); j++)
		{
			if(octagons[i] % 100 == pentagons[j]/100)
			{	
				tmp.push_back(8);
				tmp.push_back(5);
				tmp.push_back(octagons[i]);
				tmp.push_back(pentagons[j]);	
				
				list8.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < hexagons.size(); j++)
		{
			if(octagons[i] % 100 == hexagons[j]/100)
			{
				tmp.push_back(8);
				tmp.push_back(6);
				tmp.push_back(octagons[i]);
				tmp.push_back(hexagons[j]);	
				
				list8.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < triangles.size(); j++)
		{
			if(octagons[i] % 100 == triangles[j]/100)
			{
				tmp.push_back(8);
				tmp.push_back(3);
				tmp.push_back(octagons[i]);
				tmp.push_back(triangles[j]);	
				list8.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < heptagons.size(); j++)
		{
			if(octagons[i] % 100 == heptagons[j]/100)
			{
				
				tmp.push_back(8);
				tmp.push_back(7);
				tmp.push_back(octagons[i]);
				tmp.push_back(heptagons[j]);	
				list8.push_back(tmp);
				tmp.clear();			
			}
		}
	}
	
	for(i = 0; i < heptagons.size(); i++)
	{
		for(j = 0; j < squares.size(); j++)
		{
			if(heptagons[i] % 100 == squares[j]/100)
			{
				tmp.push_back(7);
				tmp.push_back(4);
				tmp.push_back(heptagons[i]);
				tmp.push_back(squares[j]);	
				list7.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < pentagons.size(); j++)
		{
			if(heptagons[i] % 100 == pentagons[j]/100)
			{	
				tmp.push_back(7);
				tmp.push_back(5);
				tmp.push_back(heptagons[i]);
				tmp.push_back(pentagons[j]);	
				list7.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < hexagons.size(); j++)
		{
			if(heptagons[i] % 100 == hexagons[j]/100)
			{
				tmp.push_back(7);
				tmp.push_back(6);
				tmp.push_back(heptagons[i]);
				tmp.push_back(hexagons[j]);	
				
				list7.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < triangles.size(); j++)
		{
			if(heptagons[i] % 100 == triangles[j]/100)
			{
				tmp.push_back(7);
				tmp.push_back(3);
				tmp.push_back(heptagons[i]);
				tmp.push_back(triangles[j]);	
				list7.push_back(tmp);
				tmp.clear();			
			}
		}
		for(j = 0; j < octagons.size(); j++)
		{
			if(heptagons[i] % 100 == octagons[j]/100)
			{
				
				tmp.push_back(7);
				tmp.push_back(8);
				tmp.push_back(heptagons[i]);
				tmp.push_back(octagons[j]);	
				list7.push_back(tmp);
				tmp.clear();			
			}
		}
	}
	ll count = 0;
	for(i = 0; i < list8.size(); i++)
	{
		num = list8[i][1];
		switch(num)
		{
			case 4:
				listToSearch = list4;
				break;
			case 5:
				listToSearch = list5;
				break;
			case 6:
				listToSearch = list6;
				break;
			case 7:
				listToSearch = list7;
				break;
			case 3:
				listToSearch = list3;
				break;	
		}
		for(j = 0; j < listToSearch.size(); j++)
		{
			if(listToSearch[j][1] != 8 && list8[i][3] == listToSearch[j][2])
			{
				tmp.push_back(8);
				tmp.push_back(num);
				tmp.push_back(listToSearch[j][1]);
				tmp.push_back(list8[i][2]);
				tmp.push_back(list8[i][3]);
				tmp.push_back(listToSearch[j][3]);
				list8o.push_back(tmp);
				tmp.clear();
			}
		}
	}
	for(i = 0; i < list8o.size(); i++)
	{
		num = list8o[i][2];
		switch(num)
		{
			case 4:
				listToSearch = list4;
				break;
			case 5:
				listToSearch = list5;
				break;
			case 6:
				listToSearch = list6;
				break;
			case 7:
				listToSearch = list7;
				break;
			case 3:
				listToSearch = list3;
				break;	
		}
		for(j = 0; j < listToSearch.size(); j++)
		{
			if(listToSearch[j][1] != 8 && listToSearch[j][1] != list8o[i][1] && list8o[i][5] == listToSearch[j][2])
			{
				tmp.push_back(8);
				tmp.push_back(list8o[i][1]);
				tmp.push_back(list8o[i][2]);
				tmp.push_back(listToSearch[j][1]);
				tmp.push_back(list8o[i][3]);
				tmp.push_back(list8o[i][4]);
				tmp.push_back(list8o[i][5]);
				tmp.push_back(listToSearch[j][3]);
				chain.push_back(tmp);
				tmp.clear();
			}
		}
	}
	list8o.clear();
	for(i = 0; i < chain.size(); i++)
	{
		num = chain[i][3];
		switch(num)
		{
			case 4:
				listToSearch = list4;
				break;
			case 5:
				listToSearch = list5;
				break;
			case 6:
				listToSearch = list6;
				break;
			case 7:
				listToSearch = list7;
				break;
			case 3:
				listToSearch = list3;
				break;	
		}
		for(j = 0; j < listToSearch.size(); j++)
		{
			if(listToSearch[j][1] != 8 && listToSearch[j][1] != chain[i][1] && listToSearch[j][1] != chain[i][2] && chain[i][7] == listToSearch[j][2])
			{
				tmp.push_back(8);
				tmp.push_back(chain[i][1]);
				tmp.push_back(chain[i][2]);
				tmp.push_back(chain[i][3]);
				tmp.push_back(listToSearch[j][1]);
				tmp.push_back(chain[i][4]);
				tmp.push_back(chain[i][5]);
				tmp.push_back(chain[i][6]);
				tmp.push_back(chain[i][7]);
				tmp.push_back(listToSearch[j][3]);
				list8o.push_back(tmp);
				tmp.clear();
			}
		}
	}
	chain.clear();
	for(i = 0; i < list8o.size(); i++)
	{
		num = list8o[i][4];
		switch(num)
		{
			case 4:
				listToSearch = list4;
				break;
			case 5:
				listToSearch = list5;
				break;
			case 6:
				listToSearch = list6;
				break;
			case 7:
				listToSearch = list7;
				break;
			case 3:
				listToSearch = list3;
				break;	
		}
		for(j = 0; j < listToSearch.size(); j++)
		{
			if(listToSearch[j][1] != 8 && listToSearch[j][1] != list8o[i][1] && listToSearch[j][1] != list8o[i][2] && listToSearch[j][1] != list8o[i][3] && list8o[i][9] == listToSearch[j][2])
			{
				tmp.push_back(8);
				tmp.push_back(list8o[i][1]);
				tmp.push_back(list8o[i][2]);
				tmp.push_back(list8o[i][3]);
				tmp.push_back(list8o[i][4]);
				tmp.push_back(listToSearch[j][1]);
				tmp.push_back(list8o[i][5]);
				tmp.push_back(list8o[i][6]);
				tmp.push_back(list8o[i][7]);
				tmp.push_back(list8o[i][8]);
				tmp.push_back(list8o[i][9]);
				tmp.push_back(listToSearch[j][3]);
				chain.push_back(tmp);
				tmp.clear();
			}
		}
	}
	ll sum = 0;
	for(i = 0; i < chain.size(); i++)
	{
		for(j = 6; j < chain[i].size(); j++)
		{
			if(chain[i][11]%100 == chain[i][6]/100)
			{
				cout << chain[i][j] << " ";
				sum += chain[i][j];
			}
		}
	}
	cout << endl << sum;
	return 0;
}
