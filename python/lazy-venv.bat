@ECHO off

REM Lazy way of starting virtual environment

SET venv=.\.venv\Scripts\activate.bat

ECHO Starting up .venv for python version: 3.12
%venv%
