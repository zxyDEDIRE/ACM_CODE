
import java.io.IOException;
import java.io.Serializable;
import java.util.Scanner;

import static java.lang.System.*;

//老师
class Teacher implements Serializable {
    private String JobNumber;
    private String Name;
    private String Title;
    Teacher(){
        JobNumber="";
        Name="";
        Title="";
    }
    public void add_JobNumber(String JobNumber){
        this.JobNumber=JobNumber;
    }
    public void add_Name(String Name){
        this.Name=Name;
    }
    public void add_Title(String Title){
        this.Title=Title;
    }
    public String get_JobNumber(){
        return this.JobNumber;
    }
    public String get_Name(){
        return this.Name;
    }
    public String get_Title(){
        return this.Title;
    }
}
//学生
class Student implements Serializable{
    private String StudentID;
    private String Name;
    private String Major;
    Student(){
        StudentID="";
        Name="";
        Major="";
    }
    public void add_StudentID(String StudentId){
        this.StudentID=StudentId;
    }
    public void add_Name(String Name){
        this.Name=Name;
    }
    public void add_Major(String Major){
        this.Major=Major;
    }
    public String get_StudentID(){
        return this.StudentID;
    }
    public String get_Name(){
        return this.Name;
    }
    public String get_Major(){
        return this.Major;
    }
}
//本科生
class UnderGraduate extends Student implements Serializable{
    private String Class;
    private String StartYear;
    private String Clooege;
    private String Course;
    UnderGraduate() {
        super();
        Class = "";
        StartYear = "";
        Clooege = "";
        Course = "";
    }
    public void add_Class(String Class){
        this.Class=Class;
    }
    public void add_StartYear(String StartYear){
        this.StartYear=StartYear;
    }
    public void add_Clooege(String Clooege){
        this.Clooege=Clooege;
    }
    public void add_Course(String Course){
        this.Course=Course;
    }
    public String get_Class(){
        return this.Class;
    }
    public String get_StarYear(){return this.StartYear;}
    public String get_Clooege(){return this.Clooege;}
    public String get_Couerse(){return this.Course;}
}
//研究生
class PostGraduate extends Student implements Serializable{
    private String Tutor;
    private String School;
    private String Registered;
    private String StartYear;
    private String EnterYear;
    PostGraduate(){
        super();
        Tutor="";
        School="";
        Registered="";
        StartYear="";
        EnterYear="";
    }
    public void add_Tutor(String Tutor){this.Tutor=Tutor;}
    public void add_School(String School){this.School=School;}
    public void add_Registered(String Registered){this.Registered=Registered;}
    public void add_StartYear(String StartYear){this.StartYear=StartYear;}
    public void add_EnterYear(String EnterYear){this.EnterYear=EnterYear;}
    public String get_Tutor(){return Tutor;}
    public String get_School(){return School;}
    public String get_Registered(){return Registered;}
    public String get_StartYear(){return StartYear;}
    public String get_EnterYear(){return EnterYear;}
}
//成教生
class AdultStu extends Student implements Serializable{
    String Class;
    String StartYear;
    String Station;//所在函授站
    String Couerse;//课程
    public void add_Class(String Class){this.Class=Class;}
    public void add_StartYear(String StartYear){this.StartYear=StartYear;}
    public void add_Station(String Station){this.Station=Station;}
    public void add_Course(String Course){this.Couerse=Course;}
    public String get_Class(){return this.Class;}
    public String get_SartYear(){return this.StartYear;}
    public String get_Station(){return this.Station;}
    public String get_Course(){return this.Couerse;}
}



//TOT
class TOT {
    private Teacher[] th;
    private UnderGraduate[] un;
    private PostGraduate[] po;
    private AdultStu[] ad;
    private int thnum;
    private int unnum;
    private int ponum;
    private int adnum;
    TOT(){
        th = new Teacher[1010];
        un = new UnderGraduate[4000];
        po = new PostGraduate[100];
        ad = new AdultStu[2000];
        thnum = 0;
        unnum = 0;
        ponum = 0;
        adnum = 0;
    }

    public void File_OUT() throws IOException {
        Teacher[] in_tea=new Teacher[thnum];
        UnderGraduate[] in_und=new UnderGraduate[unnum];
        PostGraduate[] in_pos=new PostGraduate[ponum];
        AdultStu[] in_adu=new AdultStu[adnum];
        if (thnum >= 0) arraycopy(th, 0, in_tea, 0, thnum);
        if (unnum >= 0) arraycopy(un, 0, in_und, 0, unnum);
        if (ponum >= 0) arraycopy(po, 0, in_pos, 0, ponum);
        if (adnum >= 0) arraycopy(ad, 0, in_adu, 0, adnum);
        FILE.FIN_Teacher(in_tea);
        FILE.FIN_UnderGraduate(in_und);
        FILE.FIN_PostGraduate(in_pos);
        FILE.FIN_AdultStu(in_adu);
    }
    public void File_IN() throws IOException, ClassNotFoundException {
        File_Teacher();
        File_UnderGraduate();
        File_PostGraduate();
        File_AdultStu();
    }

    private void File_Teacher() throws IOException, ClassNotFoundException {
        Teacher[] tha=FILE.File_Teacher();
        int len=tha.length;
        arraycopy(tha, 0, th, 0, len);
        thnum+=len;
    }
    private void File_UnderGraduate() throws IOException, ClassNotFoundException {
        UnderGraduate[] und=FILE.File_UnderGraduate();
        int len=und.length;
        arraycopy(und, 0, un, 0, len);
        unnum+=len;
    }
    private void File_PostGraduate() throws IOException, ClassNotFoundException {
        PostGraduate[] pos=FILE.File_PostGraduate();
        int len=pos.length;
        arraycopy(pos, 0, po, 0, len);
        ponum+=len;
    }
    private void File_AdultStu() throws IOException, ClassNotFoundException {
        AdultStu[] adu=FILE.File_AdultStu();
        int len=adu.length;
        arraycopy(adu, 0, ad, 0, len);
        adnum+=len;
    }

    public void add_Teacher() {
        out.println();
        Scanner in=new Scanner(System.in);
        th[thnum]=new Teacher();
        String str;
        out.println("请输入工号");
        str=in.nextLine();
        th[thnum].add_JobNumber(str);
        out.println("请输入姓名");
        str=in.nextLine();
        th[thnum].add_Name(str);
        out.println("请输入职称");
        str=in.nextLine();
        th[thnum].add_Title(str);
        thnum++;
    }
    public void add_UnderGraduate(){
        out.println();
        Scanner in=new Scanner(System.in);
        un[unnum]=new UnderGraduate();
        out.println("请输入学生学号");
        un[unnum].add_StudentID(in.nextLine());
        out.println("请输入学生姓名");
        un[unnum].add_Name(in.nextLine());
        out.println("请输入学生专业");
        un[unnum].add_Major(in.nextLine());
        out.println("请输入学生班级");
        un[unnum].add_Class(in.nextLine());
        out.println("请输入学生入学年份");
        un[unnum].add_StartYear(in.nextLine());
        out.println("请输入学生所在学院");
        un[unnum].add_Clooege(in.nextLine());
        out.println("请输入学生所选课程");
        un[unnum].add_Course(in.nextLine());
        unnum++;
    }
    public void add_PostGraduate(){
        out.println();
        Scanner in=new Scanner(System.in);
        po[ponum]=new PostGraduate();
        out.println("请输入学生学号");
        po[ponum].add_StudentID(in.nextLine());
        out.println("请输入学生姓名");
        po[ponum].add_Name(in.nextLine());
        out.println("请输入学生专业");
        po[ponum].add_Major(in.nextLine());
        out.println("请输入学生导师");
        po[ponum].add_Tutor(in.nextLine());
        out.println("请输入学生学籍所在学校");
        po[ponum].add_School(in.nextLine());
        out.println("请输入学生入学年份");
        po[ponum].add_StartYear(in.nextLine());
        out.println("请输入学生入长沙学院时间");
        po[ponum].add_EnterYear(in.nextLine());
        ponum++;
    }
    public void add_AdultStu(){
        out.println();
        Scanner in=new Scanner(System.in);
        ad[adnum]= new AdultStu();
        out.println("请输入学生学号");
        ad[adnum].add_StudentID(in.nextLine());
        out.println("请输入学生姓名");
        ad[adnum].add_Name(in.nextLine());
        out.println("请输入学生专业");
        ad[adnum].add_Major(in.nextLine());
        out.println("请输入学生班级");
        ad[adnum].add_Class(in.nextLine());
        out.println("请输入学生入学年份");
        ad[adnum].add_StartYear(in.nextLine());
        out.println("请输入学生所在函授站");
        ad[adnum].add_Station(in.nextLine());
        out.println("请输入学生所选课程");
        ad[adnum].add_Course(in.nextLine());
        adnum++;
    }

    public void show_Teacher(){
        for(int i=0;i<thnum;i++)
        {
            out.println("老师编号: "+i);
            out.println("老师工号: "+th[i].get_JobNumber());
            out.println("老师姓名: "+th[i].get_Name());
            out.println("老师职称: "+th[i].get_Title());
            out.println();
        }
    }
    public void show_UnderGraduate(){
        for(int i=0;i<unnum;i++)
        {
            out.println("本科生编号："+i);
            out.println("本科生学生姓名："+un[i].get_Name());
            out.println("本科生学生学号："+un[i].get_StudentID());
            out.println("本科生学生专业："+un[i].get_Major());
            out.println("本科生学生班级："+un[i].get_Class());
            out.println("本科生学生入学年份："+un[i].get_StarYear());
            out.println("本科生学生所在学院："+un[i].get_Clooege());
            out.println("本科生学生课程："+un[i].get_Couerse());
            out.println();
        }
    }
}


public class STORAGE {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        TOT x=new TOT();
        x.File_IN();
        x.show_UnderGraduate();
    }
}
