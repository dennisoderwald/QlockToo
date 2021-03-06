#include "globals.h"
#include "font.h"

void temperature_setup()
{
    temperature_display((int)temperature_read_celsius());
    corner_clear();
}

void temperature_loop()
{
    if (second_has_changed)
    {
        temperature_display((int)temperature_read_celsius());
    }
}

float temperature_read_celsius()
{
    // values have been found experimentally
    return analogRead(THERMO_PIN) * 0.1145 - 33.449;
}

void temperature_display(byte temp)
{
    // settings
    const byte TOP = 2;
    const byte HEIGHT = 6;
    const byte WIDTH = 4;
    const byte LEFT_1 = 0;
    const byte LEFT_2 = 5;

    // split second in left and right part
    byte t_1 = temp / 10;
    byte t_2 = temp % 10;

    for (byte y = 0; y < ROWS; y++)
    {
        for (byte x = 0; x < COLS; x++)
        {
            // the rows
            if (y >= TOP && y < TOP + HEIGHT)
            {
                // first letter
                if (x < LEFT_1 + WIDTH)
                {
                    if (bitRead(numbers4x6[t_1][y - TOP], 7 - x + LEFT_1))
                    {
                        matrix[y][x] = BRIGHTNESS_FULL;
                    }
                    else
                    {
                        matrix[y][x] = 0;
                    }
                }
                // second letter
                else if (x >= LEFT_2 && x < LEFT_2 + WIDTH)
                {
                    if (bitRead(numbers4x6[t_2][y - TOP], 7 - x + LEFT_2))
                    {
                        matrix[y][x] = BRIGHTNESS_FULL;
                    }
                    else
                    {
                        matrix[y][x] = 0;
                    }
                }
                // clear the rest
                else
                    matrix[y][x] = 0;
            }
            else
                matrix[y][x] = 0;
        }
    }

    // degree symbol
    matrix[0][9] = BRIGHTNESS_FULL;
    matrix[0][10] = BRIGHTNESS_FULL;
    matrix[1][9] = BRIGHTNESS_FULL;
    matrix[1][10] = BRIGHTNESS_FULL;
}
