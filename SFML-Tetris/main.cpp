#include "GameInstance.h"

int main()
{
    GameInstance* instance = GameInstance::GetGameInstance();
    instance->Start();
    delete instance;
    return 0;
}
