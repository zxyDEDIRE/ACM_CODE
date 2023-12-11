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
void solve()
{
	int n,m;
	cin>>n>>m;
	if(m==0){
		if(n==1)cout<<"0 0"<<endl;
		else cout<<"-1 -1"<<endl;
		return ;
	}
	if(m>n*9){
		cout<<"-1 -1"<<endl;
		return ;
	}
	vector<int>a(n,0),b(n,0);
	int x;
	x=m;
	for(int i=0;i<n;i++)
		a[i]=min(9,x),x-=a[i];
	x=m;
	b[0]=1;x--;
	for(int i=n-1;i>=0;i--)
		b[i]+=min(9,x),x-=b[i];
	for(auto i:b)
		cout<<i;
	cout<<" ";
	for(auto i:a)
		cout<<i;
	cout<<endl;
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