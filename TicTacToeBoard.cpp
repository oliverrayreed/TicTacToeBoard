#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/

/* 
BUG: The bug is caused by the turn being set as Blank rather than X. 
If you are only checking to see if the turn has changed from the previous value, it wont catch it.
Likewise, since turn is initially set to X, it also won't catch it if you have a check for 
must be "X" or "O" unless you call the toggle turn multiple times (more than twice).
*/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X){
    turn = O;
    return O;
  }
  else {
    turn = X;
    return X;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  bool full = true;
  for (int i = 0; i < BOARDSIZE; i++)
    for(int j = 0; j < BOARDSIZE; j++)
      if (board[i][j] == Blank)
        full = false;
  if (full)
    return Invalid;
  if (row < 0 || row >= BOARDSIZE || column < 0 || column >= BOARDSIZE)
    return Invalid;
  if (board[row][column] != Blank)
    return board[row][column];
  board[row][column] = turn;
  toggleTurn();
  return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  Piece piece = board[row][column];
  return piece;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  // Check if x is winner
  bool rowcheck_x;
  Piece winner_x = X;
  
  // Check if o is winner
  bool rowcheck_o;
  Piece winner_o = O;
  
  
  // Check rows
  for (int i = 0; i < BOARDSIZE; i++){
    rowcheck_x = true;
    rowcheck_o = true;
    for (int j = 0; j < BOARDSIZE; j++){
      if (board[i][j] != winner_x){
        rowcheck_x = false;
      }
      if (board[i][j] != winner_o){
        rowcheck_o = false;
      }
    }
    if (rowcheck_o && rowcheck_x)
      return Blank;
    if (rowcheck_x)
      return winner_x;
    if (rowcheck_o)
      return winner_o;
  }
  // Check columns
  for (int i = 0; i < BOARDSIZE; i++){
    rowcheck_x = true;
    rowcheck_o = true;
    for (int j = 0; j < BOARDSIZE; j++){
      if (board[j][i] != winner_x){
        rowcheck_x = false;
      }
       if (board[j][i] != winner_o){
        rowcheck_o = false;
      }
    }
    if (rowcheck_o && rowcheck_x)
    return Blank;
    if (rowcheck_x)
      return winner_x;
    if (rowcheck_o)
      return winner_o;
  }
  
  // Check Diagonal
  rowcheck_x = true;
  rowcheck_o = true;
  for (int i = 0, j = 0; i < BOARDSIZE; i++, j++){
    if (board[i][j] != winner_x){
      rowcheck_x = false;
    }
    if (board[i][j] != winner_o){
      rowcheck_o = false;
    }
  }
  if (rowcheck_x)
      return winner_x;
  if (rowcheck_o)
    return winner_o;
    
  // Check other Diagonal  
  rowcheck_x = true;
  rowcheck_o = true;
  for (int i = 0, j = BOARDSIZE -1; i<BOARDSIZE; i++, j--){
    if (board[i][j] != winner_x){
      rowcheck_x = false;
    }
     if (board[i][j] != winner_o){
      rowcheck_o = false;
    }
  }
  if (rowcheck_x)
    return winner_x;
  if (rowcheck_o)
    return winner_o;
    
    
  // Check if Board is full      
  for (int i = 0; i < BOARDSIZE; i++)
    for(int j = 0; j < BOARDSIZE; j++)
      if (board[i][j] == Blank)
        return Invalid;
  
  // If board is full, return blank
  return Blank;
}
