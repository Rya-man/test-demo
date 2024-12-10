import java.util.*;

class Employee {
    String name;
    int empId;
    String department;
    int age;
    String designation;
    double salary;

    public Employee(String name, int empId, String department, int age, String designation, double salary) {
        this.name = name;
        this.empId = empId;
        this.department = department;
        this.age = age;
        this.designation = designation;
        this.salary = salary;
    }
}

public class two {
    public static void main(String[] args) {
        List<Employee> employees = new ArrayList<>();
        
        employees.add(new Employee("John", 101, "Sales", 28, "Sales Manager", 60000));
        employees.add(new Employee("Alice", 102, "Sales", 30, "Sales Executive", 50000));
        employees.add(new Employee("Bob", 103, "Purchase", 35, "Manager", 70000));
        employees.add(new Employee("Charlie", 104, "HR", 25, "HR Executive", 45000));
        employees.add(new Employee("David", 105, "Purchase", 40, "Manager", 75000));
        
        System.out.println("Employee Details:");
        for (Employee emp : employees) {
            System.out.println("Name: " + emp.name + ", Emp ID: " + emp.empId + ", Department: " + emp.department +
                               ", Age: " + emp.age + ", Designation: " + emp.designation + ", Salary: " + emp.salary);
        }
        
        double salesSalarySum = 0;
        for (Employee emp : employees) {
            if (emp.department.equalsIgnoreCase("Sales")) {
                salesSalarySum += emp.salary;
            }
        }
        System.out.println("\nTotal Salary of Employees in Sales Department: " + salesSalarySum);
        
        Employee highestPaidManager = null;
        for (Employee emp : employees) {
            if (emp.department.equalsIgnoreCase("Purchase") && emp.designation.equalsIgnoreCase("Manager")) {
                if (highestPaidManager == null || emp.salary > highestPaidManager.salary) {
                    highestPaidManager = emp;
                }
            }
        }
        
        if (highestPaidManager != null) {
            System.out.println("\nHighest Paid Manager in Purchase Department:");
            System.out.println("Name: " + highestPaidManager.name + ", Emp ID: " + highestPaidManager.empId +
                               ", Salary: " + highestPaidManager.salary);
        } else {
            System.out.println("\nNo Manager found in the Purchase Department.");
        }
    }
}
