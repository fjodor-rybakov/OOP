@ECHO OFF

ECHO 1) Check empty params
flipbyte.exe
IF NOT ERRORLEVEL 1 GOTO err

ECHO 2) Check one params
flipbyte.exe ref
IF NOT ERRORLEVEL 1 GOTO err

ECHO 3) Expected result check
flipbyte.exe 6 > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt 96.txt
IF ERRORLEVEL 1 GOTO err

ECHO 4) Expected result check
flipbyte.exe 20 > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt 40.txt
IF ERRORLEVEL 1 GOTO err

ECHO 5) Check for large input
flipbyte.exe 500
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT

:err
ECHO Program testing failed :-(
EXIT