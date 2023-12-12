#include<ntifs.h>



VOID             DrvUnload(PDRIVER_OBJECT pdriver)
{
	DbgPrint("Unload\n");
}

extern "C"
NTSTATUS	DriverEntry(PDRIVER_OBJECT driver, PUNICODE_STRING reg_path)
{
	driver->DriverUnload = DrvUnload;
	DbgPrint("--%wZ--\n", reg_path);
	return 0;
}