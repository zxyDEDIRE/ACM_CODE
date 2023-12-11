/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<string>v;
int t[maxn][30];
int num[maxn];
int n,tot;
void insert(string &s)
{
	int rt=0;
	for(auto ch:s)
	{
		int x=ch-'a';
		if(!t[rt][x])
			t[rt][x]=++tot;
		rt=t[rt][x];
		num[rt]++;
	}
}
void query(string &s)
{
	int rt=0,ma=0;
	for(auto ch:s)
	{
		int x=ch-'a';
		rt=t[rt][x];
		if(num[rt]>=2)ma++;
		else break;
	}
	cout<<ma<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		insert(s);
		v.push_back(s);
	}
	for(auto i:v)
		query(i);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}