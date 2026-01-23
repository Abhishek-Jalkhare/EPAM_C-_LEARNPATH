#include <stdio.h>
#include<string.h>

struct Employee
{
    char name[50];
    int employee_id;
    float salary;
    /* data */
};

void printEmployeeDetails (struct Employee e ){
    printf("Employee Name : %s \n" , e.name);
    printf("Employee ID : %i \n" , e.employee_id);
    printf("Salary : %.2f" , e.salary);
    
}


int main(int argc, char const *argv[])
{
    //struct Employee e = {"John Doe", 12345, 55000.50};  this is valid because it is intialisation not assingment
  struct Employee e;
 // e.name = "John Doe"; invalid bacuse we can not assign literal using = operator so we method such as strcopy
  strcpy(e.name, "John Doe");
  e.employee_id = 12345;
    e.salary = 55000.50;

    printEmployeeDetails(e);


    struct Employee staff [4];
    for(int i=0;i<4;i++){
        printf("Enter details for employee %d\n", i+1);
        printf("Enter name: ");
        char name[50];
        scanf("%s", name);
        strcpy(staff[i].name, name);
        printf("Enter employee ID: ");
        scanf("%d", &staff[i].employee_id);
        printf("Enter salary: ");
        scanf("%f", &staff[i].salary);
    }

    for (int i = 0; i < 4; i++)
    {
        printEmployeeDetails(staff[i]);
    }
    

    return 0;
}
