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
void solve()
{
	int n,a1,a2,b1,b2,fl=2,m;
	a1=a2=b1=b2=0;
	cin>>n;
	m=0;
	for(int i=1;;i++)
	{
		int now=min(i,n);
		if(fl<=2)
		{
			if(m&1)
			{
				a1+=(now+1)/2;
				a2+=now/2;
			}
			else
			{
				a2+=(now+1)/2;
				a1+=now/2;
			}
		}
		else
		{
			if(m&1)
			{
				b1+=(now+1)/2;
				b2+=now/2;
			}
			else
			{
				b2+=(now+1)/2;
				b1+=now/2;
			}
		}
		m+=now;
		fl++;
		if(fl==5)fl=1;
		n-=now;
		if(!n)break;
	}
	cout<<a2<<" "<<a1<<" "<<b2<<" "<<b1<<endl;
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