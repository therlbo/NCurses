#include <ncurses.h>

typedef struct{short int x, y, c; bool movhor, movver;} object;


main() {

    object scr; int i,cont=0; bool fin=false;

    initscr();

    start_color();

    init_pair(1,COLOR_WHITE,COLOR_BLACK);

    init_pair(2,COLOR_GREEN,COLOR_BLACK);

    init_pair(3,COLOR_RED,COLOR_BLACK);

    keypad(stdscr,true);

    noecho();

    curs_set(0);

    getmaxyx(stdscr,scr.y,scr.x);

    object b1={scr.x-2,scr.y/2,0,false,false},b2={1,scr.y/2,0,false,false},b={scr.x/2,scr.y/2,0,false,false};

    

    mvprintw(4,5,"      ??");

    mvprintw(5,5,"    ??????");

    mvprintw(6,5,"   ???????");

    mvprintw(7,5,"   ?   ???");

    mvprintw(8,5,"       ???");

    mvprintw(9,5,"      ???");

    mvprintw(10,5,"      ??");

    mvprintw(11,5,"      ??");

    mvprintw(12,5,"      ??");

    mvprintw(13,5,"        ");

    mvprintw(14,5,"      ??");

    

    mvprintw(16,5,"Put in your report what this program does");

    mvprintw(17,5,"\t\t\tPlayer 1 your controls are 'a' and 'q'");

    mvprintw(18,5,"\t\t\tPlayer 2 your controls are the arrows of the keyboard");

    mvprintw(19,5,"\t\t\tPush ANY key to start, 'p' for pause and ESC to quit");

    getch();

    for (nodelay(stdscr,1); !fin; usleep(4000)) {

        if (++cont%16==0){

            if ((b.y==scr.y-1)||(b.y==1))

                b.movver=!b.movver;

            if ((b.x>=scr.x-2)||(b.x<=2)){

                b.movhor=!b.movhor;

                if ((b.y==b1.y-1)||(b.y==b2.y-1)) {

                    b.movver=false;

                } else if ((b.y==b1.y+1)||(b.y==b2.y+1)) {

                    b.movver=true;

                } else if ((b.y != b1.y) && (b.y != b2.y)) {

                    (b.x>=scr.x-2) ? b1.c++: b2.c++;

                    b.x=scr.x/2;

                    b.y=scr.y/2;

                }

            }

            b.x=b.movhor ? b.x+1 : b.x-1;

            b.y=b.movver ? b.y+1 : b.y-1;

            

            if (b1.y<=1)

                b1.y=scr.y-2;

            if (b1.y>=scr.y-1)

                b1.y=2;

            if (b2.y<=1)

                b2.y=scr.y-2;

            if (b2.y>=scr.y-1)

                b2.y=2;

        }

        switch (getch()) {

            case KEY_DOWN: b1.y++; break;

            case KEY_UP:   b1.y--; break;

            case 'q':       b2.y--; break;

            case 'a':       b2.y++; break;

            case 'p':       getchar(); break;

            case 0x1B:      endwin(); fin++; break;

        }

        erase();

        attron(COLOR_PAIR(3));

        mvprintw(2,scr.x/2-2,"%i | %i",b1.c,b2.c);

        attroff(COLOR_PAIR(3));

        mvvline(0,scr.x/2,ACS_VLINE,scr.y);

        attron(COLOR_PAIR(2));

        mvprintw(b.y,b.x,"o");

        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(1));

        for(i=-1;i<2;i++){

            mvprintw(b1.y+i,b1.x,"|");

            mvprintw(b2.y+i,b2.x,"|");}

        attroff(COLOR_PAIR(1));

    }

}

