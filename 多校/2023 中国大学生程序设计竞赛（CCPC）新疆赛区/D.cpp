#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int a[maxn];
int n;
int merge_sort(int p[],int l,int r)
{
	if(l>=r)return 0;
	int t=0;
	int mid=(l+r)>>1;
	t=merge_sort(p,l,mid)+merge_sort(p,mid+1,r);
	int temp[r-l+1];
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(p[i]<=p[j])temp[k++]=p[i++];
		else
		{
			t+=mid-i+1;
			temp[k++]=p[j++];
		}
	}
	while(i<=mid)temp[k++]=p[i++];
	while(j<=r)temp[k++]=p[j++];
	for(int i=l,j=0;i<=r;i++,j++)p[i]=temp[j];
	return t;
}
void solve(int x)
{
	int n=3;
	for(int i=1;i<=n;i++)
		a[i]=i;
	do{
		for(int i=1;i<=n;i++)
			p[i]=a[i],cout<<p[i]<<" ";
		cout<<"  "<<merge_sort(p,1,n)<<endl;
	}while(next_permutation(a+1,a+1+n));
}
bool f(int x)
{
	int f1=(p[x+1]>p[x]&&p[x+2]>p[x+1]);
	int f2=(p[x+1]<p[x]&&p[x+2]<p[x+1]);
	if(f1||f2)return 0;
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int flag=0;
	// cout<<f(1)<<endl;
	for(int i=1;i+2<=n;i++)
		if(f(i)){
			// 1 3 2
			if(p[i]<p[i+1]&&p[i]<p[i+2]&&p[i+1]>p[i+2])
				swap(p[i],p[i+2]),swap(p[i+1],p[i+2]);
			// 2 1 3
			else if(p[i]>p[i+1]&&p[i]<p[i+2]&&p[i+1]<p[i+2])
				swap(p[i],p[i+1]),swap(p[i+1],p[i+2]);
			// 2 3 1
			else if(p[i+1]>p[i]&&p[i+1]>p[i+2])
				swap(p[i],p[i+1]),swap(p[i+1],p[i+2]);
			else swap(p[i+1],p[i+2]),swap(p[i],p[i+1]);
			// 3 1 2
			flag=1;
			break;
		}
	if(flag==0){
		cout<<-1<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 2 3   0
1 3 2   1
2 1 3   1
2 3 1   2
3 1 2   2
3 2 1   3

4 1 5 1
5 4 1 2
*/