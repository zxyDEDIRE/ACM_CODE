/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n,s;
void solve()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);

	int c[10];c[1]=c[2]=2;c[3]=3;

	int ma=0;
	int len=0;

	int x=s;
	do{
		x=s;
		int fl=1;
		for(int i=1;i<=n;i++)
		{
			int flag=0;
			if(p[i]<x)x+=(p[i]/2),len=max(len,i);
			else
			{
				while(p[i]>=x&&fl<=3)
					x*=c[fl],fl++;
				if(p[i]<x)x+=(p[i]/2),len=max(len,i);
				else flag=1;
			}
			if(flag)break;
		}
		while(fl<=3)
			x*=c[fl],fl++;
		ma=max(ma,x);
	}while(next_permutation(c+1,c+1+3));

	cout<<len<<endl;
	// cout<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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

*/