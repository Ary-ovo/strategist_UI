/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_background;
	lv_obj_t *screen_homekit;
	lv_obj_t *screen_home_background;
	lv_obj_t *screen_liv_light_on;
	lv_obj_t *screen_bal1_light1;
	lv_obj_t *screen_bal_light2;
	lv_obj_t *screen_bathroom_light;
	lv_obj_t *screen_mr_light1;
	lv_obj_t *screen_mr_light2;
	lv_obj_t *screen_mb_light;
	lv_obj_t *screen_cor_light2;
	lv_obj_t *screen_cor_light1;
	lv_obj_t *screen_kitc_light;
	lv_obj_t *screen_dt_light;
	lv_obj_t *screen_gr_light;
	lv_obj_t *screen_sr_light;
	lv_obj_t *screen_liv_light_btn;
	lv_obj_t *screen_liv_light_btn_label;
	lv_obj_t *screen_mr_light_bnt1;
	lv_obj_t *screen_mr_light_bnt1_label;
	lv_obj_t *screen_mr_light_bnt2;
	lv_obj_t *screen_mr_light_bnt2_label;
	lv_obj_t *screen_sr_light_btn;
	lv_obj_t *screen_sr_light_btn_label;
	lv_obj_t *screen_mb_btn;
	lv_obj_t *screen_mb_btn_label;
	lv_obj_t *screen_dt_light_btn;
	lv_obj_t *screen_dt_light_btn_label;
	lv_obj_t *screen_br_light_btn;
	lv_obj_t *screen_br_light_btn_label;
	lv_obj_t *screen_bal1_light_btn;
	lv_obj_t *screen_bal1_light_btn_label;
	lv_obj_t *screen_bal2_light_btn;
	lv_obj_t *screen_bal2_light_btn_label;
	lv_obj_t *screen_gr_light_btn;
	lv_obj_t *screen_gr_light_btn_label;
	lv_obj_t *screen_cor2_light_btn;
	lv_obj_t *screen_cor2_light_btn_label;
	lv_obj_t *screen_cor1_light_btn;
	lv_obj_t *screen_cor1_light_btn_label;
	lv_obj_t *screen_kitc_light_btn;
	lv_obj_t *screen_kitc_light_btn_label;
	lv_obj_t *screen_widgets;
	lv_obj_t *screen_clock;
	lv_obj_t *screen_hour_ten;
	lv_obj_t *screen_hour_per;
	lv_obj_t *screen_min_ten;
	lv_obj_t *screen_min_per;
	lv_obj_t *screen_semicolon;
	lv_obj_t *screen_sec_cont;
	lv_obj_t *screen_sec_per;
	lv_obj_t *screen_sec_ten;
	lv_obj_t *screen_humidity;
	lv_obj_t *screen_week;
	lv_span_t *screen_week_span;
	lv_obj_t *screen_temperature;
	lv_obj_t *screen_date;
	lv_span_t *screen_date_span;
	lv_obj_t *screen_humi_label;
	lv_obj_t *screen_tem_label;
	lv_obj_t *screen_weather_icon;
	lv_obj_t *screen_future_wea_con;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_img_2;
	lv_obj_t *screen_img_1;
	lv_obj_t *screen_label_2;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_moon_background_alpha_1024x600);
LV_IMG_DECLARE(_background_alpha_658x540);
LV_IMG_DECLARE(_living_room_alpha_272x290);
LV_IMG_DECLARE(_Balcony1_alpha_180x112);
LV_IMG_DECLARE(_Balcony2_alpha_221x165);
LV_IMG_DECLARE(_bathroom_alpha_111x100);
LV_IMG_DECLARE(_Master_Bedroom2_alpha_214x235);
LV_IMG_DECLARE(_Master_Bedroom1_alpha_184x185);
LV_IMG_DECLARE(_Master_Bathroom_alpha_110x163);
LV_IMG_DECLARE(_Corridor2_alpha_168x81);
LV_IMG_DECLARE(_Corridor1_alpha_197x109);
LV_IMG_DECLARE(_kitchen_alpha_186x155);
LV_IMG_DECLARE(_dining_table_alpha_205x218);
LV_IMG_DECLARE(_Guest_bedroom_alpha_141x156);
LV_IMG_DECLARE(_Second_Bedroom_alpha_181x189);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_light_off_alpha_48x48);
LV_IMG_DECLARE(_light_on_alpha_48x48);
LV_IMG_DECLARE(_humidity_alpha_48x48);
LV_IMG_DECLARE(_temperature_alpha_48x48);
#define LV_LOT_DECLARE(array_name) extern const uint8_t array_name[];
LV_LOT_DECLARE(lottie_yu);
LV_IMG_DECLARE(_humi_inside_alpha_48x48);
LV_IMG_DECLARE(_temp_inside_alpha_48x48);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_youshebiaotihei_80)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_youshebiaotihei_40)
LV_FONT_DECLARE(lv_font_punk_45)
LV_FONT_DECLARE(lv_font_punk_30)
LV_FONT_DECLARE(lv_font_youshebiaotihei_30)


#ifdef __cplusplus
}
#endif
#endif
