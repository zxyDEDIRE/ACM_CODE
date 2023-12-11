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
vector<int>v[maxn];
int p[maxn];
int n,k;
void NO(){cout<<"No\n";}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=n;i++){
		int x;cin>>x;p[i]=x;
		v[x].push_back(i);
	}
	int s=p[1];
	int t=p[n];
	if(p[1]!=p[n]&&(v[s].size()<k||v[t].size()<k))return NO();
	if(p[1]==p[n]&&v[s].size()<k)return NO();
	else if(p[1]==p[n]){
		cout<<"Yes"<<endl;
		return ;
	}
	s=v[s][k-1];
	t=v[t][(int)v[t].size()-k];
	if(s>t)return NO();
	cout<<"Yes"<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
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
0 1 2 3
*/