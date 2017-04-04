/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool comp(string s1, string s2)
{
	return s1.length() > s2.length();
}
bool canHop(string w1, string w2)
{
	ll i, loc;
	bool gotOne = false;
	if(w1.length() - w2.length() == 1)
	{
		for(i = 0; i < w2.length(); i++)
		{
			if(!gotOne && w1[i] != w2[i])
			{
				if(w1[i+1] == w2[i])
				{
					gotOne = true;
				}
				else
				{
					return false;
				}
			}
			else if(gotOne && w1[i+1] != w2[i])
			{
				return false;
			}
		}
		return true;
	}
	else if(w1.length() == w2.length())
	{
		for(i = 0; i < w1.length(); i++)
		{
			if(w1[i] != w2[i])
			{
				if(!gotOne)
				{
					gotOne = true;
					loc = i;
				}
				else
				{
					return false;
				}
			}
		}
		if(gotOne)
		{
			if(w2[loc] > w1[loc])
			{
				for(i = loc+1; i < w1.length(); i++)
				{
					if(w1[i] == w2[loc])
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.in", "r", stdin);
	map<string, bool> isTaken;
	map<string, ll> position;
	ll n, i, maxTillNow = 0, j;
	cin >> n;
	string word;
	vector<string> wordsArr[11], words, seq;
	list<vector<string> > seqs, nextSeqs;
	for(i = 0; i < n; i++)
	{
		cin >> word;
		if(!isTaken[word])
		{
			wordsArr[word.length()].push_back(word);
			isTaken[word] = true;
		}
	}
	for(i = 1; i <= 10; i++)
	{
		sort(wordsArr[i].begin(), wordsArr[i].end());
	}
	for(i = 10; i >= 1; i--)
	{
		for(j = 0; j < wordsArr[i].size(); j++)
		{
			word = wordsArr[i][j];
			words.push_back(word);
			position[word] = words.size()-1;
			seq.push_back(word);
			seqs.push_back(seq);
			seq.clear();
		}
	}
	bool changed = true;
	while(changed)
	{
		changed = false;
		for(list<vector<string> >::iterator it = seqs.begin(); it != seqs.end(); it++)
		{
			seq = *it;
			if(seq.size() == 0)
			{
				continue;
			}
			word = seq[seq.size()-1]; //seq[0] seq[1] seq[2] seq[3] seq[4] seq[5]
			for(i = position[word] + 1; i < words.size(); i++)
			{
				if(canHop(word, words[i]))
				{
					seq.push_back(words[i]);
					nextSeqs.push_back(seq);
					maxTillNow = max(maxTillNow, (ll)(seq.size()));
					changed = true;
					seq = *it;
				}
			}
		}
		seqs.clear();
		seqs = nextSeqs;
		nextSeqs.clear();
	}
	cout << maxTillNow;
	return 0;
}
