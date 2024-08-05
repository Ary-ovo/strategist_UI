#include "lvglGaussian.h"
#include <iostream>
#include "lvgl/lvgl.h"
#include <cmath>

lvglGaussian::lvglGaussian()
    :image_size(0),image_width(0),image_height(0)
    ,image_stride(0),content(NULL),canvas_(NULL)
{

}

lvglGaussian::~lvglGaussian()
{
    
}

void lvglGaussian::lv_draw_gaussian_blur(lv_draw_gaussian_blur_dsc_t lv_gaussian_blur)
{
    if (LV_COLOR_DEPTH != 32) {
        printf("[%s:%d] LV_COLOR_DEPTH ERROR %d\n", __FUNCTION__, __LINE__, LV_COLOR_DEPTH);
        return ;
    } 

    int color_bit = (LV_COLOR_DEPTH / 8) - 1;
    this->image_size   = lv_gaussian_blur.width * lv_gaussian_blur.height *  color_bit;
    this->image_width  = lv_gaussian_blur.width;
    this->image_height = lv_gaussian_blur.height;
    this->image_stride = lv_gaussian_blur.width *  color_bit;
    this->canvas_      = lv_gaussian_blur.canvas;

    this->x = lv_gaussian_blur.x;
    this->y = lv_gaussian_blur.y;
    this->r = lv_gaussian_blur.r;
    this->border_width = lv_gaussian_blur.border_width;
    this->border_color = lv_gaussian_blur.border_color;
    this->border_radius = lv_gaussian_blur.border_radius;

    this->content = (uint8_t *)malloc(this->image_size);
    if (this->content == NULL) {
        printf("[%s:%d] CREATE MALLOC ERROR\n", __FUNCTION__, __LINE__);
        return;
    }

    int f = 0;
    for (int column = y; column < (y + image_height); column++) {
        for (int row = x; row < (x + image_width); row++) {
            lv_color_t px_point= lv_canvas_get_px(this->canvas_, row, column);
            this->content[f]         =  px_point.ch.blue;
            this->content[f + 1]     =  px_point.ch.green;
            this->content[f + 2]     =  px_point.ch.red;
            f = f + color_bit;;
        }
    }

    if (lv_gaussian_blur.blur_type == AVERAGEBLUR) {
        this->AverageBlur(this->r);
    } else if (lv_gaussian_blur.blur_type == AVERAGEBLUR1) {
        this->AverageBlur1(this->r);  
    } else if (lv_gaussian_blur.blur_type == AVERAGEBLUR2) {
        this->AverageBlur2(this->r);  
    } else {
        this->GaussianBlur(createGaussianKernel(this->r), this->r);
    }

    f = 0;

    for (int column = y; column < (y + image_height); column++) {
        for (int row = x; row < (x + image_width); row++) {
            if (isCircle(row, column, x, y ,this->image_width,  this->image_height, border_radius) == true ) {
                if (isCircle(row, column, x + border_width, y + border_width ,image_width - border_width * 2,  image_height - border_width * 2, border_radius)
                    && isSquare(row, column, x, y ,this->image_width,  this->image_height, border_width)) {
                    lv_color_t px_point;
                    px_point.ch.blue    = this->content[f];
                    px_point.ch.green   = this->content[f + 1] ;
                    px_point.ch.red     = this->content[f + 2];
                    lv_canvas_set_px_color(this->canvas_, row, column, px_point); 
                } else {
                    lv_canvas_set_px_color(this->canvas_, row, column, border_color); 
                    //lv_canvas_set_px_opa(this->canvas_, row, column, LV_OPA_50);
                }
            }
            f = f + color_bit;
        }
    }

    if (this->content) {
        free(this->content);
        this->content = NULL;
    }
}

void lvglGaussian::AverageBlur(int radius){
    if (radius <= 0 || radius >= image_width || radius >= image_height)
    {
        return;
    }

    //uint8_t *newContent = new uint8_t[image_size]; // 分配内存
    uint8_t *newContent = (uint8_t *)malloc(image_size * sizeof(uint8_t));

    uint8_t *contentPtrN, *contentPtrO;
    
    int xStride = (2 * radius + 1) * 3;
    int yStride = (2 * radius + 1) * image_stride;

    // 水平方向模糊
    for (int j = 0; j < image_height; j++)
    {
        contentPtrO = &content[j * image_stride];
        contentPtrN = &newContent[j * image_stride];
        int bSum = 0, gSum = 0, rSum = 0;
        int cnt = 0;
        for (int u = 0; u <= radius; u++)
        {
            bSum += *(contentPtrO++);
            gSum += *(contentPtrO++);
            rSum += *(contentPtrO++);
            cnt++;
        }
        *(contentPtrN++) = bSum / cnt;
        *(contentPtrN++) = gSum / cnt;
        *(contentPtrN++) = rSum / cnt;

        for (int i = 1; i <= radius; i++)
        {
            bSum += *(contentPtrO++);
            gSum += *(contentPtrO++);
            rSum += *(contentPtrO++);
            cnt++;
            *(contentPtrN++) = bSum / cnt;
            *(contentPtrN++) = gSum / cnt;
            *(contentPtrN++) = rSum / cnt;
        }

        for (int i = radius + 1; i < image_width - radius; i++)
        {
            bSum = bSum + *(contentPtrO) - *(contentPtrO - xStride);
            contentPtrO++;
            gSum = gSum + *(contentPtrO) - *(contentPtrO - xStride);
            contentPtrO++;
            rSum = rSum + *(contentPtrO) - *(contentPtrO - xStride);
            contentPtrO++;
          
            *(contentPtrN++) = bSum / cnt;
            *(contentPtrN++) = gSum / cnt;
            *(contentPtrN++) = rSum / cnt;
           
        }
        for (int i = image_width - radius; i < image_width; i++)
        {
            bSum -= *(contentPtrO - xStride);
            contentPtrO++;
            gSum -= *(contentPtrO - xStride);
            contentPtrO++;
            rSum -= *(contentPtrO - xStride);
            contentPtrO++;
            
            cnt--;
            *(contentPtrN++) = bSum / cnt;
            *(contentPtrN++) = gSum / cnt;
            *(contentPtrN++) = rSum / cnt;
           
        }
    }
   
    // 垂直方向模糊
    for (int i = 0; i < image_width; i++)
    {
        contentPtrO = &content[i * 3];
        contentPtrN = &newContent[i * 3];
        int bSum = 0, gSum = 0, rSum = 0, Alpha = 0;
        int cnt = 0;
        for (int v = 0; v <= radius; v++)
        {
            bSum += *(contentPtrN);
            gSum += *(contentPtrN + 1);
            rSum += *(contentPtrN + 2);
        
            contentPtrN += image_stride;
            cnt++;
        }
        *(contentPtrO) = bSum / cnt;
        *(contentPtrO + 1) = gSum / cnt;
        *(contentPtrO + 2) = rSum / cnt;
        
        contentPtrO += image_stride;

        for (int j = 1; j <= radius; j++)
        {
            bSum += *(contentPtrN);
            gSum += *(contentPtrN + 1);
            rSum += *(contentPtrN + 2);
           
            contentPtrN += image_stride;
            cnt++;
            *(contentPtrO) = bSum / cnt;
            *(contentPtrO + 1) = gSum / cnt;
            *(contentPtrO + 2) = rSum / cnt;
            
            contentPtrO += image_stride;
        }

        for (int j = radius + 1; j < image_height - radius; j++)
        {
            bSum = bSum + *(contentPtrN) - *(contentPtrN - yStride);
            gSum = gSum + *(contentPtrN + 1) - *(contentPtrN + 1 - yStride);
            rSum = rSum + *(contentPtrN + 2) - *(contentPtrN + 2 - yStride);
            
            contentPtrN += image_stride;
            *(contentPtrO) = bSum / cnt;
            *(contentPtrO + 1) = gSum / cnt;
            *(contentPtrO + 2) = rSum / cnt;
          
            contentPtrO += image_stride;
        }

        for (int j = image_height - radius; j < image_height; j++)
        {
            bSum -= *(contentPtrN - yStride);
            gSum -= *(contentPtrN + 1 - yStride);
            rSum -= *(contentPtrN + 2 - yStride);
           
            contentPtrN += image_stride;
            cnt--;
            *(contentPtrO) = bSum / cnt;
            *(contentPtrO + 1) = gSum / cnt;
            *(contentPtrO + 2) = rSum / cnt;
           
            contentPtrO += image_stride;
        }
    }

    if (newContent) {
        free(newContent);
        newContent = NULL;
    }
}

void lvglGaussian::AverageBlur1(int radius) {
    if (radius <= 0) {
        return;
    }

    uint8_t *newContent = (uint8_t *) malloc(image_size * sizeof(uint8_t));

    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < image_width; x++){
            int cnt=0;
            int bSum=0, gSum=0, rSum=0;
            for (int j = -radius; j <= radius; j++) {//垂直方向求和
                for (int i = -radius; i <= radius; i++){//水平方向求和
                    if (i+x >= 0 && i+x < image_width && y+j >= 0 && y+j < image_height) {
                        cnt++;
                        bSum += content[(y+j) * image_stride + 3 * (x+i)+0];
                        gSum += content[(y+j) * image_stride + 3 * (x+i)+1];
                        rSum += content[(y+j) * image_stride + 3 * (x+i)+2];
                    }
                }
            }

            newContent[y * image_stride + 3*x + 0] = bSum/cnt;
            newContent[y * image_stride + 3*x + 1] = gSum/cnt;
            newContent[y * image_stride + 3*x + 2] = rSum/cnt;
        }
    }

    if (content) {
        free(content);
        content = NULL;
    }

    this->content = newContent;
}

void lvglGaussian::AverageBlur2(int radius){
    if(radius<=0){
        return;
    }

    uint8_t *newContent = (uint8_t *)malloc(image_size * sizeof(uint8_t));
    uint8_t *contentPtrN, *contentPtrO;

    //水平方向模糊
    for(int j=0;j<image_height;j++){
        contentPtrO=&content[j*image_stride];
        contentPtrN=&newContent[j*image_stride];

        for(int i=0;i<radius;i++){
            int rSum=0,gSum=0,bSum=0;
            for(int u=-i;u<=radius;u++){
                bSum+=*(contentPtrO+u*3);
                gSum+=*(contentPtrO+u*3+1);
                rSum+=*(contentPtrO+u*3+2);
            }
            *(contentPtrN++)=bSum/(i+radius+1);
            *(contentPtrN++)=gSum/(i+radius+1);
            *(contentPtrN++)=rSum/(i+radius+1);

            contentPtrO+=3;
        }

        for(int i=radius;i<image_width-radius;i++){
            int rSum=0,gSum=0,bSum=0;
            for(int u=-radius;u<=radius;u++){
                bSum+=*(contentPtrO+u*3);
                gSum+=*(contentPtrO+u*3+1);
                rSum+=*(contentPtrO+u*3+2);
            }
            *(contentPtrN++)=bSum/(2*radius+1);
            *(contentPtrN++)=gSum/(2*radius+1);
            *(contentPtrN++)=rSum/(2*radius+1);

            contentPtrO+=3;
        }
        for(int i=image_width-radius;i<image_width;i++){
            int rSum=0,gSum=0,bSum=0;
            int rLen=image_width-i;
            for(int u=-radius;u<rLen;u++){
                //printf("FK?\n");
                bSum+=*(contentPtrO+u*3);
                gSum+=*(contentPtrO+u*3+1);
                rSum+=*(contentPtrO+u*3+2);
            }

            *(contentPtrN++)=bSum/(radius+rLen);
            *(contentPtrN++)=gSum/(radius+rLen);
            *(contentPtrN++)=rSum/(radius+rLen);

            contentPtrO+=3;
        }
    }

    //垂直方向模糊
    for(int i=0;i<image_width;i++){
        contentPtrO=&content[3*i];
        contentPtrN=&newContent[3*i];

        for(int j=0;j<radius;j++){
            int rSum=0,gSum=0,bSum=0;
            for(int v=-j;v<=radius;v++){
                int s=v*image_stride;
                bSum+=*(contentPtrN+s);
                gSum+=*(contentPtrN+s+1);
                rSum+=*(contentPtrN+s+2);
            }
            *(contentPtrO)=bSum/(radius+1+j);
            *(contentPtrO+1)=gSum/(radius+1+j);
            *(contentPtrO+2)=rSum/(radius+1+j);
            contentPtrO+=image_stride;
            contentPtrN+=image_stride;
        }

        for(int j=radius;j<image_height-radius;j++){
            int rSum=0,gSum=0,bSum=0;
            for(int v=-radius;v<=radius;v++){
                int s=v*image_stride;
                bSum+=*(contentPtrN+s);
                gSum+=*(contentPtrN+s+1);
                rSum+=*(contentPtrN+s+2);
            }
            *(contentPtrO)=bSum/(2*radius+1);
            *(contentPtrO+1)=gSum/(2*radius+1);
            *(contentPtrO+2)=rSum/(2*radius+1);
            contentPtrO+=image_stride;
            contentPtrN+=image_stride;
        }

        for(int j=image_height-radius;j<image_height;j++){
            int rSum=0,gSum=0,bSum=0;
            int cLen=image_height-j;
            for(int v=-radius;v<cLen;v++){
                int s=v*image_stride;
                bSum+=*(contentPtrN+s);
                gSum+=*(contentPtrN+s+1);
                rSum+=*(contentPtrN+s+2);
            }
            *(contentPtrO)=bSum/(radius+cLen);
            *(contentPtrO+1)=gSum/(radius+cLen);
            *(contentPtrO+2)=rSum/(radius+cLen);
            contentPtrO+=image_stride;
            contentPtrN+=image_stride;
        }

    }

    if (newContent) {
        free(newContent);
        newContent = NULL;
    }
}


void lvglGaussian::GaussianBlur(float * weights,int radius) {
    uint8_t *newContent = (uint8_t *)malloc(image_size * sizeof(uint8_t));
    //float weightsSum=0;
    uint8_t *contentPtrO=content;
    uint8_t *contentPtrN=newContent;
    float *weightPtr=weights;


    //printf("111111GaussianKernel:\n");
    for(int j=0;j<image_height;j++){
        contentPtrO=&content[j*image_stride];
        contentPtrN=&newContent[j*image_stride];
        //printf("wumh weightPtr++ Kernel:%d, ptr %p \n",j*stride,content);


        for(int i=0;i<image_width;i++){
            float rSum=0,gSum=0,bSum=0;
            weightPtr=weights;
            for(int u=-radius;u<=radius;u++){
                for(int v=-radius;v<=radius;v++){
                    if(u+i<0||u+i>=image_width||v+j<0||v+j>=image_height){
                        weightPtr++;
                        continue;
                    }
                    //printf(" weightPtr++ :%p Kernel:%p,%p,%p,%p\n",contentPtrO + v*stride+3*u+0, content , &content[j*stride] - 5760,contentPtrO, contentPtrO - 5760);
                    
                    int abc = v*image_stride+3*u+0;

                    //weightsSum+=weights[weightIndex];
                    bSum+=*(contentPtrO+abc)*(*weightPtr);

                    //printf("wumh weightPtr++ Kernel:\n");
                    gSum+=*(contentPtrO+abc+1)*(*weightPtr);
                    //printf("wumh weightPtr++ Kernel:\n");
                    rSum+=*(contentPtrO+abc+2)*(*weightPtr);
                    weightPtr++;
                }
            }

            //bSum/=weightsSum;
            //gSum/=weightsSum;
            //rSum/=weightsSum;
            (*contentPtrN)=bSum;
            contentPtrN++;
            (*contentPtrN)=gSum;
            contentPtrN++;
            (*contentPtrN)=rSum;
            contentPtrN++;

            contentPtrO+=3;
        }
    }

    if (content) {
        free(content);
        content = NULL;
    }

    this->content = newContent;

     if (weights) {
        free(weights);
        weights = NULL;
    }
}

float * lvglGaussian::createGaussianKernel(int radius){
    float sigma=radius/2;
    float weightsSum=0;
    int weightsLen=radius*2+1;
    float *weights= (float *)malloc(weightsLen*weightsLen * sizeof(float));
    for(int u=-radius;u<=radius;u++){ //row
        for(int v=-radius;v<=radius;v++){ //collum
            int i=u+radius,j=v+radius;
            weights[j*weightsLen+i]=1/(6.28*sigma*sigma)*exp((-u*u-v*v)/(2*sigma*sigma));
            weightsSum+=weights[j*weightsLen+i];
        }
    }

    for(int u=-radius;u<=radius;u++){ //row
        for(int v=-radius;v<=radius;v++){ //collum
            int i=u+radius,j=v+radius;
            weights[j*weightsLen+i]/=weightsSum;
        }
    }
    return weights;
}