# GameBoy Header Beautifier

[![Build Status](https://travis-ci.org/Geospace/ghb.svg?branch=master)](https://travis-ci.org/Geospace/ghb)

GameBoy Header Beautifier (GHB) is a command line tool to help you retrieve
informations from a GameBoy ROM. It reads its header and outputs
all it finds.

``` terminal
$ ./ghb "The Legend of Zelda, Link's Awakening.gbc"
Entry:                  00 c3 50 01
Nintendo:               ce ed 66 66 cc 0d 00 0b 03 73 00 83...
Title:                  ZELDA
Color support:          Monochromatic & Color
Licensee code:          30 (new)
Super Game Boy:         Yes
Cartridge:              1b
ROM Size:               05
ROM Size:               03
Destination:            Non-Japanese
Version:                Unknown
```

Check out [this link](http://gbdev.gg8.se/wiki/articles/The_Cartridge_Header)
for more informations about the GameBoy cartridge header.

## Installation

Clone the repo, make, run.

``` terminal
$ git clone git@github.com:Geospace/ghb.git
$ cd ghb/
ghb $ make
ghb $ ./ghb
GHB is a GameBoy Header Beautifier.
It reads a GambeBoy ROM file and prints some informations.

USAGE: ./ghb [ROM file]
```

GHB is written in plain C11 and should run on approximately any modern system.

## Contribute

Open an issue, a pull request, fork the project, do whatever you want ! :)
