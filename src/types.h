#pragma once

#include <cstdint>

namespace polaris {
  enum PieceType : uint8_t {
    NO_PIECE_TYPE = 0,     // 0000

    PAWN,                  // 0001
    BISHOP,                // 0010
    KNIGHT,                // 0011
    ROOK,                  // 0100
    QUEEN,                 // 0101
    KING,                  // 0110

    PIECE_TYPE_NB = 7
  };

  enum Piece : uint8_t {
    WHITE_PAWN     = 1,                           // 0001
    WHITE_BISHOP,                                 // 0010
    WHITE_KNIGHT,                                 // 0011
    WHITE_ROOK,                                   // 0100
    WHITE_QUEEN,                                  // 0101
    WHITE_KING,                                   // 0110

    PIECE_TOGGLE   = 8,                           // 1000

    BLACK_PAWN     = PIECE_TOGGLE ^ WHITE_PAWN,   // 1001
    BLACK_BISHOP   = PIECE_TOGGLE ^ WHITE_BISHOP, // 1010
    BLACK_KNIGHT   = PIECE_TOGGLE ^ WHITE_KNIGHT, // 1011
    BLACK_ROOK     = PIECE_TOGGLE ^ WHITE_ROOK,   // 1100
    BLACK_QUEEN    = PIECE_TOGGLE ^ WHITE_QUEEN,  // 1101
    BLACK_KING     = PIECE_TOGGLE ^ WHITE_KING    // 1110
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
  }

  enum Color : uint8_t {
    WHITE,
    BLACK,
    COLOR_NB
  };

  struct Game {
    Color side_to_move;

    int     full_moves;
    uint8_t half_moves;

    uint64_t board_pieces[COLOR_NB + 1];
    uint64_t pieces[COLOR_NB][PIECE_TYPE_NB]; // first element -> 0 will be unused, since 0 -> NO_PIECE_TYPE

  };




} // namespace polaris
