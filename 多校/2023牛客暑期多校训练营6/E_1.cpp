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
const int maxn=1e6+100;
vector<int>v[2];
int p[maxn];
int w[maxn];
int n,q;
void solve()
{
	cin>>n>>q;

	v[0].clear();
	v[1].clear();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];p[i]+=p[i-1];
		w[i]=(p[i]&1);
		v[w[i-1]].push_back(i);
	}
	// for(auto x:v[0])cout<<x<<" ";cout<<endl;
	// for(auto x:v[1])cout<<x<<" ";cout<<endl;
	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		int flag=0;
		if(w[l-1]!=w[r]){
			cout<<"NO"<<endl;
			continue;
		}
		int f1=lower_bound(v[w[l-1]].begin(),v[w[l-1]].end(),l)-v[w[l]].begin();
		int f2=upper_bound(v[w[l-1]].begin(),v[w[l-1]].end(),r)-v[w[l]].begin();
		f2--;
		// cout<<f1<<" "<<f2<<endl;
		if(f2>=f1&&f2-f1+1>=k)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
}
signed main(){
 // freopen("out.txt","r",stdin);
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
1
3 1
1 0 1
1 3 2

1
2 1
1 3
1 2  1
*/