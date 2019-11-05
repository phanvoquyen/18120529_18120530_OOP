#pragma once
#include "Ball.h"
#include "Paddle.h"

extern int speed;



class Handing
{
private:
	int width, height;
	int score1, score2;
	int paddleLength;
	bool quit;

	Ball *ball;
	Paddle *player1;
	Paddle *player2;
	Paddle *computer;
public:
	Handing();
	~Handing();
	Handing(int w, int h, bool modepalyer);
	// Hàm khởi tạo game ban đầu
	void Restart(bool modeplayer);
	// Hàm tính điểm
	void ScoreUp(Paddle *player, bool modeplayer);
	// Hàm vẽ khung chơi
	void Draw(bool modeplayer);
	// hàm kiểm tra đầu vào
	void Move(bool modeplayer);
	// hàm xử lí va chạm
	void HandCollisions(bool modeplayer);
	// hàm chạy game
	void Run();
};
