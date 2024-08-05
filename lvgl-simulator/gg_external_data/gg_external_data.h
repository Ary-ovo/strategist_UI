/*
 * SPDX-License-Identifier: MIT
 * Copyright 2023 NXP
 */

#ifndef GG_EXTERNAL_DATA_H
#define GG_EXTERNAL_DATA_H

#include <stdint.h>
#include "lvgl.h"

typedef void (*gg_edata_task_cb_t)(void * param);

typedef struct _gg_edata_task_t
{
    uint64_t last_time;
    uint32_t period;
    gg_edata_task_cb_t cb;
    void * param;
} gg_edata_task_t;

enum gg_widget_type {
    GG_LABEL = 1,
    GG_CHART,
    GG_BAR,
    GG_METER,
    GG_ARC,
    GG_SLIDER,
    GG_SWITCH
};

/**
 * get time in us
 */
uint64_t gg_get_us_time();

/**
 * get time in ms
 */
uint64_t gg_get_ms_time();

/**
 * sleep in ns
 * @param ns number to sleep.
 */
void gg_nanosleep(int ns);

/**
 * init edata task link
 */
void gg_edata_task_init(void);

/**
 * clear edata task linked list, The list remain valid but become empty.
 */
void gg_edata_task_clear(lv_obj_t * act_scr);

/**
 * Create a new edata task
 * @param period call period in ms unit
 * @param cb a callback which will be called periodically.
 * @param param parameter for callback
 * @return pointer to the new task
 */
gg_edata_task_t * gg_edata_task_create(uint32_t period, gg_edata_task_cb_t cb, void * param);

/**
 * routine which will be executed in a new thread
 */
void *gg_edata_task_exec();

#endif