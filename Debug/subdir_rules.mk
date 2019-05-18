################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
DLOG4CHC.obj: ../DLOG4CHC.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="DLOG4CHC.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_CodeStartBranch.obj: ../F2806x_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="F2806x_CodeStartBranch.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_CpuTimers.obj: ../F2806x_CpuTimers.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="F2806x_CpuTimers.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_DefaultIsr.obj: ../F2806x_DefaultIsr.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="F2806x_DefaultIsr.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_GlobalVariableDefs.obj: ../F2806x_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="F2806x_GlobalVariableDefs.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_PieCtrl.obj: ../F2806x_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="F2806x_PieCtrl.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_PieVect.obj: ../F2806x_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="F2806x_PieVect.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_SysCtrl.obj: ../F2806x_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="F2806x_SysCtrl.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_usDelay.obj: ../F2806x_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="F2806x_usDelay.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

MyADC.obj: ../MyADC.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="MyADC.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

MyEPWM.obj: ../MyEPWM.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="MyEPWM.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

MyFilter.obj: ../MyFilter.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="MyFilter.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

MyGPIO.obj: ../MyGPIO.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="MyGPIO.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

MyGrid.obj: ../MyGrid.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="MyGrid.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

MySCI.obj: ../MySCI.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="MySCI.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

mathblock.obj: ../mathblock.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_common/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/device_support/f2806x/v130/F2806x_headers/source" --include_path="D:/Dropbox/CODING_THESIS/CODE_GRID_220V/F2806x_drivers" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/app_libs/motor_control/math_blocks/v3.0" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/include" --include_path="D:/SOTFWAVE/controlSUITE3.4.7setup/controlSUITE/libs/math/IQmath/v15c/lib" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c2000_6.4.6/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="mathblock.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


