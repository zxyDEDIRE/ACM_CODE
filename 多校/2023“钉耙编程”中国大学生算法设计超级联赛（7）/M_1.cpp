/*！*/
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
int s[maxn];
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
	for(int i=1;i<=n;i++)
		a[n-i+1]=p[i];
	for(int i=1;i<=n;i++)s[i]=p[i];
	int ans_1=merge_sort(s,1,n);
	for(int i=1;i<=n;i++)s[i]=a[i];
	int ans_2=merge_sort(s,1,n);
	// cout<<ans_1<<" "<<ans_2<<endl;
	if(ans_1%2==ans_2%2)cout<<"YES"<<endl;
	else cout<<"SDFSDFSD"<<endl;
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	n=5;
	for(int i=1;i<=n;i++)
		p[i]=i;
	int cnt=0;
	do{
		// cout<<"cnt :"<<++cnt<<endl;
		solve();
		// _sleep(100);
	}while(next_permutation(p+1,p+1+n));
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5
1 2 4 3 5
5
1 2 5 4 3
5
1 2 3 4 5
5
3 4 1 2 5
5
4 2 5 1 3

*/