set base_dir=D:\Dropbox\projects\code\monotextdisplay
set build_dir=%base_dir%\build\windows-msvc\shared-debug

cmake -S %base_dir%\source -B %build_dir% ^
    -D BUILD_SHARED_LIBS=YES ^
    -D CMAKE_BUILD_TYPE=Debug

cmake --build %build_dir% ^
    --config Debug

pause