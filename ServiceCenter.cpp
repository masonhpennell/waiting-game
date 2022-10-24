#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(int rWindows, int cWindows, int fWindows){
    m_time = 0;
    registrar = new Office(rWindows);
    cashier = new Office(cWindows);
    financialAid = new Office(fWindows);
}

ServiceCenter::~ServiceCenter(){
}