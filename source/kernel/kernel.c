/*
 *  The Main GoGX Operating system Kernel
 *  Main script goes here
 *  Author: pradosh-arduino / helloImPR#6776
 *  Project: Started: 1/8/22 Github: 3/8/22
 */

// includes
#include <stdint.h>
#include <stddef.h>
#include <graphics.h>
#include <limine.h>
#include <strings.h>
#include <hal.h>
#include <keyboard.h>
#include <memory.h>
#include <e9print.h>
#include <idt.>

// Limine terminal 
static volatile struct limine_terminal_request terminal_request = {
    .id = LIMINE_TERMINAL_REQUEST,
    .revision = 0
};

struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0, .response = NULL
};

struct limine_module_request module_request = {
    .id = LIMINE_MODULE_REQUEST,
    .revision = 0, .response = NULL
};

bool LeftShift = false;
char string[1000];
int i_ = 0;
// We need to halt if not limine will bootloop
static void done(void) {
    for (;;) {
        int inData = inb(0x60);

        if(inData == 0x0E){print("\b \b");} // Backspace

        if(inData == 0x1C){print("\n\x1b[0;92m>>"); ResetColor();}    // Enter

        if(inData == 0x2A){
            LeftShift = true;
        }
        if(inData == 0xAA){
            LeftShift = false;
        }

        if(!(inData > 99 && inData < 1000) && inData != 42){
            // char string[20];
            // itoa(inData, string, 10, 10);
            Translate(inData, false);
            
            if(LeftShift == true){
                currentKey[0] = currentKey[0] - 32;
                if(currentKey != 0 && currentKey != 0xE0) print(currentKey); 
            }else{
                if(currentKey != 0 && currentKey != 0xE0) print(currentKey);
            }
            for(int i=0;i<100000*740;i++){
                __asm__("nop");
                __asm__("nop");
            }
        }
    }
}

// Main start
void _start(void) {
    if (terminal_request.response == NULL || terminal_request.response->terminal_count < 1) done();

    print("Welcome To \x1b[0;93mGoGX OS!\n\r");

    struct limine_framebuffer_response *fb_response = framebuffer_request.response;
    struct limine_framebuffer *fb = fb_response->framebuffers[0];
    ResetColor();
    e9_printf("\x1b[0;34mWidth: %d Height: %d", fb->width, fb->height);

    print("\x1b[0;92m>>");
    ResetColor();
 
    done();
}

//Print Function
void print(char msg[], ...){
    struct limine_terminal *terminal = terminal_request.response->terminals[0];
    terminal_request.response->write(terminal, msg, strlen(msg));
}