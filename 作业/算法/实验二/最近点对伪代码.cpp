const maxn = 1000001
const INF = 2^20
int n, temp[maxn]
struct Point
    x, y
end struct
Point S[maxn]
// 比较函数，按照x值排序，x相等则按y值排序
bool cmp(Point a, Point b)
    if a.x == b.x
        return a.y < b.y
    else
        return a.x < b.x
    end if
end bool
// 比较函数，按照y值排序，用于temp中元素的排序
bool cmps(int a, int b)
    return S[a].y < S[b].y
end bool
// 最小值函数
double min(double a, double b)
    if a < b
        return a
    else
        return b
    end if
end double
// 计算点i和点j之间的距离
double dist(int i, int j)
    x = (S[i].x - S[j].x) ^ 2
    y = (S[i].y - S[j].y) ^ 2
    return sqrt(x + y)
end double
// 递归函数，将点集S从left到right范围内的点分成两个子集
// 计算子集中的最小距离d
double merge(int left, int right)
    // 如果只剩下一个点，则最小距离为INF
    if left = right
        return INF
    end if
    // 如果只剩下两个点，则计算它们之间的距离
    if left + 1 = right
        return dist(left, right)
    end if
    // 左右子集的分界点
    mid = (left + right) / 2
    // 计算左右子集中的最短距离
    d1 = merge(left, mid)
    d2 = merge(mid + 1, right)
    // 取左右子集的最小距离
    d = min(d1, d2)
    // 计算跨越左右子集且距离<=d的点对的距离
    k = 0
    for i from left to right
        // 只考虑在mid左边d距离内和右边d距离内的点
        if fabs(S[i].x - S[mid].x) < d
            temp[k] = i
            k = k + 1
        end if
    end for
    // 按y值排序，方便从上到下扫描temp中的点
    sort(temp, temp + k, cmps)
    // 扫描temp，计算距离<=d的点对的距离
    for i from 0 to k - 1
        for j from i + 1 to k - 1
            if S[temp[j]].y - S[temp[i]].y < d
                d3 = dist(temp[i], temp[j])
                if d > d3
                    d = d3
                end if
            else
                // 如果y方向距离>d，则后面的点不用考虑，因为已按y排好序
                break
            end if
        end for
    end for
    return d
end double