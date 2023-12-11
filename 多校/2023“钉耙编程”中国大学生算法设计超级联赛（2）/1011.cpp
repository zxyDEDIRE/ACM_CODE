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
int p[maxn];
int n;
void solve(int n)
{
	int ans=0;
	int res=0;
	for(int k=0;k<n;k++)
	{
		for(int i=1;i<=n;i++)
			p[i]=i;
		int cnt=0;
		do{
			int ma=0;
			for(int i=1;i<=k;i++)
				ma=max(ma,p[i]);
			for(int i=k+1;i<=n;i++)
				if(p[i]>ma){
					if(p[i]==n)cnt++;
					break;
				}
		}while(next_permutation(p+1,p+1+n));
		if(cnt>ans) res=k,ans=cnt;
	}
	cout<<n<<" "<<res<<'\n';
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// int __;cin>>__;
	// while(__--)
	// for(int i=1;i<=12;i++)
	// 	solve(i);
	int n=9000;
	int m=3311;
	
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}