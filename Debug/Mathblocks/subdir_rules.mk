################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Mathblocks/MyFilter.obj: ../Mathblocks/MyFilter.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="c:/ti/ccsv6/tools/compiler/c2000_6.2.7/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_common/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_headers/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_headers/support" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_drivers" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/IQmath/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/Mathblocks" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/TNPC" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="Mathblocks/MyFilter.pp" --obj_directory="Mathblocks" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Mathblocks/MyGrid.obj: ../Mathblocks/MyGrid.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="c:/ti/ccsv6/tools/compiler/c2000_6.2.7/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_common/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_headers/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_headers/support" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_drivers" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/IQmath/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/Mathblocks" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/TNPC" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="Mathblocks/MyGrid.pp" --obj_directory="Mathblocks" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Mathblocks/mathblock.obj: ../Mathblocks/mathblock.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="c:/ti/ccsv6/tools/compiler/c2000_6.2.7/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_common/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_headers/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_headers/support" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/F2806x_drivers" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/IQmath/include" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/Mathblocks" --include_path="D:/Dropbox/CODING_THESIS/CCS WS/TNPC" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="Mathblocks/mathblock.pp" --obj_directory="Mathblocks" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


