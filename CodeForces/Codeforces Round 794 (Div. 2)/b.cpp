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
	int fl=0,ma=-1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(ma>p[i])
		{
			cnt++;
			ma=-1;
		}
		else 
		ma=max(ma,p[i]);
	}
	cout<<cnt<<endl;
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