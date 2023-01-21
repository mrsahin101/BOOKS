@echo off
@set arg1=%1
@set arg2=%2
shift
shift
gcc %arg1%.c -o %arg1%
start %arg1%.exe