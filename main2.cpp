#include <iostream>
#include <string>
#include <array>
#include "DriverLicense.h"
using namespace std;


int main()
{   
    string address,fname,lname,idate,edate;
    
    DriverLicense l1{"111111111","Esma", "Yildirim","20006 45th ave", "09/12/2012","09/11/2016","03/23/1944", 5, 5, "B", "BROWN", "F" };
    DriverLicense l2{"222222222","John", "Doe", "221 Baker St", "09/12/2012","09/11/2016","03/23/1944", 5, 5, "B", "BROWN", "M" };
    

    array<DriverLicense,2>licenses;
    
    

    licenses[0] = l1;
    licenses[1] = l2;
    //clicenses[0]= l1.getID();
    //clicenses[1]= l2.getID();
    //addr[0]     = l1.setAddress(address);
    //addr[1]     = l2.setAddress(address);

    for (size_t i = 0 ; i < licenses.size() ; i++ )
    cout <<licenses[i].toString()<< endl<<endl;


    int tf=0,saveI;
    string c;

  


    size_t i;
    while(  c !="quit" )
  {
     cout << "ID(type quit to exit the program)? ";
     cin >> c;
     
     
    if(c != "quit")
    {
        
        while(tf==0 )
    
    {
       
       
        if(c!="quit" )
        {
            for ( i = 0 ; i < licenses.size() ; ++i )
            {
                if (c == licenses[i].getID())
                {
                    //cout << licenses[i].toString()<< endl << endl;
                    tf++;
                    saveI=i;//SAVE THE VALUE OF I AS INDEX SO YOU CAN USE IT LATER

                }
            }
        if (tf==0)
          { 
              cout << "ID not found. Try again "<< endl;
              cout << "ID(type quit to exit the program)? ";
              cin >> c;
          }
        }
    }

//------------------------ changing service ----------------------------------------------------------------------------------------------------
    
    int opt;
    while(opt!= -1 )
    {
        cout <<"Enter option number(-1 to stop): " << endl << "1 for address change" << endl << "2 for name change" << endl << "3 for license renewal" << endl;
        cin >> opt;
        
        if(opt==1)
        {
            cout << "Enter Address: ";
            cin.ignore();
            getline(cin,address);
            
            licenses[saveI].setAddress(address);
            
            //WHAT IF I HAD 100 OBJECTS? ARE YOU GOING TO WRITE 100 IF STATEMENTS?
           /* if (clicenses[saveI]) //YOU CANNOT GIVE ID MANUALLY. SAVE THE INDEX OF THE OBJECT FROM THE PREVIOUS WHILE LOOP INSTEAD OF SAVING THE ID
            {
                l1.setAddress(address); //WHAT IS L1 // IT SHOULD BE SOMETHING LIKE licenses[index] */
                cout << "After change: " << endl;
                cout << licenses[saveI].toString() << endl;
          /*  }
            if(d=="222222222")
            {
                l2.setAddress(address);
                cout << endl << "After change: " << endl;
                cout << l2.toString() << endl;
            }*/
        }
        if(opt==2)
        {
            cout << "Enter first name and last name: ";
            cin >> fname ; //USE CIN IF YOU ARE GOING TO READ ONE WORD. NOT GETLINE.

            
            cin >> lname;//SAME HERE


           licenses[saveI].setFirstName(fname);
           licenses[saveI].setLastName(lname);
                cout << "After change: " << endl;
                cout << licenses[saveI].toString() << endl;
            
           
        
            
        }

        if(opt==3)
        {

            //DATES MIGHT THROW AN EXCEPTION. USE A TRY CATCH BLOCK HERE TO HANDLE IT. OTHERWISE IT WILL ABORT THE PROGRAM
           int tf=0;
           while(tf != 1)
          {
            try{
            cout << "Enter issue date(MM/DD/YYYY): ";
            cin >> idate; //USE CIN
            cout << "Enter expiration date(MM/DD/YYYY): ";
            cin >> edate;//USE CIN
             
              
 
             
             if(idate.size() != 10 or edate.size() != 10 or idate[2]!='/' or edate[2]!='/' or idate[5]!= '/' or edate[5]!='/')
             {
                cout << "Invalid date. Try again" << endl;
             }
             
             if(idate.size() == 10 and edate.size() == 10 and idate[2]=='/' and edate[2]=='/' and idate[5]== '/' and edate[5]=='/')    
                {
               licenses[saveI].setIssueDate(idate);
                licenses[saveI].setExpDate(edate);
                cout << "After change: " << endl;
                cout << licenses[saveI].toString() << endl;
                tf++;
             }
            }
          
             
          catch(string ex)
          
               { 
               
               }

          }
            
            
        

            
        }
       
        if (opt==-1)       
       { 
           opt = -1;
       }
       
       
       //if(opt!=1 and opt!=2 and opt!=3 and opt !=4 and opt !=-1)
        else  
          { cout << "Invalid choice. " ;//WHERE ARE YOUR BRACES
            cout << "Try again." << endl;  //THESE TWO STATEMENT BELONG TO ELSE
    
           }
       
        
    }
    }

 }


    return 0;

}