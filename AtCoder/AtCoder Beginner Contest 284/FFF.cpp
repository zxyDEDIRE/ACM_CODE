#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+7;
int lena,lenb;
int p[maxn];
string s,t;
void pre()
{
	p[1]=0;
    for(int i=1,j=0;i<=lenb;i++)
    {
    	while(j>0&&t[j+1]!=t[i+1])j=p[j];
    	if(t[i+1]==t[j+1])j++;
    	p[i+1]=j;
	}
}
void kmp()
{
	for(int i=0,j=0;i<lena;i++)
	{
		while(j>0&&t[j+1]!=s[i+1])j=p[j];
		if(t[j+1]==s[i+1])j++;
		if(j==lenb)
		{
			j=p[j];
            printf("%d\n",i-lenb+2);
		}
	}
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s>>t;
    lena=s.size();
    lenb=t.size();
    s=" "+s;
    t=" "+t;
    pre();
    kmp();
    for(int i=1;i<=lenb;i++)printf("%d ",p[i]);
}
/*
ABABABC
ABA
*/
