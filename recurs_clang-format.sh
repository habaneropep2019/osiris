#!/bin/bash

# (C) Copyright 2024 Alec Bloss. Licensed under the GNU GPL version 2.0.

# SPDX-License-Identifier: GPL-2.0

cpps="$(find . -type f -name "*.cpp")"
hs="$(find . -type f -name "*.h")"

for cppsrc in $cpps
do
	clang-format -style=file:'./.clang-format' -i "$cppsrc"
done;

for hsrc in $hs
do
	clang-format -style=file:'./.clang-format' -i "$hsrc"
done;

exit 0
