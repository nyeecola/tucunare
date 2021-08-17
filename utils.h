#ifndef TUCUNARE_UTILS_H
#define TUCUNARE_UTILS_H

static void unreachable(char *str) {
    fprintf(stderr, "Unreachable: %s\n", str);
    exit(1);
}

#endif //TUCUNARE_UTILS_H
