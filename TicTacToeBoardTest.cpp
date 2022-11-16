/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} 
		virtual ~TicTacToeBoardTest(){} 
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// toggle turn testing
/************************************************************************/
TEST(TicTacToeBoardTest, first_turn_test) {
	TicTacToeBoard ttb;
	Piece expect = O;
	Piece actual = ttb.toggleTurn();
	ASSERT_EQ(expect, actual);
}

TEST(TicTacToeBoardTest, O_turn_test) {
	TicTacToeBoard ttb;
	Piece expect = X;
	ttb.toggleTurn();
	Piece actual = ttb.toggleTurn();
	ASSERT_EQ(expect, actual);
}

TEST(TicTacToeBoardTest, X_turn_test) {
	TicTacToeBoard ttb;
	Piece expect = O;
	ttb.toggleTurn();
	ttb.toggleTurn();
	Piece actual = ttb.toggleTurn();
	ASSERT_EQ(expect, actual);
}

TEST(TicTacToeBoardTest, turn_test) {
	TicTacToeBoard ttb;
	ASSERT_EQ(ttb.toggleTurn(), O);
	ASSERT_EQ(ttb.toggleTurn(), X);
	ASSERT_EQ(ttb.toggleTurn(), O);
	ASSERT_EQ(ttb.toggleTurn(), X);
}

// place piece testing
/************************************************************************/

TEST(TicTacToeBoardTest, invalid_piece_placement) {
	TicTacToeBoard ttb;
	Piece actual = ttb.placePiece(4, 1);
	ASSERT_EQ(actual, Invalid);
	ASSERT_EQ(ttb.placePiece(1,4), Invalid);
}

TEST(TicTacToeBoardTest, place_first_piece) {
	TicTacToeBoard ttb;
	Piece actual = ttb.placePiece(1,1);
	ASSERT_EQ(actual, X);
	ASSERT_EQ(ttb.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, place_mult_pieces) {
	TicTacToeBoard ttb;
	ASSERT_EQ(ttb.placePiece(0,0), X);
	ASSERT_EQ(ttb.placePiece(1,1), O);
	ASSERT_EQ(ttb.placePiece(0,2), X);
	ASSERT_EQ(ttb.placePiece(1,0), O);
}

TEST(TicTacToeBoardTest, overlapping_pieces) {
	TicTacToeBoard ttb;
	ASSERT_EQ(ttb.placePiece(1,1), X); //switches turn to O
	ASSERT_EQ(ttb.placePiece(1,1), O); //switches turn to X
	ASSERT_EQ(ttb.toggleTurn(), O); //switches turn to O
}