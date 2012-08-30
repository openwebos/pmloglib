PmLogLib
========

This is the repository for PmLogLib, the webOS logging library.

How to Build on Linux
=====================

## Dependencies

Below are the tools (and their minimum versions) required to build PmLogLib:

* cmake 2.6
* gcc 4.3
* make (any version)
* pkg-config 0.22

## Building

Once you have downloaded the source, execute the following to build it:

    $ mkdir BUILD
    $ cd BUILD
    $ cmake ..
    $ make
    $ sudo make install

The header file will be installed under

    /usr/local/include/PmLogLib

and the libraries under

    /usr/local/lib

You can install it elsewhere by supplying a value for _CMAKE\_INSTALL\_PREFIX_ when invoking _cmake_. For example:

    $ cmake -D CMAKE_INSTALL_PREFIX:STRING=$HOME/projects/openwebos ..
    $ make
    $ make install
    
will install the header file under

    $HOME/projects/openwebos/include/PmLogLib
    
and the libraries under

    $HOME/projects/openwebos/lib
    
directory.

## Generating documentation

The tools required to generate the documentation are:

* doxygen 1.6.3
* graphviz 2.20.2

Once you have run _cmake_, execute the following to generate the documentation:

    $ make docs

To view the generated HTML documentation, point your browser to

    doc/html/index.html

## Linking against PmLogLib

If your system has pkgconfig then you can just add this to your makefile:

    CFLAGS += $(shell pkg-config --cflags PmLogLib)
    LDFLAGS += $(shell pkg-config --libs PmLogLib)

# Copyright and License Information

Unless otherwise specified, all content, including all source code files and
documentation files in this repository are:

Copyright (c) 2007-2012 Hewlett-Packard Development Company, L.P.

Unless otherwise specified or set forth in the NOTICE file, all content,
including all source code files and documentation files in this repository are:
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this content except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
