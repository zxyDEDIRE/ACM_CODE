#include<bits/stdc++.h>
using namespace std;
const int N=100;
#define int long long
int mp[N][N];
int n,m;

long long get(long long n)
{
	return n*(n+1)/2;
}

signed main()
{
	cin>>n>>m;
	long long tp=get(n)*(get(m));
	if(tp&1){
		cout<<"NO"<<endl;
		return 0;
	}
	int len=n/2;
	
	int more=(len+1)*(n-len);

	int a=get(m)*get(len);
	int b=get(m)*get(n-len-1);
	int c=get(m)*1;
	int tot=a+b+c;

	cout<<"now: "<<tp/2<<endl;
	cout<<a<<" "<<b<<" "<<c<<" "<<a+b+c<<endl;

	tp/=2;
	int now=0;
	for(int i=1;i<=n;i++)
	{
		int x=(now+1)*more;
		int y=m-i+1;
		if(tot+x-y<=tp){
			// cout<<tot<<endl;
			cout<<"0 ",tot=tot+x-y,now++;
		}
		else cout<<"1 ",now=0;
	}
	cout<<endl;
	cout<<tot<<endl;

}
