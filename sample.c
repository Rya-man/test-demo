#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
} DynamicArray;

void arrayDefinition(DynamicArray *dynArr) {
    printf("Enter the array size: ");
    scanf("%d", &dynArr->size);
    
    dynArr->arr = (int*)malloc(dynArr->size * sizeof(int));
    
    printf("Enter the array elements: ");
    for(int i = 0; i < dynArr->size; i++) {
        scanf("%d", &(dynArr->arr[i]));        
    }
}

void display(DynamicArray dynArr) {
    printf("Array elements: ");
    for(int i = 0; i < dynArr.size; i++) {
        printf("%d\t", dynArr.arr[i]);
    }
    printf("\n");
}

void insertion(DynamicArray *dynArr) {
    int pos, ele;
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    printf("Enter the element: ");
    scanf("%d", &ele);

    dynArr->size += 1;
    dynArr->arr = (int*)realloc(dynArr->arr, dynArr->size * sizeof(int));

    for(int i = dynArr->size - 1; i > pos; i--) {
        dynArr->arr[i] = dynArr->arr[i - 1];
    }
    dynArr->arr[pos] = ele;
}

void deletion(DynamicArray *dynArr) {
    int pos;
    printf("\nEnter the position to be deleted: ");
    scanf("%d", &pos);

    for(int i = pos; i < dynArr->size - 1; i++) {
        dynArr->arr[i] = dynArr->arr[i + 1];
    }
    dynArr->size -= 1;
    dynArr->arr = (int*)realloc(dynArr->arr, dynArr->size * sizeof(int));
}

int main() {
    DynamicArray dynArr;
    int choice;
    
    arrayDefinition(&dynArr);

    do {
        printf("\nChoose an operation:\n");
        printf("1. Display\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                display(dynArr);
                break;
            case 2:
                insertion(&dynArr);
                break;
            case 3:
                deletion(&dynArr);
                break;
            case 4:
                free(dynArr.arr);
                return 0;
            default:
                printf("\nEnter a valid choice!\n");
        }
    } while(1);

    free(dynArr.arr);
    return 0;
}
