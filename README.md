# Osiris

Osiris is a graphical toolkit for X11-based Linux and Unix platforms.

[[_TOC_]]

## About

Osiris is a fork of the Qt toolkit, from version 2.3.2. Osiris is largely source compatible (but not binary compatible) with Qt 2.3.2 (with the exception of some naming conventions potentially changing). This means that you can compile legacy applications built originally for Qt2 using Osiris. In addition, porting from Qt1 takes very little work.

Osiris was previously part of ZFreeKit.

## The frontpage changed!!

Yes, with the way development is handled, the `main` branch doesn't serve much purpose other than being the default frontpage users see.

So, the README for `main` can now be frequently updated.

## Why Osiris?

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
| 2.4.5       | September 5th, 2026  | TBD        | Stable   | Security/Bugfix |
| 2.4.4       | November 29th, 2025  | Septemper 5th, 2026             | Oldstable   | Maintenance/Bugfix |
| 2.4.3       | January 14th, 2025 | November 29th, 2025  | Unsupported     | Security           |
| 2.5.0       | TBD                | N/A             | Testing    | Development        |

### Distribution Support

These are distributions that are tested with each release. Note that packages are not provided for all supported distributions and architectures due to developer time constraints.

| Distribution | Status    | Latest Stable Release | Notes | Packages |
|--------------|-----------|-----------------------|-------|----------|
| Debian 12    | Supported | 2.4.4                 |   Source only, but bug reports are still accepted    |  No |
| Debian 13    | Supported | 2.4.5                 |       | Yes  |
| Ubuntu 24.04 | Supported | 2.4.4                 |       |  Yes |


### Architecture Support

Osiris is supported on arm64, amd64, and i386 for source builds. Other architectures may work, but have not been tested.

For packages, arm64 is supported on both Debian and Ubuntu. arm64 packages are temporarily unable to be built due to limited availablity of arm64 nodes (as of 09-25-2026)

### Packages for Debian

First, grab the package signing key and add the repository (note that this may need to be done as root or using `sudo`):

```
wget https://pkg.midesk.top/debian/pool/stable/m/midesktop-archive-keyring/midesktop-archive-keyring_1.0.0-1_all.deb

dpkg -i midesktop-archive-keyring_1.0.0-1_all.deb

echo 'deb [signed-by=/usr/share/keyrings/midesktop.pgp] https://pkg.midesk.top/debian trixie stable' > /etc/apt/sources.list.d/midesktop.list

apt update
```

**Note:** You can replace `trixie` with your Debian release: e.g., `bookworm`. You can choose from three variants: `stable`, `testing`, and `nightly`. For most users, `stable` is recommended. If you want to test beta/RC releases, you can use `testing`. And lastly, if you want to test the latest updates as they are released during development, you can use `nightly` (though, releases are not necessarily released every night!).

Then, install Osiris:

```
apt install osiris osiris-doc originator`
```

If you plan to do development with Osiris, you may also want the development and debugging packages:

```
apt install originator-dbgsym osiris-dev-tools osiris-dev osiris-dbgsym osiris-dev-tools-dbgsym
```

It's recommended to reboot after installation.

### Packages for Ubuntu

First, grab the package signing key and add the repository (note that this may need to be done as root or using `sudo`):

```
wget https://pkg.midesk.top/ubuntu/pool/stable/m/midesktop-archive-keyring/midesktop-archive-keyring_1.0.0-1_all.deb

dpkg -i midesktop-archive-keyring_1.0.0-1_all.deb

echo 'deb [signed-by=/usr/share/keyrings/midesktop.pgp] https://pkg.midesk.top/ubuntu noble stable' > /etc/apt/sources.list.d/midesktop.list

apt update
```

**Note:** Currently, only `noble` is supported, although the packages may work on newer releases. You can choose from three variants: `stable`, `testing`, and `nightly`. For most users, `stable` is recommended. If you want to test beta/RC releases, you can use `testing`. And lastly, if you want to test the latest updates as they are released during development, you can use `nightly` (though, releases are not necessarily released every night!).

Then, install Osiris:

```
apt install osiris osiris-doc originator`
```

If you plan to do development with Osiris, you may also want the development and debugging packages:

```
apt install originator-dbgsym osiris-dev-tools osiris-dev osiris-dbgsym osiris-dev-tools-dbgsym
```

It's recommended to reboot after installation.

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


