#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // For each pixel, calculate the average pixel value
            int rgbGray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed + (3 / 2)) / 3);

            // Set each color value to the average value
            image[i][j].rgbtBlue = rgbGray;
            image[i][j].rgbtGreen = rgbGray;
            image[i][j].rgbtRed = rgbGray;
        }
    }
    return;
}

// Caps max RGB value at 255
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }

    return RGB;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate each new color value using the Sepia formula
            int sepiaRed = limit(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            int sepiaGreen = limit(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            int sepiaBlue = limit(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));


            // Set each color to the Sepia color value
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int c, d;
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (c = width - 1, d = 0; c >= 0; c--, d++)
        {
            // Copying elements into array "temp" starting from end of array "image"
            temp[i][d] = image[i][c];
        }
    }

    // Copying reversed array "temp" into the original array "image"
    for (int i = 0; i < height; i++)
    {
        for (int j = 0;  j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;

    // Create a temporary array containing colors of the image, to not alter the calculations
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            // Add together the RGB value of the pixel and the 8 neighbouring pixels.
            // Skip current interation if index goes outside the image
            for (int k = -1; k < 2; k++)
            {

                // Rows at the edge
                if (i + k < 0 || i + k > height - 1)
                {
                    continue;
                }

                // Columns at the edge
                for (int h = -1; h < 2; h++)
                {
                    if (j + h < 0 || j + h > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[i + k][j + h].rgbtBlue;
                    sumGreen += image[i + k][j + h].rgbtGreen;
                    sumRed += image[i + k][j + h].rgbtRed;
                    counter++;
                }
            }

            // Average the sum for blur effect
            temp[i][j].rgbtBlue = round(sumBlue / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtRed = round(sumRed / counter);

        }
    }

    // Copy values from temp to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
}