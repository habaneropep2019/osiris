#!/bin/bash

# (C) Copyright 2024 Alec Bloss. Licensed under the GNU GPL version 2.0.

# SPDX-License-Identifier: GPL-2.0

# This script generates the necessary ldconfig and profile files to set
# the $PATH and inform the shared library loader where the libraries are.
# This will eventually be unnecessary once Osiris installs into a default
# prefix that is normal for distributions, aka, not /opt. For now this
# makes it work.

set -e # Exit if a command fails

# Generate the ldconfig file

echo "${MESON_INSTALL_PREFIX}/lib" > ${DESTDIR}/etc/ld.so.conf.d/osiris.conf

# Generate the profile file

echo '#!/bin/bash' > ${DESTDIR}/etc/profile.d/osiris.sh
echo "${MESON_INSTALL_PREFIX}/bin" >> ${DESTDIR}/etc/profile.d/osiris.sh
chmod +x ${DESTDIR}/etc/profile.d/osiris.sh

