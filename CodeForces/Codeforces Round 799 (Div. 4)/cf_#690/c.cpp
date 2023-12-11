#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int n;
void solve()
{
	cin>>n;
	if(n>45){
		cout<<"-1"<<endl;
		return ;
	}
	int s=0;
	vector<int>v;
	for(int i=9;i>=1;i--)
	{
		if(s+i>=n)
		{
			v.push_back(n-s);
			break;
		}
		v.push_back(i);
		s+=i;
	}
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i];
	cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}