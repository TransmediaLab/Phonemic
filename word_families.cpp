
#include <sifteo.h>
#include "phonemic.h"
#include "word_families.h"

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
			"cat",
			"and",
			"away",
			"big",
			"blue",
			"can",
			"come",
			"down",
		},
		{	/*word length*/
			3,3,4,3,4,3,4,4
		},
		{	/*grapheme*/
			{"c","a","t"},
			{"a","n","d"},
			{"a","w","ay"},
			{"b","i","g"},
			{"b","i","g"},
			{"c","a","n"},
			{"c","o","me"},
		},
		{	/*phoneme*/
			{"c","a","t"},
			{"a","n","d"},
			{"u","w","a_"},
			{"b","i","g"},
			{"b","l","u_"},
			{"k","a","n"},
			{"k","u","m"},
			{"d","ow","n"},
		},
	},

		/* Level 1 */
};