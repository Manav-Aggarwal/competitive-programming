#include <bits/stdc++.h>
using namespace std;int main(){long N,e=2;cin>>N;while(N!=0){if((N&e)==e){cout << e << " ";N -= e;}e*=2;}cout<<endl;return 0;}
