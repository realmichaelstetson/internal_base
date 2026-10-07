@echo off
setlocal
rem ---------------------------------------------------------------------------
rem  One click: runs cs2-sdk.exe (CS2 must be open), waits until the dump is
rem  written, then rewrites every offset / signature / pattern in src\ and ui\
rem    src\sdk       schema headers, offsets, vtables, interfaces, signatures.cpp
rem    src\features  src\hooks  src\core  ui\   hardcoded offsets and patterns
rem
rem  Extra arguments are passed straight through, e.g.
rem      update_sdk.bat --dry-run      show what would change, write nothing
rem      update_sdk.bat --skip-dump    do not run cs2-sdk.exe, use include\ as is
rem ---------------------------------------------------------------------------
cd /d "%~dp0"

set "PY="
where py >nul 2>&1 && set "PY=py -3"
if not defined PY (
    where python >nul 2>&1 && set "PY=python"
)
if not defined PY (
    echo [!] Python 3 not found. Install it from https://www.python.org/downloads/
    echo     and tick "Add python.exe to PATH".
    pause
    exit /b 1
)

%PY% tools\update_sdk.py %*
set "RC=%ERRORLEVEL%"

echo.
if "%RC%"=="0" (
    echo [+] done - everything resolved against the new dump, you can rebuild now.
) else (
    echo [!] finished with warnings - read the lines marked !! above
    echo     ^(full report: tools\sdk_update_report.txt^). Do NOT inject before
    echo     checking them: a hook on a stale address crashes CS2.
)
pause
exit /b %RC%
