#include "misaligned.h"
#include <iostream>
#include <assert.h>

#define MAJOR_COLORS 5

#define MINOR_COLORS 5

struct ColorPair {
    int index;
    const char* major;
    const char* minor;
};

static void generateColorMap(struct ColorPair colorMap[]) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
   for (int j = 0; j < MINOR_COLORS; j++) {
             colorMap[count].index = count + 1;
             colorMap[count].major = majorColor[i];
        colorMap[count].minor = minorColor[i]; // <-- BUG
            count++;
    }
}
}
static void generateOutputString(char *buffer, size_t bufSize, struct ColorPair colorMap[]) {
    buffer[0] = '\0';
  char line[50];
    for (int i = 0; i < MAJOR_COLORS * MINOR_COLORS; i++) {
        snprintf(line, sizeof(line), "%d | %s | %s\n",
                 colorMap[i].index, colorMap[i].major, colorMap[i].minor);
        strncat(buffer, line, bufSize - strlen(buffer) - 1);
    }
}
int printColorMap(void (*outputFunc)(const char*)) {
    struct ColorPair colorMap[MAJOR_COLORS * MINOR_COLORS];
    char buffer[1024];
    generateColorMap(colorMap);
    generateOutputString(buffer, sizeof(buffer), colorMap);
    outputFunc(buffer);
    return MAJOR_COLORS * MINOR_COLORS;
}
