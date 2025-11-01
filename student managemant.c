#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define student structure
struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

struct Student students[MAX_STUDENTS];
int count = 0; // total number of students

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    do {
        printf("\n====== Student Management System ======\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to add a student
void addStudent() {
    if(count == MAX_STUDENTS) {
        printf("Cannot add more students. Storage full!\n");
        return;
    }

    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name); // read string with spaces
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[count] = s;
    count++;

    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if(count == 0) {
        printf("No student records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for(int i = 0; i < count; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
        printf("-----------------------\n");
    }
}

// Function to search student by ID
void searchStudent() {
    int id, found = 0;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            printf("Student found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No student found with ID %d.\n", id);
}

// Function to update student record
void updateStudent() {
    int id, found = 0;
    printf("Enter student ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No student found with ID %d.\n", id);
}

// Function to delete student record
void deleteStudent() {
    int id, found = 0;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            for(int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Record deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("No student found with ID %d.\n", id);
}