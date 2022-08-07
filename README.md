# TeaEngine
Tea engine is a game engine being wrote in nelua with a custom system that should give better performance, it is focused on ease of use for the user without creating a cluttered a user interface.
* **Modular** to allow only the things you require to be a part of your build and ease of use
* **Simple** use for the end user, allowing them to worry less about the engine and more about what they are doing.
* **Smaller scope** than game engines as Unity, this means you won't get distracted by the amount of tools, leading to faster and more productive. If there are too many tools you *may* get distracted by them or they may even get in your way.
* **Focused** on what you *need* to make a game, if you don't need it, and it doesn't have a good, well thought out purpose it is not there.

![Discord](https://img.shields.io/discord/992551570547949568?color=blue&label=Discord&style=for-the-badge)

# Quick navigation

| [Releases](https://github.com/TeaSpillStudios/TeaEngine#releases) |
[Usage](https://github.com/TeaSpillStudios/TeaEngine#usage) |
[Building from source](https://github.com/TeaSpillStudios/TeaEngine#building-from-source) |
[FAQ](https://github.com/TeaSpillStudios/TeaEngine#faq) |
[TODO](https://github.com/TeaSpillStudios/TeaEngine#todo) |
[Goals](https://github.com/TeaSpillStudios/TeaEngine#goals) |
[Community](https://github.com/TeaSpillStudios/TeaEngine#community) |

# Releases

All releases will be posted in the [Github releases tab](https://github.com/TeaSpillStudios/TeaEngine/releases)

# Usage

##### Linux

Please download the linux build from the [Github releases tab](https://github.com/TeaSpillStudios/TeaEngine/releases) and extract it, then run the ELF Executable file labelled `TeaEngine`.

##### Windows

Please download the windows build from the [Github releases tab](https://github.com/TeaSpillStudios/TeaEngine/releases) and extract it, then run the exe

# Building from source

Download the source code with `git clone --recurse-submodules https://github.com/TeaSpillStudios/TeaEngine/`

Enter the new folder called `TeaEngine` and run `make libs`. Then `make libs-install`. Then enter the `src` folder in the `TeaEngine` directory. Run `make`

Please download the source code from the [Github releases tab](https://github.com/TeaSpillStudios/TeaEngine/releases) and the extract it, on linux please run `make` in the folder. On windows, please run the `.bat` file

# FAQ

### What platforms are going to be supported at the moment?
Windows and Linux are the platforms that are going to be developed for at the moment.

### Is it actively developed?
Yes, it is being devoloped whenever possible, a commit may be released every day at times, or maybe even more at times.

### How long will it take to be a good, usable engine?
This project will probably be good and usable after a couple of months, please be patient.

### TODO

###### Widgets
- [x] UI Window
- [x] Button
- [ ] Text box
- [ ] Check box
- [ ] Input box
- [ ] Slider
- [ ] Dropdown

###### Core systems

- [x] Information Handler
- [x] Event Manager
- [x] UIManager
- [x] Utilities 
- [x] Mouse
- [ ] Scene Manager
- [ ] Engine GUI
- [ ] Map editor
- [ ] Renderer
- [ ] Compiler

# Goals

* To create an easy to use game engine that does not get in your way and simply provides tools to make things easier for you!
* To help people make games for themselves and for others
* To make a game engine anyone can use and not need to pay for anything at all.
* To create a game engine for people to have fun with

# Community

[Discord](https://discord.gg/M7Qkgby2rm)
