#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n;
long long k;
string s;
int p[N];
int m;
long long sum[N];

bool check(int mi)
{
    int l=1,r=mi;
    long long res=0;
    for(int i=1;i<=(l+r)/2;i++)
    {
        res+=1ll*(p[i]-p[i-1]-1)*(i-1);
    }
    for(int i=r;i>=(l+r)/2;i--)
    {
        res+=1ll*(p[i+1]-p[i]-1)*(r-i);
    }
//     cout<<res<<'\n';
    if(res<=k) return true;
    while(r+1<=m)
    {
        res-=sum[(l+r)/2]-sum[l];
        r++;l++;
        res+=sum[r]-sum[(l+r)/2];
//         cout<<res<<'\n';
        if(res<=k) return true;
    }
    
    return false;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	cin>>s;
	s='0'+s;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='6') {
            p[++m]=i;
        }
    }
    for(int i=2;i<=m;i++)
    {
        sum[i]=sum[i-1]+p[i]-p[i-1]-1;
    }
    int l,r;
    l=1,r=m;
    while(l<r)
    {
        int mi=(l+r+1)>>1;
        if(check(mi)) l=mi;
        else r=mi-1;
    }
    cout<<r;
	return 0;
}