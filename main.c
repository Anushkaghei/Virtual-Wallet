#include "Customer_Billing.h"
  struct account 
  {
	char name[100];
	int acct_no;
	long mobile_no;
	char city[100];
	float balance;
  }customer[1000]; //Variable declared with structure account

int cust_count = 0,act_no = 0, id = 101,i=0;
char ch,d;
int main()
{
    
	    printf("\n1: Add New Customer Wallet.\n");
	    printf("2: Search Existing Customer Account.\n");
        printf("3: Pay the Bills.\n");
        printf("4: Print All Customers Details.\n");
        printf("5: Top-Up Balance.\n");
        printf("6: Exit\nEnter your choice:\n");
	    
    while(1)
    {
        scanf("%c",&ch); 
        switch (ch)
        {
            case '1'://new customer wallet
                cust_count += 1;
                 printf("Serial number:- %d", cust_count);
                int id = createAccount(i);
                i += 1;
                printf("Your Account Number is:- %d\n\n", id);
                main();
                break;

            case '2'://search existing customer account
                printf("Enter the Account Number:- ");
                scanf("%d", &act_no);
                searchACustomer(act_no);
                main();
                break;

            case '3'://pay the bill
                printf("Enter the Account Number:- ");
                scanf("%d", &act_no);
                payBill(act_no);
                main();
                break;

            case '4'://print all customer details
                printAllCustomers();
                main();
                break;

            case '5'://top up balance
                printf("Enter Your Account Number:- ");
                scanf("%d", &act_no);
                addBalance(act_no);
                main();
                break;

            case '6'://exit
                printf("\nRecords Saved Successfully\nThank you for using the program\n\n");
                exit(0);
                break;
        }
    }
}

int createAccount(int ind)
{
    customer[ind].acct_no = id++;
    printf("\nEnter the name of the customer:- ");
    scanf("%s", customer[ind].name);


    printf("Enter Contact Number:-\t");
    scanf("%ld", &customer[ind].mobile_no);


    printf("Enter city:- ");
    scanf("%s", customer[ind].city);


    printf("How much balance you want to maintain:- ");
    scanf("%f", &customer[ind].balance);
    
    return customer[ind].acct_no;
}
     
void searchACustomer(int act_no)
{
    for(int i = 0; i < cust_count; i++)
    {
        if(customer[i].acct_no == act_no)
        {
            printf("Customer ID is:- %d\n", customer[i].acct_no);
            printf("Customer name:- %s\n", customer[i].name);
            printf("Customer mobile number:- %ld\n", customer[i].mobile_no);
            printf("customer city name:- %s\n", customer[i].city);
            printf("Account balance:- %.2f\n\n", customer[i].balance);
        }
        else
            printf("\nInvalid account number\n");
    }
    return;
}
void payBill(int act_no)
{
    float amount = 0;
    printf("Enter the bill amount to Pay:- ");
    scanf("%f", &amount);
    if(amount>0.0)
    {
        for(int i = 0; i < cust_count; i++)
        {
            if (customer[i].acct_no == act_no)
            {
                if (customer[i].balance >= amount) 
                {
                    customer[i].balance -= amount;
                    printf("Updated Balance:- %.2f\n", customer[i].balance);
                }
                else 
                {
                    printf("\nAdd Balance to your Wallet:- ");
                    addBalance(act_no);
                }
            }
            else
                printf("\nInvalid account number\n");
        }
    }
    else
        printf("\nEnter a positive value instead\n");

    return;
}
void addBalance(int act_no)
{
    float amount = 0;
    printf("\nEnter the amount to add for your Wallet:- ");
    scanf("%f", &amount);
    for(int i =0; i < cust_count; i++)
    {
        if (customer[i].acct_no == act_no)
        {
            customer[i].balance += amount;
            printf("Updated account balance:- %.2f\n\n", customer[i].balance);
        }
        else
            printf("\nInvalid account number\n");
    }
    return;
}
void printAllCustomers() 
{
    for (int i = 0; i < cust_count ; i++ )
    {
        printf("CUSTOMER-- %d\n", (i+1));
        printf("\t Customer ID:- %d\n", customer[i].acct_no);
        printf("\t customer name:- %s\n", customer[i].name);
        printf("\t customer mobile:- %ld\n", customer[i].mobile_no);
        printf("\t Customer city:- %s\n", customer[i].city);
        printf("\t Customer Balance:- %.2f\n", customer[i].balance);
    }
    return;
}