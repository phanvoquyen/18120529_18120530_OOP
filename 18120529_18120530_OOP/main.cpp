#pragma once
#include "Handing.h"




int main()
{
	WindowInit();
	ModeMenu(modeplayer);
	Handing hd(60, 20, modeplayer);
	hd.Run();
	system("pause");
	return 0;
}
