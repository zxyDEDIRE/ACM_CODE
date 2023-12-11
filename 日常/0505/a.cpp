#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int maxn=2e5+10;
int p[211];
string str;
int n,k;
int find(int r){
	return p[r]=(p[r]==r)?r:find(p[r]);
}
void solve()
{
	cin>>n>>k;
	cin>>str;
	for(int j=1;j<=200;j++)p[j]=j;
	for(int i=0;i<n;i++)
	{
		int x=(int)(str[i]-'a'+1);
		x=find(x);
		if(x!=1&&k>0)
		{
			while(1)
			{
				if(x==1)break;
				x=find(x);
				if(k==0||x==1)break;
				p[x]=x-1;
				k--;
				x--;
				if(k==0)break;
			}
		}
		cout<<((char)('a'+x-1));
	}
	cout<<"\n";
}
int main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
97

1
3 2
cba

1
4 5
fgde

1
7 5
gndcafb

1
4 19
ekyv

5 2
dcbae
ccbae
bbbae
aaaae
*/