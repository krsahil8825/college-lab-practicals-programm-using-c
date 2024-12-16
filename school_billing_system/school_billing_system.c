#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // For clrscr() and getch()

// Structure for Student and Faculty Records
typedef struct {
    char name[50];
    char role[50]; // Class for students, Position for faculty
    int id;        // Roll number for students, Employee ID for faculty
    float amount;  // Fees for students, Salary for faculty
    float dues;    // Remaining dues or advance
} Record;

// Function Prototypes
void mainMenu();
void studentMenu();
void facultyMenu();
void addRecord(const char *filename);
void displayRecords(const char *filename, const char *type);
void displayFees();
void displayDues();
void displayAdvance();
void displayTotalFees();
void displayFacultySalary();

void main() {
    // Ensure the data directory exists
    #ifdef _WIN32
        system("if not exist data mkdir data");
    #else
        system("mkdir -p data");
    #endif

    while (1) {
        mainMenu();
    }
}

void mainMenu() {
    int choice;
    printf("\n===== School Billing System =====\n");
    printf("1. Manage Student Accounts\n");
    printf("2. Manage Faculty Accounts\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            studentMenu();
            break;
        case 2:
            facultyMenu();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Press any key to try again.");
            getch();
    }
}

void studentMenu() {
    char filename[] = "data/students.dat";
    int choice;
    printf("\n===== Student Account Management =====\n");
    printf("1. Add Student Record\n");
    printf("2. Display All Records\n");
    printf("3. Display Fees\n");
    printf("4. Display Dues\n");
    printf("5. Display Advance\n");
    printf("6. Display Total Fees\n");
    printf("7. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addRecord(filename);
            break;
        case 2:
            displayRecords(filename, "Student");
            break;
        case 3:
            displayFees();
            break;
        case 4:
            displayDues();
            break;
        case 5:
            displayAdvance();
            break;
        case 6:
            displayTotalFees();
            break;
        case 7:
            return;
        default:
            printf("Invalid choice! Press any key to try again.");
            getch();
    }
}

void facultyMenu() {
    char filename[] = "data/faculty.dat";
    int choice;
    printf("\n===== Faculty Account Management =====\n");
    printf("1. Add Faculty Record\n");
    printf("2. Display All Records\n");
    printf("3. Display Salary Details\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addRecord(filename);
            break;
        case 2:
            displayRecords(filename, "Faculty");
            break;
        case 3:
            displayFacultySalary();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice! Press any key to try again.");
            getch();
    }
}

void addRecord(const char *filename) {
    Record rec;
    FILE *file = fopen(filename, "ab");

    if (!file) {
        printf("Error opening file! Press any key to return.");
        getch();
        return;
    }

    printf("Enter Name: ");
    getchar();
    fgets(rec.name, sizeof(rec.name), stdin);
    strtok(rec.name, "\n");

    printf("Enter Role (Class/Position): ");
    fgets(rec.role, sizeof(rec.role), stdin);
    strtok(rec.role, "\n");

    printf("Enter ID (Roll No/Employee ID): ");
    scanf("%d", &rec.id);

    printf("Enter Amount (Fees/Salary): ");
    scanf("%f", &rec.amount);

    printf("Enter Dues (Advance/Dues): ");
    scanf("%f", &rec.dues);

    fwrite(&rec, sizeof(rec), 1, file);
    fclose(file);

    printf("Record added successfully! Press any key to return.");
    getch();
}

void displayRecords(const char *filename, const char *type) {
    Record rec;
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("Error opening file! Press any key to return.");
        getch();
        return;
    }

    printf("\n===== %s Records =====\n", type);
    while (fread(&rec, sizeof(rec), 1, file)) {
        printf("Name: %s, Role: %s, ID: %d, Amount: %.2f, Dues: %.2f\n",
               rec.name, rec.role, rec.id, rec.amount, rec.dues);
    }
    fclose(file);

    printf("\nPress any key to return.");
    getch();
}

void displayFees() {
    Record rec;
    FILE *file = fopen("data/students.dat", "rb");

    if (!file) {
        printf("Error opening file! Press any key to return.");
        getch();
        return;
    }

    printf("\n===== Student Fees =====\n");
    while (fread(&rec, sizeof(rec), 1, file)) {
        printf("Name: %s, Fees: %.2f\n", rec.name, rec.amount);
    }
    fclose(file);

    printf("\nPress any key to return.");
    getch();
}

// Similar functions for Dues, Advance, Total Fees, and Faculty Salary...
void displayDues() {
    Record rec;
    FILE *file = fopen("data/students.dat", "rb");

    if (!file) {
        printf("Error opening file! Press any key to return.");
        getch();
        return;
    }

    printf("\n===== Student Dues =====\n");
    while (fread(&rec, sizeof(rec), 1, file)) {
        if (rec.dues > 0) {
            printf("Name: %s, Dues: %.2f\n", rec.name, rec.dues);
        }
    }
    fclose(file);

    printf("\nPress any key to return.");
    getch();
}

void displayAdvance() {
    Record rec;
    FILE *file = fopen("data/students.dat", "rb");

    if (!file) {
        printf("Error opening file! Press any key to return.");
        getch();
        return;
    }

    printf("\n===== Student Advances =====\n");
    while (fread(&rec, sizeof(rec), 1, file)) {
        if (rec.dues < 0) {
            printf("Name: %s, Advance: %.2f\n", rec.name, -rec.dues);
        }
    }
    fclose(file);

    printf("\nPress any key to return.");
    getch();
}

void displayTotalFees() {
    Record rec;
    FILE *file = fopen("data/students.dat", "rb");
    float totalFees = 0;

    if (!file) {
        printf("Error opening file! Press any key to return.");
        getch();
        return;
    }

    while (fread(&rec, sizeof(rec), 1, file)) {
        totalFees += rec.amount;
    }
    fclose(file);

    printf("\n===== Total Fees Collected =====\n");
    printf("Total Fees: %.2f\n", totalFees);

    printf("\nPress any key to return.");
    getch();
}

void displayFacultySalary() {
    Record rec;
    FILE *file = fopen("data/faculty.dat", "rb");

    if (!file) {
        printf("Error opening file! Press any key to return.");
        getch();
        return;
    }

    printf("\n===== Faculty Salaries =====\n");
    while (fread(&rec, sizeof(rec), 1, file)) {
        printf("Name: %s, Salary: %.2f\n", rec.name, rec.amount);
    }
    fclose(file);

    printf("\nPress any key to return.");
    getch();
}

