#ifndef __WSP_TERMINAL_H__
#define __WSP_TERMINAL_H__


// Sets the noncannonical mode in the terminal and
// quits the echo mode to log user input
void set_noncanon(void);

// Returns back to normal
void set_canon(void);


#endif
