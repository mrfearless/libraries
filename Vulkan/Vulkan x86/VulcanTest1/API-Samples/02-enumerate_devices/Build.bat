\masm32\bin\ml /c /coff /I"\masm32\include" 02-enumerate_devices.asm
\masm32\bin\link /SUBSYSTEM:CONSOLE /RELEASE /VERSION:4.0 /IGNORE:4210 /LIBPATH:"\masm32\lib" 02-enumerate_devices.obj