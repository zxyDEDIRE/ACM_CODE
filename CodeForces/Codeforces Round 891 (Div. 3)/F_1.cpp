/*！*/
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
const int maxn=1e6+100;
int p[maxn];
map<int,int>mp;
int n,q;
void out(int x,int y)
{
	if(!mp.count(x)||!mp.count(y))cout<<0<<" ";
	else if(x==y)cout<<mp[x]*(mp[x]-1)/2<<" ";
	else cout<<mp[x]*mp[y]<<" ";
}
void A(int x,int y)
{
	/*
	1 10 11
	2 9 18
	3 8 24
	4 7 28
	5 6 30
	*/
	int l=(x+1)/2;
	int r=x-1;
	int ans=l;

	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(mid*(x-mid)==y){
			ans=mid;
			break;
		}
		else if(mid*(x-mid)>y)ans=mid,l=mid;
		else r=mid;
	}
	while(ans*(x-ans)>y)ans++;
	if(ans*(x-ans)==y)out(ans,x-ans);
	else cout<<"0 ";
}
void B(int x,int y)
{
	/*
	-3 -14
	3 -3 -9
	4 -4 -16


	1 -4 -4
	2 -5 -10
	3 -6 -18
	*/
	int l=1;
	int r=-y;
	int ans=l;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(mid*(x-mid)==y){
			ans=mid;
			break;
		}
		else if(mid*(x-mid)<y)ans=mid,l=mid;
		else r=mid;
	}
	while(ans*(x-ans)<y)ans++;
	if(ans*(x-ans)==y)out(ans,x-ans);
	else cout<<"0 ";
}
void C(int x,int y)
{
	/*
	-7 15
	-3 -4 -12
	-2 -5 -10


	-3 -4 -12
	-2 -5 -10
	-1 -6 -6
	*/
	int l=x/2;
	int r=-1;
	int ans=l;

	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(mid*(x-mid)==y){
			ans=mid;
			break;
		}
		else if(mid*(x-mid)<y)
			ans=mid,r=mid;
		else l=mid;
	}
	while(ans*(x-ans)<y)ans++;
	if(ans*(x-ans)==y)out(ans,x-ans);
	else cout<<"0 ";
}
void D(int x,int y)
{
	/*
	5 -9
	-3 8 -27
	-2 7 -14
	-1 6 -6

	-1 6 -6
	-2 7 -14
	-3 8 -24
	*/
	int l=x+1;
	int r=-y;
	int ans=l;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(mid*(x-mid)==y){
			ans=mid;
			break;
		}
		else if(mid*(x-mid)>y)
			ans=mid,l=mid;
		else r=mid;
	}
	while(ans*(x-ans)>y)ans++;
	if(ans*(x-ans)==y)out(ans,x-ans);
	else cout<<"0 ";
}
void solve()
{
	cin>>n;
	mp.clear();
	for(int i=1;i<=n;i++)
		cin>>p[i],mp[p[i]]++;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(x>0&&y>0)A(x,y);
		if(x<0&&y<0)B(x,y);
		if(x<0&&y>0)C(x,y);
		if(x>0&&y<0)D(x,y);
	}
	cout<<endl;
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
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
7
1 4 -2 3 3 3 -4
4
2 -8
-1 -2
7 12
-6 8

2 -8

*/