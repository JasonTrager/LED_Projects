#include <FastLED.h>
#define LED_PIN     10
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define framerate   200
//#define COLOR_CORRECTION CRGB(255,172,240)
#define BRIGHTNESS  50
#define NUM_LEDS    16
CRGB leds[NUM_LEDS];
CRGB buffer[NUM_LEDS];
// setup gets called once
void setup() {
   // power-up sanity delay
  delay( 3000 );
  
  // tell FastLED about the LEDs
  FastLED.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}
// loop is called repeatedly forever
void loop()
{
  // fill 'leds' array with a rainbow, starting at
  // a slightly different color each time, to create motion.
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* higher = faster motion */
  
  
  fill_rainbow(leds, NUM_LEDS, startIndex);
  
  for(int i=0;i<NUM_LEDS;i=i+2)
  {
   leds[i]=CRGB::Black;
  }  
 
  for(int z=0;z<NUM_LEDS;z++)
   {
      buffer[z]=leds[NUM_LEDS-z-1];
    }
  for(int y=0;y<NUM_LEDS;y++)
  {
      leds[y]+=buffer[y];
      
   }
  
  // tell FastLED to send the 'leds' buffer out to the
  // actual LEDs
  FastLED.show();
  
  // insert a delay to keep the framerate modest (eg, 60 FPS).
  // delay takes milliseconds, to 1000/60 = about 60 FPS.
  delay(framerate/60);
  
}

