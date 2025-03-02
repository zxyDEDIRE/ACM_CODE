#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
map<int,int>mp;
int p[maxn],cnt,n;
int m[maxn];
int main()
{
    while(cin>>n&&n)
    {
        cnt=0;
        mp.clear();
        for(int i=1;i<=n;i++)p[i]=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(!mp[x])mp[x]=++cnt,m[cnt]=x;;
            p[mp[x]]++;
        }
        for(int i=1;i<=cnt;i++)
            if(p[i]&1){
                cout<<m[i]<<"\n";
            }
    }
}