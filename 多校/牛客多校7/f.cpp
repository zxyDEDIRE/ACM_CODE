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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int p[maxn];
int s[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int cnt=0;
	int top=0;
	for(int i=1;i<=n;i++)
	{
		if(top==0)s[++top]=p[i];
		else
		{
			int x=s[top];
			if((x==p[i])||(x+p[i])==m)
			{
				top--;
				cnt++;
			}
			else s[++top]=p[i];
		}
	}
	int l=1,r=top;
	while(l<r)
	{
		if(s[l]==s[r]||s[l]+s[r]==m)cnt++,l++,r--;
		else break;
	}
	cout<<cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}
/*
5 3
1 2 9 1 2
*/