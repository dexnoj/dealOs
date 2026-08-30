void print_char(char c, int x, int y) {
    volatile char *video = (volatile char*)0xB8000;
    int offset = (y * 80 + x) * 2;
    video[offset] = c;
    video[offset + 1] = 0x0F;
}

void kernel_main(void) {
    char msg[] = "Salam, dealOS!";
    for (int i = 0; msg[i] != 0; i++) {
        print_char(msg[i], i, 0);
    }
    while (1) {}
