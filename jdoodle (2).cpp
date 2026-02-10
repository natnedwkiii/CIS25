// Instructions: Debug the following code. 
// Output the highest of three inputs. 
// Update the code to be nested if statement.
// Write a comment above each line of code your fixed


#include <iostream>
using namespace std;
int main() {
    // need comma between each variable, then next line is "; "
    float n1,n2,n3;
    
    cout << "Enter three numbers: ";
    
    // two >> . and should be n2
    cin >> n1>> n2 >> n3;
    
    // it is if n1>=n2 and n1>=n3 , then the largest number is n1. also missing the closing parenthese and {}
    if(n1 >= n2 && n1>= n3){
        cout << "Largest number: "<< n1;
    }
    
    //it is if n2>=n1 and n1>=n3, missing the closing parenthese
    else if(n2 >= n1 && n2>= n3){
     //missing closing curly  bracket & it should show n2
        cout << "Largest number: " << n2;
    }
    
    //it is if n3>=n1 and "&& n1"is extra, missing the open curly  bracket
    else if (n3>=n1 && n3>=n2){
    // it should show n3
        cout <<  "Largest number: " << n3;
    }
    return 0;

}
