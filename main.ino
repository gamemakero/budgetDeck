//librerias usadas
#include <Keyboard.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//prepara la pantalla (adafruit)
#define OLED_MOSI  16
#define OLED_CLK   10
#define OLED_DC    15
#define OLED_CS    12
#define OLED_RESET 14
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//botones
#define MENU_BACK 6
#define MENU_NEXT A3
#define BTN1 5
#define BTN2 3
#define BTN3 4
#define BTN4 2

#define numMenus 1
int menu; //controlar la información que se muestra
/*
   Muestra en pantalla la información del menú requerido
   ATTR: int menu, número de menú al que queremos acceder.
*/
void displayMenu(int menuActual) {
  display.clearDisplay();
  display.display();
  delay(300);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  switch (menuActual) {
    case 0:
      display.println("1: Firefox");
      display.println("2: Grabar");
      display.println("3: Captura");
      display.println("4: Empty");
      display.display();
      break;
    case 1:
      display.println("5: Mute");
      display.println("6: ");
      display.println("B");
      display.println("C");
      display.display();
      break;
    case 2:
      display.println("Me cago en");
      display.println("la leche,");
      display.setTextSize(3);
      display.println("Merche");
      display.display();
      break;
    case 3:
      display.println("HACKERMAN");
      display.display();
      break;
    default:
      display.println("Bienvenido");
      display.display();
      delay(2000);
      displayMenu(0);

  }
}

/**
   Funcion auxiliar
   Presiona todas las teclas necesarias para activar un atajo
*/
void atajo(int boton, int menuActual) {

  char ctrl = KEY_LEFT_CTRL; //variables para facilitar uso de teclas mod.
  char alt = KEY_LEFT_ALT;
  int PrintScreen = 206; //codigo
  char win = KEY_LEFT_GUI;


  switch (menuActual) {
    case 0:
      switch (boton) {
        case BTN1:
          Keyboard.press(ctrl);
          Keyboard.press(alt);
          Keyboard.press('u');
          break;
        case BTN2:
          Keyboard.press(ctrl);
          Keyboard.press(alt);
          Keyboard.press('r');
          break;
        case BTN3:
          Keyboard.press(win);
          Keyboard.press(PrintScreen);
          break;
      }//fin switch boton
      break;
  }//fin switch menu

  delay(100); //espera
  Keyboard.releaseAll();
}

void setup() {
  Serial.begin(9600);//abre la conexion serial a 9600bps

  Keyboard.begin(); //activa el teclado

  display.begin(SSD1306_SWITCHCAPVCC);//encendemos la pantalla
  display.display();
  delay(2000);

  //configuración de los botones
  pinMode(MENU_BACK, INPUT_PULLUP);
  pinMode(MENU_NEXT, INPUT_PULLUP);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);

  menu = 0; //inicializamos variable
  displayMenu(-1);
}

void loop() {

  if (!digitalRead(MENU_BACK)) {
    menu = (menu - 1) % numMenus;
    displayMenu(menu);
  }
  if (!digitalRead(MENU_NEXT)) {
    menu = (menu + 1) % numMenus;
    displayMenu(menu);
  }
  if (!digitalRead(BTN1)) {
    atajo(BTN1, menu);
  }
  if (!digitalRead(BTN2)) {
    atajo(BTN2, menu);
  }
  if (!digitalRead(BTN3)) {
    atajo(BTN3, menu);
  }
  if (!digitalRead(BTN4)) {
    atajo(BTN4, menu);
  }
  delay(200);
}
