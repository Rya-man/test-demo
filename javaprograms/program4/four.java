class Person {
    private String name;
    private int age;
    private String gender;

    public Person(String name, int age, String gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getGender() {
        return gender;
    }

    public void displayPersonDetails() {
        System.out.println("Name: " + name + ", Age: " + age + ", Gender: " + gender);
    }
}

class Employee extends Person {
    private String department;
    private double salary;

    public Employee(String name, int age, String gender, String department, double salary) {
        super(name, age, gender);
        this.department = department;
        this.salary = salary;
    }

    public void displayEmployeeDetails() {
        displayPersonDetails();
        System.out.println("Department: " + department + ", Salary: " + salary);
    }
}

class Student extends Person {
    private String course;
    private double grade;

    public Student(String name, int age, String gender, String course, double grade) {
        super(name, age, gender);
        this.course = course;
        this.grade = grade;
    }

    public void displayStudentDetails() {
        displayPersonDetails();
        System.out.println("Course: " + course + ", Grade: " + grade);
    }
}

public class four {
    public static void main(String[] args) {
        Employee emp1 = new Employee("John", 30, "Male", "HR", 60000);
        Employee emp2 = new Employee("Alice", 28, "Female", "Finance", 65000);
        Employee emp3 = new Employee("Bob", 35, "Male", "IT", 70000);
        Employee emp4 = new Employee("David", 40, "Male", "Marketing", 75000);
        Employee emp5 = new Employee("Eve", 32, "Female", "Sales", 55000);

        System.out.println("Employee Details:");
        emp1.displayEmployeeDetails();
        emp2.displayEmployeeDetails();
        emp3.displayEmployeeDetails();
        emp4.displayEmployeeDetails();
        emp5.displayEmployeeDetails();

        System.out.println();

        Student stu1 = new Student("Mike", 21, "Male", "Computer Science", 3.9);
        Student stu2 = new Student("Sophia", 22, "Female", "Electrical Engineering", 3.7);
        Student stu3 = new Student("James", 20, "Male", "Mechanical Engineering", 3.8);
        Student stu4 = new Student("Emma", 23, "Female", "Biology", 3.6);
        Student stu5 = new Student("Lucas", 22, "Male", "Mathematics", 3.95);

        System.out.println("Student Details:");
        stu1.displayStudentDetails();
        stu2.displayStudentDetails();
        stu3.displayStudentDetails();
        stu4.displayStudentDetails();
        stu5.displayStudentDetails();
    }
}
