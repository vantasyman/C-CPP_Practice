#define _CRT_SECURE_NO_WARNINGS 1
#include "cheat.h"
DWORD GetPIDByWindowTitle(const WCHAR* windowTitle) {
    HWND hwnd = FindWindow(NULL, windowTitle); // ͨ�����ڱ����ȡ���ھ��
    if (!hwnd) return 0;  // ������ڲ����ڣ����� 0

    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid); // ��ȡ���������Ľ��� ID
    return pid;
}
int main() {
    DWORD pid;
    pid = GetPIDByWindowTitle("")

    // Ŀ�� DLL ·��
    const char* dllPath = "C:\\path\\to\\your.dll";

    // ��Ŀ�����
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        std::cout << "Failed to open process\n";
        return 1;
    }

    // ��Ŀ������з����ڴ�
    LPVOID pRemoteMemory = VirtualAllocEx(hProcess, NULL, strlen(dllPath) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    // �� DLL ·��д��Ŀ�����
    WriteProcessMemory(hProcess, pRemoteMemory, dllPath, strlen(dllPath) + 1, NULL);

    // ��ȡ LoadLibraryA �ĵ�ַ
    LPTHREAD_START_ROUTINE pLoadLibrary = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

    // ����Զ���߳�ִ�� LoadLibraryA
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, pLoadLibrary, pRemoteMemory, 0, NULL);

    // �ȴ��߳����
    WaitForSingleObject(hThread, INFINITE);

    // �ͷ���Դ
    VirtualFreeEx(hProcess, pRemoteMemory, 0, MEM_RELEASE);
    CloseHandle(hThread);
    CloseHandle(hProcess);

    return 0;
}