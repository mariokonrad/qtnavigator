qtnavigator
===========

[![Build Status](https://travis-ci.org/mariokonrad/qtnavigator.svg)](https://travis-ci.org/mariokonrad/qtnavigator)

Introduction
------------

This is a playground of a nautical navigation software.
Provided under the license stated in the LICENSE file.

The intention of this playground is to test how well
a desktop application is being implemented, well tested
from the start, keeping the focus of maintainability.
The following tools and technologies are being used
deliberately, fully knowing that they may cause overhead
now, in the hope they help being maintainable in the
future. The technologies and tools being choosen:

- C++11
- cmake (2.8.11 or newer)
- Qt 5.3 (or newer)
- GoogleMock (1.7 or newer)
- git

The design of the software shall follow the rule: everything
that is not explicitly necessary in the core of the software
should be a plugin. This supports the maintainability of each
software part, and it minimizes the dependencies within.

Additional software libraries can be considered if there is
an appropriate way of integrating them into the build process
and if they do not introduce additional dependencies.

Keep in mind:
- Clean Code
- Test Driven


Formatting Rules
----------------

The file .clang-format is being provided and all files
must be kept in proper and consistent formatting using
clang-format with the provided configuration file.

