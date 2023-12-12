#include <ntddk.h>

// 退出driver
VOID DriverUnload(PDRIVER_OBJECT pDriverObject)
{
	DbgPrint("看不见我看不见我  \n");
}

// driver的入口
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING reg_path)
{
	DbgPrint("驱动已经加载\n");

	if (NULL != pDriverObject){
		pDriverObject->DriverUnload = DriverUnload;
	}

	return STATUS_SUCCESS;
}