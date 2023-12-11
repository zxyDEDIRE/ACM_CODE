/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=long long;
using ll=long long;
const ull mod=1000000000039;
const ull prime=233317;
const ull base=114514;
class StringHash{
public:
	vector<ull>h;
	vector<ull>bas;
	StringHash():h(1),bas(1,1){}
	void push_back(char ch){
		h.push_back((h.back()*base+ch)%mod + prime);
		bas.push_back(bas.back()*base%mod);
	}
	ull get(int l,int r){
		return (h[r] + __int128(h[l])*(mod-bas[r-l]))%mod;
	}
};
int n,m;
void solve()
{
	cin>>n>>m;
	string str;
	cin>>str;
	vector<pair<ll,ll>>q;
	for(int i=1;i<=m;i++)
	{
		ll op;
		cin>>op;
		if(op==1){
			char x;cin>>x;
			str.push_back(x);
		}
		else
		{
			ll k;
			cin>>k;
			q.push_back({(ll)(str.size()),k});
		}
	}
	int N=str.size();
	StringHash hs,rhs;
	for(int i=0;i<N;i++)
		hs.push_back(str[i]);
	for(int i=N-1;i>=0;i--)
		rhs.push_back(str[i]);
	for(auto [n,k]:q)
	{
		k %= (n*2);
		int flag=1;
		if(k>n)
		{
			if(hs.get(0,2*n-k) != hs.get(k-n,n))flag=0;
			if(hs.get(0,k-n)!=rhs.get(N-k+n,N))flag=0;
			if(hs.get(2*n-k,n)!=rhs.get(N-n,N-2*n+k))flag=0;
		}
		else if(k==n)flag=1;
		else if(k>0)
		{
			//长度为k的前缀与后缀是否相同
			if(hs.get(0,k)!=hs.get(n-k,n))flag=0;
			if(hs.get(0,n-k)!=rhs.get(N-n+k,N))flag=0;
			if(hs.get(k,n)!=rhs.get(N-n,N-k))flag=0;
		}
		else {
			//前n长字符串为回文
			if(hs.get(0,n)!=rhs.get(N-n,N))flag=0;
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
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