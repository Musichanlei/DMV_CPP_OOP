#ifndef DRIVER_LICENSE_H
#define DRIVER_LICENCE_H
#include <stdexcept>
#include <string>
#include <sstream>
#include <array>
class DriverLicense{

public:

DriverLicense()
{

}

DriverLicense(std::string iid,
std::string fName,std::string lName,std::string addr,std::string eDate,std::string iDate,std::string dob,int feet,int inches,std::string lType,std::string eColor,std::string gen)
{
    setID(iid);
    setFirstName(fName);
    setLastName(lName);
    setAddress(addr);
    setExpDate(eDate);
    setIssueDate(iDate);
    setDateOfBirth(dob);
    setHeightFeet(feet);
    setHeightInches(inches);
    setLicenseType(lType);
    setEyeColor(eColor);
    setGender(gen);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
std::string toString()const
{ std::ostringstream output;
  output << "ID: " << getID() << " " << "Fullname: " << getFirstName() << " " << getLastName() << "\n" << "Address: " << getAddress() << "\n" << "Issue date: " << getIssueDate() << " Expire date: " << getExpDate() << "\n" << "DOB: "<< getDateOfBirth() << "\n";
  output << "Height: " << getHeightFeet() << "\'" << getHeightInches() << "\"" << "\n" << "Gender: "<< getGender() << " Licnese type: " << getLicenseType();


  return output.str();

}



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setID(std::string iid)
{
    for(int i=0;i<iid.size();i++)
    {

        if (iid[i] < '0' or iid[i]>'9')throw std::invalid_argument("Invalid ID: only digits allowed");

    }

    if( iid.size() != 9 )throw std::invalid_argument("Invalid ID: 9 digit required.");
    // check if all charactors are digits

    ID=iid;

}
    std::string getID()const
 {
     return ID;
 }


//--------------------------------------------------------------------------------------------------------------

void setFirstName(std::string theFirstName)
{
    firstName = theFirstName;
}

std::string getFirstName()const
{
    return firstName;
}

//-----------------------------------------------------------------------------------------------------------------


void setLastName(std::string theLastName)
{
    lastName = theLastName;
}

std::string getLastName()const
{
    return lastName;
}


//--------------------------------------------------------------------------------------------------------------------

void setAddress(std:: string theAddress)
{
    address = theAddress;
}

std::string getAddress()const
{
    return address;
}


//----------------------------------------------------------------------------------------------------------------------

void setExpDate(std::string theExpDate)
{

      if(checkDate(theExpDate))
      expDate = theExpDate;
      else throw std::invalid_argument("Invalid date.");

}

std::string getExpDate()const
{

    return expDate;
}

//----------------------------------------------------------------------------------------------------------------------

void setIssueDate (std::string theIssueDate)
{

     if(checkDate(theIssueDate))
     issueDate = theIssueDate;
    else throw std::invalid_argument("Invalid date.");
}

std::string getIssueDate ()const //THERE IS A TYPO IN THE NAME OF THE FUNCTION IT SHOULD BE getIssueDate
{
    return issueDate;
}


//----------------------------------------------------------------------------------------------------------------------

void setDateOfBirth(std::string dob)
{

    if(checkDate(dob))
    dateOfBirth = dob;
    else throw std::invalid_argument("Invalid date.");

}

std::string getDateOfBirth()const
{

    return dateOfBirth;

}

//----------------------------------------------------------------------------------------------------------------------

void setHeightFeet(int theHeightFeet)
{
    if(theHeightFeet>0)
    heightFeet = theHeightFeet; //YOU NEED TO CHECK IF THE PARAMETER VALUE IS POSITIVE

}

int getHeightFeet()const
{
    return heightFeet;
}

//----------------------------------------------------------------------------------------------------------------------

void setHeightInches(int theHeightInches)
{
    if(theHeightInches>=0)
    heightInches = theHeightInches;//YOU NEED TO CHECK IF THE PARAMETER VALUE IS POSITIVE
}

int getHeightInches()const
{
    return heightInches;
}

//------------------------------------------------------------------------------------------------------------------------

void setLicenseType(std::string theLicenseType)
{
    if(checkClass(theLicenseType))
    licenseType = theLicenseType;
    else throw std::invalid_argument("Invalid license type.");
}

std::string getLicenseType()const
{
    return licenseType;
}

//------------------------------------------------------------------------------------------------------------------------

void setEyeColor(std::string theEyeColor)
{
    eyeColor = theEyeColor;
}

std::string getEyeColor()const
{
    return eyeColor;
}



//------------------------------------------------------------------------------------------------------------------------

void setGender(std::string theGender)
{
    if(checkGender(theGender))
    gender = theGender;
    else throw std::invalid_argument("Gender is invalid. Use M F or X.");
}


std::string getGender()const
{
    return gender;
}
//------------------------------------------------------------------------------------------------------------------------

private :
std::string ID;
std::string firstName;
std::string lastName;
std::string address;
std::string expDate;
std::string issueDate;
std::string dateOfBirth;
int heightFeet;
int heightInches;
std::string licenseType;
std::string eyeColor;
std::string gender;

bool checkDate(std::string dob)
{    //check if it is 10 characters
    if(dob.size()!= 10) return false;

    for(size_t i = 0; i < dob.size(); i++)
    {
        if (i == 2 or i == 5 )
        {
          if ( dob[i] != '/' )
         return false;
          //check if dob[i] is /
        }
        else{

            if(dob[i]<'0' or dob[i] > '9' )
            return false;

            //check if dob[i] is digit
        }



    }

    //     M M / D D / Y Y Y Y
    //     0 1 2 3 4 5 6 7 8 9

    int month , day , year ;
    std::istringstream stream1(dob.substr(0,2));
    stream1 >> month;
    std::istringstream stream2(dob.substr(3,2));
    stream2 >> day;
    std::istringstream stream3(dob.substr(6,4));
    stream3 >> year;
    // get the day and year

    if(year<=1900 or year >=2024)
    return false;

    if(month<1 or month >12)
    return false;


    static const std::array <int,13>daysPerMonth = {0, 31, 28, 31, 30,31,30,31,31,30,31,30,31};
                                                  //YOU DONT NEED THIS FOR LOOP, YOU ONLY NEED THE MONTH VALUE : daysPerMonth[month]
    if(day > daysPerMonth[month] or day  <= 0 ) // USE REVERSE CONTROL day > daysPerMonth[month] or day <=0
      return false;
    return true;
}
//-------------------------------------------------------------------------------------------------

bool checkClass(std::string cc) //LOWER CASE cc
{
    static const std::array<std::string,8>types{"A","B","C","D","DJ","E","M","MJ"  };
    for(size_t i=0;i < 8 ; i++)
    {
     if(types[i]==cc)
     return true;
    }
    return false;
}

//--------------------------------------------------------------------------------------------------

bool checkGender(std::string cg )
   {
     static const std::array<std::string,3>genders{"M","F","X"};

     for( size_t i=0; i < genders.size(); i++ )
    {
        if(genders[i]==cg)
        return true;
    }



     return false;

   }





};


#endif