del %1.exe
del %1.obj
del Resource.res
cl.exe /c /EHsc %1.cpp
rc.exe Resource.rc
link.exe %1.obj Resource.res user32.lib gdi32.lib comctl32.lib /SUBSYSTEM:WINDOWS
%1.exe