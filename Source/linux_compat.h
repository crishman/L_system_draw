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
    
    // Default constructor to initialize all members
    CRect() : left(0), top(0), right(0), bottom(0) {}
    
    // Parameterized constructor
    CRect(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
    
    int Width() const { return right - left; }
    int Height() const { return bottom - top; }
};

class CPaintDC {
public:
    // Stub implementation
    CPaintDC() {} // Default constructor
};

class CWinApp {
public:
    // Stub implementation
    CWinApp() {} // Default constructor
};

class CDialog {
public:
    // Stub implementation
    CDialog() {} // Default constructor
};

#endif // LINUX_BUILD

#endif // LINUX_COMPAT_H