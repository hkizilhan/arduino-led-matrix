void shift_screen_left(byte shift_count){
  for (int i=0; i<8; i++){
    ScreenBuffer[i] = ScreenBuffer[i] << shift_count;
  }
}

void shift_screen_right(byte shift_count){
  for (int i=0; i<8; i++){
    ScreenBuffer[i] = ScreenBuffer[i] >> shift_count;
  }
}

void clear_screen(){
  for (int i=0; i<8; i++){
    ScreenBuffer[i] = 0;
  }
}

void fill_screen(){
  for (int i=0; i<8; i++){
    ScreenBuffer[i] = 16777215;
  }
}

void invert_screen(){
  for (int i=0; i<8; i++){
    ScreenBuffer[i] = ~ScreenBuffer[i];
  }
}

void set_screen_frame(long row0, long row1, long row2, long row3, long row4, long row5, long row6, long row7){
  ScreenBuffer[0] = row0;
  ScreenBuffer[1] = row1;
  ScreenBuffer[2] = row2;
  ScreenBuffer[3] = row3;
  ScreenBuffer[4] = row4;
  ScreenBuffer[5] = row5;
  ScreenBuffer[6] = row6;
  ScreenBuffer[7] = row7;
}

void set_pixel(byte x, byte y){
  if (x < 0 || x > 23) return;
  if (y < 0 || y > 7 ) return;
  bitSet(ScreenBuffer[y], 23-x);
}

byte get_pixel(byte x, byte y){
  if (x < 0 || x > 23) return 0;
  if (y < 0 || y > 7 ) return 0;
  return bitRead(ScreenBuffer[y], 23-x);
}

void clear_pixel(byte x, byte y){
  if (x < 0 || x > 23) return;
  if (y < 0 || y > 7 ) return;
  bitClear(ScreenBuffer[y], 23-x);
}


void set_sprite_8(byte x, byte y, prog_uchar sprite[]){
  
  byte width =  pgm_read_byte( &sprite[0] );
  byte height =  pgm_read_byte( &sprite[1] );
  
  for (byte i=0; i < height; i++){
    for (byte j=0; j < width; j++){
          
          if ( bitRead(  pgm_read_byte( &sprite[i+2] )  , width - j -1) == 1)
            set_pixel(x + j , y + i);
          else
            clear_pixel(x + j , y + i);
      
    } // j width
  } //i height
}


void clear_sprite_8(byte x, byte y, prog_uchar sprite[]){
  
  byte width =  pgm_read_byte( &sprite[0] );
  byte height =  pgm_read_byte( &sprite[1] );
  
  for (byte i=0; i < height; i++){
    for (byte j=0; j < width; j++){
          
      clear_pixel(x + j , y + i);
      
    } // j width
  } //i height

 
 
} 




//==============================================

void reset_scan(){
  Scan_Row = 0;
  TCNT1 = 2499;
}

void begin_sprite(){
  cli(); reset_scan();
}

void end_sprite(){  
  sei();
}


void array_shuffle(byte array[], byte n){

  byte i;
  for (i = 0; i < n - 1; i++) {
    byte j = TrueRandom.random(i, n-1);
    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;
  }
}

int availableMemory() {
  int size = 2048; // Use 2048 with ATmega328
  byte *buf;

  while ((buf = (byte *) malloc(--size)) == NULL)
    ;

  free(buf);

  return size;
}

void print_free_mem(){
  
  char buf[11];
  
  int av_mem = availableMemory();
  sprintf(buf, "MEM: %d", av_mem);
  
  anim_scroll_text(50, buf);
}
