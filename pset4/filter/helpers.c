#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg_pixel;
    for (int i = 0; i < width; i++) // loop thru rows
    {
        for (int j = 0; j < height; j++) // loop thru columns
        {
            // Calculate average for each pixel
            avg_pixel = round((image[j][i].rgbtRed + image[j][i].rgbtGreen + image[j][i].rgbtBlue)/3);
            // Apply average value to each pixel
            image[j][i].rgbtRed = avg_pixel;
            image[j][i].rgbtBlue = avg_pixel;
            image[j][i].rgbtGreen = avg_pixel;
        }
    }
    return;
}

// Convert image to sepia
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;

    for (int i = 0; i < width; i++) // loop thru rows
    {
        for (int j = 0; j < height; j++) // loop thru columns
        {
            // Calculate average for each pixel
            sepiaBlue = limit(round(.272 * image[j][i].rgbtRed + .534 * image[j][i].rgbtGreen + .131 * image[j][i].rgbtBlue));
            sepiaGreen = limit(round(.349 * image[j][i].rgbtRed + .686 * image[j][i].rgbtGreen + .168 * image[j][i].rgbtBlue));
            sepiaRed = limit(round(.393 * image[j][i].rgbtRed + .769 * image[j][i].rgbtGreen + .189 * image[j][i].rgbtBlue));
            // Apply average value to each pixel
            image[j][i].rgbtBlue = sepiaBlue;
            image[j][i].rgbtGreen = sepiaGreen;
            image[j][i].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp[3]; // temporary variable for switching pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            // Switching each pixel using tmp
            tmp[0] = image[i][j].rgbtRed;
            tmp[1] = image[i][j].rgbtGreen;
            tmp[2] = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            // storing original pixel in relfected pixel
            image[i][width - j - 1].rgbtRed = tmp[0];
            image[i][width - j - 1].rgbtGreen = tmp[1];
            image[i][width - j - 1].rgbtBlue = tmp[2];
        }
    }
    return;
}

// Blur image
//Helper function for blur. Simpler code
int boxblur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int location)
{
    float count = 0;
    int total = 0;
    for (int x = (i-1); x<(i+2); x++) //Start one before, end  two after
    {
        for (int y = (j-1); y<(j+2); y++)
        {
            if (x<0 || y<0 || x>=height || y>=width) //Check pixel validity/existence
            {
                continue;
            }
            if (location==0) //0 is red
            {
                total += image[x][y].rgbtRed;
            }
            else if (location == 1) //1 is green
            {
                total += image[x][y].rgbtGreen;
            }
            else if (location == 2) //2 iss blue
            {
                total += image[x][y].rgbtBlue;
            }
            count++;
        }
    }
    return round(total/count); //return rgb value for each pixel and color
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i<height; i++)
    {
        for (int j = 0; j<width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i<height; i++)
    {
        for (int j = 0; j<width; j++)
        {
            //Replacing color values using the side function
            image[i][j].rgbtRed = boxblur(i, j, height, width, copy, 0);
            image[i][j].rgbtGreen = boxblur(i, j, height, width, copy, 1);
            image[i][j].rgbtBlue = boxblur(i, j, height, width, copy, 2);
        }
    }
    return;
}



















