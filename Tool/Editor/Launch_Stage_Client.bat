@echo off

cd %~dp0

call PathSetting.bat

pushd ..\..
set PROJECT_ROOT=%CD%
popd

set EXE_PATH=%PROJECT_ROOT%\Saved\StagedBuilds\Windows\%PROJECT_NAME%.exe

set LAUNCH_COMMAND=%EXE_PATH% 127.0.0.1 -windowed -ResX=960 -ResY=540

echo %LAUNCH_COMMAND%
%LAUNCH_COMMAND%