#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for clear screen
#include <conio.h>  // for getch() and  go to functions.
#include <math.h>   // for all the math functions

#define PIs 180
#define PI 3.14159265

int n, z = 0, Enter = 0;

// Function declarations
void entry();
void login();
void reg();
int passtry();
void simple_calculator();
void scientific_calculator();
void conversion_calculator();
void currency();

int main()
{
    system("cls"); // Clears the console screen
    system("color b"); // Sets the text and background color
    if (Enter == 0)
    {
        entry(); // Calls the entry function if it's the first time running
    }
    int n;
    int s_number,c_number;    
    while (1)
    {
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tMenu :");
        printf("\n\n\t\t\t\t\t> 1.Simple Calculator\n\t\t\t\t\t> 2.Scientific Calculator\n\t\t\t\t\t> 3.Currency Conversion\n\t\t\t\t\t> 4.Units Conversion\n\t\t\t\t\t> 5.Exit");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &n); // Takes user input for choice
        switch (n)
        {
        case 1:
            system("cls");
            simple_calculator(); // Calls the simple calculator function
            break;
        case 2:
            system("cls");
            scientific_calculator(); // Calls the scientific calculator function
            break;
        case 3:
            system("cls");
            currency(); // Calls the currency conversion function
            break;
        case 4:
            system("cls");
            conversion_calculator(); // Calls the units conversion function
            break;
        case 5:
            system("cls");
            printf("\n\t\t-----------------------------------------------------------------------");
            printf("\n\n\t\t\t\t\t\t THANK YOU \n\n");
            printf("\n\t\t-----------------------------------------------------------------------");
            getch();
            system("cls");
            exit(0); // Exits the program
            break;
        default:
            printf("\n\t\t---------------------------------------------------------------------");
            printf("\n\n\t\t\t\t\tEnter Valid Choice !");
            printf("\n\t\t---------------------------------------------------------------------");
            break;
        }
        printf(" <-Back ");
        getch(); // Waits for a key press
        system("cls");
    }
}

// Entry function
void entry()
{
    system("cls");
    printf("\n\t\t\t===========================================================");
    printf("\n\n\n\n\n\t\t\t\t! Welcome To Our Multi-Feature Calculating System !\n");
    printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
    printf("\n\t\t\t===========================================================");
    getch(); // Waits for a key press
    system("cls");
XY:
    printf("\n\n\t\t====================================================================");
    printf("\n\n\t\t\t1. LOGIN\t\t2. REGISTER\t\t3. EXIT");
    printf("\n\n\t\t====================================================================");
    printf("\n\n\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d", &n); // Takes user choice
    switch (n)
    {
    case 1:
        system("cls");
        login(); // Calls the login function
        break;
    case 2:
        system("cls");
        reg(); // Calls the register function
        break;
    case 3:
        system("cls");
        printf("\n\n\n");
        printf("\n\t\t-----------------------------------------------------------------------");
        printf("\n\t\t\t          __ __      _   _    |          _                          ");
        printf("\n\t\t\t            |   |_| |_| | \\ | |/    \\ / | | | |                     ");
        printf("\n\t\t\t            |   | | | | |  \\| |\\_    |  |_| |_|                    ");
        printf("\n\t\t-----------------------------------------------------------------------");
        exit(0); // Exits the program
    default:
        printf("\n\n\t\t====================================================================");
        printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        printf("\n\n\t\t====================================================================");
        getch();
        system("cls");
        goto XY; // Jumps to the label XY to re-enter the choice
    }

    exit(0); // Exits the program
    return;
}

// Login function
void login()
{
    system("cls");
    FILE *fp;
    char filename[] = "arpass.txt";
    char line[10000];
    char name[200], pass[200];
    char i[] = ":", c;
    int cnt = 0, z = 0;

    printf("\n\t\t---------------------------------------------------------------------");
    printf("\n\t\t\t            LOGIN PAGE                    ");
    printf("\n\t\t---------------------------------------------------------------------");
    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%s", &name); // Takes username input
    printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
    while ((c = getch()) != 13) // Takes password input while hiding it , here 13 is ascii value of new line.
    {
        pass[z++] = c;
        printf("%c", '*');
    }
    pass[z] = '\0'; // Null-terminates the password string

    int q = strlen(pass);
    strcat(name, i); // Concatenates ':' to the username
    fp = fopen(filename, "r"); // Opens the file in read mode

    if (!fp)
    {
        perror("could not find the file"); // Prints an error message if file not found
    }
    int t = 0, r = 0;
    char a;

    while ((a = fgetc(fp)) != EOF) // Reads characters from the file until the end
    {
        if (name[r] == a) // Compares username characters with characters from file
        {
            t++;
            r++;
            if (t == strlen(name))
            {
                t = 0;
                r = 0;
                while ((a = fgetc(fp)) != EOF) // Checks for password match
                {
                    if (a != '\n')   //compares till end of line
                    {
                        if (pass[r] == a)
                        {
                            t++;
                            r++;
                            if (t == strlen(pass))
                            {
                                system("cls");
                                printf("\n\n\n\t\t\t===========================================================");
                                printf("\n\n\t\t\t\t\t  Successfully Logged !\n");
                                printf("\n\t\t\t===========================================================");
                                fclose(fp); // Closes the file
                                getch();
                                Enter = 1;
                                main(); // Calls the main function
                            }
                        }
                    }
                }
                system("cls");
                printf("\n\t\t\t===========================================================");
                printf("\n\n\t\t\t\t\tPassword Is Wrong ,Re-enter!");
                printf("\n\n\t\t\t===========================================================");
                cnt++;
                getch();
                passtry(name); // Calls the password try function
            }
        }
    }

    if (cnt == 0)   //cnt did not get incremented indicating user does not exist.
    {
        system("cls");
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tUserName doesn't Exists!!");
        printf("\n\n\t\t\t===========================================================");
        getch();
        fclose(fp); // Closes the file
        system("cls");
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tDo You Want to register?");
        printf("\n\n\t\t\t\t\t> PRESS 1 FOR YES\n\t\t\t\t\t> PRESS 2 FOR NO");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\t\t\t=> ");
        scanf("%d", &z);
        switch (z)
        {
        case 1:
            system("cls");
            reg(); // Calls the register function
            break;
        case 2:
            system("cls");
            printf("\n\n\n");
            printf("\n\t\t-----------------------------------------------------------------------");
            printf("\n\t\t\t          THANK YOU");            
            printf("\n\n\n\n\t\t\tPress Enter to EXIT...!!");
            printf("\n\t\t-----------------------------------------------------------------------");
            getch();
            exit(0); // Exits the program
        }
    }

    return;
}

// Password try function
int passtry(char *name)
{
    FILE *fp;
    char filename[] = "arpass.txt";
    char line[10000];
    char pass[200];
    char c;
    int cnt = 0, z = 0;
    system("cls");
    printf("\n\t\t---------------------------------------------------------------------");
    printf("\n\t\t\t            LOGIN PAGE                    ");
    printf("\n\t\t---------------------------------------------------------------------");
    printf("\n\n\t\t\t\t  ENTER USERNAME: %s", name);
    printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
    while ((c = getch()) != 13)
    {
        pass[z++] = c;
        printf("%c", '*');
    }
    pass[z] = '\0';

    fp = fopen(filename, "r");

    if (!fp)
    {
        perror("could not find the file");
    }

    int t = 0, r = 0;
    char a;

    while ((a = fgetc(fp)) != EOF)
    {
        if (name[r] == a)
        {
            t++;
            r++;
            if (t == strlen(name))
            {
                t = 0;
                r = 0;
                while ((a = fgetc(fp)) != EOF)
                {
                    if (a != '\n')
                    {
                        if (pass[r] == a)
                        {
                            t++;
                            r++;
                            if (t == strlen(pass))
                            {
                                system("cls");
                                printf("\n\n\n\t\t\t===========================================================");
                                printf("\n\n\t\t\t\t\t  Successfully Logged !\n");
                                printf("\n\t\t\t===========================================================");
                                fclose(fp);
                                getch();
                                Enter = 1;
                                main();
                            }
                        }
                    }
                }
                system("cls");
                printf("\n\t\t\t===========================================================");
                printf("\n\n\t\t\t\t\tPassword Is Wrong ,Re-enter!");
                printf("\n\n\t\t\t===========================================================");
                cnt++;
                getch();
                passtry(name);
            }
        }
    }
    return 0;
}

// Registration function
void reg()
{
    system("cls");
    char filename[] = "arpass.txt";
    char line[10000];
    char pass[30];

    FILE *fp;
    int i = 0, n;
    char c, checker[30];
    int z = 0;
    char cl[] = ":";
    fp = fopen(filename, "ab+"); // Opens the file in append mode and creates a new file if not present already.
    printf("\n\t\t---------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\tWELCOME TO REGISTER ZONE\n");
    printf("\n\t\t---------------------------------------------------------------------");    
    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%s", checker);
    strcat(checker, cl);
    while (fgets(line, 10000, fp) != NULL) // Reads each line in the file
    {
        if (strstr(line, checker)) // Checks if username already exists
        {
            system("cls");
            printf("\n\t\t\t===============================================================\n\n");
            printf("\t\t\t\t\t       UserName Already Exits!\n");
            printf("\n\t\t\t===============================================================");
            getch();
            system("cls");
            reg(); // Calls the register function again
        }
    }
    printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
    while ((c = getch()) != 13)
    {
        pass[z++] = c;
        printf("%c", '*');
    }
    pass[z] = '\0'; // Null-terminates the password string
    strcat(checker, pass);
    fprintf(fp, "\n");
    fprintf(fp, checker); // Writes the username and password to the file
    getch();
    fclose(fp); // Closes the file
    system("cls");
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tYou are successfully registered");
    printf("\n\n\t\t\t\t\tTry login your account??");
    printf("\n\n\t\t\t\t\t> PRESS 1 FOR YES\n\t\t\t\t\t> PRESS 2 FOR NO");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\t\t\t=> ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        system("cls");
        login(); // Calls the login function
        break;
    case 2:
        system("cls");
        printf("\n\n\n");
        printf("\n\t\t-----------------------------------------------------------------------");
        printf("\n\t\t\t          THANK YOU");            
        printf("\n\n\n\n\t\t\tPress Enter to EXIT...!!");
        printf("\n\t\t-----------------------------------------------------------------------");
        getch();
        exit(0); // Exits the program
    }

}

// Calculator functions and relevant codes
// Calculator Feature Code

void currency();
void energy();
void length();
void mass();
void matrix_addition();
void matrix_multiply();
void matrix_substraction();
void simple_calculator();
void speed();
void temperature();
void timec();
void trigonometric_function();
void sine();
void cosine();
void tangent();

// Function to handle simple calculator operations
void simple_calculator()    
{
    // Displaying the menu options
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tSimple Calculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Calculate Addition");
    printf("\n\t\t\t\t\t> 2.Calculate Subtraction");
    printf("\n\t\t\t\t\t> 3.Calculate Multiply");
    printf("\n\t\t\t\t\t> 4.Calculate Divided");
    printf("\n\t\t\t\t\t> 5.Calculate Power");
    printf("\n\t\t\t\t\t> 6.Calculate Root");
    printf("\n\t\t\t\t\t> 7.Going To Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    
    // Variables for user input and calculations
    int simple_number;
    int a, b, result;
    double number, num, p;
    
    // Taking user input for choice
    scanf("%d", &simple_number);
    
    // Loop for handling calculator operations based on user choice
    while (simple_number > 0 && simple_number < 9)
    {
        system("cls"); // Clearing the screen
        
        // Switch case for different operations
        switch (simple_number)
        {
        case 1:
            // Addition operation
            printf("\nEnter the first value  : ");
            scanf("%d", &a);
            printf("Enter the Second value : ");
            scanf("%d", &b);
            result = a + b;
            printf("Addition = %d\n\n", result);
            break;
        case 2:
            // Subtraction operation
            printf("\nEnter the first value  : ");
            scanf("%d", &a);
            printf("Enter the Second value : ");
            scanf("%d", &b);
            result = a - b;
            printf("Subtraction = %d\n\n", result);
            break;
        case 3:
            // Multiplication operation
            printf("\nEnter the first value  : ");
            scanf("%d", &a);
            printf("Enter the Second value : ");
            scanf("%d", &b);
            result = a * b;
            printf("Multiply = %d\n\n", result);
            break;
        case 4:
            // Division operation
            printf("\nEnter the first value  : ");
            scanf("%d", &a);
            printf("Enter the Second value : ");
            scanf("%d", &b);
            float result = (float)a / (float)b;
            printf("Divided = %.3f\n\n", result);
            break;
        case 5:
            // Power calculation
            printf("\nEnter The numbers and Power\n");
            printf("Enter The Number : ");
            scanf("%lf", &number);
            printf("Enter The Power : ");
            scanf("%lf", &num);
            p = pow(number, num);
            printf("Result = %.2lf\n\n", p);
            break;
        case 6:
            // Square root calculation
            printf("\nTo Root Enter The number\n");
            printf("Enter The Number : ");
            scanf("%lf", &number);
            p = sqrt(number);
            printf("Result = %.2lf\n\n", p);
            break;
        case 7:
            // Returning to the main menu
            main();
            break;
        case 8:
            // Exiting the program
            exit(0);
            break;
        default:
            break;
        }
        
        // Displaying the menu options again
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tSimple Calculator Menu :");
        printf("\n\n\t\t\t\t\t> 1.Calculate Addition");
        printf("\n\t\t\t\t\t> 2.Calculate Subtraction");
        printf("\n\t\t\t\t\t> 3.Calculate Multiply");
        printf("\n\t\t\t\t\t> 4.Calculate Divided");
        printf("\n\t\t\t\t\t> 5.Calculate Power");
        printf("\n\t\t\t\t\t> 6.Calculate Root");
        printf("\n\t\t\t\t\t> 7.Going To Menu");
        printf("\n\t\t\t\t\t> 8.Exit");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &simple_number);
        
    }
    return;
}

// Function to handle scientific calculator operations
void scientific_calculator(){
    // Displaying the menu options
    int s_number;
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tScientific Calculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Trigonometric Function\n\t\t\t\t\t> 2.Matrix Addition\n\t\t\t\t\t> 3.Matrix Subtraction\n\t\t\t\t\t> 4.Matrix Multiply\n\t\t\t\t\t> 5.back To Calculator Menu\n\t\t\t\t\t> 7.Exit the Program");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &s_number);
       
    // Loop for handling scientific calculator operations based on user choice
    while (s_number > 0 && s_number <= 8)
    {
        system("cls"); // Clearing the screen
        
        // Switch case for different operations
        switch (s_number)
        {
        case 1:
            // Function to perform trigonometric functions
            trigonometric_function();
            break;
        case 2:
            // Function to perform matrix addition
            matrix_addition();
            break;
        case 3:
            // Function to perform matrix subtraction
            matrix_substraction();
            break;
        case 4:
            // Function to perform matrix multiplication
            matrix_multiply();
            break;
        case 5:
            // Returning to the main menu
            main();
            break;
        case 6:
            // Exiting the program
            exit(0);
            break;
        default:
            break;
        }
        // Displaying the menu options again
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tScientific Calculator Menu :");
        printf("\n\n\t\t\t\t\t> 1.Trigonometric Function\n\t\t\t\t\t> 2.Matrix Addition\n\t\t\t\t\t> 3.Matrix Subtraction\n\t\t\t\t\t> 4.Matrix Multiply\n\t\t\t\t\t> 5.back To Calculator Menu\n\t\t\t\t\t> 6.Exit the Program");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &s_number);
    }
}

//Function to handle the conversion feature of the multi feature system.
void conversion_calculator(){
    int c_number;
    printf("\n\t\t\t===========================================================");  
    printf("\n\n\t\t\t\t\tConverter Calculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Convert Length");
    printf("\n\t\t\t\t\t> 2.Convert Mass");
    printf("\n\t\t\t\t\t> 3.Convert Temperature");
    printf("\n\t\t\t\t\t> 4.Convert Speed");
    printf("\n\t\t\t\t\t> 5.Convert Time");
    printf("\n\t\t\t\t\t> 6.Convert Energy");
    printf("\n\t\t\t\t\t> 7.back To Calculator Menu");
    printf("\n\t\t\t\t\t> 8.Exit the Program");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &c_number);
    while(c_number > 0 && c_number <= 10){          //Loop that executes according to user choice.
        system("cls");
        switch(c_number){
            case 1:
                length();
                break;
            case 2:
                mass();
                break;
            case 3:
                temperature();
                break;
            case 4:
                speed();
                break;
            case 5:
                timec();
                break;
            case 6:
                energy();
                break;
            case 7:
                main();
                break;
            case 8:
                exit(0);
                break;
            default:
                break;
        }
        printf("\n\t\t\t===========================================================");  
        printf("\n\n\t\t\t\t\tConverter Calculator Menu :");
        printf("\n\n\t\t\t\t\t> 1.Convert Length");
        printf("\n\t\t\t\t\t> 2.Convert Mass");
        printf("\n\t\t\t\t\t> 3.Convert Temperature");
        printf("\n\t\t\t\t\t> 4.Convert Speed");
        printf("\n\t\t\t\t\t> 5.Convert Time");
        printf("\n\t\t\t\t\t> 6.Convert Energy");
        printf("\n\t\t\t\t\t> 7.back To Calculator Menu");
        printf("\n\t\t\t\t\t> 8.Exit the Program");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &c_number);
        system("cls");
    }
}

//Function to handle trigonomtric part of the scientific calculator.
void trigonometric_function()
{
    int trigonometric_number;
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tTrigonometric Calculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Find the value of sine");
    printf("\n\t\t\t\t\t> 2.Find the value of cos");
    printf("\n\t\t\t\t\t> 3.Find the value of tan");
    printf("\n\t\t\t\t\t> 4.Going To Menu");
    printf("\n\t\t\t\t\t> 5.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &trigonometric_number);
    while (trigonometric_number >= 1 && trigonometric_number <= 4)      //Loop that executes according to user choice.
    {
        system("cls");
        switch (trigonometric_number)
        {
        case 1:
            sine();
            break;
        case 2:
            cosine();
            break;
        case 3:
            tangent();
            break;
        case 4:
            main();
            break;
            system("cls");
        case 5:
            exit(0);
            break;
        default:
            break;
        }
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tTrigonometric Calculator Menu :");
        printf("\n\n\t\t\t\t\t> 1.Find the value of sine");
        printf("\n\t\t\t\t\t> 2.Find the value of cos");
        printf("\n\t\t\t\t\t> 3.Find the value of tan");
        printf("\n\t\t\t\t\t> 4.Going To Menu");
        printf("\n\t\t\t\t\t> 5.Exit");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &trigonometric_number);
    }
}
void sine()
{
    system("cls");
    int k;
    double input, output;
    printf("\n\t\t\t==========================================================");           //Choice of Taking input in radians or degrees .
    printf("\n\t\t\tDo You Want Input Value in Radian Or Degre?\n\t\t\t> 1.Radian\n\t\t\t> 2.Degree");
    printf("\n\n\t\t\t===========================================================");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &k);
    system("cls");
    
    if (k == 1)
    {
        printf("\n\n\n\t\t\tEnter the Radian Value for sin : "); //taking input in radians and printing the sine value
        scanf("%lf", &input);  
        output = sin(input);
        printf("\n\t\t\tsin : %.3lf\n\n\n\n", output);
    }
    else
    {
        printf("\n\n\n\t\t\tEnter the value in degrees for sin : ");
        scanf("%lf", &input);
        output = sin(input * PI / 180);                             //converting the angle to radians and then executing the sin to print the output.             
        printf("\n\t\t\tsin of %.0lf Degree is %.3lf\n\n\n\n", input, output);
        return;
    }
}
void cosine()
{
    system("cls");
    int k;
    double input, output;
    printf("\n\t\t\t===========================================================");
    printf("\n\t\t\tDo You Want Input Value in Radian Or Degre?\n\t\t\t> 1.Radian\n\t\t\t> 2.Degree");
    printf("\n\n\t\t\t===========================================================");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &k);
    system("cls");
    if (k == 1)
    {
        printf("\n\n\t\t\tEnter the Radian Value for cos : ");   //taking input in radians and printing the cosine value      
        scanf("%lf", &input);
        output = cos(input);
        printf("\n\t\t\tcos : %.3lf\n\n\n\n", output);
    }
    else
    {
        printf("\n\n\t\t\tEnter the value of cos : ");
        scanf("%lf", &input);                                   //taking input in degrees and printing the cosine value
        output = cos(input * PI / 180);                         //converting the angle to radians and then executing the cosine to print the output. 
        printf("\n\t\t\tcos of %.0lf Degree is %.3lf\n\n\n\n", input, output);
        return;
    }
}
void tangent()
{
    system("cls");
    int k;
    double input, output;
    printf("\n\t\t\t===========================================================");
    printf("\n\t\t\tDo You Want Input Value in Radian Or Degree?\n\t\t\t> 1.Radian\n\t\t\t> 2.Degree");
    printf("\n\n\t\t\t===========================================================");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &k);
    system("cls");
    if (k == 1)
    {
        printf("\n\n\t\t\tEnter the Radian Value for tan : ");          //taking input in radians and printing the tan value .
        scanf("%lf", &input);
        output = tan(input * PI / 180);
        printf("\n\t\t\tsin : %.3lf\n\n\n\n", output);
    }
    else
    {
        printf("\n\n\n\t\t\tEnter the value in degree for tan : ");
        scanf("%lf", &input);                                             //taking input in degrees and printing the tan value .
        output = tan(input * PI / 180);                                  //converting the angle to radians and then executing the tan to print the output
        printf("\n\t\t\ttan of %.0lf Degree is %.3lf\n\n\n\n", input, output);
        return;
    }
}
//addition of matrix
void matrix_addition()
{
    int row_size, column_size;
    printf("\nInsert Row Size    : ");  
    scanf("%d", &row_size);                 //user input of row size 
    printf("Insert Column Size : ");
    scanf("%d", &column_size);                                  //user input of column size
    int array1[row_size][column_size], array2[row_size][column_size];       // 2d arrays defining 
    printf("Insert the %d * %d Matrix A :\n", row_size, column_size);
    int i, j;
    for (i = 0; i < row_size; i++) //  taking user input of matrix A
    {
        for (j = 0; j < column_size; j++)
        {
            scanf("%d", &array1[i][j]);
        }
    }
    printf("Insert the %d * %d Matrix B :\n", row_size, column_size);           // asking for input of entries from user.
    int k, l;
    for (k = 0; k < row_size; k++)
    {
        for (l = 0; l < column_size; l++)
        {
            scanf("%d", &array2[k][l]);
        }
    }
    printf("Here Matrix A + B is : \n"); 
    for (i = 0; i < row_size; i++)
    {
        for (j = 0; j < column_size; j++)           //summation using loop and then printing the summation.
        {  
            printf("%d ", array1[i][j]); 
            printf("+");
            printf(" %d", array2[i][j]);
            printf("\t");
        }

        printf("\n");
    }
    
    printf("Summation of A , B Matrix is : \n");         //printing of addition of the matrices.
    for (i = 0; i < row_size; i++)
    {
        int sum = 0;
        for (j = 0; j < column_size; j++)
        {
            sum = array1[i][j] + array2[i][j];
            printf("%d\t", sum);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void matrix_substraction()      //function for performing the matrix substraction.
{
    int row_size, column_size;       //defining row and column variables
    printf("\nInsert Row Size    : ");
    scanf("%d", &row_size);
    printf("Insert Column Size : ");
    scanf("%d", &column_size);
    int array1[row_size][column_size], array2[row_size][column_size];
    printf("Insert the %d * %d Matrix A :\n", row_size, column_size); 
    int i, j;
    for (i = 0; i < row_size; i++)          // taking inputs for matrix A
    {
        for (j = 0; j < column_size; j++)
        {
            scanf("%d", &array1[i][j]);
        }
    }
    printf("Insert the %d * %d Matrix B :\n", row_size, column_size);       // taking inputs for matrix B
    int k, l;
    for (k = 0; k < row_size; k++)
    {
        for (l = 0; l < column_size; l++)
        {
            scanf("%d", &array2[k][l]);
        }
    }
    printf("Here Matrix A - B\n", row_size, column_size);
    for (i = 0; i < row_size; i++)
    {
        for (j = 0; j < column_size; j++)
        {
            printf("%d ", array1[i][j]);
            printf("-");
            printf(" %d", array2[i][j]);
            printf("\t");
        }

        printf("\n");
    }
    printf("SubsTraction of A , B Matrix is : \n");     // printing subtraction of matrix in the matrix form.
    for (i = 0; i < row_size; i++)
    {
        int sum = 0;
        for (j = 0; j < column_size; j++)
        {
            sum = array1[i][j] - array2[i][j];
            printf("%d\t", sum);
        }
        printf("\n");
    }
    printf("\n");

    return;
}

void matrix_multiply()          //function for performing matrix multiplication.
{
    system("cls");
    //defining three matrix and some variables 
    int a[10][10], b[10][10], mult[10][10], a_row_size, a_column_size, b_row_size, b_column_size, i, j, k;
    int row_size, column_size;
    printf("Enter 1st Matrix Rows and Column : ");
    scanf("%d %d", &a_row_size, &a_column_size); // providing info for rows and columns.
    printf("Enter 2nd Matrix Rows and Column : ");
    scanf("%d %d", &b_row_size, &b_column_size);
    printf("\nInsert the %d * %d Matrix A :\n", a_row_size, a_column_size);
    for (i = 0; i < a_row_size; i++) //inserting elements by user for A
    {
        for (j = 0; j < a_column_size; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Insert the %d * %d Matrix B :\n", b_row_size, b_column_size);
    for (i = 0; i < b_row_size; i++) //inserting elements by user for B
    {
        for (j = 0; j < b_column_size; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < a_row_size; i++)
    {
        for (j = 0; j < b_column_size; j++)
        {
            mult[i][j] = 0;
        }
    }
    printf("Here Matrix A * B\n", a_row_size, b_column_size); // after multiplication order will be row size of A and column size of B.
    for (i = 0; i < a_row_size; i++)
    {
        for (j = 0; j < b_column_size; j++)
        {
            int count = 0;
            for (k = 0; k < a_column_size; k++)
            {
                printf("%d * %d", a[i][k], b[k][j]);
                mult[i][j] += a[i][k] * b[k][j]; // The expression for actual multiplication.
                if (count == a_column_size - 1)
                {
                    break;
                }
                count++;
                printf(" + ");
            }
            printf("\t");
        }
        printf("\n");
    }
    printf("\nResult of Matrix A * B\n", row_size, column_size);    // The printing of multiplication of A and B.
    for (i = 0; i < a_row_size; ++i)
    {
        for (j = 0; j < b_column_size; ++j)
        {
            printf("%d\t", mult[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}
 // conversion function for length conversion.
void length()
{
    system("cls");
    float centimetre, Metre, kilometre, convert_number;  //declaration of required variables.
    int length_number;
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tLength Calculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Convert Centimetre to Metre");
    printf("\n\t\t\t\t\t> 2.Convert Centimetre to Kilometre");
    printf("\n\t\t\t\t\t> 3.Convert Metre to Centimetre");
    printf("\n\t\t\t\t\t> 4.Convert Metre to Kilometre");
    printf("\n\t\t\t\t\t> 5.Convert Kilometre to Centimetre");
    printf("\n\t\t\t\t\t> 6.Convert Kilometre to Metre");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");// selection of unit of conversion.
    scanf("%d", &length_number);
    system("cls");
    while (length_number > 0 && length_number < 7) 
    {
        system("cls");
        switch (length_number)
        {
        case 1:     //taking input in centimetre and converting it in metre
            printf("\nCentimetre : ");
            scanf("%f", &convert_number);
            printf("metre      : %.3f\n", convert_number / 100); // normal division and getting value upto three decimal places
            break;
        case 2:         //centimetre to kilometre
            printf("\nCentimetre : ");
            scanf("%f", &convert_number);
            printf("Kilometre  : %.3f\n", convert_number / 100000);
            break;
        case 3:       // metre to centimetre
            printf("\nMetre      : ");
            scanf("%f", &convert_number);
            printf("Centimetre : %.3f\n", convert_number * 100);
            break;
        case 4:    // metre to kilometre
            printf("\nMetre     : ");
            scanf("%f", &convert_number);
            printf("Kilometre : %.3f\n", convert_number / 1000);
            break;
        case 5:     //kilometre to centimetre
            printf("\nKilometre  : ");
            scanf("%f", &convert_number);
            printf("Centimetre : %.3f\n", convert_number * 100000);
            break;
        case 6:    // kilometre to metre
            printf("\nKilometre : ");
            scanf("%f", &convert_number);
            printf("Metre     : %.3f\n", convert_number * 1000);
            break;
        default:
         // breaks out from loop
            break;
        }
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tLength Calculator Menu :");
        printf("\n\n\t\t\t\t\t> 1.Convert Centimetre to Metre");
        printf("\n\t\t\t\t\t> 2.Convert Centimetre to Kilometre");
        printf("\n\t\t\t\t\t> 3.Convert Metre to Centimetre");
        printf("\n\t\t\t\t\t> 4.Convert Metre to Kilometre");
        printf("\n\t\t\t\t\t> 5.Convert Kilometre to Centimetre");
        printf("\n\t\t\t\t\t> 6.Convert Kilometre to Metre");
        printf("\n\t\t\t\t\t> 7.Calculator Menu");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &length_number);
        }

    return;
}
// function for mass unit conversion 
void mass()
{
    system("cls");
    float convert_number;
    int mass_number;
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tMass Calculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Convert Centigram to Gram");
    printf("\n\t\t\t\t\t> 2.Convert Centigram to Kilogram");
    printf("\n\t\t\t\t\t> 3.Convert Gram to Centigram");
    printf("\n\t\t\t\t\t> 4.Convert Gram to Kilogram");
    printf("\n\t\t\t\t\t> 5.Convert Kilogram to Centigram");
    printf("\n\t\t\t\t\t> 6.Convert Kilogram to Gram");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &mass_number);
    while (mass_number > 0 && mass_number < 7)
    {
        system("cls");
        switch (mass_number)
        {
        case 1:  // centigram to gram
            printf("\nCentigram : ");
            scanf("%f", &convert_number);
            printf("Gram      : %.3f\n", convert_number / 100);
            break;
        case 2:  //centigram to kilogram
            printf("\nCentigram : ");
            scanf("%f", &convert_number);
            printf("Kilogram  : %.3f\n", convert_number / 100000);
            break;
        case 3:  //gram to centigram 
            printf("\nGram      : ");
            scanf("%f", &convert_number);
            printf("Centigram : %.3f\n", convert_number * 100);
            break;
        case 4:  //gram to kilogram
            printf("\nGram     : ");
            scanf("%f", &convert_number);
            printf("Kilogram : %.3f\n", convert_number / 1000);
            break;
        case 5: //kilogram to centigram
            printf("\nKilogram  : ");
            scanf("%f", &convert_number);
            printf("Centigram : %.3f\n", convert_number * 100);
            break;
        case 6: //kilogram to gram
            printf("\nKilogram : ");
            scanf("%f", &convert_number);
            printf("Gram     : %.3f\n", convert_number * 1000);
            break;
        default:
        //breaks out of loops
            break;
        }
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tMass Calculator Menu :");
        printf("\n\n\t\t\t\t\t> 1.Convert Centigram to Gram");
        printf("\n\t\t\t\t\t> 2.Convert Centigram to Kilogram");
        printf("\n\t\t\t\t\t> 3.Convert Gram to Centigram");
        printf("\n\t\t\t\t\t> 4.Convert Gram to Kilogram");
        printf("\n\t\t\t\t\t> 5.Convert Kilogram to Centigram");
        printf("\n\t\t\t\t\t> 6.Convert Kilogram to Gram");
        printf("\n\t\t\t\t\t> 7.Calculator Menu");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &mass_number);      //taking user choice for further calculation.
    }

    return;
}
//temperature conversion function.
void temperature()
{
    system("cls");
    float convert_number;
    int temperature_number;
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tTempreture Calculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Convert Celsius to Fahrenheit");
    printf("\n\t\t\t\t\t> 2.Convert Celsius to Kelvin");
    printf("\n\t\t\t\t\t> 3.Convert Fahrenheit to Celsius");
    printf("\n\t\t\t\t\t> 4.Convert Fahrenheit to Kelvin");
    printf("\n\t\t\t\t\t> 5.Convert Kelvin to Celsius");
    printf("\n\t\t\t\t\t> 6.Convert Kelvin to Fahrenheit");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &temperature_number);
    while (temperature_number > 0 && temperature_number < 7)
    {
        system("cls");
        switch (temperature_number)
        {
        case 1:  //celsius to farenheit
            printf("\nCelsius    : ");
            scanf("%f", &convert_number);
            printf("Fahrenheit : %.3f\n", convert_number * 1.8 + 32); //actual calculation and result upto three decimal places.
            break;
        case 2:    // celsius to kelvin
            printf("\nCelsius : ");
            scanf("%f", &convert_number);
            printf("Kelvin  : %.3f\n", convert_number + 273.15);
            break;
        case 3: //farenheit to celsius
            printf("\nFahrenheit : ");
            scanf("%f", &convert_number);
            printf("Celsius    : %.3f\n", (convert_number - 32) * 0.5556);
            break;
        case 4:  //farenheit to kelvin
            printf("\nFahrenheit : ");
            scanf("%f", &convert_number);
            printf("Kelvin     : %.3f\n", (convert_number + 459.67) * 5 / 9);
            break;
        case 5: // kelvin to celsius
            printf("\nKelvin  : ");
            scanf("%f", &convert_number);
            printf("Celsius : %.3f\n", convert_number - 273.15);
            break;
        case 6: //kelvin to farenheit
            printf("\nKelvin     : ");
            scanf("%f", &convert_number);
            printf("Fahrenheit : %.3f\n", (convert_number * 9 / 5) - 459.67);
            break;
        default:
            break;
        }
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tTempreture Calculator Menu :");
        printf("\n\n\t\t\t\t\t> 1.Convert Celsius to Fahrenheit");
        printf("\n\t\t\t\t\t> 2.Convert Celsius to Kelvin");
        printf("\n\t\t\t\t\t> 3.Convert Fahrenheit to Celsius");
        printf("\n\t\t\t\t\t> 4.Convert Fahrenheit to Kelvin");
        printf("\n\t\t\t\t\t> 5.Convert Kelvin to Celsius");
        printf("\n\t\t\t\t\t> 6.Convert Kelvin to Fahrenheit");
        printf("\n\t\t\t\t\t> 7.Calculator Menu");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &temperature_number);           //taking user choice for further calculation.
        }

    return;
}
//function for speed unit conversion
void speed()
{
    system("cls");
    float convert_number;
    int speed_number;
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tSpeed Calculator Menu :");
    printf("\n\n\t\t\t\t\t> 1.Convert metres per Second to Kilometres per Hours");
    printf("\n\t\t\t\t\t> 2.Convert metres per Second to Miles per Hours");
    printf("\n\t\t\t\t\t> 3.Convert Kilometres per Hours to metres per Second");
    printf("\n\t\t\t\t\t> 4.Convert Kilometres per Hours to Miles per Hours");
    printf("\n\t\t\t\t\t> 5.Convert Miles per Hours to metres per Second");
    printf("\n\t\t\t\t\t> 6.Convert Miles per Hours to Kilometres per Hours");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &speed_number);
    while (speed_number > 0 && speed_number < 0)
    {
        system("cls");
        switch (speed_number)
        {
        case 1:  // metre per second to kilometre per hours
            printf("\nmetres per Second    : ");
            scanf("%f", &convert_number);
            printf("Kilometres per Hours : %.2f\n\n", convert_number * 3.60); //output upto 2 decimal places
            break;
        case 2: //metre per second to miles per hours
            printf("\nmetres per Second : ");
            scanf("%f", &convert_number);
            printf("Miles per Hours   : %.2f\n\n", convert_number * 2.24); 
            break;
        case 3:  //kilometres per hours to metres per second
            printf("\nKilometres per Hours : ");
            scanf("%f", &convert_number);
            printf("metres per Second    : %.2f\n\n", convert_number * 0.28);
            break;
        case 4:  //kilometres per hours to miles per hours
            printf("\nKilometres per Hours : ");
            scanf("%f", &convert_number);
            printf("Miles per Hours      : %.2f\n\n", convert_number * 0.62);
            break;
        case 5: //miles per hours to metres per seconds
            printf("\nMiles per Hours   : ");
            scanf("%f", &convert_number);
            printf("metres per Second : %.2f\n\n", convert_number * 0.45);
            break;
        case 6: //miles per hour to kilometres per hours 
            printf("\nMiles per Hours      : ");
            scanf("%f", &convert_number);
            printf("Kilometres per Hours : %.2f\n\n", convert_number * 1.61);
            break;
        default:
            break;
        }
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tSpeed Calculator Menu :");
        printf("\n\n\t\t\t\t\t> 1.Convert metres per Second to Kilometres per Hours");
        printf("\n\t\t\t\t\t> 2.Convert metres per Second to Miles per Hours");
        printf("\n\t\t\t\t\t> 3.Convert Kilometres per Hours to metres per Second");
        printf("\n\t\t\t\t\t> 4.Convert Kilometres per Hours to Miles per Hours");
        printf("\n\t\t\t\t\t> 5.Convert Miles per Hours to metres per Second");
        printf("\n\t\t\t\t\t> 6.Convert Miles per Hours to Kilometres per Hours");
        printf("\n\t\t\t\t\t> 7.Calculator Menu");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &speed_number);         //taking user choice for further calculation.
    }

    return;
}
//time unit conversion
void timec()
{
    system("cls");
    float convert_number;
    int time_number;
    int min, minu, h ,s1,s2;
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tTime  Calculator Menu :");
    printf("\n\t\t\t\t\t> 1.Convert Seconds to Minutes");
    printf("\n\t\t\t\t\t> 2.Convert Seconds to Hours");
    printf("\n\t\t\t\t\t> 3.Convert Minutes to Seconds");
    printf("\n\t\t\t\t\t> 4.Convert Minutes to Hours");
    printf("\n\t\t\t\t\t> 5.Convert Hours to Seconds");
    printf("\n\t\t\t\t\t> 6.Convert Hours to Minutes");
    printf("\n\t\t\t\t\t> 7.Calculator Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &time_number);
    while (time_number > 0 && time_number < 7)
    {
        system("cls");
        switch (time_number)
        {
        case 1:  //seconds to minutes
            printf("\nSeconds : ");
            scanf("%d", &s1);
            printf("Minutes : %d minutes and %i seconds\n\n", (s1 / 60),( s1 %60));
            break;
        case 2: //seconds to hours
            printf("\nSeconds : ");
            scanf("%f", &convert_number);
            printf("Hours   : %.5f\n\n", convert_number / 3600); //output upto 5 decimal places
            break;
        case 3: //minutes to seconds
            printf("\nMinutes : ");
            scanf("%f", &convert_number);
            printf("Seconds : %.2f\n\n", 60 * convert_number); //output upto 2 decimal places
            break;
        case 4: //minutes to hours
            printf("\nMinutes : ");
            scanf("%i", &min);
            h = min / 60;
            minu = min % 60;
            printf("Hours   : %d hr %i min\n\n", h, minu);
            break;
        case 5: //hours to second
            printf("\nHours   : ");
            scanf("%f", &convert_number);
            printf("Seconds : %.2f\n\n", convert_number * 3600);
            break;
        case 6: //hours to minutes
            printf("\nHours   : ");
            scanf("%f", &convert_number);
            printf("Minutes : %.2f\n\n", convert_number * 60);
            break;
        case 7:
            main();
            system("cls"); //clearing screen
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
        }
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tTime  Calculator Menu :");
        printf("\n\t\t\t\t\t> 1.Convert Seconds to Minutes");
        printf("\n\t\t\t\t\t> 2.Convert Seconds to Hours");
        printf("\n\t\t\t\t\t> 3.Convert Minutes to Seconds");
        printf("\n\t\t\t\t\t> 4.Convert Minutes to Hours");
        printf("\n\t\t\t\t\t> 5.Convert Hours to Seconds");
        printf("\n\t\t\t\t\t> 6.Convert Hours to Minutes");
        printf("\n\t\t\t\t\t> 7.Calculator Menu");
        printf("\n\t\t\t\t\t> 8.Exit");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &time_number);          //taking user choice for further calculation.
    }

    return;
}
//currency conversion for specified values(not real time).
void currency() 
{
    system("cls");
    float convert_number;
    int currency_number;
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tCurrency Calculator Menu :");
    printf("\n\t\t\t\t\t> 1.Convert Indian Rupees to US Dollar");
    printf("\n\t\t\t\t\t> 2.Convert Indian Rupees to Euro");
    printf("\n\t\t\t\t\t> 3.Convert US Dollar to Indian Rupees");
    printf("\n\t\t\t\t\t> 4.Convert US Dollar to Euro");
    printf("\n\t\t\t\t\t> 5.Convert Euro to Indian Rupees");
    printf("\n\t\t\t\t\t> 6.Convert Euro to US Dollar");
    printf("\n\t\t\t\t\t> 7.Go Back to Main Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &currency_number);
    while (currency_number > 0 && currency_number < 7)
    {   //all cureency cases-
        system("cls");
        switch (currency_number)
        {
        case 1:
            printf("\nIndian Rupees : ");
            scanf("%f", &convert_number);
            printf("US Dollar   : %.3f\n\n", convert_number * 0.0122133);
            break;
        case 2:
            printf("\nIndian Rupees : ");
            scanf("%f", &convert_number);
            printf("Euro  : %.3f\n\n", convert_number * 0.0112533);   
            break;
        case 3:
            printf("\nUS Dollar : ");
            scanf("%f", &convert_number);
            printf("Indian Rupees : %.3f\n\n", 83.6772 * convert_number);
            break;
        case 4:
            printf("\nUS Dollar  : ");
            scanf("%f", &convert_number);
            printf("Euro : %.3f\n\n", convert_number * 0.93911);
            break;
        case 5:
            printf("\nEuro  : ");
            scanf("%f", &convert_number);
            printf("Indian Rupees : %.3f\n\n", convert_number * 88.8774);
            break;
        case 6:
            printf("\nEuro  : ");
            scanf("%f", &convert_number);
            printf("US Dollar : %f\n\n", convert_number * 1.06359);
            break;
        case 7:
            main();
            system("cls");
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
        }
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tCurrency Calculator Menu :");
        printf("\n\t\t\t\t\t> 1.Convert Indian Rupees to US Dollar");
        printf("\n\t\t\t\t\t> 2.Convert Indian Rupees to Euro");
        printf("\n\t\t\t\t\t> 3.Convert US Dollar to Indian Rupees");
        printf("\n\t\t\t\t\t> 4.Convert US Dollar to Euro");
        printf("\n\t\t\t\t\t> 5.Convert Euro to Indian Rupees");
        printf("\n\t\t\t\t\t> 6.Convert Euro to US Dollar");
        printf("\n\t\t\t\t\t> 7.Back to Main Menu");
        printf("\n\t\t\t\t\t> 8.Exit");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &currency_number);              //taking user choice for further calculation.
    }
    return;
}
//energy unit conversion
void energy()
{
    system("cls");
    float convert_number;
    int energy_number;
    printf("\n\t\t\t===========================================================");
    printf("\n\n\t\t\t\t\tEnergy Conversion Menu :");
    printf("\n\t\t\t\t\t> 1.Convert Joules to Kilowatt-hour");
    printf("\n\t\t\t\t\t> 2.Convert Joules to Kilojoules");
    printf("\n\t\t\t\t\t> 3.Convert Kilowatt-hour to Joules");
    printf("\n\t\t\t\t\t> 4.Convert Kilowatt-hour to Kilojoules");
    printf("\n\t\t\t\t\t> 5.Convert Kilojoules to Joules");
    printf("\n\t\t\t\t\t> 6.Convert Kilojoules to Kilowatt-hour");
    printf("\n\t\t\t\t\t> 7.Calculator To Menu");
    printf("\n\t\t\t\t\t> 8.Exit");
    printf("\n\n\t\t\t===========================================================\n\n");
    printf("\n\n\t\t\tEnter Your Choice => ");
    scanf("%d", &energy_number);
    while (energy_number > 0 && energy_number <= 8)
    {  // all energy conversion cases-
        system("cls");
        switch (energy_number)
        {
        case 1:
            printf("\nJoules    : ");
            scanf("%f", &convert_number);
            printf("Kilowatt-hour : %.10f\n\n", convert_number / 3600000);
            break;
        case 2:
            printf("\nJoules     : ");
            scanf("%f", &convert_number);
            printf("KiloJoules : %.3f\n\n", convert_number / 1000);
            break;
        case 3:
            printf("\nKilowatt-hour : ");
            scanf("%f", &convert_number);
            printf("Joules    : %10.f\n\n", 3600000 * convert_number);
            break;
        case 4:
            printf("\nKilowatt-hour  : ");
            scanf("%f", &convert_number);
            printf("Kilojoules : %.3f\n\n", convert_number * 3600);
            break;
        case 5:
            printf("\nKilojoules : ");
            scanf("%f", &convert_number);
            printf("Joules     : %.3f\n\n", convert_number * 1000);
            break;
        case 6:
            printf("\nKilojoules : ");
            scanf("%f", &convert_number);
            printf("Kilowatt-hour  : %f\n\n", convert_number / 3600);
            break;
        case 7:
            main();
            system("cls");
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
        }
        printf("\n\t\t\t===========================================================");
        printf("\n\n\t\t\t\t\tEnergy Calculator Menu :");
        printf("\n\t\t\t\t\t> 1.Convert Joules to Kilowatt-hour");
        printf("\n\t\t\t\t\t> 2.Convert Joules to Kilojoules");
        printf("\n\t\t\t\t\t> 3.Convert Kilowatt-hour to Joules");
        printf("\n\t\t\t\t\t> 4.Convert Kilowatt-hour to Kilojoules");
        printf("\n\t\t\t\t\t> 5.Convert Kilojoules to Joules");
        printf("\n\t\t\t\t\t> 6.Convert Kilojoules to Kilowatt-hour");
        printf("\n\t\t\t\t\t> 7.Calculator To Menu");
        printf("\n\t\t\t\t\t> 8.Exit");
        printf("\n\n\t\t\t===========================================================\n\n");
        printf("\n\n\t\t\tEnter Your Choice => ");
        scanf("%d", &energy_number);            //taking user choice for further calculation.
    }
    return;
}
//END OF CODE THANK YOU..

