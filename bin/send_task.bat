@echo off

if /i "%~x2" NEQ ".cpp" (
    echo Can send only C++ ^(.cpp^) files.
    exit /b
)

set "filename=%~nx2"
set "dirname=%~n1"

python "%~dp0..\manager.py" --send %dirname% %filename%