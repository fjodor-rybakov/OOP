@ECHO OFF

ECHO 1) Check empty params
crypt.exe
IF NOT ERRORLEVEL 1 GOTO err

ECHO 2) Check three params
crypt.exe crypt in.txt out.txt
IF NOT ERRORLEVEL 1 GOTO err

ECHO 3) Check for non-numeric input
crypt.exe crypt in.txt out.txt ef
IF NOT ERRORLEVEL 1 GOTO err

ECHO 4) Check for incorrect operation
crypt.exe cry in.txt out.txt 53
IF NOT ERRORLEVEL 1 GOTO err

ECHO 5) Expected result check
crypt.exe crypt in.txt out.txt 12 > output.txt
IF ERRORLEVEL 1 GOTO err
FC output.txt cryptText.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT

:err
ECHO Program testing failed :-(
EXIT