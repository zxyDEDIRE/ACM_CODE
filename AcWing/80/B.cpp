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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int n;
int len(int x){
	int cnt=0;
	while(x)cnt++,x/=10;
	return cnt;
}
void solve()
{
	cin>>n;
	int s = len(n);
	if(s&1)
	{
		s=(s+1)/2;
		for(int i=1;i<=s;i++)
			cout<<4;
		for(int i=1;i<=s;i++)
			cout<<7;
		cout<<endl;
	}
	else
	{
		s=s/2;
		std::vector<int> v;
		for(int i=1;i<=s;i++)
			v.push_back(4);
		for(int i=1;i<=s;i++)
			v.push_back(7);
		do{
			int x=0;
			for(auto i:v)
				x=x*10+i;
			if(x>=n){
				cout<<x<<endl;
				return ;
			}
		}while(next_permutation(v.begin(),v.end()));
		s++;
		for(int i=1;i<=s;i++)
			cout<<4;
		for(int i=1;i<=s;i++)
			cout<<7;
		cout<<endl;
	}

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