#include <stdlib.h>
#include "../miui_inter.h"
#include "../miui.h"
#include "../../../miui_intent.h"

#define POWER_REBOOT                 0
#define POWER_RECOVERY               1
#define POWER_BOOTLOADER             2
#define POWER_POWEROFF               3

static STATUS power_mode_sel_child_show(menuUnit *p)
{
    //confirm
    if (RET_YES == miui_confirm(3, p->name, p->desc, p->icon)) {
        switch(p->result) {
            case POWER_REBOOT:
                miuiIntent_send(INTENT_REBOOT, 1, "reboot");
                break;
            case POWER_BOOTLOADER:
                miuiIntent_send(INTENT_REBOOT, 1, "bootloader");
                break;
            case POWER_RECOVERY:
                miuiIntent_send(INTENT_REBOOT, 1, "recovery");
                break;
            case POWER_POWEROFF:
                miuiIntent_send(INTENT_REBOOT, 1, "poweroff");
                break;
            default:
                assert_if_fail(0);
            break;
        }
    }
    return MENU_BACK;
}

struct _menuUnit * power_reset_ui_init()
{
    struct _menuUnit *p = common_ui_init();
    return_null_if_fail(p != NULL);
    strncpy(p->name, "<~powerreset.name>", MENU_LEN);
    menuUnit_set_title(p, "<~power.title>");
    menuUnit_set_icon(p,"@power");
    menuUnit_set_show(p, &power_mode_sel_child_show);
    p->result = POWER_REBOOT;
    assert_if_fail(menuNode_init(p) != NULL);
    return p;
}

struct _menuUnit * power_poweroff_ui_init()
{
    struct _menuUnit *p = common_ui_init();
    return_null_if_fail(p != NULL);
    strncpy(p->name, "<~poweroff.name>", MENU_LEN);
    menuUnit_set_title(p, "<~power.title>");
    menuUnit_set_icon(p,"@power");
    menuUnit_set_show(p, &power_mode_sel_child_show);
    p->result = POWER_POWEROFF;
    assert_if_fail(menuNode_init(p) != NULL);
    return p;
}

struct _menuUnit * power_download_ui_init()
{
    struct _menuUnit *p = common_ui_init();
    return_null_if_fail(p != NULL);
    strncpy(p->name, "<~powerdownload.name>", MENU_LEN);
    menuUnit_set_title(p, "<~power.title>");
    menuUnit_set_icon(p,"@power");
    menuUnit_set_show(p, &power_mode_sel_child_show);
    p->result = POWER_BOOTLOADER;
    assert_if_fail(menuNode_init(p) != NULL);
    return p;
}

struct _menuUnit * power_recovery_ui_init()
{
    struct _menuUnit *p = common_ui_init();
    return_null_if_fail(p != NULL);
    strncpy(p->name, "<~powerrecovery.name>", MENU_LEN);
    menuUnit_set_title(p, "<~power.title>");
    menuUnit_set_icon(p,"@power");
    menuUnit_set_show(p, &power_mode_sel_child_show);
    p->result = POWER_RECOVERY;
    assert_if_fail(menuNode_init(p) != NULL);
    return p;
}

