#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],id[maxn],m,n,sum;
inline int ask(int k){
	putchar('?'),putchar(32);
	for(ri i=1;i<=m;++i)putchar((i==k)|48);
	putchar(10);
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	return ret;
}
char ans[maxn];
inline int ask(){
	putchar('?'),putchar(32);
	puts(ans+1);
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=m;++i)sum+=(a[i]=ask(i)),ans[i]=48,id[i]=i;
	sort(id+1,id+m+1,[&](int x,int y){return a[x]<a[y];});
	for(ri ii=1,j=0;ii<=m;++ii){
		ri i=id[ii];
		ans[i]=49;
		ri tmp=ask();
		if(tmp!=a[i]+j)sum-=a[i];
		j=tmp;
	}
	printf("! %d",sum);
	fflush(stdout);
	return 0;
}