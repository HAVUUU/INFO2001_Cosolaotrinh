#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50

struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    char position[MAX_NAME_LENGTH];
    float salary;
};

void displayEmployee(struct Employee employee) {
    printf("ID: %d\n", employee.id);
    printf("Ten: %s\n", employee.name);
    printf("Chuc vu: %s\n", employee.position);
    printf("Luong: %.2f\n", employee.salary);
    printf("\n");
}

void addEmployee(struct Employee employees[], int *numEmployees) {
    if (*numEmployees == MAX_EMPLOYEES) {
        printf("Khong the them nhan vien vi da den gio han.\n");
        return;
    }

    struct Employee newEmployee;

    printf("Nhap thong tin cho nhan vien:\n");
    printf("ID: ");
    scanf("%d", &newEmployee.id);
    getchar();

    printf("Ten: ");
    fgets(newEmployee.name, sizeof(newEmployee.name), stdin);
    newEmployee.name[strcspn(newEmployee.name, "\n")] = '\0'; 
    
    printf("Chuc vu: ");
    fgets(newEmployee.position, sizeof(newEmployee.position), stdin);
    newEmployee.position[strcspn(newEmployee.position, "\n")] = '\0'; 

    printf("Luong: ");
    scanf("%f", &newEmployee.salary);
    getchar();

    employees[*numEmployees] = newEmployee;
    (*numEmployees)++;

    printf("Them thanh cong nhan vien moi.\n");
}

void deleteEmployee(struct Employee employees[], int *numEmployees, int id) {
    int index = -1;

    for (int i = 0; i < *numEmployees; i++) {
        if (employees[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay nhan vien voi ID %d .\n", id);
        return;
    }

    for (int i = index; i < (*numEmployees) - 1; i++) {
        employees[i] = employees[i + 1];
    }

    (*numEmployees)--;

    printf("Nhan vien duoc xoa thanh cong.\n");
}

void editEmployee(struct Employee employees[], int numEmployees, int id) {
    int index = -1;

    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay nhan vien voi ID %d .\n", id);
        return;
    }

    struct Employee *employee = &employees[index];

    printf("Nhap thong tin moi cho nhan vien voi ID %d:\n", id);
    printf("Ten: ");
    fgets(employee->name, sizeof(employee->name), stdin);
    employee->name[strcspn(employee->name, "\n")] = '\0';

    printf("Chuc vu: ");
    fgets(employee->position, sizeof(employee->position), stdin);
    employee->position[strcspn(employee->position, "\n")] = '\0';

    printf("Luong: ");
    scanf("%f", &employee->salary);
    getchar();

    printf("Thong tin nhan vien duoc chinh sua thanh cong.\n");
}

void displayAllEmployees(struct Employee employees[], int numEmployees) {
    printf("Danh sach nhan vien:\n");

    for (int i = 0; i < numEmployees; i++) {
        printf("Nhan vien %d:\n", i + 1);
        displayEmployee(employees[i]);
    }
}

void sortEmployeesByName(struct Employee employees[], int numEmployees) {
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = 0; j < numEmployees - i - 1; j++) {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    printf("Danh sach nhan vien da duoc sap xep theo bang chu cai.\n");
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;
    int choice;
    int id;

    do{
        printf("CHUONG TRINH QUAN LI NHAN VIEN\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Chinh sua nhan vien\n");
        printf("4. Hien thi toan bo nhan vien\n");
        printf("5. Sap xep nhan vien theo ten\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2:
                printf("Nhap ID cua nhan vien muon xoa: ");
                scanf("%d", &id);
                deleteEmployee(employees, &numEmployees, id);
                break;
            case 3:
                printf("Nhap ID cua nhan vien muon chinh sua: ");
                scanf("%d", &id);
                editEmployee(employees, numEmployees, id);
                break;
            case 4:
                displayAllEmployees(employees, numEmployees);
                break;
            case 5:
                sortEmployeesByName(employees, numEmployees);
                break;
            case 6:
                printf("Thoat khoi chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le vui long chon so tu 1 den 6.\n");
                break;
        }

        printf("\n");
    } while (choice != 6);

    return 0;
}
