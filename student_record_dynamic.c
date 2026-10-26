/*
 * Project: AI-Assisted Student Record and Result Management System (Dynamic Memory Version)
 * Course: Programming in C (PRC1001) - UPES
 * Features:
 *   - Uses <stdlib.h> for dynamic memory allocation (calloc, malloc, free)
 *   - calloc(): Used to allocate and zero-initialize the dynamic student database
 *   - malloc(): Used to allocate temporary memory during sorting and student creation
 *   - free(): Used to release allocated heap memory and avoid memory leaks
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEMESTERS 8

// Structure to hold all details of a student
struct Student {
    long long sap_id;
    char roll_no[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;                    // 1, 2, 3, or 4
    int semester;                // 1 to 8
    float sgpa[TOTAL_SEMESTERS]; // SGPAs for 8 semesters
    float cgpa;                  // Calculated CGPA
};

// Pointer to dynamically allocated student array on the heap
struct Student *students = NULL;
int totalStudents = 0;
int currentCapacity = 0;

// Function to calculate CGPA for a student (average of valid SGPAs)
void calculateStudentCGPA(int index) {
    float sum = 0.0;
    int count = 0;
    int i;

    for (i = 0; i < students[index].semester; i++) {
        if (students[index].sgpa[i] > 0.0) {
            sum += students[index].sgpa[i];
            count++;
        }
    }

    if (count > 0) {
        students[index].cgpa = sum / count;
    } else {
        students[index].cgpa = 0.0;
    }
}

// Function to print details of a single student
void printStudentDetails(int i) {
    int j;
    printf("\n------------------------------------------------------------\n");
    printf("SAP ID       : %lld\n", students[i].sap_id);
    printf("Roll Number  : %s\n", students[i].roll_no);
    printf("Name         : %s\n", students[i].name);
    printf("Phone Number : %s\n", students[i].phone);
    printf("Email ID     : %s\n", students[i].email);
    printf("Year         : %d\n", students[i].year);
    printf("Semester     : %d\n", students[i].semester);
    printf("SGPA in all 8 Semesters:\n");
    for (j = 0; j < TOTAL_SEMESTERS; j++) {
        if (j < students[i].semester) {
            printf("  Sem %d: %.2f", j + 1, students[i].sgpa[j]);
        } else {
            printf("  Sem %d: -", j + 1);
        }
        if (j == 3 || j == 7) printf("\n");
    }
    printf("Calculated CGPA: %.2f\n", students[i].cgpa);
    printf("------------------------------------------------------------\n");
}

// Function to initialize dynamic memory using calloc()
// calloc initializes all allocated bytes to zero
void initDatabase(int initialCapacity) {
    currentCapacity = initialCapacity;
    students = (struct Student *) calloc(currentCapacity, sizeof(struct Student));

    if (students == NULL) {
        printf("Fatal Error: Memory allocation using calloc() failed!\n");
        exit(1);
    }
}

// Function to expand database capacity if needed using malloc() & free()
void expandCapacityIfNeeded() {
    if (totalStudents >= currentCapacity) {
        int newCapacity = currentCapacity * 2;
        // Allocate larger block using malloc()
        struct Student *newBlock = (struct Student *) malloc(newCapacity * sizeof(struct Student));

        if (newBlock == NULL) {
            printf("Fatal Error: Memory allocation using malloc() failed!\n");
            return;
        }

        // Copy existing data to the new memory block
        for (int i = 0; i < totalStudents; i++) {
            newBlock[i] = students[i];
        }

        // Free the old memory block
        free(students);

        students = newBlock;
        currentCapacity = newCapacity;
        printf("\n[System]: Database capacity dynamically increased to %d records.\n", currentCapacity);
    }
}

// Function to load 5 initial student records
void loadInitialStudents() {
    int i;

    // Student 1 (Year 1, Sem 1)
    students[0].sap_id = 500120101LL;
    strcpy(students[0].roll_no, "R214223001");
    strcpy(students[0].name, "Aarav Sharma");
    strcpy(students[0].phone, "9876543210");
    strcpy(students[0].email, "aarav@upes.ac.in");
    students[0].year = 1;
    students[0].semester = 1;
    students[0].sgpa[0] = 9.4;
    for (i = 1; i < 8; i++) students[0].sgpa[i] = 0.0;
    calculateStudentCGPA(0);

    // Student 2 (Year 2, Sem 3)
    students[1].sap_id = 500115202LL;
    strcpy(students[1].roll_no, "R214222045");
    strcpy(students[1].name, "Diya Patel");
    strcpy(students[1].phone, "9823456781");
    strcpy(students[1].email, "diya@upes.ac.in");
    students[1].year = 2;
    students[1].semester = 3;
    students[1].sgpa[0] = 8.1;
    students[1].sgpa[1] = 8.4;
    students[1].sgpa[2] = 8.2;
    for (i = 3; i < 8; i++) students[1].sgpa[i] = 0.0;
    calculateStudentCGPA(1);

    // Student 3 (Year 3, Sem 5)
    students[2].sap_id = 500108303LL;
    strcpy(students[2].roll_no, "R214221102");
    strcpy(students[2].name, "Rohan Verma");
    strcpy(students[2].phone, "9711223344");
    strcpy(students[2].email, "rohan@upes.ac.in");
    students[2].year = 3;
    students[2].semester = 5;
    students[2].sgpa[0] = 6.8;
    students[2].sgpa[1] = 6.2;
    students[2].sgpa[2] = 6.5;
    students[2].sgpa[3] = 6.1;
    students[2].sgpa[4] = 6.4;
    for (i = 5; i < 8; i++) students[2].sgpa[i] = 0.0;
    calculateStudentCGPA(2);

    // Student 4 (Year 4, Sem 7)
    students[3].sap_id = 500095404LL;
    strcpy(students[3].roll_no, "R214220055");
    strcpy(students[3].name, "Vikram Singh");
    strcpy(students[3].phone, "9654123890");
    strcpy(students[3].email, "vikram@upes.ac.in");
    students[3].year = 4;
    students[3].semester = 7;
    students[3].sgpa[0] = 5.2;
    students[3].sgpa[1] = 4.8;
    students[3].sgpa[2] = 4.9;
    students[3].sgpa[3] = 5.1;
    students[3].sgpa[4] = 4.6;
    students[3].sgpa[5] = 4.7;
    students[3].sgpa[6] = 5.0;
    students[3].sgpa[7] = 0.0;
    calculateStudentCGPA(3);

    // Student 5 (Year 2, Sem 4)
    students[4].sap_id = 500119505LL;
    strcpy(students[4].roll_no, "R214222120");
    strcpy(students[4].name, "Ananya Gupta");
    strcpy(students[4].phone, "9988776655");
    strcpy(students[4].email, "ananya@upes.ac.in");
    students[4].year = 2;
    students[4].semester = 4;
    students[4].sgpa[0] = 8.8;
    students[4].sgpa[1] = 9.0;
    students[4].sgpa[2] = 8.7;
    students[4].sgpa[3] = 9.1;
    for (i = 4; i < 8; i++) students[4].sgpa[i] = 0.0;
    calculateStudentCGPA(4);

    totalStudents = 5;
}

// (a) Function to add student details
void addStudent() {
    int i;
    expandCapacityIfNeeded();

    // Allocate a temporary student structure on heap using malloc
    struct Student *tempStudent = (struct Student *) malloc(sizeof(struct Student));
    if (tempStudent == NULL) {
        printf("Memory allocation failed for new student!\n");
        return;
    }

    printf("\n--- ADD NEW STUDENT (DYNAMIC) ---\n");
    printf("Enter SAP ID (9 digits): ");
    scanf("%lld", &tempStudent->sap_id);

    printf("Enter Roll Number: ");
    scanf("%s", tempStudent->roll_no);

    printf("Enter Name (Use underscore or single line): ");
    scanf(" %[^\n]", tempStudent->name);

    printf("Enter Phone Number: ");
    scanf("%s", tempStudent->phone);

    printf("Enter Email ID: ");
    scanf("%s", tempStudent->email);

    printf("Enter Year (1, 2, 3, or 4): ");
    scanf("%d", &tempStudent->year);

    printf("Enter Semester (1 to 8): ");
    scanf("%d", &tempStudent->semester);

    printf("Enter SGPA for completed semesters (1 to %d):\n", tempStudent->semester);
    for (i = 0; i < TOTAL_SEMESTERS; i++) {
        if (i < tempStudent->semester) {
            printf("SGPA for Semester %d: ", i + 1);
            scanf("%f", &tempStudent->sgpa[i]);
        } else {
            tempStudent->sgpa[i] = 0.0;
        }
    }

    tempStudent->cgpa = 0.0;

    // Copy from temporary heap object to dynamic array
    students[totalStudents] = *tempStudent;
    calculateStudentCGPA(totalStudents);
    totalStudents++;

    // Free temporary memory allocated with malloc()
    free(tempStudent);

    printf("\nStudent record added successfully! (Total: %d, Capacity: %d)\n", totalStudents, currentCapacity);
}

// (b) Function to search and display student record
void searchStudent() {
    int choice;
    int found = 0;
    int i;

    printf("\n--- SEARCH STUDENT ---\n");
    printf("1. Search by SAP ID\n");
    printf("2. Search by Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        long long id;
        printf("Enter SAP ID: ");
        scanf("%lld", &id);

        for (i = 0; i < totalStudents; i++) {
            if (students[i].sap_id == id) {
                printStudentDetails(i);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        char searchName[50];
        printf("Enter Name to search: ");
        scanf(" %[^\n]", searchName);

        for (i = 0; i < totalStudents; i++) {
            if (strstr(students[i].name, searchName) != NULL) {
                printStudentDetails(i);
                found = 1;
            }
        }
    } else {
        printf("Invalid choice!\n");
        return;
    }

    if (!found) {
        printf("Student record not found!\n");
    }
}

// (c) Function to calculate and show CGPA of each student
void displayAllCGPA() {
    int i;
    printf("\n--- CGPA OF ALL STUDENTS ---\n");
    printf("%-12s %-20s %-6s %-6s\n", "SAP ID", "Name", "Sem", "CGPA");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < totalStudents; i++) {
        calculateStudentCGPA(i);
        printf("%-12lld %-20s %-6d %-6.2f\n", 
               students[i].sap_id, students[i].name, students[i].semester, students[i].cgpa);
    }
}

// (d) Function to calculate average CGPA of each year
void averageCGPAYearWise() {
    int yr, i;
    float sum[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    int count[5] = {0, 0, 0, 0, 0};

    for (i = 0; i < totalStudents; i++) {
        calculateStudentCGPA(i);
        yr = students[i].year;
        if (yr >= 1 && yr <= 4) {
            sum[yr] += students[i].cgpa;
            count[yr] += 1;
        }
    }

    printf("\n--- AVERAGE CGPA OF EACH YEAR ---\n");
    for (yr = 1; yr <= 4; yr++) {
        if (count[yr] > 0) {
            printf("Year %d: Average CGPA = %.2f (Total Students: %d)\n", yr, sum[yr] / count[yr], count[yr]);
        } else {
            printf("Year %d: No students registered\n", yr);
        }
    }
}

// (e) Function to display all students of the University
void displayAllStudents() {
    int i;
    printf("\n--- ALL UNIVERSITY STUDENTS (Total: %d, Capacity: %d) ---\n", totalStudents, currentCapacity);
    if (totalStudents == 0) {
        printf("No records found.\n");
        return;
    }
    for (i = 0; i < totalStudents; i++) {
        printStudentDetails(i);
    }
}

// (f) Function to delete student record
void deleteStudent() {
    long long id;
    int index = -1;
    int i;

    printf("\n--- DELETE STUDENT RECORD ---\n");
    printf("Enter SAP ID of student to delete: ");
    scanf("%lld", &id);

    for (i = 0; i < totalStudents; i++) {
        if (students[i].sap_id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student with SAP ID %lld not found!\n", id);
        return;
    }

    // Shift elements left
    for (i = index; i < totalStudents - 1; i++) {
        students[i] = students[i + 1];
    }
    totalStudents--;

    printf("Student record deleted successfully!\n");
}

// (g) Function to display records in increasing order of SAP ID (uses malloc & free)
void sortBySAPID() {
    if (totalStudents == 0) {
        printf("No student records available.\n");
        return;
    }

    // Dynamically allocate memory for temporary array using malloc()
    struct Student *temp = (struct Student *) malloc(totalStudents * sizeof(struct Student));
    if (temp == NULL) {
        printf("Memory allocation failed during sort!\n");
        return;
    }

    int i, j;
    for (i = 0; i < totalStudents; i++) {
        temp[i] = students[i];
    }

    // Bubble Sort
    for (i = 0; i < totalStudents - 1; i++) {
        for (j = 0; j < totalStudents - i - 1; j++) {
            if (temp[j].sap_id > temp[j + 1].sap_id) {
                struct Student swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    printf("\n--- STUDENTS IN INCREASING ORDER OF SAP ID ---\n");
    printf("%-12s %-20s %-6s %-6s\n", "SAP ID", "Name", "Year", "CGPA");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < totalStudents; i++) {
        printf("%-12lld %-20s %-6d %-6.2f\n", temp[i].sap_id, temp[i].name, temp[i].year, temp[i].cgpa);
    }

    // Free the dynamically allocated temporary array
    free(temp);
}

// (h) Function to display records in increasing order of Name (uses malloc & free)
void sortByName() {
    if (totalStudents == 0) {
        printf("No student records available.\n");
        return;
    }

    // Dynamically allocate memory for temporary array using malloc()
    struct Student *temp = (struct Student *) malloc(totalStudents * sizeof(struct Student));
    if (temp == NULL) {
        printf("Memory allocation failed during sort!\n");
        return;
    }

    int i, j;
    for (i = 0; i < totalStudents; i++) {
        temp[i] = students[i];
    }

    // Bubble Sort with strcmp
    for (i = 0; i < totalStudents - 1; i++) {
        for (j = 0; j < totalStudents - i - 1; j++) {
            if (strcmp(temp[j].name, temp[j + 1].name) > 0) {
                struct Student swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    printf("\n--- STUDENTS IN INCREASING ORDER OF NAME ---\n");
    printf("%-20s %-12s %-6s %-6s\n", "Name", "SAP ID", "Year", "CGPA");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < totalStudents; i++) {
        printf("%-20s %-12lld %-6d %-6.2f\n", temp[i].name, temp[i].sap_id, temp[i].year, temp[i].cgpa);
    }

    // Free the dynamically allocated temporary array
    free(temp);
}

// Part B: Simple AI-Assisted Academic Advisor
void academicAdvisor() {
    long long id;
    int i, found = -1;

    printf("\n--- AI-ASSISTED ACADEMIC ADVISOR ---\n");
    printf("Enter SAP ID of student: ");
    scanf("%lld", &id);

    for (i = 0; i < totalStudents; i++) {
        if (students[i].sap_id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Student not found!\n");
        return;
    }

    calculateStudentCGPA(found);
    printf("\nStudent: %s | SAP ID: %lld | CGPA: %.2f\n", 
           students[found].name, students[found].sap_id, students[found].cgpa);

    if (students[found].cgpa >= 9.0) {
        printf("Category: Excellent Performance\n");
        printf("Advice  : Outstanding result! Maintain your current study pattern and explore research or internships.\n");
    } else if (students[found].cgpa >= 7.5) {
        printf("Category: Good Performance\n");
        printf("Advice  : Good work! Stay consistent and focus on higher grades in core subjects to achieve 9+ CGPA.\n");
    } else if (students[found].cgpa >= 5.5) {
        printf("Category: Needs Improvement\n");
        printf("Advice  : Needs improvement - focus more on subjects with lower SGPA and attend doubt sessions.\n");
    } else {
        printf("Category: Requires Immediate Attention\n");
        printf("Advice  : Requires immediate attention - consult your faculty mentor and join remedial classes.\n");
    }
}

// Function to clean up all dynamically allocated memory before program exit
void freeAllMemory() {
    if (students != NULL) {
        free(students);
        students = NULL;
    }
}

// Main function
int main() {
    int choice;

    // Allocate initial memory for 10 students using calloc()
    initDatabase(10);

    // Preload initial 5 students
    loadInitialStudents();

    do {
        printf("\n============================================================\n");
        printf("  STUDENT RECORD & RESULT MANAGEMENT (DYNAMIC MEMORY)\n");
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

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                displayAllCGPA();
                break;
            case 4:
                averageCGPAYearWise();
                break;
            case 5:
                displayAllStudents();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                sortBySAPID();
                break;
            case 8:
                sortByName();
                break;
            case 9:
                academicAdvisor();
                break;
            case 10:
                printf("\nFreeing allocated dynamic memory and exiting...\n");
                freeAllMemory();
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter between 1 and 10.\n");
        }
    } while (choice != 10);

    return 0;
}
