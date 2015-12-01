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

#ifndef _WNDCB_H
#define _WNDCB_H

#include "../studio/syscb.h"

namespace WndCallback {
  enum {
    SHOWWINDOW=10,
    HIDEWINDOW=20,
  };
};

#define WNDCALLBACKI_PARENT SysCallbackI
class COMEXP WndCallbackI : public WNDCALLBACKI_PARENT {
public:
  virtual int syscb_getEventType() { return SysCallback::WINDOW; }

protected:
  virtual int onShowWindow(GUID g) { return 0; }
  virtual int onHideWindow(GUID g) { return 0; }

private:
  virtual int syscb_notify(int msg, int param1=0, int param2=0);

};

#endif
