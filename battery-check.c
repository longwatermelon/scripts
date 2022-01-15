#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    while (true)
    {
        FILE *fp = fopen("/sys/class/power_supply/BAT0/capacity", "r");
        int battery;
        fscanf(fp, "%d", &battery);

        if (battery < 20)
            system("aplay ~/low-battery.wav");

        fclose(fp);

        sleep(10);
    }

    return 0;
}

