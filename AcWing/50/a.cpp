#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
bitset<maxn>vis;
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        vis[x]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]){
            cout<<i<<endl;
            return 0;
        }
    }
}