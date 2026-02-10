#pragma once

#include <cstdint>

namespace polaris {
  enum PieceType : uint8_t {
    PAWN,                  // 0000 
    BISHOP,                // 0001
    KNIGHT,                // 0010
    ROOK,                  // 0011
    QUEEN,                 // 0100
    KING,                  // 0101

    PIECE_TYPE_NB = 6
  };

  enum Piece : uint8_t {
    WHITE_PAWN     = 0,                           // 0000
    WHITE_BISHOP,                                 // 0001
    WHITE_KNIGHT,                                 // 0010
    WHITE_ROOK,                                   // 0011
    WHITE_QUEEN,                                  // 0100
    WHITE_KING,                                   // 0101

    PIECE_TOGGLE   = 8,                           // 1000

    BLACK_PAWN     = PIECE_TOGGLE ^ WHITE_PAWN,   // 1000
    BLACK_BISHOP   = PIECE_TOGGLE ^ WHITE_BISHOP, // 1001
    BLACK_KNIGHT   = PIECE_TOGGLE ^ WHITE_KNIGHT, // 1010
    BLACK_ROOK     = PIECE_TOGGLE ^ WHITE_ROOK,   // 1011
    BLACK_QUEEN    = PIECE_TOGGLE ^ WHITE_QUEEN,  // 1100
    BLACK_KING     = PIECE_TOGGLE ^ WHITE_KING    // 1101
  };

  enum Castling : uint8_t {
    NO_CASTLE          = 0,                                      // 0000

    WHITE_KING_CASTLE  = 1,                                      // 0001
    WHITE_QUEEN_CASTLE = WHITE_KING_CASTLE << 1,                 // 0010
    BLACK_KING_CASTLE  = WHITE_KING_CASTLE << 2,                 // 0100
    BLACK_QUEEN_CASTLE = WHITE_KING_CASTLE << 3,                 // 1000

    WHITE_CASTLE       = WHITE_KING_CASTLE | WHITE_QUEEN_CASTLE, // 0011
    BLACK_CASTLE       = BLACK_KING_CASTLE | BLACK_QUEEN_CASTLE, // 1100

    ALL_CASTLE         = WHITE_CASTLE      | BLACK_CASTLE        // 1111
  };

  enum Color : uint8_t {
    WHITE,
    BLACK,
    COLOR_NB
  };

} // namespace polaris
