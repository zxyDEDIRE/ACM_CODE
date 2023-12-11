#include<bits/stdc++.h>
#define db double
#define a first
#define b second
#define ep emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<=b;i++) 
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
using ll = long long;
using pii=pair<int,int>;
using pdi=pair<db,int>;
template<class t, class u> bool chmax(t &a, u b) {if(a < b) {a = b; return true;} return false;}
template<class t, class u> bool chmin(t &a, u b) {if(b < a) {a = b; return true;} return false;}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
template<class t, class u>  
ostream& operator<<(ostream &os, const pair<t,u> &p) {
    return os<<"{"<<p.a<<","<<p.b<<"}";
}
template<class t>
ostream& operator<<(ostream &os, const vc<t> &v) {
    os<<"{";
    for (int i=0;i<v.size()-1;i++)os<<v[i]<<",";
    return os<<v.back()<<"}";
}
template<class t>
istream& operator>>(istream &is, vc<t> &v) {
    for(auto &x:v) is>>x;
    return is;
}
template<class t, class u>
istream& operator>>(istream &is, pair<t,u> &p) {
    is>>p.first>>p.second;
    return is;
}
#define mp make_pair
#define mt make_tuple
template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
    return os<<vc<t>(all(a));
}
mt19937 rng(time(NULL));
int norm(int x, int P) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T qpow(T a, int b) {
    T res = 1;
    for (; b; b >>= 1) {
        if(b & 1) res *= a;
        a *= a;
    }
    return res;
}
const int mod = 998244353;
template<const int P> 
struct Mint {
    int val;
    Mint(int x = 0) {val = norm(x, P);}
    int v() const {return val;}
    Mint inv() const {return qpow(*this, P - 2);}
    Mint operator - () const {return Mint(norm(P - val, P));}
    Mint operator += (const Mint &rhs) {val = norm(val + rhs.val, P); return *this;}
    Mint operator -= (const Mint &rhs) {val = norm(val - rhs.val, P); return *this;}
    Mint operator *= (const Mint &rhs) {val = 1ll * val * rhs.val % P; return *this;}
    Mint operator /= (const Mint &rhs) {return *this *= rhs.inv();}
    friend Mint operator + (const Mint &lhs, const Mint &rhs) {Mint res = lhs; res += rhs; return res;}
    friend Mint operator - (const Mint &lhs, const Mint &rhs) {Mint res = lhs; res -= rhs; return res;}
    friend Mint operator * (const Mint &lhs, const Mint &rhs) {Mint res = lhs; res *= rhs; return res;}
    friend Mint operator / (const Mint &lhs, const Mint &rhs) {Mint res = lhs; res /= rhs; return res;}
    friend istream& operator >> (istream& is, Mint &x) {
        int v;
        is >> v;
        x = norm(v, P);
        return is;
    }
    friend ostream& operator << (ostream& os, const Mint &x) {
        return os << x.v();
    }
};
using mint = Mint<mod>;
const int N = 1e5 + 10;
const int M = 3e5 + 10;
int n;
int ch[N][10], tot;
mint w[N*10];
int fail[N*10];
int f[N][10][21];
mint cost[N][10][21];
string s;
int sta[M], nowpos[M];
pair<int,int> seg[M];
mint ans[M];
int tp;
void insert(int val) {
    int u=0;
    for(auto c:s) {
        int x=c-'0';
        if(!ch[u][x]) ch[u][x]=++tot;
        u=ch[u][x];
    } 
    w[u]+=val;
}
void build() {
    queue<int> q;
    // rep(i,0,tot) {
    //     cout<<"v0: ";
    //     cout<<i<<" "<<w[i]<<"\n";
    // }
    for(int i=0;i<10;i++) if(ch[0][i]) q.push(ch[0][i]);
    while(!q.empty()) {
        int u=q.front(); q.pop();
        w[u]+=w[fail[u]];
        rep(i,0,9) {
            if(ch[u][i]) {
                fail[ch[u][i]]=ch[fail[u]][i];
                q.push(ch[u][i]);
            } else ch[u][i]=ch[fail[u]][i];
        }
    }
    // rep(i,0,tot) {
    //     cout<<"v: ";
    //     cout<<i<<" "<<w[i]<<"\n";
    // }
    rep(i,0,tot) rep(c,0,9) f[i][c][0]=ch[i][c], cost[i][c][0]=w[ch[i][c]];
    rep(j,1,20) rep(i,0,tot) rep(c,0,9) {
        f[i][c][j]=f[f[i][c][j-1]][c][j-1];
        cost[i][c][j]=cost[i][c][j-1]+cost[f[i][c][j-1]][c][j-1];
    }
}
void solve() {
    cin>>n;
    rep(i,1,n) {
        cin>>s;
        int w;
        cin>>w;
        insert(w);
    }
    build();
    cin>>s;
    mint sum=0;
    s=" "+s;
    for(int i=1,p=0;i<sz(s);i++) {
        int c=s[i]-'0';
        p=ch[p][c];
        sum+=w[p];
        ++tp;
        nowpos[tp]=p;
        ans[tp]=sum;
        seg[tp]={i,i};
        sta[tp]=c;
    }
    int q;
    cin>>q;
    auto go=[&](int p, int c, int step) {
        mint ans=0;
        for(int i=20;i>=0;i--) {
            if((step>>i)&1) ans+=cost[p][c][i],p=f[p][c][i];
        }
        return mp(ans, p);
    };
    // for (int i=1;i<=tp;i++) {
    //     cout<<"ans:";
    //     cout<<i<<" "<<ans[i]<<"\n";
    // }
    while(q--){
        int opt,l,c;
        cin>>opt;
        if(opt==1) {
            cin>>l>>c;
            int ps=sz(s)-l;
            while(tp&&seg[tp].a>=ps) tp--;
            if(tp) {
                seg[tp].b=ps-1;
                auto [tot,p]=go(nowpos[tp-1],sta[tp],ps-seg[tp].a);
                nowpos[tp]=p;
                ans[tp]=ans[tp-1]+tot;
            }
            tp++;
            sta[tp]=c;
            seg[tp]=mp(ps,sz(s)-1);
            auto [tot,p]=go(nowpos[tp-1],sta[tp],l);
            ans[tp]=ans[tp-1]+tot;
            nowpos[tp]=p;
        } else {
            cin>>l;
            int ll=1,rr=tp;
            // rep(i,1,tp) {
            //     cout<<sta[i]<<" "<<seg[i].a<<" "<<seg[i].b<<"\n";
            // }
            int tt;
            while(ll<=rr) {
                int md=ll+rr>>1;
                if(seg[md].a<=l) {
                    ll=md+1;
                    tt=md;
                }
                else rr=md-1;
            }
            // cout<<tt<<"\n";
            mint ANS=ans[tt-1]+go(nowpos[tt-1],sta[tt],l-seg[tt-1].b).a;
            cout<<ANS<<"\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;
    for (; t; t--) solve();
    return 0;
}