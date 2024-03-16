@echo off
set PATH=%PATH%;"%LOCALAPPDATA%\Android\Sdk\ndk\26.2.11394342"

ndk-build APP_OPTIM="release"