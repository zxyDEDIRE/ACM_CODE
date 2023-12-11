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
vector<int>a,b;
int p[maxn];
int n,k,c;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]>0)a.push_back(p[i]);
		else if(p[i]<0)b.push_back(-p[i]);
		else c++;
	}
	sort(a.begin(),a.end(),[&](int a,int b){
		return a>b;
	});
	sort(b.begin(),b.end(),[&](int a,int b){
		return a>b;
	});
	int l=0,r=0;
	ll ans=0;
	while(k)
	{
		int x=-INF;
		int y=-INF;
		if(l<(int)a.size()-1){
			x=a[l]*a[l+1];
		}
		if(r<(int)b.size()-1)
			y=b[r]*b[r+1];
		int ma=max(x,y);
		int mi=min(x,y);
		if(ma==-INF)break;
		else if(ma==x){
			ans+=x;
			l+=2;
		}
		else if(ma==y){
			ans+=y;
			r+=2;
		}
		k--;
	}
	while(c&&k)
	{
		if(l<=a.size()-1)
			c--,k--;
		else if(r<=b.size()-1)
			c--,k--;
	}
	if(k)
	{
		ans+=a.back()*b.back()*-1;
	}
	cout<<ans<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
6 3
2 2 2
-2 -2 -2
0 0 
*/