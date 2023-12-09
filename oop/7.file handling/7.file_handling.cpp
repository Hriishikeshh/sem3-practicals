#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
    ofstream fileStream;

    public:
        FileHandler() {
            fileStream.open("data.txt", ios::app);
        }

        void appendData(string& data) {
            fileStream << data << "\n";
        }

        void displayData() {
            fileStream.close(); // Close for writing
            ifstream inputFile("data.txt");
            string line;
            cout << "Content of data.txt:\n";
            while (getline(inputFile, line)) {
                cout << line << endl;
            }
            inputFile.close(); // Close input file stream
            fileStream.open("data.txt", ios::app); // Reopen for appending
        }

        ~FileHandler() {
            fileStream.close(); // Close the file when the object is destroyed
        }
};

int main() {

    //open and write
    fstream fout;
    string line;

    fout.open("data.txt",ios::out);
    while(fout){
        getline(cin,line);
        if(line=="-1"){
            break;
        }
        fout<<line<<endl;
    }
    fout.close();

    //display data

    string choice;
    while (true) {
        cout << "Create a FileHandler object? (yes/no): ";
        cin >> choice;
        if (choice != "yes") {
            break;
        }
        FileHandler file;
        string data;
        cout << "Enter data to append to the file: ";
        cin.ignore();   //as cin used while file is created opened written earlier
        getline(cin, data);
        file.appendData(data);
        file.displayData();
    }
    return 0;
}