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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
int A(int a,int b,int h){
	h-=min(h,a);
	int t=(h+(a-b-1))/(a-b);
	return t+1;
}
void solve()
{
	int l=1,r=1e18;
	int q;cin>>q;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int a,b,n;
			cin>>a>>b>>n;
			int rr=min(INF,(a-b)*(n-1)+a);
			int ll=max(1ll,(a-b)*(n-1)+1);
			if(n>=2)
			ll=max(ll,(a-b)*(n-2)+a+1);
			// cout<<"lr: "<<l<<" "<<r<<endl;
			ll=max(l,ll);
			rr=min(r,rr);
			if(ll>rr){
				cout<<0<<" ";
			}
			else{
				l=ll;
				r=rr;
				cout<<1<<" ";
			}
			// cout<<l<<" "<<r<<endl;
			// cout<<ll<<" "<<rr<<endl;
			// cout<<"A"<<" ";
		}
		else
		{
			int a,b,n;
			cin>>a>>b;
			int mi=A(a,b,l);
			int ma=A(a,b,r);
			// cout<<"A";
			// cout<<l<<" "<<r<<" "<<mi<<" "<<ma<<endl;
			// cout<<mi<<" "<<ma<<endl;
			if(mi!=ma)cout<<-1<<" ";
			else cout<<mi<<" ";
		}
	}
	cout<<endl;
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