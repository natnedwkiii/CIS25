#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Class for my dataset
class MarketData {
public:
    string date;
    double bitcoin;
    double brentOil;
    double crudeWTI;
    double gold;
    double sp500;

    // Constructor
    MarketData(string d, double b, double br, double cw, double g, double sp) {
        date = d;
        bitcoin = b;
        brentOil = br;
        crudeWTI = cw;
        gold = g;
        sp500 = sp;
    }

    // Display function
    void display() {
        cout << date << " | "
             << bitcoin << " | "
             << brentOil << " | "
             << crudeWTI << " | "
             << gold << " | "
             << sp500 << endl;
    }
};

//main
int main() {

    // Open CSV
    ifstream file("SP500 oil gold bitcoin.csv");

    // Check to see if file opened
    if (!file.is_open()) {
        cout << "File failed to open." << endl;
        return 1;
    }

    string line;
    vector<MarketData> dataList;

    // Skip the header row
    getline(file, line);

    int count = 0;

    // Read 1st 10 rows
    while (getline(file, line) && count < 10) {

        stringstream ss(line);

        string date, bitcoin, brent, wti, gold, sp;

        getline(ss, date, ',');
        getline(ss, bitcoin, ',');
        getline(ss, brent, ',');
        getline(ss, wti, ',');
        getline(ss, gold, ',');
        getline(ss, sp, ',');

        MarketData row(
            date,
            stod(bitcoin),
            stod(brent),
            stod(wti),
            stod(gold),
            stod(sp)
        );

        dataList.push_back(row);
        count++;
    }

    file.close();

    cout << "First 10 rows of dataset:" << endl;

    for (int i = 0; i < dataList.size(); i++) {
        dataList[i].display();
    }

    return 0;
}