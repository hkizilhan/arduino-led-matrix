

void anim_fill_flash(int seconds, int anim_speed)
{
  unsigned long start_time;
  unsigned long elapsed_time;
  int total_seconds;
  
  start_time = millis();
  
  do
  {
    fill_screen();
    delay(anim_speed);
    clear_screen();
    delay(anim_speed);
    
    elapsed_time = millis() - start_time;
    total_seconds = (int)(elapsed_time / 1000UL);
    
  } while (total_seconds < seconds);  
  
  
}


void anim_fill_up_down(int anim_speed)
{
  for (int i=0; i<8; i++){
    ScreenBuffer[i] = 16777215;
    delay(anim_speed);
  }
  
}

void anim_fill_down_up(int anim_speed)
{
  for (int i=8; i>0; i--){
    ScreenBuffer[i-1] = 16777215;
    delay(anim_speed);
  }
}

void anim_fill_left_right(int anim_speed)
{
  unsigned long mask=0;
  
  for (byte i=24; i>0; i--){
    // set mask
    bitSet(mask, i-1);
    // update buffers
    for (byte j=0; j<8; j++){
      ScreenBuffer[j] = mask;
    }
    
    delay(anim_speed);
  }
}

void anim_fill_right_left(int anim_speed)
{
  unsigned long mask=0;
  
  for (byte i=0; i<24; i++){
    // set mask
    bitSet(mask, i);
    // update buffers
    for (byte j=0; j<8; j++){
      ScreenBuffer[j] = mask;
    }
    
    delay(anim_speed);
  }
}

void anim_random_pixel(int seconds, int anim_speed)
{
  unsigned long start_time;
  unsigned long elapsed_time;
  int total_seconds;
  
  start_time = millis();
  
  do
  {
    // Generate Random Pixels
    for (int i=0; i<8; i++){
      ScreenBuffer[i] = random(16777215);
    }
    
    delay(anim_speed);
    
    elapsed_time = millis() - start_time;
    total_seconds = (int)(elapsed_time / 1000UL);
    
  } while (total_seconds < seconds);

}


void anim_sequential_fill_unfill(int fill_speed, int unfill_speed, int fill_delay, int unfill_delay){
  
  clear_screen();
  anim_sequential_fill(fill_speed);
  delay(fill_delay);
  anim_sequential_unfill(unfill_speed);
  delay(unfill_delay);
  
}

void anim_sequential_fill(int anim_speed){
  int total_pixels = 192;

  do {

    for (byte i=0; i<8; i++){

      byte x_pixel;

      do {
        x_pixel = random(0, 24);
      } while (get_pixel(x_pixel, i) );
      
      set_pixel(x_pixel, i);
      total_pixels--;
      
      delay(anim_speed);
    }
 
  } while (total_pixels);

}

void anim_sequential_unfill(int anim_speed){
  int total_pixels = 192;

  do {

    for (byte i=0; i<8; i++){

      byte x_pixel;

      do {
        x_pixel = random(0, 24);
      } while (get_pixel(x_pixel, i) == 0 );
      
      clear_pixel(x_pixel, i);
      total_pixels--;
      
      delay(anim_speed);
    }
 
  } while (total_pixels);

}

void anim_messi(byte counter){
  
  for(byte i=0; i<counter; i++){
    
    set_screen_frame(0, 0, 4583290, 7145538, 5623674, 4522250, 4583290, 0); // MESSI
    delay(1000);
    invert_screen();
    delay(300);
  }
}

void anim_heart_beat(byte counter){
  
  for(byte i=0; i<counter; i++){
    
    set_screen_frame(0, 1622808, 4057020, 2081784, 1016304, 458976, 131136, 0);
    delay(800);
    set_screen_frame(1622808, 4057020, 4188156, 4188156, 2081784, 1016304, 458976, 131136);
    delay(250);
  }  
}


void anim_volvo_t5(int seconds, int anim_speed)
{
  unsigned long start_time;
  unsigned long elapsed_time;
  int total_seconds;
  
  start_time = millis();
  
  do
  {
    set_screen_frame(3595132, 8388496, 13237456, 13237463, 13631444, 16777159, 14513601, 16777159);
    delay(anim_speed);
    set_screen_frame(3595132, 8388496, 13231312, 13630679, 13630676, 16777159, 15445697, 16777159);
    delay(anim_speed);
    set_screen_frame(3595132, 8388496, 13624528, 13624535, 16776404, 16777159, 14513601, 16777159);    
    delay(anim_speed);
    set_screen_frame(3595132, 8388496, 13575376, 16770263, 16770260, 16777159, 15445697, 16777159);    
    delay(anim_speed);
    set_screen_frame(3595132, 8388496, 16721104, 16721111, 16771028, 16777159, 14513601, 16777159);    
    delay(anim_speed);
    set_screen_frame(3595132, 8388496, 16327888, 16721879, 16721876, 16777159, 15445697, 16777159);    
    delay(anim_speed);
    set_screen_frame(3595132, 8388496, 16328656, 16328663, 16728020, 16777159, 14513601, 16777159);    
    delay(anim_speed);
    set_screen_frame(3595132, 8388496, 13182928, 16334807, 16334804, 16777159, 15445697, 16777159);    
    delay(anim_speed);
    set_screen_frame(3595132, 8388496, 13189072, 13189079, 16383956, 16777159, 14513601, 16777159);    
    delay(anim_speed);
    set_screen_frame(3595132, 8388496, 13188304, 13238231, 13238228, 16777159, 15445697, 16777159);    
    delay(anim_speed);
    
    
    elapsed_time = millis() - start_time;
    total_seconds = (int)(elapsed_time / 1000UL);
    
  } while (total_seconds < seconds);

}

//=======================================================================

prog_uchar pacman_open_left[]  PROGMEM = {6, 6, B011100, B001110, B000111, B000111, B001110, B011100};
prog_uchar pacman_close[]      PROGMEM = {6, 6, B001100, B011110, B111111, B111111, B011110, B001100};
prog_uchar pacman_open_right[] PROGMEM = {6, 6, B001110, B011100, B111000, B111000, B011100, B001110};
  
prog_uchar monster_1[] PROGMEM = {6, 6, B011110, B101101, B111111, B111111, B010010, B100100};
prog_uchar monster_2[] PROGMEM = {6, 6, B011110, B101101, B111111, B111111, B010010, B001001};
 
void anim_pacman(){
   
  char counter = 25;
  char pacman_tick = 0;
  char monster_tick = 0;
  
  boolean pacman_state = false;
  boolean monster_state = false;
  
  // first turn
  while (counter > -40){
    
    // pacman
    if (pacman_state) {
      set_sprite_8(counter, 1, pacman_open_left);
    }else{
      set_sprite_8(counter, 1, pacman_close);
    }
    
    //monsters
    if (monster_state) {
      set_sprite_8(counter + 12, 1, monster_1);
      set_sprite_8(counter + 21, 1, monster_2);
      set_sprite_8(counter + 30, 1, monster_1);
    
    }else{
      set_sprite_8(counter + 12, 1, monster_2);
      set_sprite_8(counter + 21, 1, monster_1);
      set_sprite_8(counter + 30, 1, monster_2);
    }
    
    
    delay(100);
    clear_screen();
    
    
    counter--;
    
    pacman_tick++;
    if (pacman_tick > 2){
      pacman_tick = 0;
      pacman_state = !pacman_state;
    }
    
    
    monster_tick++;
    if (monster_tick == 6){
      monster_tick = 0;
      monster_state = !monster_state;
    }
  
  }
  
  
  // second turn
  while (counter < 40){
    
    // pacman
    if (pacman_state) {
      set_sprite_8(counter, 1, pacman_open_right);
    }else{
      set_sprite_8(counter, 1, pacman_close);
    }
    
    //monsters
    if (monster_state) {
      set_sprite_8(counter + 12, 1, monster_1);
      set_sprite_8(counter + 21, 1, monster_2);
      set_sprite_8(counter + 30, 1, monster_1);
    
    }else{
      set_sprite_8(counter + 12, 1, monster_2);
      set_sprite_8(counter + 21, 1, monster_1);
      set_sprite_8(counter + 30, 1, monster_2);
    }
    
    
    delay(70);
    clear_screen();
    
    
    counter++;
    
    pacman_tick++;
    if (pacman_tick > 1){
      pacman_tick = 0;
      pacman_state = !pacman_state;
    }
    
    
    monster_tick++;
    if (monster_tick == 6){
      monster_tick = 0;
      monster_state = !monster_state;
    }
  
  }
  
}

//================================================================

prog_uchar crazy_car_1[] PROGMEM = {8, 6, B00000001, B00000010, B00111111, B11111111, B11101111, B00111000};
prog_uchar crazy_car_2[] PROGMEM = {8, 6, B11111000, B00100100, B11111111, B11111111, B11110110, B00011100};

void print_crazy_car(byte x, byte y){
  begin_sprite();
  set_sprite_8(x +1 , y, crazy_car_1);
  set_sprite_8(x + 9, y, crazy_car_2);
  set_pixel(x, y + 4);
  set_pixel(x + 17 , y + 1);
  end_sprite();
}

void clear_crazy_car(){
  for (int i=1; i<7; i++){
    ScreenBuffer[i] = 0;
  }
}

void anim_crazy_car(int seconds, int anim_speed)
{
  unsigned long start_time;
  unsigned long elapsed_time;
  int total_seconds;
  
  start_time = millis();
  
  clear_screen();
  
  byte road_line = 0;
  char car_x = 50;
  enum car_states {car_intro, car_forward, car_backward, car_outtro} car_state;
  byte counter = 0;
  byte counter2 = 0;
  boolean anim_done = false;
  
  car_state = car_intro;
  do
  {
    if (anim_speed < 15) anim_speed = 15;
    
    delay(anim_speed);
    
    if (car_state == car_intro){
      counter2++;
      if (counter2 > 4){
        counter2 = 0;
      
        car_x--;
        clear_crazy_car();
        print_crazy_car(car_x, 1);
        if (car_x == 5) car_state = car_forward; 
      }
    }
    
    
    if (car_state == car_forward){
      counter++;
      if (counter == 20) {car_x--; clear_crazy_car(); print_crazy_car(car_x, 1); }
      if (counter == 40) {car_x--; clear_crazy_car(); print_crazy_car(car_x, 1); }
      if (counter == 60) {car_x--; clear_crazy_car(); print_crazy_car(car_x, 1); 
        car_state = car_backward;
        
        if (total_seconds > seconds) { anim_speed = anim_speed - 5; }
    
      }
    }// car_forward
    
    if (car_state == car_backward){
      counter--;
      if (counter == 40) {car_x++; clear_crazy_car(); print_crazy_car(car_x, 1); }
      if (counter == 20) {car_x++; clear_crazy_car(); print_crazy_car(car_x, 1); }
      if (counter == 0) {car_x++; clear_crazy_car(); print_crazy_car(car_x, 1); 
        car_state = car_forward;

        if (total_seconds > seconds) {
          anim_speed = anim_speed - 4;
          counter2++;
          if (counter2 > 6) { 
            counter=0;
            counter2=0;
            car_state = car_outtro; }
        }
      }
      
    }// car_backward
    
    if (car_state == car_outtro){
      counter++;
      if (counter > 5){
        counter = 0;
        counter2++;
        car_x--;
        clear_crazy_car(); 
        print_crazy_car(car_x, 1);
      
        if (counter2 > 30) anim_done = true;
      }
    }// car_outtro
    
    
    
    // print road line
    road_line++;
    if (road_line > 17) road_line = 0;   // check and reset
    
    if (road_line > 7 ) {
      bitSet(ScreenBuffer[7], 28);
      bitSet(ScreenBuffer[0], 24);
    }
    ScreenBuffer[7] = ScreenBuffer[7] >> 1;
    ScreenBuffer[0] = ScreenBuffer[0] >> 1;
     
    
    
    
    elapsed_time = millis() - start_time;
    total_seconds = (int)(elapsed_time / 1000UL);
    
  } while (!anim_done);

}

