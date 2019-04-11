## Welcome to the Oberon-07 C++ parser and code model/browser/generator

This is an Oberon-07 parser, code model and generator written in C++ and Qt. See http://www.projectoberon.net/wirth/Oberon/Oberon07.Report.pdf for more information about the language. The syntax was modified for Coco/R compatibility using https://github.com/rochus-keller/EbnfStudio. 

The goal of this project is to build tools to better understand the Lola-2 compiler and to automatically translate it to maintainable C++ with minimal dependencies to other C++ libraries and with no dependencies to the Oberon System. The C++ based Lola-2 compiler will be integrated in https://github.com/rochus-keller/LolaCreator.

### Parser and code model features

- Implements Oberon-07; successfully reads the Oberon System including the applications (see http://www.projectoberon.com/) and the Lola-2 compiler (see https://www.inf.ethz.ch/personal/wirth/Lola) source code (the syntax errors in Graphics.Mod line 670 and Net.Mod line 190 have to be fixed though)
- Syntax and semantics validation, error reporting
- Infers and synthesizes missing modules

### C++ Code generator features

- Generates C++03 compatible code with no other dependencies than the standard libraries
- Generates stub headers for the synthesized (missing) modules to ease implementing the missing parts
- Arrays including strings are implemented by C++ template classes
- Modules are dynamically created to maintain the correct initialization dependencies
- Comments of the original files are also translated
- Oberon idents conflicting with C++ keywords are postfixed by underscore
- The generated code is well readable and maintainable
- Currently only the subset of Oberon-07 used by the Lola-2 compiler is supported; see https://github.com/rochus-keller/Lolac for an example of the generated code
- There is no garbage collector code generated yet, but an arena based collector can easily be implemented outside of the generator by customizing the _Root class; future versions will generate a regular mark & sweep collector.

### Code browser features

- Syntax highlighting
- Code navigation; jump to the declaration of an ident
- Mark all idents refering to the same declaration
- List all uses of a declaration for easy navigation
- Browsing history, forward and backward navigation


![OberonViewer Screenshot](http://software.rochus-keller.info/oberonviewer_screenshot_1.png)


### Binary version

Here is a binary version of OberonViewer for Windows: http://software.rochus-keller.info/OberonViewer_win32.zip
Just download, unpack and run it; no installer is needed. The ZIP includes the needed Qt libraries.

### Build Steps

Follow these steps if you want to build OberonViewer yourself:

1. Make sure a Qt 5.x (libraries and headers) version compatible with your C++ compiler is installed on your system.
1. Download the Oberon source code from https://github.com/rochus-keller/Oberon/archive/master.zip and unpack it.
1. Goto the unpacked directory and execute `QTDIR/bin/qmake OberonViewer.pro` (see the Qt documentation concerning QTDIR).
1. Run make; after a couple of seconds you will find the executable in the build directory.

Alternatively you can open OberonViewer.pro using QtCreator and build it there.

The library makes use of a parser generated by Coco/R based on input from EbnfStudio. There is no other dependency than the Qt Core library.
The repository already contains the generated files. In order to regenerate ObParser.cpp/h you have to use this version of Coco/R: https://github.com/rochus-keller/Coco

## Support
If you need support or would like to post issues or feature requests please use the Github issue list at https://github.com/rochus-keller/Oberon/issues or send an email to the author.



