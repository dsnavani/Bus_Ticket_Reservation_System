#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

void bus_frontview() {

    cout<<"                                                      "<<"|--------------------|"<<endl;
    cout<<"                                                      "<<"|********************|"<<endl;
    cout<<"                                                      "<<"|*                  *|"<<endl;
    cout<<"                                                      "<<"|*                  *|"<<endl;
    cout<<"                                                      "<<"|*                  *|"<<endl;
    cout<<"                                                      "<<"|********************|"<<endl;
    cout<<"                                                      "<<"|                    |"<<endl;
    cout<<"                                                      "<<"|                    |"<<endl;
    cout<<"                                                      "<<"| +++ |````````| +++ |"<<endl;
    cout<<"                                                      "<<"| +++ |________| +++ |"<<endl;
    cout<<"                                                      "<<"|--------------------|"<<endl;
    cout<<"                                                      "<<"  ( )            ( )  "<<endl;
}
void first_page() {

    system("cls");
    time_t my_time = time(NULL);
    cout<<"*********************************************************************************************************************************";
    cout<<"                                                                                                         "<<ctime(&my_time)<<endl;
    cout<<"                                               " << "\e[1mWELCOME TO TICKETING APPLICATION" <<"\e[0m"<<endl;
    cout<<"                                  "<<"\e[3mBooking your tickets in this application makes you live longer"<<"\e[0m"<<endl;
    bus_frontview();
    cout<<"Loading";
    sleep_for(1s); cout<<".";
    sleep_for(1s); cout<<".";
    sleep_for(1s); cout<<".";
    sleep_for(1s);
    system("cls");
}
int second_page() {
    cout<<"*********************************************************************************************************************************"<<endl;
    int choice;
    cout<<"1.New user                                             2.Existing User                              3.Exit"<<endl;
    cin>>choice;
    if(choice == 1)
    {
        cout<<"*********************************************************************************************************************************"<<endl;
        cout<<"New user"<<endl;
    }
    else if(choice == 2)
    {
        cout<<"*********************************************************************************************************************************"<<endl;
        cout<<"existing user"<<endl;;
    }
    else if (choice == 3) exit(0);
    else {
        cout<<"Wrong input";
        sleep_for(2s);
        system("cls");
        second_page();
    }
    sleep_for(1s);
    return choice;
}
void booking_page() {
    cout<<"                                              BOOK YOUR SEATS                                               "<<endl;
    cout<< "|*---------------------------------------------------------------------------------------------------------|"<<endl;
    printf("|**   |  ____|01 ____|02 ____|03 ____|04 ____|05 ____|06 ____|07 ____|08 ____|09 ____|10 ____|11 ____|12   |\n");
    cout<<"|**   |                                                                                                    |"<<endl;
    printf("|**   |  ____|13 ____|14 ____|15 ____|16 ____|17 ____|18 ____|19 ____|20 ____|21 ____|22 ____|23 ____|24   |\n");
    cout<<"|**   |                                                                                                    |"<<endl;
    cout<<"|**   |                                                                                                    |"<<endl;
    cout<<"|**   |                                                                                                    |"<<endl;
    printf("|**   |  ____|25 ____|26 ____|27 ____|28 ____|29 ____|30 ____|31 ____|32 ____|33 ____|34 ____|35 ____|36   |\n");
    cout<<"|**   |                                                                                                    |"<<endl;
    printf("|**   |  ____|37 ____|38 ____|39 ____|40 ____|41 ____|42 ____|43 ____|44 ____|45 ____|46 ____|47 ____|48   |\n");
    cout<< "|*---------------------------------------------------------------------------------------------------------|"<<endl;

}





