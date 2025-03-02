#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6;
int a[maxn];
int b[maxn];
int c[maxn];
int n,len,ma;
void solve()
{
    long long x,y,z;
    cin>>x>>y>>z;
    int aa=0,bb=0,cc=0;
    if(x==z||y==z)
    {
        cout<<"YES"<<endl;
        return ;
    }
    while(x)
    {
        a[++aa]=x%2;
        x>>=1;
    }
    while(y)
    {
        b[++bb]=y%2;
        y>>=1;
    }
    while(z)
    {
        c[++cc]=z%2;
        z>>=1;
    }
    for(int i=1;i<=cc;i++)
        if(c[i]==1&&(a[i]==0&&b[i]==0))
        {
            cout<<"NO"<<endl;
            return ;
        }
    cout<<"YES"<<endl;
}
int main(){
    int __;cin>>__;
    while(__--)solve();
}
/*
11
10

1011
1101
0110
1011
10

10
*/