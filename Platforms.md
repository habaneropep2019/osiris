# Osiris supported platforms

The table below shows what features are tested and/or supported on various platforms. The configure script should correctly pick your platform most of the time.

| **Feature**        | **linux-g++** | **freebsd-g++** | **solaris-g++** | **illumos-g++** |
|--------------------|---------------|-----------------|-----------------|-----------------|
| **Debug builds**   | ✅             | 🕑              | 🕑              | 🔜 3️⃣          |
| **Thread support** | ✅             | 💤              | ❌               | ❌ 🔜 3️⃣        |
| **Modern libpng**  | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **Modern zlib**    | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **64-bit builds**  | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **Designer**       | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **libjpeg**        | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **Static builds**  | ✅             | 💤              | 💤              | 💤 🔜 3️⃣       |
| **Shared builds**  | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **Examples**       | ✅             | 🕑              | 🕑              | 🕑              |
| **X11 support**       | ✅             | 🕑              | 🕑              | 🕑              |
| **XWayland support**       | 🛠️             | 🕑              | 🕑              | 🕑              |
| **Wayland backend**       | 🔜 2️⃣          | 🚫              | 🚫              | 🚫              |
| **GGE backend**       | 🔜 3️⃣            | 🚫              | 🚫              | 🚫              |
| **OpenGL support**       | 🛠️             | 🕑              | 🕑              | 🕑              |


**Legend:**  
✅ Tested working  
🛠️ Tested, partially working or not all functionality was tested, but the most important functionality was working  
⚠️ Not implemented  
❌ Tested and not working  
🕑 Should be supported, but not tested  
🚫 No plans to implement, fix, or test  
💤 Currently not supported and/or tested, usually for a platform that files exist for but has not been tested  
🔜 Planned to test/implement/fix but either in progress or not done (usually with priority of 1️⃣, 2️⃣, or 3️⃣, one being highest priority).


# Qt 2.3.2 legacy information

Before you build the Qt library and example programs, you must run the
"configure" script to set the platform information and other build
settings.  You can use the -platform option to specify the operating
system and compiler you are using.

Supported platforms and compilers:

  aix-g++        hpux-cc        irix-o32       qnx-rtp-g++    unixware-g++
  aix-xlc        hpux-g++       linux-g++      sco-g++        unixware7-cc
  bsdi-g++       hpux-n64       linux-cxx      solaris-64     unixware7-g++
  dgux-g++       hpux-o64       netbsd-g++     solaris-cc
  freebsd-g++    irix-64        openbsd-g++    solaris-g++
  gnu-g++        irix-g++       osf1-cxx       sunos-g++
  hpux-acc	 irix-n32       osf1-g++       ultrix-g++

Limitations:

  ultrix-g++ does not support shared libraries, use static.
  qnx-rtp-g++ is experimental only. Expect some problems.

Compilation problems:

  Qt 2.x has problems compiling on some combinations of operating
  system versions and compiler versions.  Information about such
  problems will be posted on http://www.trolltech.com/platforms/ as we
  become aware of them.

Example:

  ./configure -platform irix-64 -shared -debug

Customization:

  You can create your own custom configuration by adding new files to
  the configs directory. The configuration solaris-cc-gcc is included
  as an example. It uses SunPRO CC as a C++ compiler and GNU gcc as a
  C compiler.

