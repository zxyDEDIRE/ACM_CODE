/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y;
}p[4];
void solve()
{
	for(int i=1;i<=3;i++)
		cin>>p[i].x>>p[i].y;
	int fa=0;
	if(p[2].x>=p[1].x)fa++;
	else fa--;

	if(p[3].x>=p[1].x)fa++;
	else fa--;

	int fb=0;
	if(p[2].y>=p[1].y)fb++;
	else fb--;

	if(p[3].y>=p[1].y)fb++;
	else fb--;

	int ans_1=1;
	if(fa==2)ans_1=max(ans_1,min(p[2].x,p[3].x)-p[1].x+1);
	else if(fa==-2)ans_1=max(ans_1,p[1].x-max(p[2].x,p[3].x)+1);

	int ans_2=1;
	if(fb==2)ans_2=max(ans_2,min(p[2].y,p[3].y)-p[1].y+1);
	else if(fb==-2)ans_2=max(ans_2,p[1].y-max(p[2].y,p[3].y)+1);

	cout<<ans_1+ans_2-1<<endl;
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
1
1 1
5 4
5 5

*/