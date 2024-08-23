#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include<windows.h>
#include<conio.h>
#include <chrono>
#include <iomanip>
#include <cstdio>
using namespace std;

void gotoRowCol(int rpos, int cpos)
{
    int xpos=cpos, ypos = rpos;
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void sleep(int m)
{
    for(int j=0; j<m*21000; j++)
    {

    }
}
/////////////////////////////////////////////////////

class user
{
private:
    string name;
    int password, IDnum;
public:
    void set_info(string newname, int newpass,int ID)
    {
        name=newname;
        password=newpass;
        IDnum=ID;
    }
    string getName()
    {
        return name;
    }
    int getPassword()
    {
        return password;
    }
    int getIDnum()
    {
        return IDnum;
    }
};

class signup
{
public:
    user *ptr[2];
    int new_id;
    int password;
    int count=0;
    string name;
    int pass, AccountNum,IDnum;

    int signup_info()
    {
        ptr[count]=new user;
        gotoRowCol(15,30);
        cout<<"Enter ID Number: "<<endl;
        gotoRowCol(16,30);
        cin>>IDnum;
        gotoRowCol(17,30);
        cout<<"Enter name: "<<endl;
        gotoRowCol(18,30);
        cin>>name;
        gotoRowCol(19,30);
        cout<<"Enter password: "<<endl;
        gotoRowCol(20,30);
        cin>>pass;
        gotoRowCol(21,30);
        //cout<<"enter Account Number: "<<endl;
        //gotoRowCol(22,30);
        //cin>>AccountNum;
        ptr[count]->set_info(name,pass,IDnum);
        count=count+1;
        return IDnum;
    }
    int login_info()
    {
        string aaaa = "Login__Successful__WellCome_:)";
        int counter = 0;
        gotoRowCol(15,30);
        cout<<"Enter your ID Number: "<<endl;
        gotoRowCol(16,30);
        cin>>new_id;
        gotoRowCol(17,30);
        cout<<"Enter your PassWord: "<<endl;
        gotoRowCol(18,30);
        cin>>password;

        ifstream openforLogin("File_handling.txt");

        while (openforLogin >> IDnum >> name >> pass )
        {
            if (IDnum == new_id && pass == password)
            {
                system("cls");
                  for(int i=0;i<65;i++)
                    {   
                        gotoRowCol(3,10+i);
                        cout << char(219);
                    }
                  for(int i=0;i<30;i++)
                    {
                        gotoRowCol(3+i,10);
                        cout << char(219);
                    }
                  for(int i=0;i<65;i++)
                    {
                        gotoRowCol(33,10+i);
                        cout << char(219);
                    }
                   for(int i=0;i<=30;i++)
                    {
                        gotoRowCol(3+i,75);
                        cout << char(219);
                    }
                gotoRowCol(13,15);
                //////////////////////////////////////
                for(int i=0;i<30;i++)
                {
                    cout << aaaa[i];
                    sleep(3500);
                }
                gotoRowCol(15,15);
                cout << "--ACCOUNT INFORMATION--"<<endl;
                gotoRowCol(16,15);
                cout << "Name: " << name << endl;
                gotoRowCol(17,15);
                cout <<"ID: "<< IDnum;
                gotoRowCol(35, 2);
                cout << "  ";
                openforLogin.close();
                counter++;
                break;
            }
    
        }
        if(counter==0)
        {
           system("cls");
                  for(int i=0;i<65;i++)
                    {   
                        gotoRowCol(3,10+i);
                        cout << char(219);
                    }
                  for(int i=0;i<30;i++)
                    {
                        gotoRowCol(3+i,10);
                        cout << char(219);
                    }
                  for(int i=0;i<65;i++)
                    {
                        gotoRowCol(33,10+i);
                        cout << char(219);
                    }
                   for(int i=0;i<=30;i++)
                    {
                        gotoRowCol(3+i,75);
                        cout << char(219);
                    }
            gotoRowCol(14,30);
            cout << "Wrong ID or Password Try Again..!" << endl;
            login_info();
        }
        return IDnum;
    }
    void save()
    {
        ofstream hout("File_handling.txt",ios::app);
        if(hout.is_open())
        {
            for(int i=0; i<count; i++)
            {
                hout<<ptr[i]->getIDnum()<<" ";
                hout<<ptr[i]->getName()<<" ";
                hout<<ptr[i]->getPassword()<<" ";
            }
            hout<<endl;
        }
        hout.close();
    }

    void askUser()
    {
        int option;
          for(int i=0;i<65;i++)
        {
            gotoRowCol(3,10+i);
            cout << char(219);
        }
         for(int i=0;i<30;i++)
        {
            gotoRowCol(3+i,10);
            cout << char(219);
        }
         for(int i=0;i<65;i++)
        {
            gotoRowCol(33,10+i);
            cout << char(219);
        }
        for(int i=0;i<=30;i++)
        {
            gotoRowCol(3+i,75);
            cout << char(219);
        }

        while(true)
        {
             gotoRowCol(10,16);
            cout << "____WELCOME TO OUR LOGIN AND REGISTRATION SYSTEM_____ :) ";
            gotoRowCol(15,15);
            cout << "Enter 1 to SignUp..." << endl;
            gotoRowCol(16,15);
            cout << "Enter 2 to LogIn...";
            //gotoRowCol(16,30);
            cin >> option;
                system("cls");
                  for(int i=0;i<65;i++)
                    {   
                        gotoRowCol(3,10+i);
                        cout << char(219);
                    }
                  for(int i=0;i<30;i++)
                    {
                        gotoRowCol(3+i,10);
                        cout << char(219);
                    }
                  for(int i=0;i<65;i++)
                    {
                        gotoRowCol(33,10+i);
                        cout << char(219);
                    }
                   for(int i=0;i<=30;i++)
                    {
                        gotoRowCol(3+i,75);
                        cout << char(219);
                    }
            if(option==1)
            {
                gotoRowCol(15,30);
                signup_info();
                save();
                system("cls");
                  for(int i=0;i<65;i++)
                    {   
                        gotoRowCol(3,10+i);
                        cout << char(219);
                    }
                  for(int i=0;i<30;i++)
                    {
                        gotoRowCol(3+i,10);
                        cout << char(219);
                    }
                  for(int i=0;i<65;i++)
                    {
                        gotoRowCol(33,10+i);
                        cout << char(219);
                    }
                   for(int i=0;i<=30;i++)
                    {
                        gotoRowCol(3+i,75);
                        cout << char(219);
                    }
                string aaaa = "Registration__Successful__:)";
                int counter = 0;
                gotoRowCol(18,16);
                for(int i=0;i<30;i++)
                {
                    cout << aaaa[i];
                    sleep(3500);
                }
                gotoRowCol(35,2);
                cout << "  ";
                break;
            }
            else if(option==2)
            {
                gotoRowCol(15,30);
                login_info();
                break;
            }
            else
            {
                gotoRowCol(1,0);
                cout << " ";
            }
        }
    }
};
int main()
{
    signup su;
    su.askUser();
    return 0;

}
