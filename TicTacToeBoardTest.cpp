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
*/

TEST(TicTacToeBoard_is_square, sanityCheck){
	int sizex = TicTacToeBoard.size();
	int sizey;
	for (int i = 0; i < sizex; i++){
		sizey = TicTacToeBoard[i].size();
		ASSERT_EQ(sizex, sizey);
	}
}

TEST(TicTacToeBoard_is_3_3, sanityCheck){
	bool three = true;
	int sizex = TicTacToeBoard.size();
	int sizey;
	
	if (size x != 3)
		
	for (int i = 0; i < sizex; i++){
		sizey = TicTacToeBoard[i].size();
		ASSERT_EQ(sizey, 3);
	}
}

TEST(TicTacToeBoard_is_empty, sanityCheck){
	for (int i = 0; i < 3; i++)
		for (int j =0; j < 3; j++)
			ASSERT_EQ
	
}