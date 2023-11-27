#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char Emp_Name[100];
    char Emp_id[10];
    char Emp_department[50];
    float Emp_salary;
};

void readdata(struct Employee *a, int index) {
    printf("\nEnter details for Employee %d:\n", index + 1);
    printf("Enter name: ");
    scanf("%s", a->Emp_Name);
    printf("Enter id: ");
    scanf("%s", a->Emp_id);
    printf("Enter department: ");
    scanf("%s", a->Emp_department);
    printf("Enter salary: ");
    scanf("%f", &a->Emp_salary);
}

float total(struct Employee *a, int n, char dep[]) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].Emp_department, dep) == 0) {
            sum += a[i].Emp_salary;
        }
    }
    return sum;
}

void display(struct Employee *a, int n) {
    printf("\nEmployee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d Name: %s\nEmployee %d id: %s\nEmployee %d Department: %s\nEmployee %d Salary: %f\n\n",
               i + 1, a[i].Emp_Name, i + 1, a[i].Emp_id, i + 1, a[i].Emp_department, i + 1, a[i].Emp_salary);
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee *employees = malloc(n * sizeof(struct Employee));
    if (employees == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        readdata(&employees[i], i);
    }

    char dep[50];
    printf("\nEnter department to find the total salary: ");
    scanf("%s", dep);

    float total_salary = total(employees, n, dep);
    printf("\nTotal salary for department %s: %.2f\n", dep, total_salary);

    display(employees, n);

    free(employees); // Free dynamically allocated memory
    return 0;
}
