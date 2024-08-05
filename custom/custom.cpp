/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "custom_event.h"
#include "clock_setting.h"
#include <time.h>
#include "filesystem.h"
#include <sys/time.h>
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
time_t t;
lv_obj_t *future_wea[24];
lv_obj_t *future_time[24];
lv_obj_t *future_temp[24];
/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

void future_wea_init(void)
{
    for (uint8_t i = 0; i < 24; i++)
    {
        future_wea[i] = lv_img_create(guider_ui.screen_future_wea_con);
        lv_img_set_src(future_wea[i], "S:/home/linxiaoyan/Downloads/yun.png");
        lv_obj_set_size(future_wea[i], 32, 32);
        lv_obj_align(future_wea[i], LV_ALIGN_LEFT_MID, 62*i, 0);

        future_time[i] = lv_label_create(guider_ui.screen_future_wea_con);
        lv_obj_set_style_text_font(future_time[i], &lv_font_montserratMedium_12, LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(future_time[i], lv_color_hex(0xFFFFFF), LV_STATE_DEFAULT);
        lv_label_set_text_fmt(future_time[i], "%d:00", 12+i);
        lv_obj_align_to(future_time[i], future_wea[i], LV_ALIGN_TOP_MID, 0, -20);

        future_temp[i] = lv_label_create(guider_ui.screen_future_wea_con);
        lv_obj_set_style_text_font(future_temp[i], &lv_font_montserratMedium_12, LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(future_temp[i], lv_color_hex(0xFFFFFF), LV_STATE_DEFAULT);
        lv_label_set_text_fmt(future_temp[i], "24°C");
        lv_obj_align_to(future_temp[i], future_wea[i], LV_ALIGN_BOTTOM_MID, 0, 20);
    }
}

/*
 *@brief 为lvgl提供心跳tick
 */
uint32_t sys_tick(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}

/**
 * Create a demo application
 */


void custom_init(lv_ui *ui)
{
    t = time(NULL);
    struct tm *dt = localtime(&t);

    clock_sec = dt->tm_sec;
    clock_min = dt->tm_min;
    clock_hour = dt->tm_hour;

    /* 取消容器的滚动效果 */
    lv_obj_clear_flag(ui->screen_widgets, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_clear_flag(ui->screen_homekit, LV_OBJ_FLAG_SCROLLABLE);

	/* 初始化添加的event */
    custom_event_init(ui);
    /* 初始化lvgl文件系统 */
    lv_port_fs_init();

    lv_font_t * yoush_24;
    yoush_24 = lv_font_load("S:/home/linxiaoyan/Downloads/yoush24.bin");

    clock_anim(ui);
    lv_timer_create(clock_timer, 1000, NULL);
    /* 初始化时钟信息，将同步的时间写到屏幕缓冲区 */
    lv_label_set_text_fmt(guider_ui.screen_sec_per, "%1d%1d", clock_sec%10, (clock_sec+1)%10);
    lv_label_set_text_fmt(guider_ui.screen_sec_ten, "%1d%1d", clock_sec/10, clock_sec/10 +1);

    lv_label_set_text_fmt(guider_ui.screen_min_per, "%1d%1d", clock_min%10, (clock_min+1)%10);
    lv_label_set_text_fmt(guider_ui.screen_min_ten, "%1d%1d", clock_min/10, clock_min/10 +1);

    lv_label_set_text_fmt(guider_ui.screen_hour_per, "%1d%1d", clock_hour%10, (clock_hour+1)%10);
    lv_label_set_text_fmt(guider_ui.screen_hour_ten, "%1d%1d", clock_hour/10, clock_hour/10+1);

    future_wea_init();

    lv_obj_t *advertise = lv_label_create(guider_ui.screen_widgets);
    lv_obj_set_style_text_font(advertise, yoush_24, LV_STATE_DEFAULT);
    lv_label_set_text_fmt(advertise, "广告招租,\n3块1天,\n10块3天");
    lv_obj_align(advertise, LV_ALIGN_BOTTOM_LEFT, 20, -36);

}



