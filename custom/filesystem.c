#include "lvgl.h"
#include <stdio.h>

static void *fs_open(lv_fs_drv_t *drv, const char *path, lv_fs_mode_t mode);
static lv_fs_res_t fs_close(lv_fs_drv_t *drv, void *file_p);
static lv_fs_res_t fs_read(lv_fs_drv_t *drv, void *file_p, void *buf, uint32_t btr, uint32_t *br);
static lv_fs_res_t fs_seek(lv_fs_drv_t *drv, void *file_p, uint32_t pos, lv_fs_whence_t whence);
static lv_fs_res_t fs_tell(lv_fs_drv_t *drv, void *file_p, uint32_t *pos_p);


/*
 *@brief 初始化文件系统
 */
void lv_port_fs_init(void)
{
    static lv_fs_drv_t fs_drv;

    lv_fs_drv_init(&fs_drv);

    fs_drv.letter = 'S';
    fs_drv.open_cb = fs_open;
    fs_drv.close_cb = fs_close;
    fs_drv.read_cb = fs_read;
    fs_drv.seek_cb = fs_seek;
    fs_drv.tell_cb = fs_tell;

    lv_fs_drv_register(&fs_drv);
}

static void *fs_open(lv_fs_drv_t *drv, const char *path, lv_fs_mode_t mode)
{
    char smode[4] = {0};
    FILE *fp = NULL;

    if (mode == LV_FS_MODE_WR)
        strcpy(smode, "wb");
    else if (mode == LV_FS_MODE_RD)
        strcpy(smode, "rb");
    else if (mode == (LV_FS_MODE_WR | LV_FS_MODE_RD))
        strcpy(smode, "wb+");
    else
        return NULL;

    fp = fopen(path, smode);

    return fp;
}

static lv_fs_res_t fs_close(lv_fs_drv_t *drv, void *file_p)
{
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;

    FILE *fp = (FILE *)file_p;

    if (0 == fclose(fp))
        res = LV_FS_RES_OK;
    else
        res = LV_FS_RES_FS_ERR;

    return res;
}

static lv_fs_res_t fs_read(lv_fs_drv_t *drv, void *file_p, void *buf, uint32_t btr, uint32_t *br)
{
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;

    FILE *fp = (FILE *)file_p;

    *br = fread(buf, (size_t)1, (size_t)btr, fp);
    if (*br == btr)
        res = LV_FS_RES_OK;
    else
        res = LV_FS_RES_FS_ERR;

    return res;
}

static lv_fs_res_t fs_seek(lv_fs_drv_t *drv, void *file_p, uint32_t pos, lv_fs_whence_t whence)
{
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;

    FILE *fp = (FILE *)file_p;

    if (0 == fseek(fp, pos, whence))
        res = LV_FS_RES_OK;
    else
        res = LV_FS_RES_FS_ERR;

    return res;
}

static lv_fs_res_t fs_tell(lv_fs_drv_t *drv, void *file_p, uint32_t *pos_p)
{
    (void)drv;
    FILE *fp = (FILE *)file_p;

    *pos_p = ftell(fp);

    return LV_FS_RES_OK;
}

