#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10;
const int base = 200001;
int fa[maxn * 40];
int f[maxn][22];
int n, m;

int FIND(int x)
{
	if ( fa[x] != x )
		fa[x] = FIND(fa[x]);
	return fa[x];
}
int find(int x,int y)
{
	return f[x][y]==x?f[x][y]:find(f[x][y],y);
}

void MERGE(int x, int y)
{
	x = FIND(x);
	y = FIND(y);
	if ( x == y )
		return;
	fa[x] = y;
	return;
}
void merge(int x,int y,int t)
{
	x=find(x,t);
	y=find(y,t);
	if(x!=y)f[x][t]=y;
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

	for(int i=1;i<=n*2;i++)
		for(int j=0;j<=20;j++)
			f[i][j]=i;


	for(int i=1;i<=n;i++)
	{
		int x=get(i,0);
		int y=get(2*n-i+1,0);
		MERGE(x,y);
	}
	for(int i=1;i<=n;i++)
		merge(i,2*n-i,0);


	auto F=[&](int l,int r)->void{
		int x=2*n-r+1;
		int y=2*n-l+1;
		for(int i=20;i>=0;i--)
			if(l+(1<<i)-1<=r){
				int _x=get(l,i);
				int _y=get(x,i);
				MERGE(_x,_y);
				l+=(1<<i);
				x+=(1<<i);
			}
	};
	auto FF=[&](int l,int r)->void{
		int x=2*n-r+1;
		int y=2*n-l+1;
		for(int i=20;i>=0;i--)
			if(l+(1<<i)-1<=r){
				merge(l,x,i);
				l+=(1<<i);
				x+=(1<<i);
			}
	};

	while(m--)
	{
		int l,r;
		cin>>l>>r;

		
		F(l,r);
		FF(l,r);
		
	}
	for(int j=20;j>=1;j--)
	{
		for(int i=1;i<=n*2;i++)
		{
			int tt=get(i,j);
			if(tt==fa[tt])continue;
			int f=FIND(tt);
			int x=f/base-(f%base==0);
			int y = f%base ? f%base : base;
			int tt1 = get(i,j-1);
			int tt2 = get(y,j-1);
			MERGE(tt1, tt2);
			tt1 = get(i + (1 << (j - 1)), j - 1);
			tt2 = get(y + (1 << (j - 1)), j - 1);
			MERGE(tt1, tt2);
		}
	}

	for(int j=20;j>=1;j--)
	{
		for(int i=1;i<=n*2;i++)
		{
			if(f[i][j]==i)continue;
			int FA=find(i,j);
			merge(i,FA,j-1);
			merge(i+(1<<(j-1)),FA+(1<<(j-1)),j-1);
		}
	}

	int cnt=0;
	for(int i=1;i<=n;i++)
		if(find(i,0)==find(i+n,0))cnt++;
	if(cnt==n)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	cout<<cnt<<endl;


	// int flag=0;
	// int ans=0;
	// for(int i=1;i<=n;i++){
	// 	int x=get(i,0);
	// 	int y=get(i+n,0);
	// 	if(FIND(x)!=FIND(y)){
	// 		flag=1;
	// 	}
	// 	else ans++;
	// }

	// if(flag)cout<<"NO"<<endl;
	// else cout<<"YES"<<endl;
	// cout<<ans<<endl;

	return 0;
}