#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int i,j,pintemp;
int main_exit;

void menu();
struct date
{
    int month,day,year;
};
struct {
    char name[60];
    int acc_no,age,pin,rate;
    char address[60],phone[10];
    char nationality[15];
    char acc_type[10];
    float amt,loanamt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc()
{
    int choice;
    FILE *ptr;
    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");
    y:
    printf("Enter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    if(add.deposit.month>12 || add.deposit.month<1||add.deposit.day>31||add.deposit.day<1)
    {
    	printf("Wrong Date try again!\n");
    	goto y;
	}
	printf("\nEnter the account number:\n");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d\n",&add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
         { 
			printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;
         }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",&add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nCreate your own secure 4 Digit pin:");
    scanf("%d",&add.pin);
	printf("\nEnter the address:(please use '-' instead of space if needed)");
    scanf("%s",&add.address);
    printf("\nEnter the nationality:");
    scanf("%s",&add.nationality);
    a:
    printf("\nEnter the phone number: ");
    scanf("%s",&add.phone);
    if(strlen(add.phone)!=10)
    {
    	printf("Invalid phone number! Please enter a valid 10 digit phone number\n");
    	goto a;
	}
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice(name):");
    scanf("%s",&add.acc_type);
    add.loanamt=0;
    add.rate=0;
    fprintf(ptr,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            exit(1);
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\t\tPHONE\t\t\tADDRESS\t\t\tNAME\n");
    while(fscanf(view,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d",&add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
		   printf("\n%d\t\t%s\t\t%s\t\t%s",add.acc_no,add.phone,add.address,add.name);
           test++;
       }

    fclose(view);
    if (test==0)
        {  
		  system("cls");
          printf("\nNO RECORDS!!\n");
		}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            exit(1);
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d",&add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   
		    test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
             {
				printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,upd.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
             }
            else if(choice==2)
             {
                printf("Enter the new phone number:");
                scanf("%s",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
             }
        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   
		    system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
            printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==1)
				menu();
            else if (main_exit==2)
                exit(1);
            else if(main_exit==0)
                edit();
            else
             {
				printf("\nInvalid!\a");
                goto edit_invalid;
			 }
        }
    else
     {
	  printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==1)
        menu();
      else
        exit(1);
     }
}

void transact(void)
{   
    int choice,test=0,pin;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
     {
        if(add.acc_no==transaction.acc_no)
          {
		   test=1;
            if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
             {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
             }
            x:
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d",&choice);
            if (choice==1)
             {
                printf("Enter the amount you want to deposit:$ ");
                scanf("%f",&transaction.amt);
                add.amt+=transaction.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\nDeposited successfully!");
             }
            else if(choice==2)
             {
                printf("Enter The Pin........");
                scanf("%d",&check.pin);
				if(add.pin==check.pin)
				 {
                    printf("Enter the amount you want to withdraw:$ ");
                  	scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
               	 }
               	else
				 {
	               printf("Wrong pin entered!");     			
				 }    
             }
            else
			 {
				printf("Wrong Choice");
				goto x;
			 } 

          }
        else
         {
          fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
         }
     }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
    {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
     else if (main_exit==1)
        menu();
     else if (main_exit==2)
        exit(1);
     else
      {
        printf("\nInvalid!");
        goto transact_invalid;
      }
    }
   else
    {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            exit(1);
    }
}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d",&add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
         {
			test++;
            printf("\nRecord deleted successfully!\n");
         }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    exit(1);
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            exit(1);
        }
}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   
			    system("cls");
                test=1;
                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nnationality:%s \nPhone number:%.0s \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("You will get $%.2f as interest on %d/%d/%d\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                        sleep(10);
						goto see_invalid;                    
					}
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("You will get $%.2f as interest on %d/%d/%d\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
						sleep(10);
						goto see_invalid;
                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("You will get $%.2f as interest on %d/%d/%d\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
						sleep(10);
						goto see_invalid;
                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("You will get $.%.2f as interest on %d of every month\n",intrst,add.deposit.day);
						sleep(10);
						goto see_invalid;
                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("You will get no interest\a\a\n");
						sleep(10);
						goto see_invalid;
                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:\n");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d %f %d",&add.acc_no,&add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   
				system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nnationality No:%s \nPhone number:%.0s \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("You will get $%.2f as interest on %d/%d/%d\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                		sleep(10);
						goto see_invalid;    
					}
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("You will get $%.2f as interest on %d/%d/%d\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
     					sleep(10);
						goto see_invalid;
                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("You will get $%.2f as interest on %d/%d/%d\n",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
						sleep(10);
						goto see_invalid;
                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("You will get $%.2f as interest on %d of every month\n",intrst,add.deposit.day);
						sleep(10);
						goto see_invalid;
                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("You will get no interest\a\a\n");
						sleep(10);
						goto see_invalid;
                     }

            }
        }
    }
    else
    {
    	printf("Wrong choice! choose again\n");
    	see();
	}

    fclose(ptr);
     if(test!=1)
        {   
		 	system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    exit(1);
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;
					}
        }
    else
     {
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
	 }
    if (main_exit==1)
     {
        system("cls");
        menu();
     }

    else
     {
      system("cls");
      exit(1);
     }

}

void Loan(void)
 { 
	int i,j,loan_amt,test=0;
	FILE *ptr,*newrec;
	ptr=fopen("record.dat","r");
	newrec=fopen("loan.dat","a");
	printf("\nWant a Loan ? , We're here for you...\n");
	printf("Select 1 for Home Loan @ 10%\n");
    printf("Select 2 for Car Loan @ 10%\n");
    printf("Select 3 for Education Loan @ 8%\n");
    printf("Select 4 for Personal Loan @ 12%\n");
    scanf("%d",&i);
    switch(i)
     {
    	case 1:
    	printf("\n Applying for home loan has never been easier!\n");
    		printf("Enter your account number\n");
    		scanf("%d",&check.acc_no);
		while (fscanf(ptr,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
         {
    		 if(check.acc_no==add.acc_no)
    		 { 
			  test=1;
			  printf("Enter Your PIN\n");
    		  scanf("%d",&check.pin);
    		  if(check.pin==add.pin)
    		  {
    		 	printf("How much loan do you require?\n");
    		 	scanf("%d",&loan_amt);
    		 	printf("Now we will check for your account information and see if you are allowed to have this much loan\n");
    		 	sleep(2);
				 if(add.amt>=(loan_amt/10.0))
    		 	 {
    		 	 	printf("You are Eligible to apply for this loan!\n");
    		 	 	printf("Do you want to take the loan?\nPress 1 for Yes and 2 for No\n");
    		 	 	scanf("%d",&j);
					switch(j)
					  {
					   case 1:
					   		printf("Your loan has been approved !!\n Your rate of interest is 10 percent annually\nKindly Deposit your aadhar card copy and bank statement at front desk and collect loan amount from money counter");
					    	add.loanamt+=loan_amt;
					    	add.rate=10;
							fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
							break;
					   case 2:
					   		printf("Loan cancelled by user");
						    break;	
					  }
    		 	 	
				 }
				 else
				  {
				  	printf("Your current account balance is not enough to apply for a loan of  the given amount\n");
				  }
			    Loan1_invalid:
              	printf("\nEnter 0 to apply again,1 to return to main menu and 2 to exit:\n");
              	scanf("%d",&main_exit);
              	system("cls");
 				if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    exit(1);
                else if(main_exit==0)
                    Loan();
                else
                 {
				  printf("\nInvalid!\a");
                  goto Loan1_invalid;
				 }
			 }
			 else
			  {
			  	printf("Wrong PIN Entered\n");
			  }
			  break;
    	   }
         }
        if(test!=1)
         {
          printf("\n\nRecord not found!!");
         }
        goto Loan1_invalid;
        break;	
    	case 2:
    	printf("Applying for car loan has never been easier!\n");
    		printf("Enter your account number\n");
    		scanf("%d",&check.acc_no);
		while (fscanf(ptr,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
         {
			 if(check.acc_no==add.acc_no)
    		 {
    		 	test=1;
    		  printf("Enter Your PIN\n");
    		  scanf("%d",&check.pin);
    		  if(add.pin==check.pin)
    		  {
    		 	printf("How much loan do you require?\n");
    		 	scanf("%d",&loan_amt);
    		 	printf("Now we will check for your account information and see if you are allowed to have this much loan\n");
    		 	sleep(2);
				 if(add.amt>=(loan_amt/10.0))
    		 	 {
    		 	 	printf("You are Eligible to apply for this loan!\n");
    		 	 	printf("Do you want to take the loan? press 1 for Yes and 2 for No\n");
    		 	 	scanf("%d",&j);
					switch(j)
					  {
					   case 1:
					   		printf("Your loan has been approved !!\n Your rate of interest is 10 percent annually\nKindly Deposit your aadhar card copy and bank statement at front desk and collect loan amount from money counter\n");
					    	add.loanamt+=loan_amt;
					    	add.rate=10;
							fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
							break;
					   case 2:
					   		printf("Loan cancelled by user\n");
						    break;	
					  }
    		 	 	
				 }
				  else
				  {
				  	printf("Your current account balance is not enough to apply for a loan of  the given amount\n");
				  }
				Loan2_invalid:
              	printf("\nEnter 0 to apply again,1 to return to main menu and 2 to exit:\n");
              	scanf("%d",&main_exit);
 				system("cls");
				 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    exit(1);
                else if(main_exit==0)
                    Loan();
                else
                 {
				  printf("\nInvalid!\a");
                  goto Loan2_invalid;
				 }  
			  }
			 else
			  {
			  	printf("Wrong PIN Entered");
			  }
    		break;
    	   }
         }
        if(test!=1)
         {
          printf("\n\nRecord not found!!");
         }  
        goto Loan2_invalid;
        break;
		case 3:
    		printf("Applying for Education loan has never been easier!\n");
    		printf("Enter your account number\n");
    		scanf("%d",&check.acc_no);
		while (fscanf(ptr,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
         {
    		 if(check.acc_no==add.acc_no)
    		 {
    		 	test=1;
    		  printf("Enter Your PIN\n");
    		  scanf("%d",&check.pin);
    		  if(add.pin==check.pin)
    		  {
    		 	printf("How much loan do you require?\n");
    		 	scanf("%d",&loan_amt);
    		 	printf("Now we will check for your account information and see if you are allowed to have this much loan\n");
    		 	sleep(2);
				 if(add.amt>=(loan_amt/10.0))
    		 	 {
    		 	 	printf("You are Eligible to apply for this loan!\n");
    		 	 	printf("Do you want to take the loan? press 1 for Yes and 2 for No\n");
    		 	 	scanf("%d",&j);
					switch(j)
					  {
					   case 1:
					   		printf("Your loan has been approved !!\n Your rate of interest is 8 percent annually\nKindly Deposit your aadhar card copy and bank statement at front desk and collect loan amount from money counter\n");
					    	add.loanamt+=loan_amt;
					    	add.rate=10;
							fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
							break;
					   case 2:
					   		printf("Loan cancelled by user\n");
						    break;	
					  }
    		 	 	
				    }
				  else
				  {
				  	printf("Your current account balance is not enough to apply for a loan of the given amount\n");
				  }
				  Loan3_invalid:
              	printf("\nEnter 0 to apply again,1 to return to main menu and 2 to exit:\n");
              	scanf("%d",&main_exit);
 				system("cls");
				 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    exit(1);
                else if(main_exit==0)
                    Loan();
                else
                 {
				  printf("\nInvalid!\a");
                  goto Loan3_invalid;
				 }
			}
			 else
			  {
			  	printf("Wrong PIN Entered");
			  }
    		break;
    		}
         }
        if(test!=1)
         {
          printf("\n\nRecord not found!!");
         }
		goto Loan3_invalid;
         break;
		case 4:
    		printf("Applying for Personal loan has never been easier!\n");
    		printf("Enter your account number\n");
    		scanf("%d",&check.acc_no);
		while (fscanf(ptr,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
         {
         	if(check.acc_no==add.acc_no)
    		 {
    		 	test=1;
    		printf("Enter Your PIN\n");
    		scanf("%d",&check.pin);
    		if(add.pin==check.pin)
    		 {
    		 	printf("How much loan do you require?\n");
    		 	scanf("%d",&loan_amt);
    		 	printf("Now we will check for your account information and see if you are allowed to have this much loan\n");
    		 	sleep(2);
				 if(add.amt>=(loan_amt/10.0))
    		 	 {
    		 	 	printf("You are Eligible to apply for this loan!\n");
    		 	 	printf("Do you want to take the loan? press 1 for Yes and 2 for No\n");
    		 	 	scanf("%d",&j);
					switch(j)
					  {
					   case 1:
					   		printf("Your loan has been approved !!\n Your rate of interest is 12 percent annually\nKindly Deposit your aadhar card copy and bank statement at front desk and collect loan amount from money counter\n");
					    	add.loanamt+=loan_amt;
					    	add.rate=10;
							fprintf(newrec,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.pin,add.address,add.nationality,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
							break;
					   case 2:
					   		printf("Loan cancelled by user\n");
						    break;	
					  }
    		 	 	
				 }
				  else
				  {
				  	printf("Your current account balance is not enough to apply for a loan of  the given amount\n");
				  }
				  Loan4_invalid:
              	printf("\nEnter 0 to apply again,1 to return to main menu and 2 to exit:\n");
              	scanf("%d",&main_exit);
 				system("cls");
				 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    exit(1);
                else if(main_exit==0)
                    Loan();
                else
                 {
				  printf("\nInvalid!\a");
                  goto Loan4_invalid;
				 }
			 }
			 else
			  {
			  	printf("Wrong PIN Entered\n");
			  }
    		break;
    		}
         }
        if(test!=1)
         {
          printf("\n\nRecord not found!!");
         }
		goto Loan4_invalid;
    	 break;
		default:
		 {
    		printf("Wrong choice entered\n");
			Loan5_invalid:
              	printf("\nEnter 0 to apply again,1 to return to main menu and 2 to exit:\n");
              	scanf("%d",&main_exit);
 				system("cls");
				 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    exit(1);
                else if(main_exit==0)
                    Loan();
                else
                 {
				  printf("\nInvalid!\a");
                  goto Loan5_invalid;
				 }
			break;
		 }
	 }
	 fclose(ptr);
	 fclose(newrec);
 }

void debitcard(void)
{
	FILE *debit;
	int test=0;
	debit=fopen("record.dat","r");
    printf("Enter the Account no. of DEBIT CARD applicant:\n");
    scanf("%d",&check.acc_no);
	while (fscanf(debit,"%d %s %d/%d/%d %d %d %s %s %s %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,&add.pin,&add.address,&add.nationality,&add.phone,&add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
         {
    	  if(check.acc_no==add.acc_no)
    	   { 
			test=1;
			printf("Enter Your PIN\n");
    		scanf("%d",&check.pin);
    	    if(check.pin==add.pin)
    		 {
    		  printf("Your request have been accepted,contact Helpdesk for PIN when you recieve the DEBIT CARD.\n");
	         }
	        else
	         {
	      	  printf("Wrong pin entered\n");
		      goto debit_invalid;
			 }
           }
		}
        if(test==0)
		   {
			printf("Record not found!!\n");
		   }
	     debit_invalid:
              	printf("\nEnter 0 to apply again,1 to return to main menu and 2 to exit:\n");
              	scanf("%d",&main_exit);
 				system("cls");
				 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    exit(1);
                else if(main_exit==0)
                    debitcard();
                else
                 {
				  printf("\nInvalid!\a");
                  goto debit_invalid;
				 }	   
		   
	     fclose(debit);
}



void menu(void)
{
   int choice;
    system("cls");
    system("color 5");
    printf("\n\n\t\t\tR-MARS Banking Solutions");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Modify Account Details\n\t\t3.Make your transactions\n\t\t4.Account's Enquiry\n\t\t5.Account Closure\n\t\t6.View customer's list\n\t\t7.Apply for Loan\n\t\t8.Apply for Debitcard\n\t\t9.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:
		new_acc();
        break;
        case 2:
		edit();
        break;
        case 3:
		transact();
        break;
        case 4:
		see();
        break;
        case 5:
		erase();
        break;
        case 6:
		view_list();
        break;
        case 7:
		Loan();
        break;
		case 8:
		debitcard();
        break;
        case 9:
		exit(1);
        break;
    }
}

int main()
{
    menu();
	return 0;
}
