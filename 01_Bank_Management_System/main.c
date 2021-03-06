#include "stdio.h"

struct account
{
    char *name;
    int age;
    int deposit;
};

void printMenu();
void createAccount(struct account *my_account);
void showAccount(struct account *my_account);
void removeAccount(struct account *my_account);

int main(int argc, char *argv[])
{
    int sel = 0;
    struct account *my_account;

    do {
        printMenu();

        scanf("%d", &sel);

        switch (sel)
        {
        case 1:
            createAccount(my_account);
            break;
        case 2:
            showAccount(my_account);
            break;
        case 3:
            removeAccount(my_account);
            break;
        default:
            break;
        }

    } while (sel != 0);

    return 0;
}

void printMenu()
{
    printf("\n\t\tBank Management System\n\n");

    printf("1. Create a new account\n");
    printf("2. Show account information\n");
    printf("3. Remove an account\n");
    printf("0. Exit\n\n");
}

void createAccount(struct account *my_account)
{
    printf("\tCreating a new account, please enter required information below.\n\n");

    printf("Enter your name: ");
    scanf("%s", &my_account->name);

    printf("Enter your age: ");
    scanf("%d", &my_account->age);

    printf("\nAccount for %s was created.", &my_account->name);
}

void showAccount(struct account *my_account)
{
    if (my_account->name == NULL && my_account->age == 0)
    {
        printf("Account does not exist\n");
        return;
    }
    printf("\t-------------------\n");    
    printf("\tAccount information\n");
    printf("\t-------------------\n");

    printf("Name:\t%s\n", &my_account->name);
    printf("Age:\t%d\n", my_account->age);
}

void removeAccount(struct account *my_account)
{
    my_account->name = NULL;
    my_account->age = 0;
    printf("\tAccount was removed\n");
}