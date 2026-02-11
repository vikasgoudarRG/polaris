#pragma once

#include <cstdint>

namespace polaris {
  enum PieceType : uint8_t {
    NO_PIECE_TYPE,         // 0000
    PAWN,                  // 0001 
    BISHOP,                // 0010
    KNIGHT,                // 0011
    ROOK,                  // 0100
    QUEEN,                 // 0101
    KING,                  // 0110

    PIECE_TYPE_NB = 7
  };

  enum Piece : uint8_t {
    NO_PIECE,                                     // 0000
                                                  
    WHITE_PAWN,                                   // 0001
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
    BLACK_KING     = PIECE_TOGGLE ^ WHITE_KING,   // 1110
    
    PIECE_NB = 13
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

  enum Square : uint8_t {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    OUT_OF_BOUNDS
  };

  enum Rank : uint8_t {
    RANK_1,
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_NB
  };

  enum File : uint8_t {
    FILE_A,
    FILE_B,
    FILE_C,
    FILE_D,
    FILE_E,
    FILE_F,
    FILE_G,
    FILE_G,
    FILE_NB
  };

  constexpr Color operator~(Color c) {
    return Color(c ^ BLACK);
  }

  constexpr Piece operator~(Piece p) {
    return Piece(p ^ PIECE_TOGGLE);
  }

  #define ENABLE_PREFIX_OPERATIONS(T) \
            constexpr T& operator++(T& d) { return d = T(int(d) + 1); } \
            constexpr T& operator--(T& d) { return d = T(int(d) - 1); }
  
  ENABLE_PREFIX_OPERATIONS(File)
  ENABLE_PREFIX_OPERATIONS(Rank)

  #undef ENABLE_PREFIX_OPERATIONS

} // namespace polaris
