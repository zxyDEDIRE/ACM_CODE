#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<pii>v;
int n,m;
void solve()
{
	cin>>n>>m;
	int l=0,r=0,flag=0;
	for(int i=1;i<=n;i++){
		v.clear();
		for(int j=1,x;j<=m;j++){
			cin>>x;
			v.push_back(pii(x,j-1));
		}
		if(flag==0&&l==r)
		{
			sort(v.begin(),v.end(),[&](pii a,pii b){return a.first<b.first;});
			int fl=0;
			for(int j=0;j<m;j++){
				int x=v[j].second;
				if(x!=j)
				{
					if(v[x].second!=j||fl>1)flag=1;
					else l=min(x,j),r=max(x,j),fl++;
				}
			}
		}
		else if(l!=r&&flag==0)
		{
			swap(v[l],v[r]);
			for(int j=0;j<m-1;j++)
				if(v[j+1].first<v[j].first)flag=1;
		}
	//	cout<<l<<" "<<r<<endl;
	}
	if(flag==1)cout<<-1<<endl;
	else cout<<l+1<<" "<<r+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}
/*
2 5
1 3 2 4 5
1 3 2 4 5

*/