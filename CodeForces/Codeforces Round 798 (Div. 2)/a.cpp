#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string a,b,c;
int n,m,k;
void solve()
{
	cin>>n>>m>>k>>a>>b;
	int i=0,j=0,fl=0,cnt=0;
	c="";
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	while(i!=n&&j!=m)
	{
		if(fl==1)
		{
			if(a[i]<b[j])
			{
				if(cnt<k)c+=a[i],cnt++,i++;
				else c+=b[j],j++,fl=-1,cnt=1;
			}
			else
			{
				c+=b[j],j++,fl=-1,cnt=1;
			}
		}
		else
		{
			if(a[i]<b[j])
			{
				c+=a[i],fl=1,cnt=1,i++;
			}
			else
			{
				if(cnt<k)c+=b[j],j++,cnt++;
				else c+=a[i],fl=1,cnt=1,i++;
			}
		}
	}
	cout<<c<<endl;
}
int main()
{
	int __;cin>>__;
	while(__--)solve();
}