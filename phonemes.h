#ifndef _PHONEMES_
#define _PHONEMES_

#define PHON(phoneme) _phon_##phoneme##_

// Phonemes drawn from: http://www.boardman.k12.oh.us/bdms/phonological/44Phonemes.pdf
enum phonemes {

	PHON(a),
	PHON(aa),
	PHON(b),
	PHON(d),
	PHON(e),
	PHON(ee),
	PHON(f),
	PHON(g),
	PHON(h),
	PHON(i),
	PHON(ii),
	PHON(j),
	PHON(k),
	PHON(l),
	PHON(m),
	PHON(n),
	PHON(o),
	PHON(oo),
	PHON(p),
	PHON(kw),
	PHON(r),
	PHON(s),
	PHON(t),
	PHON(u),
	PHON(uu),
	PHON(v),
	PHON(w),
	PHON(y),
	PHON(z),
	PHON(th),
	PHON(sh),
	PHON(ch),
	PHON(wh),
};

struct PhonemeSounds {
    const Sifteo::AssetAudio *phoneme;
};

#endif