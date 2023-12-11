#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

void qr(int &x) {scanf("%d",&x);}
int n,ans,mx,mn; char s[N];

void calc(int x) {
    static int a[N],b[N];
    for(int i=0;i<x;i++) a[i]=-1,b[i]=10;
    for(int i=1;i<=n;i+=x) {
        if(!s[i]) return ;
        int big=0,sma=0;
        for(int j=0;j<x;j++) {
            if(!big&&s[i+j]!=a[j]) big=(s[i+j]>a[j])?1:-1;
            if(!sma&&s[i+j]!=b[j]) sma=(s[i+j]<b[j])?1:-1;
        }
        for(int j=0;j<x;j++) {
            if(big==1) a[j]=s[i+j];
            if(sma==1) b[j]=s[i+j];
        }
    }
    int num=0;
    for(int i=0;i<x;i++) {
        num=num*10+a[i]-b[i];
        if(num>=ans) return ;
    }
    ans=num;
}

void solve(int x) {//x 表示 999..t 的位数
    int mx=0,mn=1000,cnt=0;
    for(int i=1;i<=n;i++)
        if(s[i]==1) {
            if(i+x>n) return ;
            bool v=1;
            for(int j=1;j<x;j++) if(s[i+j]) {v=0; break;}
            if(!v) return ;
            mx=max(mx,10+s[i+x]);
            mn=min(mn,10+s[i+x]);
            i+=x; cnt++;
        }
        else {
            if(i+x-1>n) return;
            bool v=1;
            for(int j=0;j<x-1;j++) if(s[i+j]<9) {v=0; break;}
            if(!v) return; 
            mx=max(mx,(int)s[i+x-1]);
            mn=min(mn,(int)s[i+x-1]);
            i+=x-1; cnt++;
        }
    if(cnt<2) return ;
    ans=min(ans,mx-mn);
}

int main() {
    // freopen("a.in","r",stdin);
    int T; qr(T); while(T--) {
        qr(n); scanf("%s",s+1); mx=0; mn=10;
        for(int i=1;i<=n;i++) s[i]-='0',mx=max(mx,(int)s[i]),mn=min(mn,(int)s[i]);
        ans=mx-mn;
        for(int i=2;i*i<=n;i++) if(n%i==0) calc(i),calc(n/i);
        int k=0;
        for(int i=1;i<=n;i++) 
            if(s[i]==1) {
                k=1;
                while(i+k<=n&&!s[i+k]) k++;
                break;
            }
            cout<<ans<<endl;

        //长度不等的话,要么是1000...x,要么是99999...x.
        if(k)solve(k); 
        cout<<ans<<endl;
        if(k>1) solve(k-1);
        cout<<k-1<<endl;
        printf("%d\n",ans);
    }
}
