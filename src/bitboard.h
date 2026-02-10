#pragma once

#include <cstdint>
#include "types.h"

namespace polaris {

class BitBoard {
private:
  uint64_t board_;

public:
  constexpr BitBoard() : BitBoard(0ULL) {}
  constexpr BitBoard(uint64_t board) : board_{board} {}
  
};

} // namespace polaris
