#include <sifteo.h>
#include "assets.gen.h"
#include "graphemes.h"

#define GRAPH_DEF(grapheme) {{&Grapheme_##grapheme[0], &Grapheme_##grapheme[1]}}

GraphemePics graphemes[] = {
	GRAPH_DEF(a),
	GRAPH_DEF(b),
	GRAPH_DEF(c),
	GRAPH_DEF(d),
	GRAPH_DEF(e),
	GRAPH_DEF(k),
	GRAPH_DEF(l),
	GRAPH_DEF(o),
	GRAPH_DEF(p),
	GRAPH_DEF(r),
};