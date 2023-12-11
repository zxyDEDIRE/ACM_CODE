/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<pii>v;
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	int t;
	if(n%2==0)t=n/2;
	else t=min(n-(n/2),n-(n/2+1));
	if(k>t){
		cout<<-1<<endl;
		return ;
	}


	int T=n/(k*2)-1;
	for(int ii=1;ii<=T;ii++)
	{
		int l=2*k*(ii-1)+1;
		int r=2*k*ii;

		int x=l+k;
		for(int i=l;i<=r;i++)
		{
			p[i]=x;
			x++;
			if(x>r)x=l;
		}

	}
	int l=2*k*T+1;
	int r=n;
	int x=l+k;
	for(int i=l;i<=r;i++)
	{
		p[i]=x;
		x++;
		if(x>n)x=l;
	}


	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;




}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 2 3 4 5 6 7
3 4 1 6 7 2 5

*/