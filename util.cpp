#include "util.h"
#include <iostream>

DisplayUtil::DisplayUtil() {
    DDCA_Display_Info_List* list;
    ddca_get_display_info_list2(true, &list);

    DDCA_Display_Ref ref = list ->info->dref;

    //ddca_enable_verify(true);

    ddca_open_display2(ref, false, &this->handle);
    printf("Opened display handle: %s\n", ddca_dh_repr(this->handle));
}

int DisplayUtil::getCurrentBrightness() {
    DDCA_Vcp_Feature_Code code = 0x10;
    DDCA_Non_Table_Vcp_Value value;

    ddca_get_non_table_vcp_value(this->handle, code, &value);

    return value.sl;
}

void DisplayUtil::setBrightness(int value) {
    DDCA_Vcp_Feature_Code code = 0x10;
    //ddca_set_table_vcp_value(handle, code, &value);
    //ddca_set_any_vcp_value(handle, code, &value);
    uint8_t new_sh = value >> 8;
    uint8_t new_sl = value & 0xff;
    ddca_set_non_table_vcp_value(this->handle, code, new_sh, new_sl);
}
