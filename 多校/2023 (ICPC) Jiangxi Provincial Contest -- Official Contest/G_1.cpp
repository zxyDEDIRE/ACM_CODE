#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define next wajodw
/*
* 扩展KMP算法
*/
//next[i]:x[i...m-1]与x[0...m-1]的最长公共前缀
//extend[i]:y[i...n-1]与x[0...m-1]的最长公共前缀
void pre_EKMP(char x[],int m,int next[])
{
	next[0]=m;
	int j=0;
	while(j+1<m && x[j]==x[j+1])j++;
	next[1]=j;
	int k=1;
	for(int i=2;i<m;i++)
	{
		int p=next[k]+k-1;
		int L=next[i-k];
		if(i+L<p+1)next[i]=L;
		else
		{
			j=max(0,p-i+1);
			while(i+j<m && x[i+j]==x[j])j++;
			next[i]=j;
			k=i;
		} 
	} 
}
char s[100005];
int next[100005];
int dp[100005];
int ans=1e9;
int r[100005];
int n;
int fd(int l,int lim)
{
	if(l>=n||next[l]>=lim)return l;
	return r[l]=fd(r[l],lim);
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	pre_EKMP(s,n,next);
	//for(int i=0;i<n;i++)cout<<i<<" "<<next[i]<<endl;
	for(int i=0;i<=n;i++)
		dp[i]=1e9;
	for(int i=0;i<n;i++){
		if(next[i]>i)
			next[i]=i;
	}
	for(int i=0;i<n+3;i++)
		r[i]=i+1;
	dp[1]=1;
	for(int i=2;i<n;i++)
	{
		dp[i]=min(dp[i],dp[i-1]+1);
		int now=i;
		int nowans=dp[i];
		while(1)
		{
			int k=fd(now,i);
			if(k<n)
			{
				nowans+=k-now;
				now=k;
				now=now+i;
				nowans++;
				dp[now]=min(dp[now],nowans+1);
				//dp[now+i]
			}
			else
			{
				break;
			}
		}
	}
	dp[n]=min(dp[n],dp[n-1]+1);
	cout<<dp[n]<<endl;
	return 0;
}
