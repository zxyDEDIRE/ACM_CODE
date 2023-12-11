/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int maxn=6e6+100;
int t[maxn][2];
vector<int>in[maxn];
int p[maxn];
int n,k,indx;
int ans,l,r;
vector<int> get_num(int x)
{
	vector<int>v;
	while(x){
		v.push_back(x%2);
		x/=2;
	}
	while(v.size()<k)v.push_back(0);
	reverse(v.begin(),v.end());
	// for(auto i:v)
	// 	cout<<i<<" ";cout<<endl;
	return v;
}
void insert(vector<int>v,int T)
{
	int rt=0;
	int flag=0;
	for(int i=0;i<k;i++)
	{
		int x=v[i];
		if(!t[rt][x])t[rt][x]=++indx,flag=1;
		if(flag==0)
		{
			for(auto _r:in[t[rt][x]])
			{
				int _l=T;
				// int _r=in[t[rt][x]];
				int _x=(p[_l]&p[_r]);
				_x=(((1ll<<k)-1)^_x);
				int _y=((p[_l]^_x)&(p[_r]^_x));
				if(_y>ans)
				{
					ans=_y;
					l=T;
					r=_r;
				}
			}
		}
		rt=t[rt][x];
		in[rt].push_back(T);
	}
}
void solve()
{
	cin>>n>>k;
	ans=-INF;
	l=1,r=2;
	indx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		insert(get_num(p[i]),i);
	}
	if(l>r)swap(l,r);
	int _x=(p[l]&p[r]);
	_x=(((1ll<<k)-1)^_x);
	cout<<l<<" "<<r<<" "<<_x<<endl;//" "<<((p[l]^_x)&(p[r]^_x))<<endl;

	for(int i=0;i<=indx;i++)
		t[i][0]=t[i][1]=0,in[i].clear();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
8421
1110

0011
0001
0001
1110
*/