@echo off
rem Runs cs2-sdk.exe and updates offsets/signatures in the project.
rem Extra args are passed through, e.g.  update_sdk.bat --skip-dump
cd /d "%~dp0"
where py >nul 2>nul
if %errorlevel%==0 (
    py -3 tools\update_sdk.py %*
) else (
    python tools\update_sdk.py %*
)
pause
