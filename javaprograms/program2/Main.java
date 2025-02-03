import java.util.*;

class Employee{
    String name;
    int Emp_id;
    String dep;
    int age;
    String des;

    Employee(String n,int e,String d,int a,String de)
    {
        name = n;
        Emp_id = e;
        dep = d;
        age = a;
        des = de;
    }
}


public class Main {

    public static void main(String[] args) {
        List<Employee> e = new ArrayList<>();
        e.add(new Employee("alice", 1, "ull", 021, "null"));
        e.add(new Employee("alice", 1, "ull", 021, "null"));
        e.add(new Employee("alice", 1, "ull", 021, "null"));
        e.add(new Employee("alice", 1, "ull", 021, "null"));
        e.add(new Employee("alice", 1, "ull", 021, "null"));

    
    }
    
}