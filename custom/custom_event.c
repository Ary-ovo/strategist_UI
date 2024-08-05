#include "custom_event.h"
#include <stdio.h>
#include "lvgl.h"

/**
 * @brief 客厅灯按钮开关事件处理
 * 
 * @param e 
 */
void liv_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_liv_light_on, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_liv_light_on, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_liv_light_on, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_liv_light_on, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 厨房灯按钮开关事件处理
 * 
 * @param e 
 */
void kitc_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_kitc_light, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_kitc_light, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_kitc_light, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_kitc_light, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 走廊灯1按钮开关事件处理
 * 
 * @param e 
 */
void cor1_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_cor_light1, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_cor_light1, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_cor_light1, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_cor_light1, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 客厅灯按钮开关事件处理
 * 
 * @param e 
 */
void cor2_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_cor_light2, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_cor_light2, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_cor_light2, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_cor_light2, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 客房灯按钮开关事件处理
 * 
 * @param e 
 */
void gr_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_gr_light, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_gr_light, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_gr_light, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_gr_light, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 客房灯按钮开关事件处理
 * 
 * @param e 
 */
void bal1_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_bal1_light1, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_bal1_light1, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_bal1_light1, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_bal1_light1, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 客房灯按钮开关事件处理
 * 
 * @param e 
 */
void bal2_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_bal_light2, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_bal_light2, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_bal_light2, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_bal_light2, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 客房灯按钮开关事件处理
 * 
 * @param e 
 */
void br_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_bathroom_light, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_bathroom_light, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_bathroom_light, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_bathroom_light, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 餐桌灯按钮开关事件处理
 * 
 * @param e 
 */
void dt_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_dt_light, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_dt_light, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_dt_light, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_dt_light, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 主卫灯按钮开关事件处理
 * 
 * @param e 
 */
void mb_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_mb_light, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_mb_light, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_mb_light, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_mb_light, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 次卧灯按钮开关事件处理
 * 
 * @param e 
 */
void sr_light_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_sr_light, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_sr_light, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_sr_light, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_sr_light, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 主卧灯1按钮开关事件处理
 * 
 * @param e 
 */
void mr_light1_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_mr_light1, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_mr_light1, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_mr_light1, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_mr_light1, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 主卧灯1按钮开关事件处理
 * 
 * @param e 
 */
void mr_light2_btn(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		if ( lv_obj_has_flag(guider_ui.screen_mr_light2, LV_OBJ_FLAG_HIDDEN) )   /* 检测灯的图层状态是否为关闭 */
		{
			lv_obj_clear_flag(guider_ui.screen_mr_light2, LV_OBJ_FLAG_HIDDEN);   /* 开启灯的图层 */
		}
		else if ( !lv_obj_has_flag(guider_ui.screen_mr_light2, LV_OBJ_FLAG_HIDDEN) ) /* 检测灯的图层是否开启 */
		{
			lv_obj_add_flag(guider_ui.screen_mr_light2, LV_OBJ_FLAG_HIDDEN);     /* 关闭灯的图层 */
		}
		break;
	}
	default:
		break;
	}
}

/**
 * @brief 初始化自设定event函数
 * 
 * @param ui 
 */
void custom_event_init(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_liv_light_btn, liv_light_btn, LV_EVENT_ALL, ui);   /* 添加客厅灯按键event */
    lv_obj_add_event_cb(ui->screen_kitc_light_btn, kitc_light_btn, LV_EVENT_ALL, ui); /* 添加厨房灯event */
    lv_obj_add_event_cb(ui->screen_cor1_light_btn, cor1_light_btn, LV_EVENT_ALL, ui); /* 添加走廊灯1 event */
    lv_obj_add_event_cb(ui->screen_cor2_light_btn, cor2_light_btn, LV_EVENT_ALL, ui); /* 添加走廊灯2 event */ 
    lv_obj_add_event_cb(ui->screen_gr_light_btn, gr_light_btn, LV_EVENT_ALL, ui); /* 添加客房灯 event */
    lv_obj_add_event_cb(ui->screen_bal1_light_btn, bal1_light_btn, LV_EVENT_ALL, ui); /* 添加阳台1灯 event */
    lv_obj_add_event_cb(ui->screen_bal2_light_btn, bal2_light_btn, LV_EVENT_ALL, ui); /* 添加阳台2灯 event */
    lv_obj_add_event_cb(ui->screen_br_light_btn, br_light_btn, LV_EVENT_ALL, ui); /* 添加次卫灯 event */
    lv_obj_add_event_cb(ui->screen_dt_light_btn, dt_light_btn, LV_EVENT_ALL, ui); /* 添加餐桌灯 event */
    lv_obj_add_event_cb(ui->screen_mb_btn, mb_light_btn, LV_EVENT_ALL, ui); /* 添加主卫灯 event */
    lv_obj_add_event_cb(ui->screen_sr_light_btn, sr_light_btn, LV_EVENT_ALL, ui); /* 添加次卧灯 event */
    lv_obj_add_event_cb(ui->screen_mr_light_bnt1, mr_light1_btn, LV_EVENT_ALL, ui); /* 添加主卧1灯 event */
    lv_obj_add_event_cb(ui->screen_mr_light_bnt2, mr_light2_btn, LV_EVENT_ALL, ui); /* 添加主卧2灯 event */
}

