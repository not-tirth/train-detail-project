#include <iostream>
using namespace std;

class Train
{
private:
    string trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

public:
    static int trainCount;

    Train()
    {
        trainCount++;

        this->trainNumber = "";
        this->trainName = "";
        this->source = "";
        this->destination = "";
        this->trainTime = "";
    }

    Train(string trainNumber, string trainName, string source,
          string destination, string trainTime)
    {
        trainCount++;

        this->trainNumber = trainNumber;
        this->trainName = trainName;
        this->source = source;
        this->destination = destination;
        this->trainTime = trainTime;
    }

    ~Train()
    {
        trainCount--;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> this->trainNumber;

        cout << "Enter Train Name: ";
        cin >> this->trainName;

        cout << "Enter Source: ";
        cin >> this->source;

        cout << "Enter Destination: ";
        cin >> this->destination;

        cout << "Enter Train Time: ";
        cin >> this->trainTime;
    }

    string getTrainNumber()
    {
        return this->trainNumber;
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << this->trainNumber << endl;
        cout << "Train Name: " << this->trainName << endl;
        cout << "Source: " << this->source << endl;
        cout << "Destination: " << this->destination << endl;
        cout << "Train Time: " << this->trainTime << endl;
        cout<<"\n";
        
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

int main()
{
    int choice;

    Train trains[] =
    {
        Train("1", "GujaratExpress", "Ahmedabad", "Mumbai", "10AM"),
        Train("2", "RajdhaniExpress", "Delhi", "Mumbai", "12PM"),
        Train("3", "ShatabdiExpress", "Ahmedabad", "Mumbai", "2PM"),
        Train("4", "OkhaExpress", "Surat", "Mumbai", "5PM")
    };

    int totalTrain = 4;

    while (true)
    {
        cout << "\n Railway Reservation System Menu " << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            if (totalTrain < 4)
            {
                trains[totalTrain].inputTrainDetails();
                totalTrain++;
            }
            else
            {
                cout << "No space for new train!" << endl;
            }

            break;

        case 2:

            for (int i = 0; i < totalTrain; i++)
            {
                trains[i].displayTrainDetails();
            }

            break;

        case 3:
        {
            string searchTrainNumber;

            cout << "Enter Train Number to search: ";
            cin >> searchTrainNumber;

            for (int i = 0; i < totalTrain; i++)
            {
                if (trains[i].getTrainNumber() == searchTrainNumber)
                {
                    trains[i].displayTrainDetails();
                    break;
                }
            }

            break;
        }

        case 4:

            cout << "Exit" << endl;
            return 0;

        default:

            cout << "Invalid" << endl;
        }
    }

    return 0;
}