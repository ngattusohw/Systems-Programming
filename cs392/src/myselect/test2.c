#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <term.h>
#include <curses.h>
#include <signal.h>
#include <string.h>

static void finish(int sig);
void redrawhi(int x, int y);
void redrawUnd(int x, int y);
void initdraw();
void inithi();
void ignore();
char** glob;
int* ishi;  
int size;
int maxx;
int maxy;
int lastColX;
int row, col;

int main(int argc, char* argv[])
{
    int ind = 0;
    int currRow;
    int currCol;
    int num = 1;
    int i = num;
    int currx, curry;
    size = argc - 1;
    glob = argv;
    ishi = (int*)malloc(sizeof(int) * argc - 1);
    currx = 0;
    curry = 0;
    signal(SIGINT, ignore);
    initscr();
    keypad(stdscr, TRUE);
    nonl();
    raw();
    cbreak();
    noecho();
    curs_set(0);
    getmaxyx(stdscr,row,col);
    currRow = row;
    currCol = col;
    initdraw();
    move(0,0);
    while(1)
    {
        //Check for window resizing
        getmaxyx(stdscr,row,col);
        if (row != currRow || col != currCol)
        {
            erase();
            if(currRow - row < 0)
            {
                currx--;
            }
            else
            {
                currx++;
            }
            if(currCol - col < 0)
            {
                curry -= 30;
                currx = 0;
            }
            else
            {
                curry += 30;
                currx = 0;
            }
            currRow = row;
            currCol = col;
            //currx = 0;
            //curry = 0;
            inithi();
            redrawUnd(currx,curry);
        }
        //
        int ch = getch();
        if(ch == 13)
        {
            endwin();
            while(i <= size)
            {
                if(ishi[i] == 1)
                {
                    my_str(glob[i]);
                    my_str(" ");
                }
                i++;
            }
            my_str("\n");
            finish(0);
        }
        if(ch == KEY_LEFT)
        {
            curry -= 30;
            if(curry < 0)
            {
                curry = 0;
                currx = 0;
            }
            move(currx, curry);
            redrawUnd(currx, curry);
        }
        if(ch == KEY_RIGHT)
        {
            curry += 30;
            if(curry > maxy)
            {
                curry = maxy;
                currx = lastColX;
            }
            else if(curry == maxy && currx > lastColX)
            {
                currx = lastColX;
            }
            move(currx, curry);
            redrawUnd(currx, curry);
        }
        if(ch == KEY_UP)
        {
            currx--;
            if(currx < 0)
            {
                if (curry == 0)
                {
                    currx = lastColX;
                    curry = maxy;
                }
                else
                {
                    currx = maxx;
                    curry -= 30;
                }
            }
            move(currx,curry);
            redrawUnd(currx, curry);
        }
        if(ch == KEY_DOWN)
        {
            currx++;
            if (curry < maxy)
            {
                if (currx > maxx)
                {
                    currx = 0;
                    curry += 30;
                }
            }
            else if (curry == maxy)
            {
                if (currx > lastColX)
                {
                    currx = 0;
                    curry = 0;
                }
            }
            move(currx,curry);
            redrawUnd(currx, curry);
        }
        if(ch == ' ')
        {
            ind = ((curry/30)*(maxx+1)) + currx + 1;
            ishi[ind] = !ishi[ind];
            currx++;
            if (curry < maxy)
            {
                if (currx > maxx)
                {
                    currx = 0;
                    curry += 30;
                }
            }
            else if (curry == maxy)
            {
                if (currx > lastColX)
                {
                    currx = 0;
                    curry = 0;
                }
            }
            move(currx,curry);
            redrawUnd(currx, curry);
            // redrawhi(currx,curry);
            // currx++;
            // if(currx >= maxx)
            // {
            //     currx = 0;
            //     curry += 30;
            //     if(curry >= maxy)
            //     {
            //         curry = 0;
            //     }
            // }
            // redrawUnd(currx, curry);
        }
        if(ch == 27)
        {
            endwin();
            finish(0);
        }
    }
}
static void finish(int sig)
{
    //endwin();
    exit(0);
}
void initdraw()
{
    int num = 1;
    int currx, curry;
    currx = 0;
    curry = 0;
    maxx = 0;
    maxy = 0;
    lastColX = 0;
    while(num <= size)
    {
        if (currx == 0 && curry == 0)
        {
            attron(A_UNDERLINE);
            mvaddstr(currx, curry, glob[num]);
            attroff(A_UNDERLINE);
        }
        else
        {
            mvaddstr(currx, curry, glob[num]);
        }
        if (num == size)
        {
            lastColX = currx;
        }
        ishi[num++] = 0;
        if (currx < row-1 && curry < col-1)
        {
            currx++;
        }
        else if (curry < col-1)
        {
            currx = 0;
            curry += 30;     
        }
        else
        {
            erase();
            mvaddstr(0,0,"Please enlarge the window");
            return;
        }
        if (currx > maxx)
        {
            maxx = currx;
        }
        if (curry > maxy)
        {
            maxy = curry;
        }
    }
    if (lastColX == maxx)
    {
        maxy -= 30;
    }
    return;
}

void inithi()
{
    int num = 1;
    int currx, curry;
    currx = 0;
    curry = 0;
    maxx = 0;
    maxy = 0;
    lastColX = 0;
    while(num <= size)
    {
        if (currx == 0 && curry == 0)
        {
            attron(A_UNDERLINE);
            mvaddstr(currx, curry, glob[num]);
            attroff(A_UNDERLINE);
        }
        else
        {
            mvaddstr(currx, curry, glob[num]);
        }
        if (num == size)
        {
            lastColX = currx;
        }
        if (currx < row-1 && curry < col-1)
        {
            currx++;
        }
        else if (curry < col-1)
        {
            currx = 0;
            curry += 30;     
        }
        else
        {
            erase();
            mvaddstr(0,0,"Please enlarge the window");
            return;
        }
        if (currx > maxx)
        {
            maxx = currx;
        }
        if (curry > maxy)
        {
            maxy = curry;
        }
    }
    if (lastColX == maxx)
    {
        maxy -= 30;
    }
    return;
}

void ignore()
{
    return;
}


void redrawUnd(int x, int y)
{
    int num = 1;
    int currx, curry;
    currx = 0;
    curry = 0;
    while(num <= size)
    {
        if (currx == x && curry == y)
        {
            if(ishi[num] == 1)
            {
                attron(A_STANDOUT);
                attron(A_UNDERLINE);
                mvaddstr(currx, curry, glob[num]);
                attroff(A_STANDOUT);
                attroff(A_UNDERLINE);
            }
            else
            {
                attron(A_UNDERLINE);
                mvaddstr(currx, curry, glob[num]);
                attroff(A_UNDERLINE);
            }

        }
        else
        {
            if(ishi[num] == 1)
            {
                attron(A_STANDOUT);
                mvaddstr(currx, curry, glob[num]);
                attroff(A_STANDOUT);
            }
            else
            {
                mvaddstr(currx, curry, glob[num]);
            }
        }
        num++;
        // mvaddch(0, 0, maxx);
        // mvaddch(1, 1, maxy);
        if (currx < maxx)
        {
            currx++;
        }
        else if (curry <= col-1)
        {
            currx = 0;
            curry += 30;     
        }
        else
        {
            erase();
            mvaddstr(0,0,"Please enlarge the window");
            return;
        }
        if (currx > maxx)
        {
            maxx = currx;
        }
        if (curry > maxy)
        {
            maxy = curry;
        }
        if (lastColX == maxx)
        {
            maxy -= 30;
        }

    }
    move(x,y);
}

void redrawhi(int x, int y)
{
    int currx, curry, num;
    num = 1;
    currx = 0;
    curry = 0;
    while(num <= size)
    {
        if(currx == x && curry == y)
        {
            if(ishi[num] == 0)
            {
                attron(A_STANDOUT);
                mvaddstr(currx, curry, glob[num]);
                attroff(A_STANDOUT);
                ishi[num] = 1;
            }
            else
            {
                mvaddstr(currx, curry, glob[num]);
                ishi[num] = 0;
            }
        }
        else
        {
            if(ishi[num] == 1)
            {
                attron(A_STANDOUT);
                mvaddstr(currx,curry,glob[num]);
                attroff(A_STANDOUT);
            }
            else
            {
                mvaddstr(currx, curry, glob[num]);
            }
        }
        num++;
        if(currx < maxx)
        {
            currx++;
        }
        else if(curry <= col - 1)
        {
            curry += 30;
        }
        

    }
    //redrawUnd(++x,y);
    move(x,y);
}