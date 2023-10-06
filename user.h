#include<iostream>
#include<conio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fstream>

using namespace std;

class user
{
    //PERSONAL DETAILS
    string name;
    string gender;
    string marital_status;
    string ph;
    string nationality;
    string email;
    struct
    {
        string date;
        string month;
        string year;
    }DOB;

    //ADDRESS
    struct
    {
        string door_no;
        string street;
        string area;
        string city;
        string district;
        string state;
        string zipcode;
    }AD;

    //STORAGE DIRECTORY AND FILE NAMES
    string format = ".txt";
    string dir_name = "Ticket Reservation System Data/User Data/";
    string user_list = dir_name+"user_list"+format;

    //FUNCTION TO FIND EXISTING USER
    bool duplicate(string user_name)
    {
        fstream file;
        file.open(user_list,ios::in);
        string data,temp="";
        file>>data;
        while(data!=temp)
        {
            if(data == user_name) return true;
            if(data == temp) break;
            temp = data;
            file>>data;
        }
        return false;
    }

    void retrive_data(string user_name)
    {
         while(!duplicate(user_name))
        {
           cout<<"username incorrect \n";
           cin>>user_name;
        }
        fstream file;
        file.open(dir_name+user_name+format,ios::in);
        file>>name;file>>gender;file>>marital_status;file>>DOB.date;
        file>>DOB.month;file>>DOB.year;file>>ph;file>>nationality;
        file>>email;file>>AD.door_no;file>>AD.street;file>>AD.city;
        file>>AD.district;file>>AD.state;file>>AD.zipcode;
    }

    public:
        string user_name;
        user()
        {
            mkdir("Ticket Reservation System Data");
            mkdir("Ticket Reservation System Data/User Data");
            fstream file;
            file.open(user_list,ios::app);
            file.close();
        }

        virtual string ac_type(void) = 0;

        void get_data()
        {
            system("cls");
            cout<<"---------PERSONAL DETAILS:->";
            cout<<"\nName : ";
            cin>>name;
            while(duplicate(name))
            {
                cout<<"Already Exists \nName : ";
                cin>>name;
            }
            user_name = name;
            cout<<"Gender[M - Male, F - Female, O - Others] : ";
            cin>>gender;
            cout<<"Marital Status[Yes, No] : ";
            cin>>marital_status;
            cout<<"D.O.B :\n Date : ";
            cin>>DOB.date;
            cout<<" Month : ";
            cin>>DOB.month;
            cout<<" Year : ";
            cin>>DOB.year;
            cout<<"Phone Number : ";
            cin>>ph;
            cout<<"Nationality : ";
            cin>>nationality;
            cout<<"Email : ";
            cin>>email;

            cout<<"---------ADDRESS:->";
            cout<<"\nDoor No : ";
            cin>>AD.door_no;
            cout<<"Street : ";
            cin>>AD.street;
            cout<<"Area : ";
            cin>>AD.area;
            cout<<"City : ";
            cin>>AD.city;
            cout<<"District : ";
            cin>>AD.district;
            cout<<"State : ";
            cin>>AD.state;
            cout<<"ZipCode : ";
            cin>>AD.zipcode;
            //TO STORE DATA
            fstream file;
            file.open(user_list,ios::app); file<<name<<"\n";
            file.close();
            file.open(dir_name+name+format,ios::app);
            file<<name<<"\n"<<gender<<"\n"<<marital_status<<"\n"<<DOB.date;
            file<<"\n"<<DOB.month<<"\n"<<DOB.year<<"\n"<<ph<<"\n"<<nationality;
            file<<"\n"<<email<<"\n"<<AD.door_no<<"\n"<<AD.street<<"\n"<<AD.city;
            file<<"\n"<<AD.district<<"\n"<<AD.state<<"\n"<<AD.zipcode;
            file.close();
        }


        //FUNCTION TO GET PASSWORD
        void get_password(string type)
        {
            char* passwrd = new char[20];
            int i;
            cout<<"Enter the password: ";
            for(int i = 0; i < 20; i++) {
                passwrd[i] = getch();
                if(passwrd[i] == 13) break;
                cout<<"*";
            }
            fstream file;
            file.open("Ticket Reservation System Data/"+type+"/data"+format,ios::app);
            file<<user_name<<"\n";
            file.close();
            file.open("Ticket Reservation System Data/"+type+"/password"+format,ios::app);
            file<<passwrd<<"\n";
            file.close();
        }


        void show_data()
        {
            system("cls");
            cout<<"\n---------PERSONAL DETAILS:->";
            cout<<"\nName : "<<name;
            cout<<"\nGender[M - Male, F - Female, O - Others] : "<<gender;
            cout<<"\nMarital Status[Yes, No] : "<<marital_status;
            cout<<"\nD.O.B\n Date : "<<DOB.date;
            cout<<"Month : "<<DOB.month;
            cout<<"Year : "<<DOB.year;
            cout<<"\nPhone Number : "<<ph;
            cout<<"\nNationality : "<<nationality;
            cout<<"\nEmail : "<<email;
            cout<<"\n---------ADDRESS:->";
            cout<<"\nDoor No : "<<AD.door_no;
            cout<<"\nStreet : "<<AD.street;
            cout<<"\nArea : "<<AD.area;
            cout<<"\nCity : "<<AD.city;
            cout<<"\nDistrict : "<<AD.district;
            cout<<"\nState : "<<AD.state;
            cout<<"\nZipCode : "<<AD.zipcode;
        }



        bool exis_acc(string input_name,string input_password,string type)
        {
            fstream name_file,password_file;
            name_file.open("Ticket Reservation System Data/"+type+"/data"+format,ios::in);
            password_file.open("Ticket Reservation System Data/"+type+"/password"+format,ios::in);
            string data1,temp1="",data2,temp2="";
            name_file>>data1;
            password_file>>data2;
            while(data1!=temp1)
            {
                if(data1 == input_name && data2 == input_password)
                {
                     this->retrive_data(input_name);
                     return true;
                }
                if(data1 == temp1) break;
                temp1 = data1; temp2 = data2;
                name_file>>data1; password_file>>data2;
            }
            cout<<"Password or access incorrect";
            return false;

        }


};

/* USER CLASS AVAILABLE FUNCTIONS:
    get_data, show_data, retrive_data */

class public_user : public user
{
    string pub_dir = "Ticket Reservation System Data/Public/";
    string format = ".txt";
    public:
        public_user()
        {
            mkdir("Ticket Reservation System Data/Public");
            fstream file1;
            file1.open(pub_dir+"data"+format,ios::app);
            file1.close();
            file1.open(pub_dir+"password"+format,ios::app);
            file1.close();
        }

        string ac_type()
        {
            return "pub";
        }
};



class admin_user : public user
{
    string ad_dir = "Ticket Reservation System Data/Admin/";
    string format = ".txt";
    public:
        admin_user()
        {
            mkdir("Ticket Reservation System Data/Admin");
            fstream file1;
            file1.open(ad_dir+"data"+format,ios::app);
            file1.close();
            file1.open(ad_dir+"password"+format,ios::app);
            file1.close();
        }

        string ac_type()
        {
            return "ad";
        }
};

