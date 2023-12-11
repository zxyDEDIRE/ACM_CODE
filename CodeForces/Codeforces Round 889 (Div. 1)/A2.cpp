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
int p[maxn];
int n;
bool f(int x,int y){
	if(x<0&&y>0)return 1;
	if(x>0&&y<0)return 1;
	return 0;
}
bool s(int x,int y){
	if(x<0&&y<0)return 1;
	if(x>0&&y>0)return 1;
	return 0;
}
void solve()
{
	cin>>n;
	// n=20;
	int ma=0,fl=1;
	int cnta=0,cntb=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		// if(i<=8)p[i]=20;
		// else p[i]=-1;
		if(abs(p[i])>ma)
		{
			ma=abs(p[i]);
			fl=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s(p[i],p[fl]))cnta++;
		if(f(p[i],p[fl]))cntb++;
	}
	vector<pii>ans;
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" \n"[i==n];
	// cout<<"fl "<<fl<<" "<<p[fl]<<endl;
	// cout<<"cnt "<<cnta<<" "<<cntb<<endl;

	if(cntb<=12)
	{
		for(int i=1;i<=n;i++)
			if(f(p[i],p[fl])){
				p[i]+=p[fl];
				ans.push_back({i,fl});
			}

		if(p[fl]>=0){
			for(int i=2;i<=n;i++){
				p[i]+=p[i-1];
				ans.push_back({i,i-1});
			}
		}
		else{
			for(int i=n-1;i>=1;i--){
				p[i]+=p[i+1];
				ans.push_back({i,i+1});
			}
		}
	}
	else 
	{
		int MA=0,_fl=0;
		for(int i=1;i<=n;i++)
			if(f(p[i],p[fl])&&abs(p[i])>MA){
				MA=p[i];
				_fl=i;
			}
		// cout<<"MA "<<MA<<endl;
		// cout<<"_fl "<<_fl<<" "<<p[_fl]<<endl;
		while(abs(p[_fl])<20)
		{
			p[_fl]+=p[_fl];
			ans.push_back({_fl,_fl});
		}
		// cout<<"SIZE "<<ans.size()<<endl;
		// for(int i=1;i<=n;i++)
		// 	cout<<p[i]<<" \n"[i==n];
		int T=p[fl];
		for(int i=1;i<=n;i++)
			if(s(T,p[i])){
				// cout<<"S "<<p[fl]<<" "<<p[i]<<endl;
				p[i]+=p[_fl];
				ans.push_back({i,_fl});
			}
		if(p[_fl]>0){
			for(int i=2;i<=n;i++){
				p[i]+=p[i-1];
				ans.push_back({i,i-1});
			}
		}
		else{
			for(int i=n-1;i>=1;i--){
				p[i]+=p[i+1];
				ans.push_back({i,i+1});
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" \n"[i==n];
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans)
		cout<<x<<" "<<y<<endl;


}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
12+19

20 -1 -1 -1 
*/