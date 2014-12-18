#include <sifteo.h>
#include "assets.gen.h"
#include "phonemes.h"

#define PHON_DEF(phoneme) {&Phoneme_##phoneme}

PhonemeSounds phonemes[] = {
	PHON_DEF(a),
	PHON_DEF(aa),
	PHON_DEF(b),
	PHON_DEF(d),
	PHON_DEF(e),
	PHON_DEF(ee),
	PHON_DEF(f),
	PHON_DEF(g),
	PHON_DEF(h),
	PHON_DEF(i),
	PHON_DEF(ii),
	PHON_DEF(j),
	PHON_DEF(k),
	PHON_DEF(l),
	PHON_DEF(m),
	PHON_DEF(n),
	PHON_DEF(o),
	PHON_DEF(oo),
	PHON_DEF(p),
	PHON_DEF(kw),
	PHON_DEF(r),
	PHON_DEF(s),
	PHON_DEF(t),
	PHON_DEF(u),
	PHON_DEF(uu),
	PHON_DEF(v),
	PHON_DEF(w),
	PHON_DEF(y),
	PHON_DEF(z),
	PHON_DEF(th),
	PHON_DEF(sh),
	PHON_DEF(ch),
	PHON_DEF(wh),
};