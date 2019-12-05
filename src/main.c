#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>


void drawgauge( WINDOW * gauge, int x, int y, int val );
int getEntropy();

int main( int argc, char ** argv )
{
    initscr();
    cbreak();
    noecho();
    clear();

    curs_set( 0);
    WINDOW * gauge = newwin( 14, 5, 0, 0 );
    box( gauge, 0, 0 );
    while( 1 )
    {
        drawgauge( gauge, 2, 2, (int)(((double) getEntropy()/4096.00 )*100) );
        wrefresh(gauge);
        usleep( 250000 );
    }

    endwin();
    return EXIT_SUCCESS;
}

void drawgauge( WINDOW * gauge, int x, int y, int val )
{
    for ( int i = 10; i > 0; i-- )
    {
        wmove( gauge, y, x );
        if ( i > (int)(((double)val/100.00)*10))
            waddch( gauge, 0x20 );
        else
            waddch( gauge, 0xDC );

        y++;
    }
    wmove( gauge, 12, 1 );
    wprintw( gauge, "%d%%", val );
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
