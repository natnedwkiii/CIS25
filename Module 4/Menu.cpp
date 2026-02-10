

#include <iostream>

using namespace std;

int main() {
    int choice ;
    
    cout << "What do you want to eat for dinner?" << endl;
    cout << "1. Korean BBQ" << endl;
    cout << "2. Sushi" << endl;
    cout << "3. Hotpot" << endl;
    cout << "4. Mala Tang" << endl;
    cout << "Enter your number: ";
    cin >> choice ;
    
    if (choice == 1){
        cout << "The best Korean BBQ resturants near Oakland : 1. Jong Ga House, 2. Gen 3. Ohgane"<< endl;
    }
    
    else if (choice == 2){
        cout << "The best Sushi resturants near Oakland : 1. Meat time, 2.Tokyo Central"<< endl;
    }

    else if (choice == 3){
        cout << "The best Hotpot resturants near Oakland : 1. Mumu, 2. Little Sheep 3. Wasabi"<< endl;
    }
    
    else if (choice == 4){
        cout << "The best Mala Tang resturants near Oakland : 1. Tanghuo, 2. Zhengfei"<< endl;
    }
    
    else{
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
    
    }
