# Barebones Arkanoid Clone
### Using C++ and an overdose of inheritance and templates
[SDL2](https://www.libsdl.org/) wrapper framework (`./lib/*` and `./data/*`) courtesy of [Dragon's Lake](https://dragonslake.com/join-the-team/)

# Install
In the `makefile`, first set `USINGWINDOWS` accordingly, then continue
## Linux
#### Debian-esque
```
sudo apt install sdl2-dev;
sudo apt install sdl2-image-dev;
```
then `make`
#### Other
idk [compile SDL2 from source](https://wiki.libsdl.org/SDL2/Installation#linuxunix) or something lol  
(then `make`)

## Windows
[add the absolute path to `.\lib\windows` to `%PATH%`](https://www.computerhope.com/issues/ch000549.htm)  
then `make` or `noMake`

# TODO:
- use C++20 modules
- refactor makefile?
- Add blocks as `MoveableEntity`s?
- Add block->point map idea I'd had
- Add powerups also as `MoveableEntity`s
- add player HP
- do proper game end, restart
- cry about not implementing a [component system](https://github.com/vittorioromeo/cppcon2015) instead

