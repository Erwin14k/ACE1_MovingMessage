#include <LedControl.h>

// definir 10 pines para cada fila de control de leds
// 13 = primera fila de arriba hacia abajo
// 4 = ultima fila de arriba hacia abajo

// // cada posicion indica que columna debera encenderse.
// se tendra que enviar 10 filas en cada actualizacion

#define row1 13
#define row2 12
#define row3 11
#define row4 10
#define row5 9
#define row6 8
#define row7 7
#define row8 6
#define row9 5
#define row10 4

// A cada fila se le enviará el arreglo de 32 posiciones
// pixeles por fila = 32 (dos tiras de 16 pixeles)
#define NUMPIXELS 32

// se utilizará la libreria Adafruit_NEOPIXEL
// esta libreria provee instanciar objetos lo cual para nuestro caso son las filas
#include <Adafruit_NeoPixel.h>

// objetos tipo NeoPixel de filas
Adafruit_NeoPixel row1_strip(NUMPIXELS, row1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row2_strip(NUMPIXELS, row2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row3_strip(NUMPIXELS, row3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row4_strip(NUMPIXELS, row4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row5_strip(NUMPIXELS, row5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row6_strip(NUMPIXELS, row6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row7_strip(NUMPIXELS, row7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row8_strip(NUMPIXELS, row8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row9_strip(NUMPIXELS, row9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row10_strip(NUMPIXELS, row10, NEO_GRB + NEO_KHZ800);

//MATRIZ EN SERIE CON LEDCONTROL
#define data_pin  24
#define load_pin  23
#define clock_pin 22
const int num_displays = 3;
LedControl matriz_superior  = LedControl(data_pin, clock_pin, load_pin, num_displays);



// paleta de colores para hacer interesante la impresion del mensaje
int paleta[8][3] = {
  {205, 97, 85},
  {155, 89, 182},
  {41, 128, 185},
  {26, 188, 156},
  {46, 204, 113},
  {241, 196, 15},
  {230, 126, 34},
  {52, 73, 94}
};

// CADENA DE TEXTO ACE1 - GRUPO#10
// para modificar utilizar el programa python almacenado en la carpeta del proyecto "word2matrix"

// modificar los valores de filas_necesarias, columnas necesarias a continuacion con los datos en el archivo
const int filas_necesarias = 10;
const int columnas_necesarias = 90;
// pegar la matriz generada :: verificar el formato => {{fila1},{fila2},{fila3},{fila4},{fila5},{fila6},{fila7},{fila8},{fila9},{fila10}};

int cadena[filas_necesarias][columnas_necesarias] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0},
  {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// COMUNICACION SERIAL
String mensaje = "";
String estado;

void setup()
{
  //  instanciar las tiras
  row1_strip.begin();
  row2_strip.begin();
  row3_strip.begin();
  row4_strip.begin();
  row5_strip.begin();
  row6_strip.begin();
  row7_strip.begin();
  row8_strip.begin();
  row9_strip.begin();
  row10_strip.begin();

  //  inicializar terminal
  Serial.begin(9600);
  Serial.println("Setup Terminado");

  // setup matrices seriales
  matriz_superior.shutdown(0, false);
  matriz_superior.shutdown(1, false);
  matriz_superior.shutdown(2, false);
  matriz_superior.setIntensity(0, 8);
  matriz_superior.setIntensity(1, 8);
  matriz_superior.setIntensity(2, 8);
  matriz_superior.clearDisplay(0);
  matriz_superior.clearDisplay(1);
  matriz_superior.clearDisplay(2);
}

void loop()
{
  // apagarLeds para actualizar
  apagarTiras();
  //    Serial.println("Impresion de Cadena");
  //    imprimirCadena();

    checkData();
//  armarPalabra("abcd");

  //  test #1: encender columnas impares
  //  par_impar();
}

// funcion para apagar tiras
void apagarTiras()
{
  row1_strip.clear();
  row2_strip.clear();
  row3_strip.clear();
  row4_strip.clear();
  row5_strip.clear();
  row6_strip.clear();
  row7_strip.clear();
  row8_strip.clear();
  row9_strip.clear();
  row10_strip.clear();
}

void limpiarTiras()
{

  for (int columna = 0; columna < 36; columna++)
  {
    row1_strip.setPixelColor(columna, row1_strip.Color(0, 0, 0));
    row2_strip.setPixelColor(columna, row2_strip.Color(0, 0, 0));
    row3_strip.setPixelColor(columna, row3_strip.Color(0, 0, 0));
    row4_strip.setPixelColor(columna, row4_strip.Color(0, 0, 0));
    row5_strip.setPixelColor(columna, row5_strip.Color(0, 0, 0));
    row6_strip.setPixelColor(columna, row6_strip.Color(0, 0, 0));
    row7_strip.setPixelColor(columna, row7_strip.Color(0, 0, 0));
    row8_strip.setPixelColor(columna, row8_strip.Color(0, 0, 0));
    row9_strip.setPixelColor(columna, row9_strip.Color(0, 0, 0));
    row10_strip.setPixelColor(columna, row10_strip.Color(0, 0, 0));
  }

  row1_strip.show();
  row2_strip.show();
  row3_strip.show();
  row4_strip.show();
  row5_strip.show();
  row6_strip.show();
  row7_strip.show();
  row8_strip.show();
  row9_strip.show();
  row10_strip.show();
}

// FUNCIONES DE UTILIDAD
void esperarSegundos(double segundos)
{
  delay(segundos * 1000);
}

// funcion que recibe #fila <int> (1-10) , #columna <int> (1-32)
//**la funcion hará el ajuste respecto a la interpretacion del arreglo (#columna-1)
void encenderLed(int fila, int columna)
{

  int num_random;
  int color[3];
  num_random = random(0, 2);
  color[0] = paleta[num_random][0];
  color[1] = paleta[num_random][1];
  color[2] = paleta[num_random][2];
  if ((columna - 1) < 8) {
    matriz_superior.setLed(0, fila - 1, (columna) - 1, true );
  }
  else if ((columna - 1) >= 8 && (columna - 1) < 16) {
    matriz_superior.setLed(1, fila - 1, columna - 9, true );
  } else {
    matriz_superior.setLed(2, fila - 1, columna - 17, true );
  }


  switch (fila)
  {
    case 1:

      //      row1_strip.setPixelColor(columna - 1, row1_strip.Color(color[0], color[1], color[2]));
      row1_strip.setPixelColor(columna - 1, row1_strip.Color(paleta[0][0], paleta[0][1], paleta[0][2]));
      row1_strip.show();


      break;

    case 2:
      //      num_random = random(0, 8);
      //      color[0] = paleta[num_random][0];
      //      color[1] = paleta[num_random][1];
      //      color[2] = paleta[num_random][2];

      row2_strip.setPixelColor(columna - 1, row2_strip.Color(paleta[1][0], paleta[1][1], paleta[0][2]));
      row2_strip.show();


      break;

    case 3:
      //      num_random = random(0, 8);
      //      color[0] = paleta[num_random][0];
      //      color[1] = paleta[num_random][1];
      //      color[2] = paleta[num_random][2];

      row3_strip.setPixelColor(columna - 1, row3_strip.Color(paleta[2][0], paleta[2][1], paleta[2][2]));
      row3_strip.show();
      break;

    case 4:
      //      num_random = random(0, 8);
      //      color[0] = paleta[num_random][0];
      //      color[1] = paleta[num_random][1];
      //      color[2] = paleta[num_random][2];

      row4_strip.setPixelColor(columna - 1, row4_strip.Color(paleta[3][0], paleta[3][1], paleta[3][2]));
      row4_strip.show();
      break;

    case 5:
      //      num_random = random(0, 8);
      //      color[0] = paleta[num_random][0];
      //      color[1] = paleta[num_random][1];
      //      color[2] = paleta[num_random][2];

      row5_strip.setPixelColor(columna - 1, row5_strip.Color(paleta[4][0], paleta[4][1], paleta[4][2]));
      row5_strip.show();
      break;

    case 6:
      //      num_random = random(0, 8);
      //      color[0] = paleta[num_random][0];
      //      color[1] = paleta[num_random][1];
      //      color[2] = paleta[num_random][2];

      row6_strip.setPixelColor(columna - 1, row6_strip.Color(paleta[4][0], paleta[4][1], paleta[4][2]));
      row6_strip.show();
      break;

    case 7:
      //      num_random = random(0, 8);
      //      color[0] = paleta[num_random][0];
      //      color[1] = paleta[num_random][1];
      //      color[2] = paleta[num_random][2];

      row7_strip.setPixelColor(columna - 1, row7_strip.Color(paleta[3][0], paleta[3][1], paleta[3][2]));
      row7_strip.show();
      break;

    case 8:
      //      num_random = random(0, 8);
      //      color[0] = paleta[num_random][0];
      //      color[1] = paleta[num_random][1];
      //      color[2] = paleta[num_random][2];

      row8_strip.setPixelColor(columna - 1, row8_strip.Color(paleta[2][0], paleta[2][1], paleta[2][2]));
      row8_strip.show();
      break;

    case 9:
      //      num_random = random(0, 8);
      //      color[0] = paleta[num_random][0];
      //      color[1] = paleta[num_random][1];
      //      color[2] = paleta[num_random][2];

      row9_strip.setPixelColor(columna - 1, row9_strip.Color(paleta[1][0], paleta[1][1], paleta[1][2]));
      row9_strip.show();
      break;

    case 10:
      //      num_random = random(0, 8);
      //      color[0] = paleta[num_random][0];
      //      color[1] = paleta[num_random][1];
      //      color[2] = paleta[num_random][2];

      row10_strip.setPixelColor(columna - 1, row10_strip.Color(paleta[0][0], paleta[0][1], paleta[0][2]));
      row10_strip.show();
      break;
  }
}

// el metodo utiliza la cadena definida al principio del archivo
void imprimirCadena()
{
  //  el inicio del desplazamiento comienza en -36 para que empiece desde el extremo derecho.
  int desplazamiento = -36;

  while (desplazamiento < columnas_necesarias)
  {
    //    para la mejora en la animacion primero se encenderan las filas pares y por ultimo las impares asi la animacion será un poco mas legible
    // por defecto la animacion iba de arriba a bajo por la naturaleza del ciclo for.
    for (int fila = 1; fila <= filas_necesarias; fila++)
    {
      for (int columna = 1; columna <= columnas_necesarias; columna++)
      {
        if (fila % 2 == 0)
        {
          if (cadena[fila - 1][columna - 1] == 1)
          {
            encenderLed(fila + 1, columna - 1 - desplazamiento);
          }
        }
      }
    }

    for (int fila = 1; fila <= filas_necesarias; fila++)
    {
      for (int columna = 1; columna <= columnas_necesarias; columna++)
      {
        if (fila % 2 != 0)
        {
          if (cadena[fila - 1][columna - 1] == 1)
          {
            encenderLed(fila + 1, columna - 1 - desplazamiento);
          }
        }
      }
    }

    //  insertar un delay con fines de mejora de rendimiento
    esperarSegundos(0.1);

    //   incrementar el desplazamiento en una posicion
    desplazamiento++;

    //    limpiar la pantalla para actualizar
    limpiarTiras();
  }
}

void checkData()
{
  if (Serial.available() > 0)
  {
    mensaje = "";
  }
  while (Serial.available() > 0)
  {

    Serial.println("Dato recibido");
    mensaje += char(Serial.read());
  }

  if (Serial.available() <= 0)
  {
    actualizarMensaje();
  }
  // delay(1000);
}

void actualizarMensaje()
{
  armarPalabra(mensaje);
}

// CREAR UN METODO PURO EN C,C++ QUE CONVIERTA LAS LETRAS Y LAS UNA

void armarPalabra(String palabra)
{

  int a[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int b[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int c[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int d[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int e[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int f[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int g[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int h[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int il[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int jo[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int ka[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {1, 1, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int el[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int m[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 0, 1, 1, 0},
    {1, 0, 1, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int n[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 0, 0, 1, 0},
    {1, 0, 1, 0, 1, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int o[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int p[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int q[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int r[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int s[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int t[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int u[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int v[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int w[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int x[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int y[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int z[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int space[10][6] = {

    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num1[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num2[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num3[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num4[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num5[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num6[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num7[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num8[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num9[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int num0[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int hyphen[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  int sharp[10][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  // convertir palabra a minusculas
  Serial.println("To Lower");

  for (int i = 0; i < palabra.length(); i++)
  {
    // palabra[i] = tolower(palabra[i]);
    Serial.println(int(palabra[i]));
  }

  // recorrer palabra
  for (int i = 0; i < palabra.length(); i++)
  {
    if (char(palabra[i]) >= 97 && char(palabra[i]) <= 122)
    {
      if (char(palabra[i]) >= 97 && char(palabra[i]) <= 102)
      {

        if (palabra[i] == 'a')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (a[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);


              }
            }
          }
        }

        if (palabra[i] == 'b')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (b[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'c')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (c[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'd')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (d[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'e')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (e[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'f')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (f[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }
      }

      if (palabra[i] >= 103 && palabra[i] <= 108)
      {
        if (palabra[i] == 'g')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (g[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'h')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (h[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'i')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (il[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'j')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (jo[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'k')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (ka[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'l')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (el[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }
      }

      if (char(palabra[i]) >= 109 && char(palabra[i]) <= 114)
      {
        if (palabra[i] == 'm')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (m[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'n')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (n[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'o')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (o[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'p')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (p[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'q')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (q[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'r')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (r[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }
      }

      if (char(palabra[i]) >= 115 && char(palabra[i]) <= 122)
      {
        if (palabra[i] == 's')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (s[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 't')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (t[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'u')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (u[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'v')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (v[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'w')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (w[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'x')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (x[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'y')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (y[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == 'z')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (z[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }
      }

      if (char(palabra[i]) == 32 || char(palabra[i]) == 35 || char(palabra[i]) == 45)
      {
        if (palabra[i] == ' ')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (space[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == '-')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (hyphen[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }

        if (palabra[i] == '#')
        {
          for (int j = 0; j < 10; j++)
          {
            for (int k = 0; k < 6; k++)
            {
              if (sharp[j][k] == 1)
              {
                int desplazamiento = k + (6 * i);
                encenderLed(j + 1, desplazamiento + 1);
              }
            }
          }
        }
      }

      // if (char(palabra[i]) >= 48 && char(palabra[i]) <= 57)
      // {
      //   if (palabra[i] == '1')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num1[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }

      //   if (palabra[i] == '2')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num2[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }

      //   if (palabra[i] == '3')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num3[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }

      //   if (palabra[i] == '4')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num4[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }

      //   if (palabra[i] == '5')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num5[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }

      //   if (palabra[i] == '6')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num6[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }

      //   if (palabra[i] == '7')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num7[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }

      //   if (palabra[i] == '8')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num8[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }

      //   if (palabra[i] == '9')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num9[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }

      //   if (palabra[i] == '0')
      //   {
      //     for (int j = 0; j < 10; j++)
      //     {
      //       for (int k = 0; k < 6; k++)
      //       {
      //         if (num0[j][k] == 1)
      //         {
      //           int desplazamiento = k + (6 * i);
      //           encenderLed(j + 1, desplazamiento + 1);
      //         }
      //       }
      //     }
      //   }
      // }

      delay(500);
    }
  }
}

// area de pruebas
// la funcion par_impar encendera los leds pares para las filas pares y leds impares para filas impares
void par_impar()
{

  for (int fila = 1; fila <= 10; fila++)
  {
    for (int columna = 1; columna <= NUMPIXELS; columna++)
    {
      if (fila % 2 == 0)
      {
        if (columna % 2 == 0)
        {
          encenderLed(fila, columna);
        }
      }
      else
      {
        if (columna % 2 != 0)
        {
          encenderLed(fila, columna);
        }
      }
    }
  }
}
