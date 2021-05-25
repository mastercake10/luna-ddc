#ifndef UTIL_H
#define UTIL_H
#include "ddcutil_c_api.h"
#include "ddcutil_status_codes.h"

class DisplayUtil {
    private:
        DDCA_Display_Handle handle;

    public:
        DisplayUtil();
        int getCurrentBrightness();
        void setBrightness(int value);
};



#endif // UTIL_H
