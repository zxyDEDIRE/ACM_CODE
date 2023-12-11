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
const int N=2e5+10;
int p[maxn];
int n;
struct ST{
	int f[N][30];
	int h[N][30];
	void init()
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=h[i][0]=p[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				h[i][j]=min(h[i][j-1],h[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int qma(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
	int qmi(int l,int r)
	{
		int k=log2(r-l+1);
		return min(h[l][k],h[r-(1<<k)+1][k]);
	}
}st;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	st.init();
	int l=1,r=n;
	while(l<r)
	{
		while(l<=r&&(p[l]==st.qma(l,r)||p[l]==st.qmi(l,r)))
			l++;
		while(r>=l&&(p[r]==st.qma(l,r)||p[r]==st.qmi(l,r)))
			r--;
		if(l>=r)break;
		int ma=st.qma(l,r);
		int mi=st.qmi(l,r);
		if(p[l]!=ma&&p[l]!=mi&&p[r]!=ma&&p[r]!=mi)
			break;
	}
	if(l<r){
		cout<<l<<" "<<r<<endl;
	}
	else cout<<-1<<endl;
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
6
2 3 6 5 4 1

7
1 2 4 3 5 7 6
1 7         2

*/