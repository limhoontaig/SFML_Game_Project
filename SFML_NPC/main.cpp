#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <iostream>
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);





    {
        Game game;
        bool success = game.Initialize();
        if (success)
        {
            game.RunLoop();
        }
        game.Shutdown();
    }


    return 0;
}