//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define PHONE_LEN 20

struct Contact {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
};

/* Add a contact to dynamic array */
int addContact(
    struct Contact** contacts,
    int* size,
    const char* name,
    const char* phone
) {
    if (!contacts || !size || !name || !phone)
        return 0;

    struct Contact* temp =(struct Contact*) (realloc(
        *contacts,
        (*size + 1) * sizeof(struct Contact)
    ));

    if (!temp)
        return 0;

    *contacts = temp;

    strncpy((*contacts)[*size].name, name, NAME_LEN - 1);
    (*contacts)[*size].name[NAME_LEN - 1] = '\0';

    strncpy((*contacts)[*size].phone, phone, PHONE_LEN - 1);
    (*contacts)[*size].phone[PHONE_LEN - 1] = '\0';

    (*size)++;
    return 1;
}

/* Print single contact */
void printContact(const struct Contact* c) {
    if (!c) return;

    printf("Contact Details\n");
    printf("Name  : %s\n", c->name);
    printf("Phone : %s\n\n", c->phone);
}

/* Display all contacts */
void displayAllContacts(const struct Contact* contacts, int size) {
    if (!contacts) return;

    for (int i = 0; i < size; i++) {
        printContact(&contacts[i]);
    }
}

/* Find contact by name */
struct Contact* findContact(
    struct Contact* contacts,
    int size,
    const char* name
) {
    if (!contacts || !name)
        return NULL;

    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0)
            return &contacts[i];
    }
    return NULL;
}

/* Cleanup all memory */
void cleanupContacts(struct Contact** contacts, int* size) {
    if (!contacts || !*contacts)
        return;

    free(*contacts);
    *contacts = NULL;
    *size = 0;
}

/* ------------------- MAIN ------------------- */

int main(void) {
    struct Contact* contacts = NULL;
    int size = 0;

    addContact(&contacts, &size, "hello", "19929123");
    addContact(&contacts, &size, "john", "88888888");

    displayAllContacts(contacts, size);

    struct Contact* found = findContact(contacts, size, "hello");
    printContact(found);

    cleanupContacts(&contacts, &size);
    return 0;
}
