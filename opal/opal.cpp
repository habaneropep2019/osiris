/*
 * Project Name: Opal
 * Project Description: Osiris Platform Abstraction Layer
 * Project Copyright: (C) Copyright 2026 Alec Bloss
 * SPDX-License-Identifier: GPL-2.0-or-later OR BSD-3-Clause
 *
 * File name: opal.cpp
 * Author: Alec Bloss <abloss@libranext.com>
 * Description: Opal is the Osiris Platform Abstraction Layer.
*/

#include "opal.h"

int OpalVersion = 1;

namespace Opal
{
    int GetVersion()
    {
        return OpalVersion;
    }
}
