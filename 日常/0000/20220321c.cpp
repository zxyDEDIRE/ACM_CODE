#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6;
char s[10],t[10];
int a[100],b[100];
signed main()
{
	for(int i=1;i<=3;i++)cin>>s[i];
	for(int i=1;i<=3;i++)cin>>t[i];
	for(int i=1;i<=3;i++)a[s[i]]=i;
	for(int i=1;i<=3;i++)b[i]=a[t[i]];
	if(b[1]==1&&b[2]==2)cout<<"Yes"<<endl;
	else if(b[1]==1&&b[2]==3)cout<<"No"<<endl;
	else if(b[1]==2&&b[2]==1)cout<<"No"<<endl;
	else if(b[1]==2&&b[2]==3)cout<<"Yes"<<endl;
	else if(b[1]==3&&b[2]==2)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
/*
1 2 3
1 2 3
yes


1 2 3
1 3 2
no

1 2 3
2 1 3
no

1 2 3
3 2 1
no


1 2 3 yes
1 3 2 no
2 1 3 no
2 3 1 yes
3 2 1 no
3 1 2 yes



*/