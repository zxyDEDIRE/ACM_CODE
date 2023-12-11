#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);
#define int long long
using namespace std;
const int maxn=1e6;
inline void  read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
inline void write(int x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}

vector<int>v[maxn];
int p[maxn];
int a[maxn];
int c[maxn];
int n,flag;
void dfs(int x,int fa)
{
	p[x]=0;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		dfs(y,x);
	}
	int t=p[x]+a[x]-c[x];
	if(t<0)flag=1;
	p[fa]+=t;
}
signed main(){
	ios
	cin>>n;
	p[1]=1;
	for(int i=2,x;i<=n;i++)read(x),p[i]=x,v[x].push_back(i);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(c[i]);
	int q;read(q);
	dfs(1,0);
	cout<<endl;
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)cout<<c[i]<<" ";
	cout<<endl;
	if(flag)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	cout<<endl;
	while(q--)
	{
		flag=0;
		int x,y,z;
		cin>>x>>y>>z;
	//	cout<<y<<" "<<x<<endl;
		if(x==1)a[y]=z;
		else if(x==2)c[y]=z;
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<c[i]<<" ";
		cout<<endl;
		dfs(1,0);
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		cout<<endl;
	}
	
}
