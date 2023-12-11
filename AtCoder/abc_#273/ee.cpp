/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<pii>v;
map<int,int>mp;
int q,top,x;
void solve()
{
	cin>>q;
	v.push_back({-1,-1});
	top=0;
	while(q--)
	{
		string op;
		cin>>op;
		if(op=="ADD")
		{
			cin>>x;
			v.push_back({top,x});
			top=v.size()-1;
		}
		else if(op=="DELETE")
		{
			if(v[top].first!=-1)
				top=v[top].first;
		}
		else if(op=="SAVE")
		{
			cin>>x;
			mp[x]=top;
		}	
		else
		{
			cin>>x;
			if(!mp.count(x))top=0;
			else top=mp[x];
		}
		cout<<v[top].second<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}