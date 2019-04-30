\masm32\bin\ml /c /coff /I"\masm32\include" 01-init_instance.asm
\masm32\bin\link /SUBSYSTEM:CONSOLE /RELEASE /VERSION:4.0 /IGNORE:4210 /LIBPATH:"\masm32\lib" 01-init_instance.obj