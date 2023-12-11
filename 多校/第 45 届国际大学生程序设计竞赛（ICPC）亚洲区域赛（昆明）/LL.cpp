#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int col[N];
int a[N];
set<int>s;
void solve()
{	
	cin>>n;
	s.clear();
	int id=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		auto t=s.lower_bound(a[i]);
		if(t==s.begin()){
			col[a[i]]=++id;
			s.insert(a[i]);
		}else{
			t=prev(t);
			int v=*t;
			col[a[i]]=col[v];
			s.erase(v);s.insert(a[i]);
		}
	}
	cout<<id<<'\n';
	for(int i=1;i<=n;i++){
		cout<<col[a[i]]<<" ";
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
4
1 3 2 4

5
6
1 2 5 3 6 4
*/