#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	vector<int>v[k+1],u[k+1];
	for(int i=1;i<=n;i++){
		cin>>p[i];
		v[i%k].push_back(p[i]);
		u[i%k].push_back(i);
	}
	for(int i=0;i<k;i++)
	{
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();j++)
		{
			p[u[i][j]]=v[i][j];
		}
	}
	for(int i=1;i<n;i++)
	{
		if(p[i]>p[i+1]){
			cout<<"No"<<endl;
			return ;
		}
	}
	cout<<"Yes"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    solve();
    return 0;
}
/*
5 2
3 4 1 3 4

3 1 4
4 3


3 4 1 3 4
3 3
4 4
1
*/