/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
struct node{
	int id,num;
}p[maxn];
int n,x,y;
void solve()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>p[i].num,p[i].id=i;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.num>b.num;
	});
	vector<int>a,b;
	int s1=x,s2=y;
	for(int i=1;i<=n;i++)
	{
		if(s1<=s2)a.push_back(p[i].id),s1+=x;
		else b.push_back(p[i].id),s2+=y;
	}
	cout<<a.size()<<" ";
	for(auto i:a)
		cout<<i<<" ";cout<<endl;
	cout<<b.size()<<" ";
	for(auto i:b)
		cout<<i<<" ";cout<<endl;

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