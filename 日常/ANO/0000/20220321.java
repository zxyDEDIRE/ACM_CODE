package Demo01;

public class Demo00a {
    import java.io.*;
    //将a.txt的内容复制到b.txt 
    public class Demo {
        public static void main(String []args) throws IOException { 
 【1】=new BufferedReader(new FileReader("a.txt"));
            BufferedWriterbw = new BufferedWriter(【2】);
            String s1=null; 
 【3】 {
                while ((s1=【4】.readLine())!=null){ 
 【5】.write(s1);
                    System.out.print(s1);
                }
            } catch(IOException e) {
            }finally{ bw.close(); br.close(); }
        }
    }
}
