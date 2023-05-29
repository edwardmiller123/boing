# Boing

A simple side scrolling game with music. You jump over the spikes..it's pretty straigt forward.
My second SFML project, still pretty janky but less so than the first so theres that. Thanks again to my
fiance for helping with the drawings. She also makes [things](https://github.com/LucyRTCodes) to!

## Requirements

### SFML

* Windows
  - For compilation using MinGW you can Download sfml and the matching compiler version
  from the [website](https://www.sfml-dev.org/download/sfml/2.5.1/). The versions _MUST_
  match 100 percent.

* Linux
  - The simplest way is to install SFML with:

```
sudo apt-get install libsfml-dev
```

### nlohmann/json

Pull [nlohmann/json](https://github.com/nlohmann/json) and provide the path
to single_include/nlohmann/json.hpp when compiling. Alternatively, that is the only file
that is needed so you can just download that.

## Compilation Instructions (Windows)

### Dynamic Linking

To make the .o file:

```
g++ -I path\to\sfml\SFML-2.5.1\include -I path\to\nlohmann\json -c main.cpp -o main.o
```

To make the game.exe:

```
g++ -L path\to\sfml\SFML-2.5.1\lib .\main.o -o game.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lsfml-main -mwindows
```

With console output:

```
g++ -L path\to\sfml\SFML-2.5.1\lib .\main.o -o game.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lsfml-main
```

### Static Linking

To be able to run the game out side of the directory it was built in we can compile and link to 
the static SFML libaries in one command,

```
 g++ -DSFML_STATIC -I path\to\sfml\SFML-2.5.1\include -I path\to\nlohmann\json -L C:\Users\edwar\Documents\codeProjects\C++\libaries\SFML-2.5.1\lib main.cpp -o game.exe -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -static -static-libgcc -static-libstdc++ -mwindows
```
Remember that the assets folder must still be in the same directory as the .exe

## Compilation Instructions (Linux)

You can then compile with:

```
g++ -c main.cpp
```

and create the application with:

```
g++ main.o -o game.exe sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
```
