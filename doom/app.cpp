#include "app.h"
#include "doom_icon.h"
#include <apps/i18n.h>
#include <apps/apps_container.h>
extern "C"{
  #include "apps/doom/engine/i_main.h"
}




namespace Doom {

I18n::Message App::Descriptor::name() {
  return I18n::Message::DoomApp;
}

I18n::Message App::Descriptor::upperName() {
  return I18n::Message::DoomAppCapital;
}

const Image * App::Descriptor::icon() {
  return ImageStore::DoomIcon;
}

App * App::Snapshot::unpack(Container * container) {
  return new (container->currentAppBuffer()) App(container, this);
}

void App::Snapshot::reset() {
}

App::Descriptor * App::Snapshot::descriptor() {
  static Descriptor descriptor;
  return &descriptor;
}

void App::didBecomeActive(Window * window) {
  ::App::didBecomeActive(window);
  Ion::Display::pushRectUniform(KDRect(0, 0, 320, 240), KDColorBlack);
  
  char *args[] = {"doom"};
  DoomMain(1, args);
}

void App::willBecomeInactive() {
  ::App::willBecomeInactive();
  
}

App::App(Container * container, Snapshot * snapshot) :
  ::App(snapshot, &m_doomController),
  m_appsContainer((AppsContainer*) container)
{
}

}
