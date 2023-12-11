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
vector<int>v[10];
int dp[maxn][20];
int a[maxn];
int b[maxn];
string str,s,t;
int n,m;
void solve()
{
	for(int i=0;i<=9;i++)
		v[i].clear();
	cin>>str>>m>>s>>t;
	n=str.size();
	for(int i=0;i<n;i++){
		int x=str[i]-'0';
		v[x].push_back(i+1);
	}
	for(int i=0;i<m;i++){
		a[i+1]=s[i]-'0';
		b[i+1]=t[i]-'0';
		if(a[i+1]>b[i+1])swap(a[i+1],b[i+1]);
		for(int j=0;j<=9;j++)
			dp[i+1][j]=0;
	}
	a[0]=0;b[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=a[i-1];j<=b[i-1];j++){
			for(int k=a[i];k<=b[i];k++){
				int x=dp[i-1][j];
				int fa=upper_bound(v[k].begin(),v[k].end(),x)-v[k].begin();
				if(fa == v[k].size() )
				{
					cout<<"YES"<<endl;
					return ;
				}
				fa=v[k][fa];
				dp[i][k]=max(dp[i][k],fa);
			}
		}
	}
	cout<<"NO"<<endl;
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
1
459
2
49
59
*/