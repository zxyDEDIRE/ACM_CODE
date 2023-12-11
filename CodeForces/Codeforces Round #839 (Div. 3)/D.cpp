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
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int l=0,r=1e10;
	int fa=0,fb=0;
	for(int i=2;i<=n;i++)
	{
		if(p[i-1]>p[i])
		{
			l=max(l,(p[i]+p[i-1]+1)/2);
		}
		else if(p[i-1]<p[i])
		{
			r=min(r,(p[i]+p[i-1])/2);
		}
	}
	if(l>r)cout<<-1<<endl;
	else cout<<l<<endl;

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
5 3 4 5
5 3 >=4
3 4 <=4
4 5

3 4

*/