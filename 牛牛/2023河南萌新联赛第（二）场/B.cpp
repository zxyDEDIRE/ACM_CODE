/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e6+100;
int t[maxn][2],indx;
int num[maxn];
int n,hp;
vector<int> get_num(int x)
{
	vector<int>v;
	while(x){
		v.push_back(x%2);
		x/=2;
	}
	while(v.size()<30)v.push_back(0);
	reverse(v.begin(),v.end());
	return v;
}
void insert(vector<int>v)
{
	int rt=0;
	for(int i=0;i<v.size();i++)
	{
		int c=v[i];
		if(!t[rt][c])
			t[rt][c]=++indx;
		rt=t[rt][c];
		num[rt]++;
	}
}
void remove(vector<int>v)
{
	int rt=0;
	for(int i=0;i<v.size();i++)
	{
		int c=v[i];
		rt=t[rt][c];
		num[rt]--;
	}
}
int query(vector<int>v,vector<int>h)
{
	int rt=0;
	int ans=0;
	int flag=0;
	for(int i=0;i<v.size();i++)
	{
		int c=v[i];
		int d=h[i];
		if(d==0)
			ans+=num[t[rt][c^1]];
		if(d==1)c^=1;
		if(!t[rt][c]){
			flag=1;
			break;
		}
		rt=t[rt][c];
	}
	return ans;
}
void solve()
{
	cin>>n>>hp;
	while(n--)
	{
		int op;
		cin>>op;
		if(op==0)
		{
			int x;cin>>x;
			insert(get_num(x));
		}
		else if(op==1)
		{
			int x;cin>>x;
			remove(get_num(x));
		}
		else
		{
			int x,h;cin>>x>>h;
			int now=query(get_num(x), get_num(h));
			cout<<now<<endl;
			if(now==0)hp--;
		}
	}
	cout<<hp<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}