#define _CRT_SECURE_NO_WARNINGS 1
#include "cheat.h"
DWORD GetPIDByWindowTitle(const WCHAR* windowTitle) {
    HWND hwnd = FindWindow(NULL, windowTitle); // 通过窗口标题获取窗口句柄
    if (!hwnd) return 0;  // 如果窗口不存在，返回 0

    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid); // 获取窗口所属的进程 ID
    return pid;
}
int main() {
    DWORD pid;
    pid = GetPIDByWindowTitle("")

    // 目标 DLL 路径
    const char* dllPath = "C:\\path\\to\\your.dll";

    // 打开目标进程
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        std::cout << "Failed to open process\n";
        return 1;
    }

    // 在目标进程中分配内存
    LPVOID pRemoteMemory = VirtualAllocEx(hProcess, NULL, strlen(dllPath) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    // 将 DLL 路径写入目标进程
    WriteProcessMemory(hProcess, pRemoteMemory, dllPath, strlen(dllPath) + 1, NULL);

    // 获取 LoadLibraryA 的地址
    LPTHREAD_START_ROUTINE pLoadLibrary = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

    // 创建远程线程执行 LoadLibraryA
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, pLoadLibrary, pRemoteMemory, 0, NULL);

    // 等待线程完成
    WaitForSingleObject(hThread, INFINITE);

    // 释放资源
    VirtualFreeEx(hProcess, pRemoteMemory, 0, MEM_RELEASE);
    CloseHandle(hThread);
    CloseHandle(hProcess);

    return 0;
}