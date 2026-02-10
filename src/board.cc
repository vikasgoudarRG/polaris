#include "bitboard.h"
#include "types.h"

namespace polaris {
class ChessBoard {
  BitBoard board_color[COLOR_NB];
  BitBoard board_piece[COLOR_NB][PIECE_TYPE_NB]; 
};
} // namespace polaris