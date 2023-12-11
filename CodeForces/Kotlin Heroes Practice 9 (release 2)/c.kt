以下是将上述C++代码转换为Kotlin的版本：

kotlin
复制
fun main() {   
	val read = Scanner(System.`in`)   
	var p = IntArray(200) // 根据输入最大值n动态分配数组长度    
	var n=read.nextInt()    
	for (i in 1..n) {        
		val x = scanner.nextInt()        
		p[i] = x    
	}    
	Arrays.sort(p, 0, n) // 使用Java的Arrays.sort()函数排序    
	var ans = 0    
	for (i in 0 until n by 2) 
	{        
		ans += p[i + 1] - p[i]    
	}    
	println(ans) // 输出结果到控制台
}

