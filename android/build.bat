@echo off
set PATH=%PATH%;"%LOCALAPPDATA%\Android\Sdk\ndk-bundle"

ndk-build APP_OPTIM="release"