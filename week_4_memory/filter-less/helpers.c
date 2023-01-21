#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            // algorithm to convert image to sepia
            float sepiaRed = .393 * image[k][l].rgbtRed + .769 * image[k][l].rgbtGreen + .189 * image[k][l].rgbtBlue;
            float sepiaGreen = .349 * image[k][l].rgbtRed + .686 * image[k][l].rgbtGreen + .168 * image[k][l].rgbtBlue;
            float sepiaBlue = .272 * image[k][l].rgbtRed + .534 * image[k][l].rgbtGreen + .131 * image[k][l].rgbtBlue;

            // if color value exceed 255, it will be set to 255

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[k][l].rgbtRed = round(sepiaRed);
            image[k][l].rgbtGreen = round(sepiaGreen);
            image[k][l].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int reflectRedPixels[height][width];
    int reflectGreenPixels[height][width];
    int reflectBluePixels[height][width];

    for (int m = 0; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            // copies the image to another array for later use
            reflectRedPixels[m][n] = image[m][n].rgbtRed;
            reflectGreenPixels[m][n] = image[m][n].rgbtGreen;
            reflectBluePixels[m][n] = image[m][n].rgbtBlue;
        }
    }

    for (int o = 0; o < height; o++)
    {
        for (int p = 0; p < width; p++)
        {
            // takes the last pixel horizontally (then moves to the pixel to the left as p increases) and sets it to the pixel [o][p]
            image[o][p].rgbtRed = reflectRedPixels[o][(width - 1) - p];
            image[o][p].rgbtGreen = reflectGreenPixels[o][(width - 1) - p];
            image[o][p].rgbtBlue = reflectBluePixels[o][(width - 1) - p];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copiedPixels[height][width];

    for (int q = 0; q < height; q++)
    {
        for (int r = 0; r < width; r++)
        {
            // makes a copy of the image
            copiedPixels[q][r] = image[q][r];
        }
    }

    for (int he = 0; he < height; he++)
    {
        for (int wi = 0; wi < width; wi++)
        {
            float numOfPixels = 0.0;
            float redValues = 0.0;
            float greenValues = 0.0;
            float blueValues = 0.0;

            // right pixel
            if (wi != width - 1)
            {
                redValues += copiedPixels[he][wi + 1].rgbtRed;
                greenValues += copiedPixels[he][wi + 1].rgbtGreen;
                blueValues += copiedPixels[he][wi + 1].rgbtBlue;

                numOfPixels++;
            }

            // left pixel
            if (wi != 0)
            {
                redValues += copiedPixels[he][wi - 1].rgbtRed;
                greenValues += copiedPixels[he][wi - 1].rgbtGreen;
                blueValues += copiedPixels[he][wi - 1].rgbtBlue;

                numOfPixels++;
            }

            // bottom pixel
            if (he != height - 1)
            {
                redValues += copiedPixels[he + 1][wi].rgbtRed;
                greenValues += copiedPixels[he + 1][wi].rgbtGreen;
                blueValues += copiedPixels[he + 1][wi].rgbtBlue;

                numOfPixels++;
            }

            // top pixel
            if (he != 0)
            {
                redValues += copiedPixels[he - 1][wi].rgbtRed;
                greenValues += copiedPixels[he - 1][wi].rgbtGreen;
                blueValues += copiedPixels[he - 1][wi].rgbtBlue;

                numOfPixels++;
            }

            // bottom right pixel
            if (he != height - 1 && wi != width - 1)
            {


                redValues += copiedPixels[he + 1][wi + 1].rgbtRed;
                greenValues += copiedPixels[he + 1][wi + 1].rgbtGreen;
                blueValues += copiedPixels[he + 1][wi + 1].rgbtBlue;

                numOfPixels++;
            }

            // bottom left pixel
            if (he != height - 1 && wi != 0)
            {
                redValues += copiedPixels[he + 1][wi - 1].rgbtRed;
                greenValues += copiedPixels[he + 1][wi - 1].rgbtGreen;
                blueValues += copiedPixels[he + 1][wi - 1].rgbtBlue;

                numOfPixels++;
            }

            // top right pixel
            if (he != 0 && wi != width - 1)
            {
                redValues += copiedPixels[he - 1][wi + 1].rgbtRed;
                greenValues += copiedPixels[he - 1][wi + 1].rgbtGreen;
                blueValues += copiedPixels[he - 1][wi + 1].rgbtBlue;

                numOfPixels++;
            }

            // top left pixel
            if (he != 0 && wi != 0)
            {
                redValues += copiedPixels[he - 1][wi - 1].rgbtRed;
                greenValues += copiedPixels[he - 1][wi - 1].rgbtGreen;
                blueValues += copiedPixels[he - 1][wi - 1].rgbtBlue;

                numOfPixels++;
            }

            // middle pixel
            redValues += copiedPixels[he][wi].rgbtRed;
            greenValues += copiedPixels[he][wi].rgbtGreen;
            blueValues += copiedPixels[he][wi].rgbtBlue;

            numOfPixels++;

            image[he][wi].rgbtRed = round(redValues / numOfPixels);
            image[he][wi].rgbtGreen = round(greenValues / numOfPixels);
            image[he][wi].rgbtBlue = round(blueValues / numOfPixels);
        }
    }
    return;
}
