public class Student {
    static int num=0;
    int rollno;
    public Student(int n){
        this.rollno=n;
        num++;
    }
 public static void main(String args[])   {
    Student s1=new Student(1);
    System.out.println(Student.num);
    Student s2=new Student(2);
    System.out.println(Student.num);
 }
}
