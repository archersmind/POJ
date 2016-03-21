/*
 * =====================================================================================
 *
 *       Filename:  poj-3299-Humidex.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年03月21日 09时57分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <math.h>

#define INPUT_FLAG_TEMPERATURE 0x001
#define INPUT_FLAG_DEWPOINT    0x010
#define INPUT_FLAG_HUMIDEX     0x100

int main(void) {

    float temperature, dewpoint, humidex = 0.0;
    char input_0, input_1 = '\0';
    int index = 0x000;
    float f1, f2 = 0.0;
    double e, h = 0.0;

    while(scanf("%c",&input_0)!=EOF && input_0 != 'E') {

        //printf ("input_0 = %c \n", input_0);
        scanf("%f %c %f", &f1, &input_1, &f2);

        index = 0x000;
        if (input_0 == 'T') {
            temperature = f1;
            index |= INPUT_FLAG_TEMPERATURE;
        } else if (input_0 == 'D') {
            dewpoint = f1;
            index |= INPUT_FLAG_DEWPOINT;
        } else  if (input_0 == 'H'){
            humidex = f1;
            index |= INPUT_FLAG_HUMIDEX;
        }

        //printf ("--1 T = %.1f \n", temperature);

        if (input_1 == 'T') {
            temperature = f2;
            index |= INPUT_FLAG_TEMPERATURE;
        } else if (input_1 == 'D') {
            dewpoint = f2;
            index |= INPUT_FLAG_DEWPOINT;
        } else if (input_1 == 'H'){
            humidex = f2;
            index |= INPUT_FLAG_HUMIDEX;
        }

        //printf ("--2 T = %.1f \n", temperature);
        //printf ("index = 0x%x \n", index);

        if (index & INPUT_FLAG_DEWPOINT) {
            e = 6.11 *
                (exp(5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16)))));
            h = (0.5555) * (e - 10.0);
        } 

        if (!(index & INPUT_FLAG_TEMPERATURE)) {
            temperature = humidex - h;
        } else if (!(index & INPUT_FLAG_HUMIDEX)) {
            humidex =  temperature + h;
        } else {
            h = humidex - temperature;
            e = h / 0.5555 + 10.0;
            dewpoint = (1 / ((1 / 273.16) - (log(e / 6.11) / 5417.7530)))
            - 273.16;
        }

        printf ("T %.1f D %.1f H %.1f\n", temperature, dewpoint, humidex);
        scanf("%c", &input_0);
    }

    return 0;
}
