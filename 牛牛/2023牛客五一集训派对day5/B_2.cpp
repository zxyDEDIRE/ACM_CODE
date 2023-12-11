#include<bits/stdc++.h>
using namespace std;
#define rep(x,y,z) for(register int x=y; x<=z; x++)
#define downrep(x,y,z) for(register int x=y; x>=z; x--)
#define LL long long
#define ms(x,y,z) memset(x,y,sizeof(z))
#define repedge(x,y) for(register int x=hed[y]; ~x; x=edge[x].nex)
#define mp make_pair
#define fr first
#define se second
inline int read(){
    int x=0; int w=0; char ch=0;
    while(ch<'0' || ch>'9') w|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return w? (-x):x;
}
const int N=200005;
const int Maxlg=30;
const int maxn=N*(Maxlg+1);
const LL inf=1e15;
int n,f[N],toc[N],vis[N],ch[maxn][2],id[maxn],cnt;
LL a[N];
pair<LL,LL> E[N];
vector<int> dt[N];
void trie_init(){
	rep(i,0,cnt) ch[i][0]=ch[i][1]=0,id[i]=n+1; 
	cnt=0; 
}
int que(int x){
	int k=0; int v=a[x]; 
	downrep(i,Maxlg,0){
		int p=((v>>i)&1); 
		if (ch[k][p]) k=ch[k][p];
		else k=ch[k][p^1];
	}
	return id[k]; 
}
void ins(int x){
	int k=0; int v=a[x];
	downrep(i,Maxlg,0){
		int p=((v>>i)&1);
		if (!ch[k][p]){
			ch[k][p]=++cnt; 
            if (i==0) id[ch[k][p]]=x;
	    }
	    k=ch[k][p]; 
 	} 
 	id[k]=min(id[k],x); 
}
LL Boruvka(){
	LL res=0; int num=0;  
	rep(i,1,n){ f[i]=i; dt[f[i]].push_back(i); }
	while(num<n-1){
		rep(i,1,n) vis[i]=0;
		int tmp=0; rep(i,1,n) if (!vis[f[i]]){ toc[++tmp]=f[i]; vis[f[i]]=1; }
		trie_init(); 
		rep(i,1,tmp){
			E[toc[i]]=mp(inf,inf);
			int t=dt[toc[i]].size();
			rep(j,0,t-1){
				int v=dt[toc[i]][j];
				int x=que(v); if (x>n) continue;
				LL edgenum=(min(x,v)-1)*1ll*n+max(x,v)*1ll-1ll;
				E[toc[i]]=min(E[toc[i]],mp((a[v]^a[x])*1ll,edgenum));
			}
			rep(j,0,t-1){
				int v=dt[toc[i]][j];
				ins(v); 
			}
		}
		trie_init(); 
		downrep(i,tmp,1){
			int t=dt[toc[i]].size();
			rep(j,0,t-1){
				int v=dt[toc[i]][j]; 
				int x=que(v); if (x>n) continue;
				LL edgenum=(min(x,v)-1)*1ll*n+max(x,v)*1ll-1ll;
				E[toc[i]]=min(E[toc[i]],mp((a[v]^a[x])*1ll,edgenum));
			}
			rep(j,0,t-1){
				int v=dt[toc[i]][j];
				ins(v); 
			}
		}
		rep(i,1,tmp){
			int a=f[E[toc[i]].se%n+1]; int b=f[E[toc[i]].se/n+1]; 
			if (a==b) continue; 
			res+=E[toc[i]].fr; num++; 
			if (dt[a].size()>dt[b].size()) swap(a,b); 
			int t=dt[a].size();
			rep(j,0,t-1){ dt[b].push_back(dt[a][j]); f[dt[a][j]]=b; }
			dt[a].clear(); 
		}   
	}
	return res;
}
int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    LL ans=Boruvka(); 
    printf("%lld\n",ans);
    return 0;
}