# Osiris

Osiris is a graphical toolkit for X11-based Linux and Unix platforms.

[[_TOC_]]

## About

Osiris is actually a fork of the Qt toolkit, from version 2.3.2. Osiris is largely source compatible (but not binary compatible) with Qt 2.3.2 (with the exception of some naming conventions potentially changing). This means that you can compile legacy applications built originally for Qt2 using Osiris. In addition, porting from Qt1 takes very little work.

Osiris was previously part of ZFreeKit.

#### But why not use modern Qt?

Good question. If you're asking that, chances are that you SHOULD use modern Qt. Qt6 is a masterful toolkit. It's high-quality, robust, and the documentation is second to none. Osiris is not meant to be a competitor nor a replacement for modern Qt.

Fun fact: If you've traversed the code, you'd be surprised to find that more code than you'd expect from legacy Qt versions is still present in modern versions. No need to fix what isn't broken.

#### But why Osiris?

Osiris is based on Qt2, which is a much improved version from Qt1. It also is extremely lightweight and small by todays standards. It helps revive legacy programs for historical and nostalgic purposes, and where every bit of performance and size is important, Osiris delivers a standard set of tools to build GUIs without a bunch of extra features. It's simple, but complete, and stupidly fast and lean. Plus most of the codebase has **decades** of real-world use so it's for the most part tried and true.

## Disclaimer

Osiris is **not** in any way, form, or shape affiliated with or supported by Trolltech, Nokia, Digia, the Free KDE Foundation, or the Qt Company. Osiris is a fork of the Qt toolkit, originally developed by Trolltech. Osiris is the _upstream_ of Osiris, meaning that bug reports, patches, etc., should be directed here to the Osiris project _not_ to the Qt bug tracker (or other Qt services). Some references to Qt either remain because they have not been replaced, need to remain for credit/copyright purposes, or for other functional reasons.

Osiris is provided **WITHOUT** any warranty or guarantee of any kind, either express or implied. The Osiris project, Libranext Computer Systems, contributors, and copyright holders expressly disclaim any liability with the use of or distribution of this software.


## A note about security

Osiris is based on old software, released somewhere circa 2000. There may still be unknown security issues or bugs that have not been discovered yet. If you do find one, please submit a bug report and/or a fix merge request.

## About licensing

First off, I'm not a lawyer, and this is not legal advice. Should you have questions about licensing, please see the source file in question and/or contact a competent software licensing lawyer.

The QPL can be viewed by going to the COPYING folder in the source tree root.

### Licensing of source code
Since Osiris is based on Qt, it inherits the original licensing scheme. For Qt version 2.3.2, this means that most files are tri-licensed, these licenses being a commercial Qt license, the Q Public License (QPL), and the GNU General Public License, version 2 (GPLv2).

It's important to note that some files may be (or have been) replaced with new or different versions that are not tri-licensed. A notable example is modern `libpng` support, which is GPLv2 only.

### Licensing as-distributed

Osiris is distributed and modified under the terms of the GNU GPL version 2 (with the exception of some individual files that may be more permissively licensed). As of version 2.4.1 or newer, files and/or changes that are only available under GPLv2 are used (modern `libpng` support, for example), effectively preventing compilation of Osiris as we distribute it under any of the other licenses.

#### About using Osiris under a Qt commercial license

The Osiris project nor Libranext Computer Systems play any part in the commerical licensing of Qt. Please refer to your specific license and/or contract terms. We can not help you with that. The vanilla source code can be found here as the first commit of code, or the tag Qt2.3.2-vanilla. Later commits have introduced files and/or changes that are not available under a Qt commercial license. It is your responsibility to audit source code to ensure license compatability. We do not provide support or licensing for any Qt products, and are not affiliated with Qt in any way.

#### About using Osiris under the QPL

When Osiris was part of ZFreeKit, some effort was made to maintain a separate patchset to be QPL compliant. This is no longer the case as of 2.4.0. In order to compile Osiris under the QPL, you'd have to either use the ZFreeKit release (which lacks all of the fixes in later versions of Osiris), or audit all source code to remove GPLv2-only licensed files. There are no plans to provide a QPL-compliant patchset again, as this would require re-writing some portions of code to allow use under QPL.

#### About using Osiris under the SADLv2

A few small portions of code were previously licensed under SADLv2. This license has been deprecated and removed, and all code in Osiris covered by it has been relicensed to GPLv2. If you see a portion still listed as SADLv2, please submit a bug report so this can be fixed.

## System Requirements

Osiris requires a Linux system running a X Windows System. G++ and Clang++ are supported. Osiris will run on either 32-bit or 64-bit x86 systems, as well as many 64-bit ARM systems. Other processors have not been tested.

Osiris is extremely lean on a modern computer, takes very little time to compile, and is not resource intensive while running.

At a minimum, to run Osiris, you'll need a Pentium 133mhz or better CPU, 64mb of RAM, 10-100MB of disk space, an X11 Window System of at least revision 7 (XFree86 4.0+ should also likely work but is untested). To build Osiris, you'll probably want at least a Pentium II 233Mhz CPU and more than 64MB of RAM, although this isn't necessarily required. FreeType2, Zlib, libjpeg, XFT, XKB and probably some more libraries are required.

| Library | Minimum Supported Version | Recommended Version |
| --- | --- | --- |
| libpng | 1.6.0 | 1.6.40 |
| zlib | 1.2.13 | 1.2.13 |
| libglu | 9.0 | 9.0.2 |

#### A note about older libpng and zlib versions

Osiris has been ported to modern libpng. There was an API change some time ago, and Qt2 was never ported to it, probably because the change occurred after Qt2's lifecycle had ended. That being said, using the new libpng with a version of zlib that is too old will cause warnings about `libpng error: bad parameters to zlib`. Using a newer version of zlib at compile time will fix this error.

FWIW, libpng says it needs zlib 1.0.4 or later. However, even zlib 1.1.3 will cause errors. You **should** be using zlib 1.2.13 or later.

#### A note about formerly included 3rd party libraries

Qt2 originally kept copies of 3rd party libraries libpng and zlib. Osiris no longer does, as this can result in terribly out of date versions of these libraries, or other issues arising from mismatches. You should be able to use the libraries provided by your distribution.

#### What about Unix ports?

A lot of ports to other platforms are inherited from the original Qt code. These should still work on 2000-era versions. They have not been tested. We plan to work on ensuring these ports still work on at least a limited subset of non-Linux platforms in the modern world, however, this work has not been completed yet. You are welcome to try building Osiris on other platforms and submit patches here to fix the ports as needed (or add new platform ports).

#### What about Wayland support?

Wayland support is planned, eventually. There is no ETA however. Applications ported to Osiris should work properly under XWayland however, with the exception being window managers. Patches/PRs are welcome.

You can run Osiris using XWayland without problems.

#### What about Python3 bindings?

~~None available *yet*, sorry! It's on the to-do list somewhere.~~

As of April 2024, work on Pysiris has begun, although no release date is available yet. So yes, Python bindings are on the way.

#### A note on clipboard functionality under X11

Getting the clipboard implemented correctly under X11 is ridiculously complicated. Osiris has some partial fixes to improve X11 clipboard functionality over Qt2.3.2, but it's still not perfect. For now, clipboard functionality is still on the to-do list, although it's not top priority unless we get a lot of users needing it for their applications. The reason being that the clipboard will be re-implemented when Wayland support happens, so it's not currently worth spending a lot of time on.

## Building and debugging

#### Building a release version on Linux platforms

**New for 2.4.2:** The build system has changed to Meson, so it's even easier to compile and install Osiris.

**Notes for Ubuntu systems:** You will need to install the following packages to build Osiris: `libx11-dev gawk bison flex build-essential libjpeg62-dev libxext-dev libxft-dev libglu1-mesa-dev libxmu-dev`

The default behavior is to install Osiris to `/opt`. Examples and tutorials are built, but are installed to the source working directory. It is not currently recommended to install Osiris to `/usr`.

To build Osiris, checkout or download a release, and from the source directory run:

```
meson setup build
cd build
ninja
sudo ninja install
```

Alternatively, you can build with Clang:

```
CC=clang CXX=clang++ meson setup build
cd build
ninja
sudo ninja install
```


Then, you need to set up the environment. Usually adding the following to your `.profile`, logging out, and logging back in again is sufficient. This should be done for both root _and_ any local users who will be using Osiris.

```
PATH="$PATH:$OSIRISDIR/bin"
MANPATH="$MANPATH:$OSIRISDIR/doc/man"
LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$OSIRISDIR/lib"
export OSIRISDIR PATH MANPATH LD_LIBRARY_PATH
```

You should also make `ldconfig` aware of Osiris libraries:

```
sudo echo "/opt/osiris/lib" > /etc/ld.so.conf.d/osiris.conf
sudo ldconfig -v
```

#### Debugging

Meson builds with debugging turned on by default. If you're compiling Osiris and don't need debugging support, or are packaging for a distribution, you can run Meson setup with `--buildtype=release` (best for daily use) or `--buildtype=plain` (better for distribution packaging)

## Credits

Credits to the following are due because they have either contributed directly to Osiris, or their fixes were imported.

- Martin Tobias Holmedahl Sandsmark
- Robert McIsaac
- Helio Chissini de Castro
- The Trinity Desktop Environment project
- Keith Chambers