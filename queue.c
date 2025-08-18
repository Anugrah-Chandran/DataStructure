#include <stdio.h>
#define SIZE 100
    int Q[SIZE];
    int item;
    int FRONT = -1,REAR = -1;

 int enqueue(int item){

    if(REAR == SIZE-1){
        printf("Overflow");
        return 0;
    }
    else{
        if(FRONT = -1)FRONT = 0;
        REAR = REAR+1;
        printf("Enter the item to be aded:");
        Q[REAR] = item;
        printf("\nThe item is:%d",item);
        return 1;

    }}
void dequeue(){

    if(FRONT == -1 || FRONT > REAR){
        printf("Underflow"); 
    }
    else{
        int item = Q[FRONT];
        printf("Deleted item is %d",item);
        FRONT = FRONT+1;
    }
}
void display(){
     if (FRONT == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = FRONT; i <= REAR; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");

}}


int main(){
    

    int choice,item;
   while(1){
        printf("\n1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice); 
        
        switch(choice){
            
            case 1:
                printf("Enter the value to be added:");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited");
                break;
            default:
                printf("Ivalid value");
                break;

        }
    }
}
 
