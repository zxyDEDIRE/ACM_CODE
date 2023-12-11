#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
    int x,id;
}p[maxn];
string str;
int n,m;
int f(int x)
{
    cout<<"? ";
    str[x-1]='1';
    cout<<str<<'\n';
    int res;
    cin>>res;
    str[x-1]='0';
    return res;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        str+='0';
    int sum=0;
    for(int i=1;i<=m;i++){
        p[i].x=f(i);
        p[i].id=i;
    }
    sort(p+1,p+1+m,[&](node a,node b){return a.x<b.x;});
    
    for(int i=1;i<=m;i++)
    {

    }

    fflush(stdout);
}
int main(){
    int __;  
    __=1;
    while(__--)solve();
    return 0;
}
/*
1
3
5
9
*/