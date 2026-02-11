#pragma once

#include <cstdint>
#include <iostream>
#include <sstream>
#include "types.h"

namespace polaris {

class BitBoard {
private:
  uint64_t board_;

public:
  constexpr BitBoard() : BitBoard(0ULL) {}
  constexpr BitBoard(uint64_t board) : board_{board} {}
  inline void bb_print();
  inline bool is_set(File file, Rank rank); 
};

inline bool BitBoard::is_set(File file, Rank rank) {
  Square square = Square(8 * (rank - 1) + file);
  return board_ & (1ULL << square);
}

inline void BitBoard::bb_print() {
  std::ostringstream output{};

  for (Rank rank = RANK_8; ; --rank) {
    output << "+---+---+---+---+---+---+---+---+\n";
               | X |
    for (File file = FILE_A; file <= FILE_G; ++file) {
      output << "| ";
      
    }
  }

  std::cout << output;
}

} // namespace polaris
