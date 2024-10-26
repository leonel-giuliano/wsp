#ifndef __WSP_KEY_H__
#define __WSP_KEY_H__


#define SERV_EXIT 'q'


// Checks if the SERV_EXIT char was passed
// The arg is a (volatile char *)
void *th_key_handler(void *arg);

// Sets the noncannonical mode in the terminal and
// quits the echo mode to log user input
void set_noncanon(void);

// Returns back to normal
void set_canon(void);


#endif
