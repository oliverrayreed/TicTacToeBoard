/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoard_is_square, sanityCheck){
	bool equal = true;
	int sizex = TicTacToeBoard.size();
	int sizey;
	for (int i = 0; i < sizex; i++){
		sizey = TicTacToeBoard[i].size();
		if (sizex != sizey) {
			equal = false;
		}
	}
}

TEST(TicTacToeBoard_is_3_3, sanityCheck){
	bool three = true;
	int sizex = TicTacToeBoard.size();
	int sizey;
	
	if (sizex != 3)
		three = false;
		
	for (int i = 0; i < sizex; i++){
		sizey = TicTacToeBoard[i].size();
		ASSERT_EQ(sizey, 3);
	}
}

TEST(TicTacToeBoard_is_empty, sanityCheck){
	bool empty = true;
	for (int i = 0; i < 3; i++)
		for (int j =0; j < 3; j++)
			if (TicTacToeBoard[i][j] != "Blank")
				empty = false;
	ASSERT_TRUE(empty);
}

*/

TEST(Player_alternates, sanityCheck){
	TicTacToeBoard TicTac;
	Piece one = TicTac.toggleTurn();
	Piece two = TicTac.toggleTurn();
	ASSERT_NE(one, two);
}

TEST(Player_is_returned, sanityCheck){
	TicTacToeBoard TicTac;
	bool returned = true;
	returned = TicTac.toggleTurn(); 
	ASSERT_TRUE(returned);
}

TEST(Player_is_valid, sanityCheck){
	TicTacToeBoard TicTac;
	bool valid = true;
	Piece player;
	for (int i = 0; i < 2; i++){
	player = TicTac.toggleTurn();
	if ((player != X) && (player != O))
		valid = false;
	}
	ASSERT_TRUE(valid);
}

TEST(Player_alternates_multiple, sanityCheck){
	TicTacToeBoard TicTac;
	Piece one;
	Piece two;
	bool equal = false;
	int i = 0;
	
	while((!equal) && (i < 10)){
		one = TicTac.toggleTurn();
		two = TicTac.toggleTurn();
		if (one == two){
			equal = true;
		}
		i++;
	}
	ASSERT_FALSE(equal);
}

TEST(Place_invalid, sanityCheck){
	TicTacToeBoard TicTac;
	ASSERT_EQ (TicTac.placePiece(0,4), Invalid);
}

TEST(Place_on_existing, sanityCheck){
	TicTacToeBoard TicTac;
	Piece one = TicTac.placePiece(0,0);
	ASSERT_EQ(TicTac.placePiece(0,0), one);
}

TEST(Place_is_Valid, sanityCheck){
	TicTacToeBoard TicTac;
	TicTac.placePiece(0,0);
	ASSERT_EQ(TicTac.getPiece(0,0), X);
}

TEST(Place_on_full_board, sanityCheck){
	TicTacToeBoard TicTac;
	for(int i = 0; i < BOARDSIZE; i++){
		for (int j = 0; j < BOARDSIZE; j++)
			TicTac.placePiece(i,j);
	}
	ASSERT_EQ(TicTac.placePiece(1,2), Invalid);
				
}