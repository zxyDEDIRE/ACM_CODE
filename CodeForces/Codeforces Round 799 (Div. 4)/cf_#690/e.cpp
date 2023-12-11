#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=2e5+100;
int p[maxn];
int a[maxn];
int b[maxn];
int n,ans;
void solve()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++)
		b[i]=a[i]=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		b[p[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		b[x]--;
		for(int v=-2;v<=2;v++)
		{
			for(int u=-2;u<=2;u++)
			{
				int y=x+v;
				int z=x+u;
				int mi=min({x,y,z});
				int ma=max({x,y,z});
				if(ma-mi>2||mi<1||ma>n)continue;
				ans+=a[y]*b[z];
			}
		}
		a[x]++;
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}