 输入：n（物品数量），m（最大重量），w（重量数组），v（价值数组）
    输出：ans（最大值）

    ans = 0
    for i = 0 to 2^n - 1:
        cos = 0
        val = 0
        for j = 0 to n - 1:
            if i & (1 << j) != 0:
                cos += w[j]
                val += v[j]
        if cos <= m:
            ans = max(ans, val)
    打印 ans