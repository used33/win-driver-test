#include <ntddk.h>

// �˳�driver
VOID DriverUnload(PDRIVER_OBJECT pDriverObject)
{
	DbgPrint("�������ҿ�������  \n");
}

// driver�����
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING reg_path)
{
	DbgPrint("�����Ѿ�����\n");

	if (NULL != pDriverObject){
		pDriverObject->DriverUnload = DriverUnload;
	}

	return STATUS_SUCCESS;
}