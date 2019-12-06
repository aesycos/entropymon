#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void drawgauge( WINDOW * gauge, int val );
int getEntropy();
void flush_entropy();
int toPercentage( int part, int max );

int main( int argc, char ** argv )
{
    int x, y, c = 0;
    MEVENT event;
    
    initscr();
    cbreak();
    noecho();
    clear();
    
    mousemask( BUTTON1_CLICKED, NULL );
    curs_set( 0 );
    
    getmaxyx( stdscr, y, x );
    WINDOW * gauge = newwin( y, x, 0, 0 );
    keypad( gauge, TRUE );
    wtimeout( gauge, 250 );
    
    while( 1 )
    {
        // check for mouse button and flush /dev/random if pressed 
        c = wgetch( gauge );
        if ( c == KEY_MOUSE ) 
        {
            if ( getmouse( &event ) == OK )
            {
                if ( event.bstate & BUTTON1_CLICKED )
                {
                    flush_entropy();
                    flushinp();
                }
            }
        }
       
        // Gotta be a better way to redraw the gauge
        getmaxyx( stdscr, y, x );
        x = 5;
        wresize( gauge, y, x );
        wclear( gauge );
        drawgauge( gauge, toPercentage( getEntropy(), 4096 ) );
        refresh();
        box( gauge, 0, 0 );
        wrefresh(gauge);
    }

    endwin();
    return EXIT_SUCCESS;
}

void drawgauge( WINDOW * gauge, int val )
{
    int y, x, height;
    getmaxyx( gauge, y, x );

    height = y - 4;
    y = 2;
    x = 2;

    for ( int i = height; i > 0; i-- )
    {
        wmove( gauge, y, x );
        if ( toPercentage( i, height ) > val )
            waddch( gauge, 0x20 );
        else
            waddch( gauge, 0xDC );
        y += 1;
    }
    wmove( gauge, height+2, 1 );
    if ( val > 99 )
        val = 99;

    wprintw( gauge, "%2d%%", val );
}

int getEntropy()
{
    int entropy = 0;
    unsigned char buff[4];

    FILE * fp;

    if ( !(fp = fopen( "/proc/sys/kernel/random/entropy_avail", "r" ) ) )
        return entropy;
    
    fread( buff, 1, 4, fp );
    fclose(fp);

    entropy = atoi( (const char *) buff );
    return entropy;
}

void flush_entropy()
{
    // TODO Find a better was to clear /dev/random
    // preferrably all in one call to flush_entropy
    
    unsigned char buffer[4096];

    int fp;

    if ( !(fp = open( "/dev/random", O_RDONLY ) ) )
        return;

    read( fp, buffer, 4096 );
    close(fp);
    
    return;
}

int toPercentage( int part, int max )
{
    return (int)(((double) part / (double) max ) * 100);
}

