/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int a[maxn],b[maxn];
int n;
void solve()
{
	cin>>n;
	priority_queue<int>s,t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		while(a[i]%2==0)a[i]/=2;
		s.push(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		t.push(b[i]);
	}
	int flag=0;
	while(!s.empty())
	{
		int x=s.top();s.pop();
		int y=t.top();t.pop();
		if(x==y)continue;
		y/=2;
		if(y==0)
		{
			flag=1;
			break;
		}
		s.push(x);
		t.push(y);
	}
	if(flag)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}