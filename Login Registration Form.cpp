#include<bits/stdc++.h>
using namespace std;
void login();
void registration();
void forgot();
int main()
{

    int c;
    cout<<"\t______________________________________________\n\n";
    cout<<"\t          Welcome to the Login Page           \n\n";
    cout<<"\t___________________ MENU _____________________\n\n";
    cout<<"\t!  Press 1 to Login                       !"<<endl;
    cout<<"\t!  Press 2 to Register                    !"<<endl;
    cout<<"\t!  Press 3 to if you forgot Password      !"<<endl;
    cout<<"\t!  Press 4 to Exit                        !"<<endl;
    cout<<"\n\t Please Enter Your Choice: ";
    cin>>c;
    cout<<endl<<endl;

    switch(c)
    {
        case 1:
        login();
        break;

        case 2:
        registration();
        break;

        case 3:
        forgot();
        break;

        case 4:
        cout<<"\t Thank You ! \n\n";
        break;

        default:
        system("cls");
        cout<<"\t Please select from the options given below ! \n"<<endl;

        main();
    }
}

    void login()
    {
        int count;
        string userid, password, id, pass;
        system("cls");
        cout<<"\t Please Enter the Username and Password: "<<endl;
        cout<<"\t Username: ";
        cin>>userid;
        cout<<"\t Password: ";
        cin>>password;

        ifstream input("records.txt");

        while(input>>id>>pass)
        {
            if(id==userid && pass==password)
            {
                count = 1;
                system("cls");
            }
        }
        input.close();

        if(count==1)
        {
            cout<<"\t\t"<<userid<<"\n\t Your Login is Successfull ! \n\t Thanks for Logging in ! \n";
            main();
        }
        else
        {
            cout<<"\n\t Login Error ! \n\t Please ckeck your Username and Password ! \n";
            main();
        }
    }

    void registration()
    {
        string ruserid, rpassword, rid, rpass;
        system("cls");
        cout<<"\t Enter the Username: ";
        cin>>ruserid;
        cout<<"\t Enter the Password: ";
        cin>>rpassword;

        ofstream f1("records.txt", ios::app);
        f1<<ruserid<<' '<<rpassword<<endl;
        system("cls");
        cout<<"\n\t Registration Successfull ! \n";
        main();
    }

    void forgot()
    {
        int option;
        system("cls");
        cout<<"\t You forgot the Paswword? No Worries! \n\n";
        cout<<"\t Press 1 to search your ID by Username \n"<<endl;
        cout<<"\t Press 2 to go back to the Main Menu \n"<<endl;
        cout<<"\t Enter your Choice: ";
        cin>>option;

        switch(option)
        {
            case 1:
            {
            int count = 0;
            string suserid,sid,spass;
            cout<<"\n\t Enter the Username which you remembered: ";
            cin>>suserid;

            ifstream f2("records.txt");

            while(f2>>sid>>spass)
            {
                if(sid==suserid)
                {
                    count=1;
                }
            }
            f2.close();
            if(count=1)
            {
                cout<<"\n\t Your Account is found ! \n";
                cout<<"\n\t Your Password is: "<<spass<<endl<<endl;
                main();
            }
            else
            {
                cout<<"\n\t Sorry! Your Account is not found ! \n";
                main();
            }
            break;
            }
            case 2:
            {
            main();
            }
            default:
            cout<<"\t Wrong Choice! Please try again ! \n"<<endl;
            forgot();
        }
    }
