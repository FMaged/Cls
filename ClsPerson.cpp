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















