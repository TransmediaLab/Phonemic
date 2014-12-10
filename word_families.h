#ifndef _WORD_FAMILIES_
#define _WORD_FAMILIES_

#include <sifteo/string.h>
//#include "phonemes.h"
//#include "graphemes.h"
//#include "chunks.h"
 
const int MAX_WORD_SIZE = 5;
const int MAX_CHUNK_SIZE = 2;
const int MAX_CUBES = 11;
 
using namespace Sifteo;

struct WordFamilyCube {
	const char *symbol;
	const AssetAudio *sound;
	const AssetImage *images[2];
};

struct WordFamily {
    const char *words[8];
	const int length[8];
	const char *grapheme[8][MAX_WORD_SIZE];
	const int phoneme[8][MAX_WORD_SIZE];
};
 
#endif