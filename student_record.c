#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to hold all details of a student
struct Student {
    long long sap_id;
    char roll_no[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;          // 1, 2, 3, or 4
    int semester;      // 1 to 8
    float sgpa[8];     // SGPA for 8 semesters
    float cgpa;        // Calculated CGPA
};

// Global array of students and count of current students
struct Student students[MAX];
int totalStudents = 0;

// Main function - Basic menu skeleton
int main() {
    int choice;

    do {
        printf("\n============================================================\n");
        printf("    STUDENT RECORD & RESULT MANAGEMENT SYSTEM\n");
        printf("============================================================\n");
        printf("1. Add Student Record\n");
        printf("2. Search Student Record\n");
        printf("3. Calculate CGPA of Each Student\n");
        printf("4. Calculate Average CGPA of Each Year\n");
        printf("5. Display All Students\n");
        printf("6. Delete Student Record\n");
        printf("7. Display Students Sorted by SAP ID\n");
        printf("8. Display Students Sorted by Name\n");
        printf("9. AI-Assisted Academic Advisor\n");
        printf("10. Exit\n");
        printf("============================================================\n");
        printf("Enter your choice (1-10): ");
        scanf("%d", &choice);

        if (choice == 10) {
            printf("\nExiting program. Thank you!\n");
        } else {
            printf("\nFeature under development.\n");
        }
    } while (choice != 10);

    return 0;
}
