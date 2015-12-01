/*

  Nullsoft WASABI Source File License

  Copyright 1999-2001 Nullsoft, Inc.

    This software is provided 'as-is', without any express or implied
    warranty.  In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.


  Brennan Underwood
  brennan@nullsoft.com

*/

#ifndef _CONTWND_H // Generic container window
#define _CONTWND_H

#include "common.h"
#include "basewnd.h"
#include "labelwnd.h"
#include "tlist.h"

#define CONTWND_PARENT LabelWnd

class ChildSlot {
public:
  friend class ContWnd;
  ChildSlot(BaseWnd *_child, RECT &_pos, int inval) {
    child = _child;
    pos = _pos;
    invalidate_on_resize = inval;
  }
  ~ChildSlot() {
    delete child;
  }

protected:
  RECT pos;
  BOOL invalidate_on_resize;
  BaseWnd *child;
};

class COMEXP ContWnd : public LabelWnd {
public:
  virtual ~ContWnd();

  virtual int onInit();
  virtual int onPaint(Canvas *canvas);
  virtual int onResize();
  
  int addChild(BaseWnd *child, int x, int y, int w, int h, int invalidate_on_resize=0);

private:
  PtrList<ChildSlot> children;
};

#endif