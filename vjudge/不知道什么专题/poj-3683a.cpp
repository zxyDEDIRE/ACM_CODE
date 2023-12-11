#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int a[55][55];
int w[55*55][55*55];
int lx[55*55];
int ly[55*55];
int vx[55*55];
int vy[55*55];
int match[55*55];
int n,m,low;
int find(int u)
{
    vx[u]=1;
    for(int i=0;i<n*m;i++)
    {
        if(vy[i]==1)continue;
        int tmpp=lx[u]+ly[i]-w[u][i];
        if(tmpp==0)
        {
            vy[i]=1;
            if(match[i]==-1||find(match[i]))
            {
                match[i]=u;
                return 1;
            }
        }
        else if(tmpp<low)low=tmpp;
    }
    return 0;
}
void KM()
{
    memset(match,-1,sizeof(match));
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n*m;j++)
        {
            lx[i]=max(lx[i],w[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            memset(vx,0,sizeof(vx));
            memset(vy,0,sizeof(vy));
            low=0x3f3f3f3f;
            if(find(i))break;
            for(int j=0;j<n*m;j++)
            {
                if(vx[j])lx[j]-=low;
                if(vy[j])ly[j]+=low;
            }
        }
    }
    double sum=0;
    for(int i=0;i<n*m;i++)
    {
        if(match[i]==-1)continue;
        sum+=w[match[i]][i];
    }
    printf("%.6f\n",-sum/n);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<n;k++)
                {
                    w[i][j+k*m]=-(a[i][j]*(k+1));
                }
            }
        }
        KM();
    }
}
/*
3

3 4
100 100 100 1
99 99 99 1
98 98 98 1

3 4
1 100 100 100
99 1 99 99
98 98 1 98

3 4
1 100 100 100
1 99 99 99
98 1 98 98
*/