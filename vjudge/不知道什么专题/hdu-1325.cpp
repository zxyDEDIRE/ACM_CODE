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
map<int,int>mp;
vector<int>in;
int cnt,x,y;
void solve()
{
	for(int q=1;;q++)
	{
		mp.clear();
		in.clear();
		cnt=0;
		in.push_back(0);
		while(1)
		{
			cin>>x>>y;
			if(x<0&&y<0)return ;
			if(x==0&&y==0)break;

			if(!mp[x])mp[x]=++cnt,in.push_back(0);
			if(!mp[y])mp[y]=++cnt,in.push_back(0);

			in[mp[y]]++;
		}
		int flag=1,cnt=-1;
		for(auto i:in)
		{
			if(i>1)flag=0;
			if(i==0)cnt++;
		}
		if(cnt!=1)flag=0;
		cout<<"Case "<<q<<" is ";
		if(flag==0)cout<<"not ";
		cout<<"a tree."<<endl;
	}
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}