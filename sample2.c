#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
struct Employee
{
    char Emp_Name[100];
    char Emp_id[10];
    char Emp_department[3];
    float Emp_salary;

};
void readdata(struct Employee *a){
    static int x =1;
    printf("\nENter name %d\t",x);
    scanf("%s",a->Emp_Name);
    printf("ENter id %d\t",x);
    scanf("%s",a->Emp_id);
    printf("ENter department %d\t",x);
    scanf("%s",a->Emp_department);
    printf("ENter salary %d\t",x);
    scanf("%f",&a->Emp_salary);
    x++;
}
float total(struct Employee *a,char dep[3])
{
    if(!strcmp(a->Emp_department,dep))
    {
        return a->Emp_salary;
    }
    else return 0;
}
void display(struct Employee *a)
{
    static int df = 1;
    printf("\n\nEmployee %d Name :\t%s\nEmployee %d id :\t%s\nEmployee %d Department :\t%s\nEmployee %d Salary :\t%f\n",df,a->Emp_Name,df,a->Emp_id,df,a->Emp_department,df,a->Emp_salary); 
}
int main()
{
    struct Employee a[10];
    int n,sum=0;char dep[3];
    printf("ENTER NUMBER OF EMPLOYEES\n"); scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        readdata(&a[i]);
    //   display(&a);
    }
    printf("\nenter department to find the total\t");
    scanf("%s",dep);
    for(int i=0;i<n;i++)
    {
        sum+=total(&a[i],dep);
    }
    printf("\nTotal for this department is %f",sum);
    return 0;
//printf("%f",a->Emp_salary);
}