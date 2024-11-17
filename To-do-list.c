#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 50

// Structure to represent a task
typedef struct {
    char description[MAX_TASK_LENGTH];
    bool completed;
} Task;

// Function prototypes
void displayMenu();
void addTask(Task tasks[], int *count);
void editTask(Task tasks[], int count);
void markTaskComplete(Task tasks[], int count);
void displayTasks(Task tasks[], int count);

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                editTask(tasks, taskCount);
                break;
            case 3:
                markTaskComplete(tasks, taskCount);
                break;
            case 4:
                displayTasks(tasks, taskCount);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display the menu options
void displayMenu() {
    printf("\n===== To-Do List Menu =====\n");
    printf("1. Add Task\n");
    printf("2. Edit Task\n");
    printf("3. Mark Task as Complete\n");
    printf("4. Display Tasks\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a task
void addTask(Task tasks[], int *count) {
    if (*count >= MAX_TASKS) {
        printf("Cannot add more tasks. Maximum limit reached.\n");
        return;
    }

    printf("Enter task description: ");
    scanf(" %[^\n]", tasks[*count].description);
    tasks[*count].completed = false;
    (*count)++;
}

// Function to edit a task
void editTask(Task tasks[], int count) {
    int taskIndex;
    printf("Enter the index of the task to edit (1-%d): ", count);
    scanf("%d", &taskIndex);

    if (taskIndex < 1 || taskIndex > count) {
        printf("Invalid task index.\n");
        return;
    }

    printf("Enter new description for the task: ");
    scanf(" %[^\n]", tasks[taskIndex - 1].description);
}

// Function to mark a task as complete
void markTaskComplete(Task tasks[], int count) {
    int taskIndex;
    printf("Enter the index of the task to mark as complete (1-%d): ", count);
    scanf("%d", &taskIndex);

    if (taskIndex < 1 || taskIndex > count) {
        printf("Invalid task index.\n");
        return;
    }

    tasks[taskIndex - 1].completed = true;
    printf("Task marked as complete.\n");
}

// Function to display all tasks
void displayTasks(Task tasks[], int count) {
    if (count == 0) {
        printf("No tasks.\n");
        return;
    }

    printf("\n===== To-Do List =====\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, tasks[i].description, tasks[i].completed ? "Completed" : "Incomplete");
    }
}
