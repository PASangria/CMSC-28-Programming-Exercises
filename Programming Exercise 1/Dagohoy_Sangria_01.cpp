/* A program created by Dave Laurence Dagohoy and Prescious Apple Sangria */
// BSCS -1 
// Programming Exercises 01
// List Implementation (Linked List)

// Program Description:
// This program creates a linked list that receives a string character (it could be numbers, words, or a sentence. 
// The only limit is that the program can't store a string that includes a new line). 
// It can add and delete item from the list, and display and delete the list. 

//Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure for the linked list node
struct node {
    char* item;
    struct node *next;
};

// Function prototypes
char menu();
void task(char choice, struct node **head);
void addMenu(struct node **head);
void insertBeginning(struct node **head, const char* item);
void insertEnd(struct node **head, const char* item);
void insertSpecific(struct node **head, const char* item, int position);
void displayList(struct node **head);
void deleteItem(struct node **head);
void deleteList(struct node **head);

// Main Function
int main() {
    struct node *head = NULL; 
    char choice;
    do {
        choice = menu();
        task(choice, &head); 
    } while (choice != '0');

    printf("Program exited.\n");
    return 0;
}


// Function: Menu
// Description: This function displays the menu and prompts the user to enter a choice.
// Return: The user's choice as a character.
char menu() {
    char choice;
    // Ensures that the user enters a valid choice
    do {
        printf("\nMenu\n");
        printf("[1] Add Item\n");
        printf("[2] Delete Item\n");
        printf("[3] Display List\n");
        printf("[4] Delete List\n");
        printf("[0] Exit Program\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '0') {
            printf("Invalid Choice. Please choose again.\n");
        }
    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '0');
    return choice;
}

// Function: Task
// Description: This function performs the task based on the user's choice.
// Parameter: char choice - The user's choice as a character.
//           struct node **head - A pointer to the head of the linked list.
void task(char choice, struct node **head) {
    switch (choice) {
        case '1':
            addMenu(head);
            break;
        case '2':
            deleteItem(head);
            break;
        case '3':
            displayList(head);
            break;
        case '4':
            deleteList(head);
            break;
        case '0':
            printf("Program exited.\n");
            exit(0);
        default:
            printf("Invalid choice. Exiting program.\n");
            exit(1);
    }
}

// Function: Add Menu
// Description: This function displays the add menu and prompts the user to enter a choice. 
//              The menu contains options to add an item to the beginning, end, or a specific position. 
//              This also asks user what item to insert in the list.
// Parameter: struct node **head - A pointer to the head of the linked list.
void addMenu(struct node **head) {
    char item[100]; 
    int position;
    char choice;
  
    printf("\nPlease enter the item to be added: ");
    // The syntax below allows user to enter a string with spaces
    scanf(" %[^\n]", item);
    getchar();

   // The do-while loop ensures that the user enters a valid choice.
    do {
        printf("\nWhere to add the item?\n");
        printf("[1] Start of the list\n");
        printf("[2] End of the list\n");
        printf("[3] Specific position\n");
        printf("[0] Cancel\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        if (choice != '1' && choice != '2' && choice != '3' && choice != '0') {
            printf("\nInvalid choice. Please choose again.");
        }
    } while (choice != '1' && choice != '2' && choice != '3' && choice != '0');
    
    // The switch statement executes the corresponding action based on the user's choice.
    switch (choice) {
        case '1':
            insertBeginning(head, item);
            break;
        case '2':
            insertEnd(head, item); 
            break;
        case '3':
            printf("\nWhich position do you want to add this item? ");
            printf("\nPosition: ");
            scanf("%d", &position);
            insertSpecific(head, item, position);
            break;
        case '0':
            return;
        default:
            printf("Invalid Choice. Exiting program.");
            exit(1);
    }
}

// Function: Insert Beginning
// Description: This function inserts an item at the beginning of the linked list.
// Parameters: struct node **head - A pointer to the head of the linked list.
//            const char *item - The item to be inserted.
void insertBeginning(struct node **head, const char* item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nMemory allocation failed");
        return;
    }
    ptr->item = (char*)malloc(strlen(item) + 1); 
    strcpy(ptr->item, item); 
    ptr->next = *head;
    *head = ptr;
    printf("\nNode inserted");
}

// Function: Insert End
// Description: This function inserts an item at the end of the linked list.
// Parameters: struct node **head - A pointer to the head of the linked list.
//            const char *item - The item to be inserted.
void insertEnd(struct node **head, const char* item) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nMemory allocation failed");
        return;
    }
    ptr->item = (char*)malloc(strlen(item) + 1); 
    strcpy(ptr->item, item); 
    ptr->next = NULL;
    
    if (*head == NULL) {
      // If the list is empty, the new node becomes the head.
      *head = ptr;
    } else {
        struct node *temp = *head;
        // Traverse to the last node and adds the item to the end.
        while (temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = ptr;
    }
    printf("\nNode inserted");
}

// Function: Insert Specific
// Description: This function inserts an item at a specific position in the linked list.
// Parameters: struct node **head - A pointer to the head of the linked list.
//            const char *item - The item to be inserted.
//            int position - The position at which to insert the item.
void insertSpecific(struct node **head, const char* item, int position) {
    int i;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nMemory allocation failed");
        return;
    }
    ptr->item = (char*)malloc(strlen(item) + 1); 
    strcpy(ptr->item, item);

    if (position == 1) {
        // Inserts the item at the beginning of the list.
        ptr->next = *head;
        *head = ptr;
    } else {
        // Finds the node at the specified position.
        struct node *temp = *head;
        for (i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        // If the position is out of range, the function calls insertEnd function to insert it to the end of the list.
        if (temp == NULL) {
            printf("\nPosition does not exist. Adding the item to the end of the list.\n");
            insertEnd(head, item);
            return;
        }
        // Inserts the item at the specified position.
        ptr->next = temp->next;
        temp->next = ptr;
    }
    printf("\nNode inserted");
}

// Function: Display List
// Description: This function displays the linked list.
// Parameters: struct node **head - A pointer to the head of the linked list.
void displayList(struct node **head) {
    printf("\nLIST content:\n");
    int position = 0;
    struct node *current = *head;
    if (current == NULL) {
    	printf("\nList is currently empty.");
	}else{
       // Traverses the list and prints the item at each node.
        while (current != NULL) {
            position++;
            printf("Position %d: %s\n", position, current->item);
            current = current->next;
        }
    }
    printf("\n");
}

// Funtion: Delete Item
// Description: This function deletes an item from the linked list.
// Paremeters: struct node **head - A pointer to the head of the linked list.
void deleteItem(struct node **head){
  int position = 1;
  char item[100];
  bool is_found = false;
  struct node *current, *previous;

  printf("Enter an item to delete: ");
  scanf("%s", item);

  current = *head;
  previous = NULL;

  // This goes through the list to find where the item we're searching for is kept
  while(current != NULL){
    if (strcmp(current->item, item) == 0){
      is_found = true;
      break;
    }
    // This updates the previous pointer to current node
    previous = current;    
    current = current->next;
    position++;
  }

  // This checks if the item is not found in the list
  if (is_found == false){
    printf("The list does not contain the item %s. \n", item);
  }

  // This is executed when the item is found in the list
  else{
    if(previous == NULL){
      *head = current->next;
    }
    else{
      previous->next = current->next;
    }
    printf("The element %s, which is at position %d, has been deleted. \n", item, position);

    free(current);
  }
}

// Function: Delete List
// Description: This function deletes the entire linked list.
// Parameters: struct node **head - A pointer to the head of the linked list.
void deleteList(struct node **head)
{
    struct node *current = *head;
    struct node *next;

    // This goes through the list and frees the memory allocated to each node. 
    while (current != NULL)
    {
       next = current->next;
       free(current);
       current = next;
    }
   // This sets the head pointer to NULL to indicate that the list is empty.
   *head = NULL;
   printf("The list has been emptied!");
}
