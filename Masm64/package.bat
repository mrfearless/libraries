@echo off
echo Masm64 Library - Creating packages
echo.
echo Creating Masm64 Library source package...
del Masm64LibrarySource.zip
"Z:\Program Files\Compression Programs\WinRAR\WinRar.exe" a -m5 Masm64LibrarySource.zip Masm64.rap Masm64.Inc *.Asm Notes.txt Masm64Library-readme.txt
echo.
echo Creating Masm64 Library only package...
del Masm64LibraryOnly.zip
"Z:\Program Files\Compression Programs\WinRAR\WinRar.exe" a -m5 Masm64LibraryOnly.zip Masm64.Inc Masm64.lib Masm64Library-readme.txt
echo.
echo Creating Masm64 Library full package including source...
del Masm64Library-FullPackageIncSource.zip
"Z:\Program Files\Compression Programs\WinRAR\WinRar.exe" a -m5 Masm64Library-FullPackageIncSource.zip Masm64LibrarySource.zip Masm64.inc Masm64.lib Masm64Library-readme.txt
echo.
echo.Copying files to GitHub project folders...
Copy /Y Masm64LibraryOnly.zip M:\GitProjects\Masm64-Library\downloads\ >> NUL
Copy /Y Masm64LibrarySource.zip M:\GitProjects\Masm64-Library\downloads\ >> NUL
Copy /Y Masm64Library-readme.txt M:\GitProjects\Masm64-Library\downloads\ >> NUL
Copy /Y Masm64.inc M:\GitProjects\Masm64-Library\downloads\ >> NUL
Copy /Y Masm64.lib M:\GitProjects\Masm64-Library\downloads\ >> NUL
Copy /Y Masm64Library-FullPackageIncSource.zip M:\GitProjects\Masm64-Library\downloads\ >> NUL

Copy /Y Masm64LibraryOnly.zip M:\GitProjects\Masm64-Library\ >> NUL
Copy /Y Masm64LibrarySource.zip M:\GitProjects\Masm64-Library\ >> NUL
Copy /Y Masm64Library-readme.txt M:\GitProjects\Masm64-Library\ >> NUL
Copy /Y Masm64.inc M:\GitProjects\Masm64-Library\ >> NUL
Copy /Y Masm64.lib M:\GitProjects\Masm64-Library\ >> NUL
Copy /Y Masm64Library-FullPackageIncSource.zip M:\GitProjects\Masm64-Library\ >> NUL
echo.
echo.Finished