#include <iostream>
#include <LBlocks/LBlocks.hpp>
#include <test/Test.hpp>
#include <conio.h>
#include <Windows.h>
#include <LBlocks/LLog.hpp>

int main()
{
    double RefPos = 1.0;
    double RealPos = 0.0;
    int Key = 0;
    lee::blocks::test::Sys sys;
    lee::blocks::LLog<double> Log;
    sys.setInput(&RefPos);
    sys.setOutput(&RealPos);
    sys.init();
    std::cout<<"start"<<std::endl;
    while(Key!=' ')
    {
        Key = 0;
        if(_kbhit())
        {
            Key = _getch();
        }
        sys.run();
        sys.print();

        Log.startLog();
        Log.addLog(RefPos,  "Ref Position");
        Log.addLog(RealPos, "Real Position");
    }
    Log.saveLog("test.dat");
    std::cout<<"over"<<std::endl;
    return 0;
}