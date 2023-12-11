#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cout.tie(0);
using namespace std;
const int maxn=1e5+7;
int f[maxn][30];//f[i][j]从i开始2^j长度的最大值 
int mn[maxn];//储存答案 
int p[maxn];//原数组 
int n,m;

int read(){
    int num=0;char ch;
    while((ch=getchar())<'0'||'9'<ch);
    do num=num*10+ch-48,ch=getchar();while('0'<=ch&&ch<='9');
    return num;
}
void st()
{
	for(int i=1;i<=n;i++)//距离为0初始化 
		f[i][0]=p[i];
	int t=log(n)/log(2)+1;//j定位 
	for(int j=1;j<t;j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
		}
	}
	
	for(int len=1;len<=n;len++)//数组储存答案 
	{
		int k=0;
		while((1<<(k+1))<=len)
			k++;
		mn[len]=k;
	}
}

int rst(int L,int R)//答案数组查寻 不推荐 
{
	if(L>R)swap(L,R);
	int k=mn[R-L+1];
	return max(f[L][k],f[R-(1<<k)+1][k]);
}

int query(int l,int r)
{
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	IOS
	n=read();m=read();
	for(int i=1;i<=n;i++)
		p[i]=read();
	//clock_t start, finish;
	//start = clock();
	st();
	while(m--)
	{
		int x,y;
		x=read();y=read();
		printf("%d\n",rst(x,y));
	}
	// finish = clock();
	//  cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
}