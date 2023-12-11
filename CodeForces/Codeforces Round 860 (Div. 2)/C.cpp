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
#define int long long
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
int a[maxn],b[maxn],s[maxn];
int n;
int lcm(int x,int y){
	return x*y/__gcd(x,y);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s[i]=a[i]*b[i];
	}
	int ans=0;
	int r=1;
	for(int i=1;i<=n;i++)
	{
		ans++;
		int g=s[i];
		int l=b[i];
		r=i;
		while(r+1<=n)
		{
			int _g=__gcd(g,s[r+1]);
			int _l=lcm(l,b[r+1]);
			if(_g%_l!=0)break;
			r++;
			g=_g;
			l=_l;
		}
		i=r;
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
/*
20 3 12
6 2  12


60
12
12


12

*/