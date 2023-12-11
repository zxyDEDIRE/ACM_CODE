
#include <cstdio>
#include <cstring>
int const MAX = 200005;
int const MAX2 = 4000;
bool has[MAX2];
int fa[MAX2], out[MAX2], in[MAX2], path[MAX], e[MAX2][MAX2];
int n, len, st;
struct node
{
    int u, v;
    char name[3];
}r[MAX];
 
int abs(int x)
{
    return x > 0 ? x : -x;
}
 
void UF_set()
{
    for(int i = 0; i < MAX2; i++)
        fa[i] = i;
}
 
int Find(int x)
{
    return x == fa[x] ? x : fa[x] = Find(fa[x]); 
}
 
void Union(int a, int b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if(r1 != r2)
        fa[r1] = r2;
}
 
int ctoi(char ch)
{ 
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;  
    if(ch >= 'a' && ch <= 'z') return ch - 'a' + 36;  
    return ch - '0';  
}
 
char itoc(int a)
{
    if(a >= 0 && a <= 9) return '0' + a;
    if(a >= 10 && a <= 35) return 'A' + a - 10;
    return 'a' + a - 36;
}
 
bool Exist()
{
    int t = -1;
    for(int i = 0; i < MAX2; i++)
    {
        if(has[i])
        {
            if(t == -1)
                t = Find(i);
            else if(Find(i) != t)
                return false;
        }
    }
    int sum = 0, tmp;
    for(int i = 0; i < MAX2; i++)
    {
        if(has[i])
        {
            tmp = i;
            if(in[i] != out[i])
            {
                sum++;
                if(abs(in[i] - out[i]) > 1)
                    return false;
                if(out[i] > in[i])
                    st = i;
            }
        }
    }
    if(sum > 2)
        return false;
    if(sum == 0)
        st = tmp;
    return true;
}
 
void DFS(int now)
{
    for(int i = 0; i < MAX2; i++)
    {
        while(e[now][i])
        {
            e[now][i]--;
            DFS(i);
            path[len++] = i;
        }
    }
}
 
int main()
{
    scanf("%d", &n);
    UF_set();
    memset(e, 0, sizeof(e));
    for(int i = 0; i < n; i++)
    {
        scanf("%s", r[i].name);
        r[i].u = ctoi(r[i].name[0]) * 62 + ctoi(r[i].name[1]);
        r[i].v = ctoi(r[i].name[1]) * 62 + ctoi(r[i].name[2]);
        has[r[i].u] = true;
        has[r[i].v] = true;
        Union(r[i].u, r[i].v);
        out[r[i].u]++;
        in[r[i].v]++;
        e[r[i].u][r[i].v]++;
    }
    if(!Exist())
        printf("NO\n");
    else
    {   
        len = 0;
        DFS(st);
        path[len++] = st;
        printf("YES\n");
        printf("%c%c", itoc(path[len - 1] / 62), itoc(path[len - 1] % 62));
        for(int i = len - 2; i >= 0; i--)
            printf("%c", itoc(path[i] % 62));
        printf("\n");
   }
}
