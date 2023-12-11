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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	map<int,int>m1;
	for(int i=1;i<=n;i++)
		cin>>p[i],m1[p[i]]++;
		cout<<"- 0"<<endl;
	while(1)
	{
		map<int,int>m2;
		for(int i=1;i<=n;i++)
			cin>>p[i],m2[p[i]]++;
		int flag=-1;
		int ok=-1;
		for(auto [x,y]:m2)
			if(y>m1[x]&&y==1){
				ok=x;
			}
		if(ok)
		{
			for(int i=1;i<=n;i++)
				if(p[i]==ok){
					cout<<"! ";
					cout<<i<<endl;
					return ;
				}
		}
		for(auto [x,y]:m2)
			if(m1[x]<y){
				flag=x;
				break;
			}
		for(auto [x,y]:m1)
			cout<<"m1 "<<x<<" "<<y<<endl;
		for(auto [x,y]:m2)
			cout<<"m2 "<<x<<" "<<y<<endl;
		m1=m2;
		if(flag==-1){
			cout<<"- 0"<<endl;
			continue;
		}
		cout<<"FLA "<<flag<<endl;
		vector<int>v;
		for(int i=1;i<=n;i++)
			if(p[i]!=flag)v.push_back(i);
		n-=(int)v.size();
		if(n==1){
			cout<<"! ";
			for(int i=1;i<=n;i++)
				if(p[i]==flag){
					cout<<i<<endl;
					return ;
				}
		}
		else
		{
			cout<<"- ";
			for(auto i:v)
				cout<<i<<" ";
			cout<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}