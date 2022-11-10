@echo off
rem Checks if .\lib\windows is in %PATH%

echo === Checking if .\lib\windows\ is on %%PATH%% ===
set libPath=%~dp0lib\windows
set libPathIsInPath=-1

for /f "tokens=*" %%g in ('echo ";%PATH%;" ^| find /C /I ";%libPath%;"') do (set libPathIsInPath=%%g)
rem Also check with extra backslah?
if %libPathIsInPath% == 0 (
	for /f "tokens=*" %%g in ('echo ";%PATH%;" ^| find /C /I ";%libPath%\;"') do (set libPathIsInPath=%%g)
)
rem TODO: handle values other than 0?

if %libPathIsInPath% == 0 (
	echo "%libPath%" is not in the %%PATH%% environment variable.
	echo To add it, see:
	echo https://www.computerhope.com/issues/ch000549.htm
	echo You may need to restart this terminal after.
	echo.

	exit /b -1
)

cls
