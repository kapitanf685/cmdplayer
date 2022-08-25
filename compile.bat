@echo off
set PATH=%PATH%;c:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC\14.33.31629\bin\Hostx64\x64\

rem set PATH=%PATH%;c:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\
rem vcvars64.bat

set INCLUDE=c:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC\14.33.31629\include
set INCLUDE=%INCLUDE%;c:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt
set INCLUDE=%INCLUDE%;c:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\um
set INCLUDE=%INCLUDE%;c:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\shared\

set LIB=c:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC\14.33.31629\lib\x64\
set LIB=%LIB%;c:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\um\x64\
set LIB=%LIB%;c:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\ucrt\x64\

<<<<<<< HEAD
@cl.exe /EHsc cmdplayer.cpp /ocmdplay.exe
=======
@cl.exe /EHsc vpxdecoderidl.c cmdplayer.cpp /ocmdplay.exe

>>>>>>> 171c81a (Uploding files)
pause