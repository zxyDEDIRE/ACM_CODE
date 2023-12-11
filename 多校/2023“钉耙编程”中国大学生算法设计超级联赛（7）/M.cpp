/*！*/
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=1e6+100;
int p[maxn];
int a[maxn];
int n;
ll merge_sort(int p[],int l,int r)
{
	if(l>=r)return 0;
	ll t=0;
	int mid=l+r>>1;
	t=merge_sort(p,l,mid)+merge_sort(p,mid+1,r);
	int temp[r-l+1];
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(p[i]<=p[j])temp[k++]=p[i++];
		else
		{
			t+=mid-i+1;
			temp[k++]=p[j++];
		}
	}
	while(i<=mid)temp[k++]=p[i++];
	while(j<=r)temp[k++]=p[j++];
	for(int i=l,j=0;i<=r;i++,j++)p[i]=temp[j];
	return t;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ll cnt=merge_sort(p,1,n);
	int mi,ma;

	if(cnt&1)mi=2;
	else mi=0;
	ma=0;
	int x=log2(n);
	if((1<<x)<=n)x++;
	for(int i=x-1;i>=2;i--)
		ma|=(1<<i);
	if(cnt&1)ma=(ma^3);
	else ma=max(ma,ma^1);
	cout<<mi<<" "<<ma<<endl;
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
3
2
1 2
2
2 1
1
1
*/