#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[30];
    float basic;
    float gross;
};

struct Salary_Config {
    int hra;
    int da;
};

int main() {

    int n, i;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee *emp = (struct Employee *)malloc(n * sizeof(struct Employee));
    struct Salary_Config config;

    printf("\nConfigure Salary:\n");
    printf("- Set HRA perentage: ");
    scanf("%d", &config.hra);
    printf("- Set DA perentage: ");
    scanf("%d", &config.da);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("Employee %d\n\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", &emp[i].name);
        printf("Basic Pay: Rs. ");
        scanf("%f", &emp[i].basic);
        emp[i].gross = (emp[i].basic) + ((config.da/100)*emp[i].basic) + ((config.hra/100)*emp[i].basic);
    }

    printf("\nEmployee Details:\n");
    for (i = 0; i < n; i++) {
        printf("ID\tName\tBasic Pay\tGrosss Pay");
        printf("%d\t%s\t%.2f\t%.2f\n", emp[i].id, emp[i].name, emp[i].basic, emp[i].gross);
    }

    free(emp);
    return 0;
}
