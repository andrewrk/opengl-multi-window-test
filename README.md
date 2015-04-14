# Multi Window OpenGL Test

This repository is to figure out the answer to this question:

http://stackoverflow.com/questions/29617370/multiple-opengl-contexts-multiple-windows-multithreading-and-vsync

## Building

```
clang -Werror -Wall -g -o multi-window-test main.c -lglfw -pthread
```

## Results

 * Linux, X11, 4.4.0 NVIDIA 346.47 (2015-04-13)
   - frame rate is 60fps no matter how many windows are open.
