#include <FastLED.h>
#include "animation.h"
#define LED_PIN     10
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define framerate   200
//#define COLOR_CORRECTION CRGB(255,172,240)
#define BRIGHTNESS  50
#define NUM_LEDS    16
CRGB leds[NUM_LEDS];
CRGB buffer[NUM_LEDS];
uint8_t counter = 1;
#include "Necklace_animations.h"


// setup gets called once
void setup() {
   // power-up sanity delay
  delay( 3000 );
  
  // tell FastLED about the LEDs
  FastLED.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
  
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, Change_animation, FALLING);
}



///Declare patterns and animation class
Pattern Patternlist [] =
{
  Animation_1,
  Animation_2,
  random_ring
};
Animation animation (Patternlist,3);
///
void Change_animation()
{
  animation.iterate_animation();
}

// loop is called repeatedly forever
void loop()
{
  animation.animate();
  /*counter++;
  if(counter==0){
    Change_animation();
  }*/
}

