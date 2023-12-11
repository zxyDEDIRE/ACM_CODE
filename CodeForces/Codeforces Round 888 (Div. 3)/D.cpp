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
bitset<maxn>vis;
ll p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>p[i];
	vis.reset();
	int cnt_1=0;
	int cnt_2=0;
	int fl=-1;
	for(int i=0;i<n-1;i++){
		if(p[i+1]-p[i]>n)cnt_1++,fl=p[i+1]-p[i];
		else
		{
			if(vis[p[i+1]-p[i]])cnt_2++,fl=p[i+1]-p[i];
			else vis[p[i+1]-p[i]]=1;
		}
	}
	if(cnt_1+cnt_2>1){
		cout<<"No"<<endl;
		return ;
	}
	// cout<<fl<<endl;
	int sum=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			sum+=i;
	if(sum==fl||fl==-1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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
1 3 6
1 2 3

*/