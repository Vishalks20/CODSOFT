#include <iostream>
const int size = 3;
char board[size][size];
char currentPlayer = 'X';
void initializeBoard() {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      board[i][j] = ' ';
    }
  }
}
void displayBoard() {
  std::cout << "\n";
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::cout << board[i][j];
      if (j < size - 1)
        std::cout << " | ";
    }
    std::cout << "\n";
    if (i < size - 1) {
      std::cout << "--|---|--\n";
    }
  }
    std::cout << "\n";
  }
  bool isValidMove(int row, int col) {
    return row >= 0 && row < size && col >= 0 && col < size &&
           board[row][col] == ' ';
  }
  bool verifyWin() {
    for (int i = 0; i < size; i++) {
      if (board[i][0] == currentPlayer && board[i][1] == currentPlayer &&
          board[i][2] == currentPlayer) {
        return true;
      }
    }
    // diagonals check
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer) {
      return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer) {
      return true;
    }
    return false;
  }
  bool checkDraw() {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (board[i][j] == ' ') {
          return false;
        }
      }
    }
    return true;
  }

  void switchPlayer() { currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; }

  void playGame() {
    initializeBoard();
    bool gameWon = false;
    bool gameDraw = false;
    while (!gameWon && !gameDraw) {
      displayBoard();
      int row, col;
      std::cout << "Player" << currentPlayer << "enter your move(row col):";
      std::cin >> row >> col;

      if (isValidMove(row - 1, col - 1)) {
        board[row - 1][col - 1] = currentPlayer;
        gameWon = verifyWin();
        gameDraw = checkDraw();
        if (!gameWon && !gameDraw) {
          switchPlayer();
        }
      } else {
        std::cout << "Invalid move.Try again.\n";
      }
    }
    displayBoard();
    if (gameWon) {
      std::cout << "Player" << currentPlayer << "wins!\n";
    } else if (gameDraw) {
      std::cout << "It's a draw!\n";
    }
  }
  int main() {
    char playAgain;
    do {
      playGame();
      std::cout << "Do you want to play again?(y/n):";
      std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
  }
