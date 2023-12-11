/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=n;i>=2;i--)
		p[i]=p[i]-p[i-1];
	p[1]=INF;
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" ";
	// cout<<endl;
	int len=0,fl=1,ma=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==fl){
			len++;
			if(fl<0)fl=1-fl;
			else fl=-fl-1;
		}
		else if(p[i]==1)len=1,fl=-2;
		else len=0,fl=1;
		ma=max(ma,len);
	}
	cout<<ma+1<<endl;
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
a a+1 a-1 a+2 a-2
0 1 -2 3 -4
9
3 4 2 5 6 7 5 8 4
*/