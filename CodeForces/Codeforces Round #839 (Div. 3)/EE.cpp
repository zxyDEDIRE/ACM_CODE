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
int p[N];
int a[N];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],p[i]=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i)p[i]++;
		if(a[i]!=n-i+1)p[i]+=2;
	}
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(p[i]==1)cnt1++;
		else if(p[i]==2)cnt2++;
		else if(p[i]==3)cnt3++;
	}
	int fl=0;
	// cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
	// cin>>cnt1>>cnt2>>cnt3;
	int tt=min(cnt1,cnt2);
	tt=min(0ll,tt-1);
	cnt1-=tt;
	cnt2-=tt;
	if(cnt3<=cnt2){
		cout<<"First"<<endl;
		return;
	}
	if(cnt3+1<=cnt1){
		cout<<"Second"<<endl;
		return;
	}
	cout<<"Tie"<<endl;
}
signed main()
{
	//IOS
	int __=1;
	cin >> __;
	while (__--)
		solve();
}
/*
a=3 b=2
7
1 2 3 4 5 6 7
7
1 5 2 3 4 6 7
7
7 6 5 4 3 2 1
7
4 2 3 5 7 6 1
7
4 2  7 6 1
*/