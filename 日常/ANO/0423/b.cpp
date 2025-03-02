#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int p[maxn],a[maxn],b[maxn];
int vis[maxn];
int n,cnt;
bool cmpa(int a,int b){
	return a<b;
}
bool cmpb(int a,int b){
	return a>b;
}
void solve()
{
	cin>>n;
	int fl=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]!=a[cnt])a[++cnt]=p[i];
	}
	int cnt=0;
	int l=1;
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&i!=n&&(a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))
		{

		}
	}
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
1 2 3 9 8 7
3 8 1 7 2 9
*/