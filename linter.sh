#!/bin/bash

# (C) Copyright 2024 Alec Bloss. Licensed under the GNU GPL version 2.0.

# SPDX-License-Identifier: GPL-2.0

# This is a simple script to do some checks for the codebase.

echo 'WARNING: Unimplemented: Check all files for copyright'

# Check for licensing identifiers in source code
#  Currently: cpp, c, h, sh

echo 'INFO: Checking for License Identifiers...'

identifierCheck ()
{
	SPDX="$(cat "$1" | grep SPDX-License-Identifier)"
	ALTID="$(cat "$1" | grep Alternative-License-Identifier)"
	
	if [ -z "$SPDX" ] && [ -z "$ALTID" ]
	then
		echo "FAIL: Missing SPDX and/or ALTID License Identifier in file $1"
	else
		if [ -n "$SPDX" ]
		then
			echo "PASS: File $1 contains license identifier $SPDX"
		fi
		if [ -n "$ALTID" ]
		then
			echo "PASS: File $1 contains license identifier $ALTID"
		fi
	fi
}

cpps="$(find . -type f -name "*.cpp")"
hs="$(find . -type f -name "*.h")"
shs="$(find . -type f -name "*.sh" | grep -v linter.sh)"
cs="$(find . -type f -name "*.c")"

for file in $cpps
do
	identifierCheck "$file"
done;

for file in $hs
do
	identifierCheck "$file"
done;

for file in $shs
do
	identifierCheck "$file"
done;

for file in $cs
do
	identifierCheck "$file"
done;

# Run clang-format on the project

echo "INFO: Running clang-format on project..."

bash recurs_clang-format.sh;

exit 0