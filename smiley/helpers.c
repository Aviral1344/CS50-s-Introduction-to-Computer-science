#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE *pixel = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){

             pixel = &image[i][j];
            if ( pixel->rgbtRed == 0x00 && pixel->rgbtGreen == 0x00 &&  pixel->rgbtBlue == 0x00){

                pixel->rgbtRed = 0xFF;
            }
        }

    }
}
