#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int cnt=0,fl=0;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int t=++mp[p[i]];
		if(t>cnt)
		{
			cnt=t;
			fl=p[i];
		}
	}
	sort(p+1,p+1+n);

	if(n%2==1){
		cout<<"NO"<<endl;
		return ;
	}

	for(int i=1;i<=n/2;i++){
		if(p[i]==p[i+n/2]){
			cout<<"NO"<<endl;
			return ;
		}
		if(i+1<=n/2&&p[i+1]==p[i+n/2]){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n/2;i++){
		cout<<p[i]<<" "<<p[i+n/2]<<" ";
	}
	cout<<endl;
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
0101

2 4 2 4 2 4 3 4 3 4 3 4 3 4 3 3 

*/