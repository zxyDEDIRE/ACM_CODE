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
int n;
void solve()
{
	cin>>n;
	if(n&1)
	{
		int m=n-1;
		for(int i=1;i<=n;i++)
		{
			if(i&1)cout<<i<<" ";
			else cout<<m<<" ",m-=2;
		}
		cout<<endl;
	}
	else
	{
		int len=n/2;
		vector<int>a(len+1),b(len+1);
		int l=1,r=len,fl=1,op=1;
		while(l<=r){
			if(op&1)a[l]=fl++,l++;
			else a[r]=fl++,r--;
			op++;
		}

		l=1,r=len,fl=n,op=1;
		while(l<=r){
			if(op&1)b[r]=fl--,r--;
			else b[l]=fl--,l++;
			op++;
		}
		for(int i=1;i<=len;i++)
			cout<<a[i]<<" "<<b[i]<<" ";
		cout<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}