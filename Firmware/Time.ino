//
// Time.ino
//

#include "globals.h"

void time_init()
{
    seconds = minutes = hours = day = month = year = 0;
    dcf77_init();
    time_startTimer();
}

void time_addSecond()
{
    seconds++;
    if (seconds == 60)
    {
        seconds = 0;

        minutes++;
        if (minutes == 60)
        {
            minutes = 0;

            hours++;
            if (hours == 24)
            {
                hours = 0;
            }
        }
    }
};

void time_dumpToSerial()
{
    Serial.print("#Time: ");
    Serial.print(hours, DEC);
    Serial.print(":");
    Serial.print(minutes, DEC);
    Serial.print(":");
    Serial.print(seconds, DEC);
    Serial.print(" Date: ");
    Serial.print(day, DEC);
    Serial.print(".");
    Serial.print(month, DEC);
    Serial.print(".");
    Serial.println(year, DEC);
}

void time_startTimer()
{
    // initialize timer1
    noInterrupts();           // disable all interrupts
    TCCR1A = 0;
    TCCR1B = 0;

    TCNT1 = 3036;             // preload timer 65536-16MHz/256/1Hz
    TCCR1B |= (1 << CS12);    // 256 prescaler
    TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
    interrupts();             // enable all interrupts
}

ISR(TIMER1_OVF_vect)
{
    time_addSecond();
    time_dumpToSerial();
}