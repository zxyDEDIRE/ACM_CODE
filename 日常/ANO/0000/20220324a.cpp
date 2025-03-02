#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
const int maxn=1e6+7;;
void solve()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,fa=0,fb=0;
	cin>>n;
	vector<int>v(n+10);
	map<int,int>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(v[i]==0)fa=1;
		if(v[i]==1)fb=1;
		m[v[i]]++;
	}
	if(!fb){
		cout<<"Yes"<<endl;
		return ;
	}
	if(fa&&fb){
		cout<<"No"<<endl;
		return ;
	}
	sort(v.begin(),v.end());
	for(int i=1;i<n;i++)
	{
		if(v[i]==1)continue;
		if(v[i]-v[i-1]==1){
			cout<<"No"<<endl;
		}
	}
	cout<<"Yes"<<endl;
}
signed main(){
	int __;
	cin>>__;
	while(__--)solve();
}
/*

*/