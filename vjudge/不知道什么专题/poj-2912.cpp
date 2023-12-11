/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define endl "\n"
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int _x[maxn],_y[maxn];
int line[maxn];
char op[maxn];
int p[maxn];
int n,m;
void init()
{
	for(int i=0;i<=n*3;i++)
		p[i]=i;
}
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void un(int x,int y){
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)p[fa]=fb;
}
void solve()
{
	for(int i=1;i<=m;i++)
	{
		scanf("%d%c%d",&_x[i],&op[i],&_y[i]);
		if(op[i]=='<')swap(_x[i],_y[i]);
	}
	memset(line,0,sizeof(line));
	int cnt=0;
	int ans_1,ans_2=0;
	for(int k=0;k<n;k++)
	{
		init();

		int flag=1;
		for(int i=1;i<=m;i++)
		{
			int x=_x[i],x1=_x[i]+n,x2=_x[i]+n+n;
			int y=_y[i],y1=_y[i]+n,y2=_y[i]+n+n;
			if(op[i]=='=')
			{
				if(find(x)==find(y1)||find(x)==find(y2))
				{
					flag=0;
					line[k]=i;
					break;
				}
				else if(x!=k&&y!=k)
				{
					un(x,y);
					un(x1,y1);
					un(x2,y2);
				}
			}
			else
			{
				if(find(x)==find(y)||find(x)==find(y2))
				{
					flag=0;
					line[k]=i;
					break;
				}
				else if(x!=k&&y!=k)
				{
					un(x,y1);
					un(x2,y);
					un(x1,y2);
				}
			}
		}
		if(flag)
		{
			cnt++;
			ans_1=k;
		}
	}
	// for(int i=0;i<n;i++)
	// 	cout<<line[i]<<" ";cout<<endl;
	for(int i=0;i<n;i++)
		ans_2=max(ans_2,line[i]);
	if(cnt==0)printf("Impossible\n");
	else if(cnt==1)
		printf("Player %d can be determined to be the judge after %d lines\n",ans_1,ans_2);
	else printf("Can not determine\n");
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	while(~scanf("%d%d",&n,&m))
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}