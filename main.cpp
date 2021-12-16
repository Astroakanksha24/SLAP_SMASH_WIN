#include <graphics.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>

char  start_animation_1()
{
	int animation_time = 2;
	char format;
	while (animation_time < 6)
	{
		setbkcolor(animation_time);
		outtextxy(200, 200, "WELCOME TO ""SLAP SMASH WIN""");
		delay(100);
		animation_time++;
		setbkcolor(12);
	}
	delay(800);
	outtextxy(200, 200, "WELCOME TO ""SLAP SMASH WIN""");
	outtextxy(210, 220, "ENTER ANY KEY TO START");
	getch();
	cleardevice();
	setbkcolor(9);
	outtextxy(180, 180, "**********SELECT FORMAT**********");
	delay(500);
	outtextxy(250, 220, "1.MULTIPLAYER");
	outtextxy(250, 240, "2.SINGLEPLAYER");
	delay(800);
	outtextxy(250, 270, "PRESS KEY");
	format = getch();
	return format;
}
void start_animation_2(char format)
{
	int i, j;
	char player_1_name[50];
	char player_2_name[50];
	cleardevice();
	setbkcolor(12);
	outtextxy(200, 200, "Enter Player 1 name");
	scanf("%s", player_1_name);
	cleardevice();
	setbkcolor(12);
	if (format == '1')
	{
		outtextxy(200, 200, "Enter Player 2 name");
		scanf("%s", player_2_name);
	}
	else
	{
		char player_2_name[50] = {'P', 'R', 'O'};
	}
	cleardevice();
	setbkcolor(0);
	//loop for first area
	for (i = 60; i <= 120; i++)
	{
		for (j = 60; j <= 120; j++)
		{
			putpixel(j, i, RED);
		}
	}

	//loop of second area
	for (i = 121; i <= 180; i++)
	{
		for (j = 121; j <= 180; j++)
		{
			putpixel(j, i, GREEN);
		}
	}

	//loop of third area
	for (i = 181; i <= 240; i++)
	{
		for (j = 181; j <= 240; j++)
		{
			putpixel(j, i, BLUE);
		}
	}
	outtextxy(4, 4, "play match between");
	delay(1000);
	outtextxy(200, 100, player_1_name);
	delay(800);
	outtextxy(200, 200, "vs");
	delay(500);
	outtextxy(200, 300, player_2_name);
	delay(1000);
	return ;
}
void warning_animation()
{
	int animation_time = 1;
	while (animation_time < 13)
	{
		cleardevice();
		setbkcolor(animation_time);
		outtextxy(220, 220, "*/*/*/*WARNING*/*/*/*");
		outtextxy(250, 240, "INVALID FORMAT");
		outtextxy(250, 270, "GAME::::ENDS");
		delay(100);
		animation_time++;
	}
	setbkcolor(4);
	outtextxy(220, 220, "*/*/*/*WARNING*/*/*/*");
	outtextxy(250, 240, "INVALID FORMAT");
	outtextxy(250, 270, "GAME::::ENDS");
	getch();
}
char str[10];
void int_to_str(int n)
{
	int i = 0, j = 0;
	while (n)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	str[i] = '\0';
	i--;
	while (j < i)
	{
		char tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j++;
		i--;
	}
	return ;
}

void obstracle(int x, int y, int value)
{
	setcolor(4);
	setlinestyle(5, 0, 3);
	rectangle(x, y, x + 50, y + 30);
	int_to_str(value);
	outtextxy(x + 20, y + 10, str);
	return ;
}



void food(int x, int y, int value)
{
	setcolor(14);
	setlinestyle(5, 0, 5);
	circle(x, y,20);
	int_to_str(value);
	outtextxy(x, y-5, str);
	return ;
}



void boarder()
{
	setcolor(3);
	setlinestyle(5, 0, 2);
	rectangle(10, 10, 626, 445); // outer boundry

	setlinestyle(3, 0, 2);
	line(318, 10, 318, 440);  // center partition
	setlinestyle(3, 0, 2);
	setcolor(12);
	rectangle(10, 450, 626, 476);

}

void backround(int y)
{
	setcolor(13);
	circle(300,y,100);
	return ;



}

void object(int x, int player,int score)
{
	int y = 290;
	if (player == 1)
		setcolor(5);
	if (player == 2)
		setcolor(2);
	setlinestyle(5, 0, 2);
	line(x - 25, y + 30, x + 25, y + 30); // base
	line(x - 25, y + 30, x, y); // left side
	line(x + 25, y + 30, x, y); // right side
	int_to_str(score);
	outtextxy(x-9,y+15,str);



}
void game_end(int player_1_score, int player_2_score)
{
	cleardevice();
	setbkcolor(13);
	if ((player_2_score <= 0) && (player_2_score <= 0))
		outtextxy(200, 200, "****MAtch is tie****");
	else if (player_1_score <= 0)
		outtextxy(150, 200, "**COngo player 2 , better luck next time player 1**");
	else if (player_2_score <= 0)
		outtextxy(150, 200, "**COngo player 1 , better luck next time player 2**");
	getch();
}

int speed = 2;
int obs_sco[3][6] = {0};
void disply_obs(int pos_y1, int pos_y2, int pos_y3)
{
	int no;
	for (no = 0; no < 6; no++)
	{
		int value = obs_sco[0][no];
		if (value != 0)
			obstracle(13 + no * 50, pos_y1, value);

	}
	for (no = 0; no < 6; no++)
	{
		int value = obs_sco[1][no];
		if (value != 0)
			obstracle(13 + no * 50, pos_y2, value);

	}
	for (no = 0; no < 6; no++)
	{
		int value = obs_sco[2][no];
		if (value != 0)
			obstracle(13 + no * 50, pos_y3, value);

	}
	delay(10);
	return;

}



int food_sco[6] = {0};
void display_food(int pos_y1)
{
	int  no;
	for (no = 0; no < 6; no++)
	{
		int value = food_sco[no];
		if (value != 0)
			food(38 + no * 50, pos_y1, value);

	}
	return ;
}






int obs_sco2[3][6] = {0};
void disply_obs2(int pos_y1, int pos_y2, int pos_y3)
{
	int no;
	for (no = 0; no < 6; no++)
	{
		int value = obs_sco2[0][no];
		if (value != 0)
			obstracle(13+309 + no * 50, pos_y1, value);

	}
	for (no = 0; no < 6; no++)
	{
		int value = obs_sco2[1][no];
		if (value != 0)
			obstracle(13+309 + no * 50, pos_y2, value);

	}
	for (no = 0; no < 6; no++)
	{
		int value = obs_sco2[2][no];
		if (value != 0)
			obstracle(13+309 + no * 50, pos_y3, value);

	}
	delay(10);
	return;

}



int food_sco2[6] = {0};
void display_food2(int pos_y1)
{
	int no;
	for (no = 0; no < 6; no++)
	{
		int value = food_sco2[no];
		if (value != 0)
			food(38+309 + no * 50, pos_y1, value);
	}
	return ;
}




void update_obs(int num)
{
	int i;
	if (num == 0)
	{
		for (i = 0; i < 6; i++)
		{
			int val=rand() % 10;
			obs_sco[0][i] = val;
			obs_sco2[0][i] = val;
		}
	}
	if (num == 1)
	{
		for (i = 0; i < 6; i++)
		{
			int val=rand() % 10;
			obs_sco[1][i] = val;
			obs_sco2[1][i] = val;
		}
	}
	if (num == 2)
	{
		for (i = 0; i < 6; i++)
		{
			int val=rand() % 10;
			obs_sco[2][i] = val;
			obs_sco2[2][i] = val;
		}
	}
	return ;
}


void update_food()
{
	int i;
	for (i = 0; i < 6; i++)
	{
		int val= rand() % 10;
		food_sco[i] =val;
		food_sco2[i] =val;

	}
	return;
}



int main()
{


	int gd = DETECT, gm, page=0, x_1, x_2, player_1_score, player_2_score, food_y;
	int pos_y[3] = {11, 200, 300};
	int which_block, which_block2;
	char format;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	format=start_animation_1();
	if (format == '1')        //code for multiplayer
	{
		start_animation_2(format);
		x_1 = 38 + 50 * (rand() % 6);
		x_2 = 347 + 50 * (rand() % 6);
		player_1_score = 20;
		player_2_score = 20;
		food_y=100;

		update_obs(0);
		update_obs(1);

		while (1)
		{
			cleardevice();
			boarder();
			if (kbhit())
			{
				char input = getch();
				if (input == 'b')
					break;

				if (input == 'a')
					x_1 -= 50;
				else if (input == 'd')
					x_1 += 50;
				else if (input == 'j')
					x_2 -= 50;
				else if (input == 'l')
					x_2 += 50;

			}
			if (x_1 < 38)
				x_1 = 38;
			else if (x_1 > 288)
				x_1 = 288;

			if (x_2 < 347)
				x_2 = 347;
			else if (x_2 > 597)
				x_2 = 597;
			if ((player_1_score <= 0) || (player_2_score <= 0))
			{
				game_end(player_1_score, player_2_score);
				game_end(player_1_score, player_2_score);
				game_end(player_1_score, player_2_score);
				break;
			}
			object(x_1, 1,player_1_score);
			object(x_2, 2,player_2_score);


			disply_obs(pos_y[0], pos_y[1], pos_y[2]);
			display_food(food_y);

			disply_obs2(pos_y[0], pos_y[1], pos_y[2]);
			display_food2(food_y);
			if (((pos_y[0] + 25) >= 290) && ((pos_y[0] + 25) <= 300))
			{
				which_block = x_1 - 38-309;
				which_block /= 50;
				player_1_score-=obs_sco[0][which_block];
				obs_sco[0][which_block] = 0;

				which_block2 = x_2 - 38-309;
				which_block2 /= 50;
				player_2_score-=obs_sco2[0][which_block2];
				obs_sco2[0][which_block2] = 0;


			}
			else if (((pos_y[1] + 25) >= 290) && ((pos_y[1] + 25) <= 300))
			{
				which_block = x_1 - 38-309;
				which_block /= 50;
				player_1_score-=obs_sco[1][which_block];
				obs_sco[1][which_block] = 0;

				which_block2 = x_2 - 38-309;
				which_block2/= 50;
				player_2_score-=obs_sco2[1][which_block2];
				obs_sco2[1][which_block2] = 0;
			}
			else if (((pos_y[2] + 25) >= 290) && ((pos_y[2] + 25) <= 300))
			{
				which_block = x_1 - 38-309;
				which_block /= 50;
				player_1_score-=obs_sco[2][which_block];
				obs_sco[2][which_block] = 0;

				which_block2 = x_2 - 38-309;
				which_block2 /= 50;
				player_2_score-=obs_sco2[2][which_block2];
				obs_sco2[2][which_block2] = 0;
			}
			if (((food_y + 25) >= 290) && ((food_y + 25) <= 300))
			{
				which_block = x_1 - 38-309;
				which_block /= 50;
				player_1_score+=food_sco[which_block];
				food_sco[which_block] = 0;

				which_block2 = x_2 - 38-309;
				which_block2 /= 50;
				player_2_score+=food_sco2[which_block2];
				food_sco2[which_block2] = 0;
			}



			if (pos_y[0] >= 400)
			{
				pos_y[0] = 11;
				update_obs(0);
			}
			if (pos_y[1] >= 400)
			{
				pos_y[1] = 11;
				update_obs(1);
			}
			if (pos_y[2] >= 400)
			{
				pos_y[2] = 11;
				update_obs(2);
			}
			if (food_y >= 400)
			{
				food_y = 11;
				update_food();
			}

			int_to_str(player_1_score);
			outtextxy(15,460,"SCORE OF PLAYER 1 ::");
			outtextxy(170,460,str);
			int_to_str(player_2_score);
			outtextxy(240,460,"SCORE OF PLAYER 2 ::");
			outtextxy(400,460,str);
			delay(10);



			pos_y[0] += 10;
			pos_y[1] += 10;
			pos_y[2] += 10;
			food_y += 10;
			page=1-page;
			delay(50);

		}



	}
	else if (format == '2')    // code for single player
	{
		start_animation_2(format);

		x_1 = 38 + 50 * (rand() % 6);
		x_2 = 347 + 50 * (rand() % 6);
		player_1_score = 25;
		player_2_score = 25;
		food_y=100;

		update_obs(0);
		update_obs(1);

		while (1)
		{
			cleardevice();
			boarder();
			if (kbhit())
			{
				char input = getch();
				if (input == 'b')
					break;

				if (input == 'a')
					x_1 -= 50;
				else if (input == 'd')
					x_1 += 50;
				else if (input == 'j')
					x_2 -= 50;
				else if (input == 'l')
					x_2 += 50;

			}
			if (x_1 < 38)
				x_1 = 38;
			else if (x_1 > 288)
				x_1 = 288;

			if (x_2 < 347)
				x_2 = 347;
			else if (x_2 > 597)
				x_2 = 597;
			if ((player_1_score <= 0) || (player_2_score <= 0))
			{
				game_end(player_1_score, player_2_score);
				game_end(player_1_score, player_2_score);
				game_end(player_1_score, player_2_score);
				break;
			}
			object(x_1, 1,player_1_score);



			disply_obs(pos_y[0], pos_y[1], pos_y[2]);
			display_food(food_y);

			if (((pos_y[0] + 25) >= 290) && ((pos_y[0] + 25) <= 300))
			{
				int which_block = x_1 - 38;
				which_block /= 50;
				player_1_score-=obs_sco[0][which_block];
				obs_sco[0][which_block] = 0;
			}
			else if (((pos_y[1] + 25) >= 290) && ((pos_y[1] + 25) <= 300))
			{
				int which_block = x_1 - 38;
				which_block /= 50;
				player_1_score-=obs_sco[1][which_block];
				obs_sco[1][which_block] = 0;
			}
			else if (((pos_y[2] + 25) >= 290) && ((pos_y[2] + 25) <= 300))
			{
				int which_block = x_1 - 38;
				which_block /= 50;
				player_1_score-=obs_sco[2][which_block];
				obs_sco[2][which_block] = 0;
			}
			if (((food_y + 25) >= 290) && ((food_y + 25) <= 300))
			{
				int which_block = x_1 - 38;
				which_block /= 50;
				player_1_score+=food_sco[which_block];
				food_sco[which_block] = 0;
			}



			if (pos_y[0] >= 400)
			{
				pos_y[0] = 11;
				update_obs(0);
			}
			if (pos_y[1] >= 400)
			{
				pos_y[1] = 11;
				update_obs(1);
			}
			if (pos_y[2] >= 400)
			{
				pos_y[2] = 11;
				update_obs(2);
			}
			if (food_y >= 400)
			{
				food_y = 11;
				update_food();
			}

			int_to_str(player_1_score);
			outtextxy(15,460,"SCORE OF PLAYER 1 ::");
			outtextxy(170,460,str);
			int_to_str(player_2_score);
			outtextxy(240,460,"SCORE OF PLAYER 2 ::");
			outtextxy(400,460,str);
			delay(10);



			pos_y[0] += 10;
			pos_y[1] += 10;
			pos_y[2] += 10;
			food_y += 10;
			delay(50);
			page=1-page;

		}

	}
	else
	{
		warning_animation();
	}
	closegraph();
	return 0;

}
