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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,id,y;
}p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x,p[i].id=i;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.x<b.x;
	});
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i].x<<" "<<p[i].id<<endl;
	for(int i=1;i<=n;i++)
		p[i].y=i;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.id<b.id;
	});
	for(int i=1;i<=n;i++)
		cout<<p[i].x<<" "<<p[i].y<<endl;
	vector<int>v;
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		int x=i;
		int y=p[i].y;
		if(x==y)continue;
		if(i-1)
			v.push_back(i-1);
		ma=max(ma,y-x+1);
		i=y;
	}
	v.push_back(n);
	int ans=n;
	for(auto i:v){
		cout<<i<<" ";
		ans=lcm(ans,i);
	}cout<<endl;
	cout<<"ans "<<ans<<endl;
	cout<<"ma "<<ma<<endl;

	int cnt=0;
	for(int i=1;i*i<=ans;i++)
		if(n%i==0)
		{
			if(i>=ma&&i<=n)cnt++;
			if((n/i!=i)&&(n/i)>=ma&&i<=n)cnt++;
		}
	cout<<"cnt "<<cnt<<endl;


}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
3 4

*/
/*
6
121 117 114 105 107 111

4
114 514 1919 810

13
1 1 4 5 1 4 1 9 1 9 8 1 0
*/