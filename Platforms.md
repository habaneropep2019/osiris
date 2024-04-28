# Osiris supported platforms

The table below shows what features are tested and/or supported on various platforms.

| **Feature**        | **linux** | **freebsd** | **solaris** | **illumos** |
|--------------------|---------------|-----------------|-----------------|-----------------|
| **Debug builds**   | ✅             | 🕑              | 🕑              | 🔜 3️⃣          |
| **Thread support** | ✅             | 💤              | ❌               | ❌ 🔜 3️⃣        |
| **Modern libpng**  | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **Modern zlib**    | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **64-bit builds**  | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **arm64 support**  | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **Clang++ support**| ✅             | ⚠️              | ⚠️              | ⚠️             |
| **G++ support**    | ✅             | 🕑              | 🕑              | 🕑             |
| **Designer**       | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **libjpeg**        | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **Static builds**  | ✅             | 💤              | 💤              | 💤 🔜 3️⃣       |
| **Shared builds**  | ✅             | 🕑              | 🕑              | 🕑 🔜 3️⃣       |
| **Examples**       | ✅             | 🕑              | 🕑              | 🕑              |
| **X11 support**       | ✅             | 🕑              | 🕑              | 🕑              |
| **XWayland support**       | ✅             | 🕑              | 🕑              | 🕑              |
| **Wayland backend**       | 🔜 2️⃣          | 🚫              | 🚫              | 🚫              |
| **OpenGL support**       | ✅             | 🕑              | 🕑              | 🕑              |


**Legend:**  
✅ Tested working  
🛠️ Tested, partially working or not all functionality was tested, but the most important functionality was working  
⚠️ Not implemented  
❌ Tested and not working  
🕑 Should be supported, but not tested  
🚫 No plans to implement, fix, or test  
💤 Currently not supported and/or tested, usually for a platform that files exist for but has not been tested  
🔜 Planned to test/implement/fix but either in progress or not done (usually with priority of 1️⃣, 2️⃣, or 3️⃣, one being highest priority).
