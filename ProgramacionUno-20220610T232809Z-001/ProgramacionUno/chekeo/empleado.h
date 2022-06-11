#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int id;
    char name[21];
    char lastName[21];
    float salary;
    int sector;
    int isEmpty;
}Employee;

#endif // EMPLEADO_H_INCLUDED

int menu();

int initEmployees(Employee list[], int len);

int availability(Employee list[], int len);

int capitalisation(char string[]);

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

int findEmployeeById(Employee list[], int len, int id);

int removeEmployee(Employee list[], int len, int id);

int editEmployee(Employee list[], int len);

int sortEmployees(Employee list[], int len, int order);

void printEmployee(Employee anEmployee, int len);

int printEmployees(Employee list[], int len);

int checkString(char string[], char message[], char errorMessage[], int max);

int checkCharacter(char* character, char message[], char errorMessage[], char validCharacter1, char validCharacter2);

int checkFloat(float* number, char message[], char errorMessage[], float min, float max);

int checkInteger(int* number, char message[], char errorMessage[], int min, int max);

int calculateSalary(Employee list[], int len);
