import java.util.Scanner

fun main() {    // 包级可见的函数，接受一个字符串数组作为参数
   println("Hello World!")         // 分号可以省略
   val read = Scanner(System.`in`)

   var T=read.nextInt()

   while(T>0)
   {
      var n = read.nextInt()
      var a: Int = 0
      var b: Int = 0
      var cnta: Int = 0
      var cntb: Int = 0
      var fa: Int = 0
      var fb: Int = 0
      for (i in 1..n)
      {
         var x=read.nextInt()
         if(x==a)cnta++;
         else if(x==b)cntb++;
         else if(a==0)
         {
            a=x;
            fa=i;
            cnta++;
         }
         else if(b==0)
         {
            b=x;
            fb=i;
            cntb++;
         }
      }
      if(cnta == 1){
         println(fa)
      }
      else{
         println(fb)
      }
      T--
   }
}