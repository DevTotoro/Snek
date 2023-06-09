# Snek
 
A remake of the classic Snake game made with C++ and SDL2.

## Building

No OS-specific code has been used so the application should work on all operating systems, but it has only been tested on Windows.

### Requirements

- premake5
- Visual Studio 2022 or higher

### Steps

1. Clone or download the repository
2. Create a `.bat` file in the repository directory and enter the following:

```
CALL path\to\premake5.exe\premake5.exe vs2022
PAUSE
```

3. Save the file and run
4. Open the created `*.sln` with Visual Studio and build the project
5. Copy the `SDL2.dll` file from `vendor/SDL2-2.26.5/lib/x86` to output folder
