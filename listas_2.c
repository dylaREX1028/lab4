#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estructura de un nodo
struct Node {
    int data;
    struct Node *next;
};

// Función que añade un nodo al final de la lista
void appendNode(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Se crea un nuevo nodo
    newNode->data = value; // Se le asigna un valor
    newNode->next = NULL; // El último nodo se establece como nulo 


    // Condicional respecto al estado de la lista
    if (*head == NULL) {
        *head = newNode; // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    } else {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next; // Recorrido de la lista para encontrar el último nodo
        }
        current->next = newNode; // Unir el nuevo nodo al último nodo de la lista
    }
}

// Función para eliminar un nodo por valor
void deleteNodeByValue(struct Node **head, int value) {
    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next; // Se recorre la lista para encontrar el nodo con el valor a eliminar
    }

    if (current == NULL) {
        printf("El valor %d no se encontró en la lista.\n", value);
    } else {
        if (prev == NULL) {
            *head = current->next; // Si el nodo a eliminar es la cabeza, actualizar la cabeza
        } else {
            prev->next = current->next; // Se une el nodo anterior al siguiente nodo
        }
        free(current); // Se libera el nodo eliminado
    }
}

// Función para agregar un nodo al inicio de la lista
void prependNode(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Se crea un nuevo nodo
    newNode->data = value; // Se le asigna el valor
    newNode->next = *head; // El siguiente del nuevo nodo es la cabeza actual
    *head = newNode; // El nuevo nodo se convierte en la nueva cabeza
}

// Función para buscar un nodo por su valor
void searchNodeByValue(struct Node *head, int value) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            printf("El valor %d se encontró en la lista.\n", value);
            return;
        }
        current = current->next; // Se rRecorre la lista en busca del valor
    }
    printf("El valor %d no se encontró en la lista.\n", value);
}

// Función para imprimir la lista
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data); // Se imprime el valor del nodo actual
        current = current->next; // Se mueve al siguiente nodo
    }
    printf("NULL\n");
}

// Función para obtener el elemento enésimo
void getNodeByIndex(struct Node *head, int index) {
    struct Node *current = head;
    int i = 0;

    while (current != NULL && i < index) {
        current = current->next; // Recorrer la lista hasta el índice especificado
        i++;
    }

    if (current != NULL) {
        printf("Elemento en el índice %d: %d\n", index, current->data);
    } else {
        printf("No se encontró un elemento en el índice %d.\n", index);
    }
}

// Función para liberar la memoria de la lista
void freeList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp); // Se Libera el nodo actual
    }
}


// Main del programa que ejemplifica el uso de cada una de estas operaciones.
int main() {
    struct Node *head = NULL;
    srand(time(NULL)); // Se genera números aleatorios

    // Se crea una lista con 5 valores aleatorios entre 1 y 100
    for (int i = 0; i < 5; i++) {
        int randomValue = rand() % 100 + 1; // Genera números aleatorios entre 1 y 100
        appendNode(&head, randomValue); // Se guarda los números aleatorio a la lista
    }

    printf("Lista inicial: ");
    printList(head);

    // Realizar operaciones con la lista e imprime los valores
    deleteNodeByValue(&head, 20);
    printf("Después de eliminar el valor 20: ");
    printList(head);

    prependNode(&head, 5);
    printf("Después de agregar 5 al inicio: ");
    printList(head);

    appendNode(&head, 40);
    printf("Después de agregar 40 al final: ");
    printList(head);

    searchNodeByValue(head, 30);
    searchNodeByValue(head, 50);

    getNodeByIndex(head, 2);
    getNodeByIndex(head, 5);

    // Liberar la memoria de la lista
    freeList(head);

    return 0;
}

