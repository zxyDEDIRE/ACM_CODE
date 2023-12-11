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
const int maxn=2e6+100;
bitset<maxn>dpa,dpb;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int ma=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],ma=max(ma,p[i]);
	sort(p+1,p+1+n);
	dpa.reset();
	dpb.reset();
	if(p[1]!=1){
		cout<<"NO"<<endl;
			return ;
	}
	dpa[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(dpa[p[i]]!=1){
			cout<<"NO"<<endl;
			return ;
		}
		dpb=dpa|(dpa<<(p[i]));
		dpa=dpb;
	}
	cout<<"YES"<<endl;
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