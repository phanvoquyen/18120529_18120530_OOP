﻿#include "Handing.h"



Handing::Handing()
{
}


Handing::~Handing()
{
	delete ball, player1, computer;
}

// hàm dựng tham số
Handing::Handing(int w, int h, bool modepalyer)
{
	srand(time(NULL));
	quit = false;
	score1 = score2 = 0;
	paddleLength = 6;
	width = w; height = h;
	ball = new Ball(w / 2, h / 2);
	player1 = new Paddle(1, h / 2 - 3);
	if (modepalyer)
		player2 = new Paddle(w - 2, h / 2 - 3);
	else
		computer = new Paddle(w - 2, h / 2 - 3);
	if (ball->getDirection() == STOP) {
		eDir a = (eDir)((rand() % 6) + 1);
		ball->changeDirection(a);
	}
}

// Hàm thiết thập thông số ban đầu
void Handing::Restart(bool modeplayer)
{
	system("cls");
	ball->Reset();
	player1->Reset();
	if (modeplayer)
	{
		player2->Reset();
	}
	else
		computer->Reset();
	TextColor(0);
	Draw(modeplayer);
	if (ball->getDirection() == STOP) {
		eDir a = (eDir)((rand() % 6) + 1);
		ball->changeDirection(a);
	}
	speed = 100000000;
}

// hàm tính điểm
void Handing::ScoreUp(Paddle *player, bool modeplayer)
{
	
	if (player == player1)
	{
		TextColor(10);
		gotoxy(width / 2 - 6, height / 2); cout << "PLAYER1 WON";
		score1++;
		// cập nhật điểm ngay lập tức
		gotoxy(width - 60, height + 3);
		cout << "Player1's score: " << score1;
		TextColor(14);
		gotoxy(width / 2 - 13, height / 2 + 1);
		int temp = toupper(_getch());
		if (temp == 'Q')
			quit = true;
		if (quit)
			return;
	}
	// modeplayer == true thì thực hiện thao tác liên quan đến 2 người chơi
	if (modeplayer)
	{
		if (player == player2)
		{
			TextColor(11);
			gotoxy(width / 2 - 6, height / 2); cout << "PLAYER2 WON";
			score2++;
			// cập nhật điểm ngay lập tức
			gotoxy(width - 17, height + 3);
			cout << "Player2's score: " << score2;
			TextColor(14);
			gotoxy(width / 2 - 13, height / 2 + 1);
			int temp = toupper(_getch());
			if (temp == 'Q')
				quit = true;
			if (quit)
				return;
		}
	}
	else
	{
		if (player == computer)
		{
			TextColor(11);
			gotoxy(width / 2 - 6, height / 2); cout << "COMPUTER WON";
			score2++;
			// cập nhật điểm ngay lập tức
			gotoxy(width - 20, height + 3);
			cout << "Computer's score: " << score2;
			TextColor(14);
			gotoxy(width / 2 - 13, height / 2 + 1);
			int temp = toupper(_getch());
			if (temp == 'Q')
				quit = true;
			if (quit)
				return;
		}
	}
	
	Restart(modeplayer);
}

// hàm vẽ khung trò chơi, vẽ hướng dẫn chơi
void Handing:: Draw(bool modeplayer)
{
	gotoxy(0, 0);

	TextColor(119);
	// in thanh ngang trên
	for (int i = 0; i < width + 2; i++)
	{
		cout << '#';
	}
	TextColor(0);
	cout << endl;
	// nếu là chế độ người vs máy thì thực hiện if
	if (!modeplayer)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				

				// in thanh dọc trái
				if (j == 0)
				{
					TextColor(119);
					cout << '#';
					TextColor(0);
				}

				// in bóng
				if (j == ball->getX() && i == ball->getY())
				{
					TextColor(12);
					cout << 'O';
					TextColor(0);
				}

				// in player
				else if (j == player1->getX() && i >= player1->getY() && i <= player1->getY() + paddleLength - 1)
				{
					TextColor(25);
					char c = 177;
					cout << c;
					TextColor(0);
				}

				// in computer
				else if (j == computer->getX() && i >= computer->getY() && i <= computer->getY() + paddleLength - 1)
				{
					TextColor(20);
					char c = 177;
					cout << c;
					TextColor(0);
				}
				// in khoảng trắng giữ khung trò chơi
				else
					cout << ' ';

				// in thanh dọc phải
				if (j == width - 1)
				{
					TextColor(119);
					cout << '#';
					TextColor(0);
				}
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				

				if (j == 0)
				{
					TextColor(119);
					cout << '#';
					TextColor(0);
				}

				if (j == ball->getX() && i == ball->getY())
				{
					TextColor(12);
					cout << 'O';
					TextColor(0);
				}
				else if (j == player1->getX() && i >= player1->getY()&& i <= player1->getY() + paddleLength - 1)
				{
					TextColor(25);
					char c = 177;
					cout << c;
					TextColor(0);
				}
				else if (j == player2->getX() && i >= player2->getY() && i <= player2->getY() + paddleLength - 1)
				{
					TextColor(20);
					char c = 177;
					cout << c;
					TextColor(0);
				}
				else
					cout << ' ';

				if (j == width - 1)
				{
					TextColor(119);
					cout << '#';
					TextColor(0);
				}
			}
			cout << endl;
		}

	}

	TextColor(119);
	// in thang ngang dưới
	for (int i = 0; i < width + 2; i++)
		cout << '#';
	TextColor(0);
	cout << endl;
	TextColor(10);
	//in điểm của người chơi và hướng dẫn chơi
	gotoxy(width - 60, height + 3);
	cout << "Player1's score: " << score1;
	TextColor(11);

	if (modeplayer)
	{
		gotoxy(width - 17, height + 3);
		cout << "Player2's score: " << score2;
		TextColor(11);
		gotoxy(width + 5, 10);
		cout << "Press W to move up for player1";
		gotoxy(width + 5, 11);
		cout << "Press S to move down for player1";
		TextColor(10);
		gotoxy(width + 5, 12);
		cout << "Press O to move up for player2";
		gotoxy(width + 5, 13);
		cout << "Press L to move down for player2";
	}
	else
	{
		gotoxy(width - 20, height + 3);
		cout << "Computer's score: " << score2;
		gotoxy(width + 5, 10);
		cout << "Press W to move up for player";
		gotoxy(width + 5, 11);
		cout << "Press S to move down for player";
	}


	TextColor(14);
	gotoxy(width + 11, 7);
	cout << "PING PONG GAME" << endl;
	TextColor(15);
	gotoxy(width + 5, 8);
	cout << "Press Q key to quit game";
	gotoxy(width + 5, 9);
	cout << "Press R key to restart game";
}

// hàm nhận thông số đầu vào
void Handing::Move(bool modeplayer)
{
	ball->Move();

	

	// kiểm tra bắt phím, phục vụ di chuyển paddle
	if (_kbhit())
	{
		int temp = toupper(_getch());

		if (temp == 'W')
			if (player1->getY() > 0)
				player1->moveUp();
		if (temp=='S')
			if (player1->getY() + paddleLength - 1 < height - 1)
				player1->moveDown();
		if (modeplayer)
		{
			
			if (temp=='O')
				if (player2->getY() > 0)
					player2->moveUp();
			if (temp=='L')
				if (player2->getY() + paddleLength - 1 < height - 1)
					player2->moveDown();
		}



		// nếu là q thì thoát game
		if (temp=='Q')
		{
			quit = true;
		}

		// nếu là r thì chơi ván mới, ghi nhận thành tích ván trước
		if (temp=='R') {
		
			
			Restart(modeplayer);
		}
	}

	

	// Hàm xử lý thanh tự động
	if (!modeplayer)
	{
		
		
			if (ball->getDirection() == RIGHT)
			{
				if (ball->getY() > computer->getY() + paddleLength - 1)
				{
					if (computer->getY() + paddleLength - 1 < height - 1)
						computer->moveDown();
				}
				else if (ball->getY() < computer->getY())
				{
					if (computer->getY() > 0)
						computer->moveUp();
				}
			}

			if (ball->getDirection() == DOWNRIGHT && ball->getY() > computer->getY() + paddleLength - 1)
			{
				computer->moveDown();
			}
			if (ball->getDirection() == UPRIGHT && ball->getY() < computer->getY())
			{
				if (computer->getY() > 0)
					computer->moveUp();
			}
		
	}
}

	


void Handing::HandCollisions(bool modeplayer)
{
	



	// Kiểm tra va chạm với người chơi 1, xử lí chuyển hướng, người chơi đánh trúng mới tăng speed lên
	for (int i = 0; i < 6; i++)
	{
		if (ball->getX() == player1->getX() + 1)
			if (ball->getY() == player1->getY() + i)
			{
				
				// xử lí theo nguyên tắc phản xạ vật lí
				if (ball->getDirection() == LEFT) {
					eDir a = eDir(rand() % 3 + 4);
					ball->changeDirection(a);
				}
				if (ball->getDirection() == UPLEFT)
					ball->changeDirection(UPRIGHT);
				if (ball->getDirection() == DOWNLEFT)
					ball->changeDirection(DOWNRIGHT);
				// khi đánh trúng bóng thì tăng speed
				speed = speed * 0.7;
			}
	}

	// Kiểm tra va chạm giữa người chơi 2 và bóng, xử lí chuyển hướng, người chơi đánh trúng mới tăng speed lên
	if (modeplayer)
	{
		
		for (int i = 0; i < 6; i++)
		{
			if (ball->getX() == player2->getX() - 1)
				if (ball->getY() == player2->getY() + i)
				{
					
					if (ball->getDirection() == RIGHT)
					{
						eDir a = eDir(rand() % 3 + 1);
						ball->changeDirection(a);
				}
					if (ball->getDirection() == UPRIGHT)
						ball->changeDirection(UPLEFT);
					if (ball->getDirection() == DOWNRIGHT)
						ball->changeDirection(DOWNLEFT);
					speed = speed * 0.7;
				}
		}

	}
	// kiểm tra va chạm giữ computer và bóng
	else
	{
		
		for (int i = 0; i < 6; i++)
		{
			if (ball->getX() == computer->getX() - 1)
				if (ball->getY() == computer->getY() + i)
				{
					
					if (ball->getDirection() == RIGHT)
					{
						eDir a = eDir(rand() % 3 + 1);
						ball->changeDirection(a);
					}
					if (ball->getDirection() == UPRIGHT)
						ball->changeDirection(UPLEFT);
					if (ball->getDirection() == DOWNRIGHT)
						ball->changeDirection(DOWNLEFT);
					speed = speed * 0.7;
				}
		}
	}

	// xử lí va chạm biên
	if (ball->getY() == height - 1)
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
	else if (ball->getY() == 0)
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

	// chạm biên phải thì player1 thắng, tăng điểm
	if (ball->getX() == width - 1)
		ScoreUp(player1, modeplayer);
	// chạm biên trái thì palyer2 hoặc computer thắng, tùy vào mode chọn
	else if (ball->getX() == 0)
	{
		if (modeplayer)
		{
			ScoreUp(player2, modeplayer);
		}
		else
		{
			ScoreUp(computer, modeplayer);
		}
	}
}



void Handing::Run()
{
	// vẽ khung chơi ban đầu, cùng in thông tin
	Draw(modeplayer);
	// thực hiện while để chạy game, chạy đến khi qiut == true thì dừng
	while (!quit)
	{
		srand(time(NULL));
		// kiểm tra đầu vào
		Move(modeplayer);
		
		// xử lí các va chạm
		HandCollisions(modeplayer);
		// vẽ lại màn hình sau một xử lí
		Draw(modeplayer);
	}
	// in chiến thắng chung cuộc
	if (quit)
	{
		system("cls");
		gotoxy(30, 15);
		if (modeplayer)
		{
			if (score1 > score2)
				cout << "END GAME - WINNER: PLAYER1 - CONGRATULATION" << endl;
			else if (score1 < score2)
				cout << "END GAME - WINNER: PLAYER2 - CONGRATULATION" << endl;
			else
				cout << "END GAME - TIE" << endl;
			gotoxy(30, 16);
		}
		else
		{
			if (score1 > score2)
				cout << "END GAME - WINNER: PLAYER1 - CONGRATULATION" << endl;
			else if (score1 < score2)
				cout << "END GAME - WINNER: COMPUTER - CONGRATULATION" << endl;
			else
				cout << "END GAME - TIE" << endl;
			gotoxy(30, 16);
		}
	}
}