#include <bits/stdc++.h>
using namespace std;
struct node{
    int c[4];
    void out(){
        for(int i = 0; i <= 3; i ++) cout << c[i] << " ";
        cout << "\n";
    }
    int sg(int t[]){
        if(t[0] == 0 && t[1] < 2 && (t[1] == 0 || t[2] == 0)) return -1;
        int res = -1;
        // out();
        for(int i = 0; i <= 3; i ++){
            if(!t[i]) continue ;
            t[i] --;
            for(int j = i; j <= 3; j ++){
                if(!t[j] || i + j > 3 || (i == 0 && j == 0)) continue ;
                t[j] --;
                t[i + j] += 2;
                res = max(res, -sg(t));
                t[j] ++;
                t[i + j] -= 2;
                if(res == 1) break;
            }
            t[i] ++;
            if(res == 1) break;
        }
        return res;
    }

    int solve(int *a){
        for(int i = 0; i <= 3; i ++)c[i]=a[i];
        if(sg(c) == 1) return 1;
        else return -1;
    }
}st;
int p[111];
void dfs(int step,int num)
{
    if(step==3)
    {
        p[step]=num;
        printf("(%d %d %d %d %d)\n",p[0],p[1],p[2],p[3],st.solve(p));
        return ;
    }
    else
    {
       for(int i=1;i<=num;i++)
        {
            p[step]=i;
            dfs(step+1,num-i);
        } 
    }
    
}
int main()
{
    p[0]=3;
    dfs(1,7);
}