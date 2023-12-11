class Solution {
public:
    class Seg{
    public:
        struct node{int l,r,val_1,val_2;};
        vector<node>t;
        vector<int>w;
        int INF=1e9+7;
        int n,tot;
        Seg(int x,vector<int>p):n(x),w(p){
            t.resize(x*4+100);
        }
        void pushup(int rt){
            vector<int>now;
            now.push_back(t[rt<<1].val_1);
            now.push_back(t[rt<<1].val_2);
            now.push_back(t[rt<<1|1].val_1);
            now.push_back(t[rt<<1|1].val_2);
            sort(now.begin(),now.end());
            t[rt].val_1=now[0];
            t[rt].val_2=now[1];
        }
        void build(int rt,int l,int r){
            t[rt]={l,r,INF,INF};
            if(l==r){
                t[rt].val_1=w[l-1];
                return ;
            }
            int mid=(l+r)>>1;
            build(rt<<1,l,mid);
            build(rt<<1|1,mid+1,r);
            pushup(rt);
        }
        vector<int> query(int rt,int l,int r){
            if(l<=t[rt].l&&t[rt].r<=r)
                return {t[rt].val_1,t[rt].val_2};
            vector<int>ans;
            int mid=(t[rt].l+t[rt].r)>>1;
            if(l<=mid){
                auto now = query(rt<<1,l,r);
                ans.push_back(now[0]);
                ans.push_back(now[1]);
            }
            if(r>mid)
            {
                auto now = query(rt<<1|1,l,r);
                ans.push_back(now[0]);
                ans.push_back(now[1]);
            }
            sort(ans.begin(),ans.end());
            return {ans[0],ans[1]};
        }
    };
    int sumImbalanceNumbers(vector<int>& p) {
        Seg T(p.size(),p);
        int n=p.size();
        int ans=0;
        T.build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                auto now = T.query(1,i,j);
                if(now[1]-now[0]>1){
                    ans++;
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        cout<<endl;
        return ans;
        
    }
};