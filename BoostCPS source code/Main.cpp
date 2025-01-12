#include <iostream>
#include <ctime>
#include <windows.h>

class boostCPS
{
private:
    bool isRunning = false;

    int startDelay = 1;
    int endDelay = 60;
    int randomTime;

    double startDelayCopy;
    double endDelayCopy;
    double number = 20;

public:
    void startBoost()
    {
        while (true)
        {
            //ON
            if (GetAsyncKeyState(0x4E) & 0x8000 && !isRunning)
            {
                MessageBeep(MB_ICONSTOP);

                isRunning = true;

                startDelayCopy = startDelay * 20;
                endDelayCopy = endDelay * 20;

                while (isRunning)
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                    if (number > 0)
                    {
                        startDelayCopy /= 1.3;
                        endDelayCopy /= 1.15;

                        randomTime = rand() % (static_cast<int>(endDelayCopy) - static_cast<int>(startDelayCopy) + 1) + static_cast<int>(startDelayCopy);
                        Sleep(randomTime);
                    }
                    else
                    {
                        randomTime = rand() % (endDelay - startDelay + 1) + startDelay;
                        Sleep(randomTime);
                    }
                    number--;


                    //OFF
                    if (GetAsyncKeyState(0x4D) & 0x8000)
                    {
                        MessageBeep(MB_OK);

                        startDelayCopy = startDelay;
                        endDelayCopy = endDelay;

                        for (int i = 1; i < 15; i++)
                        {
                            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                            startDelayCopy *= 1.25;
                            endDelayCopy *= 1.15;

                            randomTime = rand() % (static_cast<int>(endDelayCopy) - static_cast<int>(startDelayCopy) + 1) + static_cast<int>(startDelayCopy);
                            Sleep(randomTime);
                        }

                        MessageBeep(MB_OK);

                        isRunning = false;
                        break;
                    }
                }
            }
        }
    }
};

int main()
{
    std::cout << "Welcome to the Boost CPS program!" << std::endl;
    std::cout << "N - start boost cps." << std::endl;
    std::cout << "M - end boost cps." << std::endl;
    boostCPS boostcps;
    boostcps.startBoost();

    return 0;
}