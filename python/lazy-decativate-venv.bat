@ECHO off

REM Quick script on deactiviating virtual environment

SET venv=.\.venv\Scripts\deactivate.bat
ECHO Deactivating venv %venv%
%venv%
