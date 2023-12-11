#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define int long long
#define endl '\n'
typedef long long ll;
typedef pair<int,int> P;
const int N=1e6+7;
const int INF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int n,k;
int an[N],vis[N],aa[N];
struct poi
{
	int num,id;
}a[N];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)an[i]=i-1;
	for(int i=1;i<=n;i++)cin>>a[i].num,a[i].id=i,vis[i]=0,aa[i]=a[i].num;
	sort(a+1,a+1+n,[&](poi a,poi b){
		if(a.num!=b.num)return a.num<b.num;
		return a.id>b.id;
	});
	int ans=0;
	int ma=0;
	for(int i=1;i<=n;i++){
		if(k>=a[i].num){
			vis[a[i].id]=1;
			k-=a[i].num;
			ans++;
			ma=max(ma,a[i].num);
		}
		else an[a[i].id]++;
	}
	if(ans+1<=n&&!vis[ans+1]){
		if(ma+k>=aa[ans+1]){
			an[ans+1]--;
		}
	}
	an[n+1]=ans;
	sort(an+1,an+2+n,[&](int a,int b){
		return a>b;
	});
	cout<<lower_bound(an+1,an+2+n,ans,greater<int>() )-an<<endl;

}
signed main()
{
	IOS
	int __=1;
	cin >> __;
	while (__--)
		solve();
}