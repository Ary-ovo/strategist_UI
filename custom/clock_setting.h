#ifndef __CLOCK_SETTING_H
#define __CLOCK_SETTING_H


#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

extern int clock_hour;
extern int clock_min;
extern int clock_sec;

void clock_anim(lv_ui *ui);
void clock_count(int * hour, int * minute, int * seconds);
void clock_timer(lv_timer_t *timer);

#ifdef __cplusplus
}
#endif

#endif /* __CLOCK_SETTING_H */
