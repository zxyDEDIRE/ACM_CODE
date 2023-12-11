归并排序(p[], l, r):
    输入：p[]（一个数组），l（左边界），r（右边界）
    输出：t（逆序对数量）

    if l >= r:
        return 0
    t = 0
    mid = (l + r) / 2
    t = 归并排序(p, l, mid) + 归并排序(p, mid + 1, r)
    temp[r - l + 1]
    k = 0
    i = l
    j = mid + 1
    while i <= mid and j <= r:
        if p[i] <= p[j]:
            temp[k] = p[i]
            k += 1
            i += 1
        else:
            t += mid - i + 1
            temp[k] = p[j]
            k += 1
            j += 1
    while i <= mid:
        temp[k] = p[i]
        k += 1
        i += 1
    while j <= r:
        temp[k] = p[j]
        k += 1
        j += 1

    for i=l to r:
        p[i] = temp[i - l]

    return t
