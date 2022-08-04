/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
string a,b;
int n,m;
void YES(){cout<<"Yes"<<endl;}
void NO(){cout<<"No"<<endl;}
void solve()
{
	cin>>n>>m>>a>>b;
	int flag=1,fl;
	for(int i=a.size()-1,j=b.size()-1;i>=0;i--)
	{
		if(flag==1)
		{
			if(a[i]==b[j])j--;
			else
			{
				flag=0;
				if(j!=0)return NO();
			}
			if(j==-1)return YES();
		}
		else if(flag==0)
		{
			if(a[i]==b[j])return YES();
		}
	}
	return NO();
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*

001001
11
y

110111
01
y

000001
11
n

111111
01
n

10000101
11010
n

1010001
1001
y

01010010
010010
y

01010101
1001
n

10101010
0110
n

1011100
11100
y
*/
