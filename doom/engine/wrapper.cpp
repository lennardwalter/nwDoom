#include "wrapper.h"
#include <ion.h>
#include <stdint.h>

Ion::Keyboard::Key keysToCheck[] = {
    Ion::Keyboard::Key::EXE,
    Ion::Keyboard::Key::OK,
    Ion::Keyboard::Key::Left,
    Ion::Keyboard::Key::Up,
    Ion::Keyboard::Key::Down,
    Ion::Keyboard::Key::Right,
    Ion::Keyboard::Key::Backspace,
    Ion::Keyboard::Key::Back,
    Ion::Keyboard::Key::Toolbox,
    Ion::Keyboard::Key::Shift,
};

void getKeyStates(__uint8_t *buf, __uint8_t len)
{

    Ion::Keyboard::State state = Ion::Keyboard::scan();
    __uint8_t returnState[sizeof(keysToCheck)];

    for (int i = 0; i < sizeof(keysToCheck); i++)
    {
        returnState[i] = state.keyDown(keysToCheck[i]) ? 1 : 0;
    }

    memcpy(buf, returnState, len);
}

void sleep(__uint32_t amount)
{
    Ion::Timing::msleep(amount);
}

__uint32_t millis()
{
    return Ion::Timing::millis();
}

void pushRect(int width, int height, __uint32_t *screenBuffer)
{
    
    // this is kinda dumb and inefficient. Better would be like this:
    // Ion::Display::pushRect(KDRect(0, 0 + 20, width, height), (KDColor*)screenBuffer);
    // but the values in the buffer are rgba8888 and we would need to convert them
    // to rgb565 before which is also needed for memory efficiency
    // because the framebuffer is way to big for the calc
    
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            char *rgba = (char *)&(screenBuffer[x + width * y]);

            KDColor color = KDColor::RGB888(*(rgba + 2), *(rgba + 1), *rgba);
            Ion::Display::pushRectUniform(KDRect(x, y + 20, 1, 1), color);
        }
    }

    uint64_t keys = Ion::Keyboard::scan();
}
