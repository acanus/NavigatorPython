#include "pch.h"
#include <iostream>
#include "NavigatorTest.h"
#include "compatibility.h"
#include "bdaqctrl.h"
#include <boost/python.hpp>

//using namespace std;
using namespace boost::python;
using namespace Automation::BDaq;

typedef unsigned char byte;

#define  deviceDescription  L"DemoDevice,BID#0"
//const wchar_t* profilePath = L"../../profile/DemoDevice.xml";
int32    startPort = 0;
int32    portCount = 1;

DIO::DIO()
{
    ErrorCode        ret = Success;
    // Step 1: Create a instantDoCtrl for DO function.
    instantDoCtrl= InstantDoCtrl::Create();
}
DIO::~DIO() {
    instantDoCtrl->Dispose();
}

bool DIO::Connect(std::wstring description)
{
    ErrorCode        ret = Success;
    DeviceInformation devInfo(description.c_str());
    std::cout << "create description" << std::endl;
    //this->instantDoCtrl = InstantDoCtrl::Create();
    ret=instantDoCtrl->setSelectedDevice(devInfo);
    std::cout << "connected" << std::endl;
    if (BioFailed(ret)) {
        //error
        return false;
    }
    else
    {
        return true;
    }
    
    
}

bool DIO::WriteByte(int32 port, uint8 value)
{
    ErrorCode        ret = Success;
    ret = instantDoCtrl->Write(port, value);
    return (!BioFailed(ret));
}
BOOST_PYTHON_MODULE(NavigatorTest)
{
    class_<DIO>("DIO")
        .def("Connect", &DIO::Connect)
        .def("WriteByte", &DIO::WriteByte)
        ;
}