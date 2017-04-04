/* Written By Manav Aggarwal */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pii make_pair
map<char, ll> cardVals;
void initMap()
{
	for(ll i = 2; i < 10; i++)
	{
		cardVals[(char)(i+'0')] = i;
	}
	cardVals['T'] = 10;
	cardVals['J'] = 11;
	cardVals['Q'] = 12;
	cardVals['K'] = 13;
	cardVals['A'] = 14;
}

bool isFlush(string hand)
{
	bool isFlush = true;
	char suit = hand[1];
	for(ll i = 4; i < hand.length(); i += 3)
	{
		if(hand[i] != suit)
		{
			return false;
		}
	}
	return true;
}

ll NthVal(string hand, ll n)
{
	vector<ll> vals;
	for(ll i = 0; i < hand.length(); i += 3)
	{
		vals.push_back(cardVals[hand[i]]);
	}
	sort(vals.begin(), vals.end());
	return vals[5-n];
}
bool isStraight(string hand)
{
	vector<ll> vals;
	ll i;
	for(i = 0; i < hand.length(); i += 3)
	{
		vals.push_back(cardVals[hand[i]]);
	}
	sort(vals.begin(), vals.end());
	for(i = 1; i < vals.size(); i++)
	{
		if(vals[i] != vals[i-1] + 1)
		{
			return false;
		}
	}
	return true;
}

pair<bool, ll> hasOnePair(string hand)
{
	ll i, j;
	for(i = 0; i < hand.length() - 3; i += 3)
	{
		for(j = i + 3; j < hand.length(); j += 3)
		{
			if(hand[i] == hand[j])
			{
				return pii(true, cardVals[hand[i]]);
			}
		}
	}
	return pii(false, cardVals[hand[i]]);
}

pair<bool, pair<ll, ll> > hasTwoPairs(string hand)
{
	ll i, j, found = -1;
	for(i = 0; i < hand.length() - 3; i += 3)
	{
		for(j = i + 3; j < hand.length(); j += 3)
		{
			if(hand[i] == hand[j] && found == -1)
			{
				found = cardVals[hand[i]];
			}
			else if(hand[i] == hand[j] && cardVals[hand[i]] != found && found != -1)
			{
				return pii(true, pii(found, cardVals[hand[i]]) );
			}
		}
	}
	return pii(false, pii(0, 0));
}

pair<bool, ll> hasThreeOfKind(string hand)
{
	ll i, j, k;
	for(i = 0; i < hand.length() - 6; i += 3)
	{
		for(j = i + 3; j < hand.length() - 3; j += 3)
		{
			for(k = j + 3; k < hand.length(); k += 3)
			{
				if(hand[i] == hand[j] && hand[j] == hand[k])
				{
					return pii(true, cardVals[hand[i]]);
				}
			}
		}
	}
	return pii(false, 0);
}

bool hasFourOfKind(string hand)
{
	ll i, j, k, l;
	for(i = 0; i < hand.length() - 9; i += 3)
	{
		for(j = i + 3; j < hand.length() - 6; j += 3)
		{
			for(k = j + 3; k < hand.length() - 3; k += 3)
			{
				for(l = k + 3; l < hand.length(); l += 3)
				{
					if(hand[i] == hand[j] && hand[j] == hand[k] && hand[k] == hand[l])
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

pair< bool, pair<ll, ll> > hasFullHouse(string hand)
{
	ll i, j, k, found = -1;
	for(i = 0; i < hand.length() - 6; i += 3)
	{
		for(j = i + 3; j < hand.length() - 3; j += 3)
		{
			for(k = j + 3; k < hand.length(); k += 3)
			{
				if(hand[i] == hand[j] && hand[j] == hand[k])
				{
					found = cardVals[hand[i]];
					break;
				}
			}
		}
	}
	if(found != -1)
	{
		for(i = 0; i < hand.length() - 3; i += 3)
		{
			for(j = i + 3; j < hand.length(); j += 3)
			{
				if(hand[i] == hand[j] && cardVals[hand[i]] != found)
				{
					return pii(true, pii(found, cardVals[hand[i]]) );
				}
			}
		}
	}
	return pii(false, pii(0, 0) );
}

ll compareAll(string hand1, string hand2)
{
	vector<ll> vals1, vals2;
	ll i;
	for(i = 0; i < hand1.length(); i += 3)
	{
		vals1.push_back(cardVals[hand1[i]]);
		vals2.push_back(cardVals[hand2[i]]);
	}
	sort(vals1.begin(), vals1.end());
	sort(vals2.begin(), vals2.end());
	for(i = vals1.size() - 1; i >= 0; i--)
	{
		if(vals1[i] > vals2[i])
		{
			return 1;
		}
		else if(vals1[i] < vals2[i])
		{
			return 2;
		}
	}
	return 0;
}
ll winner(string game)
{
	string p1, p2;
	p1 = game.substr(0, 14);
	p2 = game.substr(15, 14);
	
	ll highestValP1 = NthVal(p1, 1), highestValP2 = NthVal(p2, 1), i, j, k;
	bool flushP1 = isFlush(p1), straightP1 = isStraight(p1), hasFourP1 = hasFourOfKind(p1);
	bool straightFlushP1 = (straightP1 && flushP1);
	bool royalFlushP1 = (straightFlushP1 && (highestValP1 == 14));
	
	bool flushP2 = isFlush(p2), straightP2 = isStraight(p2), hasFourP2 = hasFourOfKind(p2);
	bool straightFlushP2 = (straightP2 && flushP2);
	bool royalFlushP2 = (straightFlushP2 && (highestValP2 == 14));
	
	pair<bool, pair<ll, ll> > fullHouseP1 = hasFullHouse(p1), fullHouseP2 = hasFullHouse(p2);
	
	if(royalFlushP1)
	{
		return 1;
	}
	
	if(royalFlushP2)
	{
		return 2;
	}
	
	if(straightFlushP1 && straightFlushP2)
	{
		return (highestValP1 > highestValP2) ? 1 : 2;
	}
	
	if(straightFlushP1)
	{
		return 1;
	}
	
	if(straightFlushP2)
	{
		return 2;
	}
	
	if(hasFourP1 && hasFourP2)
	{
		if(highestValP1 != highestValP2)
		{
			return (highestValP1 > highestValP2) ? 1 : 2;
		}
		else
		{
			return (NthVal(p1, 5) > NthVal(p2, 5)) ? 1 : 2;
		}
	}
	if(hasFourP1)
	{
		return 1;
	}
	else if(hasFourP2)
	{
		return 2;
	}
	
	if(fullHouseP1.first && fullHouseP2.first)
	{
		if(fullHouseP1.second.first == fullHouseP2.second.first)
		{
			return (fullHouseP1.second.second > fullHouseP2.second.second) ? 1 : 2;
		}
		else
		{
			return (fullHouseP1.second.first > fullHouseP2.second.first) ? 1 : 2;
		}
	}
	if(fullHouseP1.first)
	{
		return 1;
	}
	else if(fullHouseP2.first)
	{
		return 2;
	}
	
	if(flushP1 && flushP2)
	{
		return compareAll(p1, p2);
	}
	if(flushP1)
	{
		return 1;
	}
	else if(flushP2)
	{
		return 2;
	}
	
	if(straightP1 && straightP2)
	{
		return (highestValP1 > highestValP2) ? 1 : 2;
	}
	if(straightP1)
	{
		return 1;
	}
	else if(straightP2)
	{
		return 2;
	}
	
	pair<bool, ll> hasThreeOfKindP1 = hasThreeOfKind(p1), hasThreeOfKindP2 = hasThreeOfKind(p2);
	pair<bool, pair<ll, ll> > hasTwoPairsP1 = hasTwoPairs(p1), hasTwoPairsP2 = hasTwoPairs(p2);
	
	if(hasThreeOfKindP1.first && hasThreeOfKindP2.first)
	{
		if(hasThreeOfKindP1.second == hasThreeOfKindP2.second)
		{
			return compareAll(p1, p2);
		}
		else
		{
			return (hasThreeOfKindP1.second > hasThreeOfKindP2.second) ? 1 : 2;
		}
		
	}
	if(hasThreeOfKindP1.first)
	{
		return 1;
	}
	else if(hasThreeOfKindP2.first)
	{
		return 2;
	}
	
	if(hasTwoPairsP1.first && hasTwoPairsP2.first)
	{
		ll greatestP1, greatestP2, leastP1, leastP2;
		if(hasTwoPairsP1.second.first > hasTwoPairsP1.second.second)
		{
			greatestP1 = hasTwoPairsP1.second.first;
			leastP1 = hasTwoPairsP1.second.second;
		}
		else
		{
			greatestP1 = hasTwoPairsP1.second.second;
			leastP1 = hasTwoPairsP1.second.first;
		}
		
		if(hasTwoPairsP2.second.first > hasTwoPairsP2.second.second)
		{
			greatestP2 = hasTwoPairsP2.second.first;
			leastP2 = hasTwoPairsP2.second.second;
		}
		else
		{
			greatestP2 = hasTwoPairsP2.second.second;
			leastP2 = hasTwoPairsP2.second.first;
		}
		if(greatestP1 != greatestP2)
		{
			return (greatestP1 > greatestP2) ? 1 : 2;
		}
		else if(leastP1 != leastP2)
		{
			return (leastP1 > leastP2) ? 1 : 2;
		}
		else
		{
			return compareAll(p1, p2);
		}
	}
	if(hasTwoPairsP1.first)
	{
		return 1;
	}
	else if(hasTwoPairsP2.first)
	{
		return 2;
	}
	
	pair<bool, ll> hasOnePairP1 = hasOnePair(p1), hasOnePairP2 = hasOnePair(p2);
	
	if(hasOnePairP1.first && hasOnePairP2.first)
	{
		if(hasOnePairP1.second == hasOnePairP2.second)
		{
			return compareAll(p1, p2);
		}
		else 
		{
			return (hasOnePairP1.second > hasOnePairP2.second) ? 1 : 2;
		}
	}
	if(hasOnePairP1.first)
	{
		return 1;
	}
	else if(hasOnePairP2.first)
	{
		return 2;
	}
	
	return compareAll(p1, p2);
}

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0);
	initMap();
	ifstream hands("poker.txt");
	stringstream buffer;
	buffer << hands.rdbuf();
	string test;
	test = buffer.str();
	vector<string> poker;
	ll i, count = 0;
	for(i = 0; i < test.length(); i+= 30)
	{
		poker.push_back(test.substr(i, 29));
	}
	for(i = 0; i < poker.size(); i++)
	{
		if(winner(poker[i]) == 1)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
//At last, it is complete! Yay!!!!!!
