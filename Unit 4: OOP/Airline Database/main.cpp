#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <typeinfo>

//Classes
#include "user.h"
#include "customer.h"
#include "employee.h"
#include "flight.h"
#include "seat.h"

using namespace std;

static vector<Flight> flights;
static auto * currentUser = new User("Guest user");

bool inRange(int flightNumber, int seatNumber);
void printFlight(int flightNumber, Flight *flight);
bool incomplete(istringstream *ss);

int main(){
    cout << "Welcome to the Airline Database!" << endl;
    cout << "Type help for a list of commands." << endl;
    
    while(true){
        cout << endl;
        cout << '[' << currentUser->getName() << ']' << endl << ">> ";
        
        //Get input
        string input;
        getline(cin, input);
        istringstream commandss(input);
        
        string command;
        commandss >> command;

        //exit
        if(command == "exit"){
            return 1;
        }
        //help
        else if(command == "help"){
            cout << "-------------------------------------------------" << endl << "Commands:" << endl;
            cout << "Disclaimer: Extra arguments will not be accepted!" << endl;
            cout << "Discalimer: Do not put spaces when inputting parameters. Doing so may disrupt the system." << endl << endl;
            cout << "\"help\": Brings up this list of commands" << endl;
            cout << "\"exit\": Exits the program" << endl;
            cout << "\"newUser [type] [username] ([address] [phoneNumber] if customer)\": Creates a new user with specified parameters" << endl;
            cout << "\"profile\": Brings up user information" << endl;
            cout << "\"bookTicket [flightNumber] [seatNumber]\": Books the seat seatNumber on flight flightNumber" << endl;
            cout << "\"cancelTicket [flightNumber] [seatNumber]\": Cancels booking for the seat seatNumber on flight flightNumber" << endl;
            cout << "\"getFlight [flightNumber]\": Checks the flight flightNumber" << endl;
            cout << "\"getAllFlights\": Brings up a list of every flight" << endl;
            cout << "\"cancelFlight [flightNumber]\": Cancels the flight flightNumber" << endl;
            cout << "\"newFlight [seatCount]\": Adds a new flight with seatCount seats" << endl;
        }
        //new user
        else if(command == "newUser"){
            string newUserType, newUserName;
            commandss >> newUserType >> newUserName;
            if(newUserName.empty() || newUserType.empty()){
                cout << "One or more arguments is missing. Please try again." << endl;
                continue;
            }
            if(newUserType == "customer"){
                string newAddress, newPhone;
                commandss >> newAddress >> newPhone;
                if(newAddress.empty() || newPhone.empty()){
                    cout << "One or more arguments is missing. Please try again." << endl;
                    continue;
                }
                
                currentUser = new Customer(newUserName, newAddress, newPhone);
                //safe conversion of pointers to classes within an inheritance hierarchy
                auto* thisUser = dynamic_cast<Customer *>(currentUser);
                //Feedback
                cout << "Customer has been successfully created." << endl;
                cout << "Name: " << thisUser->getName() << endl;
                cout << "Address: " << thisUser->getAddress() << endl;
                cout << "Phone: " << thisUser->getPhone() << endl;
            }
            else if(newUserType == "employee"){
                currentUser = new Employee(newUserName);
                auto* thisUser = dynamic_cast<Employee *>(currentUser);
                //Feedback
                cout << "Employee has been successfully created." << endl;
                cout << "Name: " << thisUser->getName() << endl;
            }
            else{
                //Invalid type
                cout << "Invalid user type. Please try again." << endl;
            }
        }
        //display user info
        else if(command == "profile"){
            if(currentUser->getType() == "customer"){
                auto* thisUser = dynamic_cast<Customer *>(currentUser);
                cout << "User information: " << endl;
                cout << "Name: " << thisUser->getName() << endl;
                cout << "Address: " << thisUser->getAddress() << endl;
                cout << "Phone: " << thisUser->getPhone() << endl;
            }
            else if(currentUser->getType() == "employee"){
                auto* thisUser = dynamic_cast<Employee *>(currentUser);
                cout << "User information: " << endl;
                cout << "Name: " << thisUser->getName() << endl;
            }
            else{
                cout << "Invalid user type." << endl;
            }
        }
        //check ticket
        else if(command == "bookTicket"){
            int flightNumber, seatNumber;
            if(commandss.eof()){
                cout << "Flight number is missing." << endl;
                continue;
            }
            commandss >> flightNumber;
            if(commandss.eof()){
                cout << "Seat number is missing." << endl;
                continue;
            }
            commandss >> seatNumber;
            
            //check user type
            if(currentUser->getType() != "customer"){
                cout << "Only customers can book tickets." << endl;
                continue;
            }
            
            //check range of flight and seat numbers
            if(!inRange(flightNumber, seatNumber)) continue;
            Flight* currentFlight = &flights[flightNumber - 1];
            
            if(currentFlight->fullFlight()){
                cout << "This flight is fully booked. Please try another flight." << endl;
                continue;
            }
            else if(!currentFlight->checkAvailability(seatNumber - 1)){
                cout << "This seat is already booked. Please try another seat." << endl;
                cout << "Seats: " << endl << "---------------" << endl;
                printFlight(flightNumber, currentFlight);
                continue;
            }
            
            currentFlight->setSeat(seatNumber - 1, Seat(seatNumber - 1, dynamic_cast<Customer *>(currentUser)));
            //print flight information
            cout << "Seats: " << endl << "---------------" << endl;
            printFlight(flightNumber, currentFlight);
        }
        //cancel ticket
        else if(command == "cancelTicket"){
            int flightNumber, seatNumber;
            if(commandss.eof()){
                cout << "Flight number is missing." << endl;
                continue;
            }
            commandss >> flightNumber;
            if(commandss.eof()){
                cout << "Seat number is missing." << endl;
                continue;
            }
            commandss >> seatNumber;
            
            if(!inRange(flightNumber, seatNumber)) continue;
            Flight* currentFlight = &flights[flightNumber - 1];
            
            if(currentFlight->checkAvailability(seatNumber - 1)){
                cout << "Seat is currently available and cannot be cancelled." << endl;
                continue;
            }
            
            auto thisUser = *dynamic_cast<Customer *>(currentUser);
            Customer otherUser = currentFlight->checkCustomer(seatNumber - 1);
            if(thisUser.getType() == "customer" && !(otherUser == thisUser)){
                cout << "You did not book this seat and cannot cancel it." << endl;
                continue;
            }
            
            flights[flightNumber - 1].setSeat(seatNumber - 1, Seat());
            cout << "Seat " << seatNumber << " has been successfully cancelled." << endl;
            cout << "Seats: " << endl;
            printFlight(flightNumber, currentFlight);
        }
        //check flight
        else if(command == "getFlight"){
            int flightNumber;
            if(commandss.eof()){
                cout << "One or more arguments is missing. Please try again." << endl;
                continue;
            }
            commandss >> flightNumber;
            if(flightNumber <= 0 || flightNumber > flights.size()){
                cout << "Flight number is out of range. Please try again." << endl;
                continue;
            }
            printFlight(flightNumber, &flights[flightNumber -1]);
        }
        //list of flights
        else if(command == "getAllFlights"){
            for(int i = 0; i < flights.size(); i++){
                printFlight(i + 1, &flights[i]);
            }
        }
        //cancel flight
        else if(command == "cancelFlight"){
            int flightNumber;
            if(commandss.eof()){
                cout << "Flight number is missing." << endl;
                continue;
            }
            commandss >> flightNumber;
            if(flightNumber <= 0 || flightNumber > flights.size()){
                cout << "Flight number is out of range." << endl;
                continue;
            }
            Flight* currentFlight = &flights[flightNumber - 1];
            for(int i = 0; i < currentFlight->getSeatCount(); i++){
                if(!currentFlight->checkAvailability(i)){
                    cout << "Seat " << i << " is currently occupied by " << currentFlight->checkCustomer(i).toString() << endl;
                }
            }
            flights.erase(flights.begin() + flightNumber - 1);
            cout << "Flight " << flightNumber << " has been successfully cancelled" << endl;
        }
        //add a new flight
        else if(command == "newFlight"){
            if(currentUser->getType() != "employee"){
                cout << "Only employees are allowed to add flights.";
                continue;
            }
            int seatCount;
            cout << commandss.eof() << endl;
            if(incomplete(&commandss)) continue;
            commandss >> seatCount;
            flights.emplace_back(seatCount);
            cout << "New flight with " << seatCount <<  " seats has been successfully added." << endl;
            printFlight(flights.size() - 1, &flights[flights.size() - 1]);
        }
        //invaild command
        else{
            cout << "Command \"" << command << "\" is invalid. Please try again." << endl;
        }
    }
    return 0;
}

bool inRange(int flightNumber, int seatNumber){
    if(flightNumber <= 0 || flightNumber > flights.size()){
        cout << "Flight number is out of range. Please try again." << endl;
        return false;
    }
    Flight* currentFlight = &flights[flightNumber - 1];
    if(seatNumber <= 0 || seatNumber > currentFlight->getSeatCount()){
        cout << "Seat number is out of range. Please try again" << endl;
        return false;
    }
    return true;
}

void printFlight(int flightNumber, Flight* flight){
    cout << "Flight: " << flightNumber << endl;
    for(int i = 0; i < flight->getSeatCount(); i++){
        cout << (flight->checkAvailability(i) ? "O" : "X") << " ";
    }
    cout << endl;
}

bool incomplete(istringstream* ss){
    if(ss->eof()){
        cout << "One or more arguments are missing. Please try again." << endl;
        return true;
    }
    return false;
}






