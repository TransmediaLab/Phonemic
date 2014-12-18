/*
 * Phonemic 
 */
 
#include <sifteo.h>
#include <sifteo/audio.h>
#include "phonemic.h"
 
#define LAST_LEVEL 6 //24
#define FILE_LENGTH 100
#define SPLIT_LENGTH 25

int word_num, temp, length;
int order[MAX_WORD_SIZE];
 
Random gRandom;
 
/**
  * Constructs a new Phonemic app
  */  
Phonemic::Phonemic()
{

}


/**
  * Display title screen
  */
void Phonemic::title()
{

}

void resetOrder()
{
	temp = 0;
	for(int i=0; i<MAX_WORD_SIZE; i++)
		order[i] = -1;
}

/**
  * Initializes the Phonemic app
  */
void Phonemic::init()
{
	Events::neighborAdd.set(&Phonemic::onNeighborAdd, this);
	Events::neighborRemove.set(&Phonemic::onNeighborRemove, this);
	Events::cubeTouch.set(&Phonemic::onTouch, this);
	Events::cubeConnect.set(&Phonemic::onConnect, this);
	
	// Handle already-connected cubes
	int i = 0;
	for (CubeID cube : CubeSet::connected())
	{
		onConnect(cube);
		cubes[cube].cid = cube;
		i++;
	}
		
	//level = gRandom.randint(0, LAST_LEVEL-1);
	level = 0;
	word = -1;
	nextWord();
}


/**
  * Moves to the next word
  */
void Phonemic::nextWord()
{
	//resetOrder(); 	/* reset cube solution order */
    // Advance the word (and level)
	word++;
	if(word >= 8) {
		level++;
		word = 0;
	}
    if(level > LAST_LEVEL) {
        level = 0;
        word = 0;
    }
	
	//word_num = (level * 8) + word;
	
    // Test for game over
    // TODO: check for end-of-game
    length = wordFamilies[level].length[word];
	/* deprecated, added word length to wordfamily struct */
    /*while(length < MAX_WORD_SIZE && wordFamilies[level].words[word][length] != -1)
        length++;
     */   
	 
	while (length > 3) {
		word++;
		if(word >= 8) {
			level++;
			word = 0;
		}
		if(level > LAST_LEVEL) {
			level = 0;
			word = 0;
		}
		length = wordFamilies[level].length[word];
	}
	 
	int i = 0;
	int r = 0;
	int j[3] = {-1,-1,-1};
	for (int k = 0; k < 3; k++) {
		do {
			r = gRandom.randint(0, 2);
		} while (r == j[0] || r == j[1] || r == j[2]);
		j[k] = r;
	}
	for(CubeID cube: CubeSet::connected())
	{
        // Reverse the order of the cubes every other word
		// change this to random rather than reverse, and should have same functionality as proto-type
		// TO DO
        //int j = i;
        //if(word % 2 == 0) j = length - i - 1;
		if(i < length) {
				//	OLD
				cubes[cube].symbol = wordFamilies[level].phonemes[word][j[i]];
				//cubes[cube].images[0] = graphemes[wordFamilies[level].graphemes[word][j]].grapheme[0]; 
				//cubes[cube].images[1] = graphemes[wordFamilies[level].graphemes[word][j]].grapheme[1]; 
				cubes[cube].vid.bg0.image(vec(0,0), Background/**cubes[cube].images[0]*/);
				cubes[cube].sound = phonemes[wordFamilies[level].phonemes[word][j[i]]].phoneme;
			/* NEW */
			//order[temp] = j;			/* track solution sequence */
			//cubes[cube].symbol = j;		/* used to compare for solution sequence */
			/* TO DO */
			cubes[cube].vid.bg1.setMask(BG1Mask::filled(vec(0,5), vec(16,6))); /* temp - can be taken out? */
			cubes[cube].vid.bg1.text(vec(0,5), Font2, "        ");
			cubes[cube].vid.bg1.text(vec(6,5), Font2, wordFamilies[level].graphemes[word][j[i]]);	/* get draw to work properly?? */
			//cubes[cube].sound = phonemes[wordFamilies[level].phoneme[word][j]].phoneme;		/* attach sound??? */
			//System::paint();	/* is this neccesary? */
		} else {
			/* kept this the same, shouldn't require any changes */
			cubes[cube].symbol = -1;
            //cubes[cube].images[0] = &Sleep;
            //cubes[cube].images[1] = &Smile;
            cubes[cube].vid.bg0.image(vec(0,0), *cubes[cube].images[0]);
            cubes[cube].sound = &SfxBuzzer;
		}	
		i++;
		
		// Allocate 16x2 tiles on BG1 for text at the bottom of the screen
        // cubes[cube].vid.bg1.setMask(BG1Mask::filled(vec(0,14), vec(16,2)));
		// text.set(0, -20);
            // textTarget = text;
			// cubes[cube].vid.bg1.text(vec(0,14), Font, " Hello traveler ");
		// System::paint();
		
	}
	state = PLAY;
	
}

/**
  * Helper method to set all cubes to smiley faces
  */
void Phonemic::allSmiles() {
    for(CubeID cube: CubeSet::connected())
	{
        //cubes[cube].vid.bg0.image(vec(0,0), Smile/*word_pictures[word_num]*/);
		
		/* TO DO */
		//cubes[cube].vid.bg0.image(vec(0,0), Background/**cubes[cube].images[0]*/);
		//cubes[cube].vid.bg1.setMask(BG1Mask::clear());
		cubes[cube].vid.bg1.text(vec(0,5), Font2, "        ");
		cubes[cube].vid.bg0.image(vec(0,0), *wordFamilies[level].words[word].picture);  /* attach to word.png */
    }
}


/**
  * Helper method to determine if any cubes are neighboured
  */
bool Phonemic::noNeighbors() {
    for(CubeID cube: CubeSet::connected())
	{
        Neighborhood hood = Neighborhood(cube);
        if(hood.hasCubeAt(LEFT) || hood.hasCubeAt(RIGHT))
            return false;
    }
    return true;
}


/**
  * Helper method to sounds out the sequence of cubes.
  */
void Phonemic::soundOut(unsigned id) {
    // Wait for audio channel to be clear
    if(sounding.isPlaying()) return;
    
    // Highlight the current cube
    cubes[id].vid.bg0.image(vec(0,0), *cubes[id].images[1]);
    System::paint();
    System::finish();
        
    // Play the current cube's sound
    sounding.play(*cubes[id].sound);
    while(sounding.isPlaying()) {
        System::yield();
    }
    
    // Return the cube to its normal appearance
    cubes[id].vid.bg0.image(vec(0,0), *cubes[id].images[0]);
    
    // Play any cube connected to the right
    Neighborhood hood = Neighborhood(id);
    if(hood.hasCubeAt(RIGHT)) soundOut(hood.cubeAt(RIGHT));
}


/**
  * Helper method to locate the leftmost cube 
  * in a series of neighboured cubes.
  */
unsigned Phonemic::leftmostNeighbor(unsigned id) {
    // Find leftmost cube
	Neighborhood hood = Neighborhood(id);
	CubeID leftmostID = id;
	while(hood.hasCubeAt(LEFT)) {
		leftmostID = hood.cubeAt(LEFT);
		hood = Neighborhood(leftmostID);
	}
    return leftmostID;
}


/** 
  * Helper method to decide if a series of cubes
  * spells the current word.
  */
void Phonemic::checkForWord(unsigned id) {

    // Find leftmost cube
	CubeID nextID = leftmostNeighbor(id);
    Neighborhood hood = Neighborhood(nextID);
    	
	// Find the sequence of symbols spelled by
    // the sequence of cubes
    int wordAttempt[MAX_WORD_SIZE];
    wordAttempt[0] = cubes[nextID].symbol;
    int i = 1;
    while(hood.hasCubeAt(RIGHT)) {
    	nextID = hood.cubeAt(RIGHT);
	    hood = Neighborhood(nextID);
    	wordAttempt[i] = cubes[nextID].symbol;
        i++;
	}
    wordAttempt[i] = -1;
        
    // Check for a match
	bool match = true;
    for(int i = 0; i < /*MAX_WORD_SIZE*/ length; i++) {
        if(/*order[i]*/ wordFamilies[level].phonemes[word][i] != wordAttempt[i]) 
        {
            match = false;
            break;
        }
        //if(wordFamilies[level].phonemes[word][i] == -1) break;
    }
    
    // Recognize match
	if(match) {
    	//sounding.play(SfxChime);
		//sounding.play(SfxCat);
		
		sounding.play(/*SfxChime*/ *wordFamilies[level].words[word].sound);
        allSmiles();
        System::paint();
        state = WORD_FOUND;
	}
}


/**
  * Runs the Phonemic app
  */
void Phonemic::run()
{
	while(1) {
		System::paint();
	}
}


/**
  * Cleans up before shutdown
  */
void Phonemic::cleanup() 
{
	Events::neighborAdd.unset();
	Events::neighborRemove.unset();
	Events::cubeTouch.unset();
	Events::cubeConnect.unset();
}


/**
  * Event Handler for new cube connections
  */
void Phonemic::onConnect(unsigned id)
{
    // Initialize the cubes in BG0 
    // (one background layer) mode
	cubes[id].cid = id;
    cubes[id].vid.initMode(BG0_BG1);
    cubes[id].vid.attach(id);
    cubes[id].symbol = -1;
    cubes[id].images[0] = &Background;
    cubes[id].images[1] = &Background;
    cubes[id].vid.bg0.image(vec(0,0), Background);
    cubes[id].sound = &SfxBuzzer;
    cubeCount++;
}


/**
  * Event handler for cube touches
  */  
void Phonemic::onTouch(unsigned id) 
{
    // Touch events fire twice - when the
    // touch starts and when it ends.
    // We'll use the isTouching() test to
    // only trigger when the touch ends.
	cubes[id].vid.bg0.image(vec(0,0), *wordFamilies[level].words[word].picture);
	
    if(!CubeID(id).isTouching()) {
        soundOut(id);
		cubes[id].vid.bg0.image(vec(0,0), Background);
	}
}


/**
  * Event handler for cube neighboring
  */
void Phonemic::onNeighborAdd(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
{	
    // Behaviour is dependent on the current app state
    if(state == PLAY)
        // Only allow left-to-right (reading order) connections
        if((firstSide == LEFT && secondSide == RIGHT)||(firstSide == RIGHT && secondSide == LEFT)) 
        {
            playSfx(SfxAttach);
            soundOut(leftmostNeighbor(firstID));
            checkForWord(firstID);
        }
}


/**
  * Event handler for when a cube is moved away from a neighbour
  */
void Phonemic::onNeighborRemove(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide)
{
    // When all cubes are disconnected, we 
    if(state == WORD_FOUND && noNeighbors())
        nextWord();
    
    if((firstSide == LEFT && secondSide == RIGHT) || 
	   (firstSide == RIGHT && secondSide == LEFT))
		playSfx(SfxDetach);
}
