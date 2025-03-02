#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e8;
int l,r;
void solve()
{
	cin>>l>>r;
	int len=r-l;
	for(int i=0;i<=len;i++)
	{
		for(int j=0;j<=i;j++)
		{
			int a=l+j;
			int b=r-(i-j);
			if(__gcd(a,b)==1){
				cout<<b-a<<endl;
				return ;
			}
		}
	}
}
signed main(){
	int __;
//	cin>>__;
	__=1;
	while(__--)solve();
}
