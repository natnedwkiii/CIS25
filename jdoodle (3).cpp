#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Step 1: Struct
//(patient profile)
struct Patient {
    // ID, name, age, gender, diagnosis.
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

// Function prototypes
//1. Add Patient
void addPatient(Patient* patients, int& count);
//2. Display Patients
void displayPatients(Patient* patients, int count);
//3. Search Patient
int binarySearch(Patient* patients, int count, int searchID);
//4. Update Patient
void updatePatient(Patient* patients, int count);
//5. Save to File
void saveToFile(Patient* patients, int count);
//sort
void sortPatients(Patient* patients, int count);


//main function: 
int main() {
    const int MAX = 100;
    Patient* patients = new Patient[MAX]; // Step 2: Dynamic array
    int count = 0;
    int choice;

    do {
        cout << "\nHospital Patient System\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient\n";
        cout << "5. Save to File\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        //display the choice
        switch (choice) {
            // add patient
            case 1:
                addPatient(patients, count);
                sortPatients(patients, count); // needed for binary search
                break;
            //show patient
            case 2:
                displayPatients(patients, count);
                break;
            //menu
            case 3: {
                int id;
                cout << "Enter Patient ID to search: ";
                cin >> id;
                int index = binarySearch(patients, count, id);
                if (index != -1) {
                    cout << "\nPatient Found:\n";
                    cout << "ID: " << patients[index].id << endl;
                    cout << "Name: " << patients[index].name << endl;
                    cout << "Age: " << patients[index].age << endl;
                    cout << "Gender: " << patients[index].gender << endl;
                    cout << "Diagnosis: " << patients[index].diagnosis << endl;
                } else {
                    cout << "Patient not found.\n";
                }
                break;
            }
            //update
            case 4:
                updatePatient(patients, count);
                break;
            //save
            case 5:
                saveToFile(patients, count);
                break;
            //exit
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    delete[] patients;
    return 0;
}

// Add Patient
void addPatient(Patient* patients, int& count) {
    
    //ID
    cout << "\nEnter Patient ID: ";
    cin >> patients[count].id;

    //name
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, patients[count].name);

    //age
    cout << "Enter Age: ";
    cin >> patients[count].age;

    //gender
    cin.ignore();
    cout << "Enter Gender: ";
    getline(cin, patients[count].gender);

    //diagnosis
    cout << "Enter Diagnosis: ";
    getline(cin, patients[count].diagnosis);

    count++;
}

// Display Patients
void displayPatients(Patient* patients, int count) {
    if (count == 0) {
        cout << "No records found.\n";
        return;
    }

    //loop all patient
    cout << "\nPatient Records:\n";
    for (int i = 0; i < count; i++) {
        cout << "\nID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << endl;
    }
}

// Binary Search (Step 6)
int binarySearch(Patient* patients, int count, int searchID) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (patients[mid].id == searchID)
            return mid;
        else if (patients[mid].id < searchID)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Update Patient
void updatePatient(Patient* patients, int count) {
    int id;
    cout << "Enter Patient ID to update: ";
    cin >> id;

    int index = binarySearch(patients, count, id);

    if (index != -1) {
        cin.ignore();
        cout << "Enter new diagnosis: ";
        getline(cin, patients[index].diagnosis);
        cout << "Updated successfully.\n";
    } else {
        cout << "Patient not found.\n";
    }
}

// Save to file
void saveToFile(Patient* patients, int count) {
    ofstream file("patients.txt");

    for (int i = 0; i < count; i++) {
        file << patients[i].id << " "
             << patients[i].name << " "
             << patients[i].age << " "
             << patients[i].gender << " "
             << patients[i].diagnosis << endl;
    }

    file.close();
    cout << "Data saved to patients.txt\n";
}

// Sort patients by ID (required for binary search)
void sortPatients(Patient* patients, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (patients[j].id > patients[j + 1].id) {
                swap(patients[j], patients[j + 1]);
            }
        }
    }
}