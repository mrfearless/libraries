\masm32\bin\ml /c /coff /I"\masm32\include" 03-init_device.asm
\masm32\bin\link /SUBSYSTEM:CONSOLE /RELEASE /VERSION:4.0 /IGNORE:4210 /LIBPATH:"\masm32\lib" 03-init_device.obj