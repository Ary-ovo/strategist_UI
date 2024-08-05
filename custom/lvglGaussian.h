#ifndef __LVGLGAUSSIAN_H__
#define __LVGLGAUSSIAN_H__
#include <string>
#include <stdio.h>
#include <unistd.h>
#include "lvgl/lvgl.h"

inline int isCircle(float x, float y, float circle_x, float circle_y, float width, float height, float r)
{
    if (x < (circle_x + r) && y < (circle_y + r)) {
        if ((x - circle_x - r) * (x - circle_x - r) + (y - circle_y - r) * (y - circle_y - r) > r * r) {
            return false;    
        }
    }

    if (x < (circle_x + r) && y > (circle_y + height - r)) {
        if ((x - circle_x - r) * (x - circle_x - r) + (y - circle_y + r - height) * (y - circle_y + r - height) > r * r) {
            return false;  
        }
    }

    if (x > (circle_x + width -r) && y < (circle_y + r)) {
        if ((x - circle_x - width + r) * (x - circle_x - width + r) + (y - circle_y - r) * (y - circle_y - r) > r * r) {
            return false;  
        }
    }

    if (x > (circle_x + width -r) && y > (circle_y + height - r)) {
        if ((x - circle_x - width + r) * (x - circle_x - width + r) + (y - circle_y + r - height) * (y - circle_y + r - height) > r * r) {
            return false;  
        }
    }

    return true;
}

inline int isSquare(float x, float y, float circle_x, float circle_y, float width, float height, float boder) {
     
    if (x <= (circle_x + boder) && y <= (circle_y + height) ) {
        return false;  
    }
    
    if (x >= (circle_x - boder + width) && y <= (circle_y + height) ) {
        return false;  
    }

    if (x <= (circle_x + width) && y <= (circle_y + boder) ) {
        return false;  
    }

    if (x <= (circle_x + width) && y >= (circle_y + height - boder) ) {
        return false;  
    }
    return true;
}

enum lv_blur_type_e {
    AVERAGEBLUR = 0,  //均值模糊，累加优化
    AVERAGEBLUR1 = 1, //均值模糊，无优化
    AVERAGEBLUR2 = 2, //均值模糊，行模糊+列模糊
    GAUSSSIANM = 3,   //高斯模糊
};

struct lv_draw_gaussian_blur_dsc_t {
    lv_obj_t * canvas;
    lv_coord_t x;
    lv_coord_t y;
    int width; 
    int height;
    int r; //模糊半径，越大越模糊
    int border_width;
    lv_color_t border_color; //边框颜色
    int border_radius; //边框半径
    lv_blur_type_e blur_type;
};

class lvglGaussian
{
public:
    lvglGaussian();
    ~lvglGaussian();
    
    void lv_draw_gaussian_blur(lv_draw_gaussian_blur_dsc_t lv_draw_gaussian_blur);
 
private:
    void AverageBlur(int radius);
    void AverageBlur1(int radius);
    void AverageBlur2(int radius);
    void GaussianBlur(float * weights,int radius);
    float *createGaussianKernel(int radius);

    uint8_t *content;
    int image_size;
    int image_stride;
    int image_width;
    int image_height;
    int x;
    int y;
    int r;
    int border_width;
    lv_color_t border_color; //边框颜色
    int border_radius;  //边框半径
    lv_obj_t * canvas_;
};

#endif // !__LVGLGAUSSIAN_H__
