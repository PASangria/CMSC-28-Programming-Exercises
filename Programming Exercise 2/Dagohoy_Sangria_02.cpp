// A program created by Dave Laurence Dagohoy and Prescious Apple Sangria 
// BSCS -1 
// Programming Exercise 03

//Program Description:
//  This program implements a stack data structure and has the following functionalities: push, pop, check if a the stack is empty or full, 
// checks the top element of the stack, and empties the stack. Moreover, this program limits the number of items to be added in the stack to 15. 

//Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Maximum capacity of the stack
#define MAX_CAPACITY 15

// Structure for the linked list node
struct node {
    char* data;
    struct node *next;
};

//Function Prototypes
void displayMenu();
char menu();
void task(char choice, struct node **head);
void push(struct node **S);
void pop(struct node **S);
int isFull(struct node **S);
char* top(struct node** S);
int isEmpty(struct node** S);
void makeNull(struct node** S);


// Main Function
int main() {
	struct node* head = NULL; 
    char choice;
    do {
        choice = menu();
        task(choice, &head); 
    } while (choice != '0');

    printf("Program exited.\n");
    return 0;
}

// Function: Display Menu
// Description: Displays the menu options to the user.
void displayMenu() {
    printf("\n");
    printf("==========================================================================\n");
    printf("||                      Kitchenware Washing Machine                     ||\n");
    printf("--------------------------------------------------------------------------\n");
    printf("||            Embark on an epic journey to conquer kitchen              ||\n");
    printf("||         cleanup with our Kitchenware Washing Machine - the           ||\n");
    printf("||            ultimate weapon in your dishwashing arsenal!              ||\n");
    printf("==========================================================================\n");
    printf("||                                Menu                                  ||\n");
    printf("||                       [1] Add kitchenware                            ||\n");
    printf("||                       [2] Wash kitchenware                           ||\n");
    printf("||                       [3] Top kitchenware                            ||\n");
    printf("||                       [4] Wash All                                   ||\n");
    printf("||                       [0] Exit                                       ||\n");
    printf("==========================================================================\n");
    printf("Enter choice: ");
}

// Function: Clear screen
// Description: Clears the screen by printing a newline character
void clearScreen() {
    printf("\033[H\033[2J");
}

// Function:  proceed
// Description: Displays a message prompting the user to press any key before clearing the console screen.
void proceed() {
  char enter;
    printf("\n\n\n\n\nPress X key to continue...");
    do{
    	scanf(" %c", &enter);
  	}while(enter != 'X' && enter != 'x');
    return;
}

// Function: Menu
// Description: This function displays the menu and prompts the user to enter a choice.
// Return: The user's choice as a character.
char menu() {
    char choice;
    // Ensures that the user enters a valid choice
    do {
        displayMenu();
        scanf(" %c", &choice);
        if (choice != '1' && choice != '2' && choice != '3' && choice != '4'&& choice != '5' && choice != '6' && choice != '0') {
        	clearScreen();
        	printf("Invalid Choice. Please choose again.\n");
        }
    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '0');
    return choice;
}

// Function: Task
// Description: This function performs the task based on the user's choice.
// Parameter: char choice - The user's choice as a character.
//           struct node **head - A pointer to the head of the linked list.
void task(char choice, struct node **S) {
	char* topItem;
	switch (choice) {
        case '1':
            push(S);
            proceed();
            clearScreen();
            break;
        case '2':
            pop(S);
            proceed();
            clearScreen();
            break;
        case '3':
            topItem = top(S);
            if (topItem != NULL) {
               printf("%s is next to be washed.\n", topItem);
            }
            proceed();
            clearScreen();
            break;
        case '4':
            makeNull(S);
            proceed();
            clearScreen();
            break;
        case '0':
            printf("Program exited.\n");
            exit(0);
        default:
            printf("Invalid choice. Exiting program.\n");
            exit(1);
    }
}

//Function: push
//Description: Pushes or adds as a new node to the top of the stack.
//Parameter: struct node **head - A pointer to the head of the linked list.
void push(struct node **S){
  //This checks if the stack is not full before pushing an item.
  if (*S == NULL || !isFull(S)){
    char kitchenware[100]; //Temporary storage for kitchenware
    printf("Enter kitchenware to be washed: ");
    scanf(" %[^\n]s", kitchenware);

    //This allocates memory for a new node and assigns the kitchenware to the data field.
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    //This checks if memoery allocation was successful.
    if (newNode == NULL){
      printf("Error: Memory allocation failed.\n");
      exit(1);
    }

    //This copies the kitchenware
    newNode->data = strdup(kitchenware);
    newNode->next = *S;
    *S = newNode;
  } else{
    printf("The STACK is FULL. Cannot add kitchenware\n");
  }
}

//Function: pop
//Description: Pops or removes the top element from the stack.
//Parameter: struct node **head - A pointer to the head of the linked list.
void pop(struct node **S){

  // This checks if the stack is not empty before popping
  if (!isEmpty(S)){
    printf("%s is being washed.\n", (*S)->data);

    struct node *temp = *S;
    *S = (*S)->next;
    // Free memory allocated for kitchenware
    free(temp->data);
    free(temp);
  } else{
    printf("The STACK is EMPTY. No more kitchenware to wash.\n");
  }
}

// Function: isFull
// Description: This checks if the stack is full.
// Parameter: struct node **head - A pointer to the head of the linked list.
// Return: True if stack is full, false otherwise.
int isFull(struct node **S) {
    int count = 0;
    struct node *current = *S;

    // Count the number of items in the stack
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Check if the count exceeds the maximum capacity
    return count >= MAX_CAPACITY ? 1 : 0;
}

// Function: top
// Description: This checks the top item of the stack.
// Parameter: struct node **head - A pointer to the head of the linked list.
// Return: The top item of the stack.
char* top(struct node** S) {
    if (isEmpty(S)) {
        printf("The STACK is EMPTY. No kitchenware to wash.\n");
        return NULL; 
    } else {
        struct node *current = *S;
        return current->data; 
    }
}


//Function: isEmpty
//Description: This checks if the stack is empty.
//Parameter: struct node **head - A pointer to the head of the linked list.
//Return: True if stack is empty, false otherwise.
int isEmpty(struct node** S) {
    return *S == NULL ? 1 : 0;
}

//Funtion: makeNull
//Description: This empties the stack.
//Parameter: struct node **head - A pointer to the head of the linked list.
void makeNull(struct node** S) {
    struct node *current = *S;
    struct node *next;

    // This goes through the list and frees the memory allocated to each node. 
    while (current != NULL) {
      printf("%s is being washed.\n", current->data);
      next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    // This sets the head pointer to NULL to indicate that the list is empty.
    *S = NULL;
    printf("The STACK is EMPTY. No kitchenware to wash.\n");
}
