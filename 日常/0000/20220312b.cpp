#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define INF 0x3f3f3f3f
int vis[100];
void solve()
{   
    string a,b,c;
    cin>>a>>b>>c;
    int flag=1;
    for(int i=0;i<4;i++){
        memset(vis,0,sizeof(vis));
        vis[a[i]-'A']++,vis[a[i+4]-'A']++,vis[a[i+8]-'A']++;
        vis[b[i]-'A']++,vis[b[i+4]-'A']++;
        vis[c[i]-'A']++;
        if(vis['G'-'A']==3&&vis['R'-'A']==2&&vis['Y'-'A']==1)continue;
        flag=0;break;
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
