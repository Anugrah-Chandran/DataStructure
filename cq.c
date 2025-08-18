#include <stdio.h>

int main() {
	int n,j;       
    int front = -1, rear = -1;
    int operation, item;
    
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    int queue[n]; 
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your Operation: ");
        scanf("%d", &operation);

        if (operation == 1) {  
            if ((rear + 1) % n == front) {
                printf("Queue is Full\n");
            } else {
                 printf("Enter the number of elements to be added:");
                 scanf("%d",&j);
                 for(int i=0;i<j;i++){
                printf("Enter  %d element: ",i+1);
                scanf("%d", &item);
                if (front == -1) front = 0;
                rear = (rear + 1) % n;
                queue[rear] = item;
                printf("%d Inserted:\n", item);
                }
            }
        } 
        else if (operation == 2) {  
            if (front == -1) {
                printf("Queue is Empty\n");
            } else {
                item = queue[front];
                if (front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front = (front + 1) % n;
                }
                printf("Deleted item is:%d\n", item);
            }
        } 
        else if ( operation == 3) { 
            if (front == -1) {
                printf("Queue is Empty\n");
            } else {
                printf("Queue elements: ");
                int i = front;
                while (1) {
                    printf("%d ", queue[i]);
                    if (i == rear)
                        break;
                    i = (i + 1) % n;
                }
                printf("\n");
            }
        } 
        else if (operation  == 4) { 
        printf("Exiting program"); 
            break;
        } 
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
