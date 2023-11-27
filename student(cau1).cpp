#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
};

void displayStudent(struct Student student) {
    printf("ID: %d\n", student.id);
    printf("Ten: %s\n", student.name);
    printf("Tuoi: %d\n", student.age);
    printf("\n");
}

void editStudent(struct Student *student) {
    printf("nhap ID moi: ");
    scanf("%d", &student->id);
    printf("nhap ten moi: ");
    scanf("%s", student->name);
    printf("nhap tuoi moi: ");
    scanf("%d", &student->age);
}

int main() {
    int numStudents;

    printf("nhap so sinh vien: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

   
    for (int i = 0; i < numStudents; i++) {
        printf("\n nhap thong tin cho sinh vien %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("ten: ");
        scanf("%s", students[i].name);
        printf("tuoi: ");
        scanf("%d", &students[i].age);
    }

    printf("\nStudent Information:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        displayStudent(students[i]);
    }

   
    int studentIndex;
    printf("nhap thong tin cua sinh vien muon chinh sua: ");
    scanf("%d", &studentIndex);
    if (studentIndex >= 0 || studentIndex <= numStudents) {
        printf("\n sua thong tin sinh vien %d:\n", studentIndex);
        editStudent(&students[studentIndex]);
        printf("\n thong tin cua sinh vien %d da duoc chinh sua:\n", studentIndex);
        displayStudent(students[studentIndex]);
    } else {
        printf("sinh vien khong ton tai.\n");
    }

    return 0;
    
}
