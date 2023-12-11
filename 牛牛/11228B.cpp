#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
ll ans=0;
int n;
int main()
{
	cin>>n;
	int t=1;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==0)p[i]=t,ans+=t;
		else ans+=p[i];
		t=max(t+1,p[i]+1);
		if(p[i]<=p[i-1]){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
}