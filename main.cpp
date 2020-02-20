#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PALYAX 23
#define PALYAY 20
using namespace cv;

typedef struct {
	uint32_t sizex;
	uint32_t sizey;
	int mines_number;
	int palya[PALYAX][PALYAY];
}t_aknamezo_palya;

enum {
	step_simple=0,
	step_on_mine,
};
typedef  struct{
	uint32_t type;
	uint32_t x;
	uint32_t y;
}t_step;

t_aknamezo_palya aknamezo;

int generate_minefield(t_aknamezo_palya * aknamezo ){

	bzero(&(aknamezo->palya), aknamezo->sizex * aknamezo->sizey * sizeof(int)) ;
	srand(time(0));
	if(aknamezo->sizex<2){printf("size error");return -1;}
	if(aknamezo->sizey<2){printf("size error");return -1;}
	printf("aknamezo feltoltese\r\n");
	int i;
	for(i=0;i<aknamezo->mines_number;i++){
		printf("");
		uint32_t x=(((uint32_t)(rand()))%(aknamezo->sizex-1));
		uint32_t y=(((uint32_t)(rand()))%(aknamezo->sizey-1));
		if(aknamezo->palya[x][y]<255){
			printf("randomized: mine on x: %d y: %d \r\n",x, y);
			aknamezo->palya[x][y]=255;  //akna
			if(x>0){aknamezo->palya[x-1][y]++;} //jobb
			if((x>0)&&(y>0)){aknamezo->palya[x-1][y-1]++;} //jobbalso
			if((x<aknamezo->sizex-1)&&(y>0)){aknamezo->palya[x+1][y-1]++;}//bal alsü
			if((x<aknamezo->sizex-1)&&(y<aknamezo->sizey-1)){aknamezo->palya[x+1][y+1]++;}//bal felső
			if((x<aknamezo->sizex-1)){aknamezo->palya[x+1][y]++;}//bal
			if((x>0)&&(y<aknamezo->sizey-1)){aknamezo->palya[x-1][y+1]++;}//jobb felso
			if((x>0)&&(y>0)){aknamezo->palya[x][y-1]++;}//lent
			if((x>0)&&(y<aknamezo->sizey-1)){aknamezo->palya[x][y+1]++;}//fent
		}else{--i;}
	}
//	uint32_t maxstep=aknamezo->(sizex*aknamezo->sizey);
//	for(i=0;i<)


	printf("aknamezo ok\r\n");
	return 0;
}
int printminefield(t_aknamezo_palya * mine){
	uint32_t x,y;
	printf("\r\n");
	for(y=0;y<mine->sizey;y++){
	for(x=0;x<mine->sizex;x++){
	if(mine->palya[x][y]<10)
		{printf("%d ", mine->palya[x][y]  );

		}else{
			printf("X ");
		}
	}
	printf("\r\n");
	}
	return 0;
}

int step_on_minefield(t_aknamezo_palya * mine){
//	if(mine)
	return 0;
}

int main(int argc, char** argv )
{
//    if ( argc != 2 )
//    {
//        printf("usage: DisplayImage.out <Image_Path>\n");
//        return -1;
//    }
//    Mat image;
//    image = imread( argv[1], 1 );
//    if ( !image.data )
//    {
//        printf("No image data \n");
//        return -1;
//    }
//    namedWindow("Display Image", WINDOW_AUTOSIZE );
//    imshow("Display Image", image);



printf("palya size: %d of %d x %d y grid \r\n", sizeof(aknamezo.palya),PALYAX,PALYAY);
aknamezo.mines_number=10;
aknamezo.sizex=PALYAX;
aknamezo.sizey=PALYAY;
generate_minefield(&aknamezo);

printminefield(&aknamezo);

    waitKey(0);
    return 0;
}
