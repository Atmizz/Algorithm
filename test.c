#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    wprintf(L"\0xE2\n");
    return 0;
}
