#include <iostream>

int main() {
    const int sides = 6;
    const int combinations = sides * sides;
    
    // Initialize the 6x6 matrix for combinations
    int distribution[sides][sides] = {0};

    // Calculate and display the distribution
    for (int diceA = 1; diceA <= sides; ++diceA) {
        for (int diceB = 1; diceB <= sides; ++diceB) {
            int sum = diceA + diceB;
            distribution[diceA - 1][diceB - 1]++;
            std::cout << "Die A: " << diceA << ", Die B: " << diceB << ", Sum: " << sum << "\n";
        }
    }

    // Calculate and display the probability of each sum
    std::cout << "\nProbability of each sum:\n";
    for (int sum = 2; sum <= 12; ++sum) {
        int count = 0;
        for (int diceA = 1; diceA <= sides; ++diceA) {
            int diceB = sum - diceA;
            if (diceB >= 1 && diceB <= sides) {
                count += distribution[diceA - 1][diceB - 1];
            }
        }
        double probability = static_cast<double>(count) / combinations;
        std::cout << "P(Sum = " << sum << ") = " << "1/" << combinations / count << " = " << probability << "\n";
    }

    return 0;
}










