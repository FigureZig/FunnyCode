#include "Communication.h"
#include "Message.h"
#include "Data.h"


NTSTATUS IOControl(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
    UNREFERENCED_PARAMETER(DeviceObject);
    NTSTATUS Status = STATUS_UNSUCCESSFUL;
    ULONG ByteIO = 0;

    PIO_STACK_LOCATION Stack = IoGetCurrentIrpStackLocation(Irp);

    ULONG ControlCode = Stack->Parameters.DeviceIoControl.IoControlCode;

    if (ControlCode == IO_GET_CLIENTADDRESS)
    {
        PULONG OutPut = (PULONG)Irp->AssociatedIrp.SystemBuffer;
        *OutPut = HL2ClientDLLAddress;

        DebugMessage("Clinet Address requested \n");

        Status = STATUS_SUCCESS;
        ByteIO = sizeof(*OutPut);
    }
    else
    {
        ByteIO = 0;
    }

    Irp->IoStatus.Status = Status;
    Irp->IoStatus.Information = ByteIO;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);

    return Status;
}

NTSTATUS CloseCall(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
    UNREFERENCED_PARAMETER(DeviceObject);
    Irp->IoStatus.Status = STATUS_SUCCESS;
    Irp->IoStatus.Information = 0;

    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    DebugMessage("Connection terminated! \n");

    return STATUS_SUCCESS;
}

NTSTATUS CreateCall(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
    UNREFERENCED_PARAMETER(DeviceObject);
    Irp->IoStatus.Status = STATUS_SUCCESS;
    Irp->IoStatus.Information = 0;

    IoCompleteRequest(Irp, IO_NO_INCREMENT);

    DebugMessage("Connection enstablished! \n");

    return STATUS_SUCCESS;
}
