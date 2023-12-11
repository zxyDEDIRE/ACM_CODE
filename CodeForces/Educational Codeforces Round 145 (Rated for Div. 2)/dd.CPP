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
const int A=1000000000000;
const int B=1000000000001;
int a[maxn];
int b[maxn];
string str;
int n;
void solve()
{
	cin>>str;str=" "+str;
	n=str.size()-1;
	a[0]=b[n+1]=0;
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+(str[i]=='1'?1:0);
	for(int i=n;i>=1;i--)
		b[i]=b[i+1]+(str[i]=='0'?1:0);
	int mi=LLONG_MAX;
	for(int i=0;i<=n;i++)
	{
		int now=B*(a[i]+b[i+1]);
		// cout<<i<<" "<<a[i]<<" "<<b[i+1]<<endl;
		mi=min(mi,now);
		if(str[i]=='1'&&str[i+1]=='0')
			now=B*(a[i]+b[i+1]-2)+A,mi=min(mi,now);
	}
	cout<<mi<<endl;
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