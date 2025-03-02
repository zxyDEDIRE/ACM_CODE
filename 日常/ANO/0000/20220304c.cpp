#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5;
int a[maxn],b[maxn],c[maxn];
void mull(string A,string B)
{
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	int la=A.size();
	int lb=B.size();
	for(int i=0;i<la;i++)a[i]=A[i]-'0';
	for(int i=0;i<lb;i++)b[i]=B[i]-'0';
	for(int i=0;i<la;i++)
	{
		for(int j=0;j<=lb;j++)
		{
			c[i+j]+=a[i]*b[j];
		}
	}
	int len=max(la,lb)+100;
	for(int i=0;i<len;i++)
		c[i+1]+=c[i]/10,c[i]%=10;
	while(c[len]==0)len--;
	for(int i=len;i>=0;i--)cout<<c[i];
}
signed main()
{
	string a,b;
	cin>>a>>b;
	mull(a,b);
}
/*
123
11
123
 123
*/
