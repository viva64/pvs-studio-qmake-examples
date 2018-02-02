# Examples of PVS-Studio integration in QMake (QtCreator)

For [PVS-Studio](https://www.viva64.com/en/pvs-studio/) analyzer integration into your project, you can use the **PVS-Studio.pri** module. 

A few examples in this repository will help you learn how to use the QMake module in your project properly.

A few examples in this repository will help you learn how to use the QMake module in your project properly.

1. Connect the **.pri** module to your project;
2. Add a new configuration, for example, "Analyze";
3. In settings of the configuration "Build Steps" -> "Make arguments", add the name of the target (pvs_studio.target = **this_name**);
4. Switch to the created configuration and run "Build All";
5. See the results in the analyzer in the *Issues Panel*.

### Analysis without integration (Linux only)

This utility requires the [strace](http://man7.org/linux/man-pages/man1/strace.1.html) utility.

This can be built with the help of the command:

```
pvs-studio-analyzer trace -- qmake
```

You can use any other build command with all the necessary parameters instead of make, for example:

``
pvs-studio-analyzer trace -- qmake debug
``

After you build your project, you should execute the commands:

```
pvs-studio-analyzer analyze -o /path/to/project.log -e /path/to/exclude-path -j<N>
plog-converter -a GA:1,2 -t tasklist -o /path/to/project.tasks /path/to/project.log
```

Analyzer warnings will be saved into the specified *project.tasks* file.

If your project isn't CMake or you have problems with the *strace* utility, you may try generating the file *compile_commands.json* with the help of the [Bear](https://github.com/rizsotto/Bear) utility. This file will help the analyzer to check a project successfully only in cases where the environment variables don't influence the file compilation.

#### If you use cross compilers

In this case, the compilers may have special names and the analyzer will not be able to find them. To analyze such a project, you must explicitly list the names of the compilers without the paths:

```
pvs-studio-analyzer analyze ... --compiler COMPILER_NAME --compiler COMPILER_NAME ...
plog-converter ...
```

Also, when you use cross compilers, the directory with the header files of the compiler will be changed.  It's necessary to exclude such directories from the analysis with the help of ```-e``` flag, so that the analyzer doesn't issue warnings for these files.

```
pvs-studio-analyzer ... -e /path/to/exclude-path ...
```

There shouldn't be any issues with the cross compilers during the integration of the analyzer into the build system.
