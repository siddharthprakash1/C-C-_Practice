#include <stdio.h>
#include <conio.h>
#include <windows.h>

int getkey();
void display(int, int, int, int[]);
void calendar(int, int);
void getAndPopulateReminders();
void storeReminders();
void addReminder();
void displayReminders(int);
int dateMatchedInReminders(int, int, int);

//---------------- Structures ----------------

typedef struct
{
    int day;
    int month;
    int year;
    char message[100];
} Reminder;

//-------------- GOTO function definition ----------------------
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//------------ Change color -------------------
void SetColor(int ForgC)
{
    WORD wColor; // We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi; // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char *week[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

Reminder Reminders[500];
int totalReminders = 0;

int main()
{
    getAndPopulateReminders();
    int nmonth, nyr, ch;
enteryear:
    while (1)
    {
        printf("Enter year and month(number):");
        scanf("%d%d", &nyr, &nmonth);
        if (nyr < 1945)
        {
            // If year less than 1945
            printf("\n\t Please enter year above 1945\n");
            continue;
        }
        else
        {
            // If year greater than equal to 1945
            calendar(nyr, nmonth);
        }
        while (1)
        {
            gotoxy(20, 20);
            printf("(*) Use LEFT, RIGHT, UP and DOWN arrow.");
            gotoxy(20, 22);
            printf("(*) Press P to go to particular year and month.");
            gotoxy(20, 24);
            printf("(*) Press A to add a reminder.");
            gotoxy(20, 26);
            printf("(*) Press R to display all reminders.");
            gotoxy(20, 28);
            printf("(*) Press C to go back.");
            gotoxy(20, 30);
            printf("(*) Press ESC to Exit.");
            ch = getkey();
            switch (ch)
            {
            case 80: //-------- DOWN ARROW -----------
                     // Increasing month
                if (nmonth == 12)
                {
                    // Jump to next year if month is december
                    nmonth = 1;
                    nyr++;
                }
                else
                {
                    nmonth++;
                }
                calendar(nyr, nmonth);
                break;
            case 77: //-------- RIGHT ARROW ----------
                     // Increasing Year
                nyr++;
                calendar(nyr, nmonth);
                break;
            case 72: //------- UP ARROW -------------
                     // Decreasing Month
                if (nmonth == 1)
                {
                    // Jump to previous year if month is january
                    nyr--;
                    nmonth = 12;
                }
                else
                    nmonth--;
                calendar(nyr, nmonth);
                break;
            case 75: //-------- LEFT ARROW ----------
                     // Decreasing year
                if (nyr == 1945)
                {
                    // If year is 1945 and we click left arrow than
                    gotoxy(15, 2);
                    printf("Year below 1945 not available");
                }
                else
                {
                    nyr--;
                    calendar(nyr, nmonth);
                }

                break;
            case 27: //--------- ESC KEY ------------
                     // Exit program
                system("cls");
                gotoxy(50, 14);
                printf("Exiting program.\n\n\n\n\n");
                exit(0);
            case 112: //---------- p KEY ------------
                      // Go to particular year and month
                system("cls");
                goto enteryear;

            case 114: //---------- r KEY ------------
                      // Display all reminders
                system("cls");
                displayReminders(totalReminders);
                break;
            case 97: //---------- a KEY ------------
                system("cls");
                addReminder();
                storeReminders();
                system("cls");
                calendar(nyr, nmonth);
                break;
            case 99: //---------- c KEY ------------
                system("cls");
                calendar(nyr, nmonth);
                break;
                // default:
                //     printf("Key pressed %d\n", ch);
            }
        }
        break;
    }
    getch();
    return 0;
}

//============== DISPLAYING THE  CALENDAR ===================
void display(int nyr, int nmonth, int tdays, int days[])
{
    int i, j, pos;
    SetColor(12); // Color red
    gotoxy(56, 6);
    printf("%s %d", month[nmonth - 1], nyr); // Heading year and month dispalying
    for (i = 0, pos = 30; i < 7; i++, pos += 10)
    {
        if (i == 6)
            SetColor(9); // Sunday color blue
        else
            SetColor(14); // Other days color green
        gotoxy(pos, 8);
        printf("%s", week[i]);
    }

    SetColor(15); // setting the color white

    tdays++; // incrementing the tdays by 1
    if (tdays == 0 || tdays == 7)
        pos = 91; // if tdays is 0 or 7, position is sunday
    if (tdays == 1)
        pos = 31; // if tdays is 1, position is monday
    if (tdays == 2)
        pos = 41; // if tdays is 2, position is tuesday
    if (tdays == 3)
        pos = 51; // if tdays is 3, position is wednesday
    if (tdays == 4)
        pos = 61; // if tdays is 4, position is thursday
    if (tdays == 5)
        pos = 71; // if tdays is 5, position is friday
    if (tdays == 6)
        pos = 81; // if tdays is 6, position is saturday

    int reminderPosY = 5;
    int reminderPosX = 105;
    for (i = 0, j = 10, pos; i < days[nmonth - 1]; i++, pos += 10)
    {
        if (pos == 91)
            SetColor(8); // Changing color to dark grey for sunday
        else
            SetColor(7); // Changing color to white for all days

        gotoxy(pos, j);

        int dateMatched = dateMatchedInReminders(i + 1, nmonth, nyr);
        if (dateMatched != -1)
        {
            // Changing color to green for matched dates
            SetColor(10);
            printf("%d", i + 1);
            gotoxy(reminderPosX, reminderPosY);

            // green
            SetColor(10);
            printf("%d - ", i + 1);
            fflush(stdout);

            // white
            SetColor(7);
            printf("%s", Reminders[dateMatched].message);
            reminderPosY++;
        }
        else
        {
            printf("%d", i + 1);
        }

        if (pos == 91)
        {
            pos = 21; // Moving position to monday
            j++;      // Increasing j by 10 if position is sunday
        }
    }

    SetColor(5); // Changing color to purple

    // Drawing horizontal line
    for (i = 22; i < 102; i++)
    {
        gotoxy(i, 4);
        printf("%c", 196);
        gotoxy(i, 17);
        printf("%c", 196);
    }

    // Drawing all the corner of the rectangle
    gotoxy(21, 4);
    printf("%c", 218);
    gotoxy(102, 4);
    printf("%c", 191);
    gotoxy(21, 17);
    printf("%c", 192);
    gotoxy(102, 17);
    printf("%c", 217);

    // Drawing vertical line
    for (i = 5; i < 17; i++)
    {
        gotoxy(21, i);
        printf("%c", 179);
        gotoxy(102, i);
        printf("%c", 179);
    }

    SetColor(11); // Changing color to aqua

    // Drawing left and the right navigation symbol
    gotoxy(24, 11);
    printf("%c", 174);
    gotoxy(98, 11);
    printf("%c", 175);
}

//==============  ARROW KEY ===============
int getkey()
{
    int ch;
    ch = getch();
    if (ch == 0)
    {
        printf("zero");
        ch = getch();

        return ch;
    }
    return ch;
}

//============ Calculating ====================
void calendar(int nyr, int nmonth)
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tdays = 0, k, myear;
    system("cls");
    myear = nyr - 1; // Decreasing year by 1
    if (myear >= 1945)
    {
        for (k = 1945; k <= myear; k++)
        {
            if (k % 4 == 0)          // If the year is a leap year than total no of days is 366
                tdays = tdays + 366; // counting all the days till nyr - 1
            else                     // If the year is a leap year than total no of days is 365
                tdays = tdays + 365; // counting all the days till nyr - 1
        }
    }

    if (nyr % 4 == 0)
        days[1] = 29; // changing value in days array from 28 to 29 since leap year
    else
        days[1] = 28; // changing value in days array from 29 to 28 since not a leap year

    for (k = 0; k < (nmonth - 1); k++)
    {

        tdays = tdays + days[k]; // Adding nmonth-1 days to tdays
    }

    tdays = tdays % 7;                 // Finding the remainder of tdays so it can calculate the position to display
    display(nyr, nmonth, tdays, days); // Passing the value to display
}

//============== Fetching reminders ===================

void getAndPopulateReminders()
{
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        return;
    }

    char line[200];
    int reminderCount = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *token = strtok(line, ",");
        int i = 0;
        while (token != NULL)
        {
            if (i == 0)
            {
                Reminders[reminderCount].day = atoi(token);
            }
            else if (i == 1)
            {
                Reminders[reminderCount].month = atoi(token);
            }
            else if (i == 2)
            {
                Reminders[reminderCount].year = atoi(token);
            }
            else if (i == 3)
            {
                strcpy(Reminders[reminderCount].message, token);
            }
            token = strtok(NULL, ",");
            i++;
        }
        reminderCount++;
    }

    fclose(fp);
    // displayReminders(reminderCount);
    totalReminders = reminderCount;
}

void storeReminders()
{
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    for (int i = 0; i < totalReminders; i++)
    {
        fprintf(fp, "%d,%d,%d,%s", Reminders[i].day, Reminders[i].month, Reminders[i].year, Reminders[i].message);
    }

    fprintf(fp, "\n");
    fclose(fp);
}

void addReminder()
{
    int day, month, year;
    char message[200];
    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter message: ");
    scanf(" %[^\n]s", message);
    Reminders[totalReminders].day = day;
    Reminders[totalReminders].month = month;
    Reminders[totalReminders].year = year;
    strcpy(Reminders[totalReminders].message, message);
    totalReminders++;
}

//============== Displaying reminders ===================

void displayReminders(int size)
{
    for (int i = 0; i < size; i++)
    {
        // printf("%d. Day: %d, Month: %d, Year: %d, Message: %s", i + 1, Reminders[i].day, Reminders[i].month, Reminders[i].year, Reminders[i].message);

        // change colour to green
        SetColor(2);

        // print number of reminder
        printf("%d. ", i + 1);
        fflush(stdout);

        // change colour to green
        SetColor(2);
        printf("Day: ");

        // change colour to white
        SetColor(15);
        printf("%d", Reminders[i].day);

        // change colour to green
        SetColor(2);
        printf(", Month: ");

        // change colour to white
        SetColor(15);
        printf("%d", Reminders[i].month);

        // change colour to green
        SetColor(2);
        printf(", Year: ");

        // change colour to white
        SetColor(15);
        printf("%d", Reminders[i].year);

        // change colour to green
        SetColor(2);
        printf(", Message: ");

        // change colour to white
        SetColor(15);
        printf("%s", Reminders[i].message);
    }
}

int dateMatchedInReminders(int day, int month, int year)
{
    for (int i = 0; i < totalReminders; i++)
    {
        if (Reminders[i].day == day && Reminders[i].month == month && Reminders[i].year == year)
        {
            return i;
        }
    }
    return -1;
}