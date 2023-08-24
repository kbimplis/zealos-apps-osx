# TempleOS Applications

The applications were created during recreational programming sessions. The
source code is developed solely in TempleOS, so the source files are in DolDoc
format. Since GitHub has limited syntax highlights for DolDoc you may find
constructions like `$ID,2$` (which is an indentation). Also sources contain
binary data because DolDoc keeps sprites in the source files, so some files are
marked as binary by GitHub. It is recommended to read the source code with the
TempleOS editor.

## Supplemental ISO

All applications are available in [Supplemental.ISO.C](Supplemental.ISO.C).
You may use it as a CD-ROM image for TempleOS virtual machine. To mount in
TempleOS execute the next commands:

```
MountIDEAuto;
Drv('T');
Dir;
```

## Applications

### Tic-Tac-Toe

Tic-Tac-Toe game with sprites, dithering, and AI. Future plans:
- Control player (player vs ai, ai vs ai, ai vs player, etc...)
- Support dynamic board size

You may launch Tic-Tac-Toe game by including the `Run.HC`:
```
#include "TicTacToe/Run";
```

https://github.com/und3f/temple-os-apps/assets/168848/159eada6-e3c3-4026-b307-fedee1a57f4b

### TOSC Theme
TempleOS Cloud Theme

It is based on Terry's TempleOS Theme, some code scarps were taken from
AfterEgypt.

Theme media TBD

### HexView

HexView'er is a viewer for binary files. Display HEX presentation of content
side-by-side with printable characters.

Run with:
```
#include "HexView/Run";
```

Programmatic usage:
```
#include "HexView/Load"
HexView("C:/Once.HC.Z", 8);
```

## Repository build process

I use a macro (I've put it on personal menu for quick access), which removes
cursor marks and prepares a supplemental ISO file:
```
$MA,"Make supplemental ISO",LM="CursorRem(\"::/Home/Dev/*\"); RedSeaISO(\"::/Supplemental\", \"::/Home/Dev/\");\n"$
```

Then I mount TempleOS hard drive using [modified
fusefat](https://github.com/alanswx/fusefat/) that supports the `offset` option
(see second reference on how to find the offset) and rsync files into the repo
directory.

## Useful references
1. [TempleOS](https://templeos.org/)
1. [Tsoding TempleOS repo for
   AOC-2021](https://gitlab.com/tsoding/aoc-2021/-/tree/master). Take a look at
   [sync.sh](https://gitlab.com/tsoding/aoc-2021/-/blob/master/sync.sh) and
   [mount.sh](https://gitlab.com/tsoding/aoc-2021/-/blob/master/mount.sh)
   scripts that transfer files from/to TOS.

## Copyright 

Copyright (c) 2023 Sergii Zasenko

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
