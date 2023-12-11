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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int a=0,b=0,c=0,d=0;
void solve()
{
	int n=10;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='#')
			{
				if(a==0)a=i;
				else a=min(a,i);
				if(b==0)b=i;
				else b=max(b,i);
				if(c==0)c=j;
				else c=min(c,j);
				if(d==0)d=j;
				else d=max(d,j);
			}
		}
	}
	cout<<a<<" "<<b<<endl;
	cout<<c<<" "<<d<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}