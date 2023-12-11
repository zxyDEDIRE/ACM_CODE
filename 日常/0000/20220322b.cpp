#include<bits/stdc++.h>
using namespace std;
using int64 = long long;



void solve()
{
	int n;
	int64 num=0;
	cin>>n;
	vector<int64>a,b;
	map<int64,int>mp;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		mp[x]++;
		num+=x;
	}

	int cnt=n;
	a.push_back(num);
	while(a.size()&&a.size()<=cnt&&cnt)
	{
	//	cout<<"*";
		for(auto x:a)
		{
			if(mp[x])mp[x]--,cnt--;
			else
			{
				if(x>=2)
				{
					b.push_back(x/2);
					b.push_back(x-x/2);
				}
				else b.push_back(1);
			}
		}
		a=b;
		b.clear();
	}
	if(a.size())cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int __;cin>>__;
	while(__--)solve();
}