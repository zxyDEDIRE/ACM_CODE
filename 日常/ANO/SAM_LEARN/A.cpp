#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3*1e6+10;
const int maxn=3e6+10;
char ch[N];
int nl;
ll res;
struct suffixautomation
{
    int mp[maxn][30],fa[maxn],len[maxn],siz[maxn];
    int ed,ct;
    struct Edge{
    	int to,next;
    }edge[maxn];
    int head[maxn],cnt;
    suffixautomation(){ed=ct=1;}
    inline void add(int from,int to){
    	edge[++cnt].to=to;
    	edge[cnt].next=head[from];
    	head[from]=cnt;
    }
    inline void insert(int c) 
    {
        int p=ed; siz[ed=++ct]=1; len[ed]=nl;//先初始化size和len 
        for(;p&&mp[p][c]==0;p=fa[p]){mp[p][c]=ed;}//然后顺着parent树的路径向上找 
        if(p==0){fa[ed]=1;return;}int q=mp[p][c];//case1 
        if(len[p]+1==len[q]){fa[ed]=q;return;}//case2
        len[++ct]=len[p]+1;//case 3
        for(int i=1;i<=26;i++)mp[ct][i]=mp[q][i];
        fa[ct]=fa[q];fa[q]=ct;fa[ed]=ct;
        for(int i=p;mp[i][c]==q;i=fa[i])mp[i][c]=ct;
    }
    inline void bt(){//暴力建树 
    	for(int i=2;i<=ct;i++){
    		add(fa[i],i);
    	}
    }
    void dfs(int u)//dfs 
    {
        for(int i=head[u];i;i=edge[i].next){
        	dfs(edge[i].to);
        	siz[u]+=siz[edge[i].to];
        }
        if(siz[u]!=1){
        	res=max(res,(ll)siz[u]*len[u]);
        }
    }
}sam;
int main()
{
    scanf("%s",ch+1);//没啥好说的，建sam然后dfs 
    for(int i=1;ch[i]!='\0';i++){
    	sam.insert(ch[i]-'a'+1);
    }
    sam.bt();
    sam.dfs(1);
    printf("%lld",res);
    return 0;//拜拜程序~ 
}