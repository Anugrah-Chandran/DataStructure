#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* data[MAX];
    int top;
} NodeStack;

void initNodeStack(NodeStack* s) {
    s->top = -1;
}
void pushNode(NodeStack* s, Node* node) {
    s->data[++(s->top)] = node;
}
Node* popNode(NodeStack* s) {
    return s->data[(s->top)--];
}
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


int isOperand(char c) {
    return isalnum(c); 
}


Node* constructExpressionTree(char* postfix) {
    NodeStack nodeStack;
    initNodeStack(&nodeStack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isOperand(c)) {
            Node* newNode = createNode(c);
            pushNode(&nodeStack, newNode);
        } else { 
            Node* newNode = createNode(c);
            Node* rightChild = popNode(&nodeStack);
            Node* leftChild = popNode(&nodeStack);
            newNode->left = leftChild;
            newNode->right = rightChild;
            pushNode(&nodeStack, newNode);
        }
    }

    return popNode(&nodeStack); 
}


void PrintPrefix(Node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    PrintPrefix(root->left);
    PrintPrefix(root->right);
}


void PrintPostfix(Node* root) {
    if (root == NULL) return;
    PrintPostfix(root->left);
    PrintPostfix(root->right);
    printf("%c", root->data);
}

int main() {
    char infix[MAX], postfix[MAX], stack[MAX];
    int k = 0, top = -1;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {  
            postfix[k++] = c;
        } 
        else if (c == '(') {
            if (top == MAX - 1) {
                printf("Stack overflow\n");
                return 0;
            }
            stack[++top] = c;
        } 
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(') {
                top--; 
            } else {
                printf("Invalid expression\n");
                return 0;
            }
        } 
        else {
            int prec;
            if (c == '^') prec = 3;
            else if (c == '*' || c == '/') prec = 2;
            else if (c == '+' || c == '-') prec = 1;
            else prec = 0;

            while (top != -1) {
                char topOp = stack[top];
                int topPrec;
                if (topOp == '^') topPrec = 3;
                else if (topOp == '*' || topOp == '/') topPrec = 2;
                else if (topOp == '+' || topOp == '-') topPrec = 1;
                else topPrec = 0;

                if ((prec < topPrec) || (prec == topPrec && c != '^')) {
                    postfix[k++] = stack[top--];
                } else {
                    break;
                }
            }

            stack[++top] = c;
        }
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf("Invalid expression\n");
            return 0;
        }
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0'; 

    printf("Postfix expression: %s\n", postfix);

    
    Node* root = constructExpressionTree(postfix);

   
    printf("Prefix expression: ");
    PrintPrefix(root);
    printf("\n");

   
    printf("Postfix expression (from tree): ");
    PrintPostfix(root);
    printf("\n");

    return 0;
}
 
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                

