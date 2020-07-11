#include "doom_view.h"
#include <assert.h>


namespace Doom {

DoomView::DoomView() :
  View()
{
}



void DoomView::drawRect(KDContext * ctx, KDRect rect) const {
  ctx->fillRect(bounds(), KDColorBlack);
}
}