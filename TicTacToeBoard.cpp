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
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X){
    turn = O;
    return O;
  }
  else {
    turn = Blank;
    return X;
  }
  return Invalid;
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
  if (row < 0 || row > 2 || column < 0 || column > 2)
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
  bool rowcheck;
  Piece winner = X;
  
  for (int i = 0; i < BOARDSIZE; i++){
    rowcheck = true;
    for (int j = 0; j < BOARDSIZE; j++){
      if (board[i][j] != winner){
        rowcheck = false;
      }
    }
    if (rowcheck)
      return winner;
  }
  for (int i = 0; i < BOARDSIZE; i++){
    rowcheck = true;
    for (int j = 0; j < BOARDSIZE; j++){
      if (board[j][i] != winner){
        rowcheck = false;
      }
    }
    if (rowcheck)
      return winner;
  }
  rowcheck = true;
  for (int i = 0, j = 0; i < BOARDSIZE; i++, j++){
    if (board[i][j] != winner){
      rowcheck = false;
    }
  }
  if (rowcheck)
      return winner;
      
  rowcheck = true;
  for (int i = 0, j = BOARDSIZE -1; i<BOARDSIZE; i++, j--){
    if (board[i][j] != winner){
      rowcheck = false;
    }
  }
  if (rowcheck)
    return winner;
        
  for (int i = 0; i < BOARDSIZE; i++)
    for(int j = 0; j < BOARDSIZE; j++)
      if (board[i][j] == Blank)
        return Invalid;

  return Blank;
}
