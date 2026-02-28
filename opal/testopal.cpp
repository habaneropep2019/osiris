/*
 * Project Name: Opal
 * Project Description: Osiris Platform Abstraction Layer
 * Project Copyright: (C) Copyright 2026 Alec Bloss
 * SPDX-License-Identifier: GPL-2.0-or-later OR BSD-3-Clause
 *
 * File name: testopal.cpp
 * Author: Alec Bloss <abloss@libranext.com>
 * Description: Test file for opal functionality.
 */

#include "opal.h"
#include "opalws.h"
#include <cstdio>
#include <string>
#include <iostream>

int main()
{
    int opalver = Opal::GetVersion();
    printf("Opal version is: %d \n", opalver);

    std::string opalws = Opal::GetSessionType();
    std::cout << "Opal session type is: " << opalws << std::endl;

    return 0;

}
