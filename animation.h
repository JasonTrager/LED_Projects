typedef void (*Pattern) (); //define the pattern class
class Animation
{
/*
** Class that stores all of the animations that are being used in an LED array
** Purpose: Loop only calls Animation.animate: a function that essentailly loops the 
**
*/

	// Class Member Variables
	// These are initialized at startup
	//int NUM_LEDS; // number of LEDS on the animation. May change this for multiple strips. Taken out for now. 
	Pattern Patternlist[]; // List of animation pattern functions
	int first_pattern = 0;

public:
	Animation(Pattern List)
	{
		//NUM_LEDS = num;
		Patternlist = List;
		current_pattern = first_pattern;
	}

	void animate()
	{
		Patternlist[current_pattern] ();
	}
private:
	int current_pattern;
};


