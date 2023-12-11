>aabaaaab

>1.aabaaaab
>2.abaaaab
>3.baaaab
>4.aaaab
>5.aaab
>6.aab
>7.ab
>8.b

>4.aaaab
>5.aaab
>6.aab
>1.aabaaaab
>7.ab
>2.abaaaab
>8.b
>3.baaaab


### 后缀数组sa
sa[i]表示排序为i的后缀的编号

### 名次数组rk
rk[i]表示后缀i的排名

### 高度数组
height=lcp(sa[i],sa[i-1])
第i名后缀和第i-1名后缀的最长公共前缀的长度
height[2]=lcp(5,4)=3
height[3]=lcp(6,5)=2
height[4]=lcp(1,6)=3

高度数组表示两个后缀的相似度

排序相邻的两个后缀相似度最高

### void get_sa()

利用倍增和桶排序，计算sa

### void get_height()

利用sap[]和height[]，计算height[]

~~~cpp
const int N=1e5;
int n,m;//n为后缀的个数 m为桶的个数
int x[N],y[N],c[N],sa[N],rk[N],height[N];
//桶数组x[i] 辅助数组y[i] 计数数组c[i]
int s[N];//原数组
void get_sa()
{
    int i,j,k;
    //按照第一个字母排序
    for(int i=1;i<=n;i++)c[x[i]==s[i]]++;
    for(int i=1;i<=m;i++)c[i]+=c[i-1];
    //第一次计算sa值
    for(int i=n;i;i--)sa[x[c[i]]--];//后缀i的排序的i所在桶号的剩余累计值
    for(int k=1;k<=n;k<<=1){//log轮次
        //按照第二关键字排序
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)y[i]=sa[i];
        //向右偏移一位获取第二关键字的桶号并累计
        for(int i=1;i<=n;i++)c[x[y[i]+k]]++;
        for(int i=1;i<=m;i++)c[i]+=c[i-1];
        //后缀y[i]的排序是第二关键字所在桶号的剩余累计值
        for(int i=n;i;i--)sa[x[c[y[i]+k]]--]=y[i];
        //按照第一关键字排序
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)y[i]=sa[i];
        //获取第一关键字的桶号并累计
        for(int i=1;i<=n;i++)c[x[y[i]]]++;
        for(int i=1;i<=m;i++)c[i]+=c[i-1];
        //后缀y[i]的排序是第一关键字所在桶号的剩余累计值
        for(int i=n;i;i--)sa[c[x[y[i]]]--]=y[i];
        //把后缀放入桶数组
        for(int i=1;i<=n;i++)y[i]=x[i];
        for(m=0,i=1;i<=n;i++)
            if(y[sa[i]]==y[sa[i-1]]&&
              y[sa[i]+k]==y[sa[i-1]+k])x[sa[i]]=m;
        	else x[sa[i]]=++m;
        //给2字符的关键字编桶号 相邻后缀的关键字不相等则放入新桶
        if(m==n)break;//已经排序完成
    }
}
~~~

> 后缀i的前相邻后缀一定是sa[rk[i]-1]
>
> 因为i=sa[rk[i]],i的排名为rk[i]，排名减1取sa既得
>
> 例如sa[rk[1]-1]=sa[4-1]=sa[3]=6;

>height[rk[i]]>=height[rk[i-1]]-1

~~~cpp
void get_height(){
    for(int i=1;i<=n;i++)rk[sa[i]]=i;
    for(int i=1,k=0;i<=n;i++){//枚举后缀i
        if(rk[i]==1)continue;//第一名height为0
        if(k)k--;//上一个后缀的height值减一
        int j=sa[rk[i]-1];//找出后缀i的前邻后缀j
        while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k])k++;
        height[rk[i]]=k;
    }
}
/*
k++总共不会超过n次
k--总共不会超过n次
所以最多跑2n次
时间复杂度O(n)
*/
~~~

