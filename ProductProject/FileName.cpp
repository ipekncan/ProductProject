#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Node {
    int quantity;
    const char* productName;
    const char* productCategory;
    double productPrice;
    struct Node* next;
}node;
node* first = NULL;
struct Node* create(int q, const char* p, const char* pc, double price) {
    node* n = (node*)malloc(sizeof(node));


    n->quantity = q;
    n->productName = p;
    n->productCategory = pc;
    n->productPrice = price;
    n->next = NULL;
    return n;
}
void Insert(int q, const char* pn, const char* pct, double price) {
    node* newNode = create(q, pn, pct, price);
    //Sort for quantity
    if (first == NULL || first->quantity >= q) {
        newNode->next = first;
        first = newNode;//if added number is smaller then head
    }
    else {
        node* temp = first;
        while (temp->next != NULL && temp->next->quantity <= q) {
            // find the correct position
            temp = temp->next;
        }
        newNode->next = temp->next;//if added number is bigger
        temp->next = newNode;
    }

}

void writeList() {
    node* temp = first;

    while (temp != NULL) {
        printf("Quantity: %d\n %s\n %s\nPrice: %.2f\n",
            temp->quantity, temp->productName, temp->productCategory, temp->productPrice);
        temp = temp->next;
        printf("-----------------------------------\n");
    }
    printf(" [null]\n");
}



void delete_product(struct Node** list,char* name) {
    node* temp = *list;
    node* prev = NULL;

    if (*list == NULL) {
        printf("List is empty");
        return;
    }
    else if (strcmp(temp->productName, name) == 0) {
        // this code deletes first node
        *list = temp->next;
        free(temp);
        printf("Product deleted: %s\n", name);
        return ;
    }
    
        
        while (temp->next != NULL && strcmp(temp->productName, name) != 0) {
           
            prev = temp;
            temp = temp->next;
        }
       
        if(strcmp(temp->productName, name) == 0){
            prev->next = temp->next;
            free(temp);
            printf("Product deleted: %s\n", name);
            return;

        }
        
            printf("Product not found: %s\n", name);
            return;
        
     
    
}

int main() {
    int quantity;
    char name1[200];
    char category1[200];
    double price;
    char input;

    Insert(5, "Bread", "Food", 10.0);
    Insert(50, "Milk", "Beverage", 30.0);
    Insert(200, "Water", "Beverage", 10.0);



    do {
        printf("\n\nWelcome to product manager!\n\n\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Print all products\n");
        printf("Exit with x\n");
        printf("-----------------------------------\n");
        printf("Choose: ");
        scanf_s(" %c", &input); 
        system("CLS");
        switch (input) {
        case '1':
            printf("Write product's quantity: ");
            scanf_s("%d", &quantity);

            printf("Write product's name: ");
            scanf_s("%s", name1, sizeof(name1));  // for overflow safety

            printf("Write product's category: ");
            scanf_s("%s", category1, sizeof(category1));  // for overflow safety

            printf("Write product's price: ");
            scanf_s("%lf", &price);

            Insert(quantity, name1, category1, price);//call function for adding number
            printf("New product added\n\n");
            break;
        case '2':
            printf("Write the product's name that you want to delete: ");
            scanf_s("%s", name1, sizeof(name1));// for overflow safety
            delete_product(&first,name1);
           
            
            break;
        case '3':
            writeList();
            break;
        case 'x':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (input != 'x');
    return 0;
}
