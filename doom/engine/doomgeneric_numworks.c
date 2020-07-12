#include "doomkeys.h"

#include "doomgeneric.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wrapper.h"

#define KEYQUEUE_SIZE 16

static __uint16_t keyQueue[KEYQUEUE_SIZE];
static __uint8_t keyQueueWriteIndex = 0;
static __uint8_t keyQueueReadIndex = 0;
static __uint8_t keyList[10] = {52, 4, 0, 1, 2, 3, 17, 5, 16, 12};

__uint32_t startTime;

static __uint8_t convertToDoomKey(__uint8_t key)
{
    switch (key)
    {
    case 4:
    case 52:
        key = KEY_ENTER;
        break;
    case 5:
        key = KEY_ESCAPE;
        break;
    case 0:
        key = KEY_LEFTARROW;
        break;

    case 1:
        key = KEY_UPARROW;
        break;
    case 2:
        key = KEY_DOWNARROW;
        break;
    case 3:
        key = KEY_RIGHTARROW;
        break;
    case 17:
        key = KEY_FIRE;
        break;
    case 16:
        key = KEY_USE;
        break;
    case 12:
        key = KEY_RSHIFT;
        break;
    default:
        key = -1;
        break;
    }

    return key;
}

static void addKeyToQueue(__uint8_t pressed, __uint8_t keyCode)
{
    __uint8_t key = convertToDoomKey(keyCode);
    if (key != -1)
    {
        unsigned short keyData = (pressed << 8) | key;

        keyQueue[keyQueueWriteIndex] = keyData;
        keyQueueWriteIndex++;
        keyQueueWriteIndex %= KEYQUEUE_SIZE;
    }
}

void DG_Init()
{
    startTime = millis();
}



// this is bad. will do it better later

__uint8_t lastKeyStates[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void DG_DrawFrame()
{

    pushRect(DOOMGENERIC_RESX, DOOMGENERIC_RESY, DG_ScreenBuffer);

    __uint8_t *keyStates = malloc(10);
    getKeyStates(keyStates, 10);

    for (int i = 0; i < 10; i++)
    {
        if (lastKeyStates[i] != keyStates[i])
        {
            addKeyToQueue(keyStates[i], keyList[i]);
        }
    }

    for (int i = 0; i < sizeof(keyStates); i++)
    {

        lastKeyStates[i] = keyStates[i];
    }
    free(keyStates);
}

void DG_SleepMs(uint32_t ms)
{
    sleep(ms);
}

uint32_t DG_GetTicksMs()
{
    return millis() - startTime;
}

__uint8_t DG_GetKey(int *pressed, unsigned char *doomKey)
{
    if (keyQueueReadIndex == keyQueueWriteIndex)
    {
        //key queue is empty

        return 0;
    }
    else
    {
        unsigned short keyData = keyQueue[keyQueueReadIndex];
        keyQueueReadIndex++;
        keyQueueReadIndex %= KEYQUEUE_SIZE;

        *pressed = keyData >> 8;
        *doomKey = keyData & 0xFF;

        return 1;
    }
}


// sets window title ro name of wad
// doom res y is only 200 and the screen is 240 so there would be 
// enough space but black bars are looking way better
// so we don't use it
void DG_SetWindowTitle(const char *title)
{
}
