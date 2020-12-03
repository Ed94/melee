# Welcome, this is Eds personal fork of the repo...

Please [visit](https://github.com/doldecomp/melee) the original fork the actual code, mine contains slightly different formatting / content to suit my tastes while I learning / contribute.

My [wiki](https://github.com/Ed94/melee/wiki) may be helpful to you.

This repo is manually kept in sync by me, however my intention was not to do direct pull requests to the original repo. 

### Why are you going about it this way?

I know C/C++ (and some rust) from the pure coding perspective with a sort of robust (I kinda get how they work but not really...) black box to how its actually represented in intermediate langauge (llvm) or assemlby + linker. This gets me by but doesn't make me feel as comfortable as I would like to be. My aim is to attempt some reversing for this project from a lighter architecture (its PowerPC, not the monster that is x86-64), with the goal of getting more comfortable. 

I don't mind the redudancy in having to write to two diff version of the repo, and it provides me the chance to have my own flavor of conventions for comments and formatting, so I can focus more on understanding what in the world is going on while I learn.

At the same time, I finally get to see what mess HAL has under the hood for their masterpiece so I can stuff it with some lava if you know what I mean....

# Original Readme:

# Super Smash Bros Melee

This repo contains a WIP decompilation of Super Smash Bros Melee (US).

It builds the following DOL:

main.dol: `sha1: 08e0bf20134dfcb260699671004527b2d6bb1a45`

## Building

### Required tools

* [devkitPro](https://devkitpro.org/wiki/Getting_Started)
* Python3 (`pacman -S msys/python3`)
* gcc (`pacman -S gcc`)

### Instructions

1. Obtain a clean DOL of Melee 1.2 and place it in the base working directory and name it `baserom.dol`.
2. Obtain a copy of the MWCC (Build 158) PowerPC and place it in tools/mwcc_compiler/1.1/ folder in tools/. (NOTE: This compiler's executables [mwcceppc.exe mwasmeppc.exe and mwldeppc.exe] can be installed with Codewarrior 1.1 for Gamecube, but no license or crack is provided with this project. Please obtain access to the compiler on your own.) If you are in the Gamecube/Wii Decompilation discord (not public at this time, but if you are interested and have the skillset to contribute, please DM Revo#7090 on Discord for access), download GC_COMPILERS.zip and extract it to tools/mwcc_compiler/.
3. Run the `make` command

## Contributions

Contributions and PRs are welcome.
