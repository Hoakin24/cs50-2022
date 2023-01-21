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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copiedPixels[height][width];

    for (int m = 0; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            // copies the image to another array for later use
            copiedPixels[m][n] = image[m][n];
        }
    }

    for (int o = 0; o < height; o++)
    {
        for (int p = 0; p < width; p++)
        {
            // takes the last pixel horizontally (then moves to the pixel to the left as p increases) and sets it to the pixel [o][p]
            image[o][p].rgbtRed = copiedPixels[o][(width - 1) - p].rgbtRed;
            image[o][p].rgbtGreen = copiedPixels[o][(width - 1) - p].rgbtGreen;
            image[o][p].rgbtBlue = copiedPixels[o][(width - 1) - p].rgbtBlue;
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

    for (int s = 0; s < height; s++)
    {
        for (int t = 0; t < width; t++)
        {
            float numOfPixels = 0.0;
            float redValues = 0.0;
            float greenValues = 0.0;
            float blueValues = 0.0;

            // right pixel
            if (t != width - 1)
            {
                redValues += copiedPixels[s][t + 1].rgbtRed;
                greenValues += copiedPixels[s][t + 1].rgbtGreen;
                blueValues += copiedPixels[s][t + 1].rgbtBlue;

                numOfPixels++;
            }

            // left pixel
            if (t != 0)
            {
                redValues += copiedPixels[s][t - 1].rgbtRed;
                greenValues += copiedPixels[s][t - 1].rgbtGreen;
                blueValues += copiedPixels[s][t - 1].rgbtBlue;

                numOfPixels++;
            }

            // bottom pixel
            if (s != height - 1)
            {
                redValues += copiedPixels[s + 1][t].rgbtRed;
                greenValues += copiedPixels[s + 1][t].rgbtGreen;
                blueValues += copiedPixels[s + 1][t].rgbtBlue;

                numOfPixels++;
            }

            // top pixel
            if (s != 0)
            {
                redValues += copiedPixels[s - 1][t].rgbtRed;
                greenValues += copiedPixels[s - 1][t].rgbtGreen;
                blueValues += copiedPixels[s - 1][t].rgbtBlue;

                numOfPixels++;
            }

            // bottom right pixel
            if (s != height - 1 && t != width - 1)
            {
                redValues += copiedPixels[s + 1][t + 1].rgbtRed;
                greenValues += copiedPixels[s + 1][t + 1].rgbtGreen;
                blueValues += copiedPixels[s + 1][t + 1].rgbtBlue;

                numOfPixels++;
            }

            // bottom left pixel
            if (s != height - 1 && t != 0)
            {
                redValues += copiedPixels[s + 1][t - 1].rgbtRed;
                greenValues += copiedPixels[s + 1][t - 1].rgbtGreen;
                blueValues += copiedPixels[s + 1][t - 1].rgbtBlue;

                numOfPixels++;
            }

            // top right pixel
            if (s != 0 && t != width - 1)
            {
                redValues += copiedPixels[s - 1][t + 1].rgbtRed;
                greenValues += copiedPixels[s - 1][t + 1].rgbtGreen;
                blueValues += copiedPixels[s - 1][t + 1].rgbtBlue;

                numOfPixels++;
            }

            // top left pixel
            if (s != 0 && t != 0)
            {
                redValues += copiedPixels[s - 1][t - 1].rgbtRed;
                greenValues += copiedPixels[s - 1][t - 1].rgbtGreen;
                blueValues += copiedPixels[s - 1][t - 1].rgbtBlue;

                numOfPixels++;
            }

            // middle pixel
            redValues += copiedPixels[s][t].rgbtRed;
            greenValues += copiedPixels[s][t].rgbtGreen;
            blueValues += copiedPixels[s][t].rgbtBlue;

            numOfPixels++;

            image[s][t].rgbtRed = round(redValues / numOfPixels);
            image[s][t].rgbtGreen = round(greenValues / numOfPixels);
            image[s][t].rgbtBlue = round(blueValues / numOfPixels);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copiedPixels[height][width];

    for (int u = 0; u < height; u++)
    {
        for (int v = 0; v < width; v++)
        {
            // makes a copy of the image
            copiedPixels[u][v] = image[u][v];
        }
    }

    for (int he = 0; he < height; he++)
    {
        for (int wi = 0; wi < width; wi++)
        {
            float gxRedValues = 0.0;
            float gxGreenValues = 0.0;
            float gxBlueValues = 0.0;

            float gyRedValues = 0.0;
            float gyGreenValues = 0.0;
            float gyBlueValues = 0.0;

            float gRed;
            float gGreen;
            float gBlue;

            // right pixel
            if (wi != width - 1)
            {
                gxRedValues += (copiedPixels[he][wi + 1].rgbtRed * 2);
                gxGreenValues += (copiedPixels[he][wi + 1].rgbtGreen * 2);
                gxBlueValues += (copiedPixels[he][wi + 1].rgbtBlue * 2);

                gyRedValues += (copiedPixels[he][wi + 1].rgbtRed * 0);
                gyGreenValues += (copiedPixels[he][wi + 1].rgbtGreen * 0);
                gyBlueValues += (copiedPixels[he][wi + 1].rgbtBlue * 0);
            }

            // left pixel
            if (wi != 0)
            {
                gxRedValues += (copiedPixels[he][wi - 1].rgbtRed * -2);
                gxGreenValues += (copiedPixels[he][wi - 1].rgbtGreen * -2);
                gxBlueValues += (copiedPixels[he][wi - 1].rgbtBlue * -2);

                gyRedValues += (copiedPixels[he][wi - 1].rgbtRed * 0);
                gyGreenValues += (copiedPixels[he][wi - 1].rgbtGreen * 0);
                gyBlueValues += (copiedPixels[he][wi - 1].rgbtBlue * 0);
            }

            // bottom pixel
            if (he != height - 1)
            {
                gxRedValues += (copiedPixels[he + 1][wi].rgbtRed * 0);
                gxGreenValues += (copiedPixels[he + 1][wi].rgbtGreen * 0);
                gxBlueValues += (copiedPixels[he + 1][wi].rgbtBlue * 0);

                gyRedValues += (copiedPixels[he + 1][wi].rgbtRed * 2);
                gyGreenValues += (copiedPixels[he + 1][wi].rgbtGreen * 2);
                gyBlueValues += (copiedPixels[he + 1][wi].rgbtBlue * 2);
            }

            // top pixel
            if (he != 0)
            {
                gxRedValues += (copiedPixels[he - 1][wi].rgbtRed * 0);
                gxGreenValues += (copiedPixels[he - 1][wi].rgbtGreen * 0);
                gxBlueValues += (copiedPixels[he - 1][wi].rgbtBlue * 0);

                gyRedValues += (copiedPixels[he - 1][wi].rgbtRed * -2);
                gyGreenValues += (copiedPixels[he - 1][wi].rgbtGreen * -2);
                gyBlueValues += (copiedPixels[he - 1][wi].rgbtBlue * -2);
            }

            // bottom right pixel
            if (he != height - 1 && wi != width - 1)
            {
                gxRedValues += copiedPixels[he + 1][wi + 1].rgbtRed;
                gxGreenValues += copiedPixels[he + 1][wi + 1].rgbtGreen;
                gxBlueValues += copiedPixels[he + 1][wi + 1].rgbtBlue;

                gyRedValues += copiedPixels[he + 1][wi + 1].rgbtRed;
                gyGreenValues += copiedPixels[he + 1][wi + 1].rgbtGreen;
                gyBlueValues += copiedPixels[he + 1][wi + 1].rgbtBlue;
            }

            // bottom left pixel
            if (he != height - 1 && wi != 0)
            {
                gxRedValues += (copiedPixels[he + 1][wi - 1].rgbtRed * -1);
                gxGreenValues += (copiedPixels[he + 1][wi - 1].rgbtGreen * -1);
                gxBlueValues += (copiedPixels[he + 1][wi - 1].rgbtBlue * -1);

                gyRedValues += copiedPixels[he + 1][wi - 1].rgbtRed;
                gyGreenValues += copiedPixels[he + 1][wi - 1].rgbtGreen;
                gyBlueValues += copiedPixels[he + 1][wi - 1].rgbtBlue;
            }

            // top right pixel
            if (he != 0 && wi != width - 1)
            {
                gxRedValues += copiedPixels[he - 1][wi + 1].rgbtRed;
                gxGreenValues += copiedPixels[he - 1][wi + 1].rgbtGreen;
                gxBlueValues += copiedPixels[he - 1][wi + 1].rgbtBlue;

                gyRedValues += (copiedPixels[he - 1][wi + 1].rgbtRed * -1);
                gyGreenValues += (copiedPixels[he - 1][wi + 1].rgbtGreen * -1);
                gyBlueValues += (copiedPixels[he - 1][wi + 1].rgbtBlue * -1);
            }

            // top left pixel
            if (he != 0 && wi != 0)
            {
                gxRedValues += (copiedPixels[he - 1][wi - 1].rgbtRed * -1);
                gxGreenValues += (copiedPixels[he - 1][wi - 1].rgbtGreen * -1);
                gxBlueValues += (copiedPixels[he - 1][wi - 1].rgbtBlue * -1);

                gyRedValues += (copiedPixels[he - 1][wi - 1].rgbtRed * -1);
                gyGreenValues += (copiedPixels[he - 1][wi - 1].rgbtGreen * -1);
                gyBlueValues += (copiedPixels[he - 1][wi - 1].rgbtBlue * -1);
            }

            // middle pixel
            gxRedValues += (copiedPixels[he][wi].rgbtRed * 0);
            gxGreenValues += (copiedPixels[he][wi].rgbtGreen * 0);
            gxBlueValues += (copiedPixels[he][wi].rgbtBlue * 0);

            gyRedValues += (copiedPixels[he][wi].rgbtRed * 0);
            gyGreenValues += (copiedPixels[he][wi].rgbtGreen * 0);
            gyBlueValues += (copiedPixels[he][wi].rgbtBlue * 0);

            // assigns a variable
            gRed = round(sqrt(pow(gxRedValues, 2) + pow(gyRedValues, 2)));
            gGreen = round(sqrt(pow(gxGreenValues, 2) + pow(gyGreenValues, 2)));
            gBlue = round(sqrt(pow(gxBlueValues, 2) + pow(gyBlueValues, 2)));

            // checks if over 255
            if (gRed > 255)
            {
                gRed = 255;
            }

            if (gGreen > 255)
            {
                gGreen = 255;
            }

            if (gBlue > 255)
            {
                gBlue = 255;
            }

            // sets a new pixel
            image[he][wi].rgbtRed = gRed;
            image[he][wi].rgbtGreen = gGreen;
            image[he][wi].rgbtBlue = gBlue;
        }
    }
    return;
}
