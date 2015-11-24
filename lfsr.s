lfsr:
    ;TODO -- make sure numbers are all 16-bit
    ;if 16-bit, the numerical range is: [1, 65535] (No 0.... that I've seen, anyway)
    ;Counter here, and main, starts at 1. It will be a standard 4-bit int

    ;Set %edx to input value (stored auto by main of c fx
    ;repeat this until after input (counter) to ensure next 'random' number

    pushl   %ebp
    pushw   %ebx      ;is this necessary? if not also delete popw %ebx at the bottom of prog
    movl    %esp,   %ebp
    movw  $0xFEED,  %eax  ;lsfr
    leal  $0     ,  %edx  ;counter
.LOOP:
    addl    $1,  %edx     ;increment counter
    leaw  %eax,  %ebx     ;bit
    shrw    $0,  %ebx
    leaw  %eax,  %ecx
    shrw    %2,  %ecx
    xorw  %edx,  %ebx
    leaw  %eax,  %ecx
    shrw    %3,  %ecx
    xorw  %edx,  %ebx
    leaw  %eax,  %ecx
    shrw    %5,  %ecx
    xorw  %edx,  %ebx
    andw    $1,  %ebx

    shrw    $1,  %eax     ; lsfr rshift 1
    shlw   $15,  %ebx     ; bit lshift 15
    orw   %ebx,  %eax     ;

    cmpl  %edx,  8(%ebp)  ; compare counter to input
    jne .LOOP

    popw %ebx
    popl %ebp
    ret