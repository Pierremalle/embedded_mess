#include <FastLED.h>

// Définir le type de LED et le PIN utilisé
#define LED_PIN 1
#define NUM_LEDS 60

// Déclarer un tableau pour stocker les données des LEDs
CRGB leds[NUM_LEDS];

void setup()
{
  // Initialiser FastLED
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void magmaticLightning()
{
  // Allumer toutes les LEDs en rouge
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Orange;
  }
  FastLED.show(); // Mettre à jour les LEDs
  delay(1000);

  // Éteindre toutes les LEDs
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(1000);
}

void loop()
{
  magmaticLightning();
}