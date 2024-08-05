/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 1024, 600);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_background
	ui->screen_background = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_background, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_background, &_moon_background_alpha_1024x600);
	lv_img_set_pivot(ui->screen_background, 50,50);
	lv_img_set_angle(ui->screen_background, 0);
	lv_obj_set_pos(ui->screen_background, 0, 0);
	lv_obj_set_size(ui->screen_background, 1024, 600);

	//Write style for screen_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_background, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_background, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_homekit
	ui->screen_homekit = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_homekit, 360, 30);
	lv_obj_set_size(ui->screen_homekit, 658, 540);
	lv_obj_set_scrollbar_mode(ui->screen_homekit, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_homekit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_homekit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_homekit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_homekit, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_homekit, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_homekit, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_homekit, 129, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_homekit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_homekit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_homekit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_homekit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_homekit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_homekit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_homekit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_background
	ui->screen_home_background = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_home_background, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_home_background, &_background_alpha_658x540);
	lv_img_set_pivot(ui->screen_home_background, 50,50);
	lv_img_set_angle(ui->screen_home_background, 0);
	lv_obj_set_pos(ui->screen_home_background, 0, 0);
	lv_obj_set_size(ui->screen_home_background, 658, 540);

	//Write style for screen_home_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_home_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_home_background, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_home_background, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_liv_light_on
	ui->screen_liv_light_on = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_liv_light_on, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_liv_light_on, &_living_room_alpha_272x290);
	lv_img_set_pivot(ui->screen_liv_light_on, 50,50);
	lv_img_set_angle(ui->screen_liv_light_on, 0);
	lv_obj_set_pos(ui->screen_liv_light_on, 279, 194);
	lv_obj_set_size(ui->screen_liv_light_on, 272, 290);
	lv_obj_add_flag(ui->screen_liv_light_on, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_liv_light_on, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_liv_light_on, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_liv_light_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_liv_light_on, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_liv_light_on, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bal1_light1
	ui->screen_bal1_light1 = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_bal1_light1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_bal1_light1, &_Balcony1_alpha_180x112);
	lv_img_set_pivot(ui->screen_bal1_light1, 50,50);
	lv_img_set_angle(ui->screen_bal1_light1, 0);
	lv_obj_set_pos(ui->screen_bal1_light1, 308, 0);
	lv_obj_set_size(ui->screen_bal1_light1, 180, 112);
	lv_obj_add_flag(ui->screen_bal1_light1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_bal1_light1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_bal1_light1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_bal1_light1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bal1_light1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_bal1_light1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bal_light2
	ui->screen_bal_light2 = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_bal_light2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_bal_light2, &_Balcony2_alpha_221x165);
	lv_img_set_pivot(ui->screen_bal_light2, 50,50);
	lv_img_set_angle(ui->screen_bal_light2, 0);
	lv_obj_set_pos(ui->screen_bal_light2, 308, 375);
	lv_obj_set_size(ui->screen_bal_light2, 221, 165);
	lv_obj_add_flag(ui->screen_bal_light2, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_bal_light2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_bal_light2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_bal_light2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bal_light2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_bal_light2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bathroom_light
	ui->screen_bathroom_light = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_bathroom_light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_bathroom_light, &_bathroom_alpha_111x100);
	lv_img_set_pivot(ui->screen_bathroom_light, 50,50);
	lv_img_set_angle(ui->screen_bathroom_light, 0);
	lv_obj_set_pos(ui->screen_bathroom_light, 228, 68);
	lv_obj_set_size(ui->screen_bathroom_light, 111, 100);
	lv_obj_add_flag(ui->screen_bathroom_light, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_bathroom_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_bathroom_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_bathroom_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bathroom_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_bathroom_light, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_mr_light1
	ui->screen_mr_light1 = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_mr_light1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_mr_light1, &_Master_Bedroom2_alpha_214x235);
	lv_img_set_pivot(ui->screen_mr_light1, 50,50);
	lv_img_set_angle(ui->screen_mr_light1, 0);
	lv_obj_set_pos(ui->screen_mr_light1, -11, 194);
	lv_obj_set_size(ui->screen_mr_light1, 214, 235);
	lv_obj_add_flag(ui->screen_mr_light1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_mr_light1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_mr_light1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_mr_light1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_mr_light1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_mr_light1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_mr_light2
	ui->screen_mr_light2 = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_mr_light2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_mr_light2, &_Master_Bedroom1_alpha_184x185);
	lv_img_set_pivot(ui->screen_mr_light2, 50,50);
	lv_img_set_angle(ui->screen_mr_light2, 0);
	lv_obj_set_pos(ui->screen_mr_light2, 156, 245);
	lv_obj_set_size(ui->screen_mr_light2, 184, 185);
	lv_obj_add_flag(ui->screen_mr_light2, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_mr_light2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_mr_light2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_mr_light2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_mr_light2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_mr_light2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_mb_light
	ui->screen_mb_light = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_mb_light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_mb_light, &_Master_Bathroom_alpha_110x163);
	lv_img_set_pivot(ui->screen_mb_light, 50,50);
	lv_img_set_angle(ui->screen_mb_light, 0);
	lv_obj_set_pos(ui->screen_mb_light, -8, 53);
	lv_obj_set_size(ui->screen_mb_light, 110, 163);
	lv_obj_add_flag(ui->screen_mb_light, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_mb_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_mb_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_mb_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_mb_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_mb_light, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cor_light2
	ui->screen_cor_light2 = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_cor_light2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_cor_light2, &_Corridor2_alpha_168x81);
	lv_img_set_pivot(ui->screen_cor_light2, 50,50);
	lv_img_set_angle(ui->screen_cor_light2, 0);
	lv_obj_set_pos(ui->screen_cor_light2, 167, 192);
	lv_obj_set_size(ui->screen_cor_light2, 168, 81);
	lv_obj_add_flag(ui->screen_cor_light2, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_cor_light2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_cor_light2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_cor_light2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cor_light2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_cor_light2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cor_light1
	ui->screen_cor_light1 = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_cor_light1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_cor_light1, &_Corridor1_alpha_197x109);
	lv_img_set_pivot(ui->screen_cor_light1, 50,50);
	lv_img_set_angle(ui->screen_cor_light1, 0);
	lv_obj_set_pos(ui->screen_cor_light1, 466, 177);
	lv_obj_set_size(ui->screen_cor_light1, 197, 109);
	lv_obj_add_flag(ui->screen_cor_light1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_cor_light1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_cor_light1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_cor_light1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cor_light1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_cor_light1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_kitc_light
	ui->screen_kitc_light = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_kitc_light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_kitc_light, &_kitchen_alpha_186x155);
	lv_img_set_pivot(ui->screen_kitc_light, 50,50);
	lv_img_set_angle(ui->screen_kitc_light, 0);
	lv_obj_set_pos(ui->screen_kitc_light, 419, 48);
	lv_obj_set_size(ui->screen_kitc_light, 186, 155);
	lv_obj_add_flag(ui->screen_kitc_light, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_kitc_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_kitc_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_kitc_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_kitc_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_kitc_light, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_dt_light
	ui->screen_dt_light = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_dt_light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_dt_light, &_dining_table_alpha_205x218);
	lv_img_set_pivot(ui->screen_dt_light, 50,50);
	lv_img_set_angle(ui->screen_dt_light, 0);
	lv_obj_set_pos(ui->screen_dt_light, 310, 58);
	lv_obj_set_size(ui->screen_dt_light, 205, 218);
	lv_obj_add_flag(ui->screen_dt_light, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_dt_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_dt_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_dt_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_dt_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_dt_light, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gr_light
	ui->screen_gr_light = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_gr_light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_gr_light, &_Guest_bedroom_alpha_141x156);
	lv_img_set_pivot(ui->screen_gr_light, 50,50);
	lv_img_set_angle(ui->screen_gr_light, 0);
	lv_obj_set_pos(ui->screen_gr_light, 512, 255);
	lv_obj_set_size(ui->screen_gr_light, 141, 156);
	lv_obj_add_flag(ui->screen_gr_light, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_gr_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_gr_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_gr_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gr_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_gr_light, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sr_light
	ui->screen_sr_light = lv_img_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_sr_light, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_sr_light, &_Second_Bedroom_alpha_181x189);
	lv_img_set_pivot(ui->screen_sr_light, 50,50);
	lv_img_set_angle(ui->screen_sr_light, 0);
	lv_obj_set_pos(ui->screen_sr_light, 71, 26);
	lv_obj_set_size(ui->screen_sr_light, 181, 189);
	lv_obj_add_flag(ui->screen_sr_light, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_sr_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_sr_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_sr_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sr_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_sr_light, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_liv_light_btn
	ui->screen_liv_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_liv_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_liv_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_liv_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_liv_light_btn_label = lv_label_create(ui->screen_liv_light_btn);
	lv_label_set_text(ui->screen_liv_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_liv_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_liv_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_liv_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_liv_light_btn, 400, 315);
	lv_obj_set_size(ui->screen_liv_light_btn, 48, 48);

	//Write style for screen_liv_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_liv_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_liv_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_liv_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_liv_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_liv_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_liv_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_liv_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_liv_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_liv_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_liv_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_liv_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_liv_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_liv_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_liv_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_liv_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_liv_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_liv_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_liv_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_liv_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_liv_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_liv_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_liv_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_liv_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_liv_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_mr_light_bnt1
	ui->screen_mr_light_bnt1 = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_mr_light_bnt1, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_mr_light_bnt1, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_mr_light_bnt1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_mr_light_bnt1_label = lv_label_create(ui->screen_mr_light_bnt1);
	lv_label_set_text(ui->screen_mr_light_bnt1_label, "");
	lv_label_set_long_mode(ui->screen_mr_light_bnt1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_mr_light_bnt1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_mr_light_bnt1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_mr_light_bnt1, 100, 300);
	lv_obj_set_size(ui->screen_mr_light_bnt1, 48, 48);

	//Write style for screen_mr_light_bnt1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_mr_light_bnt1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_mr_light_bnt1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_mr_light_bnt1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_mr_light_bnt1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_mr_light_bnt1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_mr_light_bnt1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_mr_light_bnt1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_mr_light_bnt1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_mr_light_bnt1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_mr_light_bnt1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_mr_light_bnt1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_mr_light_bnt1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_mr_light_bnt1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_mr_light_bnt1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_mr_light_bnt1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_mr_light_bnt1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_mr_light_bnt1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_mr_light_bnt1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_mr_light_bnt1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_mr_light_bnt1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_mr_light_bnt1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_mr_light_bnt1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_mr_light_bnt1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_mr_light_bnt1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_mr_light_bnt2
	ui->screen_mr_light_bnt2 = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_mr_light_bnt2, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_mr_light_bnt2, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_mr_light_bnt2, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_mr_light_bnt2_label = lv_label_create(ui->screen_mr_light_bnt2);
	lv_label_set_text(ui->screen_mr_light_bnt2_label, "");
	lv_label_set_long_mode(ui->screen_mr_light_bnt2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_mr_light_bnt2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_mr_light_bnt2, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_mr_light_bnt2, 220, 320);
	lv_obj_set_size(ui->screen_mr_light_bnt2, 48, 48);

	//Write style for screen_mr_light_bnt2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_mr_light_bnt2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_mr_light_bnt2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_mr_light_bnt2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_mr_light_bnt2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_mr_light_bnt2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_mr_light_bnt2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_mr_light_bnt2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_mr_light_bnt2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_mr_light_bnt2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_mr_light_bnt2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_mr_light_bnt2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_mr_light_bnt2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_mr_light_bnt2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_mr_light_bnt2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_mr_light_bnt2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_mr_light_bnt2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_mr_light_bnt2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_mr_light_bnt2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_mr_light_bnt2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_mr_light_bnt2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_mr_light_bnt2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_mr_light_bnt2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_mr_light_bnt2, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_mr_light_bnt2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_sr_light_btn
	ui->screen_sr_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_sr_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_sr_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_sr_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_sr_light_btn_label = lv_label_create(ui->screen_sr_light_btn);
	lv_label_set_text(ui->screen_sr_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_sr_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_sr_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_sr_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_sr_light_btn, 160, 110);
	lv_obj_set_size(ui->screen_sr_light_btn, 48, 48);

	//Write style for screen_sr_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_sr_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sr_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sr_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sr_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sr_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_sr_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sr_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_sr_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_sr_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_sr_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_sr_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_sr_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_sr_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_sr_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_sr_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_sr_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_sr_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_sr_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_sr_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_sr_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_sr_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_sr_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_sr_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_sr_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_mb_btn
	ui->screen_mb_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_mb_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_mb_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_mb_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_mb_btn_label = lv_label_create(ui->screen_mb_btn);
	lv_label_set_text(ui->screen_mb_btn_label, "");
	lv_label_set_long_mode(ui->screen_mb_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_mb_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_mb_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_mb_btn, 25, 120);
	lv_obj_set_size(ui->screen_mb_btn, 48, 48);

	//Write style for screen_mb_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_mb_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_mb_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_mb_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_mb_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_mb_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_mb_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_mb_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_mb_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_mb_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_mb_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_mb_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_mb_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_mb_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_mb_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_mb_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_mb_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_mb_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_mb_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_mb_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_mb_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_mb_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_mb_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_mb_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_mb_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_dt_light_btn
	ui->screen_dt_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_dt_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_dt_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_dt_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_dt_light_btn_label = lv_label_create(ui->screen_dt_light_btn);
	lv_label_set_text(ui->screen_dt_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_dt_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_dt_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_dt_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_dt_light_btn, 380, 120);
	lv_obj_set_size(ui->screen_dt_light_btn, 48, 48);

	//Write style for screen_dt_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_dt_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_dt_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_dt_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_dt_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_dt_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_dt_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_dt_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_dt_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_dt_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_dt_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_dt_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_dt_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_dt_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_dt_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_dt_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_dt_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_dt_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_dt_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_dt_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_dt_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_dt_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_dt_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_dt_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_dt_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_br_light_btn
	ui->screen_br_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_br_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_br_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_br_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_br_light_btn_label = lv_label_create(ui->screen_br_light_btn);
	lv_label_set_text(ui->screen_br_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_br_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_br_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_br_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_br_light_btn, 260, 120);
	lv_obj_set_size(ui->screen_br_light_btn, 48, 48);

	//Write style for screen_br_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_br_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_br_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_br_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_br_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_br_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_br_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_br_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_br_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_br_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_br_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_br_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_br_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_br_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_br_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_br_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_br_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_br_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_br_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_br_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_br_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_br_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_br_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_br_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_br_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_bal1_light_btn
	ui->screen_bal1_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_bal1_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_bal1_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_bal1_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_bal1_light_btn_label = lv_label_create(ui->screen_bal1_light_btn);
	lv_label_set_text(ui->screen_bal1_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_bal1_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_bal1_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_bal1_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_bal1_light_btn, 380, 40);
	lv_obj_set_size(ui->screen_bal1_light_btn, 48, 48);

	//Write style for screen_bal1_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_bal1_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bal1_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_bal1_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bal1_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bal1_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_bal1_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bal1_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_bal1_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_bal1_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_bal1_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_bal1_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_bal1_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_bal1_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_bal1_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_bal1_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_bal1_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_bal1_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_bal1_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_bal1_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_bal1_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_bal1_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_bal1_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_bal1_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_bal1_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_bal2_light_btn
	ui->screen_bal2_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_bal2_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_bal2_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_bal2_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_bal2_light_btn_label = lv_label_create(ui->screen_bal2_light_btn);
	lv_label_set_text(ui->screen_bal2_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_bal2_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_bal2_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_bal2_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_bal2_light_btn, 400, 450);
	lv_obj_set_size(ui->screen_bal2_light_btn, 48, 48);

	//Write style for screen_bal2_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_bal2_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bal2_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_bal2_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bal2_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bal2_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_bal2_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bal2_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_bal2_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_bal2_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_bal2_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_bal2_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_bal2_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_bal2_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_bal2_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_bal2_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_bal2_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_bal2_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_bal2_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_bal2_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_bal2_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_bal2_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_bal2_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_bal2_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_bal2_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_gr_light_btn
	ui->screen_gr_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_gr_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_gr_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_gr_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_gr_light_btn_label = lv_label_create(ui->screen_gr_light_btn);
	lv_label_set_text(ui->screen_gr_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_gr_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_gr_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_gr_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_gr_light_btn, 550, 320);
	lv_obj_set_size(ui->screen_gr_light_btn, 48, 48);

	//Write style for screen_gr_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_gr_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gr_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_gr_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gr_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gr_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_gr_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gr_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_gr_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_gr_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_gr_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_gr_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_gr_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_gr_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_gr_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_gr_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_gr_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_gr_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_gr_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_gr_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_gr_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_gr_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_gr_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_gr_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_gr_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cor2_light_btn
	ui->screen_cor2_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_cor2_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_cor2_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_cor2_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_cor2_light_btn_label = lv_label_create(ui->screen_cor2_light_btn);
	lv_label_set_text(ui->screen_cor2_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_cor2_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_cor2_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_cor2_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_cor2_light_btn, 250, 210);
	lv_obj_set_size(ui->screen_cor2_light_btn, 48, 48);

	//Write style for screen_cor2_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_cor2_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cor2_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cor2_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cor2_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cor2_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_cor2_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cor2_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_cor2_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_cor2_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_cor2_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_cor2_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_cor2_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_cor2_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_cor2_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_cor2_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_cor2_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_cor2_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_cor2_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_cor2_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_cor2_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_cor2_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_cor2_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_cor2_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_cor2_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cor1_light_btn
	ui->screen_cor1_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_cor1_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_cor1_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_cor1_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_cor1_light_btn_label = lv_label_create(ui->screen_cor1_light_btn);
	lv_label_set_text(ui->screen_cor1_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_cor1_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_cor1_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_cor1_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_cor1_light_btn, 550, 200);
	lv_obj_set_size(ui->screen_cor1_light_btn, 48, 48);

	//Write style for screen_cor1_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_cor1_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_cor1_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_cor1_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_cor1_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cor1_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_cor1_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cor1_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_cor1_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_cor1_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_cor1_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_cor1_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_cor1_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_cor1_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_cor1_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_cor1_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_cor1_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_cor1_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_cor1_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_cor1_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_cor1_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_cor1_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_cor1_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_cor1_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_cor1_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_kitc_light_btn
	ui->screen_kitc_light_btn = lv_imgbtn_create(ui->screen_homekit);
	lv_obj_add_flag(ui->screen_kitc_light_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_kitc_light_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_light_off_alpha_48x48, NULL);
	lv_imgbtn_set_src(ui->screen_kitc_light_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_light_on_alpha_48x48, NULL);
	ui->screen_kitc_light_btn_label = lv_label_create(ui->screen_kitc_light_btn);
	lv_label_set_text(ui->screen_kitc_light_btn_label, "");
	lv_label_set_long_mode(ui->screen_kitc_light_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_kitc_light_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_kitc_light_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_kitc_light_btn, 500, 110);
	lv_obj_set_size(ui->screen_kitc_light_btn, 48, 48);

	//Write style for screen_kitc_light_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_kitc_light_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_kitc_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_kitc_light_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_kitc_light_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_kitc_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_kitc_light_btn, true, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_kitc_light_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_kitc_light_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_recolor_opa(ui->screen_kitc_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->screen_kitc_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_kitc_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_kitc_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_kitc_light_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_kitc_light_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_kitc_light_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_recolor_opa(ui->screen_kitc_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->screen_kitc_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_kitc_light_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_kitc_light_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_kitc_light_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_kitc_light_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_kitc_light_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_recolor_opa(ui->screen_kitc_light_btn, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
	lv_obj_set_style_img_opa(ui->screen_kitc_light_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_widgets
	ui->screen_widgets = lv_obj_create(ui->screen);
	lv_obj_set_pos(ui->screen_widgets, 15, 30);
	lv_obj_set_size(ui->screen_widgets, 330, 540);
	lv_obj_set_scrollbar_mode(ui->screen_widgets, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_widgets, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_widgets, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_widgets, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_widgets, lv_color_hex(0xABABAB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_widgets, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_widgets, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_widgets, 129, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_widgets, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_widgets, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_widgets, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_widgets, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_widgets, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_widgets, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_widgets, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_clock
	ui->screen_clock = lv_obj_create(ui->screen_widgets);
	lv_obj_set_pos(ui->screen_clock, 15, 5);
	lv_obj_set_size(ui->screen_clock, 300, 80);
	lv_obj_set_scrollbar_mode(ui->screen_clock, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_hour_ten
	ui->screen_hour_ten = lv_label_create(ui->screen_clock);
	lv_label_set_text(ui->screen_hour_ten, "22");
	lv_label_set_long_mode(ui->screen_hour_ten, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_hour_ten, 10, 0);
	lv_obj_set_size(ui->screen_hour_ten, 50, 160);

	//Write style for screen_hour_ten, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_hour_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_hour_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_hour_ten, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_hour_ten, &lv_font_youshebiaotihei_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_hour_ten, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_hour_ten, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_hour_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_hour_ten, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_hour_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_hour_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_hour_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_hour_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_hour_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_hour_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_hour_per
	ui->screen_hour_per = lv_label_create(ui->screen_clock);
	lv_label_set_text(ui->screen_hour_per, "22");
	lv_label_set_long_mode(ui->screen_hour_per, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_hour_per, 60, 0);
	lv_obj_set_size(ui->screen_hour_per, 50, 160);

	//Write style for screen_hour_per, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_hour_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_hour_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_hour_per, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_hour_per, &lv_font_youshebiaotihei_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_hour_per, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_hour_per, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_hour_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_hour_per, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_hour_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_hour_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_hour_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_hour_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_hour_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_hour_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_min_ten
	ui->screen_min_ten = lv_label_create(ui->screen_clock);
	lv_label_set_text(ui->screen_min_ten, "33");
	lv_label_set_long_mode(ui->screen_min_ten, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_min_ten, 140, 0);
	lv_obj_set_size(ui->screen_min_ten, 50, 180);

	//Write style for screen_min_ten, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_min_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_min_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_min_ten, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_min_ten, &lv_font_youshebiaotihei_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_min_ten, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_min_ten, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_min_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_min_ten, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_min_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_min_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_min_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_min_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_min_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_min_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_min_per
	ui->screen_min_per = lv_label_create(ui->screen_clock);
	lv_label_set_text(ui->screen_min_per, "00");
	lv_label_set_long_mode(ui->screen_min_per, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_min_per, 190, 0);
	lv_obj_set_size(ui->screen_min_per, 50, 160);

	//Write style for screen_min_per, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_min_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_min_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_min_per, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_min_per, &lv_font_youshebiaotihei_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_min_per, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_min_per, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_min_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_min_per, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_min_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_min_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_min_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_min_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_min_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_min_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_semicolon
	ui->screen_semicolon = lv_label_create(ui->screen_clock);
	lv_label_set_text(ui->screen_semicolon, ":\n");
	lv_label_set_long_mode(ui->screen_semicolon, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_semicolon, 105, -5);
	lv_obj_set_size(ui->screen_semicolon, 50, 80);

	//Write style for screen_semicolon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_semicolon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_semicolon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_semicolon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_semicolon, &lv_font_youshebiaotihei_80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_semicolon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_semicolon, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_semicolon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_semicolon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_semicolon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_semicolon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_semicolon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_semicolon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_semicolon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_semicolon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sec_cont
	ui->screen_sec_cont = lv_obj_create(ui->screen_clock);
	lv_obj_set_pos(ui->screen_sec_cont, 240, 35);
	lv_obj_set_size(ui->screen_sec_cont, 60, 30);
	lv_obj_set_scrollbar_mode(ui->screen_sec_cont, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_sec_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_sec_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sec_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sec_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sec_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_sec_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sec_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sec_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sec_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sec_per
	ui->screen_sec_per = lv_label_create(ui->screen_sec_cont);
	lv_label_set_text(ui->screen_sec_per, "12");
	lv_label_set_long_mode(ui->screen_sec_per, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_sec_per, 25, -5);
	lv_obj_set_size(ui->screen_sec_per, 40, 80);

	//Write style for screen_sec_per, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_sec_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sec_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_sec_per, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sec_per, &lv_font_youshebiaotihei_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sec_per, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_sec_per, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_sec_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sec_per, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sec_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sec_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sec_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_sec_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sec_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sec_per, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sec_ten
	ui->screen_sec_ten = lv_label_create(ui->screen_sec_cont);
	lv_label_set_text(ui->screen_sec_ten, "12");
	lv_label_set_long_mode(ui->screen_sec_ten, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_sec_ten, -5, -5);
	lv_obj_set_size(ui->screen_sec_ten, 40, 80);

	//Write style for screen_sec_ten, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_sec_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sec_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_sec_ten, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sec_ten, &lv_font_youshebiaotihei_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sec_ten, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_sec_ten, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_sec_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sec_ten, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sec_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sec_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sec_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_sec_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sec_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sec_ten, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_humidity
	ui->screen_humidity = lv_img_create(ui->screen_widgets);
	lv_obj_add_flag(ui->screen_humidity, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_humidity, &_humidity_alpha_48x48);
	lv_img_set_pivot(ui->screen_humidity, 50,50);
	lv_img_set_angle(ui->screen_humidity, 0);
	lv_obj_set_pos(ui->screen_humidity, 20, 80);
	lv_obj_set_size(ui->screen_humidity, 48, 48);

	//Write style for screen_humidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_humidity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_humidity, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_week
	ui->screen_week = lv_spangroup_create(ui->screen_widgets);
	lv_spangroup_set_align(ui->screen_week, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_week, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_week, LV_SPAN_MODE_BREAK);
	//create span 
	ui->screen_week_span = lv_spangroup_new_span(ui->screen_week);
	lv_span_set_text(ui->screen_week_span, "星期");
	lv_style_set_text_color(&ui->screen_week_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->screen_week_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->screen_week_span->style, &lv_font_punk_45);
	ui->screen_week_span = lv_spangroup_new_span(ui->screen_week);
	lv_span_set_text(ui->screen_week_span, "六");
	lv_style_set_text_color(&ui->screen_week_span->style, lv_color_hex(0x2F35DA));
	lv_style_set_text_decor(&ui->screen_week_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->screen_week_span->style, &lv_font_punk_45);
	lv_obj_set_pos(ui->screen_week, 90, 250);
	lv_obj_set_size(ui->screen_week, 140, 45);

	//Write style state: LV_STATE_DEFAULT for &style_screen_week_main_main_default
	static lv_style_t style_screen_week_main_main_default;
	ui_init_style(&style_screen_week_main_main_default);
	
	lv_style_set_border_width(&style_screen_week_main_main_default, 0);
	lv_style_set_radius(&style_screen_week_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_week_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_week_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_week_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_week_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_week_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_week_main_main_default, 0);
	lv_obj_add_style(ui->screen_week, &style_screen_week_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_week);

	//Write codes screen_temperature
	ui->screen_temperature = lv_img_create(ui->screen_widgets);
	lv_obj_add_flag(ui->screen_temperature, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_temperature, &_temperature_alpha_48x48);
	lv_img_set_pivot(ui->screen_temperature, 50,50);
	lv_img_set_angle(ui->screen_temperature, 0);
	lv_obj_set_pos(ui->screen_temperature, 20, 140);
	lv_obj_set_size(ui->screen_temperature, 48, 48);

	//Write style for screen_temperature, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_temperature, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_temperature, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_date
	ui->screen_date = lv_spangroup_create(ui->screen_widgets);
	lv_spangroup_set_align(ui->screen_date, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_date, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_date, LV_SPAN_MODE_BREAK);
	//create span 
	ui->screen_date_span = lv_spangroup_new_span(ui->screen_date);
	lv_span_set_text(ui->screen_date_span, "2024");
	lv_style_set_text_color(&ui->screen_date_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->screen_date_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->screen_date_span->style, &lv_font_punk_30);
	ui->screen_date_span = lv_spangroup_new_span(ui->screen_date);
	lv_span_set_text(ui->screen_date_span, "年");
	lv_style_set_text_color(&ui->screen_date_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->screen_date_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->screen_date_span->style, &lv_font_punk_30);
	ui->screen_date_span = lv_spangroup_new_span(ui->screen_date);
	lv_span_set_text(ui->screen_date_span, "7");
	lv_style_set_text_color(&ui->screen_date_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->screen_date_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->screen_date_span->style, &lv_font_punk_30);
	ui->screen_date_span = lv_spangroup_new_span(ui->screen_date);
	lv_span_set_text(ui->screen_date_span, "月");
	lv_style_set_text_color(&ui->screen_date_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->screen_date_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->screen_date_span->style, &lv_font_punk_30);
	ui->screen_date_span = lv_spangroup_new_span(ui->screen_date);
	lv_span_set_text(ui->screen_date_span, "28");
	lv_style_set_text_color(&ui->screen_date_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->screen_date_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->screen_date_span->style, &lv_font_punk_30);
	ui->screen_date_span = lv_spangroup_new_span(ui->screen_date);
	lv_span_set_text(ui->screen_date_span, "日");
	lv_style_set_text_color(&ui->screen_date_span->style, lv_color_hex(0x000000));
	lv_style_set_text_decor(&ui->screen_date_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&ui->screen_date_span->style, &lv_font_punk_30);
	lv_obj_set_pos(ui->screen_date, 40, 205);
	lv_obj_set_size(ui->screen_date, 246, 30);

	//Write style state: LV_STATE_DEFAULT for &style_screen_date_main_main_default
	static lv_style_t style_screen_date_main_main_default;
	ui_init_style(&style_screen_date_main_main_default);
	
	lv_style_set_border_width(&style_screen_date_main_main_default, 0);
	lv_style_set_radius(&style_screen_date_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_date_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_date_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_date_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_date_main_main_default, 0);
	lv_style_set_pad_left(&style_screen_date_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_date_main_main_default, 0);
	lv_obj_add_style(ui->screen_date, &style_screen_date_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_spangroup_refr_mode(ui->screen_date);

	//Write codes screen_humi_label
	ui->screen_humi_label = lv_label_create(ui->screen_widgets);
	lv_label_set_text(ui->screen_humi_label, "97%");
	lv_label_set_long_mode(ui->screen_humi_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_humi_label, 75, 90);
	lv_obj_set_size(ui->screen_humi_label, 80, 30);

	//Write style for screen_humi_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_humi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_humi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_humi_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_humi_label, &lv_font_youshebiaotihei_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_humi_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_humi_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_humi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_humi_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_humi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_humi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_humi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_humi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_humi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_humi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_tem_label
	ui->screen_tem_label = lv_label_create(ui->screen_widgets);
	lv_label_set_text(ui->screen_tem_label, "25°C");
	lv_label_set_long_mode(ui->screen_tem_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_tem_label, 75, 150);
	lv_obj_set_size(ui->screen_tem_label, 90, 30);

	//Write style for screen_tem_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_tem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_tem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_tem_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_tem_label, &lv_font_youshebiaotihei_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_tem_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_tem_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_tem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_tem_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_tem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_tem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_tem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_tem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_tem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_tem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_weather_icon
	ui->screen_weather_icon = lv_rlottie_create_from_raw(ui->screen_widgets, 150, 150, (const void *)lottie_yu);
	lv_obj_set_pos(ui->screen_weather_icon, 180, 55);
	lv_obj_set_size(ui->screen_weather_icon, 150, 150);

	//Write style for screen_weather_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_weather_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_future_wea_con
	ui->screen_future_wea_con = lv_obj_create(ui->screen_widgets);
	lv_obj_set_pos(ui->screen_future_wea_con, 25, 300);
	lv_obj_set_size(ui->screen_future_wea_con, 280, 100);
	lv_obj_set_scrollbar_mode(ui->screen_future_wea_con, LV_SCROLLBAR_MODE_ACTIVE);

	//Write style for screen_future_wea_con, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_future_wea_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_future_wea_con, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_future_wea_con, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_future_wea_con, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_future_wea_con, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_future_wea_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_future_wea_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_future_wea_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_future_wea_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_future_wea_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen_widgets);
	lv_label_set_text(ui->screen_label_1, "30°C");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_1, 75, 425);
	lv_obj_set_size(ui->screen_label_1, 90, 30);

	//Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_youshebiaotihei_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_1, 194, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_2
	ui->screen_img_2 = lv_img_create(ui->screen_widgets);
	lv_obj_add_flag(ui->screen_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_2, &_humi_inside_alpha_48x48);
	lv_img_set_pivot(ui->screen_img_2, 50,50);
	lv_img_set_angle(ui->screen_img_2, 0);
	lv_obj_set_pos(ui->screen_img_2, 15, 485);
	lv_obj_set_size(ui->screen_img_2, 48, 48);

	//Write style for screen_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_1
	ui->screen_img_1 = lv_img_create(ui->screen_widgets);
	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_1, &_temp_inside_alpha_48x48);
	lv_img_set_pivot(ui->screen_img_1, 50,50);
	lv_img_set_angle(ui->screen_img_1, 0);
	lv_obj_set_pos(ui->screen_img_1, 15, 415);
	lv_obj_set_size(ui->screen_img_1, 48, 48);

	//Write style for screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_recolor_opa(ui->screen_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_clip_corner(ui->screen_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen_widgets);
	lv_label_set_text(ui->screen_label_2, "68%");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_2, 75, 495);
	lv_obj_set_size(ui->screen_label_2, 90, 30);

	//Write style for screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_2, lv_color_hex(0x002bff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_2, &lv_font_youshebiaotihei_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_2, 194, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

}
