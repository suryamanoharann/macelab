class Person {
    String name;
    String gender;
    String address;  
    int age;

    public Person(){
        this.name = name;
        this.gender = gender;
        this.address = address;
        this.age = age;
    }

}

class Employee extends Person{
    int empid;
    String companyname;
    String qualification;
    double salary;

    Employee(){

    }
}

class Teacher extends Employee{
    int teacher_id;
    String subject;
    String department
}
