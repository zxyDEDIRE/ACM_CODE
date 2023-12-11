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
void solve()
{
	int n;
	cin>>n;
	if(n==0){
		cout<<"b"<<endl;
		return ;
	}
	vector<int>v;
	int x=n;
	while(x){
		v.push_back(x%3);
		x/=3;
	}
	for(int i=1;i<=10;i++)
		v.push_back(0);

	for(int i=0;i<v.size();i++)
	{
		if(v[i]==3)v[i+1]++,v[i]=0;
		else if(v[i]==-3)v[i+1]--,v[i]=0;
		else if(v[i]==2)v[i+1]++,v[i]=-1;
		else if(v[i]==-2)v[i+1]--,v[i]=1;
	}
	while(v.back()==0)v.pop_back();
	reverse(v.begin(),v.end());
	for(auto i:v)
		if(i==1)cout<<"w";
		else if(i==-1)cout<<"m";
		else cout<<"b";
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