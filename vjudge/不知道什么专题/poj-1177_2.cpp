#include<iostream>
#include<algorithm>
#include<cmath>
#define Lson (root<<1)
#define Rson (root<<1|1)
//#define int long long

const int offset = 1e4 + 0, space = 5e3 + 7;
int N;
struct kk { int y, rightX, leftX, whi; 
    bool operator <(kk& _RHS)const { 
        if (y == _RHS.y)
            return whi > _RHS.whi; 
        else return y < _RHS.y; 
    } 
};
struct kl{
    int left, right,len;
    int coverNum;
    bool leftCover, rightCover;//左右端点是否被覆盖
    int segNum;//区间有多少条线段
}love[space<<4];
struct kk ali[space << 1];
int discrete[space << 2] = {}, num = 0, ans = 0;

void buildTree(int root, int left, int right)
{
    love[root] = { left,right,0,false,false,0 };
    if (left == right)return;
    int mid = (left + right) >> 1;
    buildTree(Lson, left, mid), buildTree(Rson, mid + 1, right);
}

void pushUp(int root)
{
    if (love[root].coverNum)
    {
        love[root].leftCover = love[root].rightCover = 1;
        love[root].len = discrete[love[root].right + 1] - discrete[love[root].left];
        love[root].segNum = 1;
    }
    else if (love[root].left == love[root].right)
    {
        love[root].leftCover = love[root].rightCover = 0;
        love[root].len = 0;
        love[root].segNum = 0;
    }
    else
    {
        love[root].leftCover = love[Lson].leftCover;
        love[root].rightCover = love[Rson].rightCover;
        love[root].len = love[Lson].len + love[Rson].len;
        love[root].segNum = love[Lson].segNum + love[Rson].segNum - (love[Lson].rightCover & love[Rson].leftCover);
    }

}

void update(int root, int left, int right, int whi)
{
    int l = love[root].left, r = love[root].right;
    int mid = (l + r) >> 1;

    if (left <= l && right >= r)
    {
        love[root].coverNum += whi;
        pushUp(root);
        return;
    }
    if (left <= mid)update(Lson, left, right, whi);
    if (right > mid)update(Rson, left, right, whi);
    pushUp(root);
}


signed main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        //int y, rightX, leftX, whi
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1 += offset, y1 += offset, x2 += offset, y2 += offset;
        discrete[++num] = x1, discrete[++num] = x2;
        ali[i * 2 - 1] = { y1,x2,x1,1 };
        ali[i << 1] = { y2,x2,x1,-1 };
    }

    std::sort(discrete + 1, discrete + 1 + num);
    num = std::unique(discrete + 1, discrete + 1 + num) - discrete - 1;
    std::sort(ali + 1, ali + 1 + (N << 1));

    //离散：
    for (int i = 1; i <= N << 1; i++)
    {
        int pos1 = std::lower_bound(discrete + 1, discrete + 1 + num, ali[i].leftX) - discrete;
        int pos2 = std::lower_bound(discrete + 1, discrete + 1 + num, ali[i].rightX) - discrete;
        ali[i].leftX = pos1, ali[i].rightX = pos2;
    }

    buildTree(1, 1, num);

    int pre = 0;
    for (int i = 1; i <= N << 1; i++)
    {
        update(1, ali[i].leftX, ali[i].rightX - 1, ali[i].whi);
        ans += abs(love[1].len - pre);
        //竖线：[下一条横线的高度-现在这条横线的高度]*2*num
        ans += (ali[i + 1].y - ali[i].y) * 2 * love[1].segNum;
        pre = love[1].len;//每次都要更新上一次总区间覆盖的长度
    }

    std::cout << ans;

    return 0;
}
