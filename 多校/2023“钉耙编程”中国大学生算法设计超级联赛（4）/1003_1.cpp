/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
int tot[maxn];
int cnt[maxn];
struct node{
	int x,y;
	bool operator<(const node&a)const{
		if(a.x!=x)return a.x>x;
		return tot[a.y]-cnt[a.y]>tot[y]-cnt[y];
	}
};
multiset<node>S;
vector<int>v[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;cin>>m;
		v[i].resize(m);
		for(auto &x:v[i])
			cin>>x;
		sort(v[i].begin(),v[i].end());
		cnt[i]=1;
		tot[i]=m-1;
		S.insert({v[i][0],i});
	}
	int ans=INF;
	while(S.size()==n)
	{
		node s=*S.begin();
		node t=*S.rbegin();
		ans=min(ans,t.x-s.x);
		cout<<endl;
		cout<<s.x<<" "<<s.y<<" "<<cnt[s.y]<<" "<<tot[s.y]<<endl;
		cout<<t.x<<" "<<t.y<<" "<<cnt[t.y]<<" "<<tot[t.y]<<endl;
		S.erase(S.find(s));
		if(cnt[s.x]<=tot[s.x])
			S.insert({ v[s.y][cnt[s.x]++],s.y });
		else break;
		_sleep(500);
	}
	cout<<ans<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/