
 #include <iostream>
 using namespace std;

int main() {
     int sides = 6;
     cout<<"The distribution for all the pairs when two dices and rolled simultanetously"<<"\n";

     cout<<"{"<<"\n";
    for (int diceA = 1; diceA <= sides; ++diceA) {
        for (int diceB = 1; diceB <= sides; ++diceB) {
            cout<<"{"<<diceA<<","<<diceB<<"}"<<",";
             
        }
        cout<<"\n";
    }
    
    cout<<"}";

    

    return 0;
}
