#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int a[]={0,0};
	for(int i=1;i<=n;i++){
		cin>>p[i];
		a[p[i]&1]++;
	}
	cout<<min(a[0],a[1])<<endl;
}
int main(){
	int __;
	cin>>__;
	while(__--)solve();
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
int a[N];
void slov()
{
	int n;
	cin>>n;
	int cnt[2]={0};
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		cnt[x&1]++;
	}
	cout<<min(cnt[0],cnt[1])<<'\n';
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		slov();
}
*/
