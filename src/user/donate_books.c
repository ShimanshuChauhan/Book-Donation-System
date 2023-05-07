#include "../utils/print.c"
#include <stdio.h>
#include "../utils/trim.c"
#include "../data/data.h"
#include "../utils/delay.c"

int donateBooks()
{
    char username[100], address[100], phone[12];
    printSubHeading("Donate Book");
    printf("Let's get started by filling in some details about you:\n");
    fflush(stdin); 

    printf("Your name: ");
    fgets(username, 100, stdin);
    char *trimmedUsername = trim(username);
    fflush(stdin);

    printf("Your Address: ");
    fgets(address, 100, stdin);
    char *trimmedAddress = trim(address);
    fflush(stdin);

    printf("Your Phone Number: ");
    fgets(phone, 100, stdin);
    char *trimmedPhone = trim(phone);
    fflush(stdin);

    char bookname[100], author[100];
    printInfo("\nNow, Let's get some details regarding the book:\n\n");
    fflush(stdin);

    printf("Book name: ");
    fgets(bookname, 100, stdin);
    char *trimmedBookName = trim(bookname);
    fflush(stdin);

    printf("Author: ");
    fgets(author, 100, stdin);
    char *trimmedAuthor = trim(author);
    fflush(stdin);

    printInfo("\nBook Details:");
    printf("\nBook Name: %s | ", trimmedBookName);
    printf("Author: %s | ", trimmedAuthor);
    printf("Name: %s | ", trimmedUsername);
    printf("Address: %s | ", trimmedAddress);
    printf("Phone: %s  ", trimmedPhone);

    addDelay();
    addBook(trimmedBookName, trimmedAuthor, trimmedUsername, trimmedPhone, trimmedAddress);

    return 1;
}