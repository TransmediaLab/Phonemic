#ifndef _GRAPHEMES_
#define _GRAPHEMES_

#define GRAPH(grapheme) _GRAPH_##grapheme##_

enum graphemes {

	GRAPH(a),
	GRAPH(b),
	GRAPH(c),
	GRAPH(d),
	GRAPH(e),
	GRAPH(k),
	GRAPH(l),
	GRAPH(o),
	GRAPH(p),
	GRAPH(r),
};

struct GraphemePics {
    const Sifteo::AssetImage *grapheme[2];
};

#endif