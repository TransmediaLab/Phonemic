#include <sifteo.h>
#include "assets.gen.h"
#include "phonemes.h"

#define PHON_DEF(phoneme) {&Phoneme_##phoneme}

PhonemeSounds phonemeSounds[] = {
	PHON_DEF(a),
	PHON_DEF(b),
	PHON_DEF(d),
	PHON_DEF(e),
	PHON_DEF(k),
	PHON_DEF(l),
	PHON_DEF(o),
	PHON_DEF(r),
};