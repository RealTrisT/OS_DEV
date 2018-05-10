cd bootsector
call do.bat
cd ../kernel
call compile.bat
cd ../storage
call patch_image.bat
pause