#include "inkview.h"
#include "app.h"

using namespace hello;

static const int kFontSz = 40;

static int main_handler(int event, int first_param, int /*second_param*/){
    int res=0;
    App& app = GetApp();
    switch(event){
        case EVT_INIT:
            res = app.OnInit(kFontSz);
            break;
        case EVT_SHOW:
            res = app.OnShow();
            break;
        case EVT_KEYPRESS:
            res=app.OnKey(first_param);
            break;    
        case EVT_EXIT:
            app.OnExit();
            break;
        default:
            break;
    }
    return res;
}

int main(int argc, char* argv[]){
    InkViewMain(main_handler);
    return 0;
}