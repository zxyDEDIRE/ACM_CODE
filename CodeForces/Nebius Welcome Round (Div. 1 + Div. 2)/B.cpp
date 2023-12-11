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
int n,k,d,w;
void solve()
{
	cin>>n>>k>>d>>w;
	//w wait pi pi+1,pi+w;
	//d pi+1,pi+2,pi+d;
	//one pack k does
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int ans=0;
	int now=0;
	int cnt;
	for(int i=1,j=0;i<=n;)
	{
		now=p[i]+w;
		cnt=0;
		j=i;
		while(j<=n&&p[j]-now<=d&&cnt<k)
			j++,cnt++;
		ans++;
		i=j;
	}
	cout<<ans<<endl;
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