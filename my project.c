#include <stdio.h>
#include <string.h>

// Structure to hold student information
struct Student {
    char hall_ticket_number[20]; // Hall ticket number
    char name[100];
    char stream[50];  // e.g., "CSE", "ECE", "EEE", "MECH"
    int eamcet_rank;  // EAMCET rank
};

// Function to add a student
void addStudent(struct Student students[], int *count) {
    printf("Enter hall ticket number: ");
    getchar();  // to clear the newline character from input buffer
    fgets(students[*count].hall_ticket_number, sizeof(students[*count].hall_ticket_number), stdin);
    students[*count].hall_ticket_number[strcspn(students[*count].hall_ticket_number, "\n")] = '\0';  // Remove newline character
    printf("Enter student name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';  // Remove newline character
    printf("Enter stream (CSE/ECE/EEE/MECH): ");
    fgets(students[*count].stream, sizeof(students[*count].stream), stdin);
    students[*count].stream[strcspn(students[*count].stream, "\n")] = '\0';  // Remove newline character
    printf("Enter EAMCET rank: ");
    scanf("%d", &students[*count].eamcet_rank);
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to remove a student by hall ticket number
void removeStudent(struct Student students[], int *count, char hall_ticket_number[]) {
    int i, found = 0;
    for (i = 0; i < *count; i++) {
        if (strcmp(students[i].hall_ticket_number, hall_ticket_number) == 0) {
            found = 1;
            // Shift elements to the left
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;  // Decrease student count
            printf("Student with Hall Ticket Number %s removed successfully!\n", hall_ticket_number);
            break;
        }
    }
    if (!found) {
        printf("Student with Hall Ticket Number %s not found!\n", hall_ticket_number);
    }
}

// Function to display all students in a tabular format
void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n%-20s %-20s %-15s %-10s\n", "Hall Ticket Number", "Name", "Stream", "EAMCET Rank");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s %-15s %-10d\n", 
               students[i].hall_ticket_number, 
               students[i].name, 
               students[i].stream, 
               students[i].eamcet_rank);
    }
}

// Main function
int main() {
    struct Student students[100];  // Array to store students
    int count = 0;  // Counter to track number of students
    int choice;
    char hall_ticket_number[20];

    while (1) {
        printf("\nStudent Admission System\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                printf("Enter hall ticket number to remove: ");
                getchar();  // to clear the newline character from input buffer
                fgets(hall_ticket_number, sizeof(hall_ticket_number), stdin);
                hall_ticket_number[strcspn(hall_ticket_number, "\n")] = '\0';  // Remove newline character
                removeStudent(students, &count, hall_ticket_number);
                break;
            case 3:
                displayStudents(students, count);
                break;
            case 4:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}