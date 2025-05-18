#ifndef LINUX_COMPAT_H
#define LINUX_COMPAT_H

// Minimal compatibility layer for Linux builds
#ifdef LINUX_BUILD

// Basic types
typedef int BOOL;
typedef unsigned int UINT;
typedef void* LPVOID;
typedef const char* LPCTSTR;
typedef char* LPTSTR;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned short WORD;

// Constants
#define TRUE 1
#define FALSE 0

// MFC-equivalent classes (minimal stubs)
class CRect {
public:
    int left, top, right, bottom;
    int Width() const { return right - left; }
    int Height() const { return bottom - top; }
};

class CPaintDC {
public:
    // Stub implementation
};

class CWinApp {
public:
    // Stub implementation
};

class CDialog {
public:
    // Stub implementation
};

#endif // LINUX_BUILD

#endif // LINUX_COMPAT_H