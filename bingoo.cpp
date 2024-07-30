#include<bits/stdc++.h>
using namespace std;

struct BingoCard {
    vector<int> numbers;
};

//to generate a random number

int generateRandomNumber(int min, int max) {
    return min + (rand() % (max - min +1));
}

// to create bingo card
BingoCard createBingoCard(){
    BingoCard card;
    vector<int> possibleNumbers;

    for(int i=1;i<=25;i++){
        possibleNumbers.push_back(i);     //filling vector with numbers 1 to 25
    }

    random_shuffle(possibleNumbers.begin(), possibleNumbers.end());    //shuffle the numbers randomly

    for(int i=0;i<25;i++){
        card.numbers.push_back(possibleNumbers[i]);     //add the first 25 numbers to the card
    }

    return card;
}

//to draw a number and mark it on the cards
void drawNumberAndMark(BingoCard& player1Card, BingoCard& player2Card, int number) {
    for(int i = 0; i < player1Card.numbers.size(); ++i){
        if(player1Card.numbers[i] == number){
            player1Card.numbers[i] = 0;
        }

        if (player2Card.numbers[i] == number){
            player2Card.numbers[i] = 0;
        }
    }
} 


//to check if player have achived bingo
bool hasBingo(const BingoCard& card){

    //checking rows
    for(int i = 0; i < 5; ++i){
        if(card.numbers[i*5] == 0 && card.numbers[i*5+1] == 0 &&
           card.numbers[i*5+2] == 0 && card.numbers[i*5+3] == 0 &&
           card.numbers[i*5+4] == 0 ) {
            return true;
           }
    }
    //columns
    for(int i = 0; i < 5; ++i) {
        if(card.numbers[i] == 0 && card.numbers[i + 5] == 0 && 
           card.numbers[i + 10] == 0 &&
           card.numbers[i + 15] == 0 && card.numbers[i + 20] == 0){
            return true;
           }
    }
    //diagonals
    if ((card.numbers[0] == 0 && card.numbers[6] == 0 &&
         card.numbers[12] == 0 && card.numbers[18] == 0 && 
         card.numbers[24] == 0 ) || 
         (card.numbers[4] == 0 && card.numbers[8] == 0 &&
          card.numbers[12] == 0 && card.numbers[16] == 0 &&
          card.numbers[20] == 0)) {
            return true;
          }

          return false;
}

//to display bingocard
void displayCard(const BingoCard& card){
    for (int i = 0; i < card.numbers.size(); ++i) {
        cout << (card.numbers[i] ? to_string(card.numbers[i]) : "X") << "\t";
        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Create Bingo cards for both players
    BingoCard player1Card = createBingoCard();
    BingoCard player2Card = createBingoCard();

    // Initialize the current player
    int currentPlayer = 1;

    while (true) {
        int drawnNumber;
        
        if (currentPlayer == 1) {
            // Generate a random number for Player 1
            drawnNumber = generateRandomNumber(1, 25);
        } else {
            // Prompt user for a number for Player 2
            cout << "Player 2, enter a number between 1 and 25: ";
            cin >> drawnNumber;
            // Validate input
            while (drawnNumber < 1 || drawnNumber > 25) {
                cout << "Invalid number. Please enter a number between 1 and 25: ";
                cin >> drawnNumber;
            }
        }

        // Draw the number and mark it on both cards
        drawNumberAndMark(player1Card, player2Card, drawnNumber);

        // Display the drawn number and both players' updated Bingo cards
        cout << "Player " << currentPlayer << " - Drawn Number: " << drawnNumber << endl;
        cout << "Player 1's Card:\n";
        displayCard(player1Card);
        cout << "--------------------------" << endl;
        cout << "Player 2's Card:\n";
        displayCard(player2Card);
        cout << "--------------------------" << endl;

        // Check if the current player has achieved Bingo
        if ((currentPlayer == 1 && hasBingo(player1Card)) || (currentPlayer == 2 && hasBingo(player2Card))) {
            cout << "Player " << currentPlayer << " has achieved Bingo! Congratulations!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}