#include "draw.h"    //绘制套
#include "AndroidImgui.h"     //创建绘制套
#include "GraphicsManager.h" //获取 当前渲染模式



  600元 全源  联系 @TearGame
钉钉链接https://qr.dingtalk.com/action/joingroup?code=v1,k1,pe1CyUicgEJ/xUCHKaWnWf1OQ2zpXTzCsfNQeB1iw8I=&_dt_no_comment=1&origin=11? 泪心邀请你加入钉钉群聊泪心工作室，点击进入查看详情

QQ号   3849081700
int Mainthread( ) {
 
     
     
    ::graphics = GraphicsManager::getGraphicsInterface(GraphicsManager::VULKAN);

    //获取屏幕信息    
    ::screen_config(); 

    ::native_window_screen_x = (::displayInfo.height > ::displayInfo.width ? ::displayInfo.height : ::displayInfo.width);
    ::native_window_screen_y = (::displayInfo.height > ::displayInfo.width ? ::displayInfo.height : ::displayInfo.width);
    ::abs_ScreenX = (::displayInfo.height > ::displayInfo.width ? ::displayInfo.height : ::displayInfo.width);
    ::abs_ScreenY = (::displayInfo.height < ::displayInfo.width ? ::displayInfo.height : ::displayInfo.width);

    ::window = android::ANativeWindowCreator::Create("TearStore", native_window_screen_x, native_window_screen_y, permeate_record);
    graphics->Init_Render(::window, native_window_screen_x, native_window_screen_y);
    
    Touch::Init({(float)::abs_ScreenX, (float)::abs_ScreenY}, false); //最后一个参数改成true 只监听
    Touch::setOrientation(displayInfo.orientation);

    
    ::init_My_drawdata(); //初始化绘制数据
   音量切换阵营();

    static bool flag = true;
    while (flag) {
        drawBegin();
        graphics->NewFrame();
        
        Layout_tick_UI(&flag);      //绘制ui菜单

        graphics->EndFrame();        
    }
    
    // graphics->DeleteTexture(image);
    graphics->Shutdown();
    android::ANativeWindowCreator::Destroy(::window);
    return 0;
}





//泪心源码声明.txt
//泪心电宝@TearGame
//QQ群 435539500
//链接t.me/TearGame
