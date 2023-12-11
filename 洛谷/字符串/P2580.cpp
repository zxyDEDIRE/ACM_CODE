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
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
bitset<maxn>vis;
map<ull,int>mp;
int n,m;
ull get_hash(string &str)
{
	ull ans=0;
	for(auto i:str)
		ans=(ans*base+ull(i))%str_mod+prime;
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		ull ans=get_hash(str);
		mp[ans]=1;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string str;
		cin>>str;
		ull ans=get_hash(str);
		if(!mp.count(ans))cout<<"WRONG"<<endl;
		else
		{
			int x=mp[ans];
			if(x==1)cout<<"OK"<<endl,mp[ans]=2;
			else cout<<"REPEAT"<<endl;
		}
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