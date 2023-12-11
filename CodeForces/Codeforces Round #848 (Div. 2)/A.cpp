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
int n,fl;
void solve()
{
	cin>>n;
	fl=0;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		sum+=p[i];
		if(i>1)
		{
			if(p[i]==-1&&p[i-1]==-1)
				fl=max(fl,2);
			if(p[i]+p[i-1]==0)
				fl=max(fl,1);
		}
	}
	if(fl==2)sum+=4;
	else if(fl==0)sum-=4;
	cout<<sum<<endl;
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