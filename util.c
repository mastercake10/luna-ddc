#include "ddcutil_c_api.h"
#include "ddcutil_status_codes.h"
#include "util.h"

void setBrightness(int value) {
    DDCA_Display_Info_List* list;
    ddca_get_display_info_list2(1, &list);
    printf("%d", list->info->product_code);

    DDCA_Display_Ref ref = list->info->dref;
    DDCA_Display_Handle handle;
    ddca_enable_verify(true);

    ddca_open_display2(ref, false, &handle);
    printf("Opened display handle: %s\n", ddca_dh_repr(handle));
    DDCA_Vcp_Feature_Code code = 0x10;

    //ddca_set_table_vcp_value(handle, code, &value);
    //ddca_set_any_vcp_value(handle, code, &value);
    uint8_t new_sh = value >> 8;
    uint8_t new_sl = 10 & 0xff;
    DDCA_Status ddcrc = ddca_set_non_table_vcp_value(handle, code, new_sh, new_sl);
}


