#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    char url[256];
    struct node *previous;
    struct node *next;
} Node;

// Function to create a new node
Node* create_node(const char *url) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(new_node->url, url);
    new_node->previous = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to free all nodes starting from head
void free_all(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *current = NULL;  // Current page (initially NULL)
    int choice;
    char input_url[256];

    do {
        // Display menu
        printf("\n--- Browser Menu ---\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Show current page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline after scanf

        switch (choice) {
            case 1:
                // Visit new page
                printf("Enter URL: ");
                fgets(input_url, sizeof(input_url), stdin);
                input_url[strcspn(input_url, "\n")] = '\0';  // Remove newline

                // Clear forward history if it exists
                if (current != NULL && current->next != NULL) {
                    free_all(current->next);
                    current->next = NULL;
                }

                // Create new page
                Node *new_page = create_node(input_url);

                // Link with current if exists
                if (current != NULL) {
                    current->next = new_page;
                    new_page->previous = current;
                }

                // Move current to new page
                current = new_page;

                printf("Visited: %s\n", current->url);
                break;

            case 2:
                // Go back
                if (current != NULL && current->previous != NULL) {
                    current = current->previous;
                    printf("Moved back to: %s\n", current->url);
                } else {
                    printf("No previous page.\n");
                }
                break;

            case 3:
                // Go forward
                if (current != NULL && current->next != NULL) {
                    current = current->next;
                    printf("Moved forward to: %s\n", current->url);
                } else {
                    printf("No forward page.\n");
                }
                break;

            case 4:
                // Show current page
                if (current != NULL) {
                    printf("Current page: %s\n", current->url);
                } else {
                    printf("No page visited yet.\n");
                }
                break;

            case 5:
                // Exit and clean up memory
                if (current != NULL) {
                    // Move to head
                    while (current->previous != NULL)
                        current = current->previous;
                    free_all(current);
                }
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

