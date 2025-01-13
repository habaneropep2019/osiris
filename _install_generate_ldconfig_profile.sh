#!/bin/bash

# (C) Copyright 2024 Alec Bloss. Licensed under the GNU GPL version 2.0.

# SPDX-License-Identifier: GPL-2.0

# This script generates the necessary ldconfig and profile files to set
# the $PATH and inform the shared library loader where the libraries are.
# This will eventually be unnecessary once Osiris installs into a default
# prefix that is normal for distributions, aka, not /opt. For now this
# makes it work.

set -e # Exit if a command fails

# Well the build system won't create directories necessarily. So check if
# directory exists, and if not, create it

if [ ! -d "${DESTDIR}/etc/ld.so.conf.d" ]
then
    mkdir -p "${DESTDIR}/etc/ld.so.conf.d"
fi

if [ ! -d "${DESTDIR}/etc/profile.d" ]
then
    mkdir -p "${DESTDIR}/etc/profile.d"
fi

# Generate the ldconfig file

echo "${MESON_INSTALL_PREFIX}/lib" > "${DESTDIR}/etc/ld.so.conf.d/osiris.conf"

# Generate the profile file

echo '#!/bin/bash' > "${DESTDIR}/etc/profile.d/osiris.sh"
echo "${MESON_INSTALL_PREFIX}/bin" >> "${DESTDIR}/etc/profile.d/osiris.sh"
chmod +x "${DESTDIR}/etc/profile.d/osiris.sh"

