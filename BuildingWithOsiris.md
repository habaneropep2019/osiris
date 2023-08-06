# Building applications using Osiris

This is far from a complete guide. Most of the HTML documentation bundled originally with Qt 2.3.2 is still relevant and correct.

I'm hoping to save others a little frustration from some seemingly omitted information in the HTML docs. They appear to assume you're using tmake, and Osiris does not bundle tmake, or have plans to.

## A note about Designer 1.1

Osiris includes Designer 1.1, which was the first generation of the Designer tool. It is not an IDE. Some later versions of Designer helped facilitate more of the building/writing process. The version of Designer included with Osiris only helps you design the interface, and isn't aware of C/C++ code. It outputs a `.ui` file, which is an XML description of the UI you just designed in Designer.

## Using UI files

Once you've generated and saved your .ui file, you need to generate a header file from the UI file.

`uic -o wizard.h wizard.ui` - Make sure to replace values as needed. `-o` specifies the name of the header file to output, otherwise it just spits it out on STDOUT.

After the header file, we need to generate the implementation.

`uic -o wizard.cpp -impl wizard.h wizard.ui` - Again, replace values as needed.

When using UI files, you'll need to manually make your `main.cpp`. The included examples are a good place to start, specifically the `tools/designer/examples/walkthrough/main.cpp` file. It can often be used with very little modification, at least when just getting the dialog working.