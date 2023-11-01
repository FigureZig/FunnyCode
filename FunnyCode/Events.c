#pragma warning (disable: 4047)

#include "Events.h"
#include "Data.h"
#include "Message.h"

PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo)
{
    //DebugMessage("ImageLoaded: %ls \n", FullImageName->Buffer);

    if (wcsstr(FullImageName->Buffer, L"\\Half-Life 2\\hl2\\bin\\client.dll"))
    {
        DebugMessage("HL2 client.dll found! \n");
        HL2ClientDLLAddress = ImageInfo->ImageBase;

        DebugMessage("ProcessID: %d \n", ProcessId);
    }

    return STATUS_SUCCESS;
}
