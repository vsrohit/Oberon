## Welcome to the Oberon+ parser, code model, compiler and IDE

This project started out as an [Oberon-07](http://www.projectoberon.net/wirth/Oberon/Oberon07.Report.pdf) parser, code model and transpiler written in C++ and Qt, with the goal to build tools to better understand the [Lola-2](https://www.inf.ethz.ch/personal/wirth/Lola/Lola2.pdf) compiler and to automatically translate it to maintainable C++ with minimal dependencies to other C++ libraries, and with no dependencies to the Oberon System (see the [Lola](https://github.com/rochus-keller/lola) and [LolaCreator](https://github.com/rochus-keller/lolacreator) repositories).

Oberon turned out to be a language very well suited for compiler front and backend experiments because it is decently simple but still powerful enough to build real-world software, as it supports pointers, static and stack based data structures and call by reference, which are not usually available with scripting languages. In consequence, an other goal of this project is to study the feasibility of reusing [LuaJIT](http://luajit.org/) as a backend for statically typed programming languages like Oberon (see [this article](https://medium.com/@rochus.keller/implementing-call-by-reference-and-call-by-name-in-lua-47b9d1003cc2)). The current implementation of the compiler is able to map full Oberon+ to LuaJIT bytecode and run with decent performance (see [this report](https://github.com/rochus-keller/Oberon/blob/master/testcases/Are-we-fast-yet/Are-we-fast-yet_results.pdf)) on LuaJIT. There is also a [compatible version of the Oberon System](https://github.com/rochus-keller/OberonSystem), as well as a powerful IDE with semantic navigation and source-level debugging (see below).

During my work with Oberon and systems implemented in Oberon, I kept asking myself what properties the language would need to have so that I could use it for my own systems too, without giving up the goal of making it as simple as possible. From these considerations a new language emerged, which I call **Oberon+** (i.e. "Oberon with extensions", abbreviated OBX); it is a general-purpose, procedural and object-oriented programming language in the tradition of and based on Oberon-07, Oberon-2 and Oberon 90, with all the elements of these languages, plus generic modules, enumerations, and many additional simplifications such as support for lower case keywords, optional semicolons, and flexible declaration sequences. See [the language report](documentation/The_Programming_Language_Oberon+.adoc) for more information. The compiler supports both, Oberon+ as well as most of the syntax and semantics of the previous Oberon versions.

For representative examples of Oberon+ see the [Are-we-fast-yet benchmark suite migrated to Oberon+](https://github.com/rochus-keller/Oberon/tree/master/testcases/Are-we-fast-yet). It also demonstrates generic programming with collections and iterators.

### What this repository includes

- The old Oberon-07 validating parser with code model, Lua source code transpiler, C++ transpiler and LuaJIT bytecode compiler (file prefix Ob)
- The old OberonViewer, Oberon-07 IDE and OBNLC command line version of the compiler/transpiler
- The Oberon+ programming language specification
- The new Oberon+ validating parser, code model and LuaJIT bytecode compiler (file prefix Obx)
- The new Oberon+ IDE and OBXLJ command line version of the compiler

### Planned or work-in-progress features

- [x] Oberon+ validating parser
- [x] IDE with semantic navigation & source-level debugger
- [x] LuaJIT compiler backend
- [ ] Complete built-in procedure and Oakwood library implementations
- [ ] Write documentation and focus articles
- [ ] Implement a DotNet CIL compiler backend (started)
- [ ] Use a minimal Mono runtime as an alternative to the LuaJIT VM
- [ ] Implement an LLVM compiler backend
- [ ] Proceed with the programming language development (based on actual need and after careful consideration)

### The Oberon+ IDE

This is a lean IDE with the following features:

- Syntax highlighting
- Semantic code navigation; jump to the declaration of an ident (CTRL+click on the ident)
- Mark all idents refering to the same declaration
- Cross-reference view: list all instances of an identifier for easy navigation
- Module view: shows the records declared in the module and their bound procedures together
- Hierarchy view: shows the inheritance relation of a selected record or the overrides of a selected bound procedure
- Browsing history, forward and backward navigation
- Project files combine modules into a single project and associate them with virtual import paths
- Built-in LuaJIT engine
- Bytecode view (LuaJIT assembler syntax), synchronized to source
- Integrated source level debugger with breakpoints, stack trace and locals view
- Built-in optional Oakwood or Oberon System backend library

![Oberon+ IDE Screenshot](http://software.rochus-keller.ch/obxide_0.7.13.png)


### Oberon+ to LuaJIT bytecode compiler

- Generates LuaJIT 2.0 compatible bytecode
- The full Oberon+ language including the Oakwood libraries are supported
- The SYSTEM module is not supported
- The TRAP() and TRAPIF(condition:BOOLEAN) bult-in procedures let you escape to the debugger


### Binary versions

Here is a binary version of the Oberon+ IDE for Windows: http://software.rochus-keller.ch/OberonIDE_win32.zip.
Just unpack the ZIP somewhere on your drive and double-click ObxIDE.exe; Qt libraries are included, as well as the OBXLJ command line tools, the demo Oberon System and some other example projects (open the project using CTRL+O and then run it using CTRL+R, or right-click to open context menus and select the commands from there).

And here is a version of the Oberon IDE for Linux x86: http://software.rochus-keller.ch/OberonIDE_linux_i368.tar.gz.
It requires a preinstalled Qt version >= 5.4.

Here is a version of the Oberon IDE for macOS x86_64 (>= El Capitan): http://software.rochus-keller.ch/OberonIDE_macOS_x64.dmg.
The app can just be moved to the drive or used directly from the mounted DMG; everything required is included, also the Oberon System demo; please note that the CTRL key is mapped to the command key on Mac, but you have to press CTRL+mouse key to trigger the right mouse button; to summarize: just click=left click, command+click=middle click, CTRL+click=right click; note that the shortcuts can differ between platforms.

Here is a binary version of the OberonViewer for Windows: http://software.rochus-keller.ch/OberonViewer_win32.zip
Just download, unpack and run it; no installer is needed. The ZIP includes the needed Qt libraries.

Here is a binary version of OberonViewer for Linux x86: http://software.rochus-keller.ch/OberonViewer_linux_x86.tar.gz
It requires a preinstalled Qt version >= 5.4.


### Build Steps

Follow these steps if you want to build e.g. the Oberon+ IDE yourself:

1. Make sure a Qt 5.x (libraries and headers) version compatible with your C++ compiler is installed on your system.
1. Create an empty directory, call it e.g. Build.
1. Download https://github.com/rochus-keller/GuiTools/archive/master.zip and unpack to in the Build directory. Rename it to GuiTools.
1. Download https://github.com/rochus-keller/LjTools/archive/master.zip and unpack it to the Build directory. Rename it to LjTools.
1. Download https://github.com/rochus-keller/LuaJIT/archive/LjTools.zip and unpack it to the Build directory. Rename it to LuaJIT. Go to the src subdirectory and run the build script appropriate to your platform (see LuaJIT/doc/install.html for more information).
1. Download https://github.com/rochus-keller/Oberon/archive/master.zip and unpack it to the Build directory. Rename it to Oberon.
1. Goto the Build/Oberon directory and execute e.g. `QTDIR/bin/qmake ObxIde.pro` (see the Qt documentation concerning QTDIR).
1. Run make; after a couple of seconds you will find the executable in the build directory.

Alternatively you can open ObxIde.pro using QtCreator and build it there.

Note that this procedure also applies to OBXLJ.pro, OberonIde.pro, OBNLC.pro, and OberonViewer.pro. 

## Support
If you need support or would like to post issues or feature requests please use the Github issue list at https://github.com/rochus-keller/Oberon/issues or send an email to the author.



