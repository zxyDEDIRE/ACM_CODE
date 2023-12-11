#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int x,a,b;
int main()
{
	cin>>a>>b>>x;
	int flag=0;
	for(int i=0;i*a<=x;i++)
	{
		if((x-i*a)%b==0){
			flag=1;
			cout<<i<<" "<<(x-i*a)/b<<endl;
			return 0;
		}
	}
	if(!flag)cout<<-1;
}