/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
map<int,stack<int>>mp;
stack<int>s;
int q;
void solve()
{
	cin>>q;
	while(q--)
	{
		string op;int x;
		cin>>op;
		if(op=="ADD")
		{ 
			cin>>x;
			s.push(x);
		}
		else if(op=="DELETE")
		{
			if(!s.empty())s.pop();
		}
		else if(op=="SAVE")
		{
			cin>>x;
			mp[x]=s;
		}
		else if(op=="LOAD")
		{
			cin>>x;
			if(!mp.count(x))
			{
				while(!s.empty())s.pop();
			}
			else s=mp[x];
		}
		if(!s.empty())cout<<s.top()<<" ";
		else cout<<-1<<" ";
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