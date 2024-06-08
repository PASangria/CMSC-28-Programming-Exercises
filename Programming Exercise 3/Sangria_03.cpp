// A program created by Prescious Apple D. Sangria
// BSCS-1
// Programming Exercise 03

// Program Description:
// This program implements a queue data structure and has the following functions: checks if a queue is empty, 
// enqueues a new node, dequeues a node, and prints the front node.
// This implementation can be shown in the grocery checkout application with the following menus: Fall in Line(Enqueue), 
// Serve Customer(Dequeueu), Next Customer(Peek), Closing Time(A loop containing Dequeue), and Exit.

// Headers
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Defining the structure node
struct Node {
    float amount;
    char name[100];
    struct Node *next;
};

// Defining the structure queue
struct queue {
    struct Node *front;
    struct Node *rear;
    int queueSize;
};

// Function Prototypes
char displayMenu();
struct queue *init();
void task(char choice, struct queue *Q);
bool empty(struct queue *Q);
void enqueue(char* name, float amount, struct queue *Q);
struct Node *dequeue(struct queue *Q);
struct Node *front(struct queue *Q);
float getNumericInput(const char *prompt);
bool isValidFloat(const char *str);
char* getCustomerName(const char *prompt);
void headerDisplay();
void clearScreen();
void proceed();

// Main Function
int main() { 
    char choice;
    struct queue *Q;
    struct queue *checkoutQueue = init();
    do {
        choice = displayMenu();
        task(choice, checkoutQueue);	
    } while (choice != '0');
    return 0;
}

// Function: Display Menu
// Description: This function displays the menu and prompts the user to enter a choice.
// Return: The choice entered by the user.
char displayMenu() {
    char choice;
    char input[10];
    int stringLength;
    // Ensuring that the user enters a valid choice.
    do {
        headerDisplay();
	    printf("  [1] Fall in Line                        \n");
	    printf("  [2] Serve customer                      \n");
	    printf("  [3] Next customer                       \n");
	    printf("  [4] Closing time                        \n");
	    printf("  [0] Exit                                \n");
	    printf("===================================================================================\n");
	    printf("   Enter Choice: ");
        scanf(" %s", &input);
        stringLength = strlen(input);
        if (stringLength == 1) {
            choice = input[0];
        }
        if (stringLength != 1 || (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '0')) {
        	clearScreen();
            printf("\n Invalid choice. Please choose again.\n");
        }
    } while (stringLength != 1 || (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '0'));
    return choice;
}

// Function: headerDisplay
// Description: Displays the header of the checkout system
void headerDisplay(){
	printf("===================================================================================\n");
    printf("                                      Mr. DIY                                      \n");
    printf("                                     Counter 0		                    		  \n");
    printf("-----------------------------------------------------------------------------------\n");
}

// Function: Task
// Description: This function performs the task based on the user's choice.
// Parameters:
//      char choice: The user's choice.
//      struct queue *Q: A pointer to the queue structure.
void task(char choice, struct queue *Q) {
    float amount;
    char* name;
    struct Node *customer;
    clearScreen();
    switch(choice) {
        // Enqueues one customer info
        case '1':
        	headerDisplay();
            name = getCustomerName(" Customer Name: ");
            amount = getNumericInput(" Total Payables: ");
            printf("\n\n");
            enqueue(name, amount, Q);
            proceed();
            clearScreen();
            break;
        // Dequeues one customer info
        case '2':
        	headerDisplay();
            if (!empty(Q)) {
                customer = dequeue(Q);
                printf(" Now serving %s with total amount payable of %.4f.\n\n", customer->name, customer->amount);
                free(customer);
            } else {
                printf(" The QUEUE is EMPTY. No orders to serve.\n\n");
            }
            proceed();
            clearScreen();
            break;
        // Peeks the info of the front customer
        case '3':
        	headerDisplay();
            customer = front(Q);
            if (!empty(Q)) {
                printf(" Next order: For %s with total amount payable of %.4f.\n\n", customer->name, customer->amount);
            } else {
                printf(" The QUEUE is EMPTY. No orders to serve.\n\n");
            }
            proceed();
            clearScreen();
            break;
        // Dequeues all the remaining items in the queue
        case '4':
        	headerDisplay();
            while(!empty(Q)) {
                customer = dequeue(Q);
                printf(" Now serving %s with total amount payable of %.4f.\n\n", customer->name, customer->amount);
            }
            printf(" The QUEUE is EMPTY. No orders to serve.\n\n");
            proceed();
            clearScreen();
            break;
        case '0':
        	clearScreen();
            printf(" Checkout system has been terminated.\n\n");
            break;
        default:
            printf(" Invalid Choice. Please choose again\n\n");
            proceed();
            clearScreen();
            break;
    }
}

// Function: Init
// Description: This function initializes a new queue.
// Return: A pointer to the new queue.
struct queue *init() {
    struct queue *Q = (struct queue*)malloc(sizeof(struct queue));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

// Function: empty
// Description: This function checks if the queue is empty.
// Parameter: struct queue *Q: A pointer to the queue structure.
// Return: true if the queue is empty, false otherwise.
bool empty(struct queue *Q) {
    return (Q->front == NULL);   
}

// Function: Front
// Description: This function returns the front node of the queue.
// Parameter: struct queue *Q: A pointer to the queue structure.
// Return: A pointer to the front node of the queue which contains the info of the front customer or NULL if the queue is empty.
struct Node *front(struct queue *Q) {
    if (empty(Q)) {
        return NULL;
    } else {
        return Q->front;
    }
}

// Function: enqueue
// Description: This function enqueues a new node at the end of the queue.
// Parameters: char* name: The name of the customer.
//             float amount: The total amount payable.
//             struct queue *Q: A pointer to the queue structure.
void enqueue(char* name, float amount, struct queue *Q) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed for newNode.\n");
        return;
    }
    strcpy(newNode->name, name);
    newNode->amount = amount;
    newNode->next = NULL;
    if (empty(Q)) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

// Function: dequeue
// Description: This function dequeues the front node of the queue.
// Parameter: struct queue *Q: A pointer to the queue structure.
// Return: A pointer to the dequeued node that contains the info of the front customer or NULL if the queue is empty.
struct Node *dequeue(struct queue *Q) {
    if (!empty(Q)) {
        struct Node *temp = Q->front;
        Q->front = Q->front->next;
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
        return temp;
    } else {
        return NULL;
    }
}

// Function: IsValidFloat
// Description: Checks if the input of the user is a valid float number
// Parameter: const char* prompt: a string that contains the user input
// Return: True if the whole string is a valid float number, false if otherwise
bool isValidFloat(const char *str) {
    int dotCount = 0;
    int stringLength = strlen(str);
    // This loop continues until all characters in the string is checked
    for (int i = 0; str[i] != '\0'; i++) {
        // Checks if all characters are either a number or a dot(represents decimal)
        if (!isdigit(str[i]) && str[i] != '.') {
            return false;
        }
        // Checks how many dots are present
        if (str[i] == '.') {
            dotCount++;
            // Checks if there are invalid number of dots  or if the user inputs '.' only.
            if (dotCount > 1 || (str[i + 1] == '\0' && stringLength == 1)) {
                return false;
        	}
		}
    }
    return true;
}

// Function: getNumericInput
// Description: Takes the user's total amount of payables and checks if the input is a valid float number
// Parameter: const char *prompt: a string that contains the statement used to take input from the user
// Return: A valid float number containing the total amount of payables of a customer
float getNumericInput(const char *prompt) {
    char input[100];
    printf("%s", prompt);
    // This loops continues until a float is validated by the program
    while (1) {
        scanf("%99s", input);
        if (isValidFloat(input)) {
            return atof(input);
        } else {
            printf(" Invalid input. Please enter a numeric value\n\n%s", prompt);
            while (getchar() != '\n');
        }
    }
}

// Function: getCustomerName
// Description: Takes the customer's name and check if it is a valid name (that is, it doesn't contain any numbers or special characters)
// Parameter: const char *prompt: a string containing the command used to take user input
// Return: a string containing a valid customer name
char* getCustomerName(const char *prompt) {
    static char str[100];
    bool status;
    do {
        status = true;
        printf("%s", prompt);
        scanf(" %[^\n]s", str);
        int stringLength = strlen(str);
        for (int index = 0; index < stringLength; index++) {
            if (!isalpha(str[index]) && str[index] != ' ') {
                printf(" Invalid name. Please type again.\n\n");
                status = false;
                break;
            }
        }
    } while (!status);
    return str;
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
