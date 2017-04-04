#include<iostream>
using namespace std;int main(){int t,n,i,j,r[101][101];cin>>t;while(t--){cin>>n;;for(i=1;i<=n;i++){for(j=i;j>0;j--){cin>>r[i][j];}}for(i=n-1;i>0;i--){for(j=i;j>0;j--)r[i][j]+=max(r[i+1][j],r[i+1][j+1]);}cout<<r[1][1]<<'\n';}return 0;}
