#include "doom_controller.h"
#include <apps/apps_container.h>

namespace Doom {

DoomController::DoomController() :
  ViewController(nullptr),
  m_doomView()
{
}

View * DoomController::view() {
  return &m_doomView;
}

}
