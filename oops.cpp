#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string gender;

public:
    Person()
    {
        name = "";
        age = 0;
        gender = "";
    }

    Person(string n, int a, string g)
    {
        name = n;
        age = a;
        gender = g;
    }

    int getAge() const
    {
        return age;
    }

    virtual void displayPerson() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Passenger : virtual public Person
{
private:
    string passengerId;
    string contactNumber;

    static int totalPassengers;

public:
    Passenger()
    {
        passengerId = "";
        contactNumber = "";
        totalPassengers++;
    }

    Passenger(string id, string n, int a, string g, string contact)
        : Person(n, a, g)
    {
        passengerId = id;
        contactNumber = contact;
        totalPassengers++;
    }

    void setPassengerId(string passengerId)
    {
        this->passengerId = passengerId;
    }

    void setContactNumber(string contactNumber)
    {
        this->contactNumber = contactNumber;
    }

    static int getTotalPassengers()
    {
        return totalPassengers;
    }

    void displayPassenger() const
    {
        cout << "\n----- PASSENGER -----" << endl;
        cout << "Passenger ID: " << passengerId << endl;
        displayPerson();
        cout << "Contact Number: " << contactNumber << endl;
    }

    friend ostream& operator<<(ostream& out, const Passenger& p)
    {
        out << "\n----- STREAM OPERATOR -----" << endl;
        out << "Passenger ID: " << p.passengerId << endl;
        out << "Name: " << p.name << endl;
        out << "Age: " << p.age << endl;
        out << "Gender: " << p.gender << endl;
        out << "Contact Number: " << p.contactNumber << endl;

        return out;
    }

    friend istream& operator>>(istream& in, Passenger& p)
    {
        cout << "Enter Passenger ID: ";
        in >> p.passengerId;

        in.ignore();

        cout << "Enter Passenger Name: ";
        getline(in, p.name);

        cout << "Enter Age: ";
        in >> p.age;

        cout << "Enter Gender: ";
        in >> p.gender;

        cout << "Enter Contact Number: ";
        in >> p.contactNumber;

        return in;
    }
};

int Passenger::totalPassengers = 0;

class PremiumPassenger : public Passenger
{
public:
    PremiumPassenger()
    {
    }

    PremiumPassenger(string id, string n, int a, string g, string contact)
        : Passenger(id, n, a, g, contact)
    {
    }
};


class Train
{
private:
    string trainNumber;
    string trainName;
    string source;
    string destination;
    string departureTime;
    string arrivalTime;
    double baseFare;

public:

    class Schedule
    {
    private:
        string departure;
        string arrival;

    public:
        Schedule(string d, string a)
        {
            departure = d;
            arrival = a;
        }

        void displaySchedule()
        {
            cout << "\n----- NESTED CLASS: SCHEDULE -----" << endl;
            cout << "Departure: " << departure << endl;
            cout << "Arrival: " << arrival << endl;
        }
    };

    Train()
    {
        trainNumber = "";
        trainName = "";
        source = "";
        destination = "";
        departureTime = "";
        arrivalTime = "";
        baseFare = 0;
    }

    Train(string number, string name, string src, string dest,
          string departure, string arrival, double fare)
    {
        trainNumber = number;
        trainName = name;
        source = src;
        destination = dest;
        departureTime = departure;
        arrivalTime = arrival;
        baseFare = fare;
    }

    double getFare()
    {
        return baseFare;
    }

    double getFare(string travelClass)
    {
        if (travelClass == "3AC")
            return baseFare + 500;

        if (travelClass == "2AC")
            return baseFare + 1000;

        if (travelClass == "1AC")
            return baseFare + 1500;

        return baseFare;
    }

    double getFare(string travelClass, int age)
    {
        double fare = getFare(travelClass);

        if (age < 12)
            return fare * 0.50;

        return fare;
    }

    void displayTrain()
    {
        cout << "\n----- TRAIN -----" << endl;
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Arrival Time: " << arrivalTime << endl;
        cout << "Base Fare: " << baseFare << endl;
    }
};

class Seat
{
private:
    string seatNumber;
    string travelClass;
    string status;

public:
    Seat()
    {
        seatNumber = "";
        travelClass = "";
        status = "Available";
    }

    Seat(string number, string cls)
    {
        seatNumber = number;
        travelClass = cls;
        status = "Available";
    }

    void reserve()
    {
        status = "Reserved";
    }

    void release()
    {
        status = "Available";
    }

    void displaySeat()
    {
        cout << "\n----- SEAT -----" << endl;
        cout << "Seat Number: " << seatNumber << endl;
        cout << "Travel Class: " << travelClass << endl;
        cout << "Status: " << status << endl;
    }
};

class Payment
{
private:
    string paymentId;
    double amount;
    string paymentMethod;
    string status;
    string paymentDate;

public:
    Payment()
    {
        paymentId = "";
        amount = 0;
        paymentMethod = "";
        status = "Pending";
        paymentDate = "";
    }

    Payment(string id, double amt, string method, string date)
    {
        paymentId = id;
        amount = amt;
        paymentMethod = method;
        status = "Success";
        paymentDate = date;
    }

    void displayPayment()
    {
        cout << "\n----- PAYMENT -----" << endl;
        cout << "Payment ID: " << paymentId << endl;
        cout << "Amount: " << amount << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Status: " << status << endl;
        cout << "Payment Date: " << paymentDate << endl;
    }

    friend bool operator==(const Payment& p1, const Payment& p2)
    {
        return p1.amount == p2.amount;
    }

    friend bool operator!=(const Payment& p1, const Payment& p2)
    {
        return p1.amount != p2.amount;
    }

    friend bool operator>(const Payment& p1, const Payment& p2)
    {
        return p1.amount > p2.amount;
    }
};

class PaymentGateway final
{
private:
    string gatewayId;
    string provider;

public:
    PaymentGateway()
    {
        gatewayId = "";
        provider = "";
    }

    PaymentGateway(string id, string p)
    {
        gatewayId = id;
        provider = p;
    }

    bool processPayment(Payment& payment)
    {
        cout << "\nPayment processed successfully through "
             << provider << endl;
        return true;
    }

    void displayGateway()
    {
        cout << "\n----- PAYMENT GATEWAY -----" << endl;
        cout << "Gateway ID: " << gatewayId << endl;
        cout << "Provider: " << provider << endl;
    }
};

class Ticket
{
private:
    string pnrNumber;
    string journeyDate;
    string travelClass;
    string ticketType;
    string status;

public:
    Ticket()
    {
        pnrNumber = "";
        journeyDate = "";
        travelClass = "";
        ticketType = "";
        status = "Waiting";
    }

    Ticket(string pnr, string date, string cls, string type)
    {
        pnrNumber = pnr;
        journeyDate = date;
        travelClass = cls;
        ticketType = type;
        status = "Confirmed";
    }

    void cancelTicket()
    {
        status = "Cancelled";
    }

    void displayTicket()
    {
        cout << "\n----- TICKET -----" << endl;
        cout << "PNR Number: " << pnrNumber << endl;
        cout << "Journey Date: " << journeyDate << endl;
        cout << "Ticket Type: " << ticketType << endl;
        cout << "Travel Class: " << travelClass << endl;
        cout << "Status: " << status << endl;
    }

    string getPNR()
    {
        return pnrNumber;
    }
};

class Notification
{
private:
    string notificationId;
    string type;
    string message;
    string timestamp;

public:
    Notification()
    {
        notificationId = "";
        type = "";
        message = "";
        timestamp = "";
    }

    Notification(string id, string t, string msg, string time)
    {
        notificationId = id;
        type = t;
        message = msg;
        timestamp = time;
    }

    void send()
    {
        cout << "\n----- NOTIFICATION -----" << endl;
        cout << "Notification ID: " << notificationId << endl;
        cout << "Type: " << type << endl;
        cout << "Message: " << message << endl;
        cout << "Timestamp: " << timestamp << endl;
        cout << "Notification sent successfully." << endl;
    }
};

class FareAmount
{
private:
    double amount;
public:
    FareAmount(double a)
    {
        amount = a;
    }

    operator double() const
    {
        return amount;
    }
};

class DiscountedFare
{
private:
    double amount;

public:
    DiscountedFare(const FareAmount& fare)
    {
        double originalAmount = fare;
        amount = originalAmount * 0.90;
    }

    void display() const
    {
        cout << "Fare after 10% discount: " << amount << endl;
    }
};

template <class T>
void displayValue(T value)
{
    cout << "Template value: " << value << endl;
}

int main()
{
    Passenger p1;

    cout << "===== PASSENGER INPUT =====" << endl;
    cin >> p1;

    cout << p1;

    cout << "\nTotal Passengers: "
         << Passenger::getTotalPassengers() << endl;

    Passenger* pPtr = &p1;

    cout << "\n----- POINTER TO OBJECT -----" << endl;
    pPtr->displayPassenger();


    PremiumPassenger premium(
        "P999",
        "Premium Passenger",
        25,
        "Male",
        "9999999999"
    );

    PremiumPassenger* derivedPtr = &premium;

    cout << "\n----- POINTER TO DERIVED CLASS -----" << endl;
    derivedPtr->displayPassenger();

    Person* personPtr = &p1;

    cout << "\n----- VIRTUAL FUNCTION -----" << endl;
    personPtr->displayPerson();

    string ticketType;
    int ticketChoice;

    cout << "\n===== TICKET BOOKING TYPE =====" << endl;
    cout << "1. Normal" << endl;
    cout << "2. Tatkal" << endl;
    cout << "3. Premium Tatkal" << endl;
    cout << "4. Ladies Quota" << endl;
    cout << "5. Senior Citizen" << endl;

    cout << "Enter Ticket Type: ";
    cin >> ticketChoice;

    switch (ticketChoice)
    {
        case 1:
            ticketType = "Normal";
            break;

        case 2:
            ticketType = "Tatkal";
            break;

        case 3:
            ticketType = "Premium Tatkal";
            break;

        case 4:
            ticketType = "Ladies Quota";
            break;

        case 5:
            ticketType = "Senior Citizen";
            break;

        default:
            ticketType = "Normal";
            cout << "Invalid choice. Normal ticket selected." << endl;
    }

    cout << "Selected Ticket Type: "
         << ticketType << endl;

    string trainNumber, trainName, source, destination;
    string departureTime, arrivalTime;
    double baseFare;

    cout << "\n===== TRAIN DETAILS =====" << endl;

    cout << "Enter Train Number: ";
    cin >> trainNumber;

    cin.ignore();

    cout << "Enter Train Name: ";
    getline(cin, trainName);

    cout << "Enter Source: ";
    getline(cin, source);

    cout << "Enter Destination: ";
    getline(cin, destination);

    cout << "Enter Departure Time: ";
    cin >> departureTime;

    cout << "Enter Arrival Time: ";
    cin >> arrivalTime;

    cout << "Enter Base Fare: ";
    cin >> baseFare;

    Train t1(
        trainNumber,
        trainName,
        source,
        destination,
        departureTime,
        arrivalTime,
        baseFare
    );

    t1.displayTrain();

    Train::Schedule schedule(departureTime, arrivalTime);
    schedule.displaySchedule();

    string seatNumber, travelClass;

    cout << "\nEnter Seat Number: ";
    cin >> seatNumber;

    cout << "Enter Travel Class: ";
    cin >> travelClass;

    Seat s1(seatNumber, travelClass);

    s1.reserve();
    s1.displaySeat();

    string pnrNumber, journeyDate;

    cout << "\nEnter PNR Number: ";
    cin >> pnrNumber;

    cout << "Enter Journey Date: ";
    cin >> journeyDate;

    Ticket tk1(
        pnrNumber,
        journeyDate,
        travelClass,
        ticketType
    );

    tk1.displayTicket();

    cout << "\n----- METHOD OVERLOADING -----" << endl;

    cout << "Base Fare: "
         << t1.getFare() << endl;

    cout << travelClass << " Fare: "
         << t1.getFare(travelClass) << endl;

    cout << travelClass << " Fare for Age: "
         << t1.getFare(travelClass, p1.getAge())
         << endl;

    string paymentId, paymentMethod, paymentDate;
    double amount;

    cout << "\nEnter Payment ID: ";
    cin >> paymentId;

    cout << "Enter Payment Amount: ";
    cin >> amount;

    cout << "Enter Payment Method: ";
    cin >> paymentMethod;

    cout << "Enter Payment Date: ";
    cin >> paymentDate;

    Payment pay1(
        paymentId,
        amount,
        paymentMethod,
        paymentDate
    );

    pay1.displayPayment();

    string gatewayId, provider;

    cout << "\nEnter Payment Gateway ID: ";
    cin >> gatewayId;

    cout << "Enter Payment Provider: ";
    cin >> provider;

    PaymentGateway pg1(gatewayId, provider);

    pg1.displayGateway();
    pg1.processPayment(pay1);

    cout << "\n----- OPERATOR OVERLOADING -----" << endl;

    string paymentId2, paymentMethod2, paymentDate2;
    double amount2;

    cout << "Enter Second Payment ID: ";
    cin >> paymentId2;

    cout << "Enter Second Payment Amount: ";
    cin >> amount2;

    cout << "Enter Second Payment Method: ";
    cin >> paymentMethod2;

    cout << "Enter Second Payment Date: ";
    cin >> paymentDate2;

    Payment pay2(
        paymentId2,
        amount2,
        paymentMethod2,
        paymentDate2
    );

    if (pay1 == pay2)
        cout << "Both payments have the same amount." << endl;
    else
        cout << "Payments have different amounts." << endl;

    if (pay1 != pay2)
        cout << "Payments are not equal." << endl;

    if (pay1 > pay2)
        cout << "First payment is greater than second payment." << endl;
    else
        cout << "First payment is not greater than second payment." << endl;

    cout << "\n----- OBJECT SLICING -----" << endl;

    Person slicedPerson = p1;

    cout << "Passenger object copied into Person object:" << endl;
    slicedPerson.displayPerson();

    cout << "\n----- STATIC VARIABLE AND FUNCTION -----" << endl;

    cout << "Total Passengers Created: "
         << Passenger::getTotalPassengers() << endl;

    Notification n1(
        "N001",
        "Booking",
        "Your ticket has been confirmed.",
        "10:30 AM"
    );

    n1.send();
    double basicFare = 1200.0;
    FareAmount fareObject = basicFare;
    cout << "\n----- BASIC-TO-CLASS TYPECASTING -----" << endl;
    cout << "Basic fare converted to class object." << endl;

    double convertedFare = fareObject;
    cout << "\n----- CLASS-TO-BASIC TYPECASTING -----" << endl;
    cout << "Fare object converted to double: "
         << convertedFare << endl;

    DiscountedFare discountedObject = fareObject;
    cout << "\n----- CLASS-TO-CLASS TYPECASTING -----" << endl;
    discountedObject.display();

    cout << "\n----- FUNCTION TEMPLATE -----" << endl;
    displayValue<int>(100);
    displayValue<double>(250.50);
    displayValue<string>("Railway Reservation");
    return 0;
}