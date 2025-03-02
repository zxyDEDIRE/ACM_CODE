#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);
#define int long long
using namespace std;
const int maxn=1e6;


inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
inline void write(int x){
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}


int b[maxn],c[maxn],p[maxn];
int ans=0;
int n;
signed main(){
	ios;
	cin>>n;c[n+1]=1e9+7;
	for(int i=1;i<=n;i++)cin>>b[i],ans=max(ans,b[i]);
	for(int i=1;i<=n;i++)cin>>c[i],ans=max(ans,b[i]);
	int t=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(c[j]<=b[i])t++,j++;
		p[i]=t--;
		cout<<p[i]<<" ";
	}
}

