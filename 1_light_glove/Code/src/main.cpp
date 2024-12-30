#include <FastLED.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Définir le type de LED et le PIN utilisé
#define LED_PIN 1
#define NUM_LEDS 60

// Déclarer un tableau pour stocker les données des LEDs
CRGB leds[NUM_LEDS];

const CRGB magmaColor[] = {CRGB::Red, CRGB::Brown, CRGB::Orange};
size_t colorCount = sizeof(magmaColor) / sizeof(magmaColor[0]);

unsigned long lastTime = millis();

void setup()
{
  // Initialiser FastLED
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void ledOff()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(100);
  }
}

void randomMagma()
{
  std::srand(std::time(nullptr));
  for (int i = 0; i < NUM_LEDS; i++)
  {
    int random_number = std::rand() % (colorCount + 1); // Plage [0, max_value]
    leds[i] = magmaColor[random_number];
    FastLED.show();
    delay(50);
  }
}

void magmaticLightning()
{
  unsigned long currentTime = millis();

  unsigned long delta = currentTime - lastTime;

  randomMagma();
  delay(1000);

  ledOff();
  delay(750);

  // Mettre à jour le temps de la dernière boucle
  lastTime = currentTime;
}

void loop()
{
  magmaticLightning();
}