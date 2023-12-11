/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define endl "\n"
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int MaxM=1e6;
const int MaxP=1e6;
char g[maxn];
struct DLX{
	int U[MaxM],D[MaxM],L[MaxM],R[MaxM];
	int Row[MaxM],Col[MaxM];
	int First[MaxP];
	int Size[MaxM];
	int stk[maxn];
	int tot;
	int ans;
	int flag;
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
		flag=0;
		ans=inf;
	}
	void insert(int x,int y){
		Row[++tot]=x; Col[tot]=y;
		Size[y]++;
		D[tot]=D[y]; U[D[y]]=tot;
		U[tot]=y; D[y]=tot;
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
	}

	void remove(int c){
		L[R[c]]=L[c];
		R[L[c]]=R[c];
		for(int i=D[c];i!=c;i=D[i]){
			for(int j=R[i];j!=i;j=R[j]){
				U[D[j]]=U[j];
				D[U[j]]=D[j];
				Size[Col[j]]--;
			}
		}
	}
	void resume(int y){
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
		if(flag)return ;
		if(depth>=ans)
			return ;
		if(R[0]==0){
			flag=1;
			ans=depth;
			for(int i=0;i<depth;i++)
				g[(stk[i]-1)/9]=(stk[i]-1)%9+'1';
			for(int i=0;i<9*9;i++)
				cout<<g[i];
			cout<<endl;
			return ;
		}
		int y=R[0];
		for(int i=R[0];i!=0;i=R[i])
			if(Size[i]<Size[y])
				y=i;
		remove(y);
		for(int i=D[y];i!=y;i=D[i]){
			stk[depth]=Row[i];			
			for(int j=R[i];j!=i;j=R[j])
				remove(Col[j]);
			dance(depth+1);
			for(int j=L[i];j!=i;j=L[j])
				resume(Col[j]);
		}
		resume(y);
	}
}dlx;
int c[10];
string str;
int n=9;
void replace(int i,int j,int k)
{
	c[0]=(i*n+j)*n+k;
	c[1]=i*n+j+1;// 这个格子是否放置了数字
	c[2]=n*n + i*n+k;//行
	c[3]=n*n*2 + j*n+k;//列
	c[4]=n*n*3 + ((j)/3+(i)/3*3)*n+k;//宫
}
void solve()
{
	dlx.build(n*n*n,n*n*4);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=1;k<=n;k++){
				if(str[i*n+j]=='.'||str[i*n+j]==(char)('0'+k)){
					replace(i,j,k);
					dlx.insert(c[0],c[1]);
					dlx.insert(c[0],c[2]);
					dlx.insert(c[0],c[3]);
					dlx.insert(c[0],c[4]);
					cout<<i<<" "<<j<<" "<<k<<endl;
					cout<<i*n+j<<" "<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<endl;
				}
			}
	dlx.dance(0);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>str&&str!="end")
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0
11 12 13
21 22 23
31 32 33

*/