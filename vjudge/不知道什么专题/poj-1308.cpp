#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e6;
int vis[maxn];
int in[maxn];
int p[maxn];
int x,y,numa,numb,numc,flag;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void init()
{
	for(int i=1;i<=10000;i++)
		p[i]=i,vis[i]=0,in[i]=0;
}
int main()
{
	int w=0,l=0;
	while(1)
	{
		w++;
		numa=0,numb=0,numc=0,flag=1;
		init();
		while(~scanf("%d%d",&x,&y))
		{
			if(x==0&&y==0)break;
			if(x==-1&&y==-1)return 0;
			if(!vis[x])vis[x]=1,numa++;
			if(!vis[y])vis[y]=1,numa++;
			int fa=find(x);
			int fb=find(y);
			if(fa==fb)flag=0;
			else p[fa]=fb;
			in[y]++;
		}
		for(int i=1;i<=10000;i++)
		{
			if(in[i]==0&&vis[i])numc++;
			if(p[i]==i&&vis[i])numb++;
		}
		if(numa==0)printf("Case %d is a tree.\n",w);
		else if(!flag||numb!=1||numc!=1)printf("Case %d is not a tree.\n",w);
		else printf("Case %d is a tree.\n",w);
	}
}
