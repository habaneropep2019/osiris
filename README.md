# Osiris

Osiris is a graphical toolkit for X11-based Linux and Unix platforms.

[[_TOC_]]

## About

Osiris is actually a fork of the Qt toolkit, from version 2.3.2. Osiris should maintain source compatability with Qt 2.3.2 (with the exception of some naming conventions potentially changing). This means that you can compile legacy applications built originally for Qt2 using Osiris. In addition, porting from Qt1 takes very little work.

Osiris was previously part of ZFreeKit.

#### But why not use modern Qt?

Good question. If you're asking that, chances are that you SHOULD use modern Qt. Qt6 is a masterful toolkit. It's high-quality, robust, and the documentation is second to none. Osiris is not meant to be a competitor nor a replacement for modern Qt. 

Fun fact: If you've traversed the code, you'd be surprised to find that more code thatn you'd expect from legacy Qt versions is still present in modern versions. No need to fix what isn't broken.

#### But why Osiris?

Osiris is based on Qt2, which is a much improved version from Qt1. It also is extremely lightweight and small by todays standards. It helps revive legacy programs for historical and nostalgic purposes, and where every bit of performance and size is important, Osiris delivers a standard set of tools to build GUIs without a bunch of extra features. It's simple, but complete, and stupidly fast and lean. Plus most of the codebase has **decades** of real-world use so it's for the most part tried and true.

## Disclaimer

Osiris is **not** in any way, form, or shape affiliated with or supported by Trolltech, Nokia, Digia, the Free KDE Foundation, or the Qt Company. Osiris is a fork of the Qt toolkit, originally developed by Trolltech. Osiris is the _upstream_ of Osiris, meaning that bug reports, patches, etc., should be directed here to the Osiris project _not_ to the Qt bug tracker (or other Qt services). Some references to Qt either remain because they have not been replaced, need to remain for credit/copyright purposes, or for other functional reasons.

Osiris is provided **WITHOUT** any warranty or guarantee of any kind, either express or implied. The Osiris project, Libranext Computer Systems, contribtors, and copyright holders expressly disclaim any liability with the use of or distribution of this software.


## A note about security

Osiris is based on old software, released somewhere circa 2000. Currently, I'm going through and fixing some known issues and potential flaws. However, there's no guarantee that I'll catch all security flaws or bugs. Use with caution. Do not deploy in a production environment, and if you do, know that it is at your own risk. That being said, I tend to believe that by the time I make a stable release, the worst cases will have been fixed. It should be relatively stable, as it's based on an already tried and true codebase.

## About licensing

First off, I'm not a lawyer, and this is not legal advice. Should you have questions about licensing, please see the source file in question and/or contact a competent software licensing lawyer.

Since Osiris is based on Qt, it inherits the original licensing scheme. For Qt version 2.3.2, this means that most files are tri-licensed, these licenses being a commercial Qt license, the Q Public License (QPL), and the GNU General Public License, version 2 (GPLv2).

It's important to note that some files may be (or have been) replaced with new or different versions that are not tri-licensed.

#### Licensing of Osiris files

New files and functionality will be licensed under the GPLv2, the modified BSD license (3-clause BSD license), and/or the SADLv2. Backported features from newer versions of Qt will retain their respective licensing.

#### About the Q Public License

The QPL is an open-source free software license. However, it requires modifications to be distributed as patches, or some other separate format from the source code. When Osiris was part of ZFreeKit, I aimed to maintain QPL compatability in case some legacy program was QPL licensed. However, this makes it notoriously difficult to maintain the source base in a modern source version control system as it's not easy to follow changes without having to apply patches first and then go through the clobbered up or non-existent history. Osiris will not maintain a patchset. You can, however, generate one yourself if desired

#### About using Osiris under a Qt commercial license

The Osiris project nor Libranext Computer Systems play any part in the commerical licensing of Qt. Please refer to your specific license and/or contract terms. We can not help you with that. The vanilla source code can be found here as the first commit of code, or the tag Qt2.3.2-vanilla. Later commits may introduce files and/or changes that are not available under a Qt commercial license. It is your responsibility to audit source code to ensure license compatability. We do not provide support or licensing for any Qt products, and are not affiliated with Qt in any way.

## System Requirements

Osiris requires a Linux system running a X Windows System. The GNU autotools system and the standard set of GNU development tools are required to build (make, gcc, g++, byacc, flex, etc.). Osiris will run on either 32-bit or 64-bit x86 systems. Other processors have not been tested. Compiling using clang has not been tested and is not currently supported, but will be implemented for at least Linux platforms in the future.

Osiris is extremely lean on a modern computer, takes very little time to compile, and is not resource intensive while running.

At a minimum, to run Osiris, you'll need a Pentium 133mhz or better CPU, 64mb of RAM, 10-100MB of disk space, an X11 Window System of at least revision 7 (XFree86 4.0+ should also likely work but is untested). To build Osiris, you'll probably want at least a Pentium II 233Mhz CPU and more than 64MB of RAM, although this isn't necessarily required.

#### What about Unix ports?

A lot of ports to other platforms are inherited from the original Qt code. These should still work on 2000-era versions. They have not been tested. We plan to work on ensuring these ports still work on at least a limited subset of non-Linux platforms in the modern world, however, this work has not been completed yet. You are welcome to try building Osiris on other platforms and submit patches here to fix the ports as needed (or add new platform ports).

#### What about Wayland support?

Osiris does not have any clue about Wayland - it hadn't even been thought of when Qt2.3.2 was mainstream. Most applications using Osiris _should_ theoretically run on XWayland, although I've not tested it yet. It's possible that I'll add Wayland support to Osiris at some point. It's certainly on the to-do list, althought a bit lower for now. Again, patches and bug reports are absolutely welcome!

#### What about Python3 bindings?

None available _yet_, sorry! It's on the to-do list somewhere.