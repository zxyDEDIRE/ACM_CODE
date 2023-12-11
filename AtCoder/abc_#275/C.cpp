/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=100;
char mp[maxn][maxn];
vector<pii>v;
int n=9;
double dis(int x,int y){
	return hypot(v[x].first-v[y].first,v[x].second-v[y].second);
}
bool ok(int x){
	return mp[v[x].first][v[x].second]=='#';
}
bool check(int a,int b,int c,int d)
{
	if(!ok(a)||!ok(b)||!ok(c)||!ok(d))return 0;
	double ab=dis(a,b);
	double ac=dis(a,c);
	double ad=dis(a,d);
	double bc=dis(b,c);
	double bd=dis(b,d);
	double cd=dis(c,d);
	// if(ab==bc&&bc==cd&&cd==ad)return 1;
	if(ab==bd&&bd==cd&&cd==ac&&ad==bc)return 1;
	if(ab==bc&&bc==cd&&cd==ad&&ac==bd)return 1;
	if(ac==bc&&bc==bd&&bd==ad&&ab==cd)return 1;
	return 0;
}
void f(int x){
	cout<<v[x].first<<" "<<v[x].second<<endl;
}
void solve()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j],v.push_back({i,j});
	int ans=0;
	// cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			for(int I=j+1;I<v.size();I++)
			{
				for(int J=I+1;J<v.size();J++)
				{
					if(check(i,j,I,J)){
						// f(i);
						// f(j);
						// f(I);
						// f(J);
						// cout<<endl;
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
.#.......
#.#......
.#.......
.........
....#.#.#
.........
....#.#.#
........#
.........

##.#.....
###......
.##......
#..#.....
.........
.........
.........
.........
.........

*/