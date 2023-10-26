#include <Tiny4kOLED.h>
#include "graphics.h"


int b = 2;
int pressed = false;
int sql_status = 0; //0 = not jumping, 1 = jumping phase 1, etc ... jumping phase 3;
int sql_hgt = 0;
int sql_theorical[8] = {0, 1, 2, 3, 3, 2, 1, 0};
int obstacles[3][3] = {{0, 0}, {-1, -1},{ -1, -1}};
int LOOSE = false;
int ospeed = 1;
int omspeed = 8;
int pspeed = 1;
int o_timer = 0;
int p_timer = 0;
int jump = 0;
uint8_t score = 0;
int nb_obstacles = 1;
int updated_d = 0;

// ============================================================================

void setup() {
  // put your setup code here, to run once:

  oled.begin();

  oled.clear();


  oled.on();
  oled.clear();
  oled.switchRenderFrame();
  oled.clear();
  oled.switchRenderFrame();
  pinMode(7, INPUT);
}

void update_sql(bool jump) {
  if (p_timer == pspeed) {
    if (sql_status && sql_status < 8) sql_status +=1;
    else sql_status = 0;
  
    if (jump && !sql_status) {
      sql_status += 1;
    }
  
    sql_hgt = sql_theorical[sql_status];
    
    
    p_timer = 0;
    display_update();

  }
  p_timer++;
  
  
}

void loose_check() {
  if (!sql_hgt) { //on the ground
      for (int i = 0; i < nb_obstacles; i ++) {
        if (obstacles[i][0] >= 102 && obstacles[i][0] <= 118) LOOSE = true;
      }
  }
}


void update_obs(){
  if (o_timer==ospeed) {
    for (int i = 0; i < nb_obstacles; i++) {
      if (obstacles[i][0] != -1) {
        obstacles[i][0]+= omspeed;
      }
      if (obstacles[i][0] > 132) {
        obstacles[i][0] = 0;
        score +=1;
        omspeed = 6 + score/10;
      }
    }
    o_timer = 0;
    display_update();

  }
  o_timer++;
  
}


void display_update() {
  if (!updated_d) {
    oled.switchRenderFrame();
    oled.clear();
    oled.bitmap(110, sql_hgt, 110+6, sql_hgt+1, trex);
    for (int i = 0; i < nb_obstacles; i++) {
      oled.bitmap(obstacles[i][0], 0, obstacles[i][0] + 8, 1, citrouille);
    }
    oled.switchDisplayFrame();
    updated_d = 1;
  }
  

}

void loop() {
  if (!LOOSE) {
    int played = digitalRead(b);
    if (!played && pressed) pressed = 0;
    if (played && !pressed) {
      pressed = !pressed;
      jump = 1;
      p_timer = pspeed;
    } else {
      jump = 0;
    }
    update_obs();
    if (jump || sql_status) update_sql(jump);
    loose_check();
    updated_d = 0;
    delay(0);
    
  } else {
      oled.switchRenderFrame();
      oled.clear();
      oled.setFont(FONT8X16);
      oled.setCursor(12, 0);
      oled.print(F("LOOSER"));
      oled.setCursor(12,2);
      oled.print(F("Score : "));
      oled.setCursor(75,2);
      oled.print(score);
      oled.switchDisplayFrame();
      int played = digitalRead(b);
      if (!played && pressed) pressed = 0;
      if (played && !pressed){
        obstacles[0][0] = 0;
        obstacles[1][0] = -1;
        obstacles[2][0] = -1;
        pressed = !pressed;
        delay(1000);
        score = 0;
        LOOSE = !LOOSE;
      }


  }
  
  
  // This example only shows a static image on the display.
  // The microcontroller could be turned off now.
}
