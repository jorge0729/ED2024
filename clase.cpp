#include <stdio.h>
#include <stdlib.h>

// Student Node structure
typedef struct StudentNode {
    char firstName[50];
    int studentCode;
    float grade;
    struct StudentNode* next;
} StudentNode;

// Linked List structure
typedef struct LinkedList {
    StudentNode* head;
} LinkedList;

// Function to create a new student node
StudentNode* createStudentNode(char* firstName, int studentCode, float grade) {
    StudentNode* node = (StudentNode*) malloc(sizeof(StudentNode));
    //strcpy(node->firstName, firstName);
    node->studentCode = studentCode;
    node->grade = grade;
    node->next = NULL;
    return node;
}

// Function to insert a student node into the linked list
void insertStudentNode(LinkedList* list, StudentNode* node) {
    if (list->head == NULL) {
        list->head = node;
    } else {
        StudentNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Function to implement bubble sort
void bubbleSort(LinkedList* list, int sortBy) {
    int swapped;
    StudentNode* current;
    StudentNode* next;

    if (sortBy == 0) { // Sort by student code
        do {
            swapped = 0;
            current = list->head;
            while (current->next != NULL) {
                next = current->next;
                if (current->studentCode > next->studentCode) {
                    // Swap nodes
                    StudentNode* temp = current->next;
                    current->next = next->next;
                    next->next = current;
                    current = temp;
                    swapped = 1;
                }
            }
        } while (swapped);
    } else { // Sort by grade
        do {
            swapped = 0;
            current = list->head;
            while (current->next != NULL) {
                next = current->next;
                if (current->grade < next->grade) {
                    // Swap nodes
                    StudentNode* temp = current->next;
                    current->next = next->next;
                    next->next = current;
                    current = temp;
                    swapped = 1;
                }
            }
        } while (swapped);
    }
}

// Function to find the highest grade
StudentNode* findHighestGrade(LinkedList* list) {
    StudentNode* current = list->head;
    StudentNode* highest = current;
    while (current != NULL) {
        if (current->grade > highest->grade) {
            highest = current;
        }
        current = current->next;
    }
    return highest;
}

// Function to find the lowest grade
StudentNode* findLowestGrade(LinkedList* list) {
    StudentNode* current = list->head;
    StudentNode* lowest = current;
    while (current != NULL) {
        if (current->grade < lowest->grade) {
            lowest = current;
        }
        current = current->next;
    }
    return lowest;
}

// Function to calculate the average grade
float calculateAverageGrade(LinkedList* list) {
    float sum = 0;
    int count = 0;
    StudentNode* current = list->head;
    while (current != NULL) {
        sum += current->grade;
        count++;
        current = current->next;
    }
    return sum / count;
}

// Main function
int main() {
    LinkedList list;
    list.

    int option;
    do {
        printf("Menu:\n");
        printf("1. Ingresar datos de estudiantes\n");
        printf("2. Ordenar y mostrar la lista de estudiantes\n");
        printf("3. Mostrar la mayor nota, menor nota y promedio del curso\n");
        printf("4. Salir del");
    }


    return 0;
    
    }