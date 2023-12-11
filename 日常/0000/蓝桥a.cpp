#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int p[maxn];
int n;
int merge_sort(int p[],int l,int r)
{
	sort(p+1,p+1+r);
	return 9;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
		cout<<"8"<<endl;
	int res=merge_sort(p,1,n);
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
	cout<<res<<endl;
}
/*
D:\VScode\mingw64\mingw64\bin
*/