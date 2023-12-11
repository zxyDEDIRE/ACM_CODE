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
	for(int i=1;i<=n;i++){
		if(k>=a[i].num){
			vis[a[i].id]=1;
			k-=a[i].num;
			ans++;
		}
		else an[a[i].id]++;
	}
	int ma=-1,mi=INF,t1=-1,t2=-1;
	for(int i=1;i<=n;i++){
		if(!vis[i])continue;
		ma=max(ma,aa[i]);
	}
	// cout<<t1<<" "<<t2<<endl;
	if(ma!=-1&&!vis[ans+1]){
		// cout<<"**"<<endl;
		if(ma+k>=aa[ans+1]){
			an[ans+1]--;
			// cout<<"&&&"<<endl;
		}
	}
	// for(int i=1;i<=n;i++)cout<<an[i]<<" ";cout<<endl;
	int anss=1;
	for(int i=1;i<=n;i++){
		if(an[i]>ans)anss++;
	}
	cout<<anss<<endl;
}
signed main()
{
	IOS
	int __=1;
	cin >> __;
	while (__--)
		solve();
}