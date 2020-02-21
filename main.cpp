#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#define PALYAX 30
#define PALYAY 20

#define PALYAMAXX 26
#define PALYAMAXY 26
//class minesweeper {
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


int generate_minefield(t_aknamezo_palya * aknamezo ){

	memset(aknamezo->palya, 0, aknamezo->sizex * aknamezo->sizey * sizeof(int));
	srand(time(0));
	if(aknamezo->sizex<2){printf("size error");return -1;}
	if(aknamezo->sizey<2){printf("size error");return -1;}
	printf("aknamezo feltoltese\r\n");
	int i;
	for(i=0;i<aknamezo->mines_number;i++){
		printf("");
		uint32_t x=(((uint32_t)(rand()))%(aknamezo->sizex));
		uint32_t y=(((uint32_t)(rand()))%(aknamezo->sizey));
		if(aknamezo->palya[x][y]<255){
			printf("randomized: mine on x: %d y: %d \r\n",x, y);
			aknamezo->palya[x][y]=255;  //akna
			if(x>0){aknamezo->palya[x-1][y]++;} //jobb
			if((x>0)&&(y>0)){aknamezo->palya[x-1][y-1]++;} //jobbalso
			if((x<aknamezo->sizex-1)&&(y>0)){aknamezo->palya[x+1][y-1]++;}//bal alsü
			if((x<aknamezo->sizex-1)&&(y<aknamezo->sizey-1)){aknamezo->palya[x+1][y+1]++;}//bal felső
			if((x<aknamezo->sizex-1)){aknamezo->palya[x+1][y]++;}//bal
			if((x>0)&&(y<aknamezo->sizey-1)){aknamezo->palya[x-1][y+1]++;}//jobb felso
			if((y>0)){aknamezo->palya[x][y-1]++;}//lent
			if((y<aknamezo->sizey-1)){aknamezo->palya[x][y+1]++;}//fent
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
		{if(mine->palya[x][y]<-1){
		if(mine->palya[x][y]==0){printf(". ");}
		else{printf("%d ", mine->palya[x][y]+16  );
		}}else{
			printf("  ");
		}

		}
	else{
		if(mine->palya[x][y]!=(255-16)){
			printf("X ");}
		else{printf("*-");}
		}
	}
	printf("\r\n");
	}
	return 0;
}

int step_on_minefield(t_aknamezo_palya * mine, t_step * step){
	uint32_t val=mine->palya[step->x][step->y];
	if(val<0){printf("already revealed %d %d\r\n",step->x,step->y);return 0;}
	if(val>20){printf("\r\n\n\nBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMMMMMMMMMMMMMM!!");
	mine->palya[step->x][step->y]-=16;return -1;}
	else{mine->palya[step->x][step->y]-=16;
	return 0;
	}
}

//}

t_aknamezo_palya aknamezo;
t_aknamezo_palya solver_fieldo;
int main(int argc, char** argv )
{

printf("palya size: %d of %d x %d y grid \r\n", sizeof(aknamezo.palya),PALYAX,PALYAY);
aknamezo.mines_number=(PALYAX*PALYAY /10);
aknamezo.sizex=PALYAX;
aknamezo.sizey=PALYAY;
generate_minefield(&aknamezo);
t_step step;
int i=0;
do{
step.type=0;step.x=(uint32_t)(rand()%(aknamezo.sizex-1)),step.y=(uint32_t)(rand()%(aknamezo.sizey-1));

printf("\r\nround %d new step on x %d y %d \r\n", ++i,step.x+1,step.y+1);
}
while(0==step_on_minefield(&aknamezo,&step));
printminefield(&aknamezo);
//    waitKey(0);
    return 0;
}
