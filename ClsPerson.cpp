#include "ClsPerson.hh"


void ClsPerson::setFirstName(string FirstName){
    _firstName=FirstName;
}
void ClsPerson::setLastName(string LastName){
    _lastName=LastName;
}
void ClsPerson::setEmail(string Email){
    _email=Email;
}
void ClsPerson::setPhone(string Phone){
    _phone=Phone;
}


string ClsPerson::getFirstName(){
    return _firstName;
}
string ClsPerson::getLastName(){
    return _lastName;
}
string ClsPerson::getEmail(){
    return _email;
}
string ClsPerson::getPhone(){
    return _phone;
}


ClsPerson::ClsPerson(string FirstName, string LastName, string Email, string Phone){
    _firstName=FirstName;
    _lastName=LastName;
    _email=Email;
    _phone=Phone;
}
ClsPerson::ClsPerson(string FirstName, string LastName,string Phone){
    _firstName=FirstName;
    _lastName=LastName;
    _phone=Phone;
}

string ClsPerson::getFullName(){
    return (_firstName+" "+_lastName);
}
void ClsPerson::print(){
    cout<<"\n-------------------------";
    cout<<"\nFirstName: "<<_firstName;
    cout<<"\nLastName : "<<_lastName;
    cout<<"\nEmail    :"<<_email;
    cout<<"\nPhone    :"<<_phone;
    cout<<"\n-------------------------\n";
}
void ClsPerson::sendEmail(string Subject, string Body){
    cout<<"\nsent successfully to Email: "<<_email;
    cout<<"\nSubject: "<<Subject;
    cout <<"\nBody: "<<Body;
}
void ClsPerson::sendSMS(string TXTMessage){
    cout<<"\nsent successfully to Number: "<<_phone;
    cout<<"TEXT"<<TXTMessage;
}








