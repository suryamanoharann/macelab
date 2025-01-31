import java.util.Scanner;

class Student {
    int rollno;
    String name;
    int marks;
    static int Count = 0;

    public Student(){
        Scanner sc=new Scanner(System.in);
        System.out.println("rollno:");
        rollno=sc.nextInt();
        sc.nextLine();
        System.out.println("name:");
        name=sc.nextLine();
        System.out.println("marks:");
        marks=sc.nextInt();
        Count++;
    }
    public Student(int rollno,String name,int marks){
        this.rollno=rollno;
        this.name=name;
        this.marks=marks;
        Count++;
    }
    public Student(Student other){
        this.rollno=other.rollno;
        this.name=other.name;
        this.marks=other.marks;
        Count++;
    }
    public void displayStd(){
        System.out.println(name+" "+marks);
    }
    public static void displayCount(){
        System.out.println("No of students:"+Count);

    }
}
public class StudentDemo{
    public static void sortStd(Student s[]){
        int n=Student.Count;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                if(s[i].marks<s[j].marks){
                    Student temp=s[i];
                    s[i]=s[j];
                     s[j]=temp;

                }
            }
    }
    public static void main(String args[]){
        Student s[]=new Student[10];
        for(int i=0;i<5;i++)
            s[i]=new Student();
        sortStd(s);
        for(int i=0;i<5;i++)
        {
            System.out.print(i+1+" ");

            s[i].displayStd();
        }
    }
}


    


