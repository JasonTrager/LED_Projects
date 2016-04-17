
void Animation_1()
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
  delay(framerate/20);
}
//
void Animation_2()
{
    // fill 'leds' array with a rainbow, starting at
  // a slightly different color each time, to create motion.
  static uint8_t startIndex = 0;
  startIndex = startIndex + 4; /* higher = faster motion */
  
  
  fill_rainbow(leds, NUM_LEDS, startIndex);
  FastLED.show();
  
  // insert a delay to keep the framerate modest (eg, 60 FPS).
  // delay takes milliseconds, to 1000/60 = about 60 FPS.
  delay(framerate/60);
}
//

void random_ring()
{
  int randomizer;
  for(int i=0; i<NUM_LEDS; i++){
    leds[i]=leds[i] + CHSV(0,0,(random(25)-random(50)));
    randomizer = random(999);
    if(randomizer %2 ==0)
    {
          leds[i].setRGB(random(255),random(255),random(255));

    }
    if(leds[i].getAverageLight()>180)
      leds[i]=CRGB::Black;
  }

  FastLED.show();
  delay(framerate);


}