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

// Limine terminal 
static volatile struct limine_terminal_request terminal_request = {
    .id = LIMINE_TERMINAL_REQUEST,
    .revision = 0
};

// We need to halt if not limine will bootloop
static void done(void) {
    for (;;) {
        __asm__("hlt");
    }
}

// Delay seconds
void delay(int s){
    for(int i=0;i<s;i++){ for(int i=0;i<1275;i++){} }
}

// Main start
void _start(void) {
    if (terminal_request.response == NULL || terminal_request.response->terminal_count < 1) done();
 
    print("Welcome to GoGX OS!\n\rI hate my life.\n\r");
 
    done();
}

//Print Function
void print(char msg[]){
    struct limine_terminal *terminal = terminal_request.response->terminals[0];
    terminal_request.response->write(terminal, msg, strlen(msg));
}

//Print Char Function
void printchr(char msg){
    struct limine_terminal *terminal = terminal_request.response->terminals[0];
    terminal_request.response->write(terminal, msg, strlen(msg));
}