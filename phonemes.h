#ifndef _PHONEMES_
#define _PHONEMES_

#define PHON(phoneme) _phon_##phoneme##_

// Phonemes drawn from: http://www.boardman.k12.oh.us/bdms/phonological/44Phonemes.pdf
enum phonemes {

	PHON(a),
	PHON(b),
	PHON(d),
	PHON(e),
	PHON(k),
	PHON(l),
	PHON(o),
	PHON(p),
	PHON(r),
};

struct PhonemeSounds {
    const Sifteo::AssetAudio *phoneme;
};

#endif