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

TEST(Player_is_returned, sanityCheck){
	bool returned = true;
	returned = toggleTurn(); 
	ASSERT_TRUE(returned);
}

TEST(Player_is_valid, sanityCheck){
	bool valid = true;
	Piece player;
	for (int i = 0; i < 2; i++){
	player = toggleTurn();
	if (player != X && player != O)
		valid = false;
	}
	ASSERT_TRUE(valid);
}

TEST(Player_alternates, sanityCheck){
	bool exes = true;
	bool ohs = true;
	Piece player[10] = {?};
	for (int i = 0; i < 10; i++){
		player[i] = toggleTurn();
	}
	int i=0;
	while((!exes || !ohs) && i < 10){
		if (i%2)
			exes = (player[1] == player [i]);
		else
			ohs = (player[0] == player[i]);
	
		if (!exes || !ohs)
			ASSERT_TRUE(false);
	}
}
