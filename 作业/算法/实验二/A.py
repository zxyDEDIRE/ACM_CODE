def qsort(l, r, a):
	mid = a[(l + r) // 2] # 中间数
	i = l
	j = r
	while i <= j:
		while a[i] < mid:
			i += 1 # 查找左半部分比中间数大的数
		while a[j] > mid:
			j -= 1 # 查找右半部分比中间数小的数
		if i <= j:
			a[i], a[j] = a[j], a[i] # 交换
			i += 1
			j -= 1
	if l < j:
		qsort(l, j, a) # 递归搜索左半部分
	if i < r:
		qsort(i, r, a) # 递归搜索右半部分	