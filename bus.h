#include<iostream>
#include<conio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fstream>

using namespace std;

struct
{
    string from;
    string ftime;
    string to;
    string ttime;
    string seats;
}bus;
void init()
{
    mkdir("Ticket Reservation System Data/Bus");
    fstream file;
    file.open("Ticket Reservation System Data/Bus/5.txt",ios::app);
    file.close();
    file.open("Ticket Reservation System Data/Bus/1.txt",ios::app);
    file.close();
    file.open("Ticket Reservation System Data/Bus/2.txt",ios::app);
    file.close();
    file.open("Ticket Reservation System Data/Bus/3.txt",ios::app);
    file.close();
    file.open("Ticket Reservation System Data/Bus/4.txt",ios::app);
    file.close();
    file.open("Ticket Reservation System Data/Bus/seats.txt",ios::app);
    file.close();
}

string seat_detail(char no)
{
    fstream file;
    file.open("Ticket Reservation System Data/Bus/seats.txt",ios::in);
    string s1,s2,s3,s4,s5;
    file>>s1>>s2>>s3>>s4>>s5;
    switch(no)
    {
    case '1':
        return s1;
        break;
    case '2':
        return s2;
        break;
    case '3':
        return s3;
        break;
    case '4':
        return s4;
        break;
    case '5':
        return s5;
        break;
    }
}
 void seat_update(char no,string seats)
 {
    fstream file;
    file.open("Ticket Reservation System Data/Bus/seats.txt",ios::in);
    string s1,s2,s3,s4,s5;
    file>>s1>>s2>>s3>>s4>>s5;
    file.close();

    switch(no)
    {
    case '1':
        s1 = seats;
        break;
    case '2':
        s2 = seats;
        break;
    case '3':
        s3 = seats;
        break;
    case '4':
        s4 = seats;
        break;
    case '5':
        s5 = seats;
        break;
    }
    file.open("Ticket Reservation System Data/Bus/seats.txt");
    file<<s1<<"\n";file<<s2<<"\n";file<<s3<<"\n";file<<s4<<"\n";file<<s5<<"\n";
    file.close();

    }

void update(string no)
{
    fstream file;
    file.open("Ticket Reservation System Data/Bus/"+no+".txt");
    cout<<"\nFrom place : ";
    string fplace; cin>>fplace;
    file<<fplace<<"\n";
    cout<<"\nFrom time : ";
    string ftime; cin>>ftime;
    file<<ftime<<"\n";
    cout<<"\nTo place : ";
    string tplace; cin>>tplace;
    file<<tplace<<"\n";
    cout<<"\nTo time : ";
    string ttime; cin>>ttime;
    file<<ttime<<"\n";
}

void schedule(string no)
{
    fstream file;
    file.open("Ticket Reservation System Data/Bus/"+no+".txt",ios::in);
    string fplace;
    file>>fplace;
    string ftime;
    file>>ftime;
    string tplace;
    file>>tplace;
    string ttime;
    file>>ttime;
    cout<<"\nBus "<<no<<": "<<fplace<<" -> "<<tplace<<"  "<<ftime<<" -> "<<ttime;
}
