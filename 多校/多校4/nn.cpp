/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int t[50];
int p[maxn];
int n;
int sum,psum;
void F(int x)
{
	vector<int>v;
	int y=0;
	while(x)
	{
		t[y++]+=x%2;
		x>>=1;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		F(p[i]);
	}

	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		int s=0;
		int fl=0;
		for(int j=0;j<=15;j++)
		{	
			if(t[j])fl=1;
			if(t[j])s+=(1<<j),t[j]--;
			
		}
		if(!fl)break;
		v.push_back(s);
	}
	while(v.size()<n)
		v.push_back(0);



    for(int i=0;i<n;i++)
    {
    	sum+=v[i];
    	psum+=v[i]*v[i];
    }

    int up=n*psum-sum*sum;
    int down=n*n;

    // cout<<up<<" "<<down<<endl;

    if(up==0)
    {
        cout<<"0/1";
        return ;
    }
    if(up<0)
    {
    	cout<<"-";
    	up=-up;
    }
    int t=__gcd(up,down);
    up/=t;
    down/=t;
    cout<<up<<"/"<<down;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
