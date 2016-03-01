#ifndef __DEFINES__
#define __DEFINES__

#include <utility>
#include <vector>

typedef std::pair<unsigned int, unsigned int> Size;
typedef std::pair<int, int> Pos;

template <class N>
using Matrix = std::vector<std::vector<N>>;

typedef unsigned int uint;
#endif // __DEFINES__