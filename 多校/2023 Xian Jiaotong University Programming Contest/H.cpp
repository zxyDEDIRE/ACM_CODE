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
const int maxn=1e4;
bitset<maxn>vis[40];
string p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		vector<int>cnt(30,0);
		for(auto x:p[i])
			cnt[x-'a']++;
		for(int i=0;i<26;i++)
			vis[i][cnt[i]]=1;
	}
	for(int i=0;i<26;i++)
	{
		if(vis[i].count()==n)
		{
			cout<<"YES"<<endl;
			for(int j=0;j<26;j++)
				if(j!=i)
					cout<<(char)(j+'a');
			cout<<(char)(i+'a')<<endl;
			return ;
		}
	}
	cout<<"NO"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
cabd
ab
ccd

*/