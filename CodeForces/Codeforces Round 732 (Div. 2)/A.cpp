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
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	queue<pii>fa;
	queue<pii>fb;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i])
			fa.push({i,a[i]-b[i]}),t+=a[i]-b[i];
		if(a[i]<b[i])
			fb.push({i,b[i]-a[i]}),t+=a[i]-b[i];
	}
	if(t!=0){
		cout<<-1<<endl;
		return ;
	}
	vector<pii>v;
	while(fa.size())
	{
		auto [x,num_x]=fa.front();fa.pop();
		auto [y,num_y]=fb.front();fb.pop();
		// cout<<x<<" "<<y<<endl;
		v.push_back({x,y});
		if(num_x>1)fa.push({x,num_x-1});
		if(num_y>1)fb.push({y,num_y-1});
	}
	cout<<v.size()<<endl;
	for(auto [x,y]:v)
		cout<<x<<" "<<y<<endl;
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
abcdef
uuuuuu
kekeke
ekekek
xyzklm

xbcklf
eueueu
ayzdem
ukukuk
*/