#include <array>

#include "bitboard.h"
#include "types.h"

namespace polaris {
class Position {

private:
  Color    sideToMove_;
  Castling castleRights_;
  Square   enPassantSq_;
  int      halfMoveClock_;
  int      fullMoveClock_;


  std::array<BitBoard, COLOR_NB> bbByColor_{};
  std::array<std::array<BitBoard, PIECE_TYPE_NB>, COLOR_NB> bbByPiece_{};
};
} // namespace polaris
