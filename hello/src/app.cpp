
#include "app.h"
#include "inkview.h"

namespace hello{

App& GetApp(){
    static App app;
    return app;
}

int App::OnInit(int font_sz){
    font_sz_ = font_sz;
    font_ = OpenFont("LiberationMono", font_sz_,0);
    RETURN_ERROR(font_,FAIL);
    return 0;
}

int App::OnKey(int key_code){
    CloseApp();
}

int App::OnShow(){
    ClearScreen();
    SetFont(font_,BLACK);

    DrawTextRect(0,ScreenHeight()/2 - font_sz_/2, ScreenWidth(),
     font_sz_, "Hello PocketBook World !",ALIGN_CENTER); 
    FullUpdate();
    return 0;
}

void App::OnExit(){
    Deinit();
}

void App::Deinit(){
    if(font_){
        CloseFont(font_);
        font_=nullptr;
    }
}

}//exit hello