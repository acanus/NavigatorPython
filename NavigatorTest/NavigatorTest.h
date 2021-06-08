#pragma once
#ifdef NAVIGATORTEST_EXPORTS
#define NAVIGATORTEST_API __declspec(dllexport)
#else
#define NAVIGATORTEST_API __declspec(dllimport)
#endif
#include "bdaqctrl.h"
using namespace Automation::BDaq;
class DIO {
public:
    DIO();
    ~DIO();
    bool Connect(std::wstring description);
    bool WriteByte(int32 port,uint8 value);
private:
    InstantDoCtrl* instantDoCtrl;
};


