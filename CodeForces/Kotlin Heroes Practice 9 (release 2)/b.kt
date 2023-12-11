import java.util.Scanner
fun main() {    
	var read = Scanner(System.`in`)
	var n=read.nextInt()
	var str=read.next()
	println(n)
	println(str)
	var now :Int= 0
	var s :Int= 1
	var ans = StringBuilder()
	while (now < n) {
		ans.append(str[now])
		now = now + s
		s = s + 1
	}
	println(ans.toString()
}

