#ifndef __DEFINES__
#define __DEFINES__

#include <utility>
#include <vector>

typedef std::pair<int, int> Size;
typedef std::pair<int, int> Pos;

template <class N>
using Matrix = std::vector<std::vector<N>>;

typedef unsigned int uint;

enum Direction {
	UP		= 0,
	DOWN	= 1,
	LEFT	= 2,
	RIGHT	= 3
};

#endif // __DEFINES__
