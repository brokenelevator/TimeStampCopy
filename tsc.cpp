#include "stdafx.h"
#include <windows.h>

HANDLE source;
HANDLE target;
FILETIME creation_time_stamp;
FILETIME access_time_stamp;
FILETIME edit_time_stamp;

int _tmain(int argc, _TCHAR* argv[])
{
if(argc != 6)
        {
        printf("\nUsage: tsc [source] [target] [creation] [access] [write]\n\nsource - file to read timestamp[s] from\ntarget - file to save timestamp[s] to\ncreation, access, write - timestamp options:\n      c - replace with source file creation timestamp\n      a - replace with source file last access timestamp\n      w - replace with source file last write(save) timestamp\n      x - leave unchanged\n");
        return 0;
        }
source = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
if(source == INVALID_HANDLE_VALUE)
        {
        printf("Could not open file to read.");
        return -1;
        }
target = CreateFile(argv[2], FILE_WRITE_ATTRIBUTES, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (target == INVALID_HANDLE_VALUE)
        {
        printf("Could not open file to write.");
        return -1;
        }
int tmp = 0;
tmp = GetFileTime(source, &creation_time_stamp, &access_time_stamp, &edit_time_stamp);
if(tmp == 0)
        {
        printf("Getting timestamps failed");
        CloseHandle(source);
        CloseHandle(target);
        return -1;
        }
if(wcscmp(argv[3], L"x") == 0) printf(" ");
else if(wcscmp(argv[3], L"c") == 0) tmp = SetFileTime(target, &creation_time_stamp, (LPFILETIME) NULL, (LPFILETIME) NULL);
else if(wcscmp(argv[3], L"a") == 0) tmp = SetFileTime(target, &access_time_stamp, (LPFILETIME) NULL, (LPFILETIME) NULL);
else if(wcscmp(argv[3], L"w") == 0) tmp = SetFileTime(target, &edit_time_stamp, (LPFILETIME) NULL, (LPFILETIME) NULL);
if(tmp == 0)
        {
        printf("Changing timestamps failed");
        CloseHandle(source);
        CloseHandle(target);
        return -1;
        }
if(wcscmp(argv[4], L"x") == 0) printf(" ");
else if(wcscmp(argv[4], L"c") == 0) tmp = SetFileTime(target, (LPFILETIME) NULL, &creation_time_stamp, (LPFILETIME) NULL);
else if(wcscmp(argv[4], L"a") == 0) tmp = SetFileTime(target, (LPFILETIME) NULL, &access_time_stamp, (LPFILETIME) NULL);
else if(wcscmp(argv[4], L"w") == 0) tmp = SetFileTime(target, (LPFILETIME) NULL, &edit_time_stamp, (LPFILETIME) NULL);
if(tmp == 0)
        {
        printf("Changing timestamps failed");
        CloseHandle(source);
        CloseHandle(target);
        return -1;
        }
if(wcscmp(argv[5], L"x") == 0) printf(" ");
else if(wcscmp(argv[5], L"c") == 0) tmp = SetFileTime(target, (LPFILETIME) NULL, (LPFILETIME) NULL, &creation_time_stamp);
else if(wcscmp(argv[5], L"a") == 0) tmp = SetFileTime(target, (LPFILETIME) NULL, (LPFILETIME) NULL, &access_time_stamp);
else if(wcscmp(argv[5], L"w") == 0) tmp = SetFileTime(target, (LPFILETIME) NULL, (LPFILETIME) NULL, &edit_time_stamp);
if(tmp == 0)
        {
        printf("Changing timestamps failed");
        CloseHandle(source);
        CloseHandle(target);
        return -1;
        }
CloseHandle(source);
CloseHandle(target);
return 0;
}