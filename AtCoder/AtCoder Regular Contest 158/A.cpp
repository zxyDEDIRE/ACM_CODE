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
void solve()
{
	int p[4];
	cin>>p[1]>>p[2]>>p[3];
	int sum=p[1]+p[2]+p[3];
	if(abs(p[2]-p[1])%2==1||abs(p[3]-p[2])%2==1){cout<<-1<<endl;return ;}
	if(sum%3!=0){cout<<-1<<endl;return ;}
	sum=sum/3;
	int ma=0;
	ma=max(ma,abs(p[1]-sum)/2);
	ma=max(ma,abs(p[2]-sum)/2);
	ma=max(ma,abs(p[3]-sum)/2);
	cout<<ma<<endl;
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
6 3 3
3 3 6
3 5 4
*/