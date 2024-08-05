#include "clock_setting.h"
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "custom_event.h"

int clock_hour = 12;
int clock_min = 30;
int clock_sec = 30;

static lv_anim_t clock_anim_sec_per_load;
static lv_anim_t clock_anim_sec_ten_load;
static lv_anim_t clock_anim_min_per_load;
static lv_anim_t clock_anim_min_ten_load;
static lv_anim_t clock_anim_hour_per_load;
static lv_anim_t clock_anim_hour_ten_load;

/**
 * @brief           24小时制时钟走时
 * @param obj       pointer to the values for hour/minute/seconds and the bool value to select AM/PM
 * @return          selection end index. The function of lv_dclock_24_timer_cb will call it.
 */
void clock_count(int * hour, int * minute, int * seconds)
{
    (*seconds)++;
    lv_anim_start(&clock_anim_sec_per_load);
    if (*seconds %10 == 0)
    {
        lv_anim_start(&clock_anim_sec_ten_load);
    }
    
    if(*seconds == 60) {    /* 分加1 */
        *seconds = 0;
        (*minute)++;
        lv_anim_start(&clock_anim_min_per_load);    /* 当min++时，移动个位 */
        if (*minute%10 == 0)
        {
            lv_anim_start(&clock_anim_min_ten_load);/* 如果此时分满10，则移动十位 */
        }
    }

    if(*minute == 60) {
        *minute = 0;
        (*hour)++;
        lv_anim_start(&clock_anim_hour_per_load);
        if (*hour %10 ==0 )
        {
            lv_anim_start(&clock_anim_hour_ten_load);
        }
    }

    if(*hour == 24) {
        *hour = 0;
    }
}

static void anim_clock_past(void * var, int32_t v)
{
    lv_obj_set_y(var, v);   /* 将图像向上运动 */
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
/*动画结束后设置成下一个数字，obj回归原位*/
static void sec_per_anim_ready_cb(lv_anim_t* var)
{
    lv_label_set_text_fmt(guider_ui.screen_sec_per, "%1d%1d", clock_sec%10, (clock_sec+1)%10);
    lv_obj_set_y(guider_ui.screen_sec_per, -5);
}

static void sec_ten_anim_ready_cb(lv_anim_t* var)
{
    uint8_t sec_ten_now, sec_ten_next;
    sec_ten_now = clock_sec/10; sec_ten_next = clock_sec/10 +1;
    if( sec_ten_next == 6 ) sec_ten_next = 0;   /* 到5时下一个切换为0 */
    lv_label_set_text_fmt(guider_ui.screen_sec_ten, "%1d%1d", sec_ten_now, sec_ten_next);
    lv_obj_set_y(guider_ui.screen_sec_ten, -5);
}

static void min_per_anim_ready_cb(lv_anim_t* var)
{
    lv_label_set_text_fmt(guider_ui.screen_min_per, "%1d%1d", clock_min%10, (clock_min+1)%10);
    lv_obj_set_y(guider_ui.screen_min_per, 0);
}

static void min_ten_anim_ready_cb(lv_anim_t* var)
{
    uint8_t min_ten_now, min_ten_next;
    min_ten_now = clock_sec/10; min_ten_next = clock_sec/10 +1;
    if( min_ten_next == 6 ) min_ten_next = 0;   /* 到5时下一个切换为0 */
    lv_label_set_text_fmt(guider_ui.screen_min_ten, "%1d%1d", min_ten_now, min_ten_next);
    lv_obj_set_y(guider_ui.screen_min_ten, 0);
}

static void hour_per_anim_ready_cb(lv_anim_t* var)
{
    uint8_t hour_per_now, hour_per_next;
    hour_per_now = clock_hour%10; hour_per_next = (clock_hour+1)%10;
    if ( (clock_hour/10 == 2) && (hour_per_next == 4) )
    {
        hour_per_next = 0;
    }
    
    lv_label_set_text_fmt(guider_ui.screen_hour_per, "%1d%1d", hour_per_now, hour_per_next);
    lv_obj_set_y(guider_ui.screen_hour_per, 0);
}

static void hour_ten_anim_ready_cb(lv_anim_t* var)
{
    uint8_t hour_ten_now, hour_ten_next;
    hour_ten_now = clock_hour/10; hour_ten_next = clock_hour/10+1;
    if (hour_ten_next == 3) hour_ten_next = 0;
    lv_label_set_text_fmt(guider_ui.screen_hour_ten, "%1d%1d", hour_ten_now, hour_ten_next);
    lv_obj_set_y(guider_ui.screen_hour_ten, 0);
}
/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

/**
 * @brief 时钟要设置的时钟动画
 * 
 * @param ui 
 */
void clock_anim(lv_ui *ui)
{
    /* 秒个位 */
    lv_anim_init(&clock_anim_sec_per_load);
    lv_anim_set_var(&clock_anim_sec_per_load, ui->screen_sec_per);
    lv_anim_set_values(&clock_anim_sec_per_load, -5, -45);
    lv_anim_set_time(&clock_anim_sec_per_load, 500);
    lv_anim_set_path_cb(&clock_anim_sec_per_load, lv_anim_path_bounce);
    lv_anim_set_exec_cb(&clock_anim_sec_per_load, anim_clock_past);
    lv_anim_set_ready_cb(&clock_anim_sec_per_load, sec_per_anim_ready_cb);

    /* 秒十位 */
    lv_anim_init(&clock_anim_sec_ten_load);
    lv_anim_set_var(&clock_anim_sec_ten_load, ui->screen_sec_ten);
    lv_anim_set_values(&clock_anim_sec_ten_load, -5, -45);
    lv_anim_set_time(&clock_anim_sec_ten_load, 500);
    lv_anim_set_path_cb(&clock_anim_sec_ten_load, lv_anim_path_bounce);
    lv_anim_set_exec_cb(&clock_anim_sec_ten_load, anim_clock_past);
    lv_anim_set_ready_cb(&clock_anim_sec_ten_load, sec_ten_anim_ready_cb);

    /* 分个位 */
    lv_anim_init(&clock_anim_min_per_load);
    lv_anim_set_var(&clock_anim_min_per_load, ui->screen_min_per);
    lv_anim_set_values(&clock_anim_min_per_load, 0, -80);
    lv_anim_set_time(&clock_anim_min_per_load, 500);
    lv_anim_set_path_cb(&clock_anim_min_per_load, lv_anim_path_bounce);
    lv_anim_set_exec_cb(&clock_anim_min_per_load, anim_clock_past);
    lv_anim_set_ready_cb(&clock_anim_min_per_load, min_per_anim_ready_cb);

    /* 分十位 */
    lv_anim_init(&clock_anim_min_ten_load);
    lv_anim_set_var(&clock_anim_min_ten_load, ui->screen_min_ten);
    lv_anim_set_values(&clock_anim_min_ten_load, 0, -80);
    lv_anim_set_time(&clock_anim_min_ten_load, 500);
    lv_anim_set_path_cb(&clock_anim_min_ten_load, lv_anim_path_bounce);
    lv_anim_set_exec_cb(&clock_anim_min_ten_load, anim_clock_past);
    lv_anim_set_ready_cb(&clock_anim_min_ten_load, min_ten_anim_ready_cb);

    /* 时个位 */
    lv_anim_init(&clock_anim_hour_per_load);
    lv_anim_set_var(&clock_anim_hour_per_load, ui->screen_hour_per);
    lv_anim_set_values(&clock_anim_hour_per_load, 0, -80);
    lv_anim_set_time(&clock_anim_hour_per_load, 500);
    lv_anim_set_path_cb(&clock_anim_hour_per_load, lv_anim_path_bounce);
    lv_anim_set_exec_cb(&clock_anim_hour_per_load, anim_clock_past);
    lv_anim_set_ready_cb(&clock_anim_hour_per_load, hour_per_anim_ready_cb);

    /* 时十位 */
    lv_anim_init(&clock_anim_hour_ten_load);
    lv_anim_set_var(&clock_anim_hour_ten_load, ui->screen_hour_ten);
    lv_anim_set_values(&clock_anim_hour_ten_load, 0, -80);
    lv_anim_set_time(&clock_anim_hour_ten_load, 500);
    lv_anim_set_path_cb(&clock_anim_hour_ten_load, lv_anim_path_bounce);
    lv_anim_set_exec_cb(&clock_anim_hour_ten_load, anim_clock_past);
    lv_anim_set_ready_cb(&clock_anim_hour_ten_load, hour_ten_anim_ready_cb);
}


/**
 * @brief lvgl定时器任务，主要用于更新时间
 * 
 * @param timer 
 */
void clock_timer(lv_timer_t *timer)
{
    clock_count(&clock_hour, &clock_min, &clock_sec);
}
