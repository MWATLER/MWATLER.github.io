//drawPixel.cpp - Draw a pixel using SDL2
//
#include "SDL2/SDL.h"
#include <iostream>
#include <signal.h>
#include <sys/ipc.h>
#include <unistd.h>

using namespace std;

#define WINDOW_HEIGHT 640
#define WINDOW_WIDTH  960

bool is_running, is_shooting;
int xPos, yPos;
pthread_mutex_t lock_x;

void *draw_func1(void *arg);
void *draw_func2(void *arg);
void *draw_func3(void *arg);
void *draw_func4(void *arg);

struct Line {
    int x1;
    int y1;
    int x2;
    int y2;
};

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running=false;
            break;
    }
}

int main ( int argc, char *argv[] )
{
    SDL_Rect rect[3];
    Line line;
    int retVal=0;
    pthread_t tid[4];
    const unsigned int delay=10;
    is_running = true;
    is_shooting = false;
    signal(SIGINT, shutdownHandler);
    pthread_mutex_init(&lock_x, NULL);
    SDL_Renderer *renderer=nullptr;
    SDL_Window *window=nullptr;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
       cout<<"Init failed: "<<SDL_GetError()<<endl;
       retVal = -1;
    }
    else
    {
//      window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
//      unsigned int render_flags = 0;//SDL_RENDERER_ACCELERATED;
//      renderer = SDL_CreateRenderer(window, -1, render_flags);

        SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	int ret1, ret2, ret3, ret4;
        ret1 = pthread_create(&tid[0], NULL, draw_func1, &rect[0]);
	ret2 = pthread_create(&tid[1], NULL, draw_func2, &rect[1]);
	ret3 = pthread_create(&tid[2], NULL, draw_func3, &rect[2]);
	ret4 = pthread_create(&tid[3], NULL, draw_func4, &line);
	if(ret1!=0 || ret2!=0 || ret3!=0 || ret4!=0) {
	    is_running=false;
	    cout<<strerror(errno)<<endl;
	}

	while(is_running==true) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	    for(int i=0; i<3; ++i) SDL_RenderDrawRect(renderer, &rect[i]);
	    if(is_shooting==true){
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	        SDL_RenderDrawLine(renderer, line.x1, line.y1, line.x2, line.y2);
	    }
            SDL_RenderPresent(renderer);
            SDL_Delay(delay);
            SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
            SDL_RenderClear(renderer);
        }
	cout<<"Quitting..."<<endl;
	for(int i=0; i<3; ++i) pthread_join(tid[i],NULL);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    return retVal;
}

void *draw_func1(void *arg)
{
    cout<<"draw_func1: enter"<<endl;
    SDL_Rect *rect = (SDL_Rect *)arg;
    rect->w=50;
    rect->h=50;
    for(int y=0; y<WINDOW_HEIGHT-50 && is_running==true; y++) {
        for(int x=0; x<WINDOW_WIDTH-50 && is_running==true; x++) {
            rect->x=x;
            rect->y=y;
	    usleep(50000);
        }
    }
    cout<<"draw_func1: exit"<<endl;
    pthread_exit(NULL);
}

void *draw_func2(void *arg)
{
    cout<<"draw_func2: enter"<<endl;
    SDL_Rect *rect = (SDL_Rect *)arg;
    rect->w=10;
    rect->h=10;
    for(int y=0; y<WINDOW_HEIGHT-10 && is_running==true; y++) {
        for(int x=0; x<WINDOW_WIDTH-10 && is_running==true; x++) {
            rect->x=x;
            rect->y=y;
	    usleep(25000);
        }
    }
    cout<<"draw_func2: exit"<<endl;
    pthread_exit(NULL);
}

void *draw_func3(void *arg)
{
    cout<<"draw_func3: enter"<<endl;
    SDL_Rect *rect = (SDL_Rect *)arg;
    rect->w=100;
    rect->h=10;
    rect->y=WINDOW_HEIGHT-10;
    rect->x=WINDOW_WIDTH/2;
    while(is_running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                is_running = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.scancode)
                {
                case SDL_SCANCODE_A:
                    --rect->x;
		    if(rect->x<0) rect->x=0;
                    break;
                case SDL_SCANCODE_LEFT:
                    rect->x -= 10;
		    if(rect->x<0) rect->x=0;
                    break;
                case SDL_SCANCODE_S:
                    ++rect->x;
		    if(rect->x>WINDOW_WIDTH-100) rect->x=WINDOW_WIDTH-100;
                    break;
                case SDL_SCANCODE_RIGHT:
                    rect->x += 10;
		    if(rect->x>WINDOW_WIDTH-100) rect->x=WINDOW_WIDTH-100;
                    break;
                case SDL_SCANCODE_W:
                    --rect->y;
		    if(rect->y<WINDOW_HEIGHT-100) rect->y=WINDOW_HEIGHT-100;
                    break;
                case SDL_SCANCODE_Z:
                    ++rect->y;
		    if(rect->y>WINDOW_HEIGHT-10) rect->y=WINDOW_HEIGHT-10;
                    break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.scancode)
                {
                case SDL_SCANCODE_UP:
	            is_shooting = true;
		    xPos = rect->x + rect->w/2;
		    yPos = rect->y;
		    break;
                }
                break;
            }
        }
    }
    cout<<"draw_func3: exit"<<endl;
    pthread_exit(NULL);
}

void *draw_func4(void *arg)
{
    cout<<"draw_func4: enter"<<endl;
    Line *line = (Line *)arg;
    line->x1=line->x2=WINDOW_WIDTH/2;
    line->y1=WINDOW_HEIGHT-10;
    line->y2=WINDOW_HEIGHT-20;
    while(is_running)
    {
        if(is_shooting==true) {
            line->x1 = line->x2 = xPos;
	    for(int i=yPos; i>10; --i) {
                usleep(1000);
                line->y1 = i;
                line->y2 = i-10;
            }
	    is_shooting = false;
        }
	usleep(100);
    }
    cout<<"draw_func4: exit"<<endl;
    pthread_exit(NULL);
}
