
// avr-libc library includes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "TrueRandom.h"
#include "font.h"


// Shift Register Stuff
const int latchPin = 8;    //Pin connected to ST_CP of 74HC595
const int clockPin = 12;   //Pin connected to SH_CP of 74HC595
const int dataPin  = 11;   ////Pin connected to DS of 74HC595

// Screen Buffer Variable
volatile unsigned long ScreenBuffer[8];
 
// Current Scanning Row Number
volatile byte Scan_Row = 0;

void setup()
{
    // Clear Screen
    clear_screen();
 
    // Set PORTD as output
    DDRD = 255;
    
    // Set Shift Register Pins as output
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    
    // initialize Timer1
    cli();          // disable global interrupts
    TCCR1A = 0;     // set entire TCCR1A register to 0
    TCCR1B = 0;     // same for TCCR1B
 
    // set compare match register to desired timer count:
    OCR1A = 2500;
    // turn on CTC mode:
    TCCR1B |= (1 << WGM12);
    // Set CS11 bit for 8 prescaler:
      //TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS11);
      //TCCR1B |= (1 << CS12);
    // enable timer compare interrupt:
    TIMSK1 |= (1 << OCIE1A);
    // enable global interrupts:
    sei();
}
 
void loop()
{
  //print_free_mem();

  byte anim_number;
  byte counter = 0;
  
  
  // update random seed
  randomSeed(TrueRandom.random());

    anim_number = TrueRandom.random(1, 35);

    clear_screen();

    switch (anim_number) {
      case 1:
        anim_fill_up_down(random(50, 200));
        break;
      
      case 4:
        anim_fill_down_up(random(50, 200));
        break;
      
      case 7:
        anim_fill_left_right(random(50, 200));
        break;
      
      case 10:
        anim_fill_right_left(random(50, 200));
        break;
      
      case 13:
        anim_fill_flash(random(5, 10), random(30, 300));
        break;
        
      case 16:
        anim_random_pixel(random(5, 10), random(30, 300));
        break;
        
      case 19:
        anim_sequential_fill_unfill(random(1, 5), random(1, 5), random(200, 1000), random(100, 500));
        break;
      
      case 22:
        anim_messi(random(4, 9));
        break;
        
      case 25:
        anim_heart_beat(random(4, 9));
        break;
        
      case 28:
        anim_pacman();
        break;
        
      case 31:
        anim_volvo_t5(random(10, 16), random(30, 70));
        break;
        
      case 34:
        anim_crazy_car(random(10, 16), random(30, 70));
        break;
        
      default:
        anim_scroll_text_random();
      
    } // switch
  
  
  counter++;
  if (counter > 15){
    counter = 0;
    anim_scroll_text_from_progmem(0);
  }
  
  
  
} //loop function




ISR(TIMER1_COMPA_vect){
  
  //// Update Shift Registers From Screen Buffer
  byte buf[3];
  buf[0] = (byte) ScreenBuffer[Scan_Row];
  buf[1] = (byte) (ScreenBuffer[Scan_Row] >> 8) & 0xFF;
  buf[2] = (byte) (ScreenBuffer[Scan_Row] >> 16) & 0xFF;
  
  // take the latchPin low so 
  // the LEDs don't change while you're sending in bits:
  digitalWrite(latchPin, LOW);
  
  // shift out the bits:
  shiftOut(dataPin, clockPin, LSBFIRST, buf[0]);
  shiftOut(dataPin, clockPin, LSBFIRST, buf[1]);
  shiftOut(dataPin, clockPin, LSBFIRST, buf[2]);
  
  //take the latch pin high so the LEDs will light up:
  digitalWrite(latchPin, HIGH);
    
  //// Do Scan...
  PORTD=0;  
  bitSet(PORTD, Scan_Row);
  Scan_Row++;
  if (Scan_Row == 8) Scan_Row = 0;
}

