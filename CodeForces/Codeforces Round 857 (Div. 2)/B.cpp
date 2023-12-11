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
int f(int x){
	if(x==0)return 0;
	if(x%2==0){
		int y=x/2;
		if(y%2==1)return (y+1)/2*2;
		else
		{
			int a=y+1;
			int b=y-1;
			return (a+1)/2+(b+1)/2;
		}
	}
	else return (x+1)/2;
}
void solve()
{
	cin>>n;
	int ma=0;
	int _cnt=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==1)
		{
			cnt++;
			ma=max(ma,f(_cnt)+cnt);
		}
		else
		{
			_cnt+=cnt;
			cnt=0;
		}
	}
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
8 4 4
3 5
2 3

*/