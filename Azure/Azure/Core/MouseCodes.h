
#ifndef MOUSECODES_H
#define MOUSECODES_H

#include "azpch.h"
namespace Azure{
    using MouseCode = uint16_t;

    namespace Mouse
    {
        enum : MouseCode
        {
            Button0                = 0,
            Button1                = 1,
            Button2                = 2,
            Button3                = 3,
            Button4                = 4,
            Button5                = 5,
            Button6                = 6,
            Button7                = 7,

            ButtonLast             = Button7,
            ButtonLeft             = Button1,
            ButtonRight            = Button3,
            ButtonMiddle           = Button2
        };
    }
}

#endif //MOUSECODES_H
