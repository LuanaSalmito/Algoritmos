#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

struct linked_list_int_node {
    int value;
    struct linked_list_int_node* prev;
    struct linked_list_int_node* next;
};

struct linked_list_int {
    struct linked_list_int_node* first;
    struct linked_list_int_node* last;
    unsigned int size;
};

// Cria uma nova lista em memória. Retorna um ponteiro para a lista recém criada.
struct linked_list_int* linked_list_create() {
    struct linked_list_int* new_list = (struct linked_list_int*)malloc(sizeof(struct linked_list_int));
    if (new_list == NULL) {
        return NULL;
    }

    new_list->first = NULL;
    new_list->last = NULL;
    new_list->size = 0;

    return new_list;
}

// Retorna um elemento localizado no índice index.
int linked_list_get(struct linked_list_int* list, int index, int* error) {
    if (list == NULL || index < 0 || index >= list->size) {
        *error = 1;
        return 0;
    }

    *error = 0;
    struct linked_list_int_node* current = list->first;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->value;
}

// Adiciona um novo elemento ao final da lista.
unsigned int linked_list_push_back(struct linked_list_int* list, int i) {
    struct linked_list_int_node* new_node = (struct linked_list_int_node*)malloc(sizeof(struct linked_list_int_node));
    if (new_node == NULL) {
        return list->size;
    }

    new_node->value = i;
    new_node->next = NULL;

    if (list->size == 0) {
        new_node->prev = NULL;
        list->first = new_node;
    } else {
        new_node->prev = list->last;
        list->last->next = new_node;
    }

    list->last = new_node;
    list->size++;

    return list->size;
}

// Remove um elemento do final da lista, caso exista. O final da lista é o índice tamanho-1.
unsigned int linked_list_pop_back(struct linked_list_int* list) {
    if (list == NULL || list->size == 0) {
        return list->size;
    }

    struct linked_list_int_node* last_node = list->last;
    if (list->size == 1) {
        list->first = NULL;
        list->last = NULL;
    } else {
        list->last = last_node->prev;
        list->last->next = NULL;
    }

    free(last_node);
    list->size--;

    return list->size;
}

// Retorna a quantidade de elementos na lista.
unsigned int linked_list_size(struct linked_list_int* list) {
    return (list == NULL) ? 0 : list->size;
}

// Busca um elemento na lista. Retorna o índice onde ele se encontra ou -1 se ele não estiver na lista.
int linked_list_find(struct linked_list_int* list, int element) {
    if (list == NULL) {
        return -1;
    }

    struct linked_list_int_node* current = list->first;
    int index = 0;
    while (current != NULL) {
        if (current->value == element) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

// Insere um novo elemento na lista, aumentando a quantidade de elementos. O elemento inserido deve se localizar no índice index.
unsigned int linked_list_insert_at(struct linked_list_int* list, int index, int value) {
    if (list == NULL || index < 0 || index > list->size) {
        return list->size;
    }

    struct linked_list_int_node* new_node = (struct linked_list_int_node*)malloc(sizeof(struct linked_list_int_node));
    if (new_node == NULL) {
        return list->size;
    }

    new_node->value = value;

    if (index == 0) {
        new_node->prev = NULL;
        new_node->next = list->first;
        list->first = new_node;
        if (list->size == 0) {
            list->last = new_node;
        }
    } else if (index == list->size) {
        new_node->prev = list->last;
        new_node->next = NULL;
        list->last->next = new_node;
        list->last = new_node;
    } else {
        struct linked_list_int_node* current = list->first;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->prev = current;
        new_node->next = current->next;
        current->next->prev = new_node;
        current->next = new_node;
    }

    list->size++;

    return list->size;
}

// Remove elemento localizado no índice index.
int linked_list_remove_from(struct linked_list_int* list, int index) {
    if (list == NULL || index < 0 || index >= list->size) {
        return -1;
    }

    int value;
    if (index == 0) {
        struct linked_list_int_node* first_node = list->first;
        value = first_node->value;
        list->first = first_node->next;
        if (list->size == 1) {
            list->last = NULL;
        } else {
            list->first->prev = NULL;
        }
        free(first_node);
    } else if (index == list->size - 1) {
        struct linked_list_int_node* last_node = list->last;
        value = last_node->value;
        list->last = last_node->prev;
        list->last->next = NULL;
        free(last_node);
    } else {
        struct linked_list_int_node* current = list->first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        value = current->value;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }

    list->size--;

    return value;
}

// Retorna o espaço efetivamente reservado para a lista.
unsigned int linked_list_capacity(struct linked_list_int* list) {
    return (list == NULL) ? 0 : list->size;
}

// Retorna o percentual do espaço reservado efetivamente ocupado por elementos da lista. O percentual é um valor entre 0.0 e 1.0.
double linked_list_percent_occupied(struct linked_list_int* list) {
    if (list == NULL || list->size == 0) {
        return 0.0;
    }

    return (double)list->size / linked_list_capacity(list);
}

// Libera memória usada pela lista.
void linked_list_destroy(struct linked_list_int* list) {
    if (list == NULL) {
        return;
    }

    struct linked_list_int_node* current = list->first;
    while (current != NULL) {
        struct linked_list_int_node* next_node = current->next;
        free(current);
        current = next_node;
    }

    free(list);
}

