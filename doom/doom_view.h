#ifndef APPS_DOOM_VIEW_H
#define APPS_DOOM_VIEW_H

#include <escher.h>

namespace Doom {

class DoomView : public View {
public:
  DoomView();
  void drawRect(KDContext * ctx, KDRect rect) const override;
};

}

#endif
