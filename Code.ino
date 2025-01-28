//João Pedro Mori Noce - 3G - 23/05/2023
//PING-PONG #2

#include <Adafruit_NeoPixel.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_NeoPixel fita(20,13,NEO_GRB + NEO_KHZ800);
Adafruit_7segment placar = Adafruit_7segment();


#define BTN1 3
#define BTN2 2
int x;
int inicio = 0;
int s = 1;
int player1 = 0;
int player2 = 0;

void Placar(int a, int b)
{
  char ct;

  ct = a + 48;
  placar.print(ct);
  placar.write(0);
  placar.write(0);
  ct = b + 48;
  placar.print(ct);
  placar.println();

  placar.drawColon(true);

  placar.writeDisplay();
}
void setup()
{
  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BTN1),Btn1,FALLING);
  attachInterrupt(digitalPinToInterrupt(BTN2),Btn2,FALLING);

  fita.begin();
  fita.clear();

  placar.begin(0x70);
  Serial.begin(9600);

  Serial.println("PLACAR PING PONG DO JP");
}

void loop()
{
  Placar(player1, player2);

  if(player1 > 4){
    player1 = 0;
    player2 = 0;
    placar.drawColon(false);
    placar.print("1EBA");
    placar.writeDisplay();
    Serial.print("PLAYER1 WON!!!");
    delay(4000);
    placar.clear();
    Serial.println("");
    delay(1000);
    s = -1;
    inicio = 19;
    loop();
  }

  if(player2 > 4){
    player1 = 0;
    player2 = 0;
    placar.drawColon(false);
    placar.print("2EBA");
    placar.writeDisplay();
    Serial.print("PLAYER2 WON!!!");
    Serial.println("");
    delay(4000);
    placar.clear();
    delay(1000);
    s = 1;
    inicio = 0;
    loop();
  }
  
  Serial.print("PLAYER1  = ");
  Serial.print(player1);
  Serial.print(" | ");
  Serial.print("PLAYER2  = ");
  Serial.print(player2);
  Serial.println("");

  for(x = inicio; x > -1 && x < 20; x = x + s){
    fita.clear();

    if(digitalRead(BTN1) == 0){
      break;
    }
    if(digitalRead(BTN2) == 0){
      break;
    }

    if(x == 0 || x == 19){
      fita.setPixelColor(x,255,0,0); //vermelho
    }

    if(x == 1 || x == 18){
      fita.setPixelColor(x,255,255,0); //amarelo
    }

    if(x == 2 || x == 17){
      fita.setPixelColor(x,0,255,0); //verde
    }

    if(x >= 3 && x <= 16){
      fita.setPixelColor(x,0,0,255); //azul
    }

    fita.show();
    delay(500);
  }
  if(s == 1){
    s = -1;
    inicio = 19;
  }
  else{
    s = 1;
    inicio = 0;
  }
}

/////////////////////////////////////////////
void Btn2(){

  if(x == 17){
    for(x = 16;x >= 0;x = x - 1){
      fita.clear();

      if(x == 0){
        fita.setPixelColor(x,255,0,0);
      }

      if(x == 1){
        fita.setPixelColor(x,255,255,0);
      }

      if(x == 2){
        fita.setPixelColor(x,0,255,0);
      }

      if(x >= 3 && x <= 16){
        fita.setPixelColor(x,0,0,255);
      }
      fita.show();
      delay(400);
    }
  }

  if(x == 18){
    for(x = 17;x >= 0;x -= 1){
      fita.clear();

      if(x == 0){
        fita.setPixelColor(x,255,0,0);
      }

      if(x == 1){
        fita.setPixelColor(x,255,255,0);
      }

      if(x == 2 || x == 17){
        fita.setPixelColor(x,0,255,0);
      }

      if(x >= 3 && x <= 16){
        fita.setPixelColor(x,0,0,255);
      }
      fita.show();
      delay(300);
    }
  }

  if(x == 19){
    for(x = 18;x >= 0;x -= 1){
      fita.clear();

      if(x == 0){
        fita.setPixelColor(x,255,0,0);
      }

      if(x == 1 || x == 18){
        fita.setPixelColor(x,255,255,0);
      }

      if(x == 2 || x == 17){
        fita.setPixelColor(x,0,255,0);
      }

      if(x >= 3 && x <= 16){
        fita.setPixelColor(x,0,0,255);
      }
      fita.show();
      delay(200);
    }
  }
  if(x >= 0 && x <= 16){
    fita.clear();
    fita.show();
    delay(2000);
    s = 1;
    inicio = 0;
    player1 = player1 + 1;
    loop();
  }
}

////////////////////////////////////////////////

void Btn1(){

  if(x == 0){
    for(x = x + 1;x <= 19;x ++){
      fita.clear();

      if(x == 19){
        fita.setPixelColor(x,255,0,0);
      }

      if(x == 1 || x == 18){
        fita.setPixelColor(x,255,255,0);
      }

      if(x == 2 || x == 17){
        fita.setPixelColor(x,0,255,0);
      }

      if(x >= 3 && x <= 16){
        fita.setPixelColor(x,0,0,255);
      }
      fita.show();
      delay(200);
    }
  }

  if(x == 1){
    for(x = x + 1;x <= 19;x ++){
      fita.clear();

      if(x == 19){
        fita.setPixelColor(x,255,0,0);
      }

      if(x == 18){
        fita.setPixelColor(x,255,255,0);
      }

      if(x == 2 || x == 17){
        fita.setPixelColor(x,0,255,0);
      }

      if(x >= 3 && x <= 16){
        fita.setPixelColor(x,0,0,255);
      }
      fita.show();
      delay(300);
    }
  }

  if(x == 2){
    for(x = x + 1;x <= 19;x ++){
      fita.clear();

      if(x == 19){
        fita.setPixelColor(x,255,0,0);
      }

      if(x == 18){
        fita.setPixelColor(x,255,255,0);
      }

      if(x == 17){
        fita.setPixelColor(x,0,255,0);
      }

      if(x >= 3 && x <= 16){
        fita.setPixelColor(x,0,0,255);
      }
      fita.show();
      delay(400);
    }
  }
  if(x >= 3 && x <= 19 || digitalRead(BTN1) == 1 && x < 0){
    fita.clear();
    fita.show();
    delay(2000);
    s = -1;
    inicio = 19;
    player2 = player2 + 1;
    loop();
  }
}