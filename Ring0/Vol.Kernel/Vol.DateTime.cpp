#include "stdafx.h"
#include "Vol.DateTime.h"


namespace MBox
{
    namespace Vol
    {
        namespace DateTime
        {
            PLARGE_INTEGER FormatTimeoutToLargeInteger(PLARGE_INTEGER aTimeout, UINT32 aMilliseconds)
            {
                //if (INFINITE == aMilliseconds)
                if (Infinite == aMilliseconds)
                {
                    return nullptr;
                }

                aTimeout->QuadPart = Int32x32To64(aMilliseconds, -10000);
                return aTimeout;
            }

            void GetLocalTime(PLARGE_INTEGER aLocalTime)
            {
                LARGE_INTEGER vUtcTime;
                KeQuerySystemTime(&vUtcTime);
                ExSystemTimeToLocalTime(&vUtcTime, aLocalTime);
            }

            void GetLocalTimeFields(PTIME_FIELDS aTimeFields)
            {
                LARGE_INTEGER vLocalTime;
                GetLocalTime(&vLocalTime);
                RtlTimeToTimeFields(&vLocalTime, aTimeFields);
            }

        }
    }
}
