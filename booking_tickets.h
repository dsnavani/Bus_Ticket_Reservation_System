#include <iostream>
#include <bits/stdc++.h>
using namespace std::this_thread;
using namespace std::chrono_literals;
using namespace std;

class Payment {
    string card_holder_name;
    string card_no;
    string cvv;
    public:
    void get_data(int no_of_tickets);
};
void Payment :: get_data(int no_of_tickets) {
    cout<<"One ticket price is Rs.1000"<<endl;
    cout<<"Total price : "<<1000 * no_of_tickets<<endl;
    cout<<"Enter the Card Holder name : ";
    cin>>card_holder_name;
    cout<<"Enter the Card number      : ";
    cin>>card_no;
    cout<<"Enter the CVV              : ";
    cin>>cvv;
    time_t my_time = time(NULL);
    cout<<"Payment Processing";
    sleep_for(1s); cout<<".";
    sleep_for(1s); cout<<".";
    sleep_for(1s); cout<<"."<<endl;
    system("cls");
    cout<<"Payment is successful"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"   Date of booking   ||  "<<ctime(&my_time)<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"        Status       ||       Confirmed        "<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"   Payment Status    ||        Approved         "<<endl;
    cout<<"------------------------------------------------"<<endl;

    cout<<"        \e[1mHAVE A SAFE JOURNEY\e[0m"<<endl;
}
void booking(string& seat_list) {
    int seat_no;
    int no_of_tickets;
    int no_of_seats=0;
    for(int i = 1; i < 49; i++) {
            if(seat_list[i] == '0') no_of_seats++;
    }
    do{cout<<no_of_seats<<" seats are available"<<endl;
    cout<<"Enter the number of tickets: ";
    cin>>no_of_tickets;}
    while(no_of_tickets>no_of_seats);
    for(int i = 0; i < no_of_tickets; i++) {
        cout<<"Enter the seat number: ";
        cin>>seat_no;
        if(seat_no <1 || seat_no >48) {
            cout<<"wrong seat number"<<endl;
            i--;
        }
        if(seat_list[seat_no] == '1') {
            cout<<"Seat is already booked"<<endl;
            i--;
        }
        else {
            seat_list[seat_no]++;
            no_of_seats--;
            cout<<i+1<<". The Seat is selected"<<endl;
        }
    }
    system("cls");
    Payment obj;
    obj.get_data(no_of_tickets);
    return ;
}
