#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20

struct Student {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    int age;
};

void displayStudent(struct Student student) {
    printf("Ma sinh vien: %s\n", student.id);
    printf("Ten sinh vien: %s\n", student.name);
    printf("Tuoi cua sinh vien: %d\n", student.age);
    printf("\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;
    char id[MAX_ID_LENGTH];

    do {
        printf("CHUONG TRINH QUAN LI SINH VIEN\n");
        printf("1. Khoi tao danh sach sinh vien\n");
        printf("2. Them sinh vien vao danh sach\n");
        printf("3. Hien thi toan bo sinh vien trong danh sach\n");
        printf("4. Cap nhat thong tin cho sinh vien\n");
        printf("5. Tim sinh vien\n");
        printf("6. Thoat khoi chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so sinh vien muon khoi tao danh sach: ");
                int numInitialize;
                scanf("%d", &numInitialize);

                if (numInitialize < 0 || numInitialize > MAX_STUDENTS) {
                    printf("so sinh vien khong hop le vui long nhap giua 0 va %d.\n", MAX_STUDENTS);
                    break;
                }

                printf("Khoi tao danh sach sinh vien\n");

                numStudents = 0;
                memset(students, 0, sizeof(students));

                
                for (int i = 0; i < numInitialize; i++) {
                    struct Student newStudent;

                    printf("Nhap thong tin cho sinh vien %d:\n", i + 1);

                    printf("Nhap ma sinh vien: ");
                    fgets(newStudent.id, sizeof(newStudent.id), stdin);
                    newStudent.id[strcspn(newStudent.id, "\n")] = '\0'; 

                    printf("Nhap ten cho sinh vien: ");
                    fgets(newStudent.name, sizeof(newStudent.name), stdin);
                    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; 

                    printf("Nhap tuoi cho sinh vien: ");
                    scanf("%d", &newStudent.age);
                    getchar(); 

                    students[numStudents] = newStudent;
                    numStudents++;
                }

                printf("Khoi tao danh sach sinh vien thanh cong.\n");
                break;
            }
            case 2: {
                if (numStudents == MAX_STUDENTS) {
                    printf("Khong the them sinh vien .\n");
                    break;
                }

                struct Student newStudent;

                printf("Nhap thong tin cho sinh vien:\n");
                printf("ID: ");
                fgets(newStudent.id, sizeof(newStudent.id), stdin);
                newStudent.id[strcspn(newStudent.id, "\n")] = '\0'; 

                printf("Nhap ten cho sinh vien: ");
                fgets(newStudent.name, sizeof(newStudent.name), stdin);
                newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; 

                printf("Nhap tuoi cho sinh vien: ");
                scanf("%d", &newStudent.age);
                getchar(); 

                students[numStudents] = newStudent;
                numStudents++;

                printf("Them sinh vien thanh cong.\n");
                break;
            }
            case 3: {
                printf("danh sach sinh vien:\n");

                for (int i = 0; i < numStudents; i++) {
                    printf("Sinh vien %d:\n", i + 1);
                    displayStudent(students[i]);
                }

                break;
            }
            case 4: {
                printf("Nhap ma cua sinh vien muon chinh sua: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = '\0'; 

                int index = -1;

                for (int i = 0; i < numStudents; i++) {
                    if (strcmp(students[i].id, id) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong the tim thay sinh vien voi ma %s.\n", id);
                    break;
                }

                printf("Nhap ten chinh su cho sinh vien: ");
                fgets(students[index].name, sizeof(students[index].name), stdin);
                students[index].name[strcspn(students[index].name, "\n")] = '\0'; 
                printf("Chinh sua ten cho sinh vien thanh cong.\n");
                break;
            }
            case 5: {
                printf("Nhap ma cua sinh vien muon tim: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = '\0'; 

                int index = -1;

                for (int i = 0; i < numStudents; i++) {
                    if (strcmp(students[i].id, id) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong the tìm thay sinh vien voi ma %s.\n", id);
                } else {
                    printf("Da tim thay sinh vien:\n");
                    displayStudent(students[index]);
                }

                break;
            }
            case 6:
                printf("Thoat khoi chuong trinh \n");
                break;
            default:
                printf("Lua chon khong hop le vui long chon giua 1 va 6.\n");
        }
    } while (choice != 6);

    return 0;
}
