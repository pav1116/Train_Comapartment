/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Define the Compartment structure
typedef struct Compartment {
    int number;
    struct Compartment* next;
} Compartment;

// Define the Train structure
typedef struct {
    Compartment* head;
} Train;

// Function to create a new compartment
Compartment* create_compartment(int number) {
    Compartment* new_compartment = (Compartment*)malloc(sizeof(Compartment));
    new_compartment->number = number;
    new_compartment->next = NULL;
    return new_compartment;
}

// Function to initialize the train
void initialize_train(Train* train) {
    train->head = NULL;
}

// Function to add a compartment at the beginning
void add_compartment_at_beginning(Train* train, int number) {
    Compartment* new_compartment = create_compartment(number);
    new_compartment->next = train->head;
    train->head = new_compartment;
}

// Function to add a compartment at the end
void add_compartment_at_end(Train* train, int number) {
    Compartment* new_compartment = create_compartment(number);
    if (train->head == NULL) {
        train->head = new_compartment;
    } else {
        Compartment* last = train->head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_compartment;
    }
}

// Function to count the number of compartments
int count_compartments(Train* train) {
    int count = 0;
    Compartment* current = train->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to remove a compartment from the end
void remove_compartment_from_end(Train* train) {
    if (train->head == NULL) {
        return;
    }
    if (train->head->next == NULL) {
        free(train->head);
        train->head = NULL;
        return;
    }
    Compartment* second_last = train->head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}

// Function to remove a compartment from the beginning
void remove_compartment_from_beginning(Train* train) {
    if (train->head == NULL) {
        return;
    }
    Compartment* temp = train->head;
    train->head = train->head->next;
    free(temp);
}

// Function to display all compartments
void display_compartments(Train* train) {
    Compartment* current = train->head;
    while (current != NULL) {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the functionality
int main() {
    Train train;
    initialize_train(&train);

    add_compartment_at_end(&train, 1);
    add_compartment_at_end(&train, 2);
    add_compartment_at_end(&train, 3);
    add_compartment_at_beginning(&train, 0);
    
    printf("Compartments: ");
    display_compartments(&train);

    printf("Count: %d\n", count_compartments(&train));

    remove_compartment_from_end(&train);
    printf("Compartments after removing from end: ");
    display_compartments(&train);

    remove_compartment_from_beginning(&train);
    printf("Compartments after removing from beginning: ");
    display_compartments(&train);

    printf("Final Count: %d\n", count_compartments(&train));

    return 0;
}
