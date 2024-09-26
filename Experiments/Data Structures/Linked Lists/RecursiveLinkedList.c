#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct Employee {
    char name[10];
    struct Employee *next;
} Employee;

void listEmployees(Employee *traverse)
{   
    while(traverse){
        printf("%s\n",traverse->name);
        traverse = traverse->next;
    }
    return;
}
Employee* addEmployee(Employee *previous, int size_l)
{   
    Employee *new_employee = (Employee*)malloc(sizeof(Employee));
    if(size_l == 1)
    {
        return new_employee;
    }
    new_employee-> next = NULL;
    previous->next = new_employee;
    char given_name[15];
    scanf("%s",given_name);
    strcpy(new_employee->name,given_name);
    return(addEmployee(new_employee,size_l-1));
}

int main(){
    char cast_name[15] = "Miau da Gloria";
    Employee *first = (Employee*)malloc(sizeof(Employee));
    strcpy(first->name, cast_name);

    Employee *second = (Employee*)malloc(sizeof(Employee));
    strcpy(second->name, cast_name);
    
    first->next = second;
    int size_l = 10;
    scanf("Informe o tamanho do loop:\n", &size_l);
    Employee *last = addEmployee(second,size_l);
    printf("-- EMPREGADOS:\n");
    listEmployees(first);
       
    return 0;
}