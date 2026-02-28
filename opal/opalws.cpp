/*
 * Project Name: Opal
 * Project Description: Osiris Platform Abstraction Layer
 * Project Copyright: (C) Copyright 2026 Alec Bloss
 * SPDX-License-Identifier: GPL-2.0-or-later OR BSD-3-Clause
 *
 * File name: opalws.cpp
 * Author: Alec Bloss <abloss@libranext.com>
 * Description: Opal Windowing System related functionality
 */

// Replaces _WS_X11_ macro. Sort of a dummy function right now because
// it doesn't do much other than always say it's under X11.

#include <string>
#include "opalws.h"

namespace Opal
{
    std::string WS = "X11";

    std::string GetSessionType()
    {
        return WS;
    }
}
