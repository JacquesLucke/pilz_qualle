#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 44
#define USED_LEDS 25

CRGB leds[NUM_LEDS];

void setup() {
  // delay(3000);

  FastLED.addLeds<WS2812B, D2>(leds, NUM_LEDS);
}

static CRGB getColorAtTime(const float time) {
  const float hue = sinf(time * 0.03f);
  const float saturation = pow(sinf(time * 0.02f), 2);
  const float brightness = std::max(0.05, pow(sinf(time), 2));
  return CHSV(hue * 255, saturation * 255, brightness * 255);
}

void loop() {
  const float currentTime = millis() / 1000.0f;
  for (int i = NUM_LEDS - USED_LEDS - 1; i < NUM_LEDS; i++) {
    const float timeOffset = i * 0.03f;
    leds[i] = getColorAtTime(currentTime + timeOffset);
  }
  FastLED.show();
}
