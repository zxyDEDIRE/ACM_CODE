/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int p[maxn];
int n,ma;
void merge_sort(int p[],int l,int r,ll fl)
{
	if(fl>ma)return ;
	if(l>=r)return ;
	vector<int>a,b;
	for(int i=l;i<=r;i++)
	{
		if(p[i]&fl)a.push_back(p[i]);
		else b.push_back(p[i]);
	}
	int j=l,mid;
	for(int i=0;i<a.size();i++,j++)
		p[j]=a[i];
	mid=j;
	for(int i=0;i<b.size();i++,j++)
		p[j]=b[i];


	merge_sort(p,l,mid-1,fl<<1);
	merge_sort(p,mid,r,fl<<1);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		ma=max(ma,p[i]);
	}
	sort(p+1,p+1+n);
	for(int i=1;i+2<=n;i++)
	{
		if(p[i]==p[i+2]){
			cout<<"NO"<<endl;
			return ;
		}
	}
	merge_sort(p,1,n,1ll);
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
8
4 6 8 10 12 14 16 18


1
10
1 2 3 4 5 6 7 8 9 10
*/