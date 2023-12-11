#include<bits/stdc++.h>
using namespace std;
#define lson ( p << 1 )
#define rson ( p << 1 | 1 )
typedef long long ll;
const int maxn = 2e6 + 10;
const int base = 200001;
int fa[maxn * 40];
int n, m;

int find(int x)
{
	if ( fa[x] != x )
		fa[x] = find(fa[x]);
	return fa[x];
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if ( x == y )
		return;
	fa[x] = y;
	return;
}

inline int get(int x, int k)
{
	return k * base + x;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n*2;i++){
		for(int j=0;j<=20;j++){
			int x=get(i,j);
			fa[x]=x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x=get(i,0);
		int y=get(2*n-i+1,0);
		merge(x,y);
	}

	while(m--)
	{
		int l,r;
		cin>>l>>r;
		int x=2*n-r+1;
		int y=2*n-l+1;
		for(int i=20;i>=0;i--)
			if(l+(1<<i)-1<=r){
				int _x=get(l,i);
				int _y=get(x,i);
				merge(_x,_y);
				l+=(1<<i);
				x+=(1<<i);
			}

	}
	for(int j=20;j>=1;j--)
	{
		for(int i=1;i<=n*2;i++)
		{
			int tt=get(i,j);
			if(tt==fa[tt])continue;
			int f=find(tt);
			int x=f/base-(f%base==0);
			int y = f%base ? f%base : base;
			int tt1 = get(i,j-1);
			int tt2 = get(y,j-1);
			merge(tt1, tt2);
			tt1 = get(i + (1 << (j - 1)), j - 1);
			tt2 = get(y + (1 << (j - 1)), j - 1);
			merge(tt1, tt2);
		}
	}

	int flag=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=get(i,0);
		int y=get(i+n,0);
		if(find(x)!=find(y)){
			flag=1;
		}
		else ans++;
	}

	if(flag)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	cout<<ans<<endl;

	return 0;
}