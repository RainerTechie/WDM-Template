# WDM-Template
Windows Kernel driver configurated project for __inline functions (assembler), custom build configuration and debug configuration for not signed driver development (kdmapper...)

## Test Mode
![Test mode example](https://github.com/RainerTechie/WDM-Template/blob/main/readme/testmode.PNG)
**Note:**On this mode the driver can be loaded/unloaded any number of times

## Normal Mode
![Normal mode example](https://github.com/RainerTechie/WDM-Template/blob/main/readme/normalmode.PNG)
**Note:**On this mode the driver can be loaded only if the same driver does not exist and cannot be unloaded

*This project has been developed using VS2022, so to make sure it works use VS2022*
