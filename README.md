# Osiris

Osiris is a graphical toolkit for X11-based Linux and Unix platforms.

[[_TOC_]]

## About

Osiris is a fork of the Qt toolkit, from version 2.3.2. Osiris is largely source compatible (but not binary compatible) with Qt 2.3.2 (with the exception of some naming conventions potentially changing). This means that you can compile legacy applications built originally for Qt2 using Osiris. In addition, porting from Qt1 takes very little work.

Osiris was previously part of ZFreeKit.

#### But why not use modern Qt?

If you're writing an application from scratch, the general answer is you should use Qt 6. It's a quality product, and the documentation is second to none.

But if your application was originally written for Qt versions 1 or 2, then Osiris is the answer. It's pretty straightforward to revive an old program using Osiris. Technically, you could port to Qt6, but with the exception of some extremely simple applications, you'll likely save a lot of time simply porting to Osiris instead.

#### But why Osiris?

Osiris is based on Qt2, which is a much improved version from Qt1. It also is extremely lightweight and small by todays standards. It helps revive legacy programs for historical and nostalgic purposes, and where every bit of performance and size is important, Osiris delivers a standard set of tools to build GUIs without a bunch of extra features. It's simple, but complete, and stupidly fast and lean. Plus most of the codebase has **decades** of real-world use so it's for the most part tried and true.

## Disclaimer

Osiris is **not** in any way, form, or shape affiliated with or supported by Trolltech, Nokia, Digia, the Free KDE Foundation, or the Qt Company. Osiris is a fork of the Qt toolkit, originally developed by Trolltech. Osiris is the _upstream_ of Osiris, meaning that bug reports, patches, etc., should be directed here to the Osiris project _not_ to the Qt bug tracker (or other Qt services). Some references to Qt either remain because they have not been replaced, need to remain for credit/copyright purposes, or for other functional reasons.

Osiris is provided **WITHOUT** any warranty or guarantee of any kind, either express or implied. The Osiris project, Libranext Computer Systems, contributors, and copyright holders expressly disclaim any liability with the use of or distribution of this software.


## A note about security

Osiris is based on old software, originally released somewhere circa 2000. There may still be unknown security issues or bugs that have not been discovered yet. If you do find one, please submit a bug report and/or a fix merge request.

## Lifecycle and versioning

There isn't a set release schedule. Releases happen when ready.

A change in the versioning is starting as of 2.4.4. Previously, it was planned to stay in the 2.x series indefinitely. However, Osiris has had a number of changes towards allowing it to co-exist with modern Qt, and once the rest of those changes are finalized, there is no reason to stick with one major release.  As a result, Osiris will be following major.minor.point releases from 2.4.4 onwards.


| **Version** | **Release Date**   | **End-of-Life** | **Status** | **Release Type**   |
|-------------|--------------------|-----------------|------------|--------------------|
| 2.4.4       | November 29th, 2025  | N/A             | Stable   | Maintenance/Bugfix |
| 2.4.3       | January 14th, 2025 | November 29th, 2025  | Oldstable     | Security           |
| 2.5.0       | TBD                | N/A             | Testing    | Development        |

### Distribution Support

These are distributions that are tested with each release. Note that packages are not provided for all supported distributions and architectures due to developer time constraints.

| Distribution | Status    | Latest Stable Release | Notes | Packages |
|--------------|-----------|-----------------------|-------|----------|
| Debian 12    | Supported | 2.4.4                 |   Source only, but bug reports are still accepted    |  No |
| Debian 13    | Supported | 2.4.4                 |       | Yes  |
| Ubuntu 24.04 | Supported | 2.4.4                 |       |  Yes |

## About licensing

First off, I'm not a lawyer, and this is not legal advice. Should you have questions about licensing, please see the source file in question and/or contact a competent software licensing lawyer.

The QPL can be viewed by going to the COPYING folder in the source tree root.

### Licensing of source code
Since Osiris is based on Qt, it inherits the original licensing scheme. For Qt version 2.3.2, this means that most files are tri-licensed, these licenses being a commercial Qt license, the Q Public License (QPL), and the GNU General Public License, version 2 (GPLv2).

It's important to note that some files may be (or have been) replaced with new or different versions that are not tri-licensed. A notable example is modern `libpng` support, which is GPLv2 only.

### Licensing as-distributed

Osiris is distributed and modified under the terms of the GNU GPL version 2 (with the exception of some individual files that may be more permissively licensed). As of version 2.4.1 or newer, files and/or changes that are only available under GPLv2 are used (modern `libpng` support, for example), effectively preventing compilation of Osiris as we distribute it under any of the other licenses.

### Licensing of documentation

Specifically, the new Markdown documentation (`doc/md`) is MIT-licensed.

#### About using Osiris under a Qt commercial license

The Osiris project nor Libranext Computer Systems play any part in the commerical licensing of Qt. Please refer to your specific license and/or contract terms. We can not help you with that. The vanilla source code can be found here as the first commit of code, or the tag Qt2.3.2-vanilla. Later commits have introduced files and/or changes that are not available under a Qt commercial license. It is your responsibility to audit source code to ensure license compatability. We do not provide support or licensing for any Qt products, and are not affiliated with Qt in any way.

#### About using Osiris under the QPL

When Osiris was part of ZFreeKit, some effort was made to maintain a separate patchset to be QPL compliant. This is no longer the case as of 2.4.0. In order to compile Osiris under the QPL, you'd have to either use the ZFreeKit release (which lacks all of the fixes in later versions of Osiris), or audit all source code to remove GPLv2-only licensed files. There are no plans to provide a QPL-compliant patchset again, as this would require re-writing some portions of code to allow use under QPL.

#### About using Osiris under the SADLv2

A few small portions of code were previously licensed under SADLv2. This license has been deprecated and removed, and all code in Osiris covered by it has been relicensed to GPLv2. If you see a portion still listed as SADLv2, please submit a bug report so this can be fixed.

## System Requirements

Osiris requires a Linux system running a X Windows System. G++ and Clang++ are supported. Osiris will run on either 32-bit or 64-bit x86 systems, as well as many 64-bit ARM systems. Other processors have not been tested.

Osiris is extremely lean on a modern computer, takes very little time to compile, and is not resource intensive while running.

At a minimum, to run Osiris, you'll need a Pentium 133mhz or better CPU, 64mb of RAM, 10-100MB of disk space, an X11R7 compliant X Server, and XLib. To build Osiris, you'll probably want at least a Pentium II 233Mhz CPU and more than 64MB of RAM, although this isn't necessarily required. FreeType2, Zlib, libjpeg, XFT, XKB and probably some more libraries are required.

| Library | Minimum Supported Version | Recommended Version |
| --- | --- | --- |
| libpng | 1.6.39 | 1.6.40 |
| zlib | 1.2.13 | 1.3 |
| libglu | 9.0 | 9.0.2 |

#### A note about older libpng and zlib versions

Osiris has been ported to modern libpng. There was an API change some time ago, and Qt2 was never ported to it, probably because the change occurred after Qt2's lifecycle had ended. That being said, using the new libpng with a version of zlib that is too old will cause warnings about `libpng error: bad parameters to zlib`. Using a newer version of zlib at compile time will fix this error.

FWIW, libpng says it needs zlib 1.0.4 or later. However, even zlib 1.1.3 will cause errors. You **should** be using zlib 1.2.13 or later.

#### What about Unix ports?

A lot of ports to other platforms are inherited from the original Qt code. These should still work on 2000-era versions. They have not been tested. We plan to work on ensuring these ports still work on at least a limited subset of non-Linux platforms in the modern world, however, this work has not been completed yet. You are welcome to try building Osiris on other platforms and submit patches here to fix the ports as needed (or add new platform ports).

#### What about Wayland support?

Wayland support is planned for the 3.x series. There is no ETA currently. Applications ported to Osiris should work properly under XWayland however, and window managers/DEs will run in XWayland with some caveats. Patches/PRs are welcome.

You can run Osiris-based applications using XWayland without problems, and Osiris-based applications will generally work in a Wayback environment as well.

#### What about Python3 bindings?

**Development on Pysiris is currently stalled** as of November 2025 but will be picked up in a future release.

As of April 2024, work on Pysiris has begun, although no release date is available yet. So yes, Python bindings are on the way.

#### A note on clipboard functionality under X11

The clipboard is somewhat functional. Unfortunately, getting the clipboard right under X11 is very difficult. Some progress has been made on fixing corner cases, but unfortunately there are still situations where the clipboard does not fully work. This will get better as we move towards Wayland support. It's unlikely that much time will be spent fixing the clipboard under X11, but patches are welcome.

## Packages for Supported Distributions

Packages are now available for some distributions.

#### Ubuntu Instructions

Supported architectures: `amd64`

*Note:* While Osiris supports more architectures, due to developer time constraints, only `amd64` packages are provided as of Osiris 2.4.4. If you have use for a package for a different architecture, please file a bug report.

*Note on supported architectures:* The `arm64` port isn't as well tested as the others, due to not having a good ARM board on hand right now. Please file a bug report if you have any issues.

Supported releases: **noble**

To add the official Libranext Pub-Package repository for Ubuntu, run the following commands (substituting your distribution codename):

```
sudo echo 'deb https://debpkg.libranext.com/pub/ubuntu <your distribution here> main' > /etc/apt/sources.list.d/libranext-pub.list
wget https://debpkg.libranext.com/pub/ubuntu/pool/main/libranext-debpkg-keyring_2025_all.deb
sudo dpkg -i libranext-debpkg-keyring_2025_all.deb
sudo apt update
```

After adding the repository, run the following commands to install Osiris:

```
sudo apt install osiris originator osiris-dev-tools osiris-dev osiris-doc originator-doc
```

#### Debian Instructions

Supported architectures: **For Debian bookworm:** `amd64`, `i386`, `arm64` **For Debian trixie:** `amd64`

*Notes on supported architectures:* 
- The `i386` packages were built for Pentium II or higher machines. If you need support for Pentium machines, you should compile Osiris per the build instructions below.
- The `arm64` port isn't as well tested as the others, due to not having a good ARM board on hand right now. Please file a bug report if you have any issues.

Supported releases: 2.4.3: **bookworm** 2.4.4+: **trixie**

To add the official Libranext Pub-Package repository for Debian, run the following commands as root (substituting your distribution codename):

```
echo 'deb https://debpkg.libranext.com/pub/debian <your distribution here> main' > /etc/apt/sources.list.d/libranext-pub.list
wget https://debpkg.libranext.com/pub/debian/pool/main/libranext-debpkg-keyring_2025_all.deb
dpkg -i libranext-debpkg-keyring_2025_all.deb
apt update
```

After adding the repository, run the following commands to install Osiris:

```
apt install osiris originator osiris-dev-tools osiris-dev osiris-doc originator-doc
```

## Building and debugging

#### Building a release version on Linux platforms

We use the Meson build system.

**Notes for Ubuntu systems:** You will need to install the following packages to build Osiris: `libx11-dev gawk bison flex build-essential libjpeg62-dev libxext-dev libxft-dev libglu1-mesa-dev libxmu-dev meson libjpeg-dev`

**Notes for Debian 13:** Trixie has been released now, and 2.4.4 officially supports it.

Meson is now new enough to not require backports. Run the following command to install the required dependencies:
```
apt install xorg-dev libglu1-mesa-dev libjpeg-dev meson zlib1g-dev
```

**Notes for Debian 12:** Unfortunately, the `meson` package in Debian stable is too old. You will need to install Meson from Debian backports. Run the following commands as root:
```
echo "deb http://deb.debian.org/debian bookworm-backports main" >> /etc/apt/sources.list.d/backports.list
apt update
apt install meson/bookworm-backports
apt install xorg-dev libglu1-mesa-dev libjpeg-dev
```


**Notes for Fedora 40 and up:** To get the build dependencies, run the following commands:
```
sudo dnf install xorg-x11-drv-libinput xorg-x11-server-common xorg-x11-server-Xorg

sudo dnf group install "C Development Tools and Libraries" "Development Tools" "X Software Development"

sudo dnf install meson mesa-libGLU-devel
```

The default behavior is to install Osiris to `/opt`. Examples and tutorials are built, but are installed to the source working directory. It is not currently recommended to install Osiris to any other directory.

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


**New for 2.4.3:** ldconfig and PATH are now configured automatically! A script is run during the installation step that generates and installs two files:

- `/etc/ld.so.conf.d/osiris`
- `/etc/profile.d/osiris.sh`

The first one tells the library loader where the Osiris libraries are installed. The second one adds the installation location of Osiris to the environment variable `PATH`, so applications can find Osiris tools. All you need to do is either run `ldconfig` as root, logging out of all sessions, and logging back in again (or simply rebooting).

#### Debugging

Meson builds with debugging turned on by default. If you're compiling Osiris and don't need debugging support, or are packaging for a distribution, you can run Meson setup with `--buildtype=release` (best for daily use) or `--buildtype=plain` (better for distribution packaging)

## Credits

Credits to the following are due because they have either contributed directly to Osiris, or their fixes were imported.

- Martin Tobias Holmedahl Sandsmark
- Robert McIsaac
- Helio Chissini de Castro
- The Trinity Desktop Environment project
- Keith Chambers
- Alec Bloss

## Development

Osiris now enforces a code style similar to what is used for the Linux Kernel and git-scm. This is styled in `.clang-format`. A script `recurs_clang-format.sh` is provided and should be run prior to every commit. C++11 is also enforced at build time now.
