#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<ll, ll>pi; typedef complex<double>cx;
#define int ll
#define X first
#define Y second
#define fer(i,a,n) for(int i=a;i<=n;i++)
#define ref(i,n,a) for(int i=n;i>=a;i--)
#define endl '\n'
#define mem(a,x) memset(a,x,sizeof a)
#define ac IO;int t;cin>>t;while(t--)solve()
#define AC signed main(){IO;solve();}
#define NO {cout<<"NO"<<endl;return;}
#define YES {cout<<"YES"<<endl;return;}
#define re(a) {cout<<a<<endl;return;}
#define all(v) v.begin(),v.end()
//ofstream fout("1.out", ios::out);
//ifstream fin("1.in", ios::in);
//#define cout fout
//#define cin fin
//--------------------瑞神神中神--------------------

const int N=1e5+10;
int ans,n,tot;
vector<int>e[N];
int c[N],id[N];
struct node
{
    map<int,int>cnt;
    set<int>se;
    int mx=0;

    void add(int x)
    {
        cnt[x]++;
        if(cnt[x]>mx)
        {
            mx=cnt[x];
            se.clear();
            se.insert(x);
        }
        else if(cnt[x]==mx)
        {
            se.insert(x);
        }
    }
    void clear()
    {
        if(mx<=1)return;
        cnt.clear();
        for(int it:se)
        {
            cnt[it]=1;
        }
        mx=1;
    }

}sub[N];

void dfs(int u)
{
    id[u]=++tot;
    int mx_son=-1,mx_sz=0;
    if(e[u].empty())
    {
        sub[id[u]].add(c[u]);
        return;
    }
    for(int v:e[u])
    {
        dfs(v);
        if(sub[id[v]].se.size()>mx_sz)
        {
            mx_sz=sub[id[v]].se.size();
            mx_son=v;
        }
    }
    if(mx_son!=-1)id[u]=id[mx_son];
    for(int v:e[u])
    {
        if(v==mx_son)continue;
        for(int it:sub[id[v]].se)
        {
            sub[id[u]].add(it);
        }
    }
    ans+=e[u].size()-sub[id[u]].mx;
    sub[id[u]].clear();
}

void solve()
{
    cin>>n;
    for(int v=2;v<=n;v++)
    {
        int u;cin>>u;
        e[u].emplace_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    dfs(1);
    cout<<ans+1<<'\n';
}

AC

