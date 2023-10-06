#include"user.h"
#include"application.h"
#include"bus.h"
#include"booking_tickets.h"
#include<string>


int choice2()  //PUBLIC OR ADMIN
{
    int x;
    cout<<"Public 1, admin 2"<<endl;
    cin>>x;
    return x;
}
 int main()
 {
     bus_frontview();
     first_page();
     int option1 = second_page();
     int option2 = choice2();
     if( option2 == 1)
     {
         public_user new_pub;
         if(option1 == 1)
         {
             new_pub.get_data();
             new_pub.get_password("Public");
         }
         if(option1 == 2)
         {
             string name,pass;
             cout<<"Name:";
             cin>>name;
             cout<<"Password:";
             cin>>pass;
             while(!new_pub.exis_acc(name,pass,"Public"))
            {
                //cin>>name>>pass;
                 cout<<"Name:";
                cin>>name;
                cout<<"Password:";
                cin>>pass;
            }
         }
         init();
        system("cls");
        schedule("1");schedule("2");schedule("3");schedule("4");schedule("5");
        cout<<"\nSelect Bus: ";
        char no;
        string seats;
        cin>>no;
        booking_page();
        seats = seat_detail(no);
        booking(seats);
        seat_update(no,seats);
     }
     if(option2 == 2)
     {
         admin_user new_ad;
         if(option1 == 1)
         {
             new_ad.get_data();
             new_ad.get_password("Admin");
         }
         if(option1 == 2)
         {
             string name,pass;
             cout<<"Name:";
             cin>>name;
             cout<<"Password:";
             cin>>pass;
             while(!new_ad.exis_acc(name,pass,"Admin"))
            {
                cout<<"Name:";
             cin>>name;
             cout<<"Password:";
             cin>>pass;
            }
         }
         init();

         schedule("1");schedule("2");schedule("3");schedule("4");schedule("5");
         cout<<"\nSelect Bus to change: ";
         string no;
         cin>>no;
         update(no);

     }

     return 0;
 }
