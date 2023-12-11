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
int w[maxn];
int v[maxn];
int n,m;
void solve()
{
	int n,m,ans=0;
	vector<int>w,v;
	cin>>n>>m;
	w.resize(n);
	v.resize(n);
	for(int i=0;i<n;i++)
		cin>>w[i]>>v[i];
	for(int i=0;i<(1<<n);i++)
	{
		int cos=0;
		int val=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				cos+=w[j],val+=v[j];
		if(cos<=m)
			ans=max(ans,val);
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	clock_t start, finish;
	start = clock();
	// int __;cin>>__;
	// while(__--)
		solve();
	finish = clock();
	 cout << "the time cost is" <<\
	  double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
