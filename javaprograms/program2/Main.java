import java.util.*;

class Main{
    public static void main(String[] args) {
        List<Employee> e = new ArrayList<>();
    }
}
class Employee{
    public String Name,Department,Designation;
    public int age,emp_id,salary;
    public Employee()
    {
        Name = "";
        Department = "";
        Designation = "";
        age = 0;
        emp_id = 0;
        salary=0;
    }
    public Employee(String n,String d,String D,int a,int e,int s)
    {
        Name = n;
        Department = d;
        Designation = D;
        age = a;
        emp_id = e;
        salary=s;
    }
}
