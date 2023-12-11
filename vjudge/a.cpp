/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int MaxM=450010;
const int MaxP=510;
struct DLX{
	int U[MaxM],D[MaxM],L[MaxM],R[MaxM];
	int Row[MaxM],Col[MaxM];
	int First[MaxP];
	int Size[MaxM];
	int tot=0;
	int ans;
	void build(int n,int num){
		for(int i=0;i<=num;i++){
			L[i]=i-1;R[i]=i+1;
			U[i]=i;D[i]=i;
			Size[i]=0;
		}
		L[0]=num;
		R[num]=0;
		tot=num;
		for(int i=1;i<=n;i++)
			First[i]=-1;
	}
	void insert(int x,int y){
		Row[++tot]=x;
		Col[tot]=y;
		D[tot]=D[y];
		U[D[y]]=tot;
		U[tot]=y;
		D[y]=tot;
		if(First[x]<0){
			L[tot]=tot;
			R[tot]=tot;
			First[x]=tot;
		}
		else{
			R[tot]=R[First[x]];
			L[R[First[x]]]=tot;
			L[tot]=First[x];
			R[First[x]]=tot;
		}
		Size[y]++;
	}
	void Remove_Link(int y){
		// T[T[y].R].L=T[y].L;
		L[R[y]]=L[y];
		// T[T[y].L].R=T[y].R;
		R[L[y]]=R[y];
		for(int i=D[y];i!=y;i=D[i]){
			for(int j=R[i];j!=i;j=R[j]){
				U[D[j]]=U[j];
				D[U[j]]=D[j];
				Size[Col[j]]--;
			}
		}
	}
	void Resume_Link(int y){
		for(int i=U[y];i!=y;i=U[i]){
			for(int j=L[i];j!=i;j=L[j]){
				D[U[j]]=j;
				U[D[j]]=j;
				Size[Col[j]]++;
			}
		}
		R[L[y]]=y;
		L[R[y]]=y;
	}
	void dance(int depth){
		if(depth>=ans)
			return ;
		if(R[0]==0){
			ans=depth;
			return ;
		}
		int y=R[0];
		for(int i=R[0];i!=0;i=R[i])
			if(Size[i]<Size[y])
				y=i;
		Remove_Link(y);
		for(int i=D[y];i!=y;i=D[i]){
			for(int j=R[i];j!=i;j=R[j])
				Remove_Link(Col[j]);
			dance(depth+1);
			for(int j=L[i];j!=i;j=L[j])
				Resume_Link(Col[j]);
		}
		Resume_Link(y);
	}
}dlx;
int n,m,p;
void solve()
{
	cin>>n>>m>>p;
	dlx.build(p,n*m);
	for(int i=1;i<=p;i++)
	{
		int x,y,_x,_y;
		cin>>x>>y>>_x>>_y;
		for(int I=x+1;I<=_x;I++)
			for(int J=y+1;J<=_y;J++)
				dlx.insert(i,(I-1)*m+J);
	}
	dlx.ans=inf;
	dlx.dance(0);
	if(dlx.ans==inf)cout<<-1<<endl;
	else cout<<dlx.ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
