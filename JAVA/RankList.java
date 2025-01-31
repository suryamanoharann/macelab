import java.util.Scanner;

class Student {
    int rollNo;
    String name;
    int marks;


    Student(int rollNo, String name, int marks) {
        this.rollNo = rollNo;
        this.name = name;
        this.marks = marks;
    }


    void display() {
        System.out.println("Roll No: " + rollNo + ", Name: " + name + ", Marks: " + marks);
    }
}

public class RankList {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        System.out.print("Enter the number of students: ");
        int N = sc.nextInt();
        sc.nextLine();  
    
        Student[] students = new Student[N];

        for (int i = 0; i < N; i++) {
            System.out.println("Enter details for student " + (i + 1));
            System.out.print("Roll No: ");
            int rollNo = sc.nextInt();
            sc.nextLine();  
            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Marks: ");
            int marks = sc.nextInt();
            sc.nextLine();  

          
            students[i] = new Student(rollNo, name, marks);
        }


        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (students[j].marks < students[j + 1].marks) {  
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }


        System.out.println("\nRanklist:");
        for (int i = 0; i < N; i++) {
            System.out.print("Rank " + (i + 1) + ": ");
            students[i].display();
        }

        sc.close();
    }
}
