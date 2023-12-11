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
const int mod=998244353;
const int INF=1e18+7;
int Fgcd(int a,int b){
	return b==0?a:Fgcd(b,a%b);
}
 
void solve()
{
	int a,b,x; 
	cin>>a>>b;
	x=abs(a-b);
	if(Fgcd(a,b)!=1){
		cout<<0<<endl;
		return ;
	}
	if(a==1&&b==1){
		cout<<1<<endl;
 		return ;
	}
	if(x==1)
	{
		cout<<-1<<endl;
		return ;
	}
	vector<int>v;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			v.push_back(i);
			v.push_back(x/i);
		}
	v.push_back(x);
	int ans=INF;
	for(auto i:v)
    {
        ans=min(ans,i-(a%i));
    }
	if(ans==INF)cout<<-1<<endl;
	else cout<<ans<<endl;
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