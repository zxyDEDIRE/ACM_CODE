#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int p[maxn],cnt;
int a,b;
void doit(int n)
{
	if(((int)sqrt(n)*(int)sqrt(n))!=n)return ;
	int t=10;
	while(2)
	{
		int a=n/t;
		int b=n%t;
		if(!a)break;
		t*=10;
		if(a==0||b==0)continue;
		if(((int)sqrt(a)*(int)sqrt(a))==a&&((int)sqrt(b)*(int)sqrt(b))==b){
			cout<<n<<endl;//,cout<<a<<" "<<b<<endl;
		}
		
	}
}
signed main()
{
	cin>>a>>b;
	for(int i=a;i<=b;i++)
		doit(i);
}
