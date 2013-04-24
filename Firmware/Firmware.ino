//    ____    __           __  ______
//   / __ \  / /___  _____/ /_/_  __/___  ____
//  / / / / / / __ \/ ___/ //_// / / __ \/ __ \
// / /_/ / / / /_/ / /__/ ,<  / / / /_/ / /_/ /
// \___\_\/_/\____/\___/_/|_|/_/  \____/\____/
//
// Firmware entry point for the QlockToo, an open-source remake of the QlockTwo.
// Author: Thomas Feldmann

#define VERSION "0.1"
#define BAUDRATE 57600

void setup()
{
    Serial.begin(BAUDRATE);
    api_init();
    matrix_init();
}

void loop()
{
    api_update();
    matrix_update();
}
