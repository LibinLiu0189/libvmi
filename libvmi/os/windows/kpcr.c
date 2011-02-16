/*
 * The LibVMI Library is an introspection library that simplifies access to 
 * memory in a target virtual machine or in a file containing a dump of 
 * a system's physical memory.  LibVMI is based on the XenAccess Library.
 *
 * Copyright (C) 2010 Sandia National Laboratories
 * Author: Bryan D. Payne (bpayne@sandia.gov)
 */

#include "libvmi.h"
#include "private.h"
#define _GNU_SOURCE
#include <string.h>

struct _DBGKD_DEBUG_DATA_HEADER64
{
    uint64_t List[2];
    uint32_t OwnerTag;
    uint32_t Size;
} __attribute__ ((packed));
typedef struct _DBGKD_DEBUG_DATA_HEADER64 DBGKD_DEBUG_DATA_HEADER64;

struct _KDDEBUGGER_DATA64
{
    DBGKD_DEBUG_DATA_HEADER64 Header;
    uint64_t KernBase;
    uint64_t BreakpointWithStatus;
    uint64_t SavedContext;
    uint16_t ThCallbackStack;
    uint16_t NextCallback;
    uint16_t FramePointer;
    uint16_t PaeEnabled;
    uint64_t KiCallUserMode;
    uint64_t KeUserCallbackDispatcher;
    uint64_t PsLoadedModuleList;
    uint64_t PsActiveProcessHead;
    uint64_t PspCidTable;
    uint64_t ExpSystemResourcesList;
    uint64_t ExpPagedPoolDescriptor;
    uint64_t ExpNumberOfPagedPools;
    uint64_t KeTimeIncrement;
    uint64_t KeBugCheckCallbackListHead;
    uint64_t KiBugcheckData;
    uint64_t IopErrorLogListHead;
    uint64_t ObpRootDirectoryObject;
    uint64_t ObpTypeObjectType;
    uint64_t MmSystemCacheStart;
    uint64_t MmSystemCacheEnd;
    uint64_t MmSystemCacheWs;
    uint64_t MmPfnDatabase;
    uint64_t MmSystemPtesStart;
    uint64_t MmSystemPtesEnd;
    uint64_t MmSubsectionBase;
    uint64_t MmNumberOfPagingFiles;
    uint64_t MmLowestPhysicalPage;
    uint64_t MmHighestPhysicalPage;
    uint64_t MmNumberOfPhysicalPages;
    uint64_t MmMaximumNonPagedPoolInBytes;
    uint64_t MmNonPagedSystemStart;
    uint64_t MmNonPagedPoolStart;
    uint64_t MmNonPagedPoolEnd;
    uint64_t MmPagedPoolStart;
    uint64_t MmPagedPoolEnd;
    uint64_t MmPagedPoolInformation;
    uint64_t MmPageSize;
    uint64_t MmSizeOfPagedPoolInBytes;
    uint64_t MmTotalCommitLimit;
    uint64_t MmTotalCommittedPages;
    uint64_t MmSharedCommit;
    uint64_t MmDriverCommit;
    uint64_t MmProcessCommit;
    uint64_t MmPagedPoolCommit;
    uint64_t MmExtendedCommit;
    uint64_t MmZeroedPageListHead;
    uint64_t MmFreePageListHead;
    uint64_t MmStandbyPageListHead;
    uint64_t MmModifiedPageListHead;
    uint64_t MmModifiedNoWritePageListHead;
    uint64_t MmAvailablePages;
    uint64_t MmResidentAvailablePages;
    uint64_t PoolTrackTable;
    uint64_t NonPagedPoolDescriptor;
    uint64_t MmHighestUserAddress;
    uint64_t MmSystemRangeStart;
    uint64_t MmUserProbeAddress;
    uint64_t KdPrintCircularBuffer;
    uint64_t KdPrintCircularBufferEnd;
    uint64_t KdPrintWritePointer;
    uint64_t KdPrintRolloverCount;
    uint64_t MmLoadedUserImageList;
    uint64_t NtBuildLab;
    uint64_t KiNormalSystemCall;
    uint64_t KiProcessorBlock;
    uint64_t MmUnloadedDrivers;
    uint64_t MmLastUnloadedDriver;
    uint64_t MmTriageActionTaken;
    uint64_t MmSpecialPoolTag;
    uint64_t KernelVerifier;
    uint64_t MmVerifierData;
    uint64_t MmAllocatedNonPagedPool;
    uint64_t MmPeakCommitment;
    uint64_t MmTotalCommitLimitMaximum;
    uint64_t CmNtCSDVersion;
    uint64_t MmPhysicalMemoryBlock;
    uint64_t MmSessionBase;
    uint64_t MmSessionSize;
    uint64_t MmSystemParentTablePage;
    uint64_t MmVirtualTranslationBase;
    uint16_t OffsetKThreadNextProcessor;
    uint16_t OffsetKThreadTeb;
    uint16_t OffsetKThreadKernelStack;
    uint16_t OffsetKThreadInitialStack;
    uint16_t OffsetKThreadApcProcess;
    uint16_t OffsetKThreadState;
    uint16_t OffsetKThreadBStore;
    uint16_t OffsetKThreadBStoreLimit;
    uint16_t SizeEProcess;
    uint16_t OffsetEprocessPeb;
    uint16_t OffsetEprocessParentCID;
    uint16_t OffsetEprocessDirectoryTableBase;
    uint16_t SizePrcb;
    uint16_t OffsetPrcbDpcRoutine;
    uint16_t OffsetPrcbCurrentThread;
    uint16_t OffsetPrcbMhz;
    uint16_t OffsetPrcbCpuType;
    uint16_t OffsetPrcbVendorString;
    uint16_t OffsetPrcbProcStateContext;
    uint16_t OffsetPrcbNumber;
    uint16_t SizeEThread;
    uint64_t KdPrintCircularBufferPtr;
    uint64_t KdPrintBufferSize;
    uint64_t KeLoaderBlock;
    uint16_t SizePcr;
    uint16_t OffsetPcrSelfPcr;
    uint16_t OffsetPcrCurrentPrcb;
    uint16_t OffsetPcrContainedPrcb;
    uint16_t OffsetPcrInitialBStore;
    uint16_t OffsetPcrBStoreLimit;
    uint16_t OffsetPcrInitialStack;
    uint16_t OffsetPcrStackLimit;
    uint16_t OffsetPrcbPcrPage;
    uint16_t OffsetPrcbProcStateSpecialReg;
    uint16_t GdtR0Code;
    uint16_t GdtR0Data;
    uint16_t GdtR0Pcr;
    uint16_t GdtR3Code;
    uint16_t GdtR3Data;
    uint16_t GdtR3Teb;
    uint16_t GdtLdt;
    uint16_t GdtTss;
    uint16_t Gdt64R3CmCode;
    uint16_t Gdt64R3CmTeb;
    uint64_t IopNumTriageDumpDataBlocks;
    uint64_t IopTriageDumpDataBlocks;
    uint64_t VfCrashDataBlock;
} __attribute__ ((packed));
typedef struct _KDDEBUGGER_DATA64 KDDEBUGGER_DATA64;

static status_t kpcr_symbol_resolve (vmi_instance_t vmi, unsigned long offset, uint32_t *address)
{
    uint64_t tmp = 0;
    uint32_t symaddr = vmi->os.windows_instance.kddebugger_data64 + offset;

    if (VMI_FAILURE == vmi_read_long_long_virt(vmi, symaddr, 0, &tmp)){
        return VMI_FAILURE;
    }
    *address = (uint32_t) tmp;
    return VMI_SUCCESS;
}

static status_t kpcr_symbol_offset (vmi_instance_t vmi, char *symbol, unsigned long *offset)
{
    KDDEBUGGER_DATA64 d;
    unsigned long max_symbol_length = 50;

    if (strncmp(symbol, "KernBase", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KernBase)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "BreakpointWithStatus", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.BreakpointWithStatus)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "SavedContext", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.SavedContext)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KiCallUserMode", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KiCallUserMode)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KeUserCallbackDispatcher", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KeUserCallbackDispatcher)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "PsLoadedModuleList", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.PsLoadedModuleList)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "PsActiveProcessHead", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.PsActiveProcessHead)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "PspCidTable", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.PspCidTable)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "ExpSystemResourcesList", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.ExpSystemResourcesList)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "ExpPagedPoolDescriptor", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.ExpPagedPoolDescriptor)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "ExpNumberOfPagedPools", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.ExpNumberOfPagedPools)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KeTimeIncrement", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KeTimeIncrement)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KeBugCheckCallbackListHead", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KeBugCheckCallbackListHead)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KiBugcheckData", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KiBugcheckData)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "IopErrorLogListHead", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.IopErrorLogListHead)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "ObpRootDirectoryObject", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.ObpRootDirectoryObject)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "ObpTypeObjectType", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.ObpTypeObjectType)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSystemCacheStart", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSystemCacheStart)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSystemCacheEnd", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSystemCacheEnd)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSystemCacheWs", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSystemCacheWs)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmPfnDatabase", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmPfnDatabase)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSystemPtesStart", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSystemPtesStart)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSystemPtesEnd", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSystemPtesEnd)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSubsectionBase", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSubsectionBase)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmNumberOfPagingFiles", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmNumberOfPagingFiles)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmLowestPhysicalPage", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmLowestPhysicalPage)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmHighestPhysicalPage", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmHighestPhysicalPage)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmNumberOfPhysicalPages", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmNumberOfPhysicalPages)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmMaximumNonPagedPoolInBytes", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmMaximumNonPagedPoolInBytes)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmNonPagedSystemStart", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmNonPagedSystemStart)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmNonPagedPoolStart", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmNonPagedPoolStart)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmNonPagedPoolEnd", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmNonPagedPoolEnd)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmPagedPoolStart", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmPagedPoolStart)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmPagedPoolEnd", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmPagedPoolEnd)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmPagedPoolInformation", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmPagedPoolInformation)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmPageSize", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmPageSize)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSizeOfPagedPoolInBytes", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSizeOfPagedPoolInBytes)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmTotalCommitLimit", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmTotalCommitLimit)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmTotalCommittedPages", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmTotalCommittedPages)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSharedCommit", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSharedCommit)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmDriverCommit", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmDriverCommit)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmProcessCommit", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmProcessCommit)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmPagedPoolCommit", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmPagedPoolCommit)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmExtendedCommit", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmExtendedCommit)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmZeroedPageListHead", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmZeroedPageListHead)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmFreePageListHead", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmFreePageListHead)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmStandbyPageListHead", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmStandbyPageListHead)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmModifiedPageListHead", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmModifiedPageListHead)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmModifiedNoWritePageListHead", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmModifiedNoWritePageListHead)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmAvailablePages", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmAvailablePages)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmResidentAvailablePages", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmResidentAvailablePages)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "PoolTrackTable", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.PoolTrackTable)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "NonPagedPoolDescriptor", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.NonPagedPoolDescriptor)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmHighestUserAddress", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmHighestUserAddress)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSystemRangeStart", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSystemRangeStart)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmUserProbeAddress", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmUserProbeAddress)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KdPrintCircularBuffer", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KdPrintCircularBuffer)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KdPrintCircularBufferEnd", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KdPrintCircularBufferEnd)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KdPrintWritePointer", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KdPrintWritePointer)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KdPrintRolloverCount", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KdPrintRolloverCount)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmLoadedUserImageList", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmLoadedUserImageList)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "NtBuildLab", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.NtBuildLab)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KiNormalSystemCall", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KiNormalSystemCall)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KiProcessorBlock", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KiProcessorBlock)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmUnloadedDrivers", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmUnloadedDrivers)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmLastUnloadedDriver", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmLastUnloadedDriver)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmTriageActionTaken", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmTriageActionTaken)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSpecialPoolTag", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSpecialPoolTag)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KernelVerifier", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KernelVerifier)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmVerifierData", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmVerifierData)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmAllocatedNonPagedPool", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmAllocatedNonPagedPool)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmPeakCommitment", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmPeakCommitment)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmTotalCommitLimitMaximum", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmTotalCommitLimitMaximum)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "CmNtCSDVersion", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.CmNtCSDVersion)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmPhysicalMemoryBlock", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmPhysicalMemoryBlock)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSessionBase", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSessionBase)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSessionSize", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSessionSize)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmSystemParentTablePage", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmSystemParentTablePage)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "MmVirtualTranslationBase", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.MmVirtualTranslationBase)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KdPrintCircularBufferPtr", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KdPrintCircularBufferPtr)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KdPrintBufferSize", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KdPrintBufferSize)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "KeLoaderBlock", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.KeLoaderBlock)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "IopNumTriageDumpDataBlocks", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.IopNumTriageDumpDataBlocks)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "IopTriageDumpDataBlocks", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.IopTriageDumpDataBlocks)) - (unsigned long)(&d);
    }
    else if (strncmp(symbol, "VfCrashDataBlock", max_symbol_length) == 0){
        *offset = (unsigned long)(&(d.VfCrashDataBlock)) - (unsigned long)(&d);
    }
    else{
        return VMI_FAILURE;
    }

    return VMI_SUCCESS;
}

static status_t init_kddebugger_data64 (vmi_instance_t vmi)
{
    uint32_t kpcr_address = 0xffdff000;
    uint32_t KdVersionBlock, DebuggerDataList, ListPtr;

    if (VMI_FAILURE == vmi_read_long_virt(vmi, kpcr_address + 0x34, 0, &KdVersionBlock)){
        goto error_exit;
    }
    if (VMI_FAILURE == vmi_read_long_virt(vmi, KdVersionBlock + 0x20, 0, &DebuggerDataList)){
        goto error_exit;
    }
    if (VMI_FAILURE == vmi_read_long_virt(vmi, DebuggerDataList, 0, &ListPtr)){
        goto error_exit;
    }
    vmi->os.windows_instance.kddebugger_data64 = ListPtr;

    return VMI_SUCCESS;
error_exit:
    return VMI_FAILURE;
}

status_t windows_kpcr_lookup (vmi_instance_t vmi, char *symbol, uint32_t *address)
{
    unsigned long offset = 0;

    if (!vmi->os.windows_instance.kddebugger_data64){
        if (VMI_FAILURE == init_kddebugger_data64(vmi)){
            goto error_exit;
        }
    }
    if (VMI_FAILURE == kpcr_symbol_offset(vmi, symbol, &offset)){
        goto error_exit;
    }
    if (VMI_FAILURE == kpcr_symbol_resolve(vmi, offset, address)){
        return VMI_FAILURE;
    }

    return VMI_SUCCESS;
error_exit:
    return VMI_FAILURE;
}