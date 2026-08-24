#include <stdio.h>

int main()
{
    int choice;
    float balance = 5000, amount;

    do
    {
        printf("\n1. Check Balance");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Transfer");
        printf("\n5. Account Details");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Balance = %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount: ");
                scanf("%f", &amount);

                if(amount > 0)
                    balance = balance + amount;
                else
                    printf("Invalid amount\n");
                break;

            case 3:
                printf("Enter amount: ");
                scanf("%f", &amount);

                if(amount > 0 && amount <= balance)
                    balance = balance - amount;
                else
                    printf("Insufficient balance\n");
                break;

            case 4:
                printf("Enter amount: ");
                scanf("%f", &amount);

                if(amount > 0 && amount <= balance)
                    balance = balance - amount;
                else
                    printf("Insufficient balance\n");
                break;

            case 5:
                printf("Account Number: 1001\n");
                printf("Balance = %.2f\n", balance);
                break;

            case 6:
                printf("Thank you\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 6);

    return 0;
}
