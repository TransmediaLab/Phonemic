
#include <sifteo.h>
#include "phonemic.h"
#include "word_families.h"

#define WORD(w) {&ChunkSound_##w, &ChunkImage_##w}

WordFamily wordFamilies[] = {
      /*{{
        // cab,crab,dab,gab,grab,jab,nab,tab,
        { PAIR(k,c), PAIR(ab,ab),  -1 },
        { PAIR(k,c), PAIR(r,r), PAIR(ab,ab),  -1 },
        { PAIR(d,d), PAIR(ab,ab),  -1 },
        { PAIR(g,g), PAIR(ab,ab),  -1 },
        { PAIR(g,g), PAIR(r,r), PAIR(ab,ab),  -1 },
        { PAIR(j,j), PAIR(ab,ab),  -1 },
        { PAIR(n,n), PAIR(ab,ab),  -1 },
        { PAIR(t,t), PAIR(ab,ab),  -1 },
		
		
		{"and","and 3 a n d 3 a n d"},
		{"a","a 1 a 1 a_"},
		{"away","away 3 a w ay 3 u w a_"},
		{"big","big 3 b i g 3 b i g"},
		{"blue","blue 3 b l ue 3 b l u_"},
		{"can","can 3 c a n 3 k a n"},
		{"come","come 3 c o me 3 k u m"},
		{"down","down 3 d ow n 3 d ow n"},
		
   }},*/
   
	/* can write quick script to create this structure from our original dictionary format */
   {/* Level 0 */
		{	/*word*/
			WORD(apple),
			WORD(back),
			WORD(ball),
			WORD(bear),
			WORD(bed),
			WORD(bell),
			WORD(bird),
			WORD(car),
		},
		{	/*word length*/
			//5,4,4,4,3,4,4,3
			3,3,3,3,3,3,3,3,
		},
		{	/*grapheme*/
			{"a","pp","le"},
			{"b","a","ck"},
			{"b","a","ll"},
			{"b","ea","r"},
			{"b","e","d"},
			{"b","e","ll"},
			{"b","ir","d"},
			{"c","a","r"},
			/*{GRAPH(a),GRAPH(p),GRAPH(l)},
			{GRAPH(b),GRAPH(a),GRAPH(k)},
			{GRAPH(b),GRAPH(a),GRAPH(l)},
			{GRAPH(b),GRAPH(e),GRAPH(r)},
			{GRAPH(b),GRAPH(e),GRAPH(d)},
			{GRAPH(b),GRAPH(e),GRAPH(l)},
			{GRAPH(b),GRAPH(r),GRAPH(d)},
			{GRAPH(c),GRAPH(a),GRAPH(r)},*/
		},
		{	/*phoneme*/
			{PHON(a),PHON(p),PHON(l)},
			{PHON(b),PHON(a),PHON(k)},
			{PHON(b),PHON(o),PHON(l)},
			{PHON(b),PHON(e),PHON(r)},
			{PHON(b),PHON(e),PHON(d)},
			{PHON(b),PHON(e),PHON(l)},
			{PHON(b),PHON(r),PHON(d)},
			{PHON(k),PHON(o),PHON(r)},
		},
	},

		/* Level 1 */
};