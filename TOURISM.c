#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
// Defining Enumerations(enums)
enum status
{
    MENU,
    LOGGEDIN
} status;
enum status Current_Status = MENU;
// Global Variables
char Current_User[100];
int a;
// defining structure containing user information
typedef struct User_Info
{
    char User_Name[1000];
    char Password[1000];
    char destination[100];
    int Price;
    char Mode_Of_Plan[100];
    char Mode_Of_Transport[100];
    char Car_Model[100];
    char Train_Model[100];
    char Bus_Model[100];
    int Room_Number;
    char Hotel_Name[100];
    struct User_Info *next;

} User_Info;
typedef struct Car
{
    char carrented[20];
    int rent, dr, mr, yr;
} Car;

typedef struct Customer_Car
{
    char customername[50];
    char customerId[20];
    char carrented[20];
} Customer_Car;
#define MAX_CARS 10
#define MAX_CUSTOMERS 100
char carbrand[10][20] = {"HYUNDAI", "SUZUKI", "HONDA", "TOYOTA", "FORD", "TATA", "MERCEDES", "AUDI", "ISUZU"};
char carmodel[10][20] = {"Veloster", "Celerio", "Civic", "Avalon", "Explorer", "Safari", "E-Class", "Q3", "D-MAX"};
struct Customer_Car cr[MAX_CUSTOMERS];
struct Car ca[MAX_CARS];
// defining structure containing customer care support details
typedef struct Customer_Care_Members
{
    char Name[1000];
    char Email[50];
    char Phone[50];
} Customer_Care_Members;
struct Hotel_Customer // STRUCTURE DECLARATION
{
    int Room_Number;
    char Name[20];
    char Address[25];
    char Phone_Number[15];
    int Period;
    char Arrival_Date[10];
} hc;
// Global Variables
char Current_User[100];
int a, Train_Cost = 0, Bus_Cost = 0, Car_Cost = 0, Hotel_Cost = 0, Hotel_Final_Choice = 0, Total_Bill = 0;
struct User_Info *data = NULL;
//  Defining functions
int Main_Menu(int status);
struct User_Info *Display_List(User_Info *);
void Add_List(User_Info *);
struct User_Info *Add_User(User_Info *);
int Check_Valid_Password(char *);
void Login_User(User_Info *);
void Change_Password(User_Info *);
void Logout_User();
void Exit_Program();
int Show_Brochure();
int Show_Plan_Menu();
void Book_Ticket();
void Customer_Care_Details_Display(int, int);
int Selection_Of_Place(int, User_Info *);
int Bulk_Plan(int);
int Bulk_Plan_Booking(User_Info *);
int Calculate_Price(char *, int, int);
void BulkPlan_View_Ticket(User_Info *);
int Individual_Plan(User_Info *);
int Trains_Display(User_Info *);
int Train_Booking(int);
int Buses_Display(User_Info *);
int Bus_Booking(int);
void Cars_Display(User_Info *);
int Car_Rental();
int Car_Rental_Cost(int);
int Hotels_Display(User_Info *);
int Hotel_Booking();
int Hotel_Book_Room(User_Info *);
int Check_Phone_Number(char *);
int Check_Date(char *);
void Hotel_Display_Booking();
int Hotel_Booking_Cost(int, int);
int Final_Bill(int, int, int, int, User_Info *);
void Print_Ticket(int, User_Info *);
void IndividualPlan_View_Ticket(User_Info *);
void BulkPlan_View_Ticket(User_Info *);
void Cancel_Ticket(User_Info *);
void Update_File(User_Info *);
// Main Function
int main()
{
    time_t t;
    time(&t);
    printf("\t\t***************************************************  \n");
    printf("\t\t*                                                 *\n");
    printf("\t\t*       -------------------------------           *\n");
    printf("\t\t*        WELCOME TO ASH TOURISM SERVICE           *\n");
    printf("\t\t*       -------------------------------           *\n");
    printf("\t\t*                                                 *\n");
    printf("\t\t***************************************************\n\n\n");
    printf("\n\tCurrent date and time is :%s ", ctime(&t));
    printf("\n\t In order to book a package you should create User Account ");
    Main_Menu(Current_Status);
    return 0;
}
int Main_Menu(int Current_Status)
{
    int ch1, ch2;
    data = Display_List(data);
    printf("\npress any key to continue ");
    getche();
    if (Current_Status == MENU)
    {
        printf("\n\t\t\t\t1 -> Add User\n\t\t\t\t2 -> Login User\n\t\t\t\t3 -> Brochure\n\t\t\t\t4 -> Exit Program\n\n\t\t\t\tEnter:");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1:
            data = Add_User(data);
            Main_Menu(Current_Status);
            break;
        case 2:
            Login_User(data);
            Main_Menu(LOGGEDIN);
            break;
        case 3:
            Show_Brochure();
            break;
        case 4:
            Exit_Program();
            exit(0);
            break;
        default:
            Main_Menu(Current_Status);
        }
    }
    else if (Current_Status == LOGGEDIN)
    {
        system("CLS");
        printf("\n\t\t\t\t*********************");
        printf("\n\t\t\t\t ASH TOURISM SERVICE");
        printf("\n\t\t\t\t=========================\n");
        printf("\n\t\t\t\t1 -> Book Package\n\t\t\t\t2 -> Individual View Ticket\n\t\t\t\t3 ->Bulk View Ticket\n\t\t\t\t4 -> Cancel Ticket\n\t\t\t\t5 -> Change Password"
               "\n\t\t\t\t 6 -> Logout User\n\t\t\t\t 7 -> Brochure \n\t\t\t\t 8 -> Exit \n");
        printf("Please enter any number :");
        scanf("%d", &ch2);
        switch (ch2)
        {
        case 1:
            Book_Ticket();
            system("PAUSE");
            system("CLS");
            break;
        case 2:
            IndividualPlan_View_Ticket(data);
            system("PAUSE");
            system("CLS");
            break;
        case 3:
            BulkPlan_View_Ticket(data);
            system("PAUSE");
            system("CLS");
            break;
        case 4:
            Cancel_Ticket(data);
            system("PAUSE");
            system("CLS");
            break;
        case 5:
            Change_Password(data);
            system("PAUSE");
            system("CLS");
            break;
        case 6:
            Logout_User();
            system("PAUSE");
            system("CLS");
            break;
        case 7:
            Show_Brochure();
            system("PAUSE");
            system("CLS");
            break;
        case 8:
            Exit_Program();
            exit(0);
            break;
        default:
            Main_Menu(Current_Status);
        }
    }
}
// function for displaying and adding content to list
struct User_Info *Display_List(User_Info *data2)
{
    User_Info *t, *ptr, temp;
    FILE *fp;
    fp = fopen("User_Information.txt", "r");

    if (fp == NULL)
        return NULL;

    if (fgetc(fp) == EOF)
        return NULL;
    rewind(fp);
    while (fscanf(fp, "%s %s %s %d %s %s %s %s %s %d %s", temp.User_Name, temp.Password, temp.destination, &temp.Price, temp.Mode_Of_Plan, temp.Mode_Of_Transport, temp.Car_Model, temp.Train_Model, temp.Bus_Model, &temp.Room_Number, temp.Hotel_Name) != EOF)
    {
        ptr = (User_Info *)malloc(sizeof(User_Info));
        strncpy(ptr->User_Name, temp.User_Name, sizeof(ptr->User_Name));
        strncpy(ptr->Password, temp.Password, sizeof(ptr->Password));
        strncpy(ptr->destination, temp.destination, sizeof(ptr->destination));
        ptr->Price = temp.Price;
        strncpy(ptr->Mode_Of_Plan, temp.Mode_Of_Plan, sizeof(ptr->Mode_Of_Plan));
        strncpy(ptr->Mode_Of_Transport, temp.Mode_Of_Transport, sizeof(ptr->Mode_Of_Transport));
        strncpy(ptr->Car_Model, temp.Car_Model, sizeof(ptr->Car_Model));
        strncpy(ptr->Train_Model, temp.Train_Model, sizeof(ptr->Train_Model));
        strncpy(ptr->Bus_Model, temp.Bus_Model, sizeof(ptr->Bus_Model));
        memcpy(&ptr->Room_Number, &temp.Room_Number, sizeof(ptr->Room_Number));
        strncpy(ptr->Hotel_Name, temp.Hotel_Name, sizeof(ptr->Hotel_Name));
        ptr->next = NULL;
        if (data2 == NULL)
            data2 = t = ptr;
        else
        {
            data2->next = ptr;
            data2 = ptr;
        }
    }
    fclose(fp);
    return t;
}
// function for displaying list
void Add_List(User_Info *data2)
{
    User_Info *current = data2;
    FILE *fp;
    fp = fopen("User_Information.txt", "a");
    if (fp == NULL)
    {
        printf("Unable to open the file");
    }
    else
    {
        while (current != NULL)
        {
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s\n", data2->User_Name, data2->Password, data2->destination, data2->Price, data2->Mode_Of_Plan, data2->Mode_Of_Transport, data2->Car_Model, data2->Train_Model, data2->Bus_Model, data2->Room_Number, data2->Hotel_Name);
            current = current->next;
        }
    }
    fclose(fp);
}
// Function to add a new user to the linked list
struct User_Info *Add_User(User_Info *data2)
{
    User_Info *c = data2;
    User_Info *NU = (User_Info *)malloc(sizeof(User_Info));
    printf("Enter your UserName: ");
    scanf("%s", NU->User_Name);
    while (data2 != NULL)
    {
        if (strcmp(data2->User_Name, NU->User_Name) == 0)
        {
            printf("This UserName has already been used.");
            printf("\nPlease register with another UserName\n");
            free(NU);
            Add_User(data);
            return c;
        }
        data2 = data2->next;
    }
    fflush(stdin);
    char password[100];
    do
    {
        printf("\nEnter Password (must be at least 8 characters and contain at least one uppercase letter, one lowercase letter, one digit, and one special character): ");
        scanf(" %[^\n]s", password);
        if (!Check_Valid_Password(password))
        {
            printf("Invalid password. Please try again.\n");
        }
    } while (!(Check_Valid_Password(password)));
    strncpy(NU->Password, password, sizeof(NU->Password));
    NU->next = NULL;
    strncpy(NU->destination, "N/A", sizeof(NU->destination));
    strncpy(NU->Mode_Of_Plan, "N/A", sizeof(NU->Mode_Of_Plan));
    strncpy(NU->Mode_Of_Transport, "N/A", sizeof(NU->Mode_Of_Transport));
    strncpy(NU->Car_Model, "N/A", sizeof(NU->Car_Model));
    strncpy(NU->Train_Model, "N/A", sizeof(NU->Train_Model));
    strncpy(NU->Bus_Model, "N/A", sizeof(NU->Bus_Model));
    strncpy(NU->Hotel_Name, "N/A", sizeof(NU->Hotel_Name));
    NU->Price = 0;
    NU->Room_Number = 0;
    if (data2 == NULL)
    {
        data2 = c = NU;
    }
    else
    {
        while (data2->next != NULL)
        {
            data2 = data2->next;
        }
        data2->next = NU;
    }
    Add_List(c);
    return c;
}
// function for checking valid password
int Check_Valid_Password(char *password)
{
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;
    int len = strlen(password);
    char Disallowed_Chars[] = {'^', '\t', '\n', '\r', '\0'};
    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
        {
            has_upper = 1;
        }
        else if (islower(password[i]))
        {
            has_lower = 1;
        }
        else if (isdigit(password[i]))
        {
            has_digit = 1;
        }
        else
        {
            int is_disallowed = 0;
            for (int j = 0; j < sizeof(Disallowed_Chars); j++)
            {
                if (password[i] == Disallowed_Chars[j])
                {
                    is_disallowed = 1;
                    break;
                }
            }
            if (!is_disallowed)
            {
                has_special = 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return (len >= 8 && has_upper && has_lower && has_digit && has_special);
}
// function for logging in user
void Login_User(User_Info *data2)
{
    int c;
    char username[100];
    char password[100];
    fflush(stdin);
    printf("\n\t\t\tEnter Your Registered Username:\n\t\t");
    scanf("%s", username);
    fflush(stdin);
    printf("\n\t\tEnter  Your Saved Password:\n\t\t");
    scanf(" %[^\n]s", password);
    FILE *fp;
    fp = fopen("User_Information.txt", "r");
    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return;
    }
    int found = 0;
    while (fscanf(fp, "%s %s %s %d %s %s %s %s %s %d %s", data2->User_Name, data2->Password, data2->destination, &data2->Price, data2->Mode_Of_Plan, data2->Mode_Of_Transport, data2->Car_Model, data2->Train_Model, data2->Bus_Model, &data2->Room_Number, data2->Hotel_Name) != EOF)
    {

        if ((!strcmp(data2->User_Name, username)) && (!strcmp(data2->Password, password)))
        {
            Current_Status = LOGGEDIN;
            strncpy(Current_User, username, sizeof(Current_User));
            printf("\n\t\t Your Login is  successful!\n");
            getchar();
            found = 1;
            break;
        }
        else if ((!strcmp(data2->User_Name, username)) && (strcmp(data2->Password, password)))
        {
            printf("Password you entered is mismatched with your saved Password\n");
            Main_Menu(Current_Status);
            return;
        }
        else if ((strcmp(data2->User_Name, username)) && (!strcmp(data2->Password, password)))
        {
            printf("User Name you entered is mismatched with your registered Username\n");
            Main_Menu(Current_Status);
            return;
        }
        else
        {
            data2 = data2->next;
        }
    }
    if (found == 1)
    {
        fclose(fp);
        return;
    }
    else
    {
        printf("Sorry, no such user record was found with the credentials you entered\n");
        fclose(fp);
        Main_Menu(Current_Status);
    }
}
// Function to change password
void Change_Password(User_Info *data2)
{
    char passcurr[100], username[100];
    fflush(stdin);
    printf("Enter your current username to continue:\n");
    scanf(" %s", username);
    printf("Enter your current password to continue:\n");
    scanf(" %[^\n]s", passcurr);
    FILE *fp;
    fp = fopen("User_Information.txt", "r");

    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return;
    }
    User_Info *data = NULL;
    User_Info *t = NULL;
    User_Info *current = NULL;
    while (!feof(fp))
    {
        current = (User_Info *)malloc(sizeof(User_Info));
        if (fscanf(fp, "%s %s %s %d %s %s %s %s %s %d %s", current->User_Name, current->Password, current->destination, &current->Price, current->Mode_Of_Plan, current->Mode_Of_Transport, current->Car_Model, current->Train_Model, current->Bus_Model, &current->Room_Number, current->Hotel_Name) != EOF)
        {
            current->next = NULL;
            if (data == NULL)
            {
                data = current;
                t = current;
            }
            else
            {
                t->next = current;
                t = current;
            }
        }
        else
        {
            free(current);
        }
    }
    fclose(fp);
    User_Info *user = NULL;
    t = data;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, username))
        {
            user = t;
            break;
        }
        t = t->next;
    }
    if (user == NULL)
    {
        printf("\n\t\tError: user not found\n");
        return;
    }
    char newpassword[100];
    if (!strcmp(passcurr, user->Password))
    {
        printf("Enter new Password:\n");
        scanf(" %[^\n]s", newpassword);
        if (!Check_Valid_Password(newpassword))
        {
            printf("\n\t\tPassword entered does not meet criteria\n");
            return;
        }
        strncpy(user->Password, newpassword, sizeof(user->Password));
        fp = fopen("User_Information.txt", "w");

        if (fp == NULL)
        {
            printf("Error: could not open file\n");
            return;
        }
        t = data;
        while (t != NULL)
        {
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s\n", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
            t = t->next;
        }

        fclose(fp);

        printf("\n\t\tYour Password has been successfully updated!\n");
    }
    else
    {
        printf("\n\t\tYou entered the wrong current password\n");
        return;
    }
    return;
}
// function to logout user
void Logout_User()
{
    if (Current_Status == MENU || strcmp(Current_User, "\0") == 0)
    {
        printf("You should be logged in to logout\n");
        return;
    }
    strcpy(Current_User, "\0");
    Current_Status = MENU;
    printf("You have been successfully logged out\n");
}
// function to exit program
void Exit_Program()
{
    system("cls");
    printf("\n\n\t *****THANK YOU*****");
    printf("\n\t FOR TRUSTING OUR SERVICE");
}
// function to show brochure
int Show_Brochure()
{
    system("START https://drive.google.com/file/d/1x5H99wLXn1iVhN6rqx9tqiEk8jtWY_qz/view?usp=sharing");
    Book_Ticket();
}
// Function to Book ticket
void Book_Ticket()
{
    int c, a;
    printf("\n\n");
    printf("\n\t ** Welcome to ASH Ticket Booking Service **");
    printf("\n To direct further please login if registered else register");
    printf("\n\tPress 1 to register else 2 to login: ");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        data = Add_User(data);
        break;
    case 2:
        Login_User(data);
        break;
    default:
        Exit_Program();
        break;
    }

    printf("\nTo Direct to plan menu options press 1 or  to return to main menu press 0 : ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        a = Show_Plan_Menu();
        break;
    case 0:
        Main_Menu(Current_Status);
        break;
    default:
        Exit_Program();
        break;
    }
}
// to show menu of different places
int Show_Plan_Menu()
{
    printf("\n\tWe are directing to Select place with reference to your Interest");
    printf("\n\tPress any key to continue");
    getche();
    printf("\n\n");
    printf("\n\t ** Welcome to ASH Selection of place Service **");
    printf("\n\t\t We let you Outreach Four various types of places");
    printf("\n\t\t 1.Hit 1 to select WaterFalls Places");
    printf("\n\t\t 2.Hit 2 to select Hill Stations Places");
    printf("\n\t\t 3.Hit 3 to select Beaches Places");
    printf("\n\t\t 4.Hit 4 to select Devotional Places");
    int c, member_ID, ch;
    printf("\n\t\t Enter your choice : ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        member_ID = 1;
        Customer_Care_Details_Display(member_ID, c);
        break;
    case 2:
        member_ID = 2;
        Customer_Care_Details_Display(member_ID, c);
        break;
    case 3:
        member_ID = 3;
        Customer_Care_Details_Display(member_ID, c);
        break;

    case 4:
        member_ID = 4;
        Customer_Care_Details_Display(member_ID, c);
        break;
    default:
        printf("\n\t\tPlease Enter valid Number\n");
        break;
    }
    return c;
}
// function for displaying customer care details
void Customer_Care_Details_Display(int member_ID, int choice)
{
    struct Customer_Care_Members Members_Info[4];
    switch (member_ID)
    {
    case 1:
        printf("\n\tWater Falls Customer Care Member\n");
        strcpy(Members_Info[0].Name, "Krishnaja");
        strcpy(Members_Info[0].Email, "22cs01024@iitbbs.ac.in");
        strcpy(Members_Info[0].Phone, "1234656789");
        printf("\n%s is here to assist you  and you can reach her through email  by %s and  through phone by %s \n", Members_Info[0].Name, Members_Info[0].Email, Members_Info[0].Phone);
        Selection_Of_Place(choice, data);
        break;
    case 2:
        printf("\n\tHill Stations Customer Care Member\n");
        strcpy(Members_Info[1].Name, "Srinidhi");
        strcpy(Members_Info[1].Email, "22cs01022@iitbbs.ac.in");
        strcpy(Members_Info[1].Phone, "2034156789");
        printf("\n%s is here to assist you  and you can reach her through email by %s and through phone by %s \n", Members_Info[1].Name, Members_Info[1].Email, Members_Info[1].Phone);
        Selection_Of_Place(choice, data);
        break;
    case 3:
        printf("\n\tBeaches Customer Care Member\n");
        strcpy(Members_Info[2].Name, "Hemant");
        strcpy(Members_Info[2].Email, "22cs01004@iitbbs.ac.in");
        strcpy(Members_Info[2].Phone, "2345678901");
        printf("\n%s is here to assist you  and you can reach  him through email by %s and  through phone by %s\n ", Members_Info[2].Name, Members_Info[2].Email, Members_Info[2].Phone);
        Selection_Of_Place(choice, data);
        break;
    case 4:
        printf("\n\tDevotional Customer Care Member\n");
        strcpy(Members_Info[3].Name, "Sameeksha");
        strcpy(Members_Info[3].Email, "22ec01021@iitbbs.ac.in");
        strcpy(Members_Info[3].Phone, "2008200512");
        printf("\n%s is here to assist you  and you can reach her through email by %s and  through phone by %s\n ", Members_Info[3].Name, Members_Info[3].Email, Members_Info[3].Phone);
        Selection_Of_Place(choice, data);
        break;
    default:
        printf("\n\t Please Enter Valid Number");
    }
}
// function to select places and plan
int Selection_Of_Place(int c, User_Info *data2)
{
    int choice, pc;
    User_Info *t = data2;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, Current_User))
            break;
        t = t->next;
    }
    if (t == NULL)
        return 1;
    typedef struct
    {
        int id;
        char name[100];
        char location[100];
        char destination[100];
    } Place;

    Place waterfalls[] = {
        {11, "ChitrakootWaterfall", "Chattisgarh"},
        {12, "MeenmuttyFalls", "Kerala"},
        {13, "DudhsagarFalls", "Goa"},
        {14, "VajraiFalls", "Maharashtra"}};

    Place hillStations[] = {
        {21, "Ooty", "Tamilnadu"},
        {22, "Shimla", "HimachalPradesh"},
        {23, "Lambasingi", "AndhraPradesh"},
        {24, "Jogimatti", "Karnataka"}};

    Place beaches[] = {
        {31, "Visakhapatnam", "AndhraPradesh"},
        {32, "Panaji", "Goa"},
        {33, "Trivandrum", "Kerala"},
        {34, "Gokarna", "Karnataka"}};

    Place devotionalPlaces[] = {
        {41, "Varanasi", "UttarPradesh"},
        {42, "Rameswaram", "Tamilnadu"},
        {43, "Ujjain", "Madhyapradesh"},
        {44, "Tirupati", "Andhrapradesh"}};
    switch (c)
    {
    case 1:
        for (int i = 0; i < 4; i++)
        {
            printf("\n%d) %s, %s", waterfalls[i].id, waterfalls[i].name, waterfalls[i].location);
        }
        break;
    case 2:
        for (int i = 0; i < 4; i++)
        {
            printf("\n%d) %s, %s", hillStations[i].id, hillStations[i].name, hillStations[i].location);
        }
        break;
    case 3:
        for (int i = 0; i < 4; i++)
        {
            printf("\n%d) %s, %s", beaches[i].id, beaches[i].name, beaches[i].location);
        }
        break;
    case 4:
        for (int i = 0; i < 4; i++)
        {
            printf("\n%d) %s, %s", devotionalPlaces[i].id, devotionalPlaces[i].name, devotionalPlaces[i].location);
        }
        break;
    default:
        break;
    }
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if ((choice >= 11 && choice <= 14) || (choice >= 21 && choice <= 24) || (choice >= 31 && choice <= 34) || (choice >= 41 && choice <= 44))
    {
        for (int i = 0; i < 4; i++)
        {
            if (waterfalls[i].id == choice)
            {
                strcpy(t->destination, waterfalls[i].name);
                break;
            }
            else if (hillStations[i].id == choice)
            {
                strcpy(t->destination, hillStations[i].name);
                break;
            }
            else if (beaches[i].id == choice)
            {
                strcpy(t->destination, beaches[i].name);
                break;
            }
            else if (devotionalPlaces[i].id == choice)
            {
                strcpy(t->destination, devotionalPlaces[i].name);
                break;
            }
        }
    }
    else
    {
        printf("Invalid input. Please enter a valid number.");
        return 1;
    }
    printf("\n\tWe are directing to Selection of Plan");
    printf("\n\tPress any key to continue");
    getche();
    printf("\n\n");
    printf("\n\t ** Welcome to ASH Selection of Plan  Service **");
    printf("\n\tWhat Would you like to choose Bulk plan or Individual plan?");
    printf("\n\t Hit 1 to choose Bulk plan");
    printf("\n\t Hit 2 to choose Individual plan");
    printf("\n\t Enter : ");
    scanf("%d", &pc);
    switch (pc)
    {
    case 1:
        strcpy(t->Mode_Of_Plan, "B");
        Bulk_Plan(choice);
        break;
    case 2:
        strcpy(t->Mode_Of_Plan, "I");
        Individual_Plan(data);
        break;
    default:
        Exit_Program();
        break;
    }
    FILE *fp;
    fp = fopen("User_Information.txt", "r+");
    if (fp == NULL)
    {
        printf("Problem in opening this file");
        return -1;
    }

    while (t != NULL)
    {

        if (!strcmp(t->User_Name, Current_User))
        {
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
            break;
        }
        t = t->next;
    }
    fclose(fp);
    return choice;
}
// function for bulk plan
int Bulk_Plan(int choice)
{
    switch (choice)
    {
    case 11:
        printf("\n\t\tCHITRAKOOT SCENIC VIEW PACKAGE \n\n\tCity: \t\t\t\t\t\tAllahabad, Satna, Kalinjar \n\tHighlights: \t\t\t\t\tChithrakoot Water falls, Sphatic Shila, Ram Ghat Road, Janaki Kund, Panna National Park etc...  \n\tDuration: \t\t\t\t\t3 nights/ 4 days \n\tCost of package per Adult: \t\t\t20,565/- \n\tCost of package per child (age below 12): \t18,252/- ");
        break;
    case 12:
        printf("\n\t\tMEENMUTTY WATERFALLS PACKAGE \n\n\tCity: \t\t\t\t\t\tVaduvanchal, Meenmutty, Chundel \n\tHighlights: \t\t\t\t\tMeenmutty Waterfalls, Kanthapara Waterfalls, Sunrise Valley, Chembra Park, Soochipara Waterfalls etc...  \n\tDuration: \t\t\t\t\t5 nights/ 6 days \n\tCost of package per Adult: \t\t\t22,565/- \n\tCost of package per child (age below 12): \t20,252/- ");
        break;
    case 13:
        printf("\n\t\tDUDHSAGAR FALLS PACKAGE \n\n\tCity: \t\t\t\t\t\t \n\tHighlights: \t\t\t\tDudhsagar, Goa \n\tHighlights: \t\t\t\tMollem National Park, Dudhsagar falls, Sri Mahadeva Temple Tambdisurla etc...  \n\tDuration: \t\t\t\t\t2 nights/ 3 days \n\tCost of package per Adult: \t\t\t10,565/- \n\tCost of package per child (age below 12): \t8,252/- ");
        break;
    case 14:
        printf("\n\t\tVAJRAI WATERFALLS PACKAGE \n\n\tCity: \t\t\t\t\t\tKas,  \n\tHighlights: \t\t\t\tVajrai waterfalls, Kaas plateau of Flowers, Panchagani HIll Station, Prathapgad Fort, raighad Fort etc...  \n\tDuration: \t\t\t\t\t6 nights/ 7 days \n\tCost of package per Adult: \t\t\t28,565/- \n\tCost of package per child (age below 12): \t25,252/- ");
        break;
    case 21:
        printf("\n\t\tOOTY TRIP PACKAGE \n\n\tCity: \t\t\t\t\t\tOoty, Wayanad, Kodaikanal \n\tHighlights: \t\t\t\t\tOoty lake, Doddabetta Peak, Banasura Sagar Dam, Pookode Lake etc...  \n\tDuration: \t\t\t\t\t4 nights/ 5 days \n\tCost of package per Adult: \t\t\t38,751/- \n\tCost of package per child (age below 12): \t36,547/- ");
        break;
    case 22:
        printf("\n\t\tSHIMLA TRIP PACKAGE \n\n\tCity: \t\t\t\t\t\tShimla, Kulu, Manali, Solang Valley \n\tHighlights: \t\t\t\t\tKurfi, Mall Road, The Ridge, Chirst Church, Chadwick Falls, Indian Institute of Advanced Study etc... \n\tDuration: \t\t\t\t\t5 nights/ 6 days \n\tCost of package per Adult: \t\t\t50,000/- \n\tCost of package per child (age below 12): \t47,300/- ");
        break;
    case 23:
        printf("\n\t\tLAMBASINGI TRIP PACKAGE \n\n\tCity: \t\t\t\t\t\tLambasingi, Vizag \n\tHighlights: \t\t\t\t\tThajangi Reservoir, Susan Garden, Annavaram Temple, Ghat Road, Yerravaram Waterfalls, Kondakarla Bird Sanchuray etc... \n\tDuration: \t\t\t\t\t2 nights/ 3 days \n\tCost of package per Adult: \t\t\t20,899/- \n\tCost of package per child (age below 12): \t18,743/- ");
        break;
    case 24:
        printf("\n\t\tJOGIMATTI TRIP PACKAGE \n\n\tCity: \t\t\t\t\t\tChitradurga, Jogimatti \n\tHighlights: \t\t\t\t\tTungabhadra Dam, Bhadra Dam,Bannerghatta National Park, Bhadra Wildlife Sanctuary, Kollur Mookambika Temple \n\tDuration: \t\t\t\t\t3 nights/ 4 days \n\tCost of package per Adult: \t\t\t35,565/- \n\tCost of package per child (age below 12): \t33,736/- ");
        break;
    case 31:
        printf("\n\t\tVISHAKAPATNAM PACKAGE \n\n\tCity: \t\t\t\t\t\tBorra caves, dolphin hills \n\tHighlights: \t\t\t\t\tYarada beach, rushikonda beach, rama krishna beach, kailasgiri, simhachalam temple, katiki falls  etc...  \n\tDuration: \t\t\t\t\t4 nights/ 5 days \n\tCost of package per Adult: \t\t\t18,565/- \n\tCost of package per child (age below 12): \t15,252/- ");
        break;
    case 32:
        printf("\n\t\tGOA BEACH PACKAGE \n\n\tCity: \t\t\t\t\t\tPanaji, \n\tHighlights: \t\t\t\t\tbaga beach, calangute beach, tito's street, chapora fort, divar island, salim ali bird sanctuary etc...  \n\tDuration: \t\t\t\t\t4 nights/ 5 days \n\tCost of package per Adult: \t\t\t24,565/- \n\tCost of package per child (age below 12): \t15,252/- ");
        break;
    case 33:
        printf("\n\t\tTHIRUVANANTHAPURAM PACKAGE \n\n\tCity: \t\t\t\t\t\tThiruvananthapuram, kovalam \n\tHighlights: \t\t\t\t\tPadmanabhaswamy temple, Napier museum, Kowdiar Palace, Vellayani Lake, Malankara Church etc...  \n\tDuration: \t\t\t\t\t5 nights/ 6 days \n\tCost of package per Adult: \t\t\t36,565/- \n\tCost of package per child (age below 12): \t24,252/- ");
        break;
    case 34:
        printf("\n\t\tGOKARNA BEACH PACKAGE \n\n\tCity: \t\t\t\t\t\tGokarna, Honnemaradu \n\tHighlights: \t\t\t\t\tShri Mahabhaleshwara Swami Temple, Om Beach, Mirjan Fort, Half Moon Beach, Kudle Beach road etc...  \n\tDuration: \t\t\t\t\t3 nights/ 4 days \n\tCost of package per Adult: \t\t\t15,565/- \n\tCost of package per child (age below 12): \t12,252/- ");
        break;
    case 41:
        printf("\n\t\tVARANASI PILGRIMAGE PACKAGE \n\n\tCity: \t\t\t\t\t\tVaranasi, Gaya, Prayagraj \n\tHighlights: \t\t\t\t\tShri Kashi Vishwanath, Sarnathm, Vishnu Pad, Manngla Gauri, Bodhgaya, Triveni Sangam etc...  \n\tDuration: \t\t\t\t\t4 nights/ 5 days \n\tCost of package per Adult: \t\t\t22,565/- \n\tCost of package per child (age below 12): \t19,252/- ");
        break;
    case 42:
        printf("\n\t\tRAMESWARAM PILGRIMAGE PACKAGE \n\n\tCity: \t\t\t\t\t\tMadurai, Rameshwaram, Kanyakumari \n\tHighlights: \t\t\t\t\tRamanathaswamy Temple, Gandhamadhana Parvatham, Sri Kumariamman Temple, Vivekananda Rock Memorial etc... \n\tDuration: \t\t\t\t\t3 nights/ 4 days \n\tCost of package per Adult: \t\t\t18,565/- \n\tCost of package per child (age below 12): \t15,252/- ");
        break;
    case 43:
        printf("\n\t\tUJJAIN PILGRIMAGE PACKAGE \n\n\tCity: \t\t\t\t\t\tIndore, Ujjain, Mandu \n\tHighlights: \t\t\t\t\tMahakaleshwar, Sandipani Ashram, Jahaz Mahal, Kal Bhairav etc... \n\tDuration: \t\t\t\t\t3 nights/ 4 days \n\tCost of package per Adult: \t\t\t30,068/- \n\tCost of package per child (age below 12): \t27,345/- ");
        break;
    case 44:
        printf("\n\t\tTIRUPATI PILGRIAGE PACKAGE \n\n\tCity: \t\t\t\t\t\tTirupati \n\tHighlights: \t\t\t\t\tVenkateswara Temple, Tirumala \n\tDuration: \t\t\t\t\t2 nights/ 3 days \n\tCost of package per Adult: \t\t\t12,999/- \n\tCost of package per child (age below 12): \t9,999/- ");
        break;
    default:
        break;
    }
    printf("\n\tFurther Details will be shared by your respective customer care support member through mail");
    printf("\n\n Press any key to confirm booking");
    getche();
    Bulk_Plan_Booking(data);
}
// function to calculate the price based on destination and number of travelers
int Calculate_Price(char *destination, int num_adults, int num_children)
{
    int price = 5000;
    if (strcmp(destination, "ChitrakootWaterfall") != 0)
    {
        price += num_adults * 20565 + num_children * 18252;
    }
    else if (strcmp(destination, "MeenmuttyFalls") != 0)
    {
        price += num_adults * 22565 + num_children * 20252;
    }
    else if (strcmp(destination, "DudhsagarFalls") != 0)
    {
        price += num_adults * 10565 + num_children * 8252;
    }
    else if (strcmp(destination, "VajraiFalls") != 0)
    {
        price += num_adults * 28565 + num_children * 25252;
    }
    else if (strcmp(destination, "Ooty") != 0)
    {
        price += num_adults * 38751 + num_children * 36547;
    }
    else if (strcmp(destination, "Shimla") != 0)
    {
        price += num_adults * 50000 + num_children * 47300;
    }
    else if (strcmp(destination, "Lambasingi") != 0)
    {
        price += num_adults * 20899 + num_children * 18743;
    }
    else if (strcmp(destination, "Jogimatti") != 0)
    {
        price += num_adults * 35565 + num_children * 33736;
    }
    else if (strcmp(destination, "Visakhapatnam") != 0)
    {
        price += num_adults * 18565 + num_children * 15252;
    }
    else if (strcmp(destination, "Panaji") != 0)
    {
        price += num_adults * 24565 + num_children * 15252;
    }
    else if (strcmp(destination, "Trivandrum") != 0)
    {
        price += num_adults * 36565 + num_children * 24252;
    }
    else if (strcmp(destination, "Gokarna") != 0)
    {
        price += num_adults * 15565 + num_children * 12252;
    }
    else if (strcmp(destination, "Varanasi") != 0)
    {
        price += num_adults * 22565 + num_children * 19252;
    }
    else if (strcmp(destination, "Rameswaram") != 0)
    {
        price += num_adults * 18565 + num_children * 15252;
    }
    else if (strcmp(destination, "Ujjain") != 0)
    {
        price += num_adults * 30068 + num_children * 27345;
    }
    else if (strcmp(destination, "Tirupati") != 0)
    {
        price += num_adults * 12999 + num_children * 9999;
    }
    return price;
}

// function to book a  bulk tour
int Bulk_Plan_Booking(User_Info *data2)
{
    FILE *fp;
    fp = fopen("User_Information.txt", "r+");
    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return -1;
    }
    User_Info *t = data2;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, Current_User))
        {
            int adult_f = 0, child_f = 0, adult, child, price;
            printf("\nWelcome to Bulk Plan Booking section");
            printf("\n\tHow many adults will be travelling?");
            scanf("%d", &adult);
            if (adult > 0)
            {
                adult_f += adult;
            }
            printf("\n\tHow many children will be travelling?");
            scanf("%d", &child);
            if (child > 0)
            {
                child_f += child;
            }
            price = Calculate_Price(t->destination, adult_f, child_f);
            t->Price = price;
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
            break;
        }
        t = t->next;
    }
    fclose(fp);
    BulkPlan_View_Ticket(data);
}
void BulkPlan_View_Ticket(User_Info *data2)
{
    FILE *fp;
    fp = fopen("User_Information.txt", "r");
    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return;
    }
    User_Info temp;
    int found = 0;
    while (fscanf(fp, "%s %s %s %d %s %s %s %s %s %d %s", temp.User_Name, temp.Password, temp.destination, &temp.Price, temp.Mode_Of_Plan, temp.Mode_Of_Transport, temp.Car_Model, temp.Train_Model, temp.Bus_Model, &temp.Room_Number, temp.Hotel_Name) != EOF)
    {
        if (!strcmp(temp.User_Name, Current_User))
        {
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("No such user exists\n");
        fclose(fp);
        return;
    }
    if (!strcmp(temp.destination, "N/A") || temp.Price == 0)
    {
        printf("You do not have a ticket booked yet\n");
        fclose(fp);
        return;
    }
    printf("\n\tYou have booked tickets for %s with a total price %d", temp.destination, temp.Price);
    printf("\nYour booking confirmation will be shared by your respective customer care support member through mail");
    printf("\nDetailed information about tickets of mode of transport and hotel booking will be shared by customer care member through mail");
    printf("\nContact customer care support for any queries");
    system("PAUSE");
    fclose(fp);
    Exit_Program();
}
// function for individual planning
int Individual_Plan(User_Info *data2)
{
    FILE *fp;
    fp = fopen("User_Information.txt", "r+");
    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return -1;
    }
    User_Info *t = data2;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, Current_User))
        {
            int a, train_choice, bus_choice;
            printf("\n\tWe are Directing to Select Mode of Travel ");
            printf("\n\tPress any key to continue");
            getche();
            printf("\n\n");
            printf("\n\t ** Welcome to ASH Ticket Individual Plan Booking Service **");
            printf("\n\tHow Would you like to travel ? ");
            printf("\n\t Hit 1 to go by train");
            printf("\n\t Hit 2 to go by Car");
            printf("\n\t Hit 3 to go by Bus");
            printf("\n\t Enter : ");
            scanf("%d", &a);
            switch (a)
            {
            case 1:
                strcpy(t->Mode_Of_Transport, "Train");
                printf("We are Directing to Train Display Section");
                printf("\n\tPress any key to continue");
                getche();
                Trains_Display(data);
                break;
            case 2:
                strcpy(t->Mode_Of_Transport, "Car");
                printf("We are Directing to Car Selection Section");
                printf("\n\tPress any key to continue");
                getche();
                Cars_Display(data);
                Car_Rental();
                break;
            case 3:
                strcpy(t->Mode_Of_Transport, "Bus");
                printf("We are Directing to Bus Display Section");
                printf("\n\tPress any key to continue");
                getche();
                Buses_Display(data);
                break;
            default:
                Individual_Plan(data);
                break;
            }
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
            break;
        }
        t = t->next;
    }
    fclose(fp);
}
// Function to display trains
int Trains_Display(User_Info *data2)
{
    FILE *fp;
    fp = fopen("User_Information.txt", "r+");
    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return -1;
    }
    User_Info *t = data2;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, Current_User))
        {
            struct Train
            {
                const char *name;
            };
            struct Train Trains[500] = {
                {"Empty"},
                {"DurontoExpress(12245)"},
                {"ANGAEXPRESS(12254)"},
                {"HAMSAFAREXPRESS(22833)"},
                {"PRASANTIEXPRESS(18463)"},
                {"SMVTBengaluru(12510)"}};
            int choice;
            printf("\n\n\t\t TRAINS AVAILABLE : ");
            printf("\n\n\t   1.Duronto Express(12245)               Departure:6:00AM     Price:3564RS");
            printf("\n\t   2.ANGA EXPRESS(12254)                  Departure:4:00PM     Price:2899RS");
            printf("\n\t   3.HAMSAFAR EXPRESS(22833)              Departure:3:30PM     Price:3200RS");
            printf("\n\t   4.PRASANTI EXPRESS(18463)              Departure:9:45AM     Price:3000RS");
            printf("\n\t   5.SMVT Bengaluru (12510)               Departure:8:05AM     Price:2400RS");
            printf("\n\n\t enter your choice : ");
            scanf("%d", &choice);
            char train_name[50];
            strcpy(train_name, Trains[choice].name);
            strcpy(t->Train_Model, train_name);
            Train_Cost = Train_Booking(choice);
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
            break;
        }
        t = t->next;
    }
    fclose(fp);
    printf("\nWe are Directing to Hotels Display Selection Section");
    printf("\n\tPress any key to continue");
    getche();
    printf("\n\n");
    printf("\n\t ** Welcome to ASH Hotel Booking Service **");
    Hotel_Final_Choice = Hotels_Display(data);
    printf("\n We are directing to Hotel Booking Section");
    getche();
    Hotel_Booking();
}
// Function to book train
int Train_Booking(int choice)
{
    int no_of_tickets, train_cost = 0;
    int train_costs[] = {0, 3564, 2899, 3200, 3000, 2400};
    printf("\n\tEnter Number of Tickets would you like to book: ");
    scanf("%d", &no_of_tickets);
    if (no_of_tickets <= 0)
    {
        printf("Invalid input. Please enter a positive integer.");
        return -1;
    }
    train_cost = no_of_tickets * train_costs[choice];
    printf("Cost is %d ", train_cost);
    return train_cost;
    printf("Cost is %d ", train_cost);
    return train_cost;
}
// function to display buses
int Buses_Display(User_Info *data2)
{
    FILE *fp;
    fp = fopen("User_Information.txt", "r+");
    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return -1;
    }
    User_Info *t = data2;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, Current_User))
        {
            struct Bus
            {
                const char *name;
            };
            struct Bus Buses[500] = {
                {"Empty"},
                {"OrangeToursandTravels"},
                {"IntrCitySmartBus"},
                {"KKTravels"},
                {"SreeMadhaviTravels"},
                {"RSTravels"}};
            int choice;
            printf("\n\n\t\t BUSES AVAILABLE : ");
            printf("\n\n\t\t  1.Orange Tours and Travels       Departure:22:00         Price:1419RS");
            printf("\n\t\t  2.IntrCity SmartBus              Departure:23:55         Price:1048RS");
            printf("\n\t\t  3.KK Travels                     Departure:21:30         Price:1800RS");
            printf("\n\t\t  4.Sree Madhavi Travels           Departure:9:45AM        Price:2145RS");
            printf("\n\t\t  5.RS Travels                     Departure:8:05AM        Price:1299RS");
            printf("\n\n\t enter your choice : ");
            scanf("%d", &choice);
            char bus_name[50];
            strcpy(bus_name, Buses[choice].name);
            strcpy(data2->Bus_Model, bus_name);
            Bus_Cost = Bus_Booking(choice);
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
            break;
        }
        data2 = data2->next;
    }
    fclose(fp);
    printf("\nWe are Directing to Hotels Display Selection Section");
    printf("\n\tPress any key to continue");
    getche();
    printf("\n\n");
    printf("\n\t ** Welcome to ASH Hotel Booking Service **");
    int c = Hotels_Display(data);
    Hotel_Final_Choice += c;
    printf("\n We are directing to Hotel Booking Section");
    getche();
    Hotel_Booking();
}
// function to book buses
int Bus_Booking(int choice)
{
    int no_of_tickets, bus_cost = 0;
    int bus_costs[] = {0, 1419, 1048, 1800, 2145, 1299};
    printf("\n\tEnter Number of Tickets would you like to book: ");
    scanf("%d", &no_of_tickets);
    if (no_of_tickets <= 0)
    {
        printf("Invalid input. Please enter a positive integer.");
        return -1;
    }
    bus_cost = no_of_tickets * bus_costs[choice];
    printf("Cost is %d ", bus_cost);
    return bus_cost;
}
// function to display cars
void Cars_Display(User_Info *data2)
{
    FILE *fp;
    fp = fopen("User_Information.txt", "r+");
    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return;
    }
    User_Info *t = data2;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, Current_User))
        {
            struct Car
            {
                const char *name;
            };
            struct Car Cars[500] = {
                {"Empty"},
                {"Hyundai"},
                {"Suzuki"},
                {"Honda"},
                {"Toyota"},
                {"Ford"}};
            int serial_no;
            printf("\n\t Here are details of available cars");
            printf("\n");
            printf(" Serial    CAR BRAND      MODEL    RENT PER DAY(Php)   \n");
            printf(" \n");
            printf("1           HYUNDAI      Veloster       6000           \n");
            printf("2           SUZUKI       Celerio        2000           \n");
            printf("3           HONDA        Civic          5000           \n");
            printf("4           TOYOTA       Avalon         4000           \n");
            printf("5           FORD        Explorer        8000           \n");
            printf("Enter Serial Number of car you want to rent: ");
            scanf("%d", &serial_no);
            char car_name[50];
            strcpy(car_name, Cars[serial_no].name);
            strcpy(data2->Car_Model, car_name);
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
            printf("\nWe are Directing to Car Rental Section");
            printf("\n\tPress any key to continue");
            getche();
            Car_Rental();
            Car_Cost = Car_Rental_Cost(serial_no);
            break;
        }
        t = t->next;
    }
    fclose(fp);
    printf("\nWe are Directing to Hotels Display Selection Section");
    printf("\n\tPress any key to continue");
    getche();
    printf("\n\n");
    printf("\n\t ** Welcome to ASH Hotel Booking Service **");
    Hotel_Final_Choice = Hotels_Display(data);
    printf("\n We are directing to Hotel Booking Section");
    getche();
    Hotel_Booking();
}
// function to rent a car
int Car_Rental()
{
    int j, x, u = 0, z = 0, count = 0;
    int dr, mr, yr;
    char ch;
    printf("Enter the Brand Of Car you want to Rent : ");
    scanf("%s", ca[u].carrented);
    printf("Enter Date on which you will take the CAR(dd mm yyyy): ");
    scanf("%d%d%d", &dr, &mr, &yr);
    ca[u].dr = dr;
    ca[u].mr = mr;
    ca[u].yr = yr;
    printf("CAR AVAILABLE!! \n");
    FILE *fp;
    fp = fopen("Car_rent.txt", "a");
    if (fp == NULL)
    {
        printf("Error in opening file");
        return 1;
    }
    fwrite(&ca[u], sizeof(struct Car), 1, fp);
    fclose(fp);
    printf("ENTER YOUR NAME: ");
    scanf("%s", cr[z].customername);
    printf("ENTER YOUR ID NUMBER(registered username): ");
    scanf("%s", cr[z].customerId);

    for (j = 0; j < MAX_CARS; j++)
    {
        if (strcmp(ca[j].carrented, ca[u].carrented) == 0)
        {
            break;
        }
    }
    if (j == MAX_CARS)
    {
        printf("Car brand not found\n");
        return 1;
    }
    printf("\n\nWARNING: If any damage is done to the car then you are entirely responsible. The car has to be returned in its initial condition.\n");
    printf("\n\tDetails:\n");
    printf("NAME:\t%s\nID:\t%s\nCAR RENTED:\t%s", cr[z].customername, cr[z].customerId, ca[u].carrented);

    strcpy(cr[z].carrented, ca[u].carrented);
    FILE *fptr;
    fptr = fopen("Car_rent.txt", "a+");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fwrite(&cr[z], sizeof(struct Customer_Car), 1, fptr);
    fclose(fptr);
    return 1;
}
// function to cost car rental cost
int Car_Rental_Cost(int serial_number)
{
    int car_rental_cost = 0, no_of_days;
    int car_costs[] = {0, 6000, 2000, 5000, 4000, 8000};
    printf("\n How many days would you like to rent a car: ");
    scanf("%d", &no_of_days);
    if (no_of_days <= 0)
    {
        printf("Invalid input. Please enter a positive integer.");
        return -1;
    }
    car_rental_cost = car_costs[serial_number] * no_of_days;
    printf("Total cost is %d", car_rental_cost);
    return car_rental_cost;
}
// function to display hotels
int Hotels_Display(User_Info *data2)
{
    FILE *fp;
    fp = fopen("User_Information.txt", "r+");
    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return -1;
    }
    int Hotel_Choice;
    User_Info *t = data2;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, Current_User))
        {
            struct Hotel
            {
                const char *name;
            };
            struct Hotel Hotels[500] = {
                {"Empty"},
                {"SterlingMussoorie"},
                {"HotelGem"},
                {"StarResidency"},
                {"FeelHomeResidency"},
                {"HotelRanging"}};
            printf("\n\t\t\t\tAVAILABLE HOTELS ARE:");
            printf("\n\n\t1. Sterling Mussoorie \t\t\tPrice per room per night : 5,000/-");
            printf("\n\t2. Hotel Gem \t\t\t\tPrice per room per night : 4,500/-");
            printf("\n\t3. Star Residency \t\t\tPrice per room per night : 4,000/-");
            printf("\n\t4. Feel Home Residency \t\t\tPrice per room per night : 3,000/-");
            printf("\n\t5. Hotel Ranging \t\t\tPrice per room per night : 2,750/-");
            printf("\n\nEach Room accomodates 2 adults and 1 child ");
            printf("\n\nEnter the number to choose the hotel :");
            scanf("%d", &Hotel_Choice);
            char hotel_name[50];
            strcpy(hotel_name, Hotels[Hotel_Choice].name);
            strcpy(data2->Hotel_Name, hotel_name);
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
            break;
        }
        data2 = data2->next;
    }
    fclose(fp);
    return Hotel_Choice;
}
// function to display options in hotel booking
int Hotel_Booking()
{
    int Hotel_Booking_Choice, Hotel_Booking_Value;
    printf("\n\t\tPlease enter your choice for menu:");
    printf("\n\n\t Enter 1 -> Book a Room");
    printf("\n\t Enter 2 -> View Customer Record");
    printf("\n\t\t Enter : ");
    scanf("%d", &Hotel_Booking_Choice);
    system("CLS");
    switch (Hotel_Booking_Choice)
    {
    case 1:
        Hotel_Booking_Value = Hotel_Book_Room(data);
        Hotel_Cost = Hotel_Booking_Cost(Hotel_Final_Choice, Hotel_Booking_Value);
        Total_Bill = Final_Bill(Train_Cost, Bus_Cost, Car_Cost, Hotel_Cost, data);
        Print_Ticket(Total_Bill, data);
        break;
    case 2:
        Hotel_Display_Booking();
        break;
    default:
        Hotel_Booking();
        break;
    }
    return Hotel_Booking_Value;
}
// function to check whether phone number entered is valid or not
int Check_Phone_Number(char *Number)
{
    if (strlen(Number) != 10)
    {
        return 0;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!isdigit(Number[i]))
        {
            return 0;
        }
    }
    return 1;
}
// function to check whether input date is valid or not
int Check_Date(char *Date)
{
    int Day, Month, Year;
    if (sscanf(Date, "%d\\%d\\%d", &Day, &Month, &Year) != 3)
    {
        return 0;
    }
    if (Day < 1 || Day > 31 || Month < 1 || Month > 12 || Year < 1900 || Year > 2100)
    {
        return 0;
    }
    return 1;
}
// function to book a hotel room
int Hotel_Book_Room(User_Info *data2)
{
    User_Info *t = data2;
    while (data2 != NULL)
    {
        if (!strcmp(data2->User_Name, Current_User))
            break;
        data2 = data2->next;
    }
    if (data2 == NULL)
        return 1;
    int days, count = 1, room_no, final;
    FILE *fp;
    char test;
    fp = fopen("HotelBooking.txt", "a+");
    if (fp == 0)
    {
        fp = fopen("HotelBooking.txt", "w+");
        system("cls");
        printf("Please wait while we set !!");
        printf("\n Process completed press any key to continue!! ");
        getch();
    }
    while (1)
    {
        system("cls");
        printf("\n Enter Customer Details:");
        while (1)
        {
            printf("\n Enter Room number(only positive number excluding 0 in range of 1 to 1000):\n");
            scanf("\n%d", &room_no);
            hc.Room_Number = room_no;
            if (hc.Room_Number > 0 && hc.Room_Number < 1001)
            {
                data2->Room_Number = hc.Room_Number;
                break;
            }
            else
            {
                printf("Enter Valid Room Number");
                continue;
            }
        }
        fflush(stdin);
        printf("Enter Name:\n");
        scanf("%s", hc.Name);
        fflush(stdin);
        printf("Enter Address:\n");
        scanf("%s", hc.Address);
        fflush(stdin);
        while (1)
        {
            printf("Enter Phone Number:\n");
            scanf("%s", hc.Phone_Number);
            fflush(stdin);
            if (!Check_Phone_Number(hc.Phone_Number))
            {
                printf("Please enter a 10-digit phone number.\n");
                continue;
            }
            else
            {
                break;
            }
        }
        printf("Enter Period(\'x\'days):\n");
        scanf("%d", &hc.Period);
        days = (int)hc.Period;
        fflush(stdin);
        while (1)
        {
            printf("Enter Arrival date(dd\\mm\\yyyy):\n");
            scanf("%s", &hc.Arrival_Date);
            if (!Check_Date(hc.Arrival_Date))
            {
                printf("Please enter a valid date in the format dd\\mm\\yyyy.\n");
                continue;
            }
            else
            {
                break;
            }
        }
        fwrite(&hc, sizeof(hc), 1, fp);
        fflush(stdin);
        system("PAUSE");
        printf("\n\n  Room is successfully booked!!");
        Hotel_Display_Booking();
        printf("\n Press esc key to exit,  any other key to add another customer detail:");
        // count is used to find number of bookings made
        test = getche(); // defined in conio.h
        if (test == 27)
        {
            break;
        }
        else
        {
            count += 1;
            continue;
        }
    }
    Add_List(t);
    data2 = data2->next;
    fclose(fp);
    final = days * count;
    return final;
}
// function to display hotel booking
void Hotel_Display_Booking()
{
    FILE *fp;
    int i;
    if ((fp = fopen("HotelBooking.txt", "r")) == NULL)
    {
        perror("Error opening file");
        return;
    }
    system("cls");
    printf("Room :%d\t\tName :%s\t\tAddress:%s\t\tPhoneNumber:%s\t\tPeriod : %d\t\tArrivalDate: %s\n", hc.Room_Number, hc.Name, hc.Address, hc.Phone_Number, hc.Period, hc.Arrival_Date);
    fclose(fp);
    printf("\nPress any key to continue");
    getche();
}
// function for final booking cost
int Hotel_Booking_Cost(int Hotel_Choice, int final)
{
    const int Hotel_Costs[] = {0, 5000, 4500, 4000, 3000, 2750};
    if (Hotel_Choice < 1 || Hotel_Choice > 6)
    {
        return 0;
    }
    return final * Hotel_Costs[Hotel_Choice];
}
// function to calculate final bill
int Final_Bill(int Train_Cost, int Bus_Cost, int Car_Cost, int Hotel_Cost, User_Info *data2)
{
    FILE *fp;
    fp = fopen("User_Information.txt", "r+");
    if (fp == NULL)
    {
        printf("Error: could not open file\n");
        return -1;
    }
    User_Info *t = data2;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, Current_User))
        {
            const int Fixed_Cost = 10000;
            int Total_Bill = Train_Cost + Bus_Cost + Car_Cost + Hotel_Cost + 10000;
            t->Price = Total_Bill;
            fprintf(fp, "%s %s %s %d %s %s %s %s %s %d %s", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
            break;
        }
        data2 = data2->next;
    }
    fclose(fp);
    return Total_Bill;
}
// final ticket statement
void Print_Ticket(int F_bill, User_Info *data2)
{
    Update_File(data);
    User_Info *user = NULL;
    for (User_Info *current = data2; current != NULL; current = current->next)
    {
        if (!strcmp(current->User_Name, Current_User))
        {
            user = current;
            break;
        }
    }

    if (user == NULL)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    FILE *fp;
    fp = fopen("User_Information.txt", "r");
    if (fp == NULL)
    {
        printf("Problem opening the File\n");
        return;
    }
    printf("\n\n\t\t\tYour Ticket Statement is ");
    printf("\n\tYou have booked tickets for your destination %s", user->destination);
    if (Train_Cost == 0 && Bus_Cost == 0 && Car_Cost != 0)
    {
        printf("\n\tYou Booked %s with model %s ", user->Mode_Of_Transport, user->Car_Model);
        printf("\n\tTotal Cost for Car Rental is %d ", Car_Cost);
        printf("\n\tYou Booked hotel %s with room number %d ", user->Hotel_Name, user->Room_Number);
        printf("\n\tTotal Cost for Hotel Booking is %d ", Hotel_Cost);
        printf("\n\tTotal Cost for Final Bill is %d ", user->Price);
    }
    else if (Train_Cost != 0 && Bus_Cost == 0 && Car_Cost == 0)
    {
        printf("\n\tYou Booked %s with model %s ", user->Mode_Of_Transport, user->Train_Model);
        printf("\n\tTotal Cost for Train Tickets is %d ", Train_Cost);
        printf("\n\tYou Booked hotel %s with room number %d ", user->Hotel_Name, user->Room_Number);
        printf("\n\tTotal Cost for Hotel Booking is %d ", Hotel_Cost);
        printf("\n\tTotal Cost for Final Bill is %d ", user->Price);
    }
    else
    {
        printf("\n\tYou Booked %s with model %s ", user->Mode_Of_Transport, user->Bus_Model);
        printf("\n\tTotal Cost for Bus Tickets is %d ", Bus_Cost);
        printf("\n\tYou Booked hotel %s with room number %d ", user->Hotel_Name, user->Room_Number);
        printf("\n\tTotal Cost for Hotel Booking is %d ", Hotel_Cost);
        printf("\n\tTotal Cost for Final Bill is %d ", user->Price);
    }
    printf("\n\n\t *****THANK YOU*****");
    printf("\n\t FOR TRUSTING OUR SERVICE");
    exit(0);
}
// function for viewing ticket
void IndividualPlan_View_Ticket(User_Info *data2)
{
    printf("\n\t ** Welcome to ASH Ticket Displaying Service **");
    char username[100];
    printf("\n\t\tPlease enter your registered username: ");
    scanf("%s", username);
    FILE *fp;
    fp = fopen("Individual_User.txt", "r");
    if (fp == NULL)
    {
        printf("Problem opening the File\n");
        return;
    }
    User_Info user;
    int found = 0;
    while (fscanf(fp, "%s %s %s %d %s %s %s %s %s %d %s", user.User_Name, user.Password, user.destination, &user.Price, user.Mode_Of_Plan, user.Mode_Of_Transport, user.Car_Model, user.Train_Model, user.Bus_Model, &user.Room_Number, user.Hotel_Name) != EOF)
    {
        if (!strcmp(user.User_Name, username))
        {
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found)
    {
        printf("No such user exists\n");
        fclose(fp);
        return;
    }
    if (!strcmp(user.destination, "\0") || user.Price == 0)
    {
        printf("You do not have a ticket booked yet\n");
        fclose(fp);
        return;
    }
    if (strcmp(user.Mode_Of_Transport, "Train") == 0)
        printf("\nYou have booked tickets for %s with a total cost of %d via %s and stay at room number %d in hotel %s", user.destination, user.Price, user.Mode_Of_Transport, user.Room_Number, user.Hotel_Name);
    else if (strcmp(user.Mode_Of_Transport, "Bus") == 0)
        printf("\nYou have booked tickets for %s with a total cost of %d via %s and stay at room number %d in hotel %s", user.destination, user.Price, user.Mode_Of_Transport, user.Room_Number, user.Hotel_Name);
    else if (strcmp(user.Mode_Of_Transport, "Car") == 0)
        printf("\nYou have booked tickets for %s with a total cost of %d via %s and stay at room number %d in hotel %s", user.destination, user.Price, user.Mode_Of_Transport, user.Room_Number, user.Hotel_Name);
    else
    {
        printf("\n\t\tThank YOU");
    }
}
// function to cancel ticket
void Cancel_Ticket(User_Info *data2)
{
    printf("\n\t ** Welcome to ASH Ticket Cancellation Service **");
    char username[100];
    printf("\n\t\tPlease enter your registered username: ");
    scanf("%s", username);
    FILE *fptr, *fp;
    fptr = fopen("User_Information.txt", "r");
    if (fptr == NULL)
    {
        printf("Problem opening the File\n");
        return;
    }
    User_Info *t = malloc(sizeof(User_Info));
    if (t == NULL)
    {
        printf("Error: could not allocate memory\n");
        fclose(fptr);
        return;
    }
    while (fscanf(fptr, "%s %s %s %d %s %s %s %s %s %d %s", t->User_Name, t->Password, t->destination, &t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, &t->Room_Number, t->Hotel_Name) != EOF)
    {
        if (strcmp(t->Mode_Of_Plan, "B") == 0)
        {
            fp = fopen("User_Information.txt", "r+");
        }
        else if (strcmp(t->Mode_Of_Plan, "I") == 0)
        {
            fp = fopen("Individual_User.txt", "r+");
        }
        else
        {
            printf("Invalid mode of plan");
            fclose(fptr);
            return;
        }
        t = t->next;
    }
    if (fp == NULL)
    {
        printf("Problem opening the File\n");
        fclose(fp);
        return;
    }
    User_Info user;
    int found = 0, match = 0;
    while (fscanf(fp, "%s %s %s %d %s %s %s %s %s %d %s", user.User_Name, user.Password, user.destination, &user.Price, user.Mode_Of_Plan, user.Mode_Of_Transport, user.Car_Model, user.Train_Model, user.Bus_Model, &user.Room_Number, user.Hotel_Name) != EOF)
    {
        if (!strcmp(user.User_Name, username))
        {
            found = 1;
            if (strcmp(user.destination, "N/A") == 0 || user.Price == 0)
            {
                printf("You do not have a ticket booked yet\n");
                fclose(fp);
                Main_Menu(Current_Status);
                return;
            }
            int flag = 0;
            const char *Destinations[] = {
                "ChitrakootWaterfall",
                "MeenmuttyFalls",
                "DudhsagarFalls",
                "VajraiFalls",
                "Ooty",
                "Shimla",
                "Lambasingi",
                "Jogimatti",
                "Visakhapatnam",
                "Panaji",
                "Trivandrum",
                "Gokarna",
                "Varanasi",
                "Rameswaram",
                "Ujjain",
                "Tirupati"};
            int Num_Destinations = sizeof(Destinations) / sizeof(Destinations[0]);
            for (int i = 0; i < Num_Destinations; i++)
            {
                if (!strcmp(user.destination, Destinations[i]))
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                printf("You haven't booked a tour yet\n");
                fclose(fp);
                free(t);
                Main_Menu(Current_Status);
                return;
            }
            printf("Your ticket has been successfully cancelled\nA refund of Rs %d for your Destination %s will soon be made to your original source of purchase\n", user.Price, user.destination);
            strncpy(user.destination, "N/A", sizeof(user.destination));
            strcpy(user.Mode_Of_Plan, "N/A");
            strcpy(user.Mode_Of_Transport, "N/A");
            strcpy(user.Car_Model, "N/A");
            strcpy(user.Train_Model, "N/A");
            strcpy(user.Bus_Model, "N/A");
            strcpy(user.Hotel_Name, "N/A");
            user.Price = 0;
            user.Room_Number = 0;
            fseek(fptr, -sizeof(User_Info), SEEK_CUR);
            fprintf(fptr, "%s %s %s %d %s %s %s %s %s %d %s\n", user.User_Name, user.Password, user.destination, user.Price, user.Mode_Of_Plan, user.Mode_Of_Transport, user.Car_Model, user.Train_Model, user.Bus_Model, user.Room_Number, user.Hotel_Name);
            match = 1;
        }
    }
    if (!found)
    {
        printf("No such user exists\n");
        fclose(fptr);
        return;
    }
    if (!match)
    {
        printf("No ticket found for user %s\n", username);
    }
    fclose(fp);
}
// To update data from one file to other
void Update_File(User_Info *data2)
{
    FILE *fp;
    fp = fopen("User_Information.txt", "r");

    if (fp == NULL)
    {
        printf("\n\tError: could not open file\n");
        return;
    }
    User_Info *t = data2;
    FILE *fpw;
    fpw = fopen("Individual_User.txt", "w");
    if (fpw == NULL)
    {
        printf("Error: could not open file\n");
        fclose(fp);
        return;
    }
    t = data2;
    while (t != NULL)
    {
        if (!strcmp(t->User_Name, Current_User))
        {
            fprintf(fpw, "%s %s %s %d %s %s %s %s %s %d %s\n", t->User_Name, t->Password, t->destination, t->Price, t->Mode_Of_Plan, t->Mode_Of_Transport, t->Car_Model, t->Train_Model, t->Bus_Model, t->Room_Number, t->Hotel_Name);
        }
        t = t->next;
    }
    fclose(fpw);
    fclose(fp);
}