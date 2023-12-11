#include<bits/stdc++.h>
using namespace std;
long long n;
long long get(long long a){
    long long res=0;
    while(a){
        res+=a/5;
        a/=5;
    }
    return res;
}
void solve()
{
    long long n;
    cin>>n;
    long long ans=0;
    if(n%2==0)
        for(int i=0;i<=n;i+=2){
            ans+=get(i);
        }
    else
        for(int i=1;i<=n;i+=2) ans+=get(i);
    cout<<ans<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
