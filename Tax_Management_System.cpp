#include <iostream>
#include <conio.h>
#include <fstream>
#include <process.h>
#include <windows.h>
//#include<graphics.h>
using namespace std;
char emp_name[30];
int CTC, n, D_A, x, Gross_salary, emp_code, tax, net_salary, CCTC, Cn, CD_A, Cx, CGross_salary, Cemp_code, Ctax, Cnet_salary;
char name[50], username[50], password[50], designation[30], test[50];
char nl[50], ul[20], pl[20], uname[50];
int epf, d_a, gratuity;
int taxable_salary;
char rm[20], rn[50], rp[20];
void gotoxy(int a, int b)
{
    COORD c;
    c.X = a;
    c.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void big_box()
{
    for (int i = 1; i < 120; i++)
    {
        gotoxy(i, 0);
        cout << "-";
    }
    for (int i = 1; i < 120; i++)
    {
        gotoxy(i, 28);
        cout << "-";
    }
    for (int j = 1; j <= 27; j++)
    {
        gotoxy(0, j);
        cout << "|";
        gotoxy(119, j);
        cout << "|";
    }
}
void small_box()
{
    for (int i = 1; i < 50; i++)
    {
        gotoxy(i, 0);
        cout << "-";
    }
    for (int i = 1; i < 50; i++)
    {
        gotoxy(i, 14);
        cout << "-";
    }
    for (int j = 1; j <= 14; j++)
    {
        gotoxy(0, j);
        cout << "|";
        gotoxy(50, j);
        cout << "|";
    }
}
void login_box()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 19);
    for (int i = 1; i < 50; i++)

    {
        gotoxy(i, 0);
        cout << "-";
    }
    for (int i = 1; i < 50; i++)
    {
        gotoxy(i, 14);
        cout << "-";
    }
    for (int j = 0; j <= 14; j++)
    {
        gotoxy(0, j);
        cout << "|";
        gotoxy(50, j);
        cout << "|";
    }
}
void emp_details()
{
    system("color 01");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    big_box();
    gotoxy(20, 1);
    SetConsoleTextAttribute(h, 13);
    cout << "************** DETAILS MENU ***************";
    gotoxy(20, 3);
    SetConsoleTextAttribute(h, 18);
    cout << "This Project is developed by Divyansh.";
    char b = 254;
    fstream file;
    file.open("Employees.docx", ios::app);
    gotoxy(3, 5);
    SetConsoleTextAttribute(h, 71);
    cout << "\tEnter Employee name : ";
    // cin.ignore();
    cin.getline(emp_name, 50);
    strcpy(uname, emp_name);
    file << emp_name << ' ';
    gotoxy(3, 6);
    cout << "\tEnter Employee code : ";
    cin >> emp_code;
    // Cemp_code=emp_code;
    file << emp_code << ' ';
    gotoxy(3, 7);
    cout << "\tPlease Enter CTC : ";
    cin >> CTC;
    CCTC = CTC;
    file << CTC << ' ';
    gotoxy(3, 8);
    cout << "\tPlease Enter your total service years :";
    cin >> n;
    Cn = n;
    file << n << ' ';
    gotoxy(3, 9);
    cout << "\tPlease Enter your EPF rate : ";
    cin >> x;
    Cx = x;
    file << x << ' ';
    gotoxy(3, 10);
    cout << "\tEnter your D.A. Rate : ";
    cin >> D_A;
    CD_A = D_A;
    file << D_A << endl;
    gotoxy(1, 11);
    int i, j;
    gotoxy(1, 20);
    for (i = 0; i < 70; i++)
    {
        for (j = 0; j < 1200000; j++)
        {
            j++;
            j--;
        }
        cout << b;
    }
    cout << endl;
    SetConsoleTextAttribute(h, 99);
    cout << "\tEmployee details are saving pls wait";
    for (i = 2; i < 20; i++)
    {
        for (j = 2; j < 12000000; j++)
        {
            j++;
            j--;
        }
        cout << b;
    }
    cout << endl
         << endl;
    gotoxy(1, 22);
    for (i = 2; i < 100; i++)
    {
        for (j = 2; j < 1200000; j++)
        {
            j++;
            j--;
        }
        cout << "-";
    }
    cout << endl
         << "\tDetails of employee are saved pls wait while we calculate your net salary " << endl;
    gotoxy(1, 24);
    for (i = 7; i < 100; i++)
    {
        for (j = 7; j < 12000000; j++)
        {
            j++;
            j--;
        }
        cout << "-";
    }
}
void salary()
{
    fstream file8,file7;
    file8.open("Employees.docx", ios::in);
    while (true)
    {
        file8 >> emp_name >> emp_code >> CTC >> n >> x >> D_A;
        if (file8.eof())
        {
            break;
        }
        // file>>emp_name>>emp_code>>CTC>>n>>x>>D_A;

        float u = (15 / 26);
        file7.open("Salary.docx", ios::app);
        epf = (x * CCTC) / 100;
        file7<< emp_code <<' ' ;
        file7<< epf << ' ';
        gratuity = ((CCTC / 12) * 15 * Cn) / 26;
        file7 << gratuity << ' ';
        Gross_salary = CCTC - epf - gratuity;
        file7 << Gross_salary << endl;
    }
}
void taxes()
{
    fstream file2,file4;
    file2.open("Salary.docx", ios::in);
    while (true)
    {
        file2 >> emp_code >> gratuity >> Gross_salary;
        if (file2.eof())
        {
            break;
        }
        file4.open("Taxes.docx", ios::app);

        taxable_salary = Gross_salary - 250000;
        file4 << emp_code << ' ';
        file4 << taxable_salary << ' ';
        if (Gross_salary > 250000 && Gross_salary < 500000)
        {
            tax = (5 * Gross_salary) / 100;
        }
        else if (Gross_salary > 500000 && Gross_salary < 1000000)
        {
            tax = (10 * Gross_salary) / 100;
        }
        else if (Gross_salary > 1000000)
        {
            tax = (20 * Gross_salary) / 100;
        }
        else
        {
            tax = 0;
        }
        file4 << tax << ' ';
        net_salary = Gross_salary - tax;
        file4 << net_salary << endl;
    }
}
void display()
{
    system("cls");
    taxes();
    cout << "\t\t\tHere is your Info" << endl
         << endl
         << endl;
    cout << "\t Employee name : " << emp_name << endl;
    cout << "\t Employee Code : " << emp_code << endl;
    cout << "\t Your CTC : " << CTC << endl;
    cout << "\t Total years served for company : " << n << endl;
    cout << "\t --------------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << "\t Your Gross Salary is : " << Gross_salary << endl;
    cout << "\t Your Payable tax is : " << tax << endl;
    cout << "\t ---------------------------------------------------------------------------------------------------" << endl;
    cout << "\t Your Net/In-Hand Salary is : " << net_salary << endl;
    cout << "\tYour Monthly In-Hand Salary is : " << net_salary / 12 << endl;
}

void login_new()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    char ch;
    int i;
    system("cls");
    // initwindow(50,50);
    big_box();
    fstream file;
    file.open("Login.docx", ios::app);
    gotoxy(30, 1);
    SetConsoleTextAttribute(h, 63);
    cout << "This Project is created by Divyansh Upadhyay C.S.E 3rd year ";

    gotoxy(35, 2);
    // system("color 7a");
    SetConsoleTextAttribute(h, 70);
    cout << "************ NEW USER'S MENU ***************";
    // system("color 7c");
    gotoxy(5, 5);
    SetConsoleTextAttribute(h, 10);
    cout << "Enter your name : ";
    cin.ignore();
    cin.getline(nl, 50);
    file << nl << ' ';
    gotoxy(5, 6);
    cout << "Enter username :";
    cin.getline(ul, 20);
    file << ul << ' ';
    gotoxy(5, 7);
    cout << "Create password : ";
    while ((ch = _getch()) != 13)
    {
        pl[i] = ch;
        i++;
        printf("*");
    }
    pl[i] = '\0';
    file << pl << endl;
    gotoxy(5, 10);
    cout << "Your details are saving ";
    for (int i = 2; i < 40; i++)
    {
        for (int j = 2; j < 100000000; j++)
        {
            j++;
            j--;
        }
        cout << "*";
    }
}
void login_old()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    char ch;
    int i;
    system("cls");
    system("color 02");
    login_box();
    char un[20], p[20];

    gotoxy(5, 4);
    SetConsoleTextAttribute(h, 70);
    cout << "Enter Username : ";
    cin.ignore();
    cin.getline(un, 20);
    gotoxy(5, 5);
    SetConsoleTextAttribute(h, 48);
    cout << "Enter password : ";
    while ((ch = _getch()) != 13)
    {
        p[i] = ch;
        i++;
        printf("*");
    }
    p[i] = '\0';

    // cin.getline(p,20);
    fstream file;
    file.open("Login.docx", ios::in);
    while (true)
    {
        file >> nl >> ul >> pl;
        if (file.eof())
        {
            break;
        }
        // file>>nl>>ul>>pl;
        system("cls");
        if (!strcmp(ul, un))
        {
            if (!strcmp(p, pl))
            {
                gotoxy(5, 4);
                cout << "Login Success ";
                for (int i = 2; i < 20; i++)
                {
                    for (int j = 2; j < 10000000; j++)
                    {
                        j++;
                        j--;
                    }
                    cout << "*";
                }
                for (int j = 2; j < 100000; j++)
                {
                    j++;
                    j--;
                }
                system("cls");
                emp_details();
                salary();
                system("cls");
                system("color 04");
                display();
            }
        }
    }
}
void saved_user()
{
    system("cls");
    int a;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("color 07");
    SetConsoleTextAttribute(h, 9);
    cout << "Enter the Employee code to see details : ";
    cin >> a;
    cout << endl
         << endl;
    fstream file;
    file.open("Employees.docx", ios::in);
    while (true)
    {
        file >> emp_name >> emp_code >> CTC >> n >> x >> D_A;
        if (file.eof())
        {
            break;
        }
        if (emp_code == a)
        {
            SetConsoleTextAttribute(h, 74);
            cout << "Employee's Name : " << emp_name << endl
                 << "Employee's Code : " << emp_code << endl
                 << "Employee's CTC : " << CTC << endl
                 << "Total Working Years : " << n << endl
                 << "EPF RATE : " << x << endl
                 << "Total DA : " << D_A<<endl<<endl;
                 cout<<"***********************************************************"<<endl;
        }
    }
}
void find_ctc()
{
    system("cls");
    int a, c;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("color 07");
    SetConsoleTextAttribute(h, 9);
    cout << "Enter the Employee code to see details : ";
    cin >> a;
    cout << endl
         << endl;
    fstream file;
    file.open("Employees.docx", ios::in);
    while (true)
    {
        file >> emp_name >> emp_code >> CTC >> n >> x >> D_A;
        if (file.eof())
        {
            break;
        }
        if (emp_code == a)
        {
            SetConsoleTextAttribute(h, 74);
            cout << "CTC OF THE EMPLOYEE " << emp_name << " Is : " << CTC << endl
                 << endl;
        }
    }
}
void find_pass()
{
    system("cls");
    char up[20], np[20];
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("color 07");
    SetConsoleTextAttribute(h, 5);
    cout << "Enter the Username to see details : ";
    cin.ignore();
    cin.getline(up, 20);
    cout << endl
         << endl;
    fstream file;
    file.open("Login.docx", ios::in);
    while (true)
    {
        file >> name >> username >> password;
        if (file.eof())
        {
            break;
        }
        if (!strcmp(username, up))
        {
            SetConsoleTextAttribute(h, 9);
            cout << "More Verification needed :" << endl
                 << endl;
            cout << "Enter name : ";
            cin.getline(np, 20);
            if (!strcmp(username, up) && !strcmp(name, np))
            {
                cout << "Password is : " << password;
            }
        }
    }
}
void logout()
{
    char aa[] = "Logging You out ";

    for (int i = 0; i < strlen(aa); i++)
    {
        for (int j = 1; j < 10000000; j++)
        {
            j++;
            j--;
        }
        cout << aa[i];
    }
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j < 100000000; j++)
        {
            j++;
            j--;
        }
        cout << "*";
    }
}
void retrive_pass()
{
    fstream file;
    file.open("Request.docx", ios::in);
    while (1)
    {
        file >> rm >> rn;
        if (file.eof())
        {
            break;
        }
        cout << rm << "      " << rn << endl;
    }
}
void admin()
{
    int cm;
    system("cls");
    char w;

    system("color a4");
    char admin[20], apass[20], ch, chq;
    int i = 0, j = 0;
    cout << "Username : ";
    // cin.ignore();
    while ((ch = _getch()) != 13)
    {
        admin[i] = ch;
        i++;
        printf("*");
    }
    admin[i] = '\0';

    // cin.getline(admin,20);
    cout << endl
         << "Password : ";
    while ((chq = _getch()) != 13)
    {
        apass[j] = chq;
        j++;
        printf("*");
    }
    apass[j] = '\0';
    // cout<<apass;
    // cin.getline(apass,20);
    // cout<<admin;
    // cin.getline(apass,20);
    if (!strcmp(admin, "Divyansh") || !strcmp(admin, "Aaryan") || !strcmp(admin, "Garvit"))
    {
        // cout<<"Hello";
        if (!strcmp(apass, "7409") || !strcmp(apass, "0111") || !strcmp(apass, "0065"))
        {
            cout << endl;
            cout << "Login success ";
            for (int o = 0; o < 10; o++)
            {
                for (int j = 2; j < 12000000; j++)
                {
                    j++;
                    j--;
                }
                cout << "*";
            }
            do
            {
                system("color a4");
                system("cls");
                big_box();
                gotoxy(35, 1);
                cout << "**********Admin menu**********";
                gotoxy(15, 5);
                cout << "1. See details of Saved users";
                gotoxy(15, 6);
                cout << "2. Find CTC from Employee code";
                gotoxy(15, 7);
                cout << "3. Find Login Password From Username";
                gotoxy(15, 8);
                cout << "4. See Registered Requests for Password Retrive";
                gotoxy(15, 9);
                cout << "5. Logout of Admin portal";
                gotoxy(15, 10);
                cout << "6. Exit program";
                gotoxy(15, 11);
                cout << "7. Print Registred User's List";
                gotoxy(15, 12);
                cout << "---------------------------------------------------------------";
                gotoxy(15, 14);
                cin >> cm;
                switch (cm)
                {
                    system("cls");
                case 1:
                    saved_user();
                    break;
                case 2:
                    find_ctc();
                    break;
                case 3:
                    find_pass();
                    break;
                case 4:
                    retrive_pass();
                    break;
                case 5:
                    logout();
                    break;
                case 6:
                    break;
                case 7:
                    if (!strcmp(admin, "Divyansh"))
                    {
                        system("notepad /p Employees.docx");
                        break;
                    }
                    else
                    {
                        char d[] = "\tYou are not authorized Admin to print details";
                        for (int o = 0; o < strlen(d); o++)
                        {
                            for (int j = 2; j < 12000000; j++)
                            {
                                j++;
                                j--;
                            }
                            cout << d[o];
                        }
                        break;
                    }
                }
                cout << endl
                     << endl
                     << "Do you want to use Admin Portal Again(Y/N) : ";
                cin >> w;
                if (w == 'y' || w == 'Y')
                {
                    continue;
                }
                else
                {
                    logout();
                    break;
                }
            } while (w == 'y' || w == 'Y');
        }
        else
            cout << endl
                 << "Wrong Password ";
    }
    else
        cout << endl
             << "Wrong Username ";
}
void forgot()
{
    system("cls");
    system("color 2e");
    small_box();

    gotoxy(4, 2);
    cout << "***We will help you out.***";
    gotoxy(2, 4);
    cout << "Enter the username you remembered : ";
    cin.ignore();
    cin.getline(rm, 20);
    fstream file;
    file.open("Login.docx", ios::in);
    while (1)
    {
        file >> name >> username >> password;
        if (file.eof())
        {
            break;
        }
        if (!strcmp(rm, username))
        {
            gotoxy(2, 6);
            fstream x;
            x.open("Request.docx", ios::app);
            file << rm << ' ';
            cout << "More Verification needed (Enter name): ";
            cin.getline(rn, 50);
            if (!strcmp(rm, username) && !strcmp(rn, name))
            {
                file << rn << endl;
                gotoxy(2, 8);
                cout << "Your request is sending to Admin ";
                for (int i = 0; i < 12; i++)
                {
                    for (int j = 0; j < 10000000; j++)
                    {
                        j++;
                        j--;
                    }
                    cout << " . ";
                }
            }
            else
            {
                cout << "Name does not match";
            }
        }
    }
}
void about()
{
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("Color 3F");
    big_box();
    gotoxy(40, 3);
    char welcome_msg[] = ">>>Welcome to About Section<<<";
    for (int i = 0; i < strlen(welcome_msg); i++)
    {
        for (int j = 0; j < 50000000; j++)
        {
            j++;
            j--;
        }
        cout << welcome_msg[i];
    }
    gotoxy(10, 6);
    SetConsoleTextAttribute(h, 10);
    char info1[] = ">>>This Project Name is Tax Management System<<<";
    for (int i = 0; i < strlen(info1); i++)
    {
        for (int j = 0; j < 7000000; j++)
        {
            j++;
            j--;
        }
        cout << info1[i];
    }
    gotoxy(10, 8);
    SetConsoleTextAttribute(h, 30);
    char info2[] = "*** This Project is Developed By Divyansh Upadhyay , Aaryan Bhargava & Garvit jain ***";
    for (int i = 0; i < strlen(info2); i++)
    {
        for (int j = 0; j < 7000000; j++)
        {
            j++;
            j--;
        }
        cout << info2[i];
    }
    gotoxy(10, 11);
    SetConsoleTextAttribute(h, 65);
    char info3[] = "###Our Project deals with the tax management and gives you the freedom to calculate your in-hand salary after all taxes deduction###\n";
    for (int i = 0; i < strlen(info3); i++)
    {
        for (int j = 0; j < 7000000; j++)
        {
            j++;
            j--;
        }
        cout << info3[i];
    }
    gotoxy(60, 18);
    SetConsoleTextAttribute(h, 10);
    char info4[] = ">>>Thanks for choosing Tax Management System<<<";
    for (int i = 0; i < strlen(info4); i++)
    {
        for (int j = 0; j < 7000000; j++)
        {
            j++;
            j--;
        }

        cout << info4[i];
    }



            
}
void option()
{
    system("cls");
    char kl;
    do
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        system("Color 3F");
        int ch;
        small_box();
        gotoxy(5, 1);
        char welcome_msg[] = ">>>Welcome to Tax Management System<<<";
        for (int i = 0; i < strlen(welcome_msg); i++)
        {
            for (int j = 0; j < 50000000; j++)
            {
                j++;
                j--;
            }
            cout << welcome_msg[i];
        }
        SetConsoleTextAttribute(h, 10);
        gotoxy(7, 3);

        cout << "*********** MENU ***************";
        // SetConsoleTextAttribute(h,90);
        // system("color 9f");
        gotoxy(6, 5);
        {

            cout << "1. New User ";
        }
        // system("Color 9F");
        gotoxy(6, 6);
        {
            cout << "2. Login ";
        }
        gotoxy(6, 7);
        {
            cout << "3. admin ";
        }
        gotoxy(6, 8);
        {
            cout << "4. Forgot Password ?";
        }
        gotoxy(6, 9);
        {
            cout << "5. About This Project ?";
        }
        gotoxy(6, 10);
        cout << "------------------------";
        gotoxy(6, 11);
        cin >> ch;
        system("cls");
        big_box();

        switch (ch)
        {
        case 1:
            login_new();
            break;
        case 2:
            login_old();
            break;
        case 3:
            admin();
            break;
        case 4:
            forgot();
            break;
        case 5:
            about();
            break;
        }

        cout << "\n\tDo you want to continue(y/n) : ";
        cin >> kl;
        system("cls");
    } while (kl == 'y' || kl == 'Y');
}
int main()
{
    option();
}
