#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int roll_number;
    float marks[2]; 
};

struct Student students[MAX_STUDENTS];
int student_count = 0;

void addStudent() {
    if (student_count < MAX_STUDENTS) {
        printf("Enter name: ");
        scanf(" %[^\n]", students[student_count].name);
        printf("Enter roll number: ");
        scanf("%d", &students[student_count].roll_number);
        printf("Enter marks for 3 subjects:\n");
        for (int i = 0; i < 3; i++) {
            printf("Subject %d: ", i + 1);
            scanf("%f", &students[student_count].marks[i]);
        }
        student_count++;
        printf("Student added successfully!\n");
    } else {
        printf("Cannot add more students. Maximum limit reached.\n");
    }
}

void displayStudents() {
    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }
    printf("\nList of Students:\n");
    for (int i = 0; i < student_count; i++) {
        printf("Roll Number: %d, Name: %s, Marks: %.2f, %.2f, %.2f\n",
               students[i].roll_number, students[i].name,
               students[i].marks[0], students[i].marks[1], students[i].marks[2]);
    }
}

void searchStudent() {
    int roll_number;
    printf("Enter roll number to search: ");
    scanf("%d", &roll_number);
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_number) {
            printf("Student Found: Roll Number: %d, Name: %s, Marks: %.2f, %.2f, %.2f\n",
                   students[i].roll_number, students[i].name,
                   students[i].marks[0], students[i].marks[1], students[i].marks[2]);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll_number);
}

void updateStudent() {
    int roll_number;
    printf("Enter roll number to update: ");
    scanf("%d", &roll_number);
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_number) {
            printf("Updating details for Roll Number: %d\n", roll_number);
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new marks for 3 subjects:\n");
            for (int j = 0; j < 3; j++) {
                printf("Subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);
            }
            printf("Details updated successfully!\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll_number);
}

void deleteStudent() {
    int roll_number;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll_number);
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_number) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student with roll number %d deleted successfully!\n", roll_number);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll_number);
}

int main() {
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search for a Student\n");
        printf("4. Update Student Details\n");
        printf("5. Delete a Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting program.");
                break;
            default:
                printf(" Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
