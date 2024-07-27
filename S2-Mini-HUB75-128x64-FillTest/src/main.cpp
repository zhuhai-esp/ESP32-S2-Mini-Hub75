#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define R1_PIN 18
#define G1_PIN 14
#define B1_PIN 16
#define R2_PIN 17
#define G2_PIN 13
#define B2_PIN 21
#define A_PIN 34
#define B_PIN 8
#define C_PIN 36
#define D_PIN 4
#define LAT_PIN 2
#define OE_PIN 40
#define CLK_PIN 38
#define E_PIN 10

/********** CONFIG *************/
#define PANEL_WIDTH 128
#define PANEL_HEIGHT 64
#define PANELS_NUMBER 1

MatrixPanel_I2S_DMA *dma_display = nullptr;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  HUB75_I2S_CFG mxconfig;
  mxconfig.mx_width = PANEL_WIDTH;
  mxconfig.mx_height = PANEL_HEIGHT;
  mxconfig.chain_length = PANELS_NUMBER;
  mxconfig.gpio.r1 = R1_PIN;
  mxconfig.gpio.g1 = G1_PIN;
  mxconfig.gpio.b1 = B1_PIN;
  mxconfig.gpio.r2 = R2_PIN;
  mxconfig.gpio.g2 = G2_PIN;
  mxconfig.gpio.b2 = B2_PIN;
  mxconfig.gpio.a = A_PIN;
  mxconfig.gpio.b = B_PIN;
  mxconfig.gpio.c = C_PIN;
  mxconfig.gpio.d = D_PIN;
  mxconfig.gpio.e = E_PIN;
  mxconfig.gpio.lat = LAT_PIN;
  mxconfig.gpio.oe = OE_PIN;
  mxconfig.gpio.clk = CLK_PIN;

  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(70);
}

void loop() {
  dma_display->fillScreen(dma_display->color565(0xFF, 0, 0));
  delay(1000);
  dma_display->fillScreen(dma_display->color565(0, 0, 0xFF));
  delay(1000);
  dma_display->fillScreen(dma_display->color565(0, 0xFF, 0));
  delay(1000);
  dma_display->fillScreen(dma_display->color565(0xFF, 0xFF, 0));
  delay(1000);
  dma_display->fillScreen(dma_display->color565(0, 0xFF, 0xFF));
  delay(1000);
  dma_display->fillScreen(dma_display->color565(0xFF, 0xFF, 0xFF));
  delay(1000);
}