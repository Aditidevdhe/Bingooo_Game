# Bingooo_Game
This project is a simple implementation of a Bingo game in C++. The game involves two players with their own Bingo cards. Player 1's numbers are drawn automatically by the program, while Player 2's numbers are drawn based on user input. The game continues until one of the players achieves a Bingo by marking a complete row, column, or diagonal.This project is a simple implementation of the classic Bingo game using C++. The game involves two players: Player 1 and Player 2. Player 1's numbers are drawn automatically by the program, while Player 2 manually inputs the numbers.

Features --
--Random Bingo Card Generation: Each player receives a randomly generated Bingo card with numbers from 1 to 25.
--Automatic Number Drawing for Player 1: The program automatically draws numbers for Player 1 at regular intervals.
--Manual Number Input for Player 2: Player 2 inputs the drawn numbers manually.
--Bingo Check: The program checks if either player has achieved Bingo (a full row, column, or diagonal of marked numbers) after each draw.
--Visual Representation: The Bingo cards for both players are displayed after each turn, showing the marked numbers.

How to Play --
1.Player 1's numbers are automatically drawn by the program.
2.Player 2 inputs a number between 1 and 25 when prompted.
3.The program marks the drawn numbers on both players' cards.
4.The game continues until one of the players achieves Bingo.
5.The program announces the winner and ends the game.

About Code --
BingoCard structure holds the Bingo numbers for a player.
Functions made in the code -- 
generateRandomNumber(int min, int max): Generates a random number between min and max.
createBingoCard(): Creates a Bingo card with numbers 1 through 25 shuffled randomly.
drawNumberAndMark(BingoCard& player1Card, BingoCard& player2Card, int number): Draws a number and marks it on both players' cards.
hasBingo(const BingoCard& card): Checks if the card has a complete row, column, or diagonal (Bingo).
displayCard(const BingoCard& card): Displays the Bingo card, showing "X" for marked numbers.
