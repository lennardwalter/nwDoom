#ifndef APPS_DOOM_CONTROLLER_H
#define APPS_DOOM_CONTROLLER_H

#include <escher.h>
#include "doom_view.h"

namespace Doom {

class DoomController : public ViewController {
public:
  DoomController();
  View * view() override;
private:
  DoomView m_doomView;
};

}

#endif
